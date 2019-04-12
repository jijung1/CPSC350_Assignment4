/*
Name:                   Jin Jung
Student ID:             2329401
Email:                  jijung@chapman.edu
Course no. & Section:   CS350-02
Assignment:             4
*/

/*
  Class invariant: Every instance of this object will have double* values and int size
*/

#ifndef ARITHMETIC_H
#define ARITHMETIC_H


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
