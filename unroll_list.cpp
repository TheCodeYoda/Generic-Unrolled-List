#include <iostream>

#include "unroll_list.hpp"

#define Template template<typename T>
#define NodeT Node<T>
#define UlistT Ulist<T>

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
  // TODO
}

Template int UlistT::size()
{
  NodeT *temp = this->head;
  int count = 0;
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

int main()
{
  Ulist<int> u(5);
  for (int i = 1; i < 11; i++) {
    u.push_back(i);
  }
  u.display();
  for (int i = 0; i < 5; i++) {
    u.pop_back();
  }
  u.display();

  u.push_front(6);
  u.push_front(7);
  u.push_front(8);
  // u.display_reverse();
  u.display();

  // cout << u.size() << " " << u.empty();
}
