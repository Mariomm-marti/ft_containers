#ifndef FT_CONTAINERS_VECTOR_HPP_
#define FT_CONTAINERS_VECTOR_HPP_
#pragma once

#include "enable_if.hpp"
#include "is_integral.hpp"
#include "reverse_iterator.hpp"
#include "vector_iterator.hpp"
#include <iostream>
#include <iterator>
#include <memory>
#include <stdexcept>

namespace ft {
template <class T, class Allocator = std::allocator<T> > class vector {
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
  explicit vector(size_type n, value_type const &val = value_type(),
                  allocator_type const &alloc = allocator_type())
      : _vector(NULL), _allocator(alloc), _size(0), _capacity(0) {
    assign(n, val);
  }
  template <class InputIterator>
  vector(typename ft::enable_if<!ft::is_integral<InputIterator>::value,
                                InputIterator>::type first,
         InputIterator last, allocator_type const &alloc = allocator_type())
      : _vector(NULL), _allocator(alloc), _size(0), _capacity(0) {
    assign(first, last);
  }
  vector(vector const &x) { assign(x.begin(), x.end()); }
  virtual ~vector(void) {
    for (size_type i = 0; i < _size; i++)
      _allocator.destroy(_vector + i);
    _allocator.deallocate(_vector, _capacity);
  }
  vector &operator=(vector const &x) {
    clear();
    assign(x.begin(), x.end());
    return *this;
  }

  /*
   * iterators
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

  /*
   * capacity
   */
  size_type size(void) const { return _size; }
  size_type max_size(void) const { return _allocator.max_size(); }
  void resize(size_type n, value_type val = value_type()) {
    if (n < _size)
      erase(begin() + n, end());
    else
      insert(end(), n, val);
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
      *(tmp + i) = *(_vector + i);
    if (_vector)
      _allocator.deallocate(_vector, _capacity);
    _capacity = n;
    _vector = tmp;
  }

  /*
   * element access
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

  /*
   * modifiers
   */
  template <class InputIterator>
  void assign(typename ft::enable_if<!ft::is_integral<InputIterator>::value,
                                     InputIterator>::type first,
              InputIterator last) {
    size_type operation_length = std::distance(first, last);

    clear();
    reserve(operation_length);
    _size = operation_length;
    for (size_type i = 0; i < _size; i++, first++)
      _allocator.construct(_vector + i, *first);
  }
  void assign(size_type n, value_type const &val) {
    clear();
    reserve(n);
    _size = n;
    for (size_type i = 0; i < _size; i++)
      _allocator.construct(_vector + i, val);
  }
  void push_back(value_type const &val) { insert(end(), val); }
  void pop_back(void) { erase(end() - 1); }
  iterator insert(iterator position, value_type const &val) {
    size_type idx = position.base() - _vector;

    if (_size + 1 > _capacity)
      reserve(_capacity * 2);
    size_type i = idx;
    while (i < _size) {
      *(_vector + i + 1) = *(_vector + i);
      i++;
    }
    _allocator.construct(_vector + idx, val);
    _size++;
    return iterator(_vector + idx);
  }
  void insert(iterator position, size_type n, value_type const &val) {
    difference_type idx = position.base() - _vector;

    if (_size + n > _capacity && _capacity * 2 < n)
      reserve(_size + n);
    for (size_type i = 0; i < n; i++)
      insert(_vector + idx + i, val);
  }
  template <class InputIterator>
  void insert(iterator position,
              typename ft::enable_if<!ft::is_integral<InputIterator>::value,
                                     InputIterator>::type first,
              InputIterator last) {
    difference_type idx = position.base() - _vector;

    for (; first < last; first++, idx++)
      insert(_vector + idx, *first);
  }
  iterator erase(iterator position) {
    _allocator.destroy(*position);
    for (iterator it = position; it + 1 != end(); it++)
      *it = *(it + 1);
    _size = _size - 1;
    return position;
  }
  iterator erase(iterator first, iterator last) {
    for (iterator it = first; it < last; it++)
      _allocator.destroy(*it);
    _size = _size - (last - first);
    iterator itptr = first;
    for (iterator it = last; it < end(); it++, itptr++)
      *itptr = *it;
    return first;
  }
  void swap(vector &x) {
    pointer tmp_inner_structure;
    size_type tmp_size;
    size_type tmp_capacity;

    tmp_inner_structure = x._vector;
    x._vector = _vector;
    _vector = tmp_inner_structure;
    tmp_size = x._size;
    x._size = _size;
    _size = tmp_size;
    tmp_capacity = x._capacity;
    x._capacity = _capacity;
    _capacity = tmp_capacity;
  }
  void clear(void) {
    for (size_type i = 0; i < _size; i++)
      _allocator.destroy(_vector + i);
    _size = 0;
  }

  /*
   * allocator
   */
  allocator_type get_allocator(void) const { return _allocator; }
};
}; // namespace ft
#endif
