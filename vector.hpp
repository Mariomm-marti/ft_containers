#pragma once
#include "vector_iterator.hpp"
#ifndef FT_CONTAINERS_VECTOR_HPP_
#define FT_CONTAINERS_VECTOR_HPP_

#include <algorithm>
#include <iostream> // TODO REMOVE
#include <iterator>
#include <memory>

namespace ft {
template <class T, class Allocator = std::allocator<T> > class vector {
public:
  typedef T value_type;
  typedef Allocator allocator_type;
  typedef typename allocator_type::reference &reference;
  typedef typename allocator_type::const_reference const &const_reference;
  typedef typename allocator_type::pointer const *pointer;
  typedef typename allocator_type::const_pointer const *const_pointer;
  typedef vector_iterator<value_type> *iterator; // TODO Replace with iterator
  typedef vector_iterator<value_type> const *const_iterator;
  typedef std::reverse_iterator<iterator> reverse_iterator;
  typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
  typedef std::ptrdiff_t difference_type;
  typedef std::size_t size_type;

private:
  T *_vector;
  allocator_type _allocator;
  size_type _size;
  size_type _capacity;

public:
  // explicit vector(allocator_type const &alloc = allocator_type())
  //     : _vector(NULL), _allocator(alloc), _size(0), _capacity(0){};
  // explicit vector(size_type n, value_type const &val = value_type(),
  //                 allocator_type const &alloc = allocator_type())
  //     : _allocator(alloc), _size(n), _capacity(n){_allocator.};
  explicit vector() {
    _vector = new int[10];
    _vector[0] = 42;
    std::cout << _vector[0] << std::endl;
  }

  vector_iterator<T> begin(void) const { return vector_iterator<T>(_vector); }

  size_type max_size() const { return _allocator.max_size(); }
}; // template vector
} // namespace ft

#endif
