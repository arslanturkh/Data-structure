/*pqueue.h*/

#ifndef P_QUEUE
#define P_QUEUE
#include "Job.h"
#include<iostream>

using namespace std;
typedef class Job ItemType;

class P_Queue {
public:
	P_Queue(); //construct an emty priority queue with a capacity of 10

	P_Queue(int capacity); //construct with an emty priority queue with the specified capacity

	P_Queue(const P_Queue &obj); //copy constructor

	~P_Queue(); //destructor

	P_Queue& operator=(const P_Queue &obj); //assignment

	bool empty(); //is the pqueue emty?

	int length(); //how many items are in the priority

	void addItem(const ItemType &item); //add an item to the priority queue

	ItemType &getHighest(); //return the item with the highest priority

	void removeHighest(); //remove the item with the highest priority value

	void display(); //display contents of the heap

	void swap(ItemType &first, ItemType & second);

	int getSize();

	friend ostream& operator<<(ostream& os, const P_Queue &q);

private:
	ItemType *heap; //for a dynamically allocated array
	
	int size; //number of items in the priority queue
	
	int capacity; // maximum number of items allowed
};
#endif 