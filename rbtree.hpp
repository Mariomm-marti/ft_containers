#ifndef FT_CONTAINERS_RBTREE_HPP_
#define FT_CONTAINERS_RBTREE_HPP_
#pragma once

#include "rbtree_iterator.hpp"
#include "reverse_iterator.hpp"
#include <functional>

namespace ft {
template <class T, class Compare = std::less<T>,
          class Alloc = std::allocator<ft::rbtree_node<T, Compare>>>
class btree {
public:
  typedef T value_type;
  typedef Compare value_compare;
  typedef Alloc allocator_type;
  typedef typename allocator_type::reference &reference;
  typedef typename allocator_type::const_reference const &const_reference;
  typedef typename allocator_type::pointer pointer;
  typedef typename allocator_type::const_pointer const_pointer;
  typedef ft::rbtree_iterator<value_type, value_compare> iterator;
  typedef ft::rbtree_iterator<value_type const, value_compare> const_iterator;
  typedef ft::reverse_iterator<iterator> reverse_iterator;
  typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
  typedef std::ptrdiff_t difference_type;
  typedef std::size_t size_type;

  iterator begin(void) { return rbtree_iterator<T, Compare>(_root).begin(); };
  const_iterator begin(void) const {
    return rbtree_iterator<T, Compare>(_root).begin();
  };

private:
  pointer _root;
};
}; // namespace ft

#endif
