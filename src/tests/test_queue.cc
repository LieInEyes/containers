#include <gtest/gtest.h>

#include <queue>

#include "../containers.h"
#include "test_class.h"

using namespace std;

//// ДЕФОЛТНЫЙ КОНСТРУКТОР
TEST(ConstructorDef, Default1) {
  my_space::Queue<int> test1;
  queue<int> test2;

  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());
}

TEST(ConstructorDef, Default2) {
  my_space::Queue<TestObj> test1;
  queue<TestObj> test2;

  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());
}

//// КОНСТРУКТОР С ИНИЦИАЛИЗАЦИЕЙ ЗНАЧЕНИЙ
TEST(ConstructorInit, Init1) {
  my_space::Queue<int> test1({4, 5, 2});
  queue<int> test2({4, 5, 2});

  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());
  ASSERT_EQ(test1.Front(), test2.front());
  ASSERT_EQ(test1.Back(), test2.back());
}

TEST(ConstructorInit, Init2) {
  my_space::Queue<int> test1({1});
  queue<int> test2({1});

  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());
  ASSERT_EQ(test1.Front(), test2.front());
  ASSERT_EQ(test1.Back(), test2.back());
}

TEST(ConstructorInit, Init3) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3);
  my_space::Queue<TestObj> test1({a1, a2, a3});
  queue<TestObj> test2({a1, a2, a3});

  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());
  ASSERT_EQ(test1.Front().GetNum(), test2.front().GetNum());
  ASSERT_EQ(test1.Back().GetNum(), test2.back().GetNum());
}

TEST(ConstructorInit, Init4) {
  TestObj a1("a1", 1);
  my_space::Queue<TestObj> test1({a1});
  queue<TestObj> test2({a1});

  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());
  ASSERT_EQ(test1.Front().GetNum(), test2.front().GetNum());
  ASSERT_EQ(test1.Back().GetNum(), test2.back().GetNum());
}

TEST(ConstructorInit, Init5) {
  my_space::Queue<std::string> list_string({"Hello", "I'm", "wifi"});
  std::queue<std::string> std_list_string({"Hello", "I'm", "wifi"});
  ASSERT_EQ(list_string.Size(), std_list_string.size());
  ASSERT_EQ(list_string.Empty(), std_list_string.empty());
  ASSERT_EQ(list_string.Front(), std_list_string.front());
  ASSERT_EQ(list_string.Back(), std_list_string.back());
}

//// КОНСТРУКТОР КОПИРОВАНИЕ + ПЕРЕГРУЗКА = КОПИРОВАНИЯ
TEST(ConstructorCopy, Copy1) {
  my_space::Queue<int> test1({1, 2, 3, 4, 5});
  my_space::Queue<int> test2(test1);
  queue<int> test3({1, 2, 3, 4, 5});
  queue<int> test4(test3);

  ASSERT_EQ(test1.Size(), test3.size());
  ASSERT_EQ(test2.Size(), test4.size());
  ASSERT_EQ(test1.Empty(), test3.empty());
  ASSERT_EQ(test2.Empty(), test4.empty());
  ASSERT_EQ(test1.Front(), test3.front());
  ASSERT_EQ(test2.Front(), test4.front());
  ASSERT_EQ(test1.Back(), test3.back());
  ASSERT_EQ(test2.Back(), test4.back());
}

TEST(ConstructorCopy, Copy2) {
  my_space::Queue<int> test1({1, 2, 3, 4, 5});
  my_space::Queue<int> test2;
  test2 = test1;
  queue<int> test3({1, 2, 3, 4, 5});
  queue<int> test4;
  test4 = test3;

  ASSERT_EQ(test1.Size(), test3.size());
  ASSERT_EQ(test2.Size(), test4.size());
  ASSERT_EQ(test1.Empty(), test3.empty());
  ASSERT_EQ(test2.Empty(), test4.empty());
  ASSERT_EQ(test1.Front(), test3.front());
  ASSERT_EQ(test2.Front(), test4.front());
  ASSERT_EQ(test1.Back(), test3.back());
  ASSERT_EQ(test2.Back(), test4.back());
}

TEST(ConstructorCopy, Copy3) {
  my_space::Queue<int> test1({1, 2, 3, 4, 5});
  my_space::Queue<int> test2({25, 24, 23, 27, 28});
  test2 = test1;
  queue<int> test3({1, 2, 3, 4, 5});
  queue<int> test4({25, 24, 23, 27, 28});
  test4 = test3;

  ASSERT_EQ(test1.Size(), test3.size());
  ASSERT_EQ(test2.Size(), test4.size());
  ASSERT_EQ(test1.Empty(), test3.empty());
  ASSERT_EQ(test2.Empty(), test4.empty());
  ASSERT_EQ(test1.Front(), test3.front());
  ASSERT_EQ(test2.Front(), test4.front());
  ASSERT_EQ(test1.Back(), test3.back());
  ASSERT_EQ(test2.Back(), test4.back());
}

TEST(ConstructorCopy, Copy4) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3);
  my_space::Queue<TestObj> test1({a1, a2, a3});
  my_space::Queue<TestObj> test2(test1);
  queue<TestObj> test3({a1, a2, a3});
  queue<TestObj> test4(test3);

  ASSERT_EQ(test1.Size(), test3.size());
  ASSERT_EQ(test2.Size(), test4.size());
  ASSERT_EQ(test1.Empty(), test3.empty());
  ASSERT_EQ(test2.Empty(), test4.empty());
  ASSERT_EQ(test1.Front().GetNum(), test3.front().GetNum());
  ASSERT_EQ(test2.Front().GetNum(), test4.front().GetNum());
  ASSERT_EQ(test1.Back().GetNum(), test3.back().GetNum());
  ASSERT_EQ(test2.Back().GetNum(), test4.back().GetNum());
}

TEST(ConstructorCopy, Copy5) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3);
  my_space::Queue<TestObj> test1({a1, a2, a3});
  my_space::Queue<TestObj> test2;
  test2 = test1;
  queue<TestObj> test3({a1, a2, a3});
  queue<TestObj> test4;
  test4 = test3;

  ASSERT_EQ(test1.Size(), test3.size());
  ASSERT_EQ(test2.Size(), test4.size());
  ASSERT_EQ(test1.Empty(), test3.empty());
  ASSERT_EQ(test2.Empty(), test4.empty());
  ASSERT_EQ(test1.Front().GetNum(), test3.front().GetNum());
  ASSERT_EQ(test2.Front().GetNum(), test4.front().GetNum());
  ASSERT_EQ(test1.Back().GetNum(), test3.back().GetNum());
  ASSERT_EQ(test2.Back().GetNum(), test4.back().GetNum());
}

TEST(ConstructorCopy, Copy6) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3), a4("a4", 4), a5("a5", 5),
      a6("a6", 6);
  my_space::Queue<TestObj> test1({a1, a2, a3});
  my_space::Queue<TestObj> test2({a5, a4, a6});
  test2 = test1;
  queue<TestObj> test3({a1, a2, a3});
  queue<TestObj> test4({a5, a4, a6});
  test4 = test3;

  ASSERT_EQ(test1.Size(), test3.size());
  ASSERT_EQ(test2.Size(), test4.size());
  ASSERT_EQ(test1.Empty(), test3.empty());
  ASSERT_EQ(test2.Empty(), test4.empty());
  ASSERT_EQ(test1.Front().GetNum(), test3.front().GetNum());
  ASSERT_EQ(test2.Front().GetNum(), test4.front().GetNum());
  ASSERT_EQ(test1.Back().GetNum(), test3.back().GetNum());
  ASSERT_EQ(test2.Back().GetNum(), test4.back().GetNum());
}

////// КОНСТРУКТОР ПЕРЕМЕЩЕНИЯ + ПЕРЕГРУЗКА = ПЕРЕМЕЩЕНИЯ
TEST(ConstructorMove, Move1) {
  my_space::Queue<int> test1({1, 2, 3, 4, 5});
  my_space::Queue<int> test2(std::move(test1));
  queue<int> test3({1, 2, 3, 4, 5});
  queue<int> test4(std::move(test3));

  ASSERT_EQ(test1.Size(), test3.size());
  ASSERT_EQ(test2.Size(), test4.size());
  ASSERT_EQ(test1.Empty(), test3.empty());
  ASSERT_EQ(test2.Empty(), test4.empty());
  ASSERT_EQ(test2.Front(), test4.front());
  ASSERT_EQ(test2.Back(), test4.back());
}

