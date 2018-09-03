#ifndef QUEUE
#define QUEUE

/*-- queue.h ------------------------------------------------------------
This header file defines a Stack data type. Basic operations:
constructor: Constructs an empty queue
empty: Checks if a queue is empty
enqueue: Modifies a queue by adding a value at the back
front: Retrieves the front queue value; leaves queue unchanged
dequeue: Modifies queue by removing the value at the front

-----------------------------------------------------------------------*/


#include<iostream>
using namespace std;

typedef string ItemType1;

class Queue {

public:
	Queue();

	Queue(int mySize);

	~Queue();

	int size() const;

	bool empty() const;

	void enqueue(const ItemType1 & item);

	void dequeue();

	ItemType1 front() const;



private:
	ItemType1* myArray;
	int myFront;
	int myRear;
	int capacity;
	int SIZE;
};

#endif
