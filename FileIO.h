/*
Name:                   Jin Jung
Student ID:             2329401
Email:                  jijung@chapman.edu
Course no. & Section:   CS350-02
Assignment:             4
*/

/*
  File class for handling file read/write
*/

#ifndef FILEIO_H
#define FILEIO_H


#include <fstream>
#include <string>

using namespace std;

class FileIO {
private:
  string filePath;
  ifstream istream;
public:
  FileIO(string filePath);
  ~FileIO();
  string readLine();
  string readFile();
  bool endOfFile();
  int readInt();
  string toUpperCase(string someString);
};

#endif /*FILEIO_H*/
