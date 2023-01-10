#ifndef FT_CONTAINERS_RBTREE_HPP_
#define FT_CONTAINERS_RBTREE_HPP_
#pragma once

#include "make_pair.hpp"
#include "pair.hpp"
#include <cstddef>
#include <functional>
#include <memory>

namespace ft {
enum rbtree_colors { BLACK, RED };

template <class Key, class T, class Compare = std::less<Key> >
struct rbtree_node {
  // Nodes are shallow-created. Deleting a node does not cascade
  // delete all in-depth nodes
  //
  // Node comparison-related operators will assess the key using Compare
  typedef Key key_type;
  typedef T mapped_type;
  typedef ft::pair<key_type const, mapped_type> value_type;
  typedef Compare key_compare;
  typedef enum rbtree_colors node_color;
  typedef rbtree_node<key_type, mapped_type, key_compare> node;
  typedef node *node_pointer;
  typedef node const *node_const_pointer;

  node_color color;
  value_type value;
  node_pointer parent;
  node_pointer left;
  node_pointer right;

  rbtree_node(void)
      : color(RED), value(value_type()), parent(NULL), left(NULL),
        right(NULL){};
  rbtree_node(rbtree_node const &copy)
      : color(copy.color), value(copy.value), parent(copy.parent),
        left(copy.left), right(copy.right){};
  rbtree_node(key_type const &key, mapped_type const &value,
              node_color const &color_ = RED, node_pointer const parent_ = NULL,
              node_pointer const left_ = NULL, node_pointer const right_ = NULL)
      : color(color_), value(ft::make_pair(key, value)), parent(parent_),
        left(left_), right(right_){};
  ~rbtree_node(void){};

  template <class KeyCopy, class TCopy>
  rbtree_node &operator=(rbtree_node<KeyCopy, TCopy> const &copy) {
    color = copy.color;
    value = copy.value;
    parent = copy.parent;
    left = copy.left;
    right = copy.right;
    return *this;
  }

  template <class KeyCmp, class TCmp>
  bool operator==(rbtree_node<KeyCmp, TCmp> const &x) {
    return !key_compare(value.first, x.value.first) &&
           !key_compare(x.value.first, value.first);
  }

  template <class KeyCmp, class TCmp>
  bool operator!=(rbtree_node<KeyCmp, TCmp> const &x) {
    return !(*this == x);
  }

  template <class KeyCmp, class TCmp>
  bool operator<(rbtree_node<KeyCmp, TCmp> const &x) {
    return key_compare(value.first, x.value.first);
  }

  template <class KeyCmp, class TCmp>
  bool operator>(rbtree_node<KeyCmp, TCmp> const &x) {
    return x < *this;
  }

  template <class KeyCmp, class TCmp>
  bool operator<=(rbtree_node<KeyCmp, TCmp> const &x) {
    return !(x < *this);
  }

  template <class KeyCmp, class TCmp>
  bool operator>=(rbtree_node<KeyCmp, TCmp> const &x) {
    return !(*this < x);
  }
};

template <class Key, class T, class Compare = std::less<Key> > class rbtree {
public:
  typedef Key key_type;
  typedef T mapped_type;
  typedef Compare key_compare;
  typedef rbtree_node<key_type, mapped_type, key_compare> node;
  typedef node *pointer;
  typedef node const *const_pointer;
  typedef node &reference;
  typedef node const &const_reference;
  typedef std::ptrdiff_t difference_type;
  typedef std::size_t size_type;

private:
  pointer _root;

public:
  rbtree(void) : _root(NULL){};
  // rbtree(rbtree const &x)
  // ~rbtree(void) {};

  // rbtree &operator=(rbtree const &right);
  const_pointer operator[](key_type const &key) {
    pointer treeit = _root;
    node compare_node = node(key, mapped_type());

    if (treeit == NULL)
      return NULL;
    while (treeit != compare_node) {
    }
  };
};
}; // namespace ft

#endif
