#include <wx/dc.h>
#include <memory>
#include "ChartClass.h"
#include <vector>
#include <algorithm>


ChartClass::ChartClass(std::shared_ptr<ConfigClass> c)
{
	cfg = std::move(c);
	if ((cfg->Get_x_start() - cfg->Get_x_stop()) > 8)
	{
		x_step = abs(8 * (cfg->Get_x_start() - cfg->Get_x_stop())) / 3;
		y_step = abs(8 * (cfg->Get_y_start() - cfg->Get_y_stop())) / 3;
	}
	else
	{
		x_step = abs(100 * (cfg->Get_x_start() - cfg->Get_x_stop())) / 3;
		y_step = abs(100 * (cfg->Get_y_start() - cfg->Get_y_stop())) / 3;
	}
	
}


double ChartClass::GetFunctionValue(double x,double y)
{
	if (cfg->Get_F_type() == 1) return sqrt(x * x + y * y);
	else if (cfg->Get_F_type() == 2) return x * x + y * y;
	else if (cfg->Get_F_type() == 0) return x * x;
	else return -9999;
}


void ChartClass::Contour(wxDC* dc, int w, int h, Matrix t, std::vector<Point>& punkty)
{
	punkty.clear();

	dc->SetBackground(wxBrush(RGB(255, 255, 255)));
	dc->Clear();

	double moveRangeX = (cfg->Get_x_stop() - cfg->Get_x_start()) / Get_x_step();
	double moveRangeY = (cfg->Get_y_stop() - cfg->Get_y_start()) / Get_y_step();

	for (double x{cfg->Get_x_start()}; x < cfg->Get_x_stop(); x += moveRangeX)
	{
		for (double y{cfg->Get_y_start()}; y < cfg->Get_y_stop(); y += moveRangeY)
		{
			double z_min = GetFunctionValue(x, y);
			double temp = fabs(z_min - std::round(z_min));
			if (std::round(z_min) == 0 && temp < 0.001){
				punkty.push_back(Point(x, y, std::round(z_min)));
			}
			else if (temp < 0.03 && std::round(z_min) != 0) {
				punkty.push_back(Point(x, y, std::round(z_min)));
			}
		}
	}

	dc->SetPen(wxPen(RGB(255, 0, 0)));
	for (int i = 1; i < punkty.size(); i++) 
	{
		line2d(t, punkty[i-1].x, punkty[i - 1].y, punkty[i-1].x+0.01, punkty[i-1].y+0.01, w, h, dc);
	}


	dc->SetPen(wxPen(RGB(0, 0, 255)));
	line2d(t, (fabs(cfg->Get_x_stop()) > fabs(cfg->Get_x_start()) ? -fabs(cfg->Get_x_stop()) : -fabs(cfg->Get_x_start())), 0, (fabs(cfg->Get_x_stop()) > fabs(cfg->Get_x_start()) ? fabs(cfg->Get_x_stop()) : fabs(cfg->Get_x_start())), 0, w, h, dc);
	dc->SetPen(wxPen(RGB(0, 255, 0)));
	line2d(t, 0, (fabs(cfg->Get_y_stop()) > fabs(cfg->Get_y_start()) ? -fabs(cfg->Get_y_stop()) : -fabs(cfg->Get_y_start())), 0, (fabs(cfg->Get_y_stop()) > fabs(cfg->Get_y_start()) ? fabs(cfg->Get_y_stop()) : fabs(cfg->Get_y_start())), w, h, dc);
}


void ChartClass::Draw(wxDC* dc, int w, int h, Matrix4 t, std::vector<Point>& punkty)
{
	punkty.clear();

	dc->SetBackground(wxBrush(RGB(255, 255, 255)));
	dc->Clear();
	
	double moveRangeX = (cfg->Get_x_stop() - cfg->Get_x_start()) / Get_x_step();
	double moveRangeY = (cfg->Get_y_stop() - cfg->Get_y_start()) / Get_y_step();


	for (double x{cfg->Get_x_start()}; x < cfg->Get_x_stop(); x += moveRangeX)
	{
		for (double y{cfg->Get_y_start()}; y < cfg->Get_y_stop(); y += moveRangeY)
		{
			punkty.push_back(Point(x, y, GetFunctionValue(x, y)));
		}
	}



	dc->SetPen(wxPen(RGB(0, 0, 255)));
	line3d(t, (fabs(cfg->Get_x_stop()) > fabs(cfg->Get_x_start()) ? -fabs(cfg->Get_x_stop()) : -fabs(cfg->Get_x_start())), 0, 0, (fabs(cfg->Get_x_stop()) > fabs(cfg->Get_x_start()) ? fabs(cfg->Get_x_stop()) : fabs(cfg->Get_x_start())), 0, 0, w, h, dc);
	dc->SetPen(wxPen(RGB(0, 255, 0)));
	line3d(t, 0, (fabs(cfg->Get_y_stop()) > fabs(cfg->Get_y_start()) ? -fabs(cfg->Get_y_stop()) : -fabs(cfg->Get_y_start())), 0, 0, (fabs(cfg->Get_y_stop()) > fabs(cfg->Get_y_start()) ? fabs(cfg->Get_y_stop()) : fabs(cfg->Get_y_start())), 0, w, h, dc);
	dc->SetPen(wxPen(RGB(0, 0, 0)));
	line3d(t, 0, 0, 0, 0, 0, 20, w, h, dc);
	


	dc->SetPen(wxPen(RGB(255, 0, 0)));
	for (int i = 1; i < punkty.size(); i++)
	{
		if (!(punkty[i - 1].z > cfg->Get_z_start()) && !(punkty[i].z < cfg->Get_z_stop()))
			line3d(t, punkty[i - 1].x, punkty[i - 1].y, punkty[i - 1].z, punkty[i - 1].x + moveRangeX, punkty[i - 1].y + moveRangeY, punkty[i - 1].z, w, h, dc);
	}

	
}

void ChartClass::DrawFromFile(wxDC* dc, int w, int h, Matrix4 t, std::vector<Point> &punkty)
{
	dc->SetBackground(wxBrush(RGB(255, 255, 255)));
	dc->Clear();
	dc->SetPen(wxPen(RGB(255, 0, 0)));

	double moveRangeX = (cfg->Get_x_stop() - cfg->Get_x_start()) / Get_x_step();
	double moveRangeY = (cfg->Get_y_stop() - cfg->Get_y_start()) / Get_y_step();

	dc->SetPen(wxPen(RGB(255, 0, 0)));
	for (int i = 1; i < punkty.size(); i++)
	{
		if (!(punkty[i-1].z > cfg->Get_z_start()) && !(punkty[i].z < cfg->Get_z_stop()))
			line3d(t, punkty[i - 1].x, punkty[i - 1].y, punkty[i - 1].z, punkty[i - 1].x + moveRangeX, punkty[i - 1].y + moveRangeY, punkty[i - 1].z, w, h, dc);
	}

	dc->SetPen(wxPen(RGB(0, 0, 255)));
	line3d(t, (fabs(cfg->Get_x_stop()) > fabs(cfg->Get_x_start()) ? -fabs(cfg->Get_x_stop()) : -fabs(cfg->Get_x_start())), 0, 0, (fabs(cfg->Get_x_stop()) > fabs(cfg->Get_x_start()) ? fabs(cfg->Get_x_stop()) : fabs(cfg->Get_x_start())), 0, 0, w, h, dc);
	dc->SetPen(wxPen(RGB(0, 255, 0)));
	line3d(t, 0, (fabs(cfg->Get_y_stop()) > fabs(cfg->Get_y_start()) ? -fabs(cfg->Get_y_stop()) : -fabs(cfg->Get_y_start())), 0, 0, (fabs(cfg->Get_y_stop()) > fabs(cfg->Get_y_start()) ? fabs(cfg->Get_y_stop()) : fabs(cfg->Get_y_start())), 0, w, h, dc);
	dc->SetPen(wxPen(RGB(0, 0, 0)));
	if (punkty.size() > 0)
	{
		float z_range = (*std::max_element(punkty.begin(), punkty.end(), [](const Point& a, const Point& b) { return fabs(a.z) < fabs(b.z); })).z;
		line3d(t, 0, 0, -z_range, 0, 0, z_range * 1.8, w, h, dc);
	}
	else
	{
		float z_range = 99;
		line3d(t, 0, 0, -z_range, 0, 0, z_range * 1.8, w, h, dc);
	}
}


void ChartClass::line3d(Matrix4 t, double x1, double y1, double z1, double x2, double y2, double z2, int w, int h, wxDC* dc)
{
	Vector4 begin, end;

	begin.data[0] = x1;
	begin.data[1] = y1;
	begin.data[2] = z1/4;
	begin.data[3] = 1;
	end.data[0] = x2;
	end.data[1] = y2;
	end.data[2] = z2/4;
	end.data[3] = 1;

	begin = t * begin;
	end = t * end;


	dc->DrawLine(static_cast <wxCoord> (begin.GetX()/begin.data[3]), static_cast <wxCoord> ((h - begin.GetY())/ begin.data[3]), static_cast <wxCoord> (end.GetX()/ end.data[3]), static_cast <wxCoord> ((h - end.GetY())/ end.data[3]));
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

	dc->DrawLine(static_cast <wxCoord> (begin.GetX()), static_cast <wxCoord> ((h - begin.GetY())), static_cast <wxCoord> (end.GetX()), static_cast <wxCoord> ((h - end.GetY())));
}