#include "../vector.hpp"
#include <cassert>
#include <iostream>
#include <vector>

void test_copy_constructor(void) {
  ft::vector<int> a(40, 10);
  ft::vector<int> b(a);
  ft::vector<int> c;

  int d[5] = {0, 1, 2, 3, 4};
  ft::vector_iterator<int const> e(d);
  ft::vector_iterator<int const> f(d + 5);
  ft::vector<int const> g(e, f);

  for (ft::vector_iterator<int const> h = g.cbegin(); h < g.cend(); h++)
    std::cout << "Iterating" << *h << std::endl;
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

// TODO good
void test_vector_init_capacity(void) {
  std::vector<int> test(40, 10);

  std::cout << "Cap " << test.capacity() << std::endl;
  for (size_t i = 0; i < 41; i++)
    test.push_back(10);
  std::cout << "Cap " << test.capacity() << std::endl;
}

void test_vector_iterator_range_capacity(void) {
  std::vector<int> test(40, 10);
  std::vector<int> test1(test.begin(), test.end());

  std::cout << "Cap " << test.capacity() << std::endl;
  std::cout << "Cap " << test1.capacity() << std::endl;
}

int main(void) {
  test_copy_constructor();
  test_correct_max_size();
  test_correct_max_size_complex();
  test_incorrect_max_size();
  test_vector_init_capacity();
  test_vector_iterator_range_capacity();
}
