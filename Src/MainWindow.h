#ifndef _MAIN_WINDOW_H_
#define _MAIN_WINDOW_H_

class MainWindow : public wxFrame
{
public:
	const int kInnerBorder = 10;
	const int kouterBorder = 10;

public:
	MainWindow(const wxString& Title);

	virtual ~MainWindow(void);

public:
	bool InitControls(void);

private:
	void onOpen(wxCommandEvent& Event);

private:
	wxBoxSizer* vbox_ = nullptr;

	wxTextCtrl* targetFolder_ = nullptr;

	wxButton* explorerBtn_ = nullptr;

	wxListCtrl* view_ = nullptr;

	wxButton* setupBtn_ = nullptr;

	wxToggleButton* runBtn_ = nullptr;
};

#endif//_MAIN_WINDOW_H_