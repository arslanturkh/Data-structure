#include "stack.h"
#include <cassert>
#include <iostream>

using namespace std;
//Default constructor with constant capacity of 30
Stack::Stack() {
	int myArbitraryArray = 30;
	myArray = new ItemType[myArbitraryArray];
	capacity = myArbitraryArray;
	SIZE = 0;
	myTop = -1;
}
//Default constractor with a parameter
Stack::Stack(int mySize) {
	myArray = new ItemType[mySize];
	capacity = mySize;
	SIZE = 0;
	myTop = -1;
}
//Erases the object of Stack 
//returns the heap memory
Stack::~Stack() {
	delete[] myArray;
}

int Stack::size() const {
	return SIZE;
}

bool Stack::empty() const {
	return myTop == -1;
}

void Stack::push(int item) {
	assert(myTop <= capacity);
	myTop++;
	myArray[myTop] = item;
	SIZE++;
}

void Stack::pop() {
	assert(myTop > -1);
	myTop--;
	SIZE--;
}

int Stack::top() const {
	assert(myTop > -1);
	return myArray[myTop];
}

int Stack::getMyTop() {
	return myTop;
}

void Stack::display(ostream& out) {
	int i;

	for (i = myTop; i > -1; i--) cout << myArray[i] <<" ";
	cout << endl ;
}