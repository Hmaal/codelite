//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//
// copyright            : (C) 2008 by Eran Ifrah
// file name            : findinfilesdlg.h
//
// -------------------------------------------------------------------------
// A
//              _____           _      _     _ _
//             /  __ \         | |    | |   (_) |
//             | /  \/ ___   __| | ___| |    _| |_ ___
//             | |    / _ \ / _  |/ _ \ |   | | __/ _ )
//             | \__/\ (_) | (_| |  __/ |___| | ||  __/
//              \____/\___/ \__,_|\___\_____/_|\__\___|
//
//                                                  F i l e
//
//    This program is free software; you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation; either version 2 of the License, or
//    (at your option) any later version.
//
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
#ifndef FIND_IN_FILES_DLG_H
#define FIND_IN_FILES_DLG_H

#include "findinfiles_dlg.h"
#include "findreplacedlg.h"
#include "search_thread.h"

class FindInFilesDialog : public FindInFilesDialogBase
{
    FindReplaceData m_data;
protected:
    void       DoSearch();
    void       DoSearchReplace();
    void       DoSaveSearchPaths();
    SearchData DoGetSearchData();
    void       DoSaveOpenFiles();
    void       DoSetFileMask();

    // Event Handlers
    virtual void OnClick(wxCommandEvent &event);
    virtual void OnClose(wxCloseEvent &event);
    virtual void OnAddPath( wxCommandEvent& event );
    virtual void OnRemovePath( wxCommandEvent& event );
    virtual void OnClearPaths( wxCommandEvent& event );
    virtual void OnClearPathsUI( wxUpdateUIEvent& event );
    virtual void OnRemovePathUI( wxUpdateUIEvent& event );

    virtual void OnFindWhatUI( wxUpdateUIEvent& event );

    void OnUseDiffColourForCommentsUI(wxUpdateUIEvent& event);

public:
    FindInFilesDialog(wxWindow* parent, const wxString &dataName);
    virtual ~FindInFilesDialog();
    void SetRootDir   (const wxString &rootDir);

    FindReplaceData& GetData() {
        return m_data;
    }
    
    const FindReplaceData& GetData() const {
        return m_data;
    }
    virtual bool Show();
};

#endif // FIND_IN_FILES_DLG_H
