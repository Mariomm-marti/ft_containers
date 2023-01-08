#ifndef FT_CONTAINERS_REVERSE_ITERATOR_HPP_
#define FT_CONTAINERS_REVERSE_ITERATOR_HPP_
#pragma once

#include "iterator_traits.hpp"
#include <iterator>

namespace ft {
template <class Iterator> struct reverse_iterator {
  typedef Iterator iterator_type;
  typedef typename ft::iterator_traits<iterator_type>::iterator_category
      iterator_category;
  typedef typename ft::iterator_traits<iterator_type>::value_type value_type;
  typedef typename ft::iterator_traits<iterator_type>::difference_type
      difference_type;
  typedef typename ft::iterator_traits<iterator_type>::pointer pointer;
  typedef typename ft::iterator_traits<iterator_type>::reference reference;

  reverse_iterator(void) : _it(iterator_type()) {}
  explicit reverse_iterator(iterator_type it) : _it(it){};
  template <class Iter>
  reverse_iterator(reverse_iterator<Iter> const &rev_it) : _it(rev_it.base()) {}

  iterator_type base(void) const { return _it; }

  reference operator*(void) const { return *(--iterator_type(_it)); }
  reverse_iterator operator+(difference_type n) const {
    return reverse_iterator(_it - n);
  }
  reverse_iterator &operator++(void) { return --_it; }
  reverse_iterator operator++(int) {
    reverse_iterator tmp = *this;
    --_it;
    return tmp;
  }
  reverse_iterator &operator+=(difference_type n) {
    _it = _it - n;
    return *this;
  }
  reverse_iterator operator-(difference_type n) const {
    return reverse_iterator(_it + n);
  }
  reverse_iterator &operator--(void) { return ++_it; }
  reverse_iterator operator--(int) {
    reverse_iterator tmp = *this;
    ++_it;
    return tmp;
  }
  reverse_iterator &operator-=(difference_type n) {
    _it = _it + n;
    return *this;
  }
  pointer operator->(void) const { return &(operator*()); }
  reference operator[](difference_type n) const { return base()[-n - 1]; }

private:
  iterator_type _it;
};

template <class Iterator, class CmpIterator>
bool operator==(reverse_iterator<Iterator> const &lhs,
                reverse_iterator<CmpIterator> const &rhs) {
  return lhs.base() == rhs.base();
}
template <class Iterator, class CmpIterator>
bool operator!=(reverse_iterator<Iterator> const &lhs,
                reverse_iterator<CmpIterator> const &rhs) {
  return lhs.base() != rhs.base();
}
template <class Iterator, class CmpIterator>
bool operator<(reverse_iterator<Iterator> const &lhs,
               reverse_iterator<CmpIterator> const &rhs) {
  return lhs.base() > rhs.base();
}
template <class Iterator, class CmpIterator>
bool operator<=(reverse_iterator<Iterator> const &lhs,
                reverse_iterator<CmpIterator> const &rhs) {
  return lhs.base() >= rhs.base();
}
template <class Iterator, class CmpIterator>
bool operator>(reverse_iterator<Iterator> const &lhs,
               reverse_iterator<CmpIterator> const &rhs) {
  return lhs.base() < rhs.base();
}
template <class Iterator, class CmpIterator>
bool operator>=(reverse_iterator<Iterator> const &lhs,
                reverse_iterator<CmpIterator> const &rhs) {
  return lhs.base() <= rhs.base();
}
template <class Iterator>
reverse_iterator<Iterator>
operator+(typename reverse_iterator<Iterator>::difference_type n,
          reverse_iterator<Iterator> const &rev_it) {
  return reverse_iterator<Iterator>(rev_it.base() - n);
}
template <class Iterator, class CmpIterator>
typename reverse_iterator<Iterator>::difference_type
operator-(reverse_iterator<Iterator> const &lhs,
          reverse_iterator<CmpIterator> const &rhs) {
  return rhs.base() - lhs.base();
}
}; // namespace ft

#endif
