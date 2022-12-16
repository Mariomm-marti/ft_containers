#pragma once
#ifndef FT_CONTAINERS_VECTOR_HPP_
#define FT_CONTAINERS_VECTOR_HPP_

#include <algorithm>
#include <iterator>
#include <memory>

namespace ft {
template <class T, class Allocator = std::allocator<T>> class vector {
private:
  typedef T value_type;
  typedef Allocator allocator_type;
  typedef std::size_t size_type;
  typedef std::ptrdiff_t difference_type;
  typedef typename allocator_type::reference &reference;
  typedef typename allocator_type::const_reference const &const_reference;
  typedef typename allocator_type::pointer pointer;
  typedef typename allocator_type::const_pointer const_pointer;
  typedef typename Allocator::iterator iterator; // TODO Replace with iterator
  typedef typename Allocator::const_pointer const_iterator;
  typedef std::reverse_iterator<iterator> reverse_iterator;
  typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

  T *_vector;
  allocator_type _allocator;
  size_type _size;
  size_type _capacity;

public:
  explicit vector(allocator_type const &alloc = allocator_type())
      : _vector(NULL), _allocator(alloc), _size(0), _capacity(0){};
  explicit vector(size_type n, value_type const &val = value_type(),
                  allocator_type const &alloc = allocator_type())
      : _allocator(alloc)
}; // template vector
} // namespace ft

#endif
