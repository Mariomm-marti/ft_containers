#ifndef FT_CONTAINERS_ENABLE_IF_HPP_
#define FT_CONTAINERS_ENABLE_IF_HPP_
#pragma once

namespace ft {
template <bool Cond, class T = void> struct enable_if {};
template <class T> struct enable_if<true, T> {
  typedef T type;
};
}; // namespace ft

#endif
