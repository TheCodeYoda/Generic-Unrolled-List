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
    Ulist<int> u(5);
    list<int> l;
    assert_eq_ulist(u, l, "constructor()");
  }

  /* destructor */
  {
      /* TODO */
      /* auto *u = new Ulist<int>(5); */
      /* delete u; */
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
      /* Ulist<int> u(5); */
      /* list<int> l; */
      /* for (int i = 1; i < 11; i++) { */
      /*   u.push_back(i); */
      /*   l.push_back(i); */
      /* } */
      /* assert_eq_ulist(u, l, "front()"); */
      /* assert_str(u.front() == l.front(), "front()"); */
  }

  /* back */
  {
      /* TODO */
      /* Ulist<int> u(5); */
      /* list<int> l; */
      /* for (int i = 1; i < 11; i++) { */
      /*   u.push_back(i); */
      /*   l.push_back(i); */
      /* } */
      /* assert_eq_ulist(u, l, "back()"); */
      /* assert_str(u.back() == l.back(), "back()"); */
  }

  /* begin */
  {
    Ulist<int> u(5);
    list<int> l;
    for (int i = 1; i < 11; i++) {
      u.push_back(i);
      l.push_back(i);
    }
    assert_eq_ulist(u, l, "begin()");
    assert_str(*u.begin() == *l.begin(), "begin()");
  }

  /* cbegin */
  {
      /* TODO */
      /* Ulist<int> u(5); */
      /* list<int> l; */
      /* for (int i = 1; i < 11; i++) { */
      /*   u.push_back(i); */
      /*   l.push_back(i); */
      /* } */
      /* assert_eq_ulist(u, l, "cbegin()"); */
      /* assert_str(*u.cbegin() == *l.cbegin(), "cbegin()"); */
  }

  /* end */
  {
      /* TODO */
      /* Ulist<int> u(5); */
      /* list<int> l; */
      /* for (int i = 1; i < 11; i++) { */
      /*   u.push_back(i); */
      /*   l.push_back(i); */
      /* } */
      /* assert_eq_ulist(u, l, "end()"); */
      /* assert_str(*u.end() == *l.end(), "end()"); */
  }

  /* cend */
  {
      /* TODO */
      /* Ulist<int> u(5); */
      /* list<int> l; */
      /* for (int i = 1; i < 11; i++) { */
      /*   u.push_back(i); */
      /*   l.push_back(i); */
      /* } */
      /* assert_eq_ulist(u, l, "cend()"); */
      /* assert_str(*u.cend() == *l.cend(), "cend()"); */
  }

  /* rbegin */
  {
    Ulist<int> u(5);
    list<int> l;
    for (int i = 1; i < 11; i++) {
      u.push_back(i);
      l.push_back(i);
    }
    assert_eq_ulist(u, l, "rbegin()");
    assert_str(*u.rbegin() == *l.rbegin(), "rbegin()");
  }

  /* crbegin */
  {
      /* TODO */
      /* Ulist<int> u(5); */
      /* list<int> l; */
      /* for (int i = 1; i < 11; i++) { */
      /*   u.push_back(i); */
      /*   l.push_back(i); */
      /* } */
      /* assert_eq_ulist(u, l, "crbegin()"); */
      /* assert_str(*u.crbegin() == *l.crbegin(), "crbegin()"); */
  }

  /* rend */
  {
      /* TODO */
      /* Ulist<int> u(5); */
      /* list<int> l; */
      /* for (int i = 1; i < 11; i++) { */
      /*   u.push_back(i); */
      /*   l.push_back(i); */
      /* } */
      /* assert_eq_ulist(u, l, "rend()"); */
      /* assert_str(*u.rend() == *l.rend(), "rend()"); */
  }

  /* crend */
  {
      /* TODO */
      /* Ulist<int> u(5); */
      /* list<int> l; */
      /* for (int i = 1; i < 11; i++) { */
      /*   u.push_back(i); */
      /*   l.push_back(i); */
      /* } */
      /* assert_eq_ulist(u, l, "crend()"); */
      /* assert_str(*u.crend() == *l.crend(), "crend()"); */
  }

  /* empty */
  {
    Ulist<int> u(5);
    assert_str(u.empty() == true, "empty()");
    for (int i = 1; i < 11; i++) {
      u.push_back(i);
    }
    assert_str(u.empty() == false, "empty()");
  }

  /* size */
  {
    Ulist<int> u(5);
    assert_str(u.size() == 0, "size()");
    for (int i = 1; i < 11; i++) {
      u.push_back(i);
    }
    assert_str(u.size() == 10, "size()");
  }

  /* max_size */
  {
      /* TODO */
  }

  /* clear */
  {
      /* TODO */
      /* ulist<int> u(5); */
      /* assert_str(u.empty() == true, "clear()"); */
      /* for (int i = 1; i < 11; i++) { */
      /*   u.push_back(i); */
      /* } */
      /* assert_str(u.empty() == false, "clear()"); */
      /* u.clear(); */
      /* assert_str(u.empty() == true, "clear()"); */
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

    for (int i = 0; i < 3; i++) {
      u.pop_back();
      l.pop_back();
    }
    assert_eq_ulist(u, l, "pop_back()");

    for (int i = 0; i < 7; i++) {
      u.pop_back();
      l.pop_back();
    }

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

    for (int i = 0; i < 3; i++) {
      u.pop_front();
      l.pop_front();
    }
    assert_eq_ulist(u, l, "pop_front()");

    for (int i = 0; i < 7; i++) {
      u.pop_front();
      l.pop_front();
    }

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
