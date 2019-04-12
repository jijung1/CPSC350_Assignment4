/*
Name:                   Jin Jung
Student ID:             2329401
Email:                  jijung@chapman.edu
Course no. & Section:   CS350-02
Assignment:             4
*/

/*
  Class invariant: Every instance of this class will have int arrivalTime, int timeRequired, and int waitTime
*/

#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
using namespace std;

class Student {
private:
  int arrivalTime;
  int timeRequired;
  int waitTime;
public:
  Student();
  Student(int arrivalTime, int timeRequired);
  ~Student();
  int getWaitTime();
  void incrementWaitTime();
  int getArrivalTime();
  int getTimeRequired();
  void setArrivalTime(int arrivalTime);
  void setTimeRequired(int timeRequired);

};



#endif /*STUDENT_H*/
