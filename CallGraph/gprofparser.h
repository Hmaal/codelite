/***************************************************************
 * Name:      gprofparser.h
 * Purpose:   Header to create stream parser from gprof. 
 * Author:    Vaclav Sprucek
 * Created:   2012-03-04
 * Copyright: Vaclav Sprucek 
 * License:   wxWidgets license (www.wxwidgets.org)
 * Notes:
 **************************************************************/

#include <wx/wx.h>
#include <wx/string.h> 
#include <wx/stream.h>
#include <wx/txtstrm.h>
//
#include "lineparser.h"
/**
 * @class GprofParser
 * @brief Class define structure for parser to read stream of data from gprof tool.
 */
class GprofParser
{
private:
	wxString readlinetext;
	wxString readlinetexttemp;
	bool lineheader;
	bool primaryline;
	int nameLen;
	char *nameandid;
	bool isdot;
	bool iscycle;
	bool islom;
	bool isplus;	
	
public:
	/**
	 * @brief Defautl constructor.
	 */
	GprofParser();
	/**
	 * @brief Defautl destructor.
	 */
	~GprofParser();
	/**
	 * @brief  List lines type LineParserList.
	 */
	LineParserList lines;
	/**
	 * @brief Function is reading the input stream from gprof application and scan the rows to save to collection of objects lines. 
	 * @param m_pInputStream pointer of type wxInputStream. 
	 */
	void GprofParserStream(wxInputStream *m_pInputStream);
};
