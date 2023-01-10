#ifndef FT_CONTAINERS_MAP_HPP_
#define FT_CONTAINERS_MAP_HPP_
#pragma once

#include "pair.hpp"
#include <cstddef>
#include <functional>
#include <memory>

namespace ft {
template <class Key, class T, class Compare = std::less<Key>,
          class Alloc = std::allocator<ft::pair<Key const, T> > >
class map {
public:
  typedef Key key_type;
  typedef T mapped_type;
  typedef ft::pair<key_type const, mapped_type> value_type;
  typedef Compare key_compare;
  // TODO value_compare
  typedef Alloc allocator_type;
  typedef typename allocator_type::reference reference;
  typedef typename allocator_type::const_reference const_reference;
  typedef typename allocator_type::pointer pointer;
  typedef typename allocator_type::const_pointer const_pointer;
  // TODO iterator
  // TODO const_iterator
  // TODO reverse_iterator
  // TODO const_reverse_iterator
  // TODO difference_type
  typedef std::size_t size_type;

private:
public:
};
}; // namespace ft

#endif
