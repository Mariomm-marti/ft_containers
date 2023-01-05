#ifndef FT_CONTAINERS_MAKE_PAIR_HPP_
#define FT_CONTAINERS_MAKE_PAIR_HPP_
#include "pair.hpp"
#pragma once

namespace ft {
template <class T1, class T2> ft::pair<T1, T2> make_pair(T1 x, T2 y) {
  return pair<T1, T2>(x, y);
}
}; // namespace ft

#endif
