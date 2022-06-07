#include <wx/dc.h>
#include <memory>

#include "ChartClass.h"
#include "vecmat.h"

ChartClass::ChartClass(std::shared_ptr<ConfigClass> c)
{
	cfg = std::move(c);
	x_step = 200;
	y_step = 200;
}

void ChartClass::Set_Range()
{
	double xmin = 9999.9, xmax = -9999.9, ymin = 9999.9, ymax = -9999.9, zmin=9999.9, zmax=-9999.9;
	double x, y,z, stepx, stepy;
	int i,j;

	xmin = cfg->Get_x_start();
	xmax = cfg->Get_x_stop();
	ymin = cfg->Get_y_start();
	ymax = cfg->Get_y_stop();

	stepx = (cfg->Get_x_stop() - cfg->Get_x_start()) / (double)x_step;
	stepy = (cfg->Get_y_stop() - cfg->Get_y_start()) / (double)x_step;
	x = cfg->Get_x_start();
	y = cfg->Get_y_start();

	for (i = 0; i <= x_step; i++)
	{
		for (j = 0; j <= y_step; j++){
			z = GetFunctionValue(x,y);
			if (z > zmax) zmax = z;
			if (z < zmin) zmin = z;
			y += stepy;
		}
			x = x + stepx;
	}

	z_min = zmin;
	z_max = zmax;
	y_min = ymin;
	y_max = ymax;
	x_min = xmin;
	x_max = xmax;
}


double ChartClass::GetFunctionValue(double x,double y)
{
	if (cfg->Get_F_type() == 1) return (x * x + y * y) / 2.0;
	if (cfg->Get_F_type() == 2) return sqrt(x * x - y * y);
	return x * x + y * y;
}

void ChartClass::Draw(wxDC* dc, int w, int h)
{
	
	dc->SetBackground(wxBrush(RGB(255, 255, 255)));
	dc->Clear();
	dc->SetPen(wxPen(RGB(255, 0, 0)));
	//dc->DrawRectangle(10, 10, w - 20, h - 20);
	dc->DrawText(":DDDDD", wxPoint (10, 10));

//	dc->SetClippingRegion(wxRect(10, 10, w - 20, h - 20));

//	dc->SetFont(*wxSMALL_FONT);
//	dc->SetPen(wxPen(RGB(0, 255, 0)));

//	//Matrix transposedMatrix;

//	//if (cfg->RotateScreenCenter())
//		//transposedMatrix = Rotate(w, h) * Move() * Scaling(w, h);
//	//else
//		//transposedMatrix = Move() * Rotate(w, h) * Scaling(w, h);


//	line2d(transposedMatrix, cfg->Get_x_start(), 0, cfg->Get_x_stop(), 0, w, h, dc);
//	line2d(transposedMatrix, 0, Get_Z_min(), 0, Get_Z_max(), w, h, dc);

//	double xMove = 0.8 + static_cast<int>((cfg->Get_x1() - cfg->Get_x0()) / 10);
//	double yMove = 0.8 + static_cast<int>((cfg->Get_y1() - cfg->Get_y0()) / 10);

//	for (double x = x_min; x <= x_max; x += xMove / 2)
//	{
//		line2d(transposedMatrix, x, -0.05, x, 0.05, w, h, dc);
//		line2d(transposedMatrix, x, -0.05, x, 0.05, w, h, dc);
//		//MoveText(dc, transposedMatrix, wxString::Format(wxT("%2.1f"), x), x - 0.02, -0.05, w, h);
//	}

//	line2d(transposedMatrix, x_max, 0, x_max - 0.05, 0 + 0.05, w, h, dc);
//	line2d(transposedMatrix, x_max, 0, x_max - 0.05, 0 - 0.05, w, h, dc);

//	for (double y = y_min; y <= y_max; y += yMove / 2)
//	{
//		line2d(transposedMatrix, -0.05, y, 0.05, y, w, h, dc);
//		//MoveText(dc, transposedMatrix, wxString::Format(wxT("%2.1f"), y), 0.075, y + 0.05, w, h);
//	}

//	line2d(transposedMatrix, 0, y_max, 0 + 0.05, y_max - 0.05, w, h, dc);
//	line2d(transposedMatrix, 0, y_max, 0 - 0.05, y_max - 0.05, w, h, dc);


//	dc->SetPen(wxPen(RGB(0, 0, 255)));

//	double moveRange = (cfg->Get_x1() - cfg->Get_x0()) / x_step;

//	for (double x{ cfg->Get_x_start() }; x < cfg->Get_x_stop(); x += moveRange)
//	{
//		line2d(transposedMatrix, x, GetFunctionValue(x), x + moveRange, GetFunctionValue(x + moveRange), w, h, dc);
//	}


}

