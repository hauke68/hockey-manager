#include "menubar.h"

MenuBar::MenuBar(CL_GUIManager &manager, CL_ResourceManager &application_resources) : CL_Window(&manager, CL_GUITopLevelDescription("Menu Bar & Status Bar", CL_Rect(512 + 24, 256 + 16, CL_Size(256, 180)), false)) {

	mainmenubar = new CL_MenuBar(this);
}

