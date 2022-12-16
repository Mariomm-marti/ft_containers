#include "../vector.hpp"
#include "../vector_iterator.hpp"
#include <iterator>
#include <vector>

int main(void) {
  ft::vector<int> test;
  ft::vector_iterator<int> it = test.begin();
  std::cout << *it << std::endl;
}
