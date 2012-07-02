#ifndef TEAM_H
#define TEAM_H

#include <vector>
#include <string>

#include "player.h"

using namespace std;

typedef vector<Player*> VPlayer;

class Team {

 private:
	long   id;
	string name;
	long   money;  // Team's money

	VPlayer *players; // Team's players

 public:
	Team();
	~Team();

	void addPlayer(Player*);

	// Get methods
	long   getId();
	string getName();
	long   getMoney();
	VPlayer* getPlayers();
	Player* getPlayer(string);

	// Set methods
	void setId(long);
	void setName(string);
	void setMoney(long);
	void setPlayers(VPlayer*);
};

#endif
