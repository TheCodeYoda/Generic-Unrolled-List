#include <iostream>

#include "unroll_list.hpp"

#define Template template<typename T>
#define NodeT Node<T>
#define UlistT Ulist<T>

Template NodeT::Node(int size)
{
  this->totelem = 0;
  this->arr.resize(size);
  this->next = nullptr;
  this->prev = nullptr;
}

Template UlistT::Ulist(int size)
{
  this->size = size;
  this->head = nullptr;
}

int main()
{
  Ulist<int> u(5);
}
