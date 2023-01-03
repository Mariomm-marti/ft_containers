#ifndef FT_CONTAINERS_VECTOR_HPP_
#define FT_CONTAINERS_VECTOR_HPP_
#include "enable_if.hpp"
#include "is_integral.hpp"
#include <iostream> // TODO Remove
#include <iterator>
#pragma once

#include "vector_iterator.hpp"
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
  // TODO Add reverse iterator based on the vector_iterator, std::enable_if
  // TODO Add const reverse iterator
  typedef std::ptrdiff_t difference_type;
  typedef std::size_t size_type;

private:
  pointer _vector;
  allocator_type _allocator;
  size_type _size;
  size_type _capacity;

public:
  /*
  ** initialisators
  */
  explicit vector(allocator_type const &alloc = allocator_type())
      : _vector(NULL), _allocator(alloc), _size(0), _capacity(0){};
  explicit vector(size_type n, value_type const &val = value_type(),
                  allocator_type const &alloc = allocator_type())
      : _allocator(alloc), _size(n), _capacity(n) {
    _vector = _allocator.allocate(_capacity);
    for (size_type i = 0; i < _size; i++)
      _allocator.construct(_vector + i, val);
  };
  template <class InputIterator>
  vector(InputIterator first, InputIterator last,
         allocator_type const &alloc = allocator_type(),
         typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type
             * = 0)
      : _allocator(alloc), _size(std::distance(first, last)),
        _capacity(std::distance(first, last)) {
    _vector = _allocator.allocate(_size);
    for (size_type i = 0; first < last; first++, i++)
      _allocator.construct(_vector + i, *first);
  };
  vector(vector const &copy)
      : _allocator(allocator_type(copy.get_allocator())), _size(copy.size()),
        _capacity(copy.capacity()) {
    const_iterator begin = copy.cbegin();
    const_iterator end = copy.cend();

    _vector = _allocator.allocate(_capacity);
    for (size_type i = 0; begin < end; begin++, i++)
      _allocator.construct(_vector + i, value_type(*begin));
  };
  ~vector(void) {
    if (_capacity == 0 || !_vector)
      return;
    const_iterator begin = cbegin();
    const_iterator end = cend();

    std::cout << "bye bye" << std::endl;
    for (size_type i = 0; begin < end; begin++, i++)
      _allocator.destroy(_vector + i);
    _allocator.deallocate(_vector, _capacity);
  };

  vector &operator=(vector const &x) {
    const_iterator begin = x.cbegin();
    const_iterator end = x.cend();

    if ()
      _allocator = allocator_type(x.get_allocator());
    _size = x.size();
    _capacity = x.capacity();

    _vector = _allocator.allocate(_capacity);
    for (size_type i = 0; begin < end; begin++, i++)
      _allocator.construct(_vector + i, value_type(*begin));
    return *this;
  };

  /*
  ** iterators
  */
  iterator begin(void) {
    if (_vector == NULL)
      return NULL;
    return iterator(_vector);
  };
  const_iterator begin(void) const {
    if (_vector == NULL)
      return NULL;
    return const_iterator(_vector);
  };

  iterator end(void) {
    if (_vector == NULL)
      return NULL;
    return iterator(_vector + _size);
  };
  const_iterator end(void) const {
    if (_vector == NULL)
      return NULL;
    return const_iterator(_vector + _size);
  };

  const_iterator cbegin(void) const {
    if (_vector == NULL)
      return NULL;
    return const_iterator(_vector);
  };
  const_iterator cend(void) const {
    if (_vector == NULL)
      return NULL;
    return const_iterator(_vector + _size);
  };

  /*
  ** capacity
  */
  size_type size(void) const { return _size; };
  size_type max_size(void) const { return _allocator.max_size(); };
  void resize(size_type n, value_type val = value_type()) {
    (void)n;
    (void)val;
  };
  size_type capacity(void) const { return _capacity; };

  /*
  ** allocator
  */
  allocator_type get_allocator(void) const { return _allocator; };
}; // template vector
} // namespace ft
#endif
