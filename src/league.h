#ifndef _LEAGUE_H_
#define _LEAGUE_H_

#include <string>
#include <vector>

#include "team.h"

using namespace std;

class League {

 private:
	string       name;
	int          max_teams;
	vector<Team> *teams;

 public:
	League();
	~League();

	// Get methods
	string getName();
	int getMaxTeams();

	// Set methods
	void setName(string);
	void setMaxTeams(int);
};

#endif
