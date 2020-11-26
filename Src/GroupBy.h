#ifndef _GROUP_BY_H_
#define _GROUP_BY_H_

class GroupBy : public wxApp
{
public:
	const wxString kWndTitle = wxT("GroupBy");

public:
	GroupBy(void);

	virtual ~GroupBy(void);

public:
	virtual bool OnInit() override;

	virtual int OnExit() override;

private:
	class MainWindow* mainWindow_ = nullptr;
};

#endif//_GROUP_BY_H_