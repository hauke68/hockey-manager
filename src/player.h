// Class represents an ice-hockey player!
#ifndef PLAYER_H
#define PLAYER_H

#include <string>

#define GOALIE        1
#define LEFT_DEFENSE  2
#define RIGHT_DEFENSE 3
#define LEFT_OFFENSE  4
#define CENTER        5
#define RIGHT_OFFENSE 6

using namespace std;

class Player {

 private:
	long         id;
	string       name;
	int          height;
	int          weight;
	int          handed;   // 0 = right; 1 = left
	int          pos;
	int          row;
	long         income;
	unsigned int birthday; // This is a UNIX timestamp
	int          team;     // 0 = No team
	int          goals;
	int          goals_ever;
	int          assists;
	int          assists_ever;
	int          matches;
	int          matches_ever;
	int          penalty_minutes;
	int          penalty_minutes_ever;

	// Skills
	int skating;
	int shooting;
	int defense;
	int offense;
	int passing;
	int puck_handling;

	// Physical values
	int condition;
	int cleverness;
	int health;
	int mood;

 public:

	Player();
	Player(Player*);
	~Player();
	int Save();

	// Set methods
	void setId(long);
	void setName(string);
	void setHeight(int);
	void setWeight(int);
	void setHanded(int);
	void setPosition(int);
	void setRow(int);
	void setIncome(long);
	void setBirthday(unsigned int);
	void setTeam(int);
	void setGoals(int);
	void setGoalsEver(int);
	void setAssists(int);
	void setAssistsEver(int);
	void setMatches(int);
	void setMatchesEver(int);
	void setPenalties(int);
	void setPenaltiesEver(int);
	void setSkating(int);
	void setShooting(int);
	void setDefense(int);
	void setOffense(int);
	void setPassing(int);
	void setPuckHandling(int);
	void setCondition(int);
	void setCleverness(int);
	void setHealth(int);
	void setMood(int);

	// Get methods
	long getId();
	string getName();
	int getHeight();
	int getWeight();
	int getHanded();
	int getPosition();
	int getRow();
	long getIncome();
	unsigned int getBirthday();
	int getTeam();
	int getGoals();
	int getGoalsEver();
	int getAssists();
	int getAssistsEver();
	int getMatches();
	int getMatchesEver();
	int getPenalties();
	int getPenaltiesEver();
	int getSkating();
	int getShooting();
	int getDefense();
	int getOffense();
	int getPassing();
	int getPuckHandling();
	int getCondition();
	int getCleverness();
	int getHealth();
	int getMood();
};

#endif
