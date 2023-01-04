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

void tests(void) {
  std::allocator<size_t> alloc;
  size_t *ptr;

  ptr = alloc.allocate(20);
  for (size_t i = 0; i < 20; i++)
    alloc.construct(ptr + i, i);
  for (size_t i = 0; i < 20; i++)
    std::cout << *(ptr + i) << std::endl;

  std::vector<int> a(42, 10);
  std::vector<int> b(56, 10);
  a.assign(b.begin(), b.end());
  std::cout << "cap " << a.capacity() << std::endl;
}

int main(void) {
  //////////////////////////////
  tests();
  //////////////////////////////
  test_default_constructor();
  test_resize();
  test_reserve();
}
