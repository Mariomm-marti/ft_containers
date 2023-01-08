#ifndef FT_CONTAINERS_VECTOR_ITERATOR_HPP_
#define FT_CONTAINERS_VECTOR_ITERATOR_HPP_
#pragma once

#include "iterator_traits.hpp"
#include <iterator>

namespace ft {
template <class T> struct vector_iterator {
  typedef
      typename ft::iterator_traits<T *>::iterator_category iterator_category;
  typedef typename ft::iterator_traits<T *>::value_type value_type;
  typedef typename ft::iterator_traits<T *>::difference_type difference_type;
  typedef typename ft::iterator_traits<T *>::pointer pointer;
  typedef typename ft::iterator_traits<T *>::reference reference;

  vector_iterator(void) : _cursor(NULL){};
  vector_iterator(pointer const test) : _cursor(test){};
  template <class CopyIterator>
  vector_iterator(vector_iterator<CopyIterator> const &copy) {
    _cursor = copy.base();
  };
  vector_iterator(vector_iterator const &copy) { _cursor = copy._cursor; };

  template <class Iter>
  vector_iterator &operator=(vector_iterator<Iter> const &rhs) {
    _cursor = rhs.base();
    return *this;
  }

  template <class Iter>
  bool operator==(vector_iterator<Iter> const &rhs) const {
    return _cursor == rhs.base();
  }
  template <class Iter>
  bool operator!=(vector_iterator<Iter> const &rhs) const {
    return _cursor != rhs.base();
  }

  reference operator*(void) { return *_cursor; }
  pointer operator->(void) { return _cursor; }

  vector_iterator operator++(void) {
    _cursor = _cursor + 1;
    return *this;
  }

  vector_iterator operator++(int) {
    vector_iterator old = *this;
    operator++();
    return old;
  }

  vector_iterator &operator--(void) {
    _cursor = _cursor - 1;
    return *this;
  }

  vector_iterator operator--(int) {
    vector_iterator old = *this;
    operator--();
    return old;
  }

  vector_iterator operator+(int const diff) const { return _cursor + diff; }
  template <class Iter>
  difference_type operator+(vector_iterator<Iter> const diff) const {
    return _cursor + diff.base();
  }
  vector_iterator operator-(int const diff) const { return _cursor - diff; }
  template <class Iter>
  difference_type operator-(vector_iterator<Iter> const diff) const {
    return _cursor - diff.base();
  }

  template <class Iter> bool operator<(vector_iterator<Iter> const &rhs) const {
    return _cursor < rhs.base();
  }

  template <class Iter> bool operator>(vector_iterator<Iter> const &rhs) const {
    return _cursor > rhs.base();
  }

  template <class Iter>
  bool operator<=(vector_iterator<Iter> const &rhs) const {
    return _cursor <= rhs.base();
  }

  template <class Iter>
  bool operator>=(vector_iterator<Iter> const &rhs) const {
    return _cursor >= rhs.base();
  }

  vector_iterator &operator+=(int const rhs) {
    _cursor += rhs;
    return *this;
  }

  vector_iterator &operator-=(int const rhs) {
    _cursor -= rhs;
    return *this;
  }

  reference operator[](std::size_t const idx) const { return *(_cursor + idx); }

  pointer const base(void) const { return _cursor; }

private:
  pointer _cursor;
};

template <class T>
vector_iterator<T>
operator+(typename vector_iterator<T>::difference_type const n,
          vector_iterator<T> const &rhs) {
  return vector_iterator<T>(rhs.base() + n);
}
} // namespace ft
#endif
