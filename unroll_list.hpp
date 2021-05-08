#ifndef UNROLL_LIST_H
#define UNROLL_LIST_H

#include <vector>

using namespace std;

template<typename T> class Node {
 public:
  int totelem;
  vector<T> v;
  Node *next;
  Node *prev;
  Node(int size);
};

template<typename T> class Ulist {
 private:
  int max_elem;
  Node<T> *head;
  Node<T> *tail;

 public:
  Ulist(int max_elem);
  void push_back(T data);
  void pop_back();
  void push_front(T data);
  void pop_front();
  T &front();
  T &back();
  int size();
  bool empty();
  void display();
  void display_reverse();
};

#endif
