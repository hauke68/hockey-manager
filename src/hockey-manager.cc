#include <ClanLib/core.h>
#include <ClanLib/display.h>

#include "hockey-manager.h"

void HockeyManager::run() {

	quit = false;

	CL_DisplayWindow window("Hockey Manager", 640, 480);

	CL_Slot slot_quit = window.sig_window_close().connect(this, &HockeyManager::on_window_close);
	CL_GraphicContext gc = window.get_gc();
	CL_InputDevice keyboard = window.get_ic().get_keyboard();

	while(!quit) {
		if(keyboard.get_keycode(CL_KEY_ESCAPE) == true)
			quit = true;

		window.flip();

		CL_KeepAlive::process();
		CL_System::sleep(10);
	}
}

void HockeyManager::on_window_close() {

	quit = true;
}
