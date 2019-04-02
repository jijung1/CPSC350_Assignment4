#include <iostream>
#include "Arithmetic.h"
#include "Window.h"
#include "Student.h"

using namespace std;

//void run();

int main(int argc, char** argv) {
  Student* test = new Student[5];
  for (int i = 0; i < 5; ++i) {
    test[i].setArrivalTime(5);
    test[i].setTimeRequired(i*2+1);
  }
  test[0].incrementWaitTime();
  test[0].incrementWaitTime();
  cout << test[0].getWaitTime();
  getchar();
  return 0;
}

/*
void run() {
  //
}
*/
