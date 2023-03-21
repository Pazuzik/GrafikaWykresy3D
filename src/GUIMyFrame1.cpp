#define _USE_ANTIALIASING
#include "GUIMyFrame1.h"
#include "ConfigClass.h" 
#include "ChartClass.h"

#include <iostream> 
#include <fstream>
#include <vector>


std::shared_ptr<wxPageSetupDialogData> PageSetupData;


class Printout : public wxPrintout
{
public:
	Printout(const wxChar* title = (const wxChar*)"Mój wydruk") :wxPrintout(title) {};
	bool OnPrintPage(int page);
	bool OnBeginDocument(int startPage, int endPage);
	void GetPageInfo(int* minPage, int* maxPage, int* selPageFrom, int* selPageTo);
};

bool Printout::OnBeginDocument(int startPage, int endPage)
{
	if (wxPrintout::OnBeginDocument(startPage, endPage)) return true;
	return false;
}

bool Printout::OnPrintPage(int pageNum)
{
	wxDC* dc = GetDC();
	FitThisSizeToPageMargins(wxSize(300, 600), *PageSetupData);
	return true;
}

void Printout::GetPageInfo(int* minPage, int* maxPage, int* selPageFrom, int* selPageTo)
{
	*minPage = 1;
	*maxPage = 1;
	*selPageFrom = 1;
	*selPageTo = 1;
}


std::vector<Point> punkty;

bool czyWczytaneDane = false;
bool czyRzut = false;
bool czyKontur = false;

GUIMyFrame1::GUIMyFrame1(wxWindow* parent) : MyFrame1(parent)
{
	cfg = std::make_shared<ConfigClass>(this);
}

void GUIMyFrame1::mainFormClose(wxCloseEvent& event)
{
	Destroy();
}


void GUIMyFrame1::WxEdit_x0_Update(wxCommandEvent& event)
{
	double v;
	if (ustaw_x0->GetValue().ToDouble(&v)){
		cfg->Set_x_start(v);
		Layout();
		Repaint();
	}
	else if (ustaw_x0->GetValue() != "-" && ustaw_x0->GetValue() != "")
	{
		wxBell();
	}
}


void GUIMyFrame1::WxEdit_x1_Update(wxCommandEvent& event)
{
	double v;
	if (ustaw_x1->GetValue().ToDouble(&v))
	{
		cfg->Set_x_stop(v);
		Layout();
		Repaint();
	}
	else if (ustaw_x1->GetValue() != "-" && ustaw_x1->GetValue() != "")
	{
		wxBell();
	}
}


void GUIMyFrame1::WxEdit_y0_Update(wxCommandEvent& event)
{
	double v;
	if (ustaw_y0->GetValue().ToDouble(&v))
	{
		cfg->Set_y_start(v);
		Layout();
		Repaint();
	}
	else if (ustaw_y0->GetValue() != "-" && ustaw_y0->GetValue() != "")
	{
		wxBell();
	}
}



void GUIMyFrame1::WxEdit_y1_Update(wxCommandEvent& event)
{
	double v;
	if (ustaw_y1->GetValue().ToDouble(&v))
	{
		cfg->Set_y_stop(v);
		Layout();
		Repaint();
	}
	else if (ustaw_y1->GetValue() != "-" && ustaw_y1->GetValue() != "")
	{
		wxBell();
	}
}

void GUIMyFrame1::WxEdit_z0_Update(wxCommandEvent& event)
{
	double v;
	if (ustaw_z0->GetValue().ToDouble(&v))
	{
		cfg->Set_z_stop(v);
		Repaint();
	}
	else if (ustaw_z0->GetValue() != "-" && ustaw_z0->GetValue() != "")
	{
		wxBell();
	}
}



void GUIMyFrame1::WxEdit_z1_Update(wxCommandEvent& event)
{
	double v;
	if (ustaw_z1->GetValue().ToDouble(&v))
	{
		cfg->Set_z_start(v);
		Repaint();
	}
	else if (ustaw_z1->GetValue() != "-" && ustaw_z1->GetValue() != "")
	{
		wxBell();
	}
}


void GUIMyFrame1::WxPanel_Repaint(wxUpdateUIEvent& event)
{
	Repaint();
}

void GUIMyFrame1::kontur_click(wxCommandEvent& event)
{
	czyRzut = false;
	czyKontur = true;
}


void GUIMyFrame1::rzutPersp_click(wxCommandEvent& event)
{
	czyKontur = false;
	czyRzut = true;
}

void GUIMyFrame1::wczytajDane_click(wxCommandEvent& event)
{
	wxFileDialog WxOpenFileDialog(this, wxT("Choose a file"), wxT(""), wxT(""), wxT("Geometry file (*.geo)|*.geo"), wxFD_OPEN | wxFD_FILE_MUST_EXIST);

	if (WxOpenFileDialog.ShowModal() == wxID_OK)
	{
		double x, y, z;
		punkty.clear();

		std::ifstream in(WxOpenFileDialog.GetPath().ToAscii());
		if (in.is_open())
		{
			punkty.clear();
			while (!in.eof())
			{
				in >> x >> y >> z;
				punkty.push_back(Point(x, y, z));
			}
			in.close();
		}
	}
	czyWczytaneDane = true;
}

