#pragma warning(disable: 4996) // Visual Studio: warning C4996: 'XXX': This function or variable may be unsafe. <- wxcrt.h
#include <fstream>
#include "ConfigClass.h"

using namespace std;

ConfigClass::ConfigClass(GUIMyFrame1* wnd)
{
    MainWindow = wnd;
    x_start = -2;
    x_stop = 2;
    y_start = -2;
    y_stop = 2;
    z_stop = 0;
    z_start = 5;
    F_type = -1;
}