// Map.cpp

#include "Map.h"


#include<algorithm>

#include <limits>
#include "BankAccount.h"

using namespace std;
Map::Map() {
	tsize = 0;
	numberOfItems = 0;
}
Map::Map(int size, hashFunc func) {

	numberOfItems = 0;
	this->func = func;
	tsize = size;
	hashTable.resize(size);
}
bool Map::empty() {
	return tsize == 0;
}
int Map::size() {
	return tsize;
}
bool Map::find(KeyType key) {

	typedef list<ItemType> int_list;
	typedef vector<int_list> int_list_vector;

	for (int_list_vector::iterator vectorIterator = hashTable.begin(); vectorIterator != hashTable.end(); ++vectorIterator)
	{
		for (int_list::iterator listIterator = vectorIterator->begin(); listIterator != vectorIterator->end(); ++listIterator)
		{
			if ((*listIterator).first == key) return true;
		}
	}
	return false;
}
bool Map::add(KeyType key, ValueType value) {
	int adress;

	if (find(key) == false) {
		adress = func(key, tsize);
		hashTable[adress].push_back(make_pair(key, value));
		numberOfItems++;
		return true;
	}
	else 
		return false;
}
ValueType Map::retrieve(KeyType key) {
	ValueType value;

	typedef list<ItemType> int_list;
	typedef vector<int_list> int_list_vector;

	for (int_list_vector::iterator vectorIterator = hashTable.begin(); vectorIterator != hashTable.end(); ++vectorIterator)
	{
		for (int_list::iterator listIterator = vectorIterator->begin(); listIterator != vectorIterator->end(); ++listIterator)
		{
			if ((*listIterator).first == key) {
				value = (*listIterator).second;
				return value;
			}
		}
	}
	return NULL;
}
void Map::displayItems() {
	typedef list<ItemType> int_list;
	typedef vector<int_list> int_list_vector;

	for (int_list_vector::iterator vectorIterator = hashTable.begin(); vectorIterator != hashTable.end(); ++vectorIterator)
	{
		for (int_list::iterator listIterator = vectorIterator->begin(); listIterator != vectorIterator->end(); ++listIterator)
		{// "->" because these are pointers to bank accounts
			cout << listIterator->first << ", ";
			cout << listIterator->second->getName() << endl;

		}
	}
}

ValueType Map::remove(KeyType key){
	ValueType value;
	int position = func(key, tsize);
	list<ItemType> hashtablelist = hashTable[func(key, tsize)];
	for (list<ItemType>::iterator listIterator = hashtablelist.begin(); listIterator != hashtablelist.end(); ++listIterator)
	{
		if (listIterator->first == key) {
			value = listIterator->second;
			hashTable[func(key, tsize)].erase(listIterator);
			numberOfItems--;
			return value;
		}
	}

	return NULL;
}


void Map::displayStats() {

	//Find biggest list
	auto biggest_list = hashTable.begin();
	for (auto iter = hashTable.begin(); iter != hashTable.end(); ++iter) {
		if (biggest_list->size() < iter->size()) {
			biggest_list = iter;
		}
	}

	//Find average synonm list length
	int vector_size = this->hashTable.size();
	int total = 0;
	float ave_syn_len = 0;
	for (auto iter = hashTable.begin(); iter != hashTable.end(); ++iter) {
		total += iter->size();
	}
	ave_syn_len = total / vector_size;

	cout << "Average synonym list is : " << ave_syn_len << endl;
	cout << "Longest synonym list is : " << biggest_list->size() << endl;
	cout << "Load factor is: " << double(numberOfItems) / tsize << endl;
}