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
      Node<T> *newNode = new Node<T>(this->max_elem);
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
  }
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
  u.pop_back();
  u.pop_back();
  u.push_back(100);
  u.display();
  u.display_reverse();
}
