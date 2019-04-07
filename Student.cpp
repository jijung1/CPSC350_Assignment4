#include "Student.h"

Student::Student() {
  this->arrivalTime = 0;
  this->timeRequired = 0;
  this->waitTime = 0;
}

Student::Student(int arrivalTime, int timeRequired) {
  this->arrivalTime = arrivalTime;
  this->timeRequired = timeRequired;
  this->waitTime = 0;
}
Student::~Student() {}

int Student::getWaitTime() {
  return this->waitTime;
}

void Student::incrementWaitTime() {
  this-> waitTime += 1;
}

int Student::getTimeRequired() {
  return this->timeRequired;
}

int Student::getArrivalTime() {
  return this->arrivalTime;
}


void Student::setArrivalTime(int arrivalTime) {
  this->arrivalTime = arrivalTime;
}
void Student::setTimeRequired(int timeRequired) {
  this->timeRequired = timeRequired;
}
