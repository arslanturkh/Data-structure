#include "queue.h"
#include <cassert>
#include <iostream>

using namespace std;

Queue::Queue() {
	int myArbitraryArray = 30;
	myArray = new ItemType1[myArbitraryArray];
	capacity = myArbitraryArray;
	SIZE = 0;
	myFront = -1;
	myRear = -1;
}

Queue::Queue(int mySize) {
	myArray = new ItemType1[mySize];
	capacity = mySize;
	SIZE = 0;
	myFront = -1;
	myRear = -1;
}

Queue::~Queue() {
	delete[] myArray;
}

int Queue::size() const {
	return SIZE;
}

bool Queue::empty() const {
	return (myFront == -1 && myRear == -1);
}

void Queue::enqueue(const ItemType1 & item) {
	assert((myRear + 1) % capacity != myFront);
	
	
	
	if (empty()) {
		myFront = 0;
		myRear = 0;
	}
	else myRear++;
	myArray[myRear] = item;
	SIZE++;
}

void Queue::dequeue() {
	assert(myRear > -1);

	

	if (myFront == myRear) {
		myFront = -1;
		myRear = -1;
	}
	else myFront++;
	SIZE--;
}

ItemType1 Queue::front() const {
	//assert(myFront > -1);
	return myArray[myFront];
}

