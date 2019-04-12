/*
Name:                   Jin Jung
Student ID:             2329401
Email:                  jijung@chapman.edu
Course no. & Section:   CS350-02
Assignment:             4
*/

/*
  Implementation file for Window class.
*/
#include "Window.h"
#include <iostream>
using namespace std;

Window::Window() { //default constructor
  this-> available = true;
  this-> occupied = 0;
  this-> idleTime = new double[100]; //default: number of idle times for each window throughout the day.
  for(int i = 0; i < 100; ++i) {
    idleTime[i] = -1;
  }
  this-> idleTimeSize = -1;
}
Window::~Window() { //destructor
  delete[] idleTime;
}

//accessor and mutator functions:

bool Window::isAvailable() {
  return this->available;
}
void Window::setAvailable(bool available) {
  this->available = available;
}

void Window::setOccupied(int occupied) {
  this->occupied = occupied;
}
int Window::getOccupied() {
  return this->occupied;
}

double* Window::getIdleTimes() {
  return this->idleTime;
}
double Window::getIdleTime(int index) {
  return this->idleTime[index];
}
int Window::getIdleTimeSize() {
  return this->idleTimeSize;
}
void Window::addIdleTime() {
  this->idleTimeSize++;
  idleTime[idleTimeSize] = 0;

}
void Window::incrementIdleTime() {  //increments current idle time 
  if(this->idleTimeSize >= 0) {
    this->idleTime[this->idleTimeSize] += 1;
  }
}
