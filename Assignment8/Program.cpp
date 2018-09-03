// ýt does not work!!!
#include "pqueue.h"
#include "job.h"
#include <iostream>
#include <string> 
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <vector>
#include <cassert>
#include <fstream>
#include <sstream>

using namespace std;

void openFile(ifstream& f);
void printFile(ifstream& f);

int main() {
	ifstream f;
	openFile(f);
}

void openFile(ifstream& f)
{
	string filename;
	cout << "Enter file name :";
	cin >> filename;
	f.open(filename.data());
	assert(f.is_open());
}
void printFile(ifstream& f)
{
	while (!f.eof())
	{
		stringstream lineStream;
		string line;
		int first, second, third;
		getline(f, line);
		lineStream << line;
		lineStream >> first >> second >> third;
		Job temp = Job(first, second, third);
		
	}
}