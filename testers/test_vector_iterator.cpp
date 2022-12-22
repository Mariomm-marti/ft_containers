#include "../vector_iterator.hpp"
#include <cassert>
#include <iostream>
#include <iterator>
#include <vector>

class Test {
  int a;

public:
  Test(int b) { a = b; }

  bool operator==(Test const &rhs) const { return a == rhs.a; }

  int get_a(void) const { return a; }
  void set_a(int const new_a) { a = new_a; }
};

void test_iterator_default_constructor(void) { ft::vector_iterator<int> a; }

void test_iterator_construct_value(void) {
  int ptr[4] = {0, 1, 2, 3};
  ft::vector_iterator<int> abc(ptr);
}

void test_iterator_copy_constructible(void) {
  int ptr[4] = {10, 14, 12, 13};
  ft::vector_iterator<int> a(ptr);
  ft::vector_iterator<int> b(a);

  assert(*a == *b);
  assert(*a == 10);
  a++;
  b++;
  assert(*a == *b);
  assert(*a == 14);
}

void test_iterator_copy_assignable(void) {
  typedef std::vector<int>::iterator it;

  int ptr[4] = {10, 14, 12, 13};
  ft::vector_iterator<int> a(ptr);
  ft::vector_iterator<int> b = a;

  std::vector<int> d;
  it e = d.begin();
  it f = e;

  assert(a == b);
  assert(e == f);
  f++;
  a++;
  assert(a != b);
  assert(e != f);
}

void test_iterator_equality_inequality(void) {
  typedef std::vector<int>::iterator it;

  int ptr[4] = {10, 11, 12, 13};
  int ptrb[4] = {10, 11, 12, 13};

  ft::vector_iterator<int> a(ptr);
  ft::vector_iterator<int> b(ptrb);
  std::vector<int> c;
  c.push_back(1);
  c.push_back(2);
  std::vector<int> d;
  d.push_back(1);
  d.push_back(2);

  it e = c.begin();
  it f = d.begin();

  assert(a != b);
  assert(e != f);
  a = b;
  e = f;
  assert(a == b);
  assert(e == f);
}

void test_iterator_dereference(void) {
  int ptr[4] = {0, 2, 4, 8};

  ft::vector_iterator<int> it(ptr);
  std::vector<int> vector;
  vector.push_back(0);
  vector.push_back(2);
  vector.push_back(4);
  vector.push_back(8);
  std::vector<int>::iterator it2 = vector.begin();
  assert(*it == 0);
  assert(*it2 == 0);
  assert(*it++ == 0);
  assert(*it2++ == 0);
  assert(*it == 2);
  assert(*it2 == 2);
  assert(*++it == 4);
  assert(*++it2 == 4);
}

void test_iterator_arrow_dereference(void) {
  Test ptr[4] = {Test(2), Test(4), Test(6), Test(8)};

  ft::vector_iterator<Test> it(ptr);
  std::vector<Test> vector;
  vector.push_back(Test(2));
  vector.push_back(Test(4));
  vector.push_back(Test(6));
  vector.push_back(Test(8));
  std::vector<Test>::iterator it2 = vector.begin();
  assert(it->get_a() == it2->get_a());
  it2++;
  assert(it->get_a() != it2->get_a());
  it++;
  assert(it->get_a() == it2->get_a());
}

void test_iterator_increase_pre_post(void) {
  Test ptr[4] = {Test(2), Test(4), Test(6), Test(8)};

  ft::vector_iterator<Test> it(ptr);
  ft::vector_iterator<Test> it2(ptr);
  std::vector<Test> vector;
  vector.push_back(Test(2));
  vector.push_back(Test(4));
  vector.push_back(Test(6));
  vector.push_back(Test(8));
  std::vector<Test>::iterator ot = vector.begin();
  std::vector<Test>::iterator ot2 = vector.begin();
  assert(it == it2);
  assert(ot == ot2);
  assert(it++ == it2);
  assert(ot++ == ot2);
  assert(it != it2);
  assert(ot != ot2);
  assert(it == ++it2);
  assert(ot == ++ot2);
}

void test_iterator_decrease_pre_post(void) {
  Test ptr[4] = {Test(2), Test(4), Test(6), Test(8)};

  ft::vector_iterator<Test> it(ptr);
  ft::vector_iterator<Test> it2(ptr);
  assert(it == it2);
  assert(it++ == it2);
  assert(--it == it2);
  assert(it == it2++);
  assert(it != it2--);
  assert(it == it2);
}

void test_iterator_addition(void) {
  Test ptr[4] = {Test(2), Test(4), Test(6), Test(8)};

  ft::vector_iterator<Test> it(ptr);
  ft::vector_iterator<Test> it2(ptr);
  std::vector<Test> vector;
  vector.push_back(Test(2));
  vector.push_back(Test(4));
  vector.push_back(Test(6));
  vector.push_back(Test(8));
  std::vector<Test>::iterator ot = vector.begin();
  std::vector<Test>::iterator ot2 = vector.begin();

  assert(it + 4 == it2 + 4);
  assert(ot + 4 == ot2 + 4);
  it2 += 2;
  ot2 += 2;
  assert(it + 2 == it2);
  assert(ot + 2 == ot2);
}