TEST(ConstructorMove, Move2) {
  my_space::Queue<int> test1({1, 2, 3, 4, 5});
  my_space::Queue<int> test2;
  test2 = std::move(test1);
  queue<int> test3({1, 2, 3, 4, 5});
  queue<int> test4;
  test4 = std::move(test3);

  ASSERT_EQ(test1.Size(), test3.size());
  ASSERT_EQ(test2.Size(), test4.size());
  ASSERT_EQ(test1.Empty(), test3.empty());
  ASSERT_EQ(test2.Empty(), test4.empty());
  ASSERT_EQ(test2.Front(), test4.front());
  ;
  ASSERT_EQ(test2.Back(), test4.back());
}

TEST(ConstructorMove, Move3) {
  my_space::Queue<int> test1({1, 2, 3, 4, 5});
  my_space::Queue<int> test2({25, 24, 23, 27, 28});
  test2 = std::move(test1);
  queue<int> test3({1, 2, 3, 4, 5});
  queue<int> test4({25, 24, 23, 27, 28});
  test4 = std::move(test3);

  ASSERT_EQ(test1.Size(), test3.size());
  ASSERT_EQ(test2.Size(), test4.size());
  ASSERT_EQ(test1.Empty(), test3.empty());
  ASSERT_EQ(test2.Empty(), test4.empty());
  ASSERT_EQ(test2.Front(), test4.front());
  ASSERT_EQ(test2.Back(), test4.back());
}

TEST(ConstructorMove, Move4) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3);
  my_space::Queue<TestObj> test1({a1, a2, a3});
  my_space::Queue<TestObj> test2(std::move(test1));
  queue<TestObj> test3({a1, a2, a3});
  queue<TestObj> test4(std::move(test3));

  ASSERT_EQ(test1.Size(), test3.size());
  ASSERT_EQ(test2.Size(), test4.size());
  ASSERT_EQ(test1.Empty(), test3.empty());
  ASSERT_EQ(test2.Empty(), test4.empty());
  ASSERT_EQ(test2.Front().GetNum(), test4.front().GetNum());
  ASSERT_EQ(test2.Back().GetNum(), test4.back().GetNum());
}

TEST(ConstructorMove, Move5) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3);
  my_space::Queue<TestObj> test1({a1, a2, a3});
  my_space::Queue<TestObj> test2;
  test2 = std::move(test1);
  queue<TestObj> test3({a1, a2, a3});
  queue<TestObj> test4;
  test4 = std::move(test3);

  ASSERT_EQ(test1.Size(), test3.size());
  ASSERT_EQ(test2.Size(), test4.size());
  ASSERT_EQ(test1.Empty(), test3.empty());
  ASSERT_EQ(test2.Empty(), test4.empty());
  ASSERT_EQ(test2.Front().GetNum(), test4.front().GetNum());
  ASSERT_EQ(test2.Back().GetNum(), test4.back().GetNum());
}

TEST(ConstructorMove, Move6) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3), a4("a4", 4), a5("a5", 5),
      a6("a6", 6);
  my_space::Queue<TestObj> test1({a1, a2, a3});
  my_space::Queue<TestObj> test2({a5, a4, a6});
  test2 = std::move(test1);
  queue<TestObj> test3({a1, a2, a3});
  queue<TestObj> test4({a5, a4, a6});
  test4 = std::move(test3);

  ASSERT_EQ(test1.Size(), test3.size());
  ASSERT_EQ(test2.Size(), test4.size());
  ASSERT_EQ(test1.Empty(), test3.empty());
  ASSERT_EQ(test2.Empty(), test4.empty());
  ASSERT_EQ(test2.Front().GetNum(), test4.front().GetNum());
  ASSERT_EQ(test2.Back().GetNum(), test4.back().GetNum());
}

//// PUSH
TEST(Push, Push1) {
  my_space::Queue<int> test1;
  std::queue<int> test2;

  test1.Push(444);
  test2.push(444);

  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());
  ASSERT_EQ(test1.Front(), test2.front());
  ASSERT_EQ(test1.Back(), test2.back());
}

TEST(Push, Push2) {
  my_space::Queue<int> test1({1, 2, 3});
  std::queue<int> test2({1, 2, 3});

  test1.Push(444);
  test2.push(444);

  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());
  ASSERT_EQ(test1.Front(), test2.front());
  ASSERT_EQ(test1.Back(), test2.back());
}

TEST(Push, Push3) {
  TestObj a1("a1", 1);
  my_space::Queue<TestObj> test1;
  std::queue<TestObj> test2;

  test1.Push(a1);
  test2.push(a1);

  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());
  ASSERT_EQ(test1.Front().GetNum(), test2.front().GetNum());
  ASSERT_EQ(test1.Back().GetNum(), test2.back().GetNum());
}

TEST(Push, Push4) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3), a4("a4", 4);
  my_space::Queue<TestObj> test1({a1, a2, a3});
  std::queue<TestObj> test2({a1, a2, a3});

  test1.Push(a4);
  test2.push(a4);

  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());
  ASSERT_EQ(test1.Front().GetNum(), test2.front().GetNum());
  ASSERT_EQ(test1.Back().GetNum(), test2.back().GetNum());
}

//// POP
TEST(Pop, Pop1) {
  my_space::Queue<int> test1({1, 2, 3});
  std::queue<int> test2({1, 2, 3});

  test1.Pop();
  test2.pop();

  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());
  ASSERT_EQ(test1.Front(), test2.front());
  ASSERT_EQ(test1.Back(), test2.back());
}

TEST(Pop, Pop2) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3);
  my_space::Queue<TestObj> test1({a1, a2, a3});
  std::queue<TestObj> test2({a1, a2, a3});

  test1.Pop();
  test2.pop();

  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());
  ASSERT_EQ(test1.Front().GetNum(), test2.front().GetNum());
  ASSERT_EQ(test1.Back().GetNum(), test2.back().GetNum());
}

//// SWAP
TEST(Swap, Swap1) {
  my_space::Queue<int> test1({0, 0, 0});
  my_space::Queue<int> test2({1, 2, 1, 3, 4});
  test1.Swap(test2);

  queue<int> test3({0, 0, 0});
  queue<int> test4({1, 2, 1, 3, 4});
  test3.swap(test4);

  ASSERT_EQ(test1.Size(), test3.size());
  ASSERT_EQ(test2.Size(), test4.size());
  ASSERT_EQ(test1.Empty(), test3.empty());
  ASSERT_EQ(test2.Empty(), test4.empty());
  ASSERT_EQ(test1.Front(), test3.front());
  ASSERT_EQ(test1.Back(), test3.back());
}

TEST(Swap, Swap2) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3), a4("a4", 4), a5("a5", 5),
      a6("a6", 6);
  my_space::Queue<TestObj> test1({a6, a1, a5});
  my_space::Queue<TestObj> test2({a1, a2, a1, a3, a4});
  test1.Swap(test2);

  queue<TestObj> test3({a6, a1, a5});
  queue<TestObj> test4({a1, a2, a1, a3, a4});
  test3.swap(test4);

  ASSERT_EQ(test1.Size(), test3.size());
  ASSERT_EQ(test2.Size(), test4.size());
  ASSERT_EQ(test1.Empty(), test3.empty());
  ASSERT_EQ(test2.Empty(), test4.empty());
  ASSERT_EQ(test1.Front().GetNum(), test3.front().GetNum());
  ASSERT_EQ(test1.Back().GetNum(), test3.back().GetNum());
}

//// EMPLACEFRONT
TEST(EmplaceFront, EmplaceFront1) {
  my_space::Queue<int> test1;
  std::queue<int> test2;

  test1.EmplaceBack(444);
  test2.emplace(444);

  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());
  ASSERT_EQ(test1.Front(), test2.front());
  ASSERT_EQ(test1.Back(), test2.back());
}

TEST(EmplaceFront, EmplaceFront2) {
  my_space::Queue<int> test1({1, 2, 3});
  std::queue<int> test2({1, 2, 3});

  test1.EmplaceBack(444);
  test2.emplace(444);

  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());
  ASSERT_EQ(test1.Front(), test2.front());
  ASSERT_EQ(test1.Back(), test2.back());
}

TEST(EmplaceFront, EmplaceFront3) {
  my_space::Queue<TestObj> test1;
  std::queue<TestObj> test2;

  test1.EmplaceBack("a4", 4);
  test2.emplace("a4", 4);

  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());
  ASSERT_EQ(test1.Front().GetNum(), test2.front().GetNum());
  ASSERT_EQ(test1.Back().GetNum(), test2.back().GetNum());
}

TEST(EmplaceFront, EmplaceFront4) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3);
  my_space::Queue<TestObj> test1({a1, a2, a3});
  std::queue<TestObj> test2({a1, a2, a3});

  test1.EmplaceBack("a4", 4);
  test2.emplace("a4", 4);

  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());
  ASSERT_EQ(test1.Front().GetNum(), test2.front().GetNum());
  ASSERT_EQ(test1.Back().GetNum(), test2.back().GetNum());
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
