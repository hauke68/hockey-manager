#ifndef __MAIN_H__
#define __MAIN_H__
#include <ClanLib/application.h>
#include <ClanLib/core.h>
#include <ClanLib/display.h>
#include <ClanLib/gl.h>
#include <ClanLib/gui.h>

#include "user.h"

using namespace std;

class Main {

public:
#ifdef WINDOWS
	int WinMain(const vector<CL_String> &args);
#else
	int main(const vector<CL_String> &args);
#endif
};

#endif
