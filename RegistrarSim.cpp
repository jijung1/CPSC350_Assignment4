#include "registrarSim.h"

RegistrarSim::RegistrarSim(string filePath) {
  FileIO inputData(filePath);   //read from input file and initialize students and registrar windows
  openWindows = inputData.readInt();
  registrarWindows = new Window[openWindows];
  students = new DoublyLinkedList<Student>();
  waitLine = new GenQueue<Student>();
  while(!inputData.endOfFile()) {
    int time = inputData.readInt();
    int numOfStudents = inputData.readInt();
    while (numOfStudents > 0) {
      int timeReq = inputData.readInt();
      Student student(time, timeReq);
      students->insertFront(student);
      numOfStudents--;
    }
  }
}

RegistrarSim::~RegistrarSim() {
  delete[] registrarWindows;
  while(!students->empty()) {
    students->removeFront();
  }
  while(!waitLine->isEmpty()) {
    waitLine->remove();
  }
  delete[] students;
  delete[] waitLine;
}

void RegistrarSim::run() {
  int time = 0;
  int numIdle = 0;
  int studentCount = students->getSize();
  int numStudents = studentCount;
  double* studentWaitTime = new double[numStudents];
  int n = 0;
  int servicedStudents = 0;
  while(true) {
    int count = students->getSize();
    while(count > 0) {  //add students with valid time of arrival to queue
      Student nextStudent = students->removeBack();
      if(nextStudent.getArrivalTime() == time) { //if student arrived at this time send into queue
        waitLine->insert(nextStudent);
      }
      else {
        students->insertBack(nextStudent);
      }
      count--;
    }
    for (int k = 0; k < openWindows; ++k) {
      if(registrarWindows[k].isAvailable() && !waitLine->isEmpty()) { //if students waiting in queue and window available
        Student temp = waitLine->remove();
        studentWaitTime[n] = temp.getWaitTime();
        n++;
        registrarWindows[k].setOccupied(temp.getTimeRequired());
        registrarWindows[k].setAvailable(false);
      }
      else if(registrarWindows[k].isAvailable()) {
        if(time == 0) {
          registrarWindows[k].addIdleTime();
          numIdle++;
        }
        else {
          registrarWindows[k].incrementIdleTime();
        }
      }
    }
    for (int k = 0; k < waitLine->getSize(); ++k) { //increment wait time for students in queue
      Student temp = waitLine->remove();
      if(time != 0) {
        temp.incrementWaitTime();
      }
      waitLine->insert(temp);
    }

    int i = 0;
    while(i < openWindows) {  //check and update open windows
      if(registrarWindows[i].getOccupied() <= 0 && !registrarWindows[i].isAvailable()) {
        registrarWindows[i].setAvailable(true); //reset availability
        registrarWindows[i].addIdleTime();
        numIdle++;
        studentCount--;
      }
      if(registrarWindows[i].getOccupied() > 0) { //if occupied, make sure window set to unavailable
        registrarWindows[i].setAvailable(false);
      }
      i++;
    }


    bool endSim = true; //end conditions
    for (int j = 0; j < openWindows; ++j) {
      if (!registrarWindows[j].isAvailable()) {
        registrarWindows[j].setOccupied(registrarWindows[j].getOccupied()-1); //decrement occupied counter
        endSim = false;
      }
    }
    if(studentCount == 0 && endSim){  //if no students left and all windows are available, end
      cout << "all students serviced\n Metrics: " << endl;
      cout << "num idles: " << numIdle << endl;
      double* idleTimes = new double[numIdle];
      int num = 0;
      for (int i = 0; i < openWindows; ++i) {
        for(int j = 0; j < registrarWindows[i].getIdleTimeSize(); ++j) {
          cout << registrarWindows[i].getIdleTime(j) << endl;
          if (registrarWindows[i].getIdleTime(j) != 0) {
            idleTimes[num++] = registrarWindows[i].getIdleTime(j);
          }
        }
      }
      for (int j = 0; j < numIdle; ++j) {
        cout << "idle times: " << idleTimes[j] << endl;
      }
      for (int j = 0; j < numStudents; ++j) {
        cout << "wait time " << j << ": " << studentWaitTime[j] << endl;
      }

      /*
      double* studentdata = new double[Students.getSize()];
      Window* windowData;
      //numStudents
      //numIdle
      Arithmetic studentInfo();

      //mean student wait time studentdata.mean()
      //median student wait time studentdata.median()
      //longest student wait time studentdata.max()
      //number of students over 10 minutes studentdata.greaterThan(10);
      //mean window idle time (all idle times / idle count) windowData.mean()
      //longest window idle time windowdata.max();
      //number of windows over 5 minutes windowdata.greaterThan(5)

      */
      break;
    }
    cout << "time: " << time << endl;
    cout << "students in line: " << waitLine->getSize() << endl;
    time++;
  }
}


  //Student temp = students->removeBack();
  //cout << "time required: " << temp.getTimeRequired() << endl;
  //cout << "arrival time: " << temp.getArrivalTime() << endl;
  //all data read from input file
  //run analysis by iterative pushing students into waitline, then into open windows, and tracking information
  //then use arith class to output information

/*
Student* test = new Student[5];
for (int i = 0; i < 5; ++i) {
  test[i].setArrivalTime(5);
  test[i].setTimeRequired(i*2+1);
}
test[0].incrementWaitTime();
test[0].incrementWaitTime();
cout << test[0].getWaitTime();
*/
