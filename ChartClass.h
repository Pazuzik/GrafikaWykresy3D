#ifndef __ChartClass__
#define __ChartClass__

#include <memory>
#include "ConfigClass.h"

class Matrix;

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
    // powyzej sugerowana funkcja transformujaca odcinki (jesli ktos ma
    // inny pomysl mozna ja usunac)

public:
    ChartClass(std::shared_ptr<ConfigClass> c);

    void Set_Range();   // ustala wartosci zmiennych x_min,y_min,z_min,x_max,y_max,z_max
    double Get_Z_min(); // zwraca z_min
    double Get_Z_max(); // zwraca z_max
    void Draw(wxDC* dc, int w, int h);  // rysuje wykres

    //Matrix Rotate(int w, int h); // macierz przejscia obrotu
    //Matrix Scaling(int x, int y); // macierz przejscia skalowania
    //Matrix Move(); // macierz przejscia przesuniecia wzdluz osi

    //void MoveText(wxDC* DC, Matrix transposedMatrix, wxString s, double x, double y, int w, int h); // rysowanie tekstu


};

#endif