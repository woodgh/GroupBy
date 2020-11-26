#include "Pch.h"
#include "MainWindow.h"
#include "GroupBy.h"

GroupBy::GroupBy(void)
	: mainWindow_(new MainWindow(kWndTitle))
{
}

GroupBy::~GroupBy(void)
{
}

bool GroupBy::OnInit()
{
	if (mainWindow_ == nullptr)
		return false;

	mainWindow_->Centre();
	mainWindow_->SetMinSize(wxSize(300, 400));
	mainWindow_->SetBackgroundColour(wxColor(wxT("#ffffff")));

	if (mainWindow_->InitControls() == false)
		return false;

	if (mainWindow_->Show() == false)
		return false;

	return true;
}

int GroupBy::OnExit()
{
	return EXIT_SUCCESS;
}

IMPLEMENT_APP(GroupBy)