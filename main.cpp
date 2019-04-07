#include <fstream>
#include <iostream>
//#include "Arithmetic.h"
#include "Window.h"
//#include "FileIO.h"
#include "RegistrarSim.h"
#include "GenericQueue.h"


using namespace std;

//void run();

int main(int argc, char** argv) {
  string filePath = "";
  if(argc > 1 && argc < 3) {
    filePath = argv[1];
    if (filePath.find(".txt") == -1)
    {
      filePath += ".txt";
    }
  }
  else
  {
    cout << "Invalid terminal arguments\nPlease use format: ./[executable] [filelocation]\n";
    return 0;
  }
  ifstream istream(filePath);
  if(istream.is_open()) {
    istream.close();
    RegistrarSim* test;
    test = new RegistrarSim(filePath);
    test->run();
  }
  else
  {
    cout << "File not found! Exiting..\n";
    exit(1);
  }
  /*
  Window hello;
  hello.addIdleTime();
  hello.incrementIdleTime();
  hello.incrementIdleTime();
  hello.incrementIdleTime();
  cout << "idle time size: " << hello.getIdleTimeSize()<<endl;
  double* temp = hello.getIdleTimes();
  cout << temp[0] << endl;
  hello.addIdleTime();
  cout << "idle time size: " <<hello.getIdleTimeSize()<<endl;
  temp = hello.getIdleTimes();
  cout << temp[1] << endl;

  ifstream istream(filePath);

  */
  getchar();
  return 0;
}
