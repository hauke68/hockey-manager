#include "league.h"

League::League() {}
League::~League() {}

// Get methods
string League::getName() {

	return name;
}

int League::getMaxTeams() {

	return max_teams;
}

// Set methods
void League::setName(string name) {

	this->name = name;
}

void League::setMaxTeams(int teams) {

	this->max_teams = teams;
}