void GUIMyFrame1::zapisz_click(wxCommandEvent& event)
{
	wxClientDC dc1(m_panel1);
	wxBufferedDC dc(&dc1);

	myBitmap = dc.GetAsBitmap();
	wxFileDialog saveFileDialog(this, "Wybierz plik", "", "", "BMP files (*.bmp)|*.bmp|JPG files (*.jpg)|*.jpg|PNG files (*.png)|*.png", wxFD_SAVE | wxFD_OVERWRITE_PROMPT);
	if (saveFileDialog.ShowModal() == wxID_CANCEL)
		return;
	myImage = myBitmap.ConvertToImage();
	myImage.AddHandler(new wxJPEGHandler);
	myImage.AddHandler(new wxPNGHandler);
	myImage.SaveFile(saveFileDialog.GetPath());
}

void GUIMyFrame1::drukuj_click(wxCommandEvent& event)
{
	wxPrinter Printer;
	Printout MyPrintout;
	Printer.Print(this, &MyPrintout, true);
}

void GUIMyFrame1::funkcja_pick(wxCommandEvent& event)
{
	czyWczytaneDane = false;
	cfg->Set_F_type(WxChoice->GetSelection());
}

//////////////////////////////////////




void GUIMyFrame1::Repaint()
{
	wxClientDC dc1(m_panel1);
	wxBufferedDC dc(&dc1);
	dc.SetBackground(*wxWHITE_BRUSH);
	dc.Clear();
	ChartClass MyChart(cfg);
	int w, h;
	m_panel1->GetSize(&w, &h);


	Matrix4 rotateZ;
	double angle = 45 * M_PI / 180.0;
	rotateZ.data[0][0] = cos(angle);
	rotateZ.data[0][1] = sin(angle);
	rotateZ.data[1][0] = -sin(angle);
	rotateZ.data[1][1] = cos(angle);
	rotateZ.data[2][2] = 1;

	Matrix4 matrix6;
	matrix6.data[0][0] = 1;
	matrix6.data[1][1] = 1;
	matrix6.data[3][2] = 1.0 / 2.0;

	Matrix4 matrix7;
	matrix7.data[0][0] = w / 2;
	matrix7.data[1][1] = -h / 2;
	matrix7.data[0][3] = w / 2;
	matrix7.data[1][3] = h / 2;

	Matrix4 matrix1;
	double n = -0.9, f = 5, r = -1, l = 1, t = 3, b = -3;
	matrix1.data[0][0] = 2 * n / (r - l); //  2n/(r-l)
	matrix1.data[1][1] = 2 * n / (t - b); // 2n/(t-b)
	matrix1.data[2][2] = -(f + n) / (f - n); // -(f+n)/(f-n)
	matrix1.data[3][2] = 1;
	matrix1.data[2][3] = ((-2) * f * n) / (f - n); // -2fn/(f-n)
	matrix1.data[3][3] = 0;
	matrix1.data[0][2] = (r + l) / (r - l); // (r+l)/(r-l)
	matrix1.data[1][2] = (t + b) / (t - b); // (t+b)/(t-b)

	Matrix4 scale;
	scale.data[0][0] = 1 / (fabs(cfg->Get_x_stop()) > fabs(cfg->Get_x_start()) ? fabs(cfg->Get_x_stop()) : fabs(cfg->Get_x_start()));
	scale.data[1][1] = 1 / (fabs(cfg->Get_y_stop()) > fabs(cfg->Get_y_start()) ? fabs(cfg->Get_y_stop()) : fabs(cfg->Get_y_start()));
	scale.data[2][2] = 1;

	Matrix4 transformation = matrix7 * matrix6 * matrix1 * rotateZ * scale;


	if (czyWczytaneDane == true) 
	{
		MyChart.DrawFromFile(&dc, w, h, transformation, punkty);
		
	}
	else if (czyRzut == true)
	{
		if (cfg->Get_F_type() != -1) {

			MyChart.Draw(&dc, w, h, transformation, punkty);
		}
	}

	else if (czyKontur == true)
	{
		if (cfg->Get_F_type() != -1)
		{

			Matrix pom;
			double ScaledX, ScaledY;

			ScaledX = (w - cfg->Get_x_start()) / (cfg->Get_x_stop() - cfg->Get_x_start());
			ScaledY = (h - cfg->Get_y_start()) / (cfg->Get_y_stop() - cfg->Get_y_start());

			pom.data[0][0] = ScaledX;
			pom.data[0][2] = cfg->Get_x_start() - ScaledX * cfg->Get_x_start();
			pom.data[1][1] = ScaledY;
			pom.data[1][2] = cfg->Get_y_start() - ScaledY * cfg->Get_y_start();

			MyChart.Contour(&dc, w, h, pom, punkty);		
		}
	}
}

GUIMyFrame1::~GUIMyFrame1() {}