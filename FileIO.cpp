/*
  .cpp implementation file for FileIO class
*/
#include "FileIO.h"

FileIO::FileIO(string filePath){
  this->filePath = filePath;
  this->istream = ifstream(filePath);
}
FileIO::~FileIO() {
  this->istream.close();
}

string FileIO::readLine() {
  string temp = "";
  getline(istream,temp);
  if (temp.back() == '\r') {  //remove return carriage character from string temp
  temp.pop_back();
  }
  return temp;
}

//char readChar();

int FileIO::readInt()
{
  string line = "";
  getline(istream, line);
  return stoi(line);
}
