#include "../lexicographical_compare.hpp"
#include <string>

bool reverse_compare(char const &first, char const &second) {
  return first > second;
}

void test_lexicographical_equal(void) {
  std::string str = std::string("hello!");
  std::string str2 = std::string("hello!");

  assert(ft::lexicographical_compare(str.begin(), str.end(), str2.begin(),
                                     str2.end()) == false);
  assert(std::lexicographical_compare(str.begin(), str.end(), str2.begin(),
                                      str2.end()) == false);
}

void test_lexicographical_less(void) {
  std::string str = std::string("hello ");
  std::string str2 = std::string("hello!");

  assert(ft::lexicographical_compare(str.begin(), str.end(), str2.begin(),
                                     str2.end()) == true);
  assert(std::lexicographical_compare(str.begin(), str.end(), str2.begin(),
                                      str2.end()) == true);
}

void test_lexicographical_more(void) {
  std::string str = std::string("hello!");
  std::string str2 = std::string("hello ");

  assert(ft::lexicographical_compare(str.begin(), str.end(), str2.begin(),
                                     str2.end()) == false);
  assert(std::lexicographical_compare(str.begin(), str.end(), str2.begin(),
                                      str2.end()) == false);
}

void test_different_length(void) {
  std::string str = std::string("hello");
  std::string str2 = std::string("hello!");

  assert(ft::lexicographical_compare(str.begin(), str.end(), str2.begin(),
                                     str2.end()) == true);
  assert(std::lexicographical_compare(str.begin(), str.end(), str2.begin(),
                                      str2.end()) == true);
}

void test_different_length_reverse(void) {
  std::string str = std::string("hello!");
  std::string str2 = std::string("hello");

  assert(ft::lexicographical_compare(str.begin(), str.end(), str2.begin(),
                                     str2.end()) == false);
  assert(std::lexicographical_compare(str.begin(), str.end(), str2.begin(),
                                      str2.end()) == false);
}

void test_empty(void) {
  std::string str = std::string("");
  std::string str2 = std::string("");

  assert(ft::lexicographical_compare(str.begin(), str.end(), str2.begin(),
                                     str2.end()) == false);
  assert(std::lexicographical_compare(str.begin(), str.end(), str2.begin(),
                                      str2.end()) == false);
}

void test_early_difference(void) {
  std::string str = std::string("abc");
  std::string str2 = std::string("def");

  assert(ft::lexicographical_compare(str.begin(), str.end(), str2.begin(),
                                     str2.end()) == true);
  assert(std::lexicographical_compare(str.begin(), str.end(), str2.begin(),
                                      str2.end()) == true);
}

void test_early_difference_inverted(void) {
  std::string str = std::string("def");
  std::string str2 = std::string("abc");

  assert(ft::lexicographical_compare(str.begin(), str.end(), str2.begin(),
                                     str2.end()) == false);
  assert(std::lexicographical_compare(str.begin(), str.end(), str2.begin(),
                                      str2.end()) == false);
}

void test_lexicographical_less_custom_compare(void) {
  std::string str = std::string("hello ");
  std::string str2 = std::string("hello!");

  assert(ft::lexicographical_compare(str.begin(), str.end(), str2.begin(),
                                     str2.end(), reverse_compare) == false);
  assert(std::lexicographical_compare(str.begin(), str.end(), str2.begin(),
                                      str2.end(), reverse_compare) == false);
}

int main(void) {
  test_lexicographical_equal();
  test_lexicographical_less();
  test_lexicographical_more();
  test_different_length();
  test_different_length_reverse();
  test_empty();
  test_early_difference();
  test_early_difference_inverted();
  test_lexicographical_less_custom_compare();
}
