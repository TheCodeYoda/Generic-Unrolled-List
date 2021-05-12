#include <iostream>
#include <list>
#include <cassert>
#include <algorithm>

#include "unroll_list.hpp"

struct Date {
  int dd;
  int mm;
  int yy;

  friend ostream &operator<<(ostream &o, const Date &d);
  friend bool operator==(const Date &x, const Date &y);
};

ostream &operator<<(ostream &o, const Date &d)
{
  o << d.dd << "." << d.mm << "." << d.yy;
  return o;
}

bool operator==(const Date &x, const Date &y)
{
  return x.dd == y.dd && x.mm == y.mm && x.yy == y.yy;
}

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

template<typename T> void assert_ne_ulist(Ulist<T> &ulist, Ulist<T> &list, const string &str = "")
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
    Ulist<int> u(5);
    for (int i = 0; i < 10; i++) {
      u.push_back(i);
    }
    Ulist<int> u2(3);
    for (int i = 0; i < 8; i++) {
      u2.push_back(i * 10);
    }
    u = u2;

    *u.begin() = 125;
    assert_ne_ulist(u, u2, "operator=");
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
    Ulist<int> u(5);
    list<int> l;
    for (int i = 1; i < 11; i++) {
      u.push_back(i);
      l.push_back(i);
    }
    assert_eq_ulist(u, l, "end()");
    assert_str(*(--u.end()) == *(--l.end()), "end()");
  }

  /* cend */
  {
    Ulist<int> u(5);
    list<int> l;
    for (int i = 1; i < 11; i++) {
      u.push_back(i);
      l.push_back(i);
    }
    assert_eq_ulist(u, l, "cend()");
    auto uit = u.begin();
    auto lit = l.begin();
    for (; uit != u.cend() && lit != l.cend(); uit++, lit++) {
      assert_str(*uit == *lit, "cend()");
    }
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

  /* operations */
  {
    Ulist<int> ui(3);
    ui.push_back(1);
    ui.push_back(2);
    ui.push_back(3);
    ui.display();
    cout << *find(ui.begin(), ui.end(), 2) << " element found...\n";
    cout << "\n\n";

    Ulist<float> uf(5);
    uf.push_front(1.1);
    uf.push_front(2.1);
    uf.push_front(3.1);
    uf.push_front(4.1);
    uf.push_front(5.1);
    uf.push_front(6.1);
    uf.display();
    cout << "min_element: " << *std::min_element(uf.begin(), uf.end()) << endl;
    cout << "max_element: " << *std::max_element(uf.begin(), uf.end()) << endl;
    cout << endl;
    cout << endl;

    Ulist<string> us(3);
    us.push_back("hello");
    us.push_back("world");
    us.push_back("bill");
    us.push_back("is");
    us.push_back("married");
    us.display();
    us.erase((--us.end()));
    us.insert(us.end(), "single");
    us.display();
    cout << endl;

    replace(us.begin(), us.end(), string("single"), string("married"));
    replace(us.begin(), us.end(), string("is"), string("was"));
    us.display();
    cout << endl;

    reverse(us.begin(), us.end());
    us.display();
    cout << endl << " " << *find(us.begin(), us.end(), string("was")) << "element found...\n";
    cout << endl;
  }

  {
    Ulist<Date> u(3);
    u.push_back({30, 1, 20});
    u.push_back({21, 11, 19});
    u.push_back({1, 3, 19});
    u.push_back({2, 7, 20});
    u.push_back({3, 11, 3});
    u.push_back({21, 12, 28});

    u.display();

    reverse(u.begin(), u.end());
    u.display();
    auto it = find_if(u.begin(), u.end(), [](const Date &d) { return d.yy == 3; });
    u.insert(it, {1, 2, 4});

    u.display();

    Date x = {1, 2, 4};
    u.erase(find_if(u.begin(), u.end(), [&](const Date &d) { return d == x; }));

    u.display();
  }
}
