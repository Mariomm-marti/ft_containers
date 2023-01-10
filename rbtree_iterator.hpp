#ifndef FT_CONTAINERS_RBTREE_ITERATOR_HPP_
#define FT_CONTAINERS_RBTREE_ITERATOR_HPP_
#include "iterator_traits.hpp"
#include "rbtree.hpp"
#include <functional>
#include <iterator>
#pragma once

namespace ft {
template <class Key, class T, class Compare = std::less<T> >
struct rbtree_iterator {
  typedef rbtree_node<Key, T, Compare> node;
  typedef typename std::bidirectional_iterator_tag iterator_category;
  typedef typename ft::iterator_traits<node *>::value_type value_type;
  typedef typename ft::iterator_traits<node *>::difference_type difference_type;
  typedef typename ft::iterator_traits<node *>::pointer pointer;
  typedef typename ft::iterator_traits<node *>::reference reference;

  rbtree_iterator(void) : _cursor(NULL){};
  rbtree_iterator(pointer const x) : _cursor(x){};
  template <CopyIterator>
  rbtree_iteartor()

      private : pointer _cursor;
};
}; // namespace ft

#endif
