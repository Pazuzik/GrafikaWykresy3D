#ifndef __GUIMyFrame1__
#define __GUIMyFrame1__


#include "GUI.h"
#include "vecmat.h"
#include <wx/filedlg.h>
#include <wx/dcmemory.h>
#include <wx/dcclient.h>
#include <wx/dcbuffer.h>
#include <wx/colourdata.h>
#include <wx/colordlg.h>
#include <wx/msgdlg.h>
#include <wx/rawbmp.h>
#include <wx/choice.h>
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

		void WxEdit_x0_Update(wxCommandEvent& event);
		void WxEdit_x1_Update(wxCommandEvent& event);
		void WxEdit_y0_Update(wxCommandEvent& event);
		void WxEdit_y1_Update(wxCommandEvent& event);
		void WxEdit_z0_Update(wxCommandEvent& event);
		void WxEdit_z1_Update(wxCommandEvent& event);

	public:
		/** Constructor */
		GUIMyFrame1(wxWindow* parent);
	
	
		

	void Repaint();
	~GUIMyFrame1();
	std::shared_ptr<ConfigClass> cfg;
};

#endif // __GUIMyFrame1__
