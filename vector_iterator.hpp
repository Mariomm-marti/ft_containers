#ifndef FT_CONTAINERS_VECTOR_ITERATOR_HPP_
#define FT_CONTAINERS_VECTOR_ITERATOR_HPP_
#pragma once

#include <iterator>

namespace ft {
template <class T> struct vector_iterator {
  typedef std::random_access_iterator_tag iterator_category;
  typedef T value_type;
  typedef std::ptrdiff_t difference_type;
  typedef T *pointer;
  typedef T &reference;

  vector_iterator(void) : _cursor(NULL){};
  vector_iterator(value_type *const test) : _cursor(test){};
  template <class CopyIterator> vector_iterator(CopyIterator const &copy) {
    _cursor = copy.get_cursor();
  };
  vector_iterator(vector_iterator const &copy) { _cursor = copy._cursor; };

  vector_iterator &operator=(vector_iterator const &rhs) {
    _cursor = rhs.get_cursor();
    return *this;
  }

  bool operator==(vector_iterator const &rhs) const {
    return _cursor == (rhs.get_cursor());
  }
  bool operator!=(vector_iterator const &rhs) const {
    return _cursor != (rhs.get_cursor());
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

  vector_iterator operator--(void) {
    _cursor = _cursor - 1;
    return *this;
  }

  vector_iterator operator--(int) {
    vector_iterator old = *this;
    operator--();
    return old;
  }

  vector_iterator operator+(int const diff) { return _cursor + diff; }
  vector_iterator operator-(int const diff) { return _cursor - diff; }

  bool operator<(vector_iterator const &rhs) const {
    return _cursor < (rhs.get_cursor());
  }

  bool operator>(vector_iterator const &rhs) const {
    return _cursor > (rhs.get_cursor());
  }

  bool operator<=(vector_iterator const &rhs) const {
    return _cursor <= (rhs.get_cursor());
  }

  bool operator>=(vector_iterator const &rhs) const {
    return _cursor >= (rhs.get_cursor());
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

  pointer const get_cursor(void) const { return _cursor; }

private:
  pointer _cursor;
};
} // namespace ft
#endif
