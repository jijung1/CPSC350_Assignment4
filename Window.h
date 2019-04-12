/*
Name:                   Jin Jung
Student ID:             2329401
Email:                  jijung@chapman.edu
Course no. & Section:   CS350-02
Assignment:             4
*/

/*
  Class invariant: Every instance of this class will have bool available, double* idleTime, int idleTimeSize, and int occupied
*/

#ifndef WINDOW_H
#define WINDOW_H

class Window {
public:
  bool available; //set this to true after finished servicing student
  double* idleTime; //list time idle times to be stored here
  int idleTimeSize; //keeps track of number of times window has been idle
  int occupied; //reset to time required for each new student
  Window();
  ~Window();  //delete[] idleTime;
  bool isAvailable();
  void setAvailable(bool available);
  double* getIdleTimes(); //returns array of idle times;
  double getIdleTime(int index);
  int getIdleTimeSize(); //returns size of array idleTime
  void addIdleTime();
  void incrementIdleTime();
  int getOccupied();  //returns count left until window is finished helping current student 
  void setOccupied(int occupied);
};


#endif /*WINDOW_H*/
