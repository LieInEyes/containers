#include <gtest/gtest.h>

#include <stack>

#include "../containers.h"
#include "test_class.h"

using namespace std;

//// ДЕФОЛТНЫЙ КОНСТРУКТОР
TEST(ConstructorDef, Default1) {
  my_space::Stack<int> test1;
  stack<int> test2;

  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());
}

TEST(ConstructorDef, Default2) {
  my_space::Stack<TestObj> test1;
  stack<TestObj> test2;

  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());
}

//// КОНСТРУКТОР С ИНИЦИАЛИЗАЦИЕЙ ЗНАЧЕНИЙ
TEST(ConstructorInit, Init1) {
  my_space::Stack<int> test1({4, 5, 2});
  stack<int> test2({4, 5, 2});

  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());
  ASSERT_EQ(test1.Top(), test2.top());
}

TEST(ConstructorInit, Init2) {
  my_space::Stack<int> test1({1});
  stack<int> test2({1});

  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());
  ASSERT_EQ(test1.Top(), test2.top());
}

TEST(ConstructorInit, Init3) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3);
  my_space::Stack<TestObj> test1({a1, a2, a3});
  stack<TestObj> test2({a1, a2, a3});

  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());
  ASSERT_EQ(test1.Top().GetNum(), test2.top().GetNum());
}

TEST(ConstructorInit, Init4) {
  TestObj a1("a1", 1);
  my_space::Stack<TestObj> test1({a1});
  stack<TestObj> test2({a1});

  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());
  ASSERT_EQ(test1.Top().GetNum(), test2.top().GetNum());
}

TEST(ConstructorInit, Init5) {
  my_space::Stack<std::string> list_string({"Hello", "I'm", "wifi"});
  std::stack<std::string> std_list_string({"Hello", "I'm", "wifi"});
  ASSERT_EQ(list_string.Size(), std_list_string.size());
  ASSERT_EQ(list_string.Empty(), std_list_string.empty());
  ASSERT_EQ(list_string.Top(), std_list_string.top());
}

//// КОНСТРУКТОР КОПИРОВАНИЕ + ПЕРЕГРУЗКА = КОПИРОВАНИЯ
TEST(ConstructorCopy, Copy1) {
  my_space::Stack<int> test1({1, 2, 3, 4, 5});
  my_space::Stack<int> test2(test1);
  stack<int> test3({1, 2, 3, 4, 5});
  stack<int> test4(test3);

  ASSERT_EQ(test1.Size(), test3.size());
  ASSERT_EQ(test2.Size(), test4.size());
  ASSERT_EQ(test1.Empty(), test3.empty());
  ASSERT_EQ(test2.Empty(), test4.empty());
  ASSERT_EQ(test1.Top(), test3.top());
  ASSERT_EQ(test2.Top(), test4.top());
}

TEST(ConstructorCopy, Copy2) {
  my_space::Stack<int> test1({1, 2, 3, 4, 5});
  my_space::Stack<int> test2;
  test2 = test1;
  stack<int> test3({1, 2, 3, 4, 5});
  stack<int> test4;
  test4 = test3;

  ASSERT_EQ(test1.Size(), test3.size());
  ASSERT_EQ(test2.Size(), test4.size());
  ASSERT_EQ(test1.Empty(), test3.empty());
  ASSERT_EQ(test2.Empty(), test4.empty());
  ASSERT_EQ(test1.Top(), test3.top());
  ASSERT_EQ(test2.Top(), test4.top());
}

TEST(ConstructorCopy, Copy3) {
  my_space::Stack<int> test1({1, 2, 3, 4, 5});
  my_space::Stack<int> test2({25, 24, 23, 27, 28});
  test2 = test1;
  stack<int> test3({1, 2, 3, 4, 5});
  stack<int> test4({25, 24, 23, 27, 28});
  test4 = test3;

  ASSERT_EQ(test1.Size(), test3.size());
  ASSERT_EQ(test2.Size(), test4.size());
  ASSERT_EQ(test1.Empty(), test3.empty());
  ASSERT_EQ(test2.Empty(), test4.empty());
  ASSERT_EQ(test1.Top(), test3.top());
  ASSERT_EQ(test2.Top(), test4.top());
}

TEST(ConstructorCopy, Copy4) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3);
  my_space::Stack<TestObj> test1({a1, a2, a3});
  my_space::Stack<TestObj> test2(test1);
  stack<TestObj> test3({a1, a2, a3});
  stack<TestObj> test4(test3);

  ASSERT_EQ(test1.Size(), test3.size());
  ASSERT_EQ(test2.Size(), test4.size());
  ASSERT_EQ(test1.Empty(), test3.empty());
  ASSERT_EQ(test2.Empty(), test4.empty());
  ASSERT_EQ(test1.Top().GetNum(), test3.top().GetNum());
  ASSERT_EQ(test2.Top().GetNum(), test4.top().GetNum());
}

TEST(ConstructorCopy, Copy5) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3);
  my_space::Stack<TestObj> test1({a1, a2, a3});
  my_space::Stack<TestObj> test2;
  test2 = test1;
  stack<TestObj> test3({a1, a2, a3});
  stack<TestObj> test4;
  test4 = test3;

  ASSERT_EQ(test1.Size(), test3.size());
  ASSERT_EQ(test2.Size(), test4.size());
  ASSERT_EQ(test1.Empty(), test3.empty());
  ASSERT_EQ(test2.Empty(), test4.empty());
  ASSERT_EQ(test1.Top().GetNum(), test3.top().GetNum());
  ASSERT_EQ(test2.Top().GetNum(), test4.top().GetNum());
}

TEST(ConstructorCopy, Copy6) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3), a4("a4", 4), a5("a5", 5),
      a6("a6", 6);
  my_space::Stack<TestObj> test1({a1, a2, a3});
  my_space::Stack<TestObj> test2({a5, a4, a6});
  test2 = test1;
  stack<TestObj> test3({a1, a2, a3});
  stack<TestObj> test4({a5, a4, a6});
  test4 = test3;

  ASSERT_EQ(test1.Size(), test3.size());
  ASSERT_EQ(test2.Size(), test4.size());
  ASSERT_EQ(test1.Empty(), test3.empty());
  ASSERT_EQ(test2.Empty(), test4.empty());
  ASSERT_EQ(test1.Top().GetNum(), test3.top().GetNum());
  ASSERT_EQ(test2.Top().GetNum(), test4.top().GetNum());
}

////// КОНСТРУКТОР ПЕРЕМЕЩЕНИЯ + ПЕРЕГРУЗКА = ПЕРЕМЕЩЕНИЯ
TEST(ConstructorMove, Move1) {
  my_space::Stack<int> test1({1, 2, 3, 4, 5});
  my_space::Stack<int> test2(std::move(test1));
  stack<int> test3({1, 2, 3, 4, 5});
  stack<int> test4(std::move(test3));

  ASSERT_EQ(test1.Size(), test3.size());
  ASSERT_EQ(test2.Size(), test4.size());
  ASSERT_EQ(test1.Empty(), test3.empty());
  ASSERT_EQ(test2.Empty(), test4.empty());
  ASSERT_EQ(test2.Top(), test4.top());
}

TEST(ConstructorMove, Move2) {
  my_space::Stack<int> test1({1, 2, 3, 4, 5});
  my_space::Stack<int> test2;
  test2 = std::move(test1);
  stack<int> test3({1, 2, 3, 4, 5});
  stack<int> test4;
  test4 = std::move(test3);

  ASSERT_EQ(test1.Size(), test3.size());
  ASSERT_EQ(test2.Size(), test4.size());
  ASSERT_EQ(test1.Empty(), test3.empty());
  ASSERT_EQ(test2.Empty(), test4.empty());
  ASSERT_EQ(test2.Top(), test4.top());
}

TEST(ConstructorMove, Move3) {
  my_space::Stack<int> test1({1, 2, 3, 4, 5});
  my_space::Stack<int> test2({25, 24, 23, 27, 28});
  test2 = std::move(test1);
  stack<int> test3({1, 2, 3, 4, 5});
  stack<int> test4({25, 24, 23, 27, 28});
  test4 = std::move(test3);

  ASSERT_EQ(test1.Size(), test3.size());
  ASSERT_EQ(test2.Size(), test4.size());
  ASSERT_EQ(test1.Empty(), test3.empty());
  ASSERT_EQ(test2.Empty(), test4.empty());
  ASSERT_EQ(test2.Top(), test4.top());
}

TEST(ConstructorMove, Move4) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3);
  my_space::Stack<TestObj> test1({a1, a2, a3});
  my_space::Stack<TestObj> test2(std::move(test1));
  stack<TestObj> test3({a1, a2, a3});
  stack<TestObj> test4(std::move(test3));

  ASSERT_EQ(test1.Size(), test3.size());
  ASSERT_EQ(test2.Size(), test4.size());
  ASSERT_EQ(test1.Empty(), test3.empty());
  ASSERT_EQ(test2.Empty(), test4.empty());
  ASSERT_EQ(test2.Top().GetNum(), test4.top().GetNum());
}

TEST(ConstructorMove, Move5) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3);
  my_space::Stack<TestObj> test1({a1, a2, a3});
  my_space::Stack<TestObj> test2;
  test2 = std::move(test1);
  stack<TestObj> test3({a1, a2, a3});
  stack<TestObj> test4;
  test4 = std::move(test3);

  ASSERT_EQ(test1.Size(), test3.size());
  ASSERT_EQ(test2.Size(), test4.size());
  ASSERT_EQ(test1.Empty(), test3.empty());
  ASSERT_EQ(test2.Empty(), test4.empty());
  ASSERT_EQ(test2.Top().GetNum(), test4.top().GetNum());
}

TEST(ConstructorMove, Move6) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3), a4("a4", 4), a5("a5", 5),
      a6("a6", 6);
  my_space::Stack<TestObj> test1({a1, a2, a3});
  my_space::Stack<TestObj> test2({a5, a4, a6});
  test2 = std::move(test1);
  stack<TestObj> test3({a1, a2, a3});
  stack<TestObj> test4({a5, a4, a6});
  test4 = std::move(test3);

  ASSERT_EQ(test1.Size(), test3.size());
  ASSERT_EQ(test2.Size(), test4.size());
  ASSERT_EQ(test1.Empty(), test3.empty());
  ASSERT_EQ(test2.Empty(), test4.empty());
  ASSERT_EQ(test2.Top().GetNum(), test4.top().GetNum());
}

//// PUSH
TEST(Push, Push1) {
  my_space::Stack<int> test1;
  std::stack<int> test2;

  test1.Push(444);
  test2.push(444);

  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());
  ASSERT_EQ(test1.Top(), test2.top());
}

TEST(Push, Push2) {
  my_space::Stack<int> test1({1, 2, 3});
  std::stack<int> test2({1, 2, 3});

  test1.Push(444);
  test2.push(444);

  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());
  ASSERT_EQ(test1.Top(), test2.top());
}

TEST(Push, Push3) {
  TestObj a1("a1", 1);
  my_space::Stack<TestObj> test1;
  std::stack<TestObj> test2;

  test1.Push(a1);
  test2.push(a1);

  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());
  ASSERT_EQ(test1.Top().GetNum(), test2.top().GetNum());
}

TEST(Push, Push4) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3), a4("a4", 4);
  my_space::Stack<TestObj> test1({a1, a2, a3});
  std::stack<TestObj> test2({a1, a2, a3});

  test1.Push(a4);
  test2.push(a4);

  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());
  ASSERT_EQ(test1.Top().GetNum(), test2.top().GetNum());
}

//// POP
TEST(Pop, Pop1) {
  my_space::Stack<int> test1({1, 2, 3});
  std::stack<int> test2({1, 2, 3});

  test1.Pop();
  test2.pop();

  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());
  ASSERT_EQ(test1.Top(), test2.top());
}

TEST(Pop, Pop2) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3);
  my_space::Stack<TestObj> test1({a1, a2, a3});
  std::stack<TestObj> test2({a1, a2, a3});

  test1.Pop();
  test2.pop();

  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());
  ASSERT_EQ(test1.Top().GetNum(), test2.top().GetNum());
}

//// SWAP
TEST(Swap, Swap1) {
  my_space::Stack<int> test1({0, 0, 0});
  my_space::Stack<int> test2({1, 2, 1, 3, 4});
  test1.Swap(test2);

  stack<int> test3({0, 0, 0});
  stack<int> test4({1, 2, 1, 3, 4});
  test3.swap(test4);

  ASSERT_EQ(test1.Size(), test3.size());
  ASSERT_EQ(test2.Size(), test4.size());
  ASSERT_EQ(test1.Empty(), test3.empty());
  ASSERT_EQ(test2.Empty(), test4.empty());
  ASSERT_EQ(test1.Top(), test3.top());
  ASSERT_EQ(test2.Top(), test4.top());
}

TEST(Swap, Swap2) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3), a4("a4", 4), a5("a5", 5),
      a6("a6", 6);
  my_space::Stack<TestObj> test1({a6, a1, a5});
  my_space::Stack<TestObj> test2({a1, a2, a1, a3, a4});
  test1.Swap(test2);

  stack<TestObj> test3({a6, a1, a5});
  stack<TestObj> test4({a1, a2, a1, a3, a4});
  test3.swap(test4);

  ASSERT_EQ(test1.Size(), test3.size());
  ASSERT_EQ(test2.Size(), test4.size());
  ASSERT_EQ(test1.Empty(), test3.empty());
  ASSERT_EQ(test2.Empty(), test4.empty());
  ASSERT_EQ(test1.Top().GetNum(), test3.top().GetNum());
  ASSERT_EQ(test2.Top().GetNum(), test4.top().GetNum());
}

//// EMPLACEFRONT
TEST(EmplaceFront, EmplaceFront1) {
  my_space::Stack<int> test1;
  std::stack<int> test2;

  test1.EmplaceFront(444);
  test2.emplace(444);

  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());
  ASSERT_EQ(test1.Top(), test2.top());
}

TEST(EmplaceFront, EmplaceFront2) {
  my_space::Stack<int> test1({1, 2, 3});
  std::stack<int> test2({1, 2, 3});

  test1.EmplaceFront(444);
  test2.emplace(444);

  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());
  ASSERT_EQ(test1.Top(), test2.top());
}

TEST(EmplaceFront, EmplaceFront3) {
  my_space::Stack<TestObj> test1;
  std::stack<TestObj> test2;

  test1.EmplaceFront("a4", 4);
  test2.emplace("a4", 4);

  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());
  ASSERT_EQ(test1.Top().GetNum(), test2.top().GetNum());
}

TEST(EmplaceFront, EmplaceFront4) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3);
  my_space::Stack<TestObj> test1({a1, a2, a3});
  std::stack<TestObj> test2({a1, a2, a3});

  test1.EmplaceFront("a4", 4);
  test2.emplace("a4", 4);

  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());
  ASSERT_EQ(test1.Top().GetNum(), test2.top().GetNum());
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
