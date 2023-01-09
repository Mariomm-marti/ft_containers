#ifndef FT_CONTAINERS_STACK_HPP_
#define FT_CONTAINERS_STACK_HPP_
#pragma once

#include "vector.hpp"

namespace ft {
template <class T, class Container = ft::vector<T>> class stack {
public:
  typedef T value_type;
  typedef Container container_type;
  typedef std::size_t size_type;

private:
  container_type _container;

public:
  explicit stack(container_type const &ctnr = container_type())
      : _container(ctnr){};

  template <class Type, class C>
  friend bool operator==(stack<Type, C> const &x, stack<Type, C> const &y);
  template <class Type, class C>
  friend bool operator<(stack<Type, C> const &x, stack<Type, C> const &y);

  bool empty(void) const { return _container.empty(); };
  size_type size(void) const { return _container.size(); };
  value_type &top(void) { return _container.back(); };
  value_type const &top(void) const { return _container.back(); };
  void push(value_type const &val) { _container.push_back(val); };
  void pop(void) { _container.pop_back(); };
};

template <class T, class Container>
bool operator==(stack<T, Container> const &x, stack<T, Container> const &y) {
  return x._container == y._container;
}

template <class T, class Container>
bool operator!=(stack<T, Container> const &x, stack<T, Container> const &y) {
  return !(x == y);
}

template <class T, class Container>
bool operator<(stack<T, Container> const &x, stack<T, Container> const &y) {
  return x._container < y._container;
}

template <class T, class Container>
bool operator>(stack<T, Container> const &x, stack<T, Container> const &y) {
  return y < x;
}

template <class T, class Container>
bool operator<=(stack<T, Container> const &x, stack<T, Container> const &y) {
  return !(y < x);
}

template <class T, class Container>
bool operator>=(stack<T, Container> const &x, stack<T, Container> const &y) {
  return !(x < y);
}
}; // namespace ft

#endif