void ChartClass::line2d(Matrix t, double x1, double y1, double x2, double y2, int w, int h, wxDC* dc)
{
	Vector begin, end;

	begin.data[0] = x1;
	begin.data[1] = y1;
	begin.data[2] = 1;
	end.data[0] = x2;
	end.data[1] = y2;
	end.data[2] = 1;

	begin = t * begin;
	end = t * end;

	dc->DrawLine(static_cast <wxCoord> (begin.GetX()), static_cast <wxCoord> (h - begin.GetY()), static_cast <wxCoord> (end.GetX()), static_cast <wxCoord> (h - end.GetY()));
}



double ChartClass::Get_Z_min()
{
	Set_Range();
	return z_min;
}

double ChartClass::Get_Z_max()
{
	Set_Range();
	return z_max;
}




//Matrix ChartClass::Move()
//{
//	Matrix pom;
//
//	pom.data[0][0] = pom.data[1][1] = 1;
//	pom.data[0][2] = cfg->Get_dX();
//	pom.data[1][2] = cfg->Get_dY();
//
//	return pom;
//
//}


//Matrix ChartClass::Rotate(int w, int h)
//{
//	Matrix pom;
//
//	pom.data[0][0] = cos(cfg->Get_Alpha() * M_PI / 180.0);
//	pom.data[0][1] = sin(cfg->Get_Alpha() * M_PI / 180.0);
//	pom.data[1][0] = -sin(cfg->Get_Alpha() * M_PI / 180.0);
//	pom.data[1][1] = cos(cfg->Get_Alpha() * M_PI / 180.0);
//
//	if (cfg->RotateScreenCenter())
//	{
//		pom.data[0][2] = (w / 2.0) * (1 - cos(cfg->Get_Alpha() * M_PI / 180.0)) + (h / 2.0) * (sin(-cfg->Get_Alpha() * M_PI / 180.0));
//		pom.data[1][2] = (w / 2.0) * sin(cfg->Get_Alpha() * M_PI / 180.0) + (h / 2.0) * (1 - cos(cfg->Get_Alpha() * M_PI / 180.0));
//	}
//
//	else
//	{
//		Matrix temp = Scaling(w, h);
//		pom.data[0][2] = temp.data[0][2] * (1 - cos(cfg->Get_Alpha() * M_PI / 180.0)) + temp.data[1][2] * (-sin(cfg->Get_Alpha() * M_PI / 180.0));
//		pom.data[1][2] = temp.data[0][2] * sin(cfg->Get_Alpha() * M_PI / 180.0) + temp.data[1][2] * (1 - cos(cfg->Get_Alpha() * M_PI / 180.0));
//	}
//	return pom;
//}


//Matrix ChartClass::Scaling(int w, int h)
//{
//	Matrix pom;
//	double ScaledX, ScaledY;
//
//	ScaledX = (w - x_min) / (cfg->Get_x1() - cfg->Get_x0());
//	ScaledY = (h - y_min) / (cfg->Get_y1() - cfg->Get_y0());
//
//	pom.data[0][0] = ScaledX;
//	pom.data[0][2] = x_min - ScaledX * cfg->Get_x0();
//	pom.data[1][1] = ScaledY;
//	pom.data[1][2] = y_min - ScaledY * cfg->Get_y0();
//
//	return pom;
//
//}



//void ChartClass::MoveText(wxDC* DC, Matrix transposedMatrix, wxString s, double x, double y, int w, int h)
//{
//	Vector v;
//	v.Set(x, y);
//	v = transposedMatrix * v;
//	DC->DrawRotatedText(s, static_cast <wxCoord> (v.GetX()), static_cast <wxCoord> (h - v.GetY()), -cfg->Get_Alpha());
//}
