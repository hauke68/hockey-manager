#include "team.h"

Team::Team() {

	this->setId(0);
	this->setName("Generic Team");
	this->setMoney(0);
	this->players = new VPlayer();
}

Team::~Team() {

	if(players != NULL)
		delete players;
}

void Team::addPlayer(Player *p) {

	this->players->push_back(p);
}

long Team::getId() {

	return this->id;
}

string Team::getName() {

	return name;
}

long Team::getMoney() {

	return money;
}

VPlayer* Team::getPlayers() {

	return players;
}

Player* Team::getPlayer(string name) {

	VPlayer::iterator it = this->players->begin();
	while(it != this->players->end()) {
		if ((*it)->getName() == name)
			return(new Player(*it));
		it++;
	}

	return(NULL);
}

void Team::setId(long id) {

	this->id = id;
}

void Team::setName(string name) {

	this->name = name;
}

void Team::setMoney(long money) {

	this->money = money;
}

void Team::setPlayers(VPlayer *players) {

	this->players = players;
}

