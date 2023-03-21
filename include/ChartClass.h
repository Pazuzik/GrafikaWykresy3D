#ifndef __ChartClass__
#define __ChartClass__

#include <memory>
#include <vector>
#include "ConfigClass.h"

class Matrix4;

class ChartClass
{
private:
    std::shared_ptr<ConfigClass> cfg;
    int x_step;         // liczba odcinkow z jakich bedzie sie skladal wykres
    int y_step;
    double x_min, x_max; // zakres zmiennej x
    double y_min, y_max; // zakres zmiennej y
    double z_min, z_max; // zakres wartosci przyjmowanych przez funkcje
    double GetFunctionValue(double x, double y); // zwraca wartosci rysowanej funkcji

    void line2d(Matrix t, double x1, double y1, double x2, double y2, int w, int h, wxDC* dc);
    void line3d(Matrix4 t, double x1, double y1, double z1, double x2, double y2, double z2, int w, int h, wxDC* dc);
 

public:
    ChartClass(std::shared_ptr<ConfigClass> c);

    double Get_x_step() { return x_step; }
    double Get_y_step() { return y_step; }
    void Draw(wxDC* dc, int w, int h, Matrix4 t, std::vector<Point>& punkty);  // rysuje wykres
    void Contour(wxDC* dc, int w, int h, Matrix t, std::vector<Point>& punkty); // rysuje mape 
    void DrawFromFile(wxDC* dc, int w, int h, Matrix4 t, std::vector<Point>& punkty); // rysuje z danych wczytanych z pliku
};

#endif