/*Halil Onur Arslanturk
CS240
Assignment 7*/
// Map.h


#ifndef MAPP
#define MAPP

#include<iostream>
#include "BankAccount.h"
#include<list>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

typedef int KeyType;
typedef BankAccount* ValueType;
typedef pair<KeyType, ValueType> ItemType;
typedef int(*hashFunc)(KeyType key, int tsize);

class Map {


public:
	Map();
	// constructor
	
	Map(int size, hashFunc func);
	
	bool empty();
	//RETURN TRUE IF THE MAP IS EMPTY; ELSE RETURN FALSE
	
	int size();
	//RETURN THE NUMBER OF ITEMS IN THE MAP
	
	bool find(KeyType key);
	//IF THERE IS AN ITEM WITH THIS KEY RETURN TRUE; ELSE RETURN FALSE
	
	bool add(KeyType key, ValueType value); 
	//IF THERE IS NO ITEM WITH THIS KEY, ADD ITEM TO THE MAP AND RETURN TRUE; ELSE RETURN FALSE
	
	ValueType retrieve(KeyType key);
	//IF THERE IS AN ITEM WITH THIS KEY, RETURN THE VALUE; ELSE RETURN NULL
	
	ValueType remove(KeyType key);
	// IF THERE IS AN ITEM WITH THIS KEY, REMOVE THE ITEM FROM THE MAP AND RETURN THE VALUE; ELSE RETURN NULL
	
	void displayItems(); 
	// prints the accounts
	
	void displayStats();
	//displays on the screen the load factor, average synonym list length and longest synonym list length
private:
	int tsize;
	vector<list<ItemType>> hashTable;
	hashFunc func;
	int numberOfItems;
};

#endif