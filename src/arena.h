#ifndef _ARENA_H_
#define _ARENA_H_

#include <string>

using namespace std;

class Arena {

 private:
	string name;
	long   seats;
	long   rent; // How much to pay to rent the arena one month

 public:
	Arena();
	~Arena();

	// Get methods
	string getName();
	long getSeats();
	long getRent();

	// Set methods
	void setName(string);
	void setSeats(long);
	void setRent(long);
};

#endif
