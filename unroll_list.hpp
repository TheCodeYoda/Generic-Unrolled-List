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
  class Iterator {
   private:
    Node<T> *ptr;
    int n;

   public:
    Iterator(Node<T> *ptr_, int n_);
    Iterator &operator++();
    Iterator operator++(int);
    bool operator==(const Iterator &rhs);
    bool operator!=(const Iterator &rhs);
    T operator*();
  };

  // List interface
  Ulist(int max_elem);
  void push_back(T data);
  void pop_back();
  void push_front(T data);
  void pop_front();
  const T &front();
  const T &back();
  int size();
  bool empty();
  void insert(const Iterator &it, T data);
  void erase(const Iterator &it);
  void erase(const Iterator &first, const Iterator &last);
  void clear();
  void display();
  void display_reverse();

  // Iterator interface
  Iterator begin();
  Iterator end();
  Iterator rbegin();
  Iterator rend();
};

#endif
