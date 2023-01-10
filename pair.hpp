#ifndef FT_CONTAINERS_PAIR_HPP_
#define FT_CONTAINERS_PAIR_HPP_
#pragma once

namespace ft {
template <class T1, class T2> struct pair {
  typedef T1 first_type;
  typedef T2 second_type;

  first_type first;
  second_type second;

  pair(void) : first(), second() {}
  template <class U, class V>
  pair(pair<U, V> const &pr) : first(pr.first), second(pr.second) {}
  pair(first_type const &a, second_type const &b) : first(a), second(b) {}

  template <class U, class V> pair &operator=(pair<U, V> const &pr) {
    first = pr.first;
    second = pr.second;
    return *this;
  }
};

template <class T1, class T2>
bool operator==(pair<T1, T2> const &lhs, pair<T1, T2> const &rhs) {
  return lhs.first == rhs.first && lhs.second == rhs.second;
}

template <class T1, class T2>
bool operator!=(pair<T1, T2> const &lhs, pair<T1, T2> const &rhs) {
  return !operator==(lhs, rhs);
}

template <class T1, class T2>
bool operator<(pair<T1, T2> const &lhs, pair<T1, T2> const &rhs) {
  return lhs.first < rhs.first ||
         (!(rhs.first < lhs.first) && lhs.second < rhs.second);
}

template <class T1, class T2>
bool operator<=(pair<T1, T2> const &lhs, pair<T1, T2> const &rhs) {
  return !operator<(rhs, lhs);
}

template <class T1, class T2>
bool operator>(pair<T1, T2> const &lhs, pair<T1, T2> const &rhs) {
  return operator<(rhs, lhs);
}

template <class T1, class T2>
bool operator>=(pair<T1, T2> const &lhs, pair<T1, T2> const &rhs) {
  return !(lhs < rhs);
}
}; // namespace ft

#endif
