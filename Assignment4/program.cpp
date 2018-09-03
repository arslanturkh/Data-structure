#include "queue.h"
#include "stack.h"
#include<fstream>
#include<iostream>
#include<sstream>
#include<stdlib.h>
#include<cassert>
using namespace std;
/*opens values.txt file */
void openFile(ifstream& f);
//this is called when two int and an operation needs to be calculator
int calculate(int firstNumber, int secondNumber, string symbol);
//open values.txt file
void evolation(ifstream& f);

int main() {
	ifstream f;
	openFile(f);
	evolation(f);
}

void openFile(ifstream& f) {
	string fileName;

	cout << endl << "Enter the file name: ";
	cin >> fileName;

	f.open(fileName);
	assert(f.is_open());
}

int calculate(int firstNumber, int secondNumber, string symbol) {
	if (symbol == "+") return firstNumber + secondNumber;
	else if (symbol == "-") return firstNumber - secondNumber;
	else if (symbol == "*") return firstNumber * secondNumber;
}

void evolation(ifstream& f) {
	bool illegal = false;
	ofstream outFile("out.txt");
	
	Queue tempForQueue;
	string line;
	string value;
	while (!f.eof())
	{
		stringstream lineStream;
		getline(f, line);
		lineStream << line;
		do {
			lineStream >> value;
			tempForQueue.enqueue(value);
		} while (value != "#");
	}
	while (tempForQueue.empty() == false) {
		
		Stack temp;
		value = tempForQueue.front();
		tempForQueue.dequeue();
		if (value == "#")
		{
			continue;
		}
		while (value != "#"&&!illegal)
		{
			if (value == "0")
			{
				temp.push(0);
				outFile << value << " ";
			}
			else if (atoi(value.c_str()) != 0)
			{
				temp.push(atoi(value.c_str()));
				outFile << value << " ";
			}
			else
			{
				if (temp.getMyTop() < 1)
				{
					cout << "illegal operator" << endl;
					illegal = true;
					continue;

				}
				int second = temp.top(); //error
				temp.pop();
				int first = temp.top();
				temp.pop();
				int result = calculate(first, second, value);
				temp.push(result);
				outFile << value << " ";
			}
			
			value = tempForQueue.front();
			tempForQueue.dequeue();
		}
		if (!illegal&&temp.getMyTop() == 0)
		{
			outFile << "is ";
			
			outFile << temp.top() << endl;
			
		}
		if (temp.getMyTop() > 0)
		{
			cout << "more than one int left in stack" << endl;
		}
		illegal = false;
		
	}
}