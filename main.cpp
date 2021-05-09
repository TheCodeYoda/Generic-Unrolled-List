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

  /* for (int i = 0; i < 5; i++) { */
  /*   u.pop_back(); */
  /* } */
  /* u.display(); */

  /* u.push_front(6); */
  /* u.push_front(7); */
  /* u.push_front(8); */
  /* // u.display_reverse(); */
  /* u.display(); */

  /* cout << "\n\n"; */
  /* disp(u.begin(), u.end()); */
  /* cout << endl; */

  /* cout << *find(u.begin(), u.end(), 8) << "found\n"; */

  /* cout << "\n\n"; */
  /* cout << "\n"; */
  /* std::reverse(u.begin(), u.end()); */
  /* disp(u.begin(), u.end()); */
  /* replace(u.begin(), u.end(), 8, -1); */
  /* cout << endl; */
  /* disp(u.begin(), u.end()); */

  /* // int size = u.size(); */
  /* // for (int i = 0; i < size; i++) { */
  /* //   u.pop_front(); */
  /* //   u.display(); */
  /* // } */
  /* // u.display(); */

  /* // cout << u.size() << " " << u.empty() << endl; */
}
