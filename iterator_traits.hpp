#ifndef FT_CONTAINERS_ITERATOR_TRAITS_HPP_
#define FT_CONTAINERS_ITERATOR_TRAITS_HPP_
#pragma once

#include <iterator>

namespace ft {
template <typename T> struct iterator_traits {
  typedef typename T::value_type value_type;
  typedef typename T::difference_type difference_type;
  typedef typename T::iterator_category iterator_category;
  typedef typename T::pointer pointer;
  typedef typename T::reference reference;
};

template <typename T> struct iterator_traits<T *> {
  typedef T value_type;
  typedef ptrdiff_t difference_type;
  typedef std::random_access_iterator_tag iterator_category;
  typedef T *pointer;
  typedef T &reference;
};

template <typename T> struct iterator_traits<T const *> {
  typedef T value_type;
  typedef std::ptrdiff_t difference_type;
  typedef std::random_access_iterator_tag iterator_category;
  typedef T const *pointer;
  typedef T const &reference;
};
}; // namespace ft

#endif
