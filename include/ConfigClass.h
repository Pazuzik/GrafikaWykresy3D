////!!!!
#ifndef __ConfigClass__
#define __ConfigClass__

#include "GUIMyFrame1.h"

class ConfigClass
{
    private:
        GUIMyFrame1 *MainWindow;   // wskaznik do glownego okna aplikacji
        double x_start, x_stop; // zakres zmiennosci argumentu funkcji x
        double y_start, y_stop; // zakres zmiennosci argumentu funkcji y
        double z_start, z_stop; // zakres zmiennosci argumentu funkcji z
        int F_type;             // rodzaj obliczanej funkcji

    public:
        ConfigClass(GUIMyFrame1 *wnd);
        double Get_x_start(){return x_start;};
        void   Set_x_start(double v){x_start=v;};
        double Get_x_stop(){return x_stop;};
        void   Set_x_stop(double v){x_stop=v;};

        double Get_y_start() { return y_start; };
        void   Set_y_start(double v) { y_start = v; };
        double Get_y_stop() { return y_stop; };
        void   Set_y_stop(double v) { y_stop = v; };

        double Get_z_start() { return z_start; };
        void   Set_z_start(double v) {z_start = v;};
        double Get_z_stop() { return z_stop; };
        void   Set_z_stop(double v) { z_stop = v;};

        int  Get_F_type(){return F_type;};
        void Set_F_type(int i){F_type=i;};
        
};

#endif