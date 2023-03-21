///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Apr 16 2008)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __GUI_H_
#define __GUI_H_

#include <wx/panel.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/checkbox.h>
#include <wx/button.h>
#include <wx/combobox.h>
#include <wx/frame.h>
#include <wx/radiobut.h>
#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/intl.h>
#include <wx/valtext.h>
#include <wx/choice.h>
#include <wx/bitmap.h>
#include <wx/dcbuffer.h>
#include <wx/dcgraph.h>

#include <wx/wxprec.h>
#include <wx/print.h>
#include <wx/printdlg.h>


///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MyFrame1
///////////////////////////////////////////////////////////////////////////////
class MyFrame1 : public wxFrame 
{
	private:
	
	protected:
		
		wxStaticText* ukladWsp_text;
		wxStaticText* x0_text;
		wxTextCtrl* ustaw_x0;
		wxStaticText* y0_text;
		wxTextCtrl* ustaw_y0;
		wxStaticText* x1_text;
		wxTextCtrl* ustaw_x1;
		wxStaticText* y1_text;
		wxTextCtrl* ustaw_y1;
		wxStaticText* z0_text;
		wxTextCtrl* ustaw_z0;
		wxStaticText* z1_text;
		wxTextCtrl* ustaw_z1;
		wxStaticText* kontur_text; // mapa kont. tekst
		wxRadioButton* kontur_choice; // mapa konturowa
		wxStaticText* rzut_text; // rzut persp. tekst
		wxRadioButton* rzut_choice; // rzut perspektywistyczny
		wxButton* wczyt_button; // wczytanie danych
		wxChoice* WxChoice; // wybor funkcji
		wxButton* zapis_button; // zapis
		wxButton* druk_button; // druk

		wxImage myImage;
		wxBitmap myBitmap;
	
		virtual void mainFormClose(wxCloseEvent& event) { event.Skip(); }
		virtual void WxPanel_Repaint(wxUpdateUIEvent& event) { event.Skip(); }
		virtual void kontur_click(wxCommandEvent& event) { event.Skip(); }
		virtual void rzutPersp_click(wxCommandEvent& event) { event.Skip(); }
		virtual void wczytajDane_click(wxCommandEvent& event) { event.Skip(); }
		virtual void zapisz_click(wxCommandEvent& event) { event.Skip(); }
		virtual void drukuj_click(wxCommandEvent& event) { event.Skip(); }
		virtual void funkcja_pick(wxCommandEvent& event) { event.Skip(); }

		virtual void WxEdit_x0_Update(wxCommandEvent& event) { event.Skip(); }
		virtual void WxEdit_x1_Update(wxCommandEvent& event) { event.Skip(); }
		virtual void WxEdit_y0_Update(wxCommandEvent& event) { event.Skip(); }
		virtual void WxEdit_y1_Update(wxCommandEvent& event) { event.Skip(); }
		virtual void WxEdit_z0_Update(wxCommandEvent& event) { event.Skip(); }
		virtual void WxEdit_z1_Update(wxCommandEvent& event) { event.Skip(); }


	public:
		wxPanel* m_panel1;
		MyFrame1( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = "Projekt 7: Wykresy 3D - Kowalczyk, Sulima, Wronka", const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 689,427 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		~MyFrame1();
	
};

#endif //__GUI_H_
