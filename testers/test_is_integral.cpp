#include "../is_integral.hpp"
#include <cassert>
#include <string>
#include <vector>

void test_not_integral(void) {
  assert(ft::is_integral<std::string>::value == false);
  assert(ft::is_integral<std::vector<int> >::value == false);
}

void test_is_integral(void) {
  assert(ft::is_integral<bool>::value == true);
  assert(ft::is_integral<char>::value == true);
  assert(ft::is_integral<char16_t>::value == true);
  assert(ft::is_integral<char32_t>::value == true);
  assert(ft::is_integral<wchar_t>::value == true);
  assert(ft::is_integral<signed char>::value == true);
  assert(ft::is_integral<short int>::value == true);
  assert(ft::is_integral<int>::value == true);
  assert(ft::is_integral<long int>::value == true);
  assert(ft::is_integral<long long int>::value == true);
  assert(ft::is_integral<unsigned char>::value == true);
  assert(ft::is_integral<unsigned short int>::value == true);
  assert(ft::is_integral<unsigned int>::value == true);
  assert(ft::is_integral<unsigned long int>::value == true);
  assert(ft::is_integral<unsigned long long int>::value == true);
}

int main(void) {
  test_not_integral();
  test_is_integral();
}
