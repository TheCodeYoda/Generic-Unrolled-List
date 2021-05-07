#ifndef UNROLL_LIST_H
#define UNROLL_LIST_H

#include <vector>

using namespace std;

template<typename T> class Node {
 private:
  int totelem;
  vector<T> v;
  Node *next;
  Node *prev;

 public:
  Node(int size);
};

template<typename T> class Ulist {
 private:
  int size;
  Node<T> *head;

 public:
  Ulist(int size);
  void insert(T data);
  void remove(T data);
};

#endif
