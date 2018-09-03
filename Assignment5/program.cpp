#include<stack>
#include<queue>
#include<fstream>
#include<iostream>
#include<sstream>
#include<stdlib.h>
#include<cassert>
using namespace std;
/*opens values.txt file */
void openFile(ifstream& f);
//this is called when two int and an operation needs to be calculator
double calculate(double firstNumber, double secondNumber, string symbol);
//open values.txt file
void evolation(ifstream& f);
//check priority
int priority(string checkStatus);

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

double calculate(double firstNumber, double secondNumber, string symbol) {
	if (symbol == "+") return firstNumber + secondNumber;
	else if (symbol == "-") return firstNumber - secondNumber;
	else if (symbol == "*") return firstNumber * secondNumber;
	else if (symbol == "/") return firstNumber / secondNumber;
}

void evolation(ifstream& f) {
	bool illegal = false;
	ofstream outFile("out.txt");

	queue<string> tempForQueue;
	string line;
	string value;
	while (!f.eof())
	{
		stack<string> converterStack;
		stringstream lineStream;
		getline(f, line);
		lineStream << line;
		if (line.size()) {
			outFile << "The postfix of " << line<<endl;
		}
		do {
			lineStream >> value;
			if (value != "(" && value != ")" && value != "+" && value != "-" && value != "*" && value != "/") {

				if (value != "#") tempForQueue.push(value);
			}
			else if (value == "(") converterStack.push(value);
			else if (value == ")") {
				while (converterStack.top() != "(") {
					tempForQueue.push(converterStack.top());
					converterStack.pop();
				} if (converterStack.top() == "(") converterStack.pop();
			}
			else if (value != "#") {
				while (!converterStack.empty() && (priority(value) <= priority(converterStack.top()))) {
					tempForQueue.push(converterStack.top());
					converterStack.pop();
				}
				converterStack.push(value);
			}

			if (value == "#") {
				while (!converterStack.empty()) {
					tempForQueue.push(converterStack.top());
					converterStack.pop();
				}
				tempForQueue.push("#");
			}


		} while (value != "#");

		
		while (tempForQueue.empty() == false) {

			stack<float> temp;
			value = tempForQueue.front();
			tempForQueue.pop();
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
					if (temp.top() < 1)
					{
						cout << "illegal operator" << endl;
						illegal = true;
						continue;

					}
					double second = temp.top(); //error
					temp.pop();
					double first = temp.top();
					temp.pop();
					double result = calculate(first, second, value);
					temp.push(result);
					outFile << value << " ";
				}

				value = tempForQueue.front();
				tempForQueue.pop();
			}

			outFile << "which evaluates to ";

			outFile << temp.top() << endl;


			illegal = false;

		}
	}
} 

int priority(string checkStatus) {
	int temp=0;
	if (checkStatus == "*" || checkStatus == "/") temp = 3;
	else if (checkStatus == "+" || checkStatus == "-") temp = 2;

	return temp;
}