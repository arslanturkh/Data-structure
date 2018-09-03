/*Halil Onur Arslanturk
CS240
Assignment 6
program.cpp*/

#include<string>
#include<fstream>
#include<sstream>
#include <istream>
#include <iostream>
#include <cassert>
#include "Set.h"

using namespace std;

void openFile(ifstream& f, string fileName);
//openfile
void readFile(ifstream& firstFile, ifstream& secondFile, Set& badIp, Set& goodIp, Set& spammersIp);
//read files and creates BST.
void removeOldSpammers(Set& spammersIp, ifstream& thirdFile);
// remove old spammers
void closeFile(ifstream& firstFile, ifstream& secondFile, ifstream& thirdFile);
// close files
void removeAllBST(Set& badIp, Set& goodIp, Set& spammersIp, Set& removeIp, Set& badIp2, Set& goodIp2, Set& spammersIp2, Set& removeIp2);
// calls destructors

int main() {
	ifstream firstFile;
	ifstream secondFile;
	ifstream thirdFile;

	Set badIp; 
	Set goodIp; 
	Set spammersIp; 
	Set removeIp;
	
	Set badIp2;
	Set goodIp2;
	Set spammersIp2;
	Set removeIp2;

	stringstream lineStream;

	//first test
	openFile(firstFile, "spammers1.txt");
	openFile(secondFile, "check1.txt");
	openFile(thirdFile, "remove1.txt");

	readFile(firstFile, secondFile, badIp, goodIp, spammersIp);

	cout << "First test..." << endl;
	cout << "Spammers ip size  : " << spammersIp.getSize() << endl;
	cout << "Spammers ip height: " << spammersIp.height() << endl;
	cout << "spammers ip: ";
	spammersIp.display(std::cout);
	cout << "Number of good ip : " << goodIp.getSize() << endl;
	cout << "Number of bad ip  : " << badIp.getSize() << endl;

	removeOldSpammers(spammersIp, thirdFile);
	cout << "End of first test" << endl;
	closeFile(firstFile, secondFile, thirdFile);

	//second test
	openFile(firstFile, "spammers2.txt");
	openFile(secondFile, "check2.txt");
	openFile(thirdFile, "remove2.txt");

	readFile(firstFile, secondFile, badIp2, goodIp2, spammersIp2);

	cout << "Second test..." << endl;
	cout << "Spammers ip size  : " << spammersIp2.getSize() << endl;
	cout << "Spammers ip height: " << spammersIp2.height() << endl;
	cout << "spammers ip: ";
	spammersIp2.display(std::cout);
	cout << "Number of good ip : " << goodIp2.getSize() << endl;
	cout << "Number of bad ip  : " << badIp2.getSize() << endl;

	//removeOldSpammers(spammersIp2, thirdFile);
	cout << "End of second test" << endl;
	closeFile(firstFile, secondFile, thirdFile);

	removeAllBST(badIp, goodIp, spammersIp, removeIp, badIp2, goodIp2, spammersIp2, removeIp2);
}

void openFile(ifstream& f, string fileName) {
	
	f.open(fileName.data());
	assert(f.is_open());
}

void readFile(ifstream& firstFile, ifstream& secondFile, Set& badIp, Set& goodIp, Set& spammersIp) {
	string line;

	while (getline(firstFile, line)) {
		spammersIp.add(line);
	} // insert spammersId BST

	while (getline(secondFile, line)) {
		if (spammersIp.find(line)) badIp.add(line);
		else goodIp.add(line);
	}// insert bad and good ip
}

void removeOldSpammers(Set& spammersIp, ifstream& thirdFile) {
	string line;

	while (getline(thirdFile, line)) {
		if (spammersIp.find(line)) spammersIp.remove(line);
	}

	cout << "After removing" << endl;
	cout << "Spammers ip size  : " << spammersIp.getSize() << endl;
	cout << "Spammers ip height: " << spammersIp.height() << endl;
	cout << "spammers ip: ";
	spammersIp.display(std::cout);
}

void closeFile(ifstream& firstFile, ifstream& secondFile, ifstream& thirdFile) {
	firstFile.close();
	secondFile.close();
	thirdFile.close();
}

void removeAllBST(Set& badIp, Set& goodIp, Set& spammersIp, Set& removeIp, Set& badIp2, Set& goodIp2, Set& spammersIp2, Set& removeIp2) {
	badIp.~Set();
	goodIp.~Set();
	spammersIp.~Set();
	removeIp.~Set();
	badIp2.~Set();
	goodIp2.~Set();
	spammersIp2.~Set();
	removeIp2.~Set();
}