/*
Name:                   Jin Jung
Student ID:             2329401
Email:                  jijung@chapman.edu
Course no. & Section:   CS350-02
Assignment:             4
*/

/*
  Implementation file for RegistrarSim class.
*/
#include "registrarSim.h"

RegistrarSim::RegistrarSim(string filePath) { //main constructor reads from specified file path and initializes initial values
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

RegistrarSim::~RegistrarSim() { //destructor
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

void RegistrarSim::run() {  //run registrar simulation

  int time = 0; //keep timer of simulation (unit of measure: minutes)
  int numIdle = 0;  //keep track of number of times windows have been idle to create a container later to perform math operations on
  int studentCount = students->getSize();
  int numStudents = studentCount;
  double* studentWaitTime = new double[numStudents]; //need this for student data
  int waitTime = 0; //keep track of student wait time in line
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
        studentWaitTime[waitTime] = temp.getWaitTime();
        waitTime++;
        registrarWindows[k].setOccupied(temp.getTimeRequired());
        registrarWindows[k].setAvailable(false);
      }
      if(registrarWindows[k].isAvailable() && time != 0) {  //if registrarWindows are idle and idle time has already been added
          registrarWindows[k].incrementIdleTime();
      }
      else if (registrarWindows[k].isAvailable()){
        registrarWindows[k].addIdleTime();
        int index = registrarWindows[k].getIdleTimeSize();
        numIdle++;
      }
    }

    for (int k = 0; k < waitLine->getSize(); ++k) { //increment wait time for students in queue
      Student temp = waitLine->remove();
      if(time != 0) {
        temp.incrementWaitTime();
      }
      waitLine->insert(temp);
    }

    bool endSim = true; //end conditions
    for (int j = 0; j < openWindows; ++j) {
      if (!registrarWindows[j].isAvailable()) {
        registrarWindows[j].setOccupied(registrarWindows[j].getOccupied()-1); //decrement occupied counter
        endSim = false;
      }
    }

    bool* idleOver5 = new bool[openWindows]; //flag for later determining if this window had idle time over 5 minutes
    for (int i = 0; i < openWindows; ++i) {
      idleOver5[i] = false;
    }

    if(studentCount == 0 && endSim){  //if no students left and all windows are available, end

      cout << "all students serviced\n\nMetrics:\n\n-------------------------------------------------------------\n-------------------------------------------------------------" << endl;
      double* idleTimes = new double[numIdle];
      int num = 0;
      for (int i = 0; i < openWindows; ++i) {
        for(int j = 0; j < (registrarWindows[i].getIdleTimeSize())+1; ++j) {
          if(registrarWindows[i].getIdleTime(j) > 5) {
            idleOver5[i] = true;
          }
          idleTimes[num++] = registrarWindows[i].getIdleTime(j);
        }
      }
      double *winIdleTime = new double[num];
      for (int j = 0; j < num; ++j) {
        winIdleTime[j] = idleTimes[j];
      }
      for (int j = 0; j < numStudents; ++j) {
      }

      cout.setf(ios::showpoint);  //make output pretty
      cout.setf(ios::fixed);
      cout.precision(2);

      Arithmetic studentData(studentWaitTime, numStudents);
      cout << "Mean Student wait time: " << studentData.mean() << " minute(s)" << endl;
      cout << "Median Student wait time: " << studentData.median() << " minute(s)" << endl;
      cout << "Longest student wait time: " << studentData.max() << " minute(s)" << endl;
      cout << "Number of students who waited over 10 minutes: " << studentData.greaterThan(10) << " student(s)" << endl;

      Arithmetic windowData(winIdleTime, num);
      int numIdleOver5 = 0;
      for(int k = 0; k < openWindows; ++k) {  //count number of windows that were idle over 5 minutes
        if(idleOver5[k]) {
          numIdleOver5++;
        }
      }

      cout << "Mean window idle time: " << windowData.mean() << " minute(s)" << endl;
      cout << "Longest window idle time: " << windowData.max() << " minute(s)" << endl;
      cout << "Number of windows idle over 5 minute(s): " << numIdleOver5 << endl;


      //number of windows over 5 minutes windowdata.greaterThan(5)
      break;
    }
    int i = 0;
    while(i < openWindows) {  //check and update open windows
      if(registrarWindows[i].getOccupied() <= 0 && !registrarWindows[i].isAvailable()) {
        registrarWindows[i].setAvailable(true); //reset availability
        registrarWindows[i].addIdleTime();

        numIdle++;
        studentCount--;
      }
      i++;
    }
    for (int k = 0; k < openWindows; ++k) {
      int index = registrarWindows[k].getIdleTimeSize();
    }
    time++;
  }
}
