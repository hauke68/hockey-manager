#ifndef __HOCKEY_MANAGER_H__
#define __HOCKEY_MANAGER_H__

#include <ClanLib/gui.h>

class HockeyManager {

 private:
	bool quit;

	CL_GUIManager gui_manager;

 public:
	void run();
	void on_window_close();
};

#endif