void test_iterator_subtraction(void) {
  Test ptr[4] = {Test(2), Test(4), Test(6), Test(8)};

  ft::vector_iterator<Test> it(ptr);
  ft::vector_iterator<Test> it2(ptr);
  std::vector<Test> vector;
  vector.push_back(Test(2));
  vector.push_back(Test(4));
  vector.push_back(Test(6));
  vector.push_back(Test(8));
  std::vector<Test>::iterator ot = vector.begin();
  std::vector<Test>::iterator ot2 = vector.begin();

  it++;
  ot++;
  assert(it - 1 == it2);
  assert(ot - 1 == ot2);
  it2 += 2;
  ot2 += 2;
  it += 2;
  ot += 2;
  assert(it - 1 == it2);
  assert(ot - 1 == ot2);
}

void test_iterator_less_than(void) {
  Test ptr[4] = {Test(2), Test(4), Test(6), Test(8)};

  ft::vector_iterator<Test> it(ptr);
  std::vector<Test> vector;
  vector.push_back(Test(2));
  vector.push_back(Test(4));
  vector.push_back(Test(6));
  vector.push_back(Test(8));
  std::vector<Test>::iterator ot = vector.begin();

  assert(!(it < it));
  assert(!(ot < ot));
  assert(it < it + 1);
  assert(ot < ot + 1);
  assert(!(it + 1 < it));
  assert(!(ot + 1 < ot));
}

void test_iterator_greater_than(void) {
  Test ptr[4] = {Test(2), Test(4), Test(6), Test(8)};

  ft::vector_iterator<Test> it(ptr);
  std::vector<Test> vector;
  vector.push_back(Test(2));
  vector.push_back(Test(4));
  vector.push_back(Test(6));
  vector.push_back(Test(8));
  std::vector<Test>::iterator ot = vector.begin();

  assert(!(it > it));
  assert(!(ot > ot));
  assert(it + 1 > it);
  assert(ot + 1 > ot);
  assert(!(it > it + 1));
  assert(!(ot > ot + 1));
}

void test_iterator_less_or_equals_than(void) {
  Test ptr[4] = {Test(2), Test(4), Test(6), Test(8)};

  ft::vector_iterator<Test> it(ptr);
  std::vector<Test> vector;
  vector.push_back(Test(2));
  vector.push_back(Test(4));
  vector.push_back(Test(6));
  vector.push_back(Test(8));
  std::vector<Test>::iterator ot = vector.begin();

  assert(it <= it);
  assert(ot <= ot);
  assert(it < it + 1);
  assert(ot < ot + 1);
  assert(!(it + 1 < it));
  assert(!(ot + 1 < ot));
}

void test_iterator_greater_or_equals_than(void) {
  Test ptr[4] = {Test(2), Test(4), Test(6), Test(8)};

  ft::vector_iterator<Test> it(ptr);
  std::vector<Test> vector;
  vector.push_back(Test(2));
  vector.push_back(Test(4));
  vector.push_back(Test(6));
  vector.push_back(Test(8));
  std::vector<Test>::iterator ot = vector.begin();

  assert(it >= it);
  assert(ot >= ot);
  assert(it + 1 > it);
  assert(ot + 1 > ot);
  assert(!(it > it + 1));
  assert(!(ot > ot + 1));
}

void test_iterator_addition_assign(void) {
  Test ptr[4] = {Test(2), Test(4), Test(6), Test(8)};

  ft::vector_iterator<Test> it(ptr);
  std::vector<Test> vector;
  vector.push_back(Test(2));
  vector.push_back(Test(4));
  vector.push_back(Test(6));
  vector.push_back(Test(8));
  std::vector<Test>::iterator ot = vector.begin();

  assert(*(it += 2) == Test(6));
  assert(*(ot += 2) == Test(6));
}

void test_iterator_subtraction_assign(void) {
  Test ptr[4] = {Test(2), Test(4), Test(6), Test(8)};

  ft::vector_iterator<Test> it(ptr);
  std::vector<Test> vector;
  vector.push_back(Test(2));
  vector.push_back(Test(4));
  vector.push_back(Test(6));
  vector.push_back(Test(8));
  std::vector<Test>::iterator ot = vector.begin();

  it += 4;
  ot += 4;
  assert(*(it -= 2) == Test(6));
  assert(*(ot -= 2) == Test(6));
}

void test_iterator_dereference_offset(void) {
  Test ptr[4] = {Test(2), Test(4), Test(6), Test(8)};

  ft::vector_iterator<Test> it(ptr);
  std::vector<Test> vector;
  vector.push_back(Test(2));
  vector.push_back(Test(4));
  vector.push_back(Test(6));
  vector.push_back(Test(8));
  std::vector<Test>::iterator ot = vector.begin();

  assert(it[2] == Test(6));
  assert(ot[2] == Test(6));
}

void test_iterator_const_upgrade(void) {
  Test ptr[4] = {Test(2), Test(4), Test(6), Test(8)};

  ft::vector_iterator<Test> it(ptr);
  ft::vector_iterator<Test const> it2(it);
  // DOWNGRADE IS NOT POSSIBLE ft::vector_iterator<Test> it3(it2);
  *it2;
  it2++;
  // DOWNGRADE IS NOT POSSIBLE it2->set_a();
  *it;
  it++;
  it->set_a(10);
}

int main(void) {
  test_iterator_default_constructor();
  test_iterator_copy_constructible();
  test_iterator_copy_assignable();
  test_iterator_equality_inequality();
  test_iterator_dereference();
  test_iterator_arrow_dereference();
  test_iterator_increase_pre_post();
  test_iterator_decrease_pre_post();
  test_iterator_addition();
  test_iterator_subtraction();
  test_iterator_less_than();
  test_iterator_greater_than();
  test_iterator_less_or_equals_than();
  test_iterator_greater_or_equals_than();
  test_iterator_addition_assign();
  test_iterator_subtraction_assign();
  test_iterator_dereference_offset();
  test_iterator_const_upgrade();
}
