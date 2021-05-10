#ifndef UNROLL_LIST_H
#define UNROLL_LIST_H

#include <vector>
#include <iterator>  // For std::bidirectional_iterator_tag
#include <cstddef>   // For std::ptrdiff_t

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
    Node<T> *head;
    Node<T> *tail;
    int n;

   public:
    using iterator_category = std::bidirectional_iterator_tag;
    using difference_type = T;
    using value_type = T;
    using pointer = T *;  // or also value_type*
    using reference = T &;
    Iterator(Node<T> *ptr, Node<T> *tail, Node<T> *head, int n);
    Iterator &operator++();
    Iterator operator++(int);
    Iterator &operator--();
    Iterator operator--(int);
    bool operator==(const Iterator &rhs);
    bool operator!=(const Iterator &rhs);
    T &operator*();
    const T &operator*() const;
  };

  // List interface
  Ulist(int max_elem);
  ~Ulist();
  void push_back(T data);
  void pop_back();
  void push_front(T data);
  void pop_front();
  T &front();
  const T &front() const;
  T &back();
  const T &back() const;
  size_t size();
  bool empty();
  void insert(const Iterator &it, T data);
  void erase(const Iterator &it);
  void erase(const Iterator &first, const Iterator &last);
  void clear();
  void display();
  void display_reverse();

  // Iterator interface
  Iterator begin();
  const Iterator cbegin() const;
  Iterator end();
  const Iterator cend() const;
  Iterator rbegin();
  Iterator rend();
};

#endif
