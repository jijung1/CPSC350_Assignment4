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


//  mutator functions
  void setArrivalTime(int arrivalTime);
  void setTimeRequired(int timeRequired);

};



#endif /*STUDENT_H*/
