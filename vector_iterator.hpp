#pragma once

#include <cstddef>
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
  vector_iterator(vector_iterator const &copy){};

  vector_iterator &operator=(vector_iterator const &rhs){};

  value_type operator*(void) { return *_cursor; }

private:
  T *_cursor;
};
} // namespace ft
