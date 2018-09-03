#include "Map.h"
#include<iostream>
#include<algorithm>
#include <limits>
#include "BankAccount.h"
#include<fstream>
#include<sstream>
#include<stdlib.h>
#include<cassert>

void askForUser();
int hash_func(KeyType key, int size);
void openFile(ifstream& f, Map& mapFile);
void evolation(Map& bankAccountMap);

int main() {
	
	Map map1(20, hash_func);
	ifstream f;

	openFile(f, map1);
	map1.displayItems();
	map1.displayStats();
	askForUser();
	evolation(map1);
	f.close();
}

void askForUser() {

	cout << "   1. deposit to the BankAccount with the id given (deposits must be > 0)\n";
	cout << "   2. withdraw from the BankAccount with the id given (withdrawals must be > 0)\n";
	cout << "   3. display the name and balance of the BankAccount with the id given\n";
	cout << "   4. close the BankAccount with the id given\n";
	cout << "What do you wanna do? 1,2,3 or 4. (0 to exit)\n";
	
}

int hash_func(KeyType key, int size) {
	return key%size;
}

void openFile(ifstream& f, Map& mapFile) {
	string data[37][3];
	string name, surname, id, wholename, line = "---", fileName;
	int i = 0;

	cout << endl << "Enter the file name: ";
	cin >> fileName;
	f.open(fileName);
	assert(f.is_open());

	while (!f.eof()) {
		getline(f, id, ' ');
		data[i][2] = id;
		getline(f, surname, ',');
		data[i][1] = surname;
		getline(f, name, '\n');
		data[i][0] = name;
		i++;
	}
	for (int i = 0; i<36; i++) {
		mapFile.add(atoi(data[i][2].c_str()), new BankAccount(data[i][1] + data[i][0], 0, atoi(data[i][2].c_str())));

	}
}

void evolation(Map& bankAccountMap) {
	string answer;
	string choice;

	do{
		cout << "Enter your choice: ";
		cin >> choice;

		if (choice == "1") {
			
			cout << "enter id number of bank account: ";
			cin >> answer;
			int i = atoi(answer.c_str());

			cout << "enter the amount you want to deposit (deposits must be > 0): ";
			cin >> answer;
			double d = atof(answer.c_str());
			assert(d > 0);

			bankAccountMap.retrieve(i)->deposit(d);
			cout << "Deposited " << d << " to " << bankAccountMap.retrieve(i)->getName() << endl;
		}
		else if (choice == "2") {
			cout << "enter id number of bank account: ";
			cin >> answer;
			int i = atoi(answer.c_str());

			cout << "enter the amount you want to withdraw (withdrawals must be > 0): ";
			cin >> answer;
			double d = atof(answer.c_str());
			assert(d > 0);

			bankAccountMap.retrieve(i)->withdraw(d);
			cout << "Withdrawed " << d << " from " << bankAccountMap.retrieve(i)->getName() << endl;
		}
		else if (choice == "3") {
			cout << "enter id number of bank account: ";
			cin >> answer;
			int i = atoi(answer.c_str());
			cout << "Name: " << bankAccountMap.retrieve(i)->getName() << " Balance: " << bankAccountMap.retrieve(i)->getBalance() << endl;
		}
		else if (choice == "4") {
			cout << "enter id number of bank account: ";
			cin >> answer;
			int i = atoi(answer.c_str());

			bankAccountMap.remove(i);

		}//remove doesnt work
		if (choice!="0") askForUser();
	} while (choice != "0");
}