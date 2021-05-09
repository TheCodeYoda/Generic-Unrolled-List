#include <iostream>
#include <algorithm>
#include <cassert>
#include <list>

#include "unroll_list.hpp"

#define Template template<typename T>
#define NodeT Node<T>
#define UlistT Ulist<T>
#define IteratorT Iterator<T>

Template NodeT::Node(int size)
{
  this->totelem = 0;
  this->v.resize(size);
  this->next = nullptr;
  this->prev = nullptr;
}

Template UlistT::Ulist(int max_elem)
{
  this->max_elem = max_elem;
  this->head = nullptr;
  this->tail = nullptr;
}

Template void UlistT::push_back(T data)
{
  if (this->head == nullptr) {
    this->head = new Node<T>(this->max_elem);
    this->head->v[0] = data;
    (this->head->totelem)++;
    this->tail = this->head;
  }
  else {
    if (this->tail->totelem == this->max_elem) {
      NodeT *newNode = new Node<T>(this->max_elem);
      newNode->v[0] = data;
      (newNode->totelem)++;
      this->tail->next = newNode;
      newNode->prev = this->tail;
      this->tail = newNode;
    }
    else {
      this->tail->v[this->tail->totelem] = data;
      (this->tail->totelem)++;
    }
  }
}

Template void UlistT::pop_back()
{
  if (this->head) {
    if (this->tail->totelem == 0) {
      return;
    }
    (this->tail->totelem)--;
    if (this->tail->totelem == 0) {
      NodeT *garbage = this->tail;
      this->tail = this->tail->prev;
      if (this->tail) {
        this->tail->next = nullptr;
      }
      delete garbage;
    }
  }
}

Template void UlistT::push_front(T data)
{
  if (this->head == nullptr) {
    this->head = new NodeT(this->max_elem);
    this->head->v[0] = data;
    (this->head->totelem)++;
    this->tail = this->head;
  }
  else {
    if (this->head->totelem == this->max_elem) {
      NodeT *newNode = new NodeT(this->max_elem);
      newNode->v[0] = data;
      (newNode->totelem)++;
      newNode->next = this->head;
      this->head->prev = newNode;
      this->head = newNode;
    }
    else {
      for (int i = this->head->totelem; i > 0; i--) {
        this->head->v[i] = this->head->v[i - 1];
      }
      this->head->v[0] = data;
      (this->head->totelem)++;
    }
  }
}

Template void UlistT::pop_front()
{
  if (this->head) {
    if (this->tail->totelem == 0) {
      return;
    }
    for (int i = 0; i < (this->head->totelem) - 1; i++) {
      this->head->v[i] = this->head->v[i + 1];
    }
    (this->head->totelem)--;
    if (this->head->totelem == 0) {
      NodeT *garbage = this->head;
      this->head = this->head->next;
      if (this->head) {
        this->head->prev = nullptr;
      }
      delete garbage;
    }
  }
}

Template size_t UlistT::size()
{
  NodeT *temp = this->head;
  size_t count = 0;
  while (temp) {
    count += temp->totelem;
    temp = temp->next;
  }
  return count;
}

Template bool UlistT::empty()
{
  if ((*this).size()) {
    return false;
  }
  return true;
}

Template void UlistT::display()
{
  Node<T> *temp = this->head;
  while (temp) {
    for (size_t i = 0; i < temp->totelem; i++) {
      cout << temp->v[i] << " ";
    }
    cout << "\n";
    temp = temp->next;
  }
}

Template void UlistT::display_reverse()
{
  Node<T> *temp = this->tail;
  while (temp) {
    for (int i = (temp->totelem) - 1; i > -1; i--) {
      cout << temp->v[i] << " ";
    }
    cout << "\n";
    temp = temp->prev;
  }
}

// Iterator stuff.....

Template UlistT::Iterator::Iterator(NodeT *ptr_, NodeT *tail_, NodeT *head_, int n_)
{
  this->ptr = ptr_;
  this->tail = tail_;
  this->head = head_;
  this->n = n_;
}

Template bool UlistT::Iterator::operator==(const UlistT::Iterator &rhs)
{
  if ((this->ptr == rhs.ptr) && (this->n = rhs.n)) {
    return true;
  }
  return false;
}

Template bool UlistT::Iterator::operator!=(const UlistT::Iterator &rhs)
{
  if ((this->ptr != rhs.ptr) || (this->n != rhs.n)) {
    return true;
  }
  return false;
}

Template typename UlistT::Iterator &UlistT::Iterator::operator++()
{
  if (this->ptr == nullptr) {
    this->ptr = this->head;
    this->n = 0;
    return *(this);
  }
  if (n == (this->ptr->totelem - 1)) {
    this->ptr = this->ptr->next;
    this->n = 0;
  }
  else {
    ++(this->n);
  }
  return (*this);
}

Template typename UlistT::Iterator UlistT::Iterator::operator++(int)
{
  Iterator temp = *this;
  ++(*this);
  return temp;
}

Template typename UlistT::Iterator &UlistT::Iterator::operator--()
{
  if (this->ptr == nullptr) {
    this->ptr = this->tail;
    this->n = (this->ptr->totelem) - 1;
    return (*this);
  }
  if (n == 0) {
    this->ptr = this->ptr->prev;
    if (this->ptr) {
      this->n = (this->ptr->totelem) - 1;
    }
    else {
      this->n = 0;
    }
  }
  else {
    --(this->n);
  }
  return (*this);
}

Template typename UlistT::Iterator UlistT::Iterator::operator--(int)
{
  Iterator temp = *this;
  --(*this);
  return temp;
}

Template T &UlistT::Iterator::operator*()
{
  return this->ptr->v[this->n];
}

Template typename UlistT::Iterator UlistT::begin()
{
  return Iterator(this->head, this->tail, this->head, 0);
}

Template typename UlistT::Iterator UlistT::end()
{
  return Iterator(this->tail->next, this->tail, this->head, 0);
}

Template typename UlistT::Iterator UlistT::rbegin()
{
  return Iterator(this->tail, this->tail, this->head, (this->tail->totelem) - 1);
}

Template typename UlistT::Iterator UlistT::rend()
{
  return Iterator(this->head->prev, this->tail, this->head, 0);
}

template<typename ptr_t> void disp(ptr_t first, ptr_t last)
{
  while (first != last) {
    cout << *first << " ";
    ++first;
  }
}

template<typename T> void my_swap(T &x, T &y)
{
  T temp = x;
  x = y;
  y = temp;
}

template<class BidirIt> void my_reverse(BidirIt first, BidirIt last)
{
  while ((first != last) && (first != --last)) {
    std::iter_swap(first++, last);
  }
}

template<typename ptr_t, typename T> ptr_t my_find(ptr_t first, ptr_t last, T t)
{
  while (first != last && !(*first == t)) {
    ++first;
  }
  return first;
}
