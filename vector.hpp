#ifndef FT_CONTAINERS_VECTOR_HPP_
#define FT_CONTAINERS_VECTOR_HPP_
#include <stdexcept>
#pragma once

#include "enable_if.hpp"
#include "is_integral.hpp"
#include "reverse_iterator.hpp"
#include "vector_iterator.hpp"
#include <iterator>
#include <memory>

namespace ft {
template <class T, class Allocator = std::allocator<T>> class vector {
public:
  typedef T value_type;
  typedef Allocator allocator_type;
  typedef typename allocator_type::reference &reference;
  typedef typename allocator_type::const_reference const &const_reference;
  typedef typename allocator_type::pointer pointer;
  typedef typename allocator_type::const_pointer const_pointer;
  typedef ft::vector_iterator<value_type> iterator;
  typedef ft::vector_iterator<value_type const> const_iterator;
  typedef ft::reverse_iterator<iterator> reverse_iterator;
  typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
  typedef std::ptrdiff_t difference_type;
  typedef std::size_t size_type;

private:
  pointer _vector;
  allocator_type _allocator;
  size_type _size;
  size_type _capacity;

public:
  /*
   * constructor
   */
  explicit vector(allocator_type const &alloc = allocator_type())
      : _vector(NULL), _allocator(alloc), _size(0), _capacity(0) {}
  // > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > >
  // > > > > > > > > > > > > > > > > > > > > > > > explicit vector(size_type n,
  // value_type const &val = value_type(),
  //                allocator_type const &alloc = allocator_type())
  //   : _allocator(alloc), _size(n), _capacity(n) {}

  /*
   * iterators [FINISHED]
   */
  iterator begin(void) { return iterator(_vector); }
  const_iterator begin(void) const { return const_iterator(_vector); }
  iterator end(void) { return iterator(_vector + _size); }
  const_iterator end(void) const { return const_iterator(_vector + _size); }
  reverse_iterator rbegin(void) {
    return reverse_iterator(_vector + _size - 1);
  }
  const_reverse_iterator rbegin(void) const {
    return const_reverse_iterator(_vector + _size - 1);
  }
  reverse_iterator rend(void) { return reverse_iterator(_vector - 1); }
  const_reverse_iterator rend(void) const {
    return const_reverse_iterator(_vector - 1);
  }
  const_iterator cbegin(void) const { return const_iterator(_vector); }
  const_iterator cend(void) const { return const_iterator(_vector + _size); }
  const_reverse_iterator crbegin(void) const {
    return const_reverse_iterator(_vector + _size - 1);
  }
  const_reverse_iterator crend(void) const {
    return const_reverse_iterator(_vector - 1);
  }

  /*
   * capacity
   */
  size_type size(void) const { return _size; }
  size_type max_size(void) const { return _allocator.max_size(); }
  void resize(size_type n, value_type val = value_type()) {
    if (n < _size)
      ;
    if (n > _capacity)
      ; // resize and move with check of capacity * 2 < n
    if (n > _size)
      ; // move elements
  }
  size_type capacity(void) const { return _capacity; }
  bool empty(void) const { return _size == 0; }
  void reserve(size_type n) {
    pointer tmp;

    if (n <= _capacity)
      return;
    if (n > max_size())
      throw std::length_error("attempting to reserve larger than max_size");
    tmp = _allocator.allocate(n);
    for (size_type i = 0; i < _size; i++)
  }

  /*
   * element access [FINISHED]
   */
  reference operator[](size_type n) { return *(_vector + n); }
  const_reference operator[](size_type n) const { return *(_vector + n); }
  reference at(size_type n) {
    if (n >= _size)
      throw std::out_of_range("accessing element out of range");
    return *(_vector + n);
  }
  const_reference at(size_type n) const {
    if (n >= _size)
      throw std::out_of_range("accessing element out of range");
    return *(_vector + n);
  }
  reference front(void) { return *_vector; }
  const_reference front(void) const { return *_vector; }
  reference back(void) { return *(_vector + _size - 1); }
  const_reference back(void) const { return *(_vector + _size - 1); }
  pointer data(void) { return _vector; }
  const_pointer data(void) const { return _vector; }

  /*
   * modifiers
   */
  // > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > >
  // > > > > > > > > > > > > > > > > > > > > > > >
  template <class InputIterator>
  void assign(InputIterator first, InputIterator last) {}

  /*
   * allocator [FINISHED]
   */
  allocator_type get_allocator(void) const { return _allocator; }
};
}; // namespace ft
#endif
