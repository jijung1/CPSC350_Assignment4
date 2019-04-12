/*
Name:                   Jin Jung
Student ID:             2329401
Email:                  jijung@chapman.edu
Course no. & Section:   CS350-02
Assignment:             4
*/

/*
  Class invariant: Every instance of this class will have members: Window* registrarWindows, int openWindows, DoublyLinkedList<Student>* students, and GenQueue<Student>* waitLine.
*/

#ifndef REGISTRARSIM_H
#define REGISTRARSIM_H

#include <iostream>
#include "GenericDoublyLinkedList.h"
#include "GenericQueue.h"
#include "Student.h"
#include "Window.h"
#include "Arithmetic.h"
#include "FileIO.h"
#include <cstdlib>

using namespace std;

class RegistrarSim {
public:
  RegistrarSim(string filePath);  //main constructor that reads from specified filepath to initialize the simulation
  ~RegistrarSim();
  void run();
private:
  Window* registrarWindows;
  int openWindows;
  DoublyLinkedList<Student>* students;
  GenQueue<Student>* waitLine;
};



#endif /*REGISTRARSIM_H*/
