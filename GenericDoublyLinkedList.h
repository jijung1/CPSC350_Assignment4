#ifndef GENERICDOUBLYLINKEDLIST_H
#define GENERICDOUBLYLINKEDLIST_H

#include <iostream>
#include <stdexcept>
using namespace std;
/*
class for file io, class for Arithmetic, class for generic queue, dll, list interface, student class (time of entry, time required), window class (window can just be an array that takes in student.timereq)
and exception class
*/
template <typename E>
class ListNode {
public:
    ListNode();
    ListNode(E d);
    ~ListNode();
    E data;
    ListNode *next;
    ListNode *prev;
};

class ListEmpty : public runtime_error {
public:
  ListEmpty(const string& err) : runtime_error(err) {};
};
class KeyNotFound : public runtime_error {
public:
  KeyNotFound(const string& err) : runtime_error(err) {};
};

template <typename E>
ListNode<E>::ListNode() {
  next = NULL;
  prev = NULL;
}
template <typename E>
ListNode<E>::ListNode(E d) {
  data = d;
  next = NULL;
  prev = NULL;
}

//no delete in node destructor
template <typename E>
ListNode<E>::~ListNode() {
  next = NULL;
  prev = NULL;
}

template <typename E>
class DoublyLinkedList {
private:
  ListNode<E> *front;  //sentinel node for beginning of list
  ListNode<E> *back;   //sentinel node for end of list
  unsigned int size;
public:
  DoublyLinkedList();
  virtual ~DoublyLinkedList();
  void insertFront(E Data);
  void insertBack(E data);
  E removeFront();
  E removeBack();
  virtual int getSize();
  virtual bool empty();
  E remove(E key);
};

template <typename E>
DoublyLinkedList<E>::DoublyLinkedList() {
  size = 0;
  front = new ListNode<E>();
  back = new ListNode<E>();
  front->next = back;
  back->prev = front;
}
template <typename E>
DoublyLinkedList<E>::~DoublyLinkedList() {
  while(!empty()) {removeFront();}
  front = NULL;
  back = NULL;
}
template <typename E>
bool DoublyLinkedList<E>::empty() {
  return size == 0;
}
template <typename E>
int DoublyLinkedList<E>::getSize() {
  return size;
}
template <typename E>
void DoublyLinkedList<E>::insertFront(E data) {
  ListNode<E>* node = new ListNode<E>(data);
  front->next->prev = node;
  node->next = front->next;
  node->prev = front;
  front->next = node;
  size++;
}
template <typename E>
void DoublyLinkedList<E>::insertBack(E data) {
  ListNode<E>* node = new ListNode<E>(data);
  back->prev->next = node;
  node->prev = back->prev;
  node->next = back;
  back->prev = node;
  size++;
}
template <typename E>
E DoublyLinkedList<E>::removeFront() {

  ListNode<E>* node = front->next;
  //check if empty
  if (front->next == back) {
    throw ListEmpty("removeFront from empty list!");
  }
  node->next->prev = node->prev;
  node->prev->next = node->next;
  node->next = NULL;
  node->prev = NULL;
  E temp = node -> data;
  delete node;
  size--;
  return temp;
}
template <typename E>
E DoublyLinkedList<E>::removeBack() {
  ListNode<E>* node = back->prev;
  //check if empty
  if (back->prev == front) {
    throw ListEmpty("removeBack from empty list!");
  }
  node->prev->next = back;
  back->prev = node->prev;
  E temp = node->data;
  node->prev = NULL;
  node->next = NULL;
  delete node;
  size--;
  return temp;
}
template <typename E>
E DoublyLinkedList<E>::remove(E key) { //search for data and remove it
  ListNode<E>* curr = front;
  while(curr->data != key) {
    curr = curr->next;
    if(curr == NULL) {  //key not found
      throw KeyNotFound("Key not Found!");
    }
  }
  curr->next->prev = curr->prev;
  curr->prev->next = curr->next;
  E temp = curr->data;
  curr->next = NULL;
  curr->prev = NULL;
  delete curr;
  size--;

  return temp;
}

#endif
