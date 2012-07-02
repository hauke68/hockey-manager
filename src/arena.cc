#include "arena.h"

Arena::Arena() {}
Arena::~Arena() {}

string Arena::getName() {

	return name;
}

// Get methods
long Arena::getSeats() {

	return seats;
}

long Arena::getRent() {

	return rent;
}

// Set methods
void Arena::setName(string name) {

	this->name = name;
}

void Arena::setSeats(long seats) {

	this->seats = seats;
}

void Arena::setRent(long rent) {

	this->rent = rent;
}
