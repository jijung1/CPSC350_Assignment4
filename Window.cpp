/*
  .cpp implementation of class Window

*/
#include "Window.h"

Window::Window() {
  this-> isOpen = true;
  this-> idleTime = new double[100]; //default: number of idle times for each window throughout the day.
  this-> idleTimeSize = 0;
}
Window::~Window() {
  delete[] idleTime;
}
bool Window::open() {
  return this->isOpen;
}
double* Window::getIdleTimes() {
  return this->idleTime;
}
int Window::getIdleTimeSize() {
  return this->idleTimeSize;
}
void Window::addIdleTime() {
  this->idleTime[this->idleTimeSize] = 1;
  this->idleTimeSize++;

}
void Window::incrementIdleTime() {
  this->idleTime[this->idleTimeSize-1] += 1;
}
