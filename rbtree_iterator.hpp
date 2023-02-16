#ifndef FT_CONTAINERS_RBTREE_ITERATOR_HPP_
#define FT_CONTAINERS_RBTREE_ITERATOR_HPP_
#pragma once

#include "rbtree_node.hpp"
#include <cstddef>
#include <functional>
#include <iterator>

namespace ft {
template <class T, class Compare = std::less<T>> struct rbtree_iterator {
  typedef std::bidirectional_iterator_tag iterator_category;
  typedef ft::rbtree_node<T, Compare> value_type;
  typedef std::ptrdiff_t difference_type;
  typedef value_type *pointer;
  typedef value_type &reference;

  rbtree_iterator(void) : _cursor(NULL){};
  rbtree_iterator(pointer const x) : _cursor(x){};
  template <class CopyIterator>
  rbtree_iterator(rbtree_iterator<CopyIterator> const &x) : _cursor(x.base()){};
  rbtree_iterator(rbtree_iterator const &x) : _cursor(x.base()){};

  template <class Iter>
  rbtree_iterator &operator=(rbtree_iterator<Iter> const &x) {
    _cursor = x.base();
  };

  template <class Iter> bool operator==(rbtree_iterator<Iter> const &x) const {
    return _cursor == x.base();
  };
  template <class Iter> bool operator!=(rbtree_iterator<Iter> const &x) const {
    return _cursor != x.base();
  };

  reference operator*(void) { return *_cursor; }
  pointer operator->(void) { return _cursor; }

  rbtree_iterator &operator++(void) {
    pointer tmp;

    if (_cursor == NULL)
      return *this;
    if (_cursor->parent == NULL) {

      return *this;
    }
    if (_cursor->right != NULL) {
      _cursor = _cursor->right;
      while (_cursor->left != NULL)
        _cursor = _cursor->left;
      return *this;
    }
    tmp = _cursor->parent;
    while (tmp != NULL && _cursor == tmp->right) {
      _cursor = tmp;
      tmp = tmp->parent;
    }
    _cursor = tmp;
    return *this;
  };

  rbtree_iterator operator++(int) {
    rbtree_iterator old = *this;
    operator++();
    return old;
  };

  rbtree_iterator &operator--(void) {
    pointer tmp;

    if (_cursor == NULL)
      return *this;

    return *this;
  };

  rbtree_iterator operator--(int) {
    rbtree_iterator old = *this;
    operator--();
    return old;
  };

  pointer const base(void) const { return _cursor; }

private:
  pointer _cursor;
};
}; // namespace ft

#endif
