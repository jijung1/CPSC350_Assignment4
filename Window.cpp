/*
  .cpp implementation of class Window

*/
#include "Window.h"
#include <iostream>
using namespace std;

Window::Window() {
  this-> available = true;
  this-> occupied = 0;
  this-> idleTime = new double[100]; //default: number of idle times for each window throughout the day.
  for(int i = 0; i < 100; ++i) {
    idleTime[i] = 0;
  }
  this-> idleTimeSize = 0;
}
Window::~Window() {
  delete[] idleTime;
}
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

//void Window::setIsOpen(bool open) {this->isOpen = open;}
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
  idleTime[idleTimeSize] = 1;
  this->idleTimeSize++;
}
//void closeWindow()
void Window::incrementIdleTime() {
  if(this->idleTimeSize-1 >= 0) {
    this->idleTime[this->idleTimeSize-1] += 1;
  }
}
