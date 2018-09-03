// job.h

#ifndef JOB
#define JOB
#include "PQueue.h"
#include <iostream>

using namespace std;

class Job {
public:
	Job();
	
	Job(int id, int hour,int priority);

	Job& operator=(const Job& obj);

	bool operator>(const Job& obj) const;
	
	bool operator<(const Job& obj) const;
	
	bool operator<=(const Job& obj) const;
	
	bool operator>=(const Job& obj) const;
	
	bool operator==(const Job& obj) const;
	
	bool operator!=(const Job& obj) const;

	void decrementHour();

	void setJobNumber(int number);

	int getJobNumber();

	int getPriority();

	int getId();

	int getHour();

private:
	int hour;
	int priority;
	int id;
	int JobNumber;
};
#endif 