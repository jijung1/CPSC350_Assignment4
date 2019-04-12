/*
Name:                   Jin Jung
Student ID:             2329401
Email:                  jijung@chapman.edu
Course no. & Section:   CS350-02
Assignment:             4
*/

/*
  main.cpp test file to test the functionality of the Registrar Simulation assignment
*/
#include <fstream>
#include <iostream>
#include "Window.h"
#include "RegistrarSim.h"
#include "GenericQueue.h"

using namespace std;

int main(int argc, char** argv) {
  string filePath = "";
  if(argc > 1 && argc < 3) {  //check for valid number of terminal arguments
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
  if(istream.is_open()) { //verify filePath is valid 
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

  getchar();
  return 0;
}
