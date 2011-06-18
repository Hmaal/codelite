#include "code_completion_manager.h"
#include "clang_code_completion.h"
#include "tags_options_data.h"
#include <vector>
#include "ctags_manager.h"
#include "entry.h"

static CodeCompletionManager ms_CodeCompletionManager;

CodeCompletionManager::CodeCompletionManager()
	: m_options(CC_CTAGS_ENABLED)
{
}

CodeCompletionManager::~CodeCompletionManager()
{
}

void CodeCompletionManager::WordCompletion(LEditor *editor, const wxString& expr, const wxString& word)
{
	wxString expression = expr;
	wxString tmp;
	
	DoUpdateOptions();
	
	// Trim whitespace from right and left
	static wxString trimString(wxT("!<>=(){};\r\n\t\v "));
	
	expression = expression.erase(0, expression.find_first_not_of(trimString));
	expression = expression.erase(expression.find_last_not_of(trimString)+1);
		
	if(expression.EndsWith(word, &tmp)) {
		expression = tmp;
	}
	
	if(expression.IsEmpty()) {
		// Currently, we always do ctags word completion for empty expressions
		DoCtagsWordCompletion(editor, expr, word);
		
	} else {
		DoClangWordCompletion(editor);
	}
}

CodeCompletionManager& CodeCompletionManager::Get()
{
	return ms_CodeCompletionManager;
}

bool CodeCompletionManager::DoCtagsWordCompletion(LEditor* editor, const wxString& expr, const wxString& word)
{
	std::vector<TagEntryPtr> candidates;
	//get the full text of the current page
	wxString text = editor->GetTextRange    (0, editor->GetCurrentPosition());
	int lineNum   = editor->LineFromPosition(editor->GetCurrentPosition())+1;

	if(TagsManagerST::Get()->WordCompletionCandidates(editor->GetFileName(), lineNum, expr, text, word, candidates) && !candidates.empty()) {
		editor->ShowCompletionBox(candidates, word, false);
		return true;
	}
	return false;
}

void CodeCompletionManager::DoClangWordCompletion(LEditor* editor)
{
	ClangCodeCompletion::Instance()->WordComplete(editor);
}

bool CodeCompletionManager::DoCtagsCalltip(LEditor* editor, int line, const wxString &expr, const wxString &text, const wxString &word)
{
	// Get the calltip
	clCallTipPtr tip = TagsManagerST::Get()->GetFunctionTip(editor->GetFileName(), line, expr, text, word);
	if(!tip || !tip->Count()) {
		// try the Clang engine...
		return false;
	}
	editor->ShowCalltip(tip);
	return true;
}

void CodeCompletionManager::DoClangCalltip(LEditor* editor)
{
	ClangCodeCompletion::Instance()->Calltip(editor);
}

void CodeCompletionManager::Calltip(LEditor* editor, int line, const wxString& expr, const wxString& text, const wxString& word)
{
	bool res (false);
	DoUpdateOptions();
	if(GetOptions() & CC_CTAGS_ENABLED) {
		res = DoCtagsCalltip(editor, line, expr, text, word);
	}

	if(!res && (GetOptions() & CC_CLANG_ENABLED)) {
		DoClangCalltip(editor);
	}
}

void CodeCompletionManager::CodeComplete(LEditor* editor, int line, const wxString& expr, const wxString& text)
{
	bool res (false);
	DoUpdateOptions();
	if(GetOptions() & CC_CTAGS_ENABLED) {
		res = DoCtagsCodeComplete(editor, line, expr, text);
	}

	if(!res && (GetOptions() & CC_CLANG_ENABLED)) {
		DoClangCodeComplete(editor);
	}
}

void CodeCompletionManager::DoClangCodeComplete(LEditor* editor)
{
	ClangCodeCompletion::Instance()->CodeComplete(editor);
}

bool CodeCompletionManager::DoCtagsCodeComplete(LEditor* editor, int line, const wxString& expr, const wxString& text)
{
	std::vector<TagEntryPtr> candidates;
	if (TagsManagerST::Get()->AutoCompleteCandidates(editor->GetFileName(), line, expr, text, candidates) && !candidates.empty()) {
		editor->ShowCompletionBox(candidates, wxEmptyString, false);
		return true;
	}
	return false;
}

void CodeCompletionManager::DoUpdateOptions()
{
	m_options = CC_CTAGS_ENABLED | CC_CLANG_ENABLED;
	const TagsOptionsData& options = TagsManagerST::Get()->GetCtagsOptions();
	
	// Incase CLANG is set as the main CC engine, remove the CTAGS options BUT 
	// only if CLANG is enabled...
	if((options.GetClangOptions() & CC_CLANG_FIRST) && (options.GetClangOptions() & CC_CLANG_ENABLED)) {
		m_options &= ~CC_CTAGS_ENABLED;
		m_options |= CC_CLANG_ENABLED;
	}
	
}