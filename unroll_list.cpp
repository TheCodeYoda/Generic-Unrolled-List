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
      this->tail = newNode;
    }
    else {
      this->tail->v[this->tail->totelem] = data;
      (this->tail->totelem)++;
    }
  }
}

Template void UlistT::display()
{
  Node<T> *temp = this->head;
  while (temp) {
    for (auto i : temp->v) {
      cout << i << " ";
    }
    cout << "\n";
    temp = temp->next;
  }
}

int main()
{
  Ulist<int> u(5);
  u.push_back(1);
  u.push_back(2);
  u.push_back(3);
  u.display();
}
