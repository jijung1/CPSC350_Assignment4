/*
Name:                   Jin Jung
Student ID:             2329401
Email:                  jijung@chapman.edu
Course no. & Section:   CS350-02
Assignment:             4
*/

/*
  Implementation file for FileIO class
*/
#include "FileIO.h"
#include <fstream>
#include <iostream>

FileIO::FileIO(string filePath){ //main contructor
  this->filePath = filePath;
  this->istream = ifstream(filePath);
}
FileIO::~FileIO() { //destructor
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

string FileIO::readFile() {
  string data = "";
  string temp = "";
  while(!istream.eof()) {
    data = readLine();
    if(temp.length() <= 0) {
      cout << "skipping empty line..\n";
      continue;
    }
    data += temp + " ";
  }
  return data;
}
bool FileIO::endOfFile() {
  return (istream.eof());
}
string FileIO::toUpperCase(string someString) {
  for(int i = 0; i < someString.length(); ++i)
  {
    if (static_cast<int>(someString[i]) > 96 && static_cast<int>(someString[i]) < 123)
    {
      someString[i] = static_cast<char>(static_cast<int>(someString[i])-32);
    }
  }
  return someString;
}
