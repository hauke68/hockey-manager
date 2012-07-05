/*
	This is the player, the user, the boss!
*/

#ifndef _USER_H_
#define _USER_H_

#include <string>

using namespace std;

class User {

 private:
	string name;

 public:
	User();
	User(string);

	int Save();

	string getName();
	string getHome();
};

#endif
