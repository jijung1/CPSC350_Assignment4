#include "Arithmetic.h"
#include <iostream>

using namespace std;

Arithmetic::Arithmetic(double* values, int size) {
    this->values = values;
    this->size = size;
}
double Arithmetic::mean() {
  double temp = 0.0f;
  for (int i = 0; i < this->size; ++i) {
    temp += values[i];
  }
  return (temp/size);
}

double Arithmetic::median() {
  double temp = 0.0f;
  for (int i = 0; i < this->size-1; ++i) {
    for (int j = i+1; j < this->size; ++j) {
      temp = this->values[i];
      if(this->values[j] < this->values[i]) {
        this->values[i] = this->values[j];
        this->values[j] = temp;
      }
    }
  }

  if (size % 2 != 0) {  //if odd number of elements
    return this->values[size/2];
  }
  else {
    double temp = (this->values[size/2] + this->values[(size/2) - 1]) / 2;  //avg of middle 2 elements
    return temp;
  }
}

double Arithmetic::max() {
  double max = 0.0f;
  for (int i = 0; i < this->size; ++i) {
    if (this->values[i] > max) {
      max = this->values[i];
    }
  }
  return max;
}

int Arithmetic::greaterThan(double key) {
  int count = 0;
  for (int i = 0; i < this->size; ++i) {
    if (this->values[i] > key) {
      count++;
    }
  }
  return count;
}
