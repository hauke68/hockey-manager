#include "database.h"
#include "user.h"

#include <stdlib.h>

User::User() {}

User::User(string name) {

	this->name = name;
}

string User::getName() {

	return this->name;
}

string User::getHome() {

	return (string)getenv("HOME");
}
