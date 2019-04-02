/*

  DLL based generic queue

*/
#include "GenericDoublyLinkedList.h"
#include <iostream>
#include <stdexcept>

using namespace std;

template <typename E>
class GenQueue {
  public:
    GenQueue(); //default constructor
    GenQueue(int maxSize); //overloaded constructor
    ~GenQueue();
    void insert(E d); //aka enqueue()
    E remove(); //aka dequeue()
    E front(); //aka peek()
    bool isEmpty();
    int getSize();
  private:
    DoublyLinkedList<E> myQueue;
};

class QueueFull : public runtime_error {
public:
  QueueFull(const string& err) : runtime_error(err) {};
};
class QueueEmpty : public runtime_error {
public:
  QueueEmpty(const string& err) : runtime_error(err) {};
};

//implementation
template <typename E>
GenQueue<E>::GenQueue() {
    myQueue = new DoublyLinkedList<E>(100); //default size = 100
}
template <typename E>
GenQueue<E>::GenQueue(int maxSize) {
  myQueue = new DoublyLinkedList<E>(maxSize);
}
template <typename E>
GenQueue<E>::~GenQueue() {
  delete[] myQueue;
}
template <typename E>
void GenQueue<E>::insert(E d) {
  myQueue.insertBack(d);
}
template <typename E>
E GenQueue<E>::remove() {
  E temp = myQueue.removeFront();
  return temp;
}
template <typename E>
E GenQueue<E>::front() {  //aka peek()
  if(isEmpty()) {
    throw QueueEmpty("front from empty Queue!");
  }
  E temp = myQueue.removeFront();
  myQueue.insertFront(temp);
  return temp;
}

template <typename E>
bool GenQueue<E>::isEmpty() {
  return (myQueue.size() == 0);
}
template <typename E>
int GenQueue<E>::getSize() {
  return myQueue.getSize();
}

int main(int argc, char** argv) {
  GenQueue<int> a(4);
  int n = 2;
  for (int i = 0; i < 4; ++i) {
    a.insert(n);
    cout << "i: " << i << " value: " << n << endl;
    n+=2;
  }
  for (int i = 0; i < 3; ++i) {
    cout << "removing: " << a.remove() << endl;
  }
  for (int i = 0; i < 3; ++i) {
    a.insert(n);
    cout << "i: " << i << " value: " << n << endl;
    n+=2;
  }
  for (int i = 0; i < 3; ++i) {
    cout << "removing: " << a.remove() << endl;
  }
  for (int i = 0; i < 3; ++i) {
    a.insert(n);
    cout << "i: " << i << " value: " << n << endl;
    n+=2;
  }
  for (int i = 0; i < 3; ++i) {
    cout << "removing: " << a.remove() << endl;
  }
  for (int i = 0; i < 3; ++i) {
    a.insert(n);
    cout << "i: " << i << " value: " << n << endl;
    n+=2;
  }
  for (int i = 0; i < 3; ++i) {
    cout << "removing: " << a.remove() << endl;
  }

  cout << a.front();
  return 0;
}
