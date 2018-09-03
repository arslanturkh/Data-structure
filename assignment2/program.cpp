#include <cassert>	
#include <cstdlib>
#include <string>
#include <iostream>
#include <cassert>
#include <sstream>
#include <fstream>
#include <string>
#include "Player.h"
#include "SimpleList.h"

using namespace std;

int inputOperation();
int inputPosition();
string inputLastName();
void inputTwoPositions(int *firstPosition, int *secondPosition);
void readFile(SimpleList &list1);
bool checkNumber(int num);




int main() {
	int operation, position, firstPosition, secondPosition, firstPlayerPoint, secondPlayerPoint, point, currentPosition;
	string lastName, firstName, secondName;
	bool compareName = false;
	SimpleList *list= new SimpleList();
	readFile(*list);
	/*Dosyadan okudun
	Player pl= new Player("isim","soyisim")
	Player pl2=new Player("isim2","soyisim2")

	
	a.insert(pl);
	a.insert(pl2)
	a->SimpleList::retrieve(1); */



	do {
		do
		{
			operation = inputOperation();
		} while ((operation < 0) || (operation > 3));

		switch (operation) {
			case 0:
				break;

			case 1:
				position = inputPosition();

				firstName = list->retrieve(20-position).getFirstName();
				secondName = list->retrieve(20-position).getLastName();

				cout << endl << "Name of " << position << ". player is " << firstName << " " << secondName << endl;
				break;

			case 2:
				lastName = inputLastName();

				for (int i = 0; i < 20; i++) {
					if (!(lastName.compare(list->retrieve(19-i).getLastName()))) {
						compareName = true;
						currentPosition = i+1;
					}
				

				if (compareName) {
					cout << endl << "ranking of " << lastName << " is " << currentPosition << endl;
					compareName = false;
				}

				else{
					cout << endl << "player is not ranked " << endl;
				}
				break;

			case 3:
				inputTwoPositions(&firstPosition, &secondPosition);

				firstPlayerPoint = list->retrieve(20-firstPosition).getPointTotal();
				secondPlayerPoint = list->retrieve(20-secondPosition).getPointTotal();
				point = firstPlayerPoint - secondPlayerPoint;

				if (point < 0) {
					point = point * -1;
				}

				cout << endl << "there are " << point << " points between " << firstPosition << ". player and " << secondPosition << ". player" << endl;
				break;
			default:
				break;
		}
	} while (operation != 0);

	cout << position << " " << lastName << " " << firstPosition << " " << secondPosition;
}



int inputOperation() {
	int input;

	cout << endl << "1: Find the position of player" << endl;
	cout << "2: Find the player ranking with a given last name" << endl;
	cout << "3: Find difrence of point with two players with given positions\n" << endl;
	cout << "Chose an operation (0) for Exit: ";
	cin >> input;

	return input;
}

int inputPosition() {
	int input;

	do
	{
		cout << endl << endl << "Enter a position: ";
		cin >> input;
	} while (checkNumber(input));

	return input;
}

string inputLastName() {
	string input;

	cout << endl << "Enter the last name of player: ";
	cin >> input;

	return input;
}

void inputTwoPositions(int * firstPosition, int * secondPosition){
	int first_Position, second_Position;

	do{
		cout << endl << "Enter the position of first player: ";
		cin >> first_Position;
	} while (checkNumber(first_Position));

	do{
		cout << endl << "Enter the position of first player: ";
		cin >> second_Position;
	} while (checkNumber(second_Position));

	*firstPosition = first_Position;
	*secondPosition = second_Position;
}

bool checkNumber(int num) {
	if ((num < 1) || (num >20)) {
		return true;
	}

	else {
		return false;
	}
}

void readFile(SimpleList &list1) {
	string firstName, secondName, country, line;
	int point, rank=1;

	ifstream inFile("players.txt");

	while (!(inFile.eof())) {
		getline(inFile, firstName, ' ');
		getline(inFile, secondName, ' ');
		getline(inFile, line, ' ');
		point = atoi(line.c_str());
		getline(inFile, country, '\n');
		TennisPlayer *tennisPlayer = new TennisPlayer(firstName, secondName, rank, point, country);
		list1.insert(*tennisPlayer, rank - 1);
	}
}