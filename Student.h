#ifndef STUDENT_H
#define STUDENT_H

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

  //mutator functions
  void setArrivalTime(int arrivalTime);
  void setTimeRequired(int timeRequired);
};



#endif /*STUDENT_H*/
