
#ifndef TENNISPLAYER
#define TENNISPLAYER

#include <iostream>
using namespace std;

class TennisPlayer {
public:
	TennisPlayer();

	TennisPlayer(string initFirstName, string initLastName, int initRanking, int initPointTotal, string initCountry);

	string getFirstName() const;

	string getLastName() const;

	int getRanking() const;

	int getPointTotal() const;

	string getCountry() const;

	void setRanking(int newRanking);

	void setPointTotal(int newPointTotal);

	friend ostream& operator<< (ostream & out, const TennisPlayer & f);


private:
	string firstName;
	string lastName;
	int ranking;
	int pointTotal;
	string country;
};
#endif
