//////////////////////////////////////////////////////////////////////
// This file was auto-generated by codelite's wxCrafter Plugin
// Do not modify this file by hand!
//////////////////////////////////////////////////////////////////////

#ifndef ABBREVIATIONSSETTINGSBASE_BASE_CLASSES_H
#define ABBREVIATIONSSETTINGSBASE_BASE_CLASSES_H

#include <wx/settings.h>
#include <wx/xrc/xmlres.h>
#include <wx/xrc/xh_bmp.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/listbox.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/bannerwindow.h>
#include <wx/stc/stc.h>
#include <wx/checkbox.h>
#include <wx/statline.h>
#include <wx/button.h>

class AbbreviationsSettingsBase : public wxDialog
{
protected:
    wxListBox* m_listBoxAbbreviations;
    wxStaticText* m_staticText1;
    wxTextCtrl* m_textCtrlName;
    wxBannerWindow* m_banner4;
    wxStyledTextCtrl* m_stc;
    wxCheckBox* m_checkBoxImmediateInsert;
    wxStaticLine* m_staticline1;
    wxButton* m_buttonSave;
    wxButton* m_buttonNew;
    wxButton* m_buttonDelete;
    wxButton* m_button5;
    wxButton* m_button6;
    wxButton* m_buttonCancel;

protected:
    virtual void OnItemSelected(wxCommandEvent& event) { event.Skip(); }
    virtual void OnMarkDirty(wxStyledTextEvent& event) { event.Skip(); }
    virtual void OnSave(wxCommandEvent& event) { event.Skip(); }
    virtual void OnSaveUI(wxUpdateUIEvent& event) { event.Skip(); }
    virtual void OnNew(wxCommandEvent& event) { event.Skip(); }
    virtual void OnDelete(wxCommandEvent& event) { event.Skip(); }
    virtual void OnDeleteUI(wxUpdateUIEvent& event) { event.Skip(); }
    virtual void OnImport(wxCommandEvent& event) { event.Skip(); }
    virtual void OnExport(wxCommandEvent& event) { event.Skip(); }

public:
    AbbreviationsSettingsBase(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Abbreviations Settings..."), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(-1,-1), long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER);
    virtual ~AbbreviationsSettingsBase();
};

#endif
