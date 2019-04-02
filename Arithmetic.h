#ifndef ARITHMETIC_H
#define ARITHMETIC_H

/*
  Arithmetic class for handling mathematic operations
*/

class Arithmetic {
private:
  double* values;
  int size;
public:
  Arithmetic(double* values, int size);
  double mean();
  double median();
  double max();
  int greaterThan(double key);  //returns number of values that are >key
};

#endif /*ARITHMETIC_H*/
