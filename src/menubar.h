#ifndef __MENUBAR_H__
#define __MENUBAR_H__

#include <ClanLib/gui.h>

class MenuBar : public CL_Window {

 public:
	MenuBar(CL_GUIManager &manager, CL_ResourceManager &application_resources);

 private:
	CL_MenuBar *mainmenubar;
};

#endif
