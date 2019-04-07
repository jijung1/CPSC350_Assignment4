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
  RegistrarSim(string filePath);
  ~RegistrarSim();
  void run();
private:
  Window* registrarWindows;
  int openWindows;
  DoublyLinkedList<Student>* students;
  GenQueue<Student>* waitLine;
};



#endif /*REGISTRARSIM_H*/
