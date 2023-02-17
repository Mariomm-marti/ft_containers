#ifndef FT_CONTAINERS_RBTREE_NODE_HPP_
#define FT_CONTAINERS_RBTREE_NODE_HPP_
#pragma once

#include <cstddef>
#include <functional>

namespace ft {
template <class T, class Compare = std::less<T>> struct rbtree_node {
  typedef Compare key_compare;

  T value;
  rbtree_node *parent;
  rbtree_node *left;
  rbtree_node *right;

  rbtree_node(void) : value(T()), parent(NULL), left(NULL), right(NULL){};
  rbtree_node(rbtree_node const &copy)
      : value(copy.value), parent(copy.parent), left(copy.left),
        right(copy.right){};
  rbtree_node(T value_, rbtree_node const *parent_ = NULL,
              rbtree_node const *left_ = NULL, rbtree_node const *right_ = NULL)
      : value(value_), parent(parent_), left(left_), right(right_){};
  ~rbtree_node(void){};

  rbtree_node &operator=(rbtree_node const &x) {
    value = x.value;
    parent = x.parent;
    left = x.left;
    right = x.right;
  };

  bool operator==(rbtree_node const &x) {
    return !key_compare(value, x.value) && !key_compare(x.value, value);
  };
  bool operator!=(rbtree_node const &x) { return !(*this == x); };
  bool operator<(rbtree_node const &x) { return key_compare(*this, x); };
  bool operator>(rbtree_node const &x) { return x < *this; };
  bool operator<=(rbtree_node const &x) { return !(x < *this); };
  bool operator>=(rbtree_node const &x) { return !(*this < x); };
};
}; // namespace ft

#endif
