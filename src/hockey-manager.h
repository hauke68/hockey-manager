#ifndef __HOCKEY_MANAGER_H__
#define __HOCKEY_MANAGER_H__

class HockeyManager {

 private:
	bool quit;

 public:
	void run();
	void on_window_close();
};

#endif
