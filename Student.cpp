/*
Name:                   Jin Jung
Student ID:             2329401
Email:                  jijung@chapman.edu
Course no. & Section:   CS350-02
Assignment:             4
*/

/*
  Implementation file Student class
*/

#include "Student.h"

Student::Student() {  //default constructor
  this->arrivalTime = 0;
  this->timeRequired = 0;
  this->waitTime = 0;
}

Student::Student(int arrivalTime, int timeRequired) { //main constructor
  this->arrivalTime = arrivalTime;
  this->timeRequired = timeRequired;
  this->waitTime = 0;
}
Student::~Student() {}  //destructor

int Student::getWaitTime() {  //will return length of time student waited in waitLine
  return this->waitTime;
}

void Student::incrementWaitTime() { //will increment memvar waitTime
  this-> waitTime += 1;
}

int Student::getTimeRequired() { //will return time student requires to be helped at window
  return this->timeRequired;
}

int Student::getArrivalTime() { //will return the time student enters the waitLine
  return this->arrivalTime;
}


void Student::setArrivalTime(int arrivalTime) { //mutator function for arrivalTime
  this->arrivalTime = arrivalTime;
}
void Student::setTimeRequired(int timeRequired) { //mutator function for timeRequired
  this->timeRequired = timeRequired;
}
