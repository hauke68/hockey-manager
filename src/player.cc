#include "database.h"
#include "player.h"

Player::Player() {

	this->setId(0);
	this->setName("Generic Player");
	this->setHeight(0);
	this->setWeight(0);
	this->setHanded(0);
	this->setPosition(0);
	this->setRow(0);
	this->setIncome(0);
	this->setBirthday(0);
	this->setTeam(0);
	this->setGoals(0);
	this->setGoalsEver(0);
	this->setAssists(0);
	this->setAssistsEver(0);
	this->setMatches(0);
	this->setMatchesEver(0);
	this->setPenalties(0);
	this->setPenaltiesEver(0);
	this->setSkating(0);
	this->setShooting(0);
	this->setDefense(0);
	this->setOffense(0);
	this->setPassing(0);
	this->setPuckHandling(0);
	this->setCondition(0);
	this->setCleverness(0);
	this->setHealth(0);
	this->setMood(0);
}

Player::Player(Player *p) {

	this->setId(p->getId());
	this->setName(p->getName());
	this->setHeight(p->getHeight());
	this->setWeight(p->getWeight());
	this->setHanded(p->getHanded());
	this->setPosition(p->getPosition());
	this->setRow(p->getRow());
	this->setIncome(p->getIncome());
	this->setBirthday(p->getBirthday());
	this->setTeam(p->getTeam());
	this->setGoals(p->getGoals());
	this->setGoalsEver(p->getGoalsEver());
	this->setAssists(p->getAssists());
	this->setAssistsEver(p->getAssistsEver());
	this->setMatches(p->getMatches());
	this->setMatchesEver(p->getMatchesEver());
	this->setPenalties(p->getPenalties());
	this->setPenaltiesEver(p->getPenaltiesEver());
	this->setSkating(p->getSkating());
	this->setShooting(p->getShooting());
	this->setDefense(p->getDefense());
	this->setOffense(p->getOffense());
	this->setPassing(p->getPassing());
	this->setPuckHandling(p->getPuckHandling());
	this->setCondition(p->getCondition());
	this->setCleverness(p->getCleverness());
	this->setHealth(p->getHealth());
	this->setMood(p->getMood());
}

Player::~Player() {

}

int Player::Save() {

	DBRow    row;
	Database *db;

	row["id"]             = getId();
	row["name"]           = getName();
	row["height"]         = getHeight();
	row["weight"]         = getWeight();
	row["handed"]         = getHanded();
	row["pos"]            = getPosition();
	row["row"]            = getRow();
	row["income"]         = getIncome();
	row["birthday"]       = getBirthday();
	row["team"]           = getTeam();
	row["goals"]          = getGoals();
	row["goals_ever"]     = getGoalsEver();
	row["assists"]        = getAssists();
	row["assists_ever"]   = getAssistsEver();
	row["matches"]        = getMatches();
	row["matches_ever"]   = getMatchesEver();
	row["penalties"]      = getPenalties();
	row["penalties_ever"] = getPenaltiesEver();
	row["skating"]        = getSkating();
	row["shooting"]       = getShooting();
	row["defense"]        = getDefense();
	row["offense"]        = getOffense();
	row["passing"]        = getPassing();
	row["puckhandling"]   = getPuckHandling();
	row["condition"]      = getCondition();
	row["cleverness"]     = getCleverness();
	row["health"]         = getHealth();
	row["mood"]           = getMood();

	db = new Database();
	db->Update("player", row);
	delete db;

	return 0;
}

// Set methods
void Player::setId(long id) {

	this->id = id;
}

void Player::setName(string name) {

	this->name = name;
}

void Player::setHeight(int height) {

	this->height = height;
}

void Player::setWeight(int weight) {

	this->weight = weight;
}

void Player::setHanded(int handed) {

	this->handed = handed;
}

void Player::setPosition(int pos) {

	this->pos = pos;
}

void Player::setRow(int row) {

	this->row = row;
}

void Player::setIncome(long income) {

	this->income = income;
}

void Player::setBirthday(unsigned int birthday) {

	this->birthday = birthday;
}

void Player::setTeam(int team) {

	this->team = team;
}

void Player::setGoals(int goals) {

	this->goals = goals;
}

void Player::setGoalsEver(int goals) {

	this->goals_ever = goals;
}

void Player::setAssists(int assists) {

	this->assists = assists;
}

void Player::setAssistsEver(int assists) {

	this->assists_ever = assists;
}

void Player::setMatches(int matches) {

	this->matches = matches;
}

void Player::setMatchesEver(int matches) {

	this->matches_ever = matches;
}

void Player::setPenalties(int m) {

	this->penalty_minutes = m;
}

void Player::setPenaltiesEver(int m) {

	this->penalty_minutes_ever = m;
}

void Player::setSkating(int skating) {

	this->skating = skating;
}

void Player::setShooting(int shooting) {

	this->shooting = shooting;
}

void Player::setDefense(int defense) {

	this->defense = defense;
}

void Player::setOffense(int offense) {

	this->offense = offense;
}

void Player::setPassing(int passing) {

	this->passing = passing;
}

void Player::setPuckHandling(int puck_handling) {

	this->puck_handling = puck_handling;
}

void Player::setCondition(int cond) {

	this->condition = cond;
}

void Player::setCleverness(int cleverness) {

	this->cleverness = cleverness;
}

void Player::setHealth(int health) {

	this->health = health;
}

void Player::setMood(int mood) {

	this->mood = mood;
}

// Get methods
long Player::getId() {

	return id;
}

string Player::getName() {

	return name;
}

int Player::getHeight() {

	return height;
}

int Player::getWeight() {

	return weight;
}

int Player::getHanded() {

	return handed;
}

int Player::getPosition() {

	return pos;
}

int Player::getRow() {

	return row;
}

long Player::getIncome() {

	return income;
}

unsigned int Player::getBirthday() {

	return birthday;
}

int Player::getTeam() {

	return team;
}

int Player::getGoals() {

	return goals;
}

int Player::getGoalsEver() {

	return goals_ever;
}

int Player::getAssists() {

	return assists;
}

int Player::getAssistsEver() {

	return assists_ever;
}

int Player::getMatches() {

	return matches;
}

int Player::getMatchesEver() {

	return matches_ever;
}

int Player::getPenalties() {

	return penalty_minutes;
}

int Player::getPenaltiesEver() {

	return penalty_minutes_ever;
}

int Player::getSkating() {

	return skating;
}

int Player::getShooting() {

	return shooting;
}

int Player::getDefense() {

	return defense;
}

int Player::getOffense() {

	return offense;
}

int Player::getPassing() {

	return passing;
}

int Player::getPuckHandling() {

	return puck_handling;
}

int Player::getCondition() {

	return condition;
}

int Player::getCleverness() {

	return cleverness;
}

int Player::getHealth() {

	return health;
}

int Player::getMood() {

	return mood;
}
