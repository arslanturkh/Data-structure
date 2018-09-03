/*Halil Onur Arslanturk
CS240
Assignment 7*/
// BankAccount.cpp

#include "BankAccount.h"

BankAccount::BankAccount() {
	name = "anonymous";
	balance = 0;
	id = 0;
}

BankAccount::BankAccount(string nameIn, double balanceIn, int idIn) {
	name = nameIn;
	balance = balanceIn;
	id = idIn;
}

void BankAccount::deposit(double amount) {
	balance += amount;
}

void BankAccount::withdraw(double amount) {
	balance -= amount;
}

string BankAccount::getName() const {
	return name;
}

double BankAccount::getBalance() const {
	return balance;
}


ostream& operator<<(ostream & out, const BankAccount & b) {
	return out << b.name << "   " << b.balance << endl;
}

//----> DEFINE operator< HERE
bool BankAccount::operator<(const BankAccount &first)const {
	return balance<first.getBalance();
}