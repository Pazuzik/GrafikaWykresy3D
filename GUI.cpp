///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Apr 16 2008)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "GUI.h"

///////////////////////////////////////////////////////////////////////////

MyFrame1::MyFrame1( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );
	
	m_panel1 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	bSizer3->Add( m_panel1, 1, wxEXPAND | wxALL, 5 );
	
	bSizer2->Add( bSizer3, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxVERTICAL );
	
	ukladWsp_text = new wxStaticText( this, wxID_ANY, wxT("Uklad wspolrzednych"), wxDefaultPosition, wxDefaultSize, 0 );
	ukladWsp_text->Wrap( -1 );
	bSizer5->Add(ukladWsp_text, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxHORIZONTAL );
	
	//////////////////////////////////////////////////////////////

	x0_text = new wxStaticText( this, wxID_ANY, wxT("x0:"), wxDefaultPosition, wxDefaultSize, 0 );
	x0_text->Wrap( -1 );
	bSizer6->Add(x0_text, 0, wxALL, 5 );
	
	ustaw_x0 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 20,-1 ), 0 );
	bSizer6->Add(ustaw_x0, 0, wxALL, 2 );
	
	y0_text = new wxStaticText( this, wxID_ANY, wxT("y0:"), wxDefaultPosition, wxDefaultSize, 0 );
	y0_text->Wrap( -1 );
	bSizer6->Add(y0_text, 0, wxALL, 5 );
	
	ustaw_y0 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 20,-1 ), 0 );
	bSizer6->Add(ustaw_y0, 0, wxALL, 2 );
	
	bSizer5->Add( bSizer6, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxHORIZONTAL );
	
	x1_text = new wxStaticText( this, wxID_ANY, wxT("x1:"), wxDefaultPosition, wxDefaultSize, 0 );
	x1_text->Wrap( -1 );
	bSizer10->Add(x1_text, 0, wxALL, 5 );
	
	ustaw_x1 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 20,-1 ), 0 );
	bSizer10->Add(ustaw_x1, 0, wxALL, 2 );
	
	y1_text = new wxStaticText( this, wxID_ANY, wxT("y1:"), wxDefaultPosition, wxDefaultSize, 0 );
	y1_text->Wrap( -1 );
	bSizer10->Add(y1_text, 0, wxALL, 5 );
	
	ustaw_y1 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 20,-1 ), 0 );
	bSizer10->Add(ustaw_y1, 0, wxALL, 2 );
	
	bSizer5->Add( bSizer10, 1, wxEXPAND, 5 );
	
	/////////////////////////////////////////////////////////

	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxHORIZONTAL );
	
	kontur_text = new wxStaticText( this, wxID_ANY, wxT("Mapa konturowa"), wxDefaultPosition, wxDefaultSize, 0 );
	kontur_text->Wrap( -1 );
	bSizer8->Add(kontur_text, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	kontur_choice = new wxRadioButton( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	
	bSizer8->Add(kontur_choice, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	bSizer5->Add( bSizer8, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxHORIZONTAL );
	
	rzut_text = new wxStaticText( this, wxID_ANY, wxT("Rzut perspektywiczny"), wxDefaultPosition, wxDefaultSize, 0 );
	rzut_text->Wrap( -1 );
	bSizer11->Add(rzut_text, 0, wxALL, 5 );
	
	rzut_choice = new wxRadioButton( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	
	bSizer11->Add(rzut_choice, 0, wxALL, 5 );
	
	bSizer5->Add( bSizer11, 1, wxEXPAND, 5 );

	//////////////////////////////////////////////////////////////////////
	
	wxBoxSizer* bSizer12;
	bSizer12 = new wxBoxSizer( wxHORIZONTAL );
	
	wczyt_button = new wxButton( this, wxID_ANY, wxT("Wczytaj dane"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer12->Add(wczyt_button, 0, wxALL, 5 );
	
	wybor_funkcji = new wxComboBox( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	bSizer12->Add(wybor_funkcji, 0, wxALL, 5 );

	wybor_funkcji->Append("f(x) = x^2 - y^2 = 2z");
	wybor_funkcji->Append("f(x) = x^2 + y^2 = z^2");
	wybor_funkcji->Append("f(x) = x^2 + y^2 = z");
	
	bSizer5->Add( bSizer12, 1, wxEXPAND, 5 );
	
	//////////////////////////////////////////////////////

	wxBoxSizer* bSizer13;
	bSizer13 = new wxBoxSizer( wxHORIZONTAL );
	
	maximum_text = new wxStaticText( this, wxID_ANY, wxT("ymax:"), wxDefaultPosition, wxDefaultSize, 0 );
	maximum_text->Wrap( -1 );
	bSizer13->Add(maximum_text, 0, wxALL, 5 );
	
	minimum_text = new wxStaticText( this, wxID_ANY, wxT("ymin:"), wxDefaultPosition, wxDefaultSize, 0);
	minimum_text->Wrap( -1 );
	bSizer13->Add(minimum_text, 0, wxALL, 5 );
	
	bSizer5->Add( bSizer13, 1, wxEXPAND, 5 );

	///////////////////////////////////////////////
	
	wxBoxSizer* bSizer14;
	bSizer14 = new wxBoxSizer( wxHORIZONTAL );
	
	zapis_button = new wxButton( this, wxID_ANY, wxT("Zapisz"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer14->Add( zapis_button, 0, wxALL, 5 );
	
	druk_button = new wxButton( this, wxID_ANY, wxT("Drukuj"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer14->Add( druk_button, 0, wxALL, 5 );
	
	bSizer5->Add( bSizer14, 1, wxEXPAND, 5 );
	
	bSizer2->Add( bSizer5, 1, wxEXPAND, 5 );
	
	this->SetSizer( bSizer2 );
	this->Layout();


	this->Connect(wxEVT_CLOSE_WINDOW, wxCloseEventHandler(MyFrame1::mainFormClose));
	m_panel1->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(MyFrame1::WxPanel_Repaint), NULL, this);
	kontur_choice->Connect(wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler(MyFrame1::kontur_click), NULL, this);
	rzut_choice->Connect(wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler(MyFrame1::rzutPersp_click), NULL, this);
	m_panel1->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(MyFrame1::WxPanel_Repaint), NULL, this);
	wczyt_button->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame1::wczytajDane_click), NULL, this);
	zapis_button->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame1::zapisz_click), NULL, this);
	druk_button->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame1::drukuj_click), NULL, this);
}


MyFrame1::~MyFrame1()
{
	this->Disconnect(wxEVT_CLOSE_WINDOW, wxCloseEventHandler(MyFrame1::mainFormClose));
	m_panel1->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(MyFrame1::WxPanel_Repaint), NULL, this);
	kontur_choice->Disconnect(wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler(MyFrame1::kontur_click), NULL, this);
	rzut_choice->Disconnect(wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler(MyFrame1::rzutPersp_click), NULL, this);
	m_panel1->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(MyFrame1::WxPanel_Repaint), NULL, this);
	wczyt_button->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame1::wczytajDane_click), NULL, this);
	zapis_button->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame1::zapisz_click), NULL, this);
	druk_button->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame1::drukuj_click), NULL, this);
}


