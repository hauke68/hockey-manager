#include <ClanLib/core.h>
#include <ClanLib/display.h>
#include <ClanLib/gui.h>

#include "hockey-manager.h"
#include "menubar.h"

void HockeyManager::run() {

	quit = false;

	CL_DisplayWindow main_window("Hockey Manager", 640, 480);

	CL_Slot slot_quit = main_window.sig_window_close().connect(this, &HockeyManager::on_window_close);
	CL_GraphicContext gc = main_window.get_gc();
	CL_InputDevice keyboard = main_window.get_ic().get_keyboard();

	CL_GUIManager gui(main_window);
	CL_GUIWindowManager wm = gui.get_window_manager();
	CL_Window window(&gui, CL_GUITopLevelDescription("Menu Bar & Status Bar", CL_Rect(512 + 24, 256 + 16, CL_Size(256, 180)), false));

	while(!gui.get_exit_flag()) {
		gui.process_messages(0);
		// wm.draw_windows(gc);
		main_window.flip();
		CL_KeepAlive::process();
	}

	return;

	while(!quit) {
		if(keyboard.get_keycode(CL_KEY_ESCAPE) == true)
			quit = true;

		main_window.flip();

		CL_KeepAlive::process();
		CL_System::sleep(10);
	}
}

void HockeyManager::on_window_close() {

	quit = true;
}
