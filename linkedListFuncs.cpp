#include <iostream>
#include <string>
#include <sstream> // for ostringstream
#include <cassert>

#include "linkedList.h"
#include "linkedListFuncs.h"

LinkedList * arrayToLinkedList(int *a, int size) {

  LinkedList * list = new LinkedList;

  if (size <= 0) {
    return list;
  }

  Node* head = new Node;
  head->data = a[0];
  list->head = head;
  list->tail = head;

  for(int i = 1; i < size; i++) {
    Node* next = new Node;
    next->data = a[i];
    list->tail->next = next;
    list->tail = list->tail->next;
  }

  return list;
}
// intToString converts an int to a string

std::string intToString(int i) {
// creates a stream like cout, cerr that writes to a string
  std::ostringstream oss;
  oss << i;
  return oss.str(); // return the string result
}

std::string arrayToString(int a[], int size) {

  std::ostringstream oss;
  // fencepost problem; first element gets no comma in front
  oss << "{";

  if (size>0)
    oss << intToString(a[0]);

  for (int i=1; i<size; i++) {
    oss << "," << intToString(a[i]);
  }
  oss << "}";

  return oss.str();

}


// free up every node on this linked list
// nice clean code thanks to @sashavolv2 (on Twitter) #woot

void freeLinkedList(LinkedList * list) {

  Node *next;

  for (Node *p=list->head; p!=NULL; p=next) {
    next = p->next;
    delete p;
  }

  delete list; // returns memory to the heap
}

std::string linkedListToString(LinkedList *list) {

  std::string result="";
  for (const Node *  p=list->head; p!=NULL; p=p->next) {
    result += "[" + intToString(p->data) + "]->";
  }
  result += "null";
  return result;
}
