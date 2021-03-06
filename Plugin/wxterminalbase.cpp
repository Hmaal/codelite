///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Apr 16 2008)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "wxterminalbase.h"

///////////////////////////////////////////////////////////////////////////

wxTerminalBase::wxTerminalBase( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	wxBoxSizer* mainSizer;
	mainSizer = new wxBoxSizer( wxVERTICAL );

	m_textCtrl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_AUTO_URL|wxTE_MULTILINE|wxTE_PROCESS_ENTER|wxTE_PROCESS_TAB|wxTE_RICH2 );
	m_textCtrl->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 76, 90, 90, false, wxEmptyString ) );

	mainSizer->Add( m_textCtrl, 4, wxEXPAND, 5 );

	this->SetSizer( mainSizer );
	this->Layout();
	mainSizer->Fit( this );

	// Connect Events
	m_textCtrl->Connect( wxEVT_KEY_DOWN, wxKeyEventHandler( wxTerminalBase::OnKey ), NULL, this );
	m_textCtrl->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( wxTerminalBase::OnText ), NULL, this );
	m_textCtrl->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( wxTerminalBase::OnEnter ), NULL, this );
	m_textCtrl->Connect( wxEVT_COMMAND_TEXT_URL, wxTextUrlEventHandler( wxTerminalBase::OnURL ), NULL, this );
}

wxTerminalBase::~wxTerminalBase()
{
	// Disconnect Events
	m_textCtrl->Disconnect( wxEVT_KEY_DOWN, wxKeyEventHandler( wxTerminalBase::OnKey ), NULL, this );
	m_textCtrl->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( wxTerminalBase::OnText ), NULL, this );
	m_textCtrl->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( wxTerminalBase::OnEnter ), NULL, this );
	m_textCtrl->Disconnect( wxEVT_COMMAND_TEXT_URL, wxTextUrlEventHandler( wxTerminalBase::OnURL ), NULL, this );
}
