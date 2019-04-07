#ifndef WINDOW_H
#define WINDOW_H

class Window {
private:
  bool available;
  double* idleTime;
  int idleTimeSize;
  int occupied; //reset to time required for each new student
public:
  Window();
  ~Window();  //delete[] idleTime;
  bool isAvailable();
  void setAvailable(bool available);
  double* getIdleTimes(); //returns array of idle times;
  int getIdleTimeSize(); //returns size of array idleTime
  void addIdleTime();
  void incrementIdleTime();
  int getOccupied();
  void setOccupied(int occupied);
};


#endif /*WINDOW_H*/
