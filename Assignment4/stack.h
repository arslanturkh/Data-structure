#ifndef STACK
#define STACK

/*-- Stack.h ------------------------------------------------------------
This header file defines a Stack data type. Basic operations: 
constructor: Constructs an empty stack 
empty: Checks if a stack is empty 
push: Modifies a stack by adding a value at the top 
top: Retrieves the top stack value; leaves stack unchanged 
pop: Modifies stack by removing the value at the top 
display: Displays all the stack elements Class (I did not use it!)
-----------------------------------------------------------------------*/

#include<iostream>
using namespace std;

typedef int ItemType;

class Stack {

public:
	Stack();

	Stack(int mySize);

	~Stack();

	int size() const;

	bool empty() const;

	void push(int  item);

	void pop();

	int top() const;

	int getMyTop();

	void display(ostream& out);

private:
	ItemType* myArray;
	int myTop;
	int capacity;
	int SIZE;
};

#endif
