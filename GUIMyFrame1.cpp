#include "GUIMyFrame1.h"
#include "ConfigClass.h" 
#include "ChartClass.h"
#include <iostream> 
#include <wx/choice.h>


GUIMyFrame1::GUIMyFrame1(wxWindow* parent) : MyFrame1(parent)
{
	//m_staticText1->SetLabel(_("Uklad Swiata"));
	////m_staticText9->SetLabel(_("Obr\u00F3t"));
	//m_staticText11->SetLabel(_("Wartosci na wykresie:"));
	////WxRB_Middle->SetLabel(_("\u015Arodek ekranu"));
	////WxRB_Center->SetLabel(_("\u015Arodek uk\u0142adu"));
	//m_button1->SetLabel(_("Do uk\u0142adu \u015Bwiata"));
	//cfg = std::make_shared<ConfigClass>(this);
	//Ly_min->SetLabel(wxString::Format(wxT("%2.4lf"), ChartClass(cfg).Get_Y_min()));
	//Ly_max->SetLabel(wxString::Format(wxT("%2.4lf"), ChartClass(cfg).Get_Y_max()));
}

void GUIMyFrame1::mainFormClose(wxCloseEvent& event)
{
	Destroy();
}

void GUIMyFrame1::WxPanel_Repaint(wxUpdateUIEvent& event)
{
	Repaint();
}

void GUIMyFrame1::kontur_click(wxCommandEvent& event)
{
	Close(true);
}

void GUIMyFrame1::rzutPersp_click(wxCommandEvent& event)
{

}

void GUIMyFrame1::wczytajDane_click(wxCommandEvent& event)
{

}

void GUIMyFrame1::zapisz_click(wxCommandEvent& event)
{
	wxFileDialog WxSaveFileDialog(this, _("Choose a file"), _(""), _(""), _("config files (*.cfg)|*.cfg"), wxFD_SAVE);
	if (WxSaveFileDialog.ShowModal() == wxID_OK) cfg->Save((const_cast<char*>((const char*)WxSaveFileDialog.GetPath().mb_str())));
}

void GUIMyFrame1::drukuj_click(wxCommandEvent& event)
{

}

void GUIMyFrame1::funkcja_pick(wxCommandEvent& event)
{
	cfg->Set_F_type(wybor_funkcji->GetSelection());
}

//////////////////////////////////////

void GUIMyFrame1::PrepareData(int fun)
{

}

void GUIMyFrame1::draw_prostopadloscian(double x0, double y0, double x1, double y1)
{

}

void GUIMyFrame1::draw_wykres(int N, float d[100][3], bool Contour, int MappingType, int NoLevels, bool ShowPoints)
{

}

void GUIMyFrame1::Repaint()
{
	wxClientDC dc1(m_panel1);
	wxBufferedDC dc(&dc1);

	ChartClass MyChart(cfg);
	int w, h;
	m_panel1->GetSize(&w, &h);
	MyChart.Draw(&dc, w, h);
}

void GUIMyFrame1::UpdateControls()
{
	//WxEdit_x0->SetLabel(wxString::Format(wxT("%2.1lf"), cfg->Get_x0()));
	//WxEdit_x1->SetLabel(wxString::Format(wxT("%2.1lf"), cfg->Get_x1()));
	//WxEdit_y0->SetLabel(wxString::Format(wxT("%2.1lf"), cfg->Get_y0()));
	//WxEdit_y1->SetLabel(wxString::Format(wxT("%2.1lf"), cfg->Get_y1()));
	//WxEdit_dX->SetLabel(wxString::Format(wxT("%2.1lf"), cfg->Get_dX()));
	//WxEdit_dY->SetLabel(wxString::Format(wxT("%2.1lf"), cfg->Get_dY()));
	//WxEdit_x_start->SetLabel(wxString::Format(wxT("%2.1lf"), cfg->Get_x_start()));
	//WxEdit_x_stop->SetLabel(wxString::Format(wxT("%2.1lf"), cfg->Get_x_stop()));
	//WxScrollBar_alpha->SetThumbPosition(int(cfg->Get_Alpha()));
	//WxStaticText_alpha->SetLabel(wxString::Format(wxT("%d"), WxScrollBar_alpha->GetThumbPosition()));
}

GUIMyFrame1::~GUIMyFrame1() {}