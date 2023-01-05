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
  (void)a;
  (void)b;
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
  //////////////////////////////
  //////////////////////////////
  test_default_constructor();
  test_resize();
  test_reserve();
  test_multi_insert_many();
}
