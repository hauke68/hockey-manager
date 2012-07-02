#include "manager.h"

Manager::Manager() {

	this->name   = "";
	this->income = 0;
	this->team   = new Team();
}

Manager::~Manager() {

	if (team != NULL)
		delete team;
}

// Get methods
string Manager::getName() {

	return(this->name);
}

long Manager::getIncome() {

	return(this->income);
}

Team* Manager::getTeam() {

	return(this->team);
}

// Set methods
void Manager::setName(string name) {

	this->name = name;
}

void Manager::setIncome(long income) {

	this->income = income;
}

void Manager::setTeam(Team* team) {

	if(team != NULL)
		delete team;

	this->team = team;
}

