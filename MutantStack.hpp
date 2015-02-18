#ifndef MUTANTSTACK_H
#define MUTANTSTACK_H

#include <iostream>
#include <stack>
#include <iterator>

template<class T>
class MutantStack : public std::stack<T> {
public:
  MutantStack() : std::stack<T>() {}

  class iterator : public std::iterator<std::input_iterator_tag, T> {
  public:
    T* p;
    iterator(T* x) :p(x) {}
    iterator(const iterator& mit) : p(mit.p) {}
    iterator& operator++() {++p;return *this;}
    iterator operator++(int) {iterator tmp(*this); operator++(); return tmp;}
    iterator& operator--() {--p;return *this;}
    iterator operator--(int) {iterator tmp(*this); operator--(); return tmp;}
    bool operator==(const iterator& rhs) {return p==rhs.p;}
    bool operator!=(const iterator& rhs) {return p!=rhs.p;}
    T& operator*() {return *p;}
  };
  iterator begin() {
    iterator it(&std::stack<T>::c[0]);
    return it;
  }
  iterator end() {
    iterator it(&std::stack<T>::c[std::stack<T>::c.size()]);
    return it;
  }
};

#endif
