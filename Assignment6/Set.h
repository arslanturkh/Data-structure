/*Halil Onur Arslanturk
CS240
Assignment 6*/
// Set.h

#ifndef SET
#define SET

#include<iostream>
#include<string>

using namespace std;



typedef string ItemType;     // type of item to be stored

class Set {
	// defines a set class that can hold 0 to CAPACITY items
	// Items are of type ItemType and are unique (no duplicates)
	// Items must be comparable using relational operators
private:
	class BinNode {
	public:
		ItemType item;
		BinNode* left;
		BinNode* right;
		BinNode() {
			left = 0;
			right = 0;
		}

		BinNode(const ItemType & newItem) {
			left = 0;
			right = 0;
			item = newItem;
		}
	};
	// binary search tree contains nodes of BinNode type
	// data members are public 
	// intended for use by the set class only

	int heightRec(BinNode* p) const;
	// return the heigh of the bst

	bool binSearch(const BinNode* p, const ItemType& num) const;
	bool addRec(BinNode*& p, const ItemType& item);
	void displayRec(ostream& out, BinNode* p) const;

	BinNode* root;
	// for accessing to the BST

	int numberOfItems;
	// number of items of BST

public:
	Set();
	// creates a Set object with 0 items in it

	bool empty() const;
	// returns true if Set object holds 0 items

	int getSize()const;
	// returns number of items in Set

	bool add(const ItemType & item);
	// adds item to the set and returns true; if item is 
	// already in the set or CAPACITY has been reached,
	// item is not added and false is returned

	bool find(const ItemType & item);
	// returns true if item is in the set
	// returns false if item is not in the set

	int height()const;

	bool remove(const ItemType & item);
	// removes item from the set and returns true if item is
	// in the set; otherwise returns false

	void display(ostream & out) const;
	// sends items in the Set to the ostream provided
	// precondition: operator<< is defined for ItemType

	bool removeRec(BinNode*&parent, BinNode*& current, const ItemType& item);

	~Set();
	// destructor

	void removeAllRec(BinNode* p);

	Set(const Set& original);
	//copy constructor

	void consRec(BinNode*& thisP, BinNode* original);


};
#endif   
