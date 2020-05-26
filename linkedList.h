#ifndef NODE_H
#define NODE_H

struct Node {
  int data;
  Node *next;
};

struct LinkedList {
  Node *inner;
};

#endif // NODE_H
