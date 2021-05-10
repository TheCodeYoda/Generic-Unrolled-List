#include <iostream>
#include <list>
#include <cassert>

#include "unroll_list.hpp"

void assert_str(bool val, const string &str)
{
  if (val) {
    return;
  }
  cerr << "Assertion failed with: " << str << endl;
  assert(false);
}

template<typename T> void assert_eq_ulist(Ulist<T> &ulist, list<T> &list, const string &str = "")
{
  assert_str(ulist.size() == list.size(), str);
  auto uit = ulist.begin();
  auto it = list.begin();
  for (; uit != ulist.end(); uit++, it++) {
    assert_str(*uit == *it, str);
  }
}

template<typename T> void assert_ne_ulist(Ulist<T> &ulist, list<T> &list, const string &str = "")
{
  if (ulist.size() == list.size()) {
    auto uit = ulist.begin();
    auto it = list.begin();
    bool equal = true;
    for (; uit != ulist.end(); uit++, it++) {
      if (*uit != *it) {
        equal = false;
        break;
      }
    }
    assert_str(equal == false, str);
  }
}

int main()
{
  /* constructor */
  {
      /* TODO */
  }

  /* destructor */
  {
      /* TODO */
  }

  /* operator= */
  {
      /* TODO */
  }

  /* assign */
  {
      /* TODO */
  }

  /* get_allocator */
  {
      /* TODO */
  }

  /* front */
  {
      /* TODO */
  }

  /* back */
  {
      /* TODO */
  }

  /* begin */
  {
      /* TODO */
  }

  /* cbegin */
  {
      /* TODO */
  }

  /* end */
  {
      /* TODO */
  }

  /* cend */
  {
      /* TODO */
  }

  /* rbegin */
  {
      /* TODO */
  }

  /* crbegin */
  {
      /* TODO */
  }

  /* rend */
  {
      /* TODO */
  }

  /* crend */
  {
      /* TODO */
  }

  /* empty */
  {
      /* TODO */
  }

  /* size */
  {
      /* TODO */
  }

  /* max_size */
  {
      /* TODO */
  }

  /* clear */
  {
      /* TODO */
  }

  /* insert */
  {
      /* TODO */
  }

  /* emplace */
  {
      /* TODO */
  }

  /* erase */
  {
      /* TODO */
  }

  /* push_back */
  {
    Ulist<int> u(5);
    list<int> l;
    list<int> l2;
    for (int i = 1; i < 11; i++) {
      u.push_back(i);
      l.push_back(i);
      l2.push_back(i + 1);
    }
    assert_eq_ulist(u, l, "push_back()");
    assert_ne_ulist(u, l2, "push_back()");
  }

  /* emplace_back */
  {
      /* TODO */
  }

  /* pop_back */
  {
    Ulist<int> u(5);
    list<int> l;
    for (int i = 1; i < 11; i++) {
      u.push_back(i);
      l.push_back(i);
    }

    u.display();
    for (int i = 0; i < 3; i++) {
      u.pop_back();
      l.pop_back();
    }
    assert_eq_ulist(u, l, "pop_back()");

    u.display();
    for (int i = 0; i < 7; i++) {
      u.pop_back();
      l.pop_back();
    }
    u.display();
    assert_eq_ulist(u, l, "pop_back()");
    assert_str(u.size() == 0, "size pop_back()");
  }

  /* push_front */
  {
    Ulist<int> u(5);
    list<int> l;
    list<int> l2;
    for (int i = 1; i < 11; i++) {
      u.push_front(i);
      l.push_front(i);
      l2.push_front(i + 1);
    }
    assert_eq_ulist(u, l, "push_back()");
    assert_ne_ulist(u, l2, "push_back()");
  }

  /* emplace_front */
  {
      /* TODO */
  }

  /* pop_front */
  {
    Ulist<int> u(5);
    list<int> l;
    for (int i = 1; i < 11; i++) {
      u.push_front(i);
      l.push_front(i);
    }

    u.display();
    for (int i = 0; i < 3; i++) {
      u.pop_front();
      l.pop_front();
    }
    assert_eq_ulist(u, l, "pop_front()");

    u.display();
    for (int i = 0; i < 7; i++) {
      u.pop_front();
      l.pop_front();
    }
    u.display();
    assert_eq_ulist(u, l, "pop_front()");
    assert_str(u.size() == 0, "size pop_front()");
  }

  /* resize */
  {
      /* TODO */
  }

  /* swap */
  {
      /* TODO */
  }

  /* merge */
  {
      /* TODO */
  }

  /* splice */
  {
      /* TODO */
  }

  /* remove */
  {
      /* TODO */
  }

  /* remove_if */
  {
      /* TODO */
  }

  /* reverse */
  {
      /* TODO */
  }

  /* unique */
  {
      /* TODO */
  }

  /* sort */
  {
      /* TODO */
  }

  /* operator== */
  {
      /* TODO */
  }

  /* operator!= */
  {
      /* TODO */
  }

  /* operator< */
  {
      /* TODO */
  }

  /* operator<= */
  {
      /* TODO */
  }

  /* operator> */
  {
      /* TODO */
  }

  /* operator>= */
  {
    /* TODO */
  }
}
