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

void test_default_constructor_const(void) {
  ft::vector<int const> a;
  std::vector<int const> b;
  (void)a;
  (void)b;
}

void test_sizeval_constructor(void) {
  ft::vector<int> a(40, 10);
  std::vector<int> b(40, 10);
  (void)a;
  (void)b;
}

void test_sizeval_constructor_const(void) {
  ft::vector<int const> a(40, 10);
  std::vector<int const> b(40, 10);
  (void)a;
  (void)b;
}

void test_inputit_constructor(void) {
  int ptr[5] = {0, 1, 2, 3, 4};
  ft::vector<int> a(ptr, ptr + 5);
  std::vector<int> b(ptr, ptr + 5);
  (void)a;
  (void)b;
}

void test_inputit_constructor_const(void) {
  int ptr[5] = {0, 1, 2, 3, 4};
  ft::vector<int const> a(ptr, ptr + 5);
  std::vector<int const> b(ptr, ptr + 5);
  (void)a;
  (void)b;
}

void test_copy_constructor(void) {
  ft::vector<int> a(40, 10);
  ft::vector<int> b(a);
  std::vector<int> c(40, 10);
  std::vector<int> d(c);
  (void)b;
  (void)d;
}

void test_copy_constructor_const(void) {
  ft::vector<int const> a(40, 10);
  ft::vector<int const> b(a);
  std::vector<int const> c(40, 10);
  std::vector<int const> d(c);
  (void)b;
  (void)d;
}

void test_destructor_invalidation(void) {
  std::cout << "Creating" << std::endl;
  ft::vector<int> a(40, 10);
  std::cout << "Creating" << std::endl;
  ft::vector<int> b(1, 5);
  std::cout << "Declaring it" << std::endl;
  ft::vector<int>::const_iterator it = a.cbegin();
  std::vector<int> c(40, 10);
  std::vector<int> d(1, 5);
  std::vector<int>::const_iterator it2 = c.cbegin();
  std::cout << "Erasing a?" << std::endl;
  a = b;
  c = d;
  std::cout << "Test " << *it << std::endl;
  std::cout << "Test " << *it2 << std::endl;
}

void test_correct_max_size() {
  std::vector<int> a;
  ft::vector<int> b;

  assert(a.max_size() == b.max_size());
}

void test_correct_max_size_complex() {
  std::vector<std::vector<int> > a;
  ft::vector<std::vector<int> > b;

  assert(a.max_size() == b.max_size());
}

void test_incorrect_max_size() {
  std::vector<ft::vector<int> > a;
  ft::vector<std::vector<int> > b;

  assert(a.max_size() != b.max_size());
}

int main(void) {
  test_default_constructor();
  test_default_constructor_const();
  test_sizeval_constructor();
  test_sizeval_constructor_const();
  test_inputit_constructor();
  test_inputit_constructor_const();
  test_copy_constructor();
  test_copy_constructor_const();
  test_destructor_invalidation();

  test_correct_max_size();
  test_correct_max_size_complex();
  test_incorrect_max_size();
}
