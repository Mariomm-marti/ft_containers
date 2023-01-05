#include "../vector.hpp"
#include <cassert>
#include <cstring>
#include <exception>
#include <iostream>
#include <iterator>
#include <vector>

void test_default_constructor(void) {
  ft::vector<int> a;
  std::vector<int> b;
}

void test_constructor_elements(void) {
  ft::vector<int> a(7);
  std::vector<int> b(7);
}

void test_constructor_iterator(void) {
  std::vector<int> iterable(40, 20);

  ft::vector<int> vft(iterable.begin(), iterable.end());
  std::vector<int> vstd(iterable.begin(), iterable.end());

  ft::vector<int>::iterator itft = vft.begin();
  std::vector<int>::iterator itstd = vstd.begin();
  while (itft < vft.end() || itstd < vstd.end()) {
    assert(*itft == *itstd);
    itft++, itstd++;
  }
}

void test_constructor_iterator_complex(void) {
  std::vector<int> lst;
  std::vector<int>::iterator lst_it;
  for (int i = 1; i < 5; ++i)
    lst.push_back(i * 3);

  ft::vector<int> vct(lst.begin(), lst.end());

  lst_it = lst.begin();
}

void test_resize(void) {
  ft::vector<int> a;
  std::vector<int> b;

  b.resize(10);
}

void test_reserve(void) {
  ft::vector<int> a;
  std::vector<int> b(40, 19);

  b.reserve(39);
}

void test_multi_insert_many(void) {
  std::vector<int> vstd;
  ft::vector<int> vft;

  vstd.insert(vstd.begin(), 10, 42);
  vstd.insert(vstd.begin() + 2, 5, 21);
  vft.insert(vft.begin(), 10, 42);
  vft.insert(vft.begin() + 2, 5, 21);
  std::vector<int>::iterator it = vstd.begin();
  ft::vector<int>::iterator it2 = vft.begin();
  while (it < vstd.end() || it2 < vft.end())
    assert(*it++ == *it2++);
}

void test_insert_iterator(void) {
  std::vector<int> teststd(40, 20);
  ft::vector<int> testft(40, 20);
  std::vector<int> vstd;
  ft::vector<int> vft;

  vstd.insert(vstd.begin(), teststd.begin(), teststd.end());
  teststd.assign(4, 21);
  vstd.insert(vstd.begin() + 4, teststd.begin(), teststd.end());

  vft.insert(vft.begin(), testft.begin(), testft.end());
  testft.assign(4, 21);
  vft.insert(vft.begin() + 4, testft.begin(), testft.end());

  std::vector<int>::iterator it = vstd.begin();
  ft::vector<int>::iterator it2 = vft.begin();
  while (it < vstd.end() || it2 < vft.end())
    assert(*it++ == *it2++);
}

void atExitCustom(void) { system("leaks a.out"); }

int main(void) {
  atexit(atExitCustom);
  test_default_constructor();
  test_constructor_elements();
  test_constructor_iterator();
  test_resize();
  test_reserve();
  test_multi_insert_many();
}
