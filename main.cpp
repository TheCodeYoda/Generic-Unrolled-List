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
      /* TODO */
  }

  /* push_front */
  {
      /* TODO */
  }

  /* emplace_front */
  {
      /* TODO */
  }

  /* pop_front */
  {
      /* TODO */
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
