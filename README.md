<div align='center'>

# ft_containers
#### _Reimplementation of the STL (Standard Template Library) in C++98._

[About it](#about-it) ~
[Using it](#using-it) ~
[References](#references)

</div>

## About it
The `ft_containers` is a "homemade" reimplementation of the STL (Standard Template Library).
This reimplementation aimed to help understanding the different data structures and their underlying storage algorithm.

These are the different data structures reimplemented:

- [x] `std::vector<T>` -> `ft::vector<T>`: dynamic-sized memory-contiguous array
- [x] `std::stack<T, Container = std::vector<T> >` -> `ft::stack<T, Container = std::vector<T> >`: adapts a container to become a LIFO data structure
- [ ] `std::map<Key, T, Compare = std::less<Key>` -> `ft::map<Key, T, Compare = std::less<Key>`: Key-Value container with underlying RB-Tree storage structure

And the respective data structures iterators:
- [x] `ft::vector_iterator<T>`: iterators for any given vector, whether `const`, `const *`, or `*`
- [x] `ft::reverse_iterator<T>`: reversed working iterator for any given iterator. It simply reverses the operations
- [x] `ft::rbtree_iterator<T, Compare = std::less<T> >`: red-black tree iterator for any kind of value `T`

Additionally, the following utils/metaprogramming utils were reimplemented as auxiliar structures:
- [x] `std::pair<K,V>` -> `ft::pair<K,V>`: binary tuple (ie. a pair of values)
- [x] `std::iterator_traits<T>` -> `ft::iterator_traits<T>`: util to determine which is the correct iterator property to use, depending on the value of `T` (`const`, `const *`, `*`, or normal)
- [x] `std::lexicographical_compare<InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2>` -> `ft::lexicographical_compare<InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2>`: allows comparing lexicographically (ie. comparing two iterators) if two iterable sets of elements are equal
- [x] `std::enable_if<bool Cond, T>` -> `ft::enable_if<bool Cond, T>`: conditionally removes overloads. Used mainly to determine if an iterator is actually iterable (such a number) or not. If not, then the template function is disabled
- [ ] `ft::rbtree<T, Compare = std::less<T> >`: an implementation of the red-black tree with a good space complexity of O(n) and an access time of O(log n)

## Using it
To use it, simply clone the repository and include the data structure of your need according to the aforementioned description. Here is an example of usage for `ft::vector<int>`:
```cpp
#include "vector.hpp"

// Constructs a vector of 40 elements initialised with the value 20
ft::vector<int> iterable(40, 20);

// Constructs a vector based on the previous vector by using the iterators
ft::vector<int> vft(iterable.begin(), iterable.end());
```

All functionality respects the reference given below.

## References
- [cppreference for STL on C++98](https://cppreference.com)
