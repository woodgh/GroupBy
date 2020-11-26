#include "Pch.h"
#include "MainWindow.h"

const int PathOpener = 1;

MainWindow::MainWindow(const wxString& Title)
	: wxFrame(NULL, wxID_ANY, Title, wxDefaultPosition, wxSize(800, 600))
	, vbox_(new wxBoxSizer(wxVERTICAL))
	, targetFolder_(new wxTextCtrl(this, wxID_ANY))
	, explorerBtn_(new wxButton(this, PathOpener, wxT("Explorer"), wxDefaultPosition, wxSize(80, 30)))
	, view_(new wxListCtrl(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_REPORT | wxLC_VIRTUAL))
	, setupBtn_(new wxButton(this, wxID_ANY, wxT("Setup"), wxDefaultPosition, wxSize(80, 30)))
	, runBtn_(new wxToggleButton(this, wxID_ANY, wxT("Run"), wxDefaultPosition, wxSize(80, 30)))
{
	if (vbox_)
	{
		wxBoxSizer* TopBar = new wxBoxSizer(wxHORIZONTAL);

		if (TopBar)
		{
			TopBar->Add(targetFolder_, 1, wxALIGN_CENTER | wxLEFT | wxRIGHT | wxTOP, kInnerBorder);
			TopBar->Add(explorerBtn_, 0, wxRIGHT, kInnerBorder);

			vbox_->Add(TopBar, 0, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, kouterBorder);
		}

		vbox_->Add(-1, kouterBorder);

		wxBoxSizer* MiddleBar = new wxBoxSizer(wxHORIZONTAL);

		if (MiddleBar)
		{
			MiddleBar->Add(view_, 1, wxEXPAND | wxLEFT | wxRIGHT, kInnerBorder);

			vbox_->Add(MiddleBar, 1, wxEXPAND | wxLEFT | wxRIGHT, kouterBorder);
		}
		
		vbox_->Add(-1, kouterBorder);

		wxBoxSizer* BottomBar = new wxBoxSizer(wxHORIZONTAL);

		if (BottomBar)
		{
			BottomBar->Add(setupBtn_, 0, wxALIGN_CENTER | wxLEFT, kInnerBorder);
			BottomBar->Add(new wxPanel(this, -1), 1, wxALIGN_CENTER, kInnerBorder);
			BottomBar->Add(runBtn_, 0, wxALIGN_CENTER | wxRIGHT, kInnerBorder);

			vbox_->Add(BottomBar, 0, wxEXPAND | wxLEFT | wxRIGHT | wxBOTTOM, kouterBorder);
		}

		SetSizer(vbox_);
	}
}

MainWindow::~MainWindow(void)
{
}

bool MainWindow::InitControls(void)
{
	if (targetFolder_)
	{
		targetFolder_->SetWindowStyle(wxBORDER_NONE);
		targetFolder_->SetFocus();

		Connect(PathOpener, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainWindow::onOpen));
	}

	wxListItem Column;

	wxString ColumnTxt[3] = {
		wxT("File"),
		wxT("Datetime"),
		wxT("Target File")
	};

	for (int Idx = 0; Idx != 3; ++Idx)
	{
		Column.SetId(Idx);
		Column.SetText(ColumnTxt[Idx]);
		Column.SetWidth(200);

		view_->InsertColumn(Idx, Column);
	}

	return true;
}

void MainWindow::onOpen(wxCommandEvent& Event)
{
	wxSharedPtr< wxDirDialog > DirOpener (new wxDirDialog(this));
	
	if (DirOpener->ShowModal() == wxID_OK)
		targetFolder_->ChangeValue(DirOpener->GetPath());
}