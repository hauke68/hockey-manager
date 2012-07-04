#include <ClanLib/application.h>
#include <ClanLib/core.h>
#include <ClanLib/display.h>
#include <ClanLib/gl.h>
#include <ClanLib/gui.h>

#include <vector>

using namespace std;

class Main {

public:

// Implementation of class Main
#ifdef WINDOWS
	static int WinMain(const vector<CL_String> &args) {
#else
	static int main(const vector<CL_String> &args) {
#endif

		// Setup ClanLib modules
		CL_SetupCore    setup_core;
		CL_SetupDisplay setup_display;
		CL_SetupGL      setup_gl;
		CL_SetupGUI     setup_gui;

		// Start the game here

		return 0;
	}
};

#ifdef WINDOWS
CL_ClanApplication app(&Main::WinMain);
#else
CL_ClanApplication app(&Main::main);
#endif

