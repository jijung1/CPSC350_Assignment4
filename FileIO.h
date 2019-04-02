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
  //char readChar();
  int readInt();
};


//void openStream(string filePath);

#endif /*FILEIO_H*/
