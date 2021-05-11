#include <iostream>
#include <list>
#include <cassert>
#include <algorithm>

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
    auto *u = new Ulist<int>(5);
    delete u;
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
    Ulist<int> u(5);
    list<int> l;
    for (int i = 1; i < 11; i++) {
      u.push_back(i);
      l.push_back(i);
    }
    assert_eq_ulist(u, l, "front()");
    assert_str(u.front() == l.front(), "front()");
  }

  /* back */
  {
    Ulist<int> u(5);
    list<int> l;
    for (int i = 1; i < 11; i++) {
      u.push_back(i);
      l.push_back(i);
    }
    assert_eq_ulist(u, l, "back()");
    assert_str(u.back() == l.back(), "back()");
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
    Ulist<int> u(5);
    list<int> l;
    for (int i = 1; i < 11; i++) {
      u.push_back(i);
      l.push_back(i);
    }
    assert_eq_ulist(u, l, "cbegin()");
    assert_str(*u.cbegin() == *l.cbegin(), "cbegin()");
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
    Ulist<int> u(5);
    list<int> l;
    for (int i = 1; i < 11; i++) {
      u.push_back(i);
      l.push_back(i);
    }
    assert_eq_ulist(u, l, "crbegin()");
    assert_str(*u.crbegin() == *l.crbegin(), "crbegin()");
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
    Ulist<int> u(5);
    assert_str(u.empty() == true, "clear()");
    for (int i = 1; i < 11; i++) {
      u.push_back(i);
    }
    assert_str(u.empty() == false, "clear()");
    u.clear();
    assert_str(u.empty() == true, "clear()");
  }

  /* insert */
  {
    Ulist<int> u(3);
    list<int> l;
    for (int i = 0; i < 1; i++) {
      u.push_back(i);
      l.push_back(i);
    }
    u.insert(u.begin(), 1);
    l.insert(l.begin(), 1);
    assert_eq_ulist(u, l, "insert()");
    u.clear();
    l.clear();

    for (int i = 0; i < 4; i++) {
      u.push_back(i);
      l.push_back(i);
    }
    u.insert(find(u.begin(), u.end(), 1), 9);
    l.insert(find(l.begin(), l.end(), 1), 9);
    assert_eq_ulist(u, l, "insert()");
    u.clear();
    l.clear();
  }

  /* emplace */
  {
      /* TODO */
  }

  /* erase */
  {
    /* single node, single element */
    Ulist<int> u(3);
    list<int> l;
    u.push_back(1);
    l.push_back(1);
    u.erase(u.begin());
    l.erase(l.begin());
    assert_eq_ulist(u, l, "erase()");
    u.clear();
    l.clear();

    /* single node, 2 elements */
    for (int i = 0; i < 2; i++) {
      u.push_back(i);
      l.push_back(i);
    }
    u.erase(--u.end());
    l.erase(--l.end());
    assert_eq_ulist(u, l, "erase()");
    u.clear();
    l.clear();

    /* 0, 1, _ |  3, 4, _ */
    /* remove 3, 4 */
    for (int i = 0; i < 4; i++) {
      u.push_back(i);
      l.push_back(i);
    }
    u.erase(--(--u.end()));
    l.erase(--(--l.end()));
    for (int i = 4; i < 6; i++) {
      u.push_back(i);
      l.push_back(i);
    }
    u.erase(--u.end());
    l.erase(--l.end());
    u.erase(--u.end());
    l.erase(--l.end());
    assert_eq_ulist(u, l, "erase()");
    u.clear();
    l.clear();

    /* 0, _, _ | 3, 4, _  */
    /* remove 0 */
    for (int i = 0; i < 4; i++) {
      u.push_back(i);
      l.push_back(i);
    }
    u.erase(--(--u.end()));
    l.erase(--(--l.end()));
    u.erase(--(--u.end()));
    l.erase(--(--l.end()));
    for (int i = 4; i < 5; i++) {
      u.push_back(i);
      l.push_back(i);
    }
    u.erase(u.begin());
    l.erase(l.begin());
    assert_eq_ulist(u, l, "erase()");
    u.clear();
    l.clear();

    /* 0, 1, 2 | 3, _, _ | 6, 7, 8 */
    /* remove 3 */
    for (int i = 0; i < 7; i++) {
      u.push_back(i);
      l.push_back(i);
    }
    u.erase(--(--u.end()));
    l.erase(--(--l.end()));
    u.erase(--(--u.end()));
    l.erase(--(--l.end()));
    for (int i = 7; i < 9; i++) {
      u.push_back(i);
      l.push_back(i);
    }
    u.erase(find(u.begin(), u.end(), 3));
    l.erase(find(l.begin(), l.end(), 3));
    assert_eq_ulist(u, l, "erase()");
    u.clear();
    l.clear();

    /* 0, 1, 2 | 3, _, _ | 6, 7, 8 */
    /* remove all */
    for (int i = 0; i < 7; i++) {
      u.push_back(i);
      l.push_back(i);
    }
    u.erase(--(--u.end()));
    l.erase(--(--l.end()));
    u.erase(--(--u.end()));
    l.erase(--(--l.end()));
    for (int i = 7; i < 9; i++) {
      u.push_back(i);
      l.push_back(i);
    }
    u.erase(u.begin(), u.end());
    l.erase(l.begin(), l.end());
    assert_eq_ulist(u, l, "erase()");
    u.clear();
    l.clear();

    /* 0, 1, 2 | 3, _, _ | 6, 7, 8 */
    /* remove [2, 7] */
    for (int i = 0; i < 7; i++) {
      u.push_back(i);
      l.push_back(i);
    }
    u.erase(--(--u.end()));
    l.erase(--(--l.end()));
    u.erase(--(--u.end()));
    l.erase(--(--l.end()));
    for (int i = 7; i < 9; i++) {
      u.push_back(i);
      l.push_back(i);
    }
    u.erase(find(u.begin(), u.end(), 2), find(u.begin(), u.end(), 8));
    l.erase(find(l.begin(), l.end(), 2), find(l.begin(), l.end(), 8));
    assert_eq_ulist(u, l, "erase()");
    u.clear();
    l.clear();

    /* 0, 1, 2 | 3, _, _ | 6, 7, 8 */
    /* remove [0, 3] */
    for (int i = 0; i < 7; i++) {
      u.push_back(i);
      l.push_back(i);
    }
    u.erase(--(--u.end()));
    l.erase(--(--l.end()));
    u.erase(--(--u.end()));
    l.erase(--(--l.end()));
    for (int i = 7; i < 9; i++) {
      u.push_back(i);
      l.push_back(i);
    }
    u.erase(find(u.begin(), u.end(), 0), find(u.begin(), u.end(), 6));
    l.erase(find(l.begin(), l.end(), 0), find(l.begin(), l.end(), 6));
    assert_eq_ulist(u, l, "erase()");
    u.clear();
    l.clear();
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
