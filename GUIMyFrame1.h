#ifndef __GUIMyFrame1__
#define __GUIMyFrame1__


#include "GUI.h"
#include <wx/filedlg.h>
#include <wx/dcmemory.h>
#include <wx/dcclient.h>
#include <wx/dcbuffer.h>
#include <wx/colourdata.h>
#include <wx/colordlg.h>
#include <wx/msgdlg.h>
#include <wx/rawbmp.h>
#include <memory>

class ConfigClass;

/** Implementing MyFrame1 */
class GUIMyFrame1 : public MyFrame1
{
	protected:
		// Handlers for MyFrame1 events.
		void mainFormClose(wxCloseEvent& event);
		void WxPanel_Repaint(wxUpdateUIEvent& event);
		void kontur_click(wxCommandEvent& event);
		void rzutPersp_click(wxCommandEvent& event);
		void wczytajDane_click(wxCommandEvent& event);
		void zapisz_click(wxCommandEvent& event);
		void drukuj_click(wxCommandEvent& event);
		void funkcja_pick(wxCommandEvent& event);
	public:
		/** Constructor */
		GUIMyFrame1(wxWindow* parent);
	
		//wxBitmap MemoryBitmap;
		//wxImage image;
		//float   function_data[100][3];
	
		void draw_prostopadloscian(double x0, double y0, double x1, double y1);
		void PrepareData(int fun);
		void draw_wykres(int N, float d[100][3], bool Contour, int MappingType, int NoLevels, bool ShowPoints);

	void Repaint();
	void UpdateControls();
	~GUIMyFrame1();
	std::shared_ptr<ConfigClass> cfg;
};

#endif // __GUIMyFrame1__
