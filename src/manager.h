#ifndef _MANAGER_H_
#define _MANAGER_H_

#include <string>

#include "team.h"

using namespace std;

class Manager {

 private:
	string name;   // Name of manager
	long   income; // Income of manager
	Team   *team;

 public:
	Manager();
	~Manager();

	// Get methods
	string getName();
	long   getIncome();
	Team*  getTeam();

	// Set methods
	void setName(string);
	void setIncome(long);
	void setTeam(Team*);
};

#endif
