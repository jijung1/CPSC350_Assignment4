#ifndef WINDOW_H
#define WINDOW_H

class Window {
private:
  bool isOpen;
  double* idleTime;
  int idleTimeSize;
public:
  Window();
  ~Window();  //delete[] idleTime;
  bool open();
  double* getIdleTimes(); //returns array of idle times;
  int getIdleTimeSize(); //returns size of array idleTime
  void addIdleTime();
  void incrementIdleTime();
};


#endif /*WINDOW_H*/
