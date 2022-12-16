#include "../../vector.hpp"
#include <cassert>
#include <iostream>
#include <vector>

void test_correct_max_size() {
  std::vector<int> a;
  ft::vector<int> b;

  assert(a.max_size() == b.max_size());
}

int main(void) { test_correct_max_size(); }
