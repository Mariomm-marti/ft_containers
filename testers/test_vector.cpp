#include "../vector.hpp"
#include <cassert>
#include <cstring>
#include <exception>
#include <iostream>
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
  std::cout << "ca " << b.capacity() << std::endl;
}

void test_reserve(void) {
  ft::vector<int> a;
  std::vector<int> b(40, 19);

  b.reserve(39);
  std::cout << "Capacity: " << b.capacity() << std::endl;
}

void tests(void) {
  std::allocator<size_t> alloc;
  size_t *ptr;

  ptr = alloc.allocate(20);
  for (size_t i = 0; i < 20; i++)
    alloc.construct(ptr + i, i);
  for (size_t i = 0; i < 20; i++)
    std::cout << *(ptr + i) << std::endl;
}

int main(void) {
  //////////////////////////////
  tests();
  //////////////////////////////
  test_default_constructor();
  test_resize();
  test_reserve();
}
