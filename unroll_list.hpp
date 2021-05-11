#ifndef UNROLL_LIST_H
#define UNROLL_LIST_H

#include <vector>
#include <iterator>  // For std::bidirectional_iterator_tag
#include <cstddef>   // For std::ptrdiff_t

using namespace std;

template<typename T> class Node {
 public:
  int totelem;
  vector<T> v;
  Node *next;
  Node *prev;
  Node(int size)
  {
    this->totelem = 0;
    this->v.resize(size);
    this->next = nullptr;
    this->prev = nullptr;
  }

  Node<T> &operator=(const Node<T> &other)
  {
    this->totelem = other.totelem;
    this->v = other.v;
    return *this;
  }
};

template<typename T> class Ulist {
 private:
  int max_elem;
  Node<T> *head;
  Node<T> *tail;

 public:
  class Iterator {
   private:
    Node<T> *ptr;
    Node<T> *head;
    Node<T> *tail;
    int n;

   public:
    using iterator_category = std::bidirectional_iterator_tag;
    using difference_type = std::ptrdiff_t;
    using value_type = T;
    using pointer = T *;  // or also value_type*
    using reference = T &;
    Iterator(Node<T> *ptr, Node<T> *tail, Node<T> *head, int n)
    {
      this->ptr = ptr;
      this->tail = tail;
      this->head = head;
      this->n = n;
    }

    Iterator &operator++()
    {
      if (this->ptr == nullptr) {
        this->ptr = this->head;
        this->n = 0;
        return *(this);
      }
      if (n == (this->ptr->totelem - 1)) {
        this->ptr = this->ptr->next;
        this->n = 0;
      }
      else {
        ++(this->n);
      }
      return (*this);
    }

    Iterator operator++(int)
    {
      Iterator temp = *this;
      ++(*this);
      return temp;
    }

    Iterator &operator--()
    {
      if (this->ptr == nullptr) {
        this->ptr = this->tail;
        assert(this->tail);
        this->n = (this->ptr->totelem) - 1;
        return (*this);
      }
      if (n == 0) {
        this->ptr = this->ptr->prev;
        if (this->ptr) {
          this->n = (this->ptr->totelem) - 1;
        }
        else {
          this->n = 0;
        }
      }
      else {
        --(this->n);
      }
      return (*this);
    }

    Iterator operator--(int)
    {
      Iterator temp = *this;
      --(*this);
      return temp;
    }

    bool operator==(const Iterator &rhs)
    {
      if ((this->ptr == rhs.ptr) && (this->n == rhs.n)) {
        return true;
      }
      return false;
    }

    bool operator!=(const Iterator &rhs)
    {
      if ((this->ptr != rhs.ptr) || (this->n != rhs.n)) {
        return true;
      }
      return false;
    }

    T &operator*()
    {
      return this->ptr->v[this->n];
    }

    const T &operator*() const
    {
      return this->ptr->v[this->n];
    }

    template<typename> friend class Ulist;
  };

  // List interface
  Ulist(int max_elem)
  {
    this->max_elem = max_elem;
    this->head = nullptr;
    this->tail = nullptr;
  }

  Ulist<T> &operator=(const Ulist<T> &other)
  {
    this->clear();

    /* no nodes exist */
    if (other.head == nullptr) {
      assert(other.tail == nullptr);
      return *this;
    }
    /* single node exists */
    if (other.head == other.tail) {
      this->head = new Node<T>(other.max_elem);
      this->tail = this->head;
      this->max_elem = other.max_elem;
      *this->head = *other.head;
      this->head->next = nullptr;
      this->head->prev = nullptr;
      return *this;
    }
    /* multiple nodes exist */
    this->max_elem = other.max_elem;
    auto *curr = new Node<T>(other.max_elem);
    Node<T> *prev = nullptr;
    auto *other_curr = other.head;
    this->head = curr;
    while (true) {
      *curr = *other_curr; /* set contents*/
      curr->prev = prev;   /* make prev link */
      if (prev) {
        prev->next = curr; /* make next link */
      }

      if (other_curr == other.tail) {
        if (prev) {
          prev->next = curr; /* make next link */
        }
        break;
      }

      prev = curr;

      other_curr = other_curr->next;
      curr = new Node<T>(other.max_elem);
    }
    this->tail = curr;
    assert(this->tail->next == nullptr);

    return *this;
  }

  ~Ulist()
  {
    this->clear();
    assert(this->head == nullptr && this->tail == nullptr);
  }

  void push_back(T data)
  {
    if (this->head == nullptr) {
      assert(this->tail == nullptr);
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

  void pop_back()
  {
    if (this->head) {
      assert(this->tail);
      /* TODO: this if case may never occur, verify this */
      if (this->tail->totelem == 0) {
        return;
      }
      (this->tail->totelem)--;
      if (this->tail->totelem == 0) {
        Node<T> *garbage = this->tail;
        this->tail = this->tail->prev;
        if (this->tail) {
          this->tail->next = nullptr;
        }
        else {
          /* Only one node existed and now even that is removed */
          /* since tail is pointing to null now, head should also now
           * point to null */
          this->head = nullptr;
        }
        delete garbage;
      }
    }
    else {
      assert(this->tail == nullptr);
    }
  }

  void push_front(T data)
  {
    if (this->head == nullptr) {
      assert(this->tail == nullptr);
      this->head = new Node<T>(this->max_elem);
      this->head->v[0] = data;
      (this->head->totelem)++;
      this->tail = this->head;
    }
    else {
      if (this->head->totelem == this->max_elem) {
        Node<T> *newNode = new Node<T>(this->max_elem);
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

  void pop_front()
  {
    if (this->head) {
      /* TODO: this if case may never occur, verify this */
      if (this->tail->totelem == 0) {
        return;
      }
      for (int i = 0; i < (this->head->totelem) - 1; i++) {
        this->head->v[i] = this->head->v[i + 1];
      }
      (this->head->totelem)--;
      if (this->head->totelem == 0) {
        Node<T> *garbage = this->head;
        this->head = this->head->next;
        if (this->head) {
          this->head->prev = nullptr;
        }
        else {
          this->tail = nullptr;
        }
        delete garbage;
      }
    }
    else {
      assert(this->tail == nullptr);
    }
  }

  T &front()
  {
    assert(this->head != nullptr);
    return this->head->v[0];
  }

  const T &front() const
  {
    assert(this->head != nullptr);
    return this->head->v[0];
  }

  T &back()
  {
    assert(this->tail != nullptr);
    return this->tail->v[this->tail->totelem - 1];
  }

  const T &back() const
  {
    assert(this->tail != nullptr);
    return this->tail->v[this->tail->totelem - 1];
  }

  size_t size() const
  {
    Node<T> *temp = this->head;
    size_t count = 0;
    while (temp) {
      count += temp->totelem;
      temp = temp->next;
    }
    return count;
  }

  bool empty() const
  {
    if (this->size()) {
      return false;
    }
    return true;
  }

  void insert(const Iterator &it, const T &data)
  {
    if (it.ptr == nullptr) {
      this->push_back(data);
      return;
    }
    int max_elem = this->max_elem;
    if (it.n == 0) {
      /* There is space in previous node to insert data */
      if (it.ptr->prev) {
        int prev_totelem = it.ptr->prev->totelem;
        if (prev_totelem - 1 < max_elem - 1) {
          it.ptr->prev->v[it.ptr->prev->totelem] = data;
          ++(it.ptr->prev->totelem);
          return;
        }
      }

      /* Needs new node between previous and current */
      auto *temp = new Node<T>(this->max_elem);
      temp->v[0] = data;
      temp->totelem = 1;
      auto *curr = it.ptr;
      auto *prev = curr->prev;
      temp->next = curr;
      temp->prev = prev;
      curr->prev = temp;
      if (prev) {
        prev->next = temp;
      }
      else {
        this->head = temp;
      }
    }
    /* There is space in the current node */
    else if (it.ptr->totelem - 1 < max_elem - 1) {
      auto it_n = it.ptr->v.begin();
      advance(it_n, it.n);
      it.ptr->v.insert(it_n, data);
      ++(it.ptr->totelem);
    }
    /* No space in current node, and n != 0 */
    /* 1, 2, 3 | _, _, _ */
    /* 1, 2, x | 3, _, _ */
    else if (it.ptr->totelem - 1 == max_elem - 1) {
      /* inserting temp between curr and next */
      auto *next = it.ptr->next;
      auto *curr = it.ptr;
      auto *temp = new Node<T>(this->max_elem);
      /**
       * suppose 1, 2, 3 | 4, _, _ |
       * adding x before 2 to make
       * 1, x, 2 | 3, _, _ | 4, _, _ |
       **/
      temp->v[0] = curr->v[curr->totelem - 1];
      for (int i = curr->totelem - 1; i > it.n; i--) {
        curr->v[i] = curr->v[i - 1];
      }
      curr->v[it.n] = data;
      temp->totelem = 1;
      temp->prev = it.ptr;
      temp->next = next;
      curr->next = temp;
      if (next) {
        next->prev = temp;
      }
      else {
        this->tail = temp;
      }
    }
  }

  void erase(const Iterator &it)
  {
    assert(it.ptr);
    assert(it.head == this->head);
    assert(it.tail == this->tail);
    assert(it.n >= 0 && it.n < it.ptr->totelem);

    /* single node, single element */
    if (it.head == it.tail) {
      if (it.n == 0 && it.ptr->totelem == 1) {
        delete this->head;
        this->head = nullptr;
        this->tail = nullptr;
        return;
      }
    }
    /* single element in node */
    if (it.ptr->totelem == 1) {
      auto *prev = it.ptr->prev;
      auto *next = it.ptr->next;
      auto *curr = it.ptr;
      if (prev) {
        prev->next = next;
      }
      if (next) {
        next->prev = prev;
      }
      if (curr == it.head) {
        this->head = this->head->next;
      }
      if (curr == it.tail) {
        this->tail = this->tail->prev;
      }
      delete curr;
      return;
    }
    /* multiple elements in node */
    assert(it.ptr->totelem > 1);
    for (int i = it.n; i < (it.ptr->totelem) - 1; i++) {
      it.ptr->v[i] = it.ptr->v[i + 1];
    }
    (it.ptr->totelem)--;
  }

  void erase(const Iterator &first, const Iterator &last)
  {
    assert(first.ptr);
    assert(first.head == last.head);
    assert(first.tail == last.tail);
    assert(first.head == this->head);
    assert(first.tail == this->tail);

    auto one_before_first = first;
    one_before_first--;
    auto it = first;
    while (it != last) {
      this->erase(it);
      it = one_before_first;
      auto *updated_head = this->head;
      it.head = updated_head;
      it++;
      if (it.ptr == last.ptr) {
        assert(it.n == 0);
        for (int i = last.n; i > 0; i--) {
          it.ptr->v[i - 1] = it.ptr->v[i];
          (last.ptr->totelem)--;
        }

        break;
      }
    }
  }

  void clear()
  {
    if (this->head == nullptr) {
      assert(this->tail == nullptr);
      return;
    }

    auto *node = this->head;
    while (node != nullptr) {
      auto *temp = node;
      node = node->next;
      delete temp;
    }
    this->head = nullptr;
    this->tail = nullptr;
  }

  void display()
  {
    Node<T> *temp = this->head;
    cout << "[";
    while (temp) {
      for (size_t i = 0; i < temp->totelem; i++) {
        cout << temp->v[i] << " ";
      }
      cout << "|";
      temp = temp->next;
    }
    cout << "]" << endl;
  }

  void display_reverse()
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

  // Iterator interface
  Iterator begin()
  {
    return Iterator(this->head, this->tail, this->head, 0);
  }

  const Iterator cbegin() const
  {
    return Iterator(this->head, this->tail, this->head, 0);
  }

  Iterator end()
  {
    return Iterator(nullptr, this->tail, this->head, 0);
  }

  const Iterator cend() const
  {
    return Iterator(nullptr, this->tail, this->head, 0);
  }
};

#endif
