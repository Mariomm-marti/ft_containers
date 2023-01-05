#ifndef FT_CONTAINERS_LEXICOGRAPHICAL_COMPARE_HPP_
#define FT_CONTAINERS_LEXICOGRAPHICAL_COMPARE_HPP_
#pragma once

namespace ft {
template <class InputIterator1, class InputIterator2>
bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
                             InputIterator2 first2, InputIterator2 last2) {
  for (; first1 != last1 && first2 != last2 && *first1 == *first2;
       first1++, first2++)
    ;
  return *first1 < *first2;
};

template <class InputIterator1, class InputIterator2, class Compare>
bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
                             InputIterator2 first2, InputIterator2 last2,
                             Compare comp) {
  for (; first1 < last1 && first2 < last2 && !comp(*first1, *first2) &&
         !comp(*first2, *first1);
       first1++, first2++)
    ;
  return comp(*first1, *first2);
};
}; // namespace ft

#endif
