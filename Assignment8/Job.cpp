// job.cpp

#include "Job.h"
#include<iostream>

using namespace std;

Job::Job() {
	this->id = 0;
	this->hour = 0;
	this->priority = 0;
	JobNumber = 0;
}

Job::Job(int id, int hour, int priority) {
	this->id = id;
	this->hour = hour;
	this->priority = priority;
}

Job& Job::operator=(const Job& obj) {
	this->id = obj.id;
	this->hour = obj.hour;
	this->priority = obj.priority;
	this->JobNumber = obj.JobNumber;
	return *this;
}

void Job::decrementHour() {
	hour--;
}

void Job::setJobNumber(int number) {
	JobNumber = number;
}

int Job::getJobNumber() {
	return JobNumber;
}

bool Job::operator>(const Job& obj) const{
	return this->priority > obj.priority;
}

bool Job::operator<(const Job& obj) const{
	return this->priority < obj.priority;
}

bool Job::operator<=(const Job& obj) const{
	return this->priority <= obj.priority;
}

bool Job::operator!=(const Job& obj) const{
	return !(this->priority == obj.priority);
}

bool Job::operator>=(const Job& obj) const{
	return this->priority >= obj.priority;
}

bool Job::operator==(const Job& obj) const{
	return this->priority == obj.priority;
}

int Job::getPriority() {
	return priority;
}

int Job::getId() {
	return id;
}

int Job::getHour() {
	return hour;
}