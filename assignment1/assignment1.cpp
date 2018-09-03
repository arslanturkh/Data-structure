#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string getName();
int getAge();
void display(string *name, string *secondName, int age);

int main() {
	int age;
	const int min = 0, max = 125;
	string firstName, lastName, input;

	input = getName();
	age = getAge();
	while (age < min || age > max) {
		age = getAge();
	}
	
	istringstream ss(input);
	ss >> firstName;
	ss >> lastName;

	display(&firstName, &lastName, age);
	return 0;
}

string getName() {
	string nameOfUser;

	cout << "Enter first name and last name: ";
	getline(cin, nameOfUser);

	return nameOfUser;
}


int getAge() {
	int input;

	cout << "Enter an age: ";
	cin >> input;

	return input;
}

void display(string *name, string *secondName, int age) {
	cout << *secondName << " " << *name << " " << age << endl;
}