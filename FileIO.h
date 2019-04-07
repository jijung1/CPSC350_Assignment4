#ifndef FILEIO_H
#define FILEIO_H

/*
  File class for handling file read/write
*/
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
  //char readChar();
  int readInt();
  string toUpperCase(string someString);
};


//void openStream(string filePath);

#endif /*FILEIO_H*/
