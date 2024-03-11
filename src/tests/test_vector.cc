#include <gtest/gtest.h>

#include <vector>

#include "../containers.h"
#include "test_class.h"

using namespace std;

//// ДЕФОЛТНЫЙ КОНСТРУКТОР
TEST(ConstructorDef, Defolt1) {
  my_space::Vector<int> test1;
  vector<int> test3;
  ASSERT_EQ(test1.Size(), test3.size());
  ASSERT_EQ(test1.Capacity(), test3.capacity());
  ASSERT_EQ(test1.Data(), test3.data());
}

TEST(ConstructorDef, Defolt2) {
  my_space::Vector<TestObj> test1;
  vector<TestObj> test3;
  ASSERT_EQ(test1.Size(), test3.size());
  ASSERT_EQ(test1.Capacity(), test3.capacity());
  ASSERT_EQ(test1.Data(), test3.data());
}

//// КОНСТРУКТОР С ИНИЦИАЛИЗАЦИЕЙ ЗНАЧЕНИЙ
TEST(ConstructorInit, Init1) {
  my_space::Vector<int> test1({4, 5, 2});
  vector<int> test2({4, 5, 2});
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Capacity(), test2.capacity());
  ASSERT_NE(test1.Data(), test2.data());
  for (size_t i = 0; i < test1.Size(); ++i) {
    ASSERT_EQ(test1.At(i), test2.at(i));
  }
}

TEST(ConstructorInit, Init2) {
  my_space::Vector<int> test1({1});
  vector<int> test2({1});
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Capacity(), test2.capacity());
  ASSERT_NE(test1.Data(), test2.data());
  ASSERT_EQ(test1.At(0), test2.at(0));
}

TEST(ConstructorInit, Init3) {
  my_space::Vector<int> test1({});
  vector<int> test2({});
  ASSERT_EQ(test1.Size(), 0);
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Capacity(), 0);
  ASSERT_EQ(test1.Capacity(), test2.capacity());
  ASSERT_EQ(test1.Data(), test2.data());
}

TEST(ConstructorInit, Init4) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3);
  my_space::Vector<TestObj> test1({a1, a2, a3});
  vector<TestObj> test2{a1, a2, a3};
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Capacity(), test2.capacity());
  ASSERT_NE(test1.Data(), test2.data());
  for (size_t i = 0; i < test1.Size(); i++) {
    ASSERT_EQ(test1.At(i).GetNum(), test2.at(i).GetNum());
  }
}

TEST(ConstructorInit, Init5) {
  TestObj a1("a1", 1);
  my_space::Vector<TestObj> test1({a1});
  vector<TestObj> test2({a1});
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Capacity(), test2.capacity());
  ASSERT_NE(test1.Data(), test2.data());
  ASSERT_EQ(test1.At(0).GetNum(), test2.at(0).GetNum());
}

TEST(ConstructorInit, Init6) {
  my_space::Vector<TestObj> test1({});
  vector<TestObj> test2({});
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Capacity(), test2.capacity());
  ASSERT_EQ(test1.Data(), test2.data());
}

//// КОНСТРУКТОР С УКАЗАНИЕМ РАЗМЕРА И ИНИЦИАЛИЗАЦИЕЙ НУЛЯМИ
TEST(ConstructorSize, WithSize1) {
  my_space::Vector<int> test1(50);
  vector<int> test2(50);
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Capacity(), test2.capacity());
  ASSERT_NE(test1.Data(), test2.data());
  for (size_t i = 0; i < test1.Size(); i++) {
    ASSERT_EQ(test1.At(i), test2.at(i));
  }
}

TEST(ConstructorSize, WithSize2) {
  my_space::Vector<int> test1(0);
  vector<int> test2(0);
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Capacity(), test2.capacity());
  ASSERT_EQ(test1.Data(), nullptr);
  ASSERT_EQ(test1.Data(), test2.data());
}

TEST(ConstructorSize, WithSize3) {
  my_space::Vector<TestObj> test1(50);
  vector<TestObj> test2(50);
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Capacity(), test2.capacity());
  ASSERT_NE(test1.Data(), test2.data());
  for (size_t i = 0; i < test1.Size(); i++) {
    ASSERT_EQ(test1.At(i).GetNum(), test2.at(i).GetNum());
  }
}

TEST(ConstructorSize, WithSize4) {
  my_space::Vector<TestObj> test1(0);
  vector<TestObj> test2(0);
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Capacity(), test2.capacity());
  ASSERT_EQ(test1.Data(), nullptr);
  ASSERT_EQ(test1.Data(), test2.data());
}

//// КОНСТРУКТОР КОПИРОВАНИЕ + ПЕРЕГРУЗКА = КОПИРОВАНИЯ
TEST(ConstructorCopy, Copy1) {
  my_space::Vector<int> test1({1, 2, 3, 4, 5});
  my_space::Vector<int> test2(test1);
  vector<int> test3({1, 2, 3, 4, 5});
  vector<int> test4(test3);

  ASSERT_EQ(test1.Size(), test2.Size());
  ASSERT_EQ(test1.Size(), test4.size());
  ASSERT_EQ(test2.Size(), test3.size());
  ASSERT_EQ(test2.Size(), test4.size());
  ASSERT_EQ(test3.size(), test4.size());

  ASSERT_EQ(test1.Capacity(), test2.Capacity());
  ASSERT_EQ(test1.Capacity(), test4.capacity());
  ASSERT_EQ(test2.Capacity(), test3.capacity());
  ASSERT_EQ(test2.Capacity(), test4.capacity());
  ASSERT_EQ(test3.capacity(), test4.capacity());

  ASSERT_NE(test1.Data(), test2.Data());
  ASSERT_NE(test1.Data(), test4.data());
  ASSERT_NE(test2.Data(), test3.data());
  ASSERT_NE(test2.Data(), test4.data());
  ASSERT_NE(test3.data(), test4.data());

  for (size_t i = 0; i < test1.Size(); i++) {
    ASSERT_EQ(test2.At(i), test4.at(i));
  }
}

TEST(ConstructorCopy, Copy2) {
  my_space::Vector<int> test1({1, 2, 3, 4, 5});
  my_space::Vector<int> test2(50);
  test2 = test1;
  vector<int> test3({1, 2, 3, 4, 5});
  vector<int> test4(50);
  test4 = test3;

  ASSERT_EQ(test1.Size(), test2.Size());
  ASSERT_EQ(test1.Size(), test4.size());
  ASSERT_EQ(test2.Size(), test3.size());
  ASSERT_EQ(test2.Size(), test4.size());
  ASSERT_EQ(test3.size(), test4.size());

  ASSERT_NE(test1.Capacity(), test2.Capacity());
  ASSERT_NE(test1.Capacity(), test4.capacity());
  ASSERT_NE(test2.Capacity(), test3.capacity());
  ASSERT_EQ(test2.Capacity(), test4.capacity());
  ASSERT_NE(test3.capacity(), test4.capacity());

  ASSERT_NE(test1.Data(), test2.Data());
  ASSERT_NE(test1.Data(), test4.data());
  ASSERT_NE(test2.Data(), test3.data());
  ASSERT_NE(test2.Data(), test4.data());
  ASSERT_NE(test3.data(), test4.data());

  for (size_t i = 0; i < test1.Size(); i++) {
    ASSERT_EQ(test2.At(i), test4.at(i));
  }
}

TEST(ConstructorCopy, Copy3) {
  my_space::Vector<int> test1({1, 2, 3, 4, 5});
  my_space::Vector<int> test2(2);
  test2 = test1;
  vector<int> test3({1, 2, 3, 4, 5});
  vector<int> test4(2);
  test4 = test3;

  ASSERT_EQ(test1.Size(), test2.Size());
  ASSERT_EQ(test1.Size(), test4.size());
  ASSERT_EQ(test2.Size(), test3.size());
  ASSERT_EQ(test2.Size(), test4.size());
  ASSERT_EQ(test3.size(), test4.size());

  ASSERT_EQ(test1.Capacity(), test2.Capacity());
  ASSERT_EQ(test1.Capacity(), test4.capacity());
  ASSERT_EQ(test2.Capacity(), test3.capacity());
  ASSERT_EQ(test2.Capacity(), test4.capacity());
  ASSERT_EQ(test3.capacity(), test4.capacity());

  ASSERT_NE(test1.Data(), test2.Data());
  ASSERT_NE(test1.Data(), test4.data());
  ASSERT_NE(test2.Data(), test3.data());
  ASSERT_NE(test2.Data(), test4.data());
  ASSERT_NE(test3.data(), test4.data());

  for (size_t i = 0; i < test1.Size(); i++) {
    ASSERT_EQ(test2.At(i), test4.at(i));
  }
}

TEST(ConstructorCopy, Copy4) {
  my_space::Vector<int> test1({1, 2, 3, 4, 5});
  my_space::Vector<int> test2(5);
  test2 = test1;
  vector<int> test3({1, 2, 3, 4, 5});
  vector<int> test4(5);
  test4 = test3;

  ASSERT_EQ(test1.Size(), test2.Size());
  ASSERT_EQ(test1.Size(), test4.size());
  ASSERT_EQ(test2.Size(), test3.size());
  ASSERT_EQ(test2.Size(), test4.size());
  ASSERT_EQ(test3.size(), test4.size());

  ASSERT_EQ(test1.Capacity(), test2.Capacity());
  ASSERT_EQ(test1.Capacity(), test4.capacity());
  ASSERT_EQ(test2.Capacity(), test3.capacity());
  ASSERT_EQ(test2.Capacity(), test4.capacity());
  ASSERT_EQ(test3.capacity(), test4.capacity());

  ASSERT_NE(test1.Data(), test2.Data());
  ASSERT_NE(test1.Data(), test4.data());
  ASSERT_NE(test2.Data(), test3.data());
  ASSERT_NE(test2.Data(), test4.data());
  ASSERT_NE(test3.data(), test4.data());

  for (size_t i = 0; i < test1.Size(); i++) {
    ASSERT_EQ(test2.At(i), test4.at(i));
  }
}

TEST(ConstructorCopy, Copy5) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3), a4("a4", 4), a5("a5", 5);
  my_space::Vector<TestObj> test1({a1, a2, a3, a4, a5});
  my_space::Vector<TestObj> test2(test1);
  vector<TestObj> test3({a1, a2, a3, a4, a5});
  vector<TestObj> test4(test3);

  ASSERT_EQ(test1.Size(), test2.Size());
  ASSERT_EQ(test1.Size(), test4.size());
  ASSERT_EQ(test2.Size(), test3.size());
  ASSERT_EQ(test2.Size(), test4.size());
  ASSERT_EQ(test3.size(), test4.size());

  ASSERT_EQ(test1.Capacity(), test2.Capacity());
  ASSERT_EQ(test1.Capacity(), test4.capacity());
  ASSERT_EQ(test2.Capacity(), test3.capacity());
  ASSERT_EQ(test2.Capacity(), test4.capacity());
  ASSERT_EQ(test3.capacity(), test4.capacity());

  ASSERT_NE(test1.Data(), test2.Data());
  ASSERT_NE(test1.Data(), test4.data());
  ASSERT_NE(test2.Data(), test3.data());
  ASSERT_NE(test2.Data(), test4.data());
  ASSERT_NE(test3.data(), test4.data());

  for (size_t i = 0; i < test1.Size(); i++) {
    ASSERT_EQ(test1.At(i).GetNum(), test3.at(i).GetNum());
  }
}

TEST(ConstructorCopy, Copy6) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3), a4("a4", 4), a5("a5", 5);
  my_space::Vector<TestObj> test1({a1, a2, a3, a4, a5});
  my_space::Vector<TestObj> test2(50);
  test2 = test1;
  vector<TestObj> test3({a1, a2, a3, a4, a5});
  vector<TestObj> test4(50);
  test4 = test3;

  ASSERT_EQ(test1.Size(), test2.Size());
  ASSERT_EQ(test1.Size(), test4.size());
  ASSERT_EQ(test2.Size(), test3.size());
  ASSERT_EQ(test2.Size(), test4.size());
  ASSERT_EQ(test3.size(), test4.size());

  ASSERT_NE(test1.Capacity(), test2.Capacity());
  ASSERT_NE(test1.Capacity(), test4.capacity());
  ASSERT_NE(test2.Capacity(), test3.capacity());
  ASSERT_EQ(test2.Capacity(), test4.capacity());
  ASSERT_NE(test3.capacity(), test4.capacity());

  ASSERT_NE(test1.Data(), test2.Data());
  ASSERT_NE(test1.Data(), test4.data());
  ASSERT_NE(test2.Data(), test3.data());
  ASSERT_NE(test2.Data(), test4.data());
  ASSERT_NE(test3.data(), test4.data());

  for (size_t i = 0; i < test1.Size(); i++) {
    ASSERT_EQ(test1.At(i).GetNum(), test3.at(i).GetNum());
  }
}

TEST(ConstructorCopy, Copy7) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3), a4("a4", 4), a5("a5", 5);
  my_space::Vector<TestObj> test1({a1, a2, a3, a4, a5});
  my_space::Vector<TestObj> test2(2);
  test2 = test1;
  vector<TestObj> test3({a1, a2, a3, a4, a5});
  vector<TestObj> test4(2);
  test4 = test3;

  ASSERT_EQ(test1.Size(), test2.Size());
  ASSERT_EQ(test1.Size(), test4.size());
  ASSERT_EQ(test2.Size(), test3.size());
  ASSERT_EQ(test2.Size(), test4.size());
  ASSERT_EQ(test3.size(), test4.size());

  ASSERT_EQ(test1.Capacity(), test2.Capacity());
  ASSERT_EQ(test1.Capacity(), test4.capacity());
  ASSERT_EQ(test2.Capacity(), test3.capacity());
  ASSERT_EQ(test2.Capacity(), test4.capacity());
  ASSERT_EQ(test3.capacity(), test4.capacity());

  ASSERT_NE(test1.Data(), test2.Data());
  ASSERT_NE(test1.Data(), test4.data());
  ASSERT_NE(test2.Data(), test3.data());
  ASSERT_NE(test2.Data(), test4.data());
  ASSERT_NE(test3.data(), test4.data());

  for (size_t i = 0; i < test1.Size(); i++) {
    ASSERT_EQ(test1.At(i).GetNum(), test3.at(i).GetNum());
  }
}

TEST(ConstructorCopy, Copy8) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3), a4("a4", 4), a5("a5", 5);
  my_space::Vector<TestObj> test1({a1, a2, a3, a4, a5});
  my_space::Vector<TestObj> test2(5);
  test2 = test1;
  vector<TestObj> test3({a1, a2, a3, a4, a5});
  vector<TestObj> test4(5);
  test4 = test3;

  ASSERT_EQ(test1.Size(), test2.Size());
  ASSERT_EQ(test1.Size(), test4.size());
  ASSERT_EQ(test2.Size(), test3.size());
  ASSERT_EQ(test2.Size(), test4.size());
  ASSERT_EQ(test3.size(), test4.size());

  ASSERT_EQ(test1.Capacity(), test2.Capacity());
  ASSERT_EQ(test1.Capacity(), test4.capacity());
  ASSERT_EQ(test2.Capacity(), test3.capacity());
  ASSERT_EQ(test2.Capacity(), test4.capacity());
  ASSERT_EQ(test3.capacity(), test4.capacity());

  ASSERT_NE(test1.Data(), test2.Data());
  ASSERT_NE(test1.Data(), test4.data());
  ASSERT_NE(test2.Data(), test3.data());
  ASSERT_NE(test2.Data(), test4.data());
  ASSERT_NE(test3.data(), test4.data());

  for (size_t i = 0; i < test1.Size(); i++) {
    ASSERT_EQ(test1.At(i).GetNum(), test3.at(i).GetNum());
  }
}

//// КОНСТРУКТОР ПЕРЕМЕЩЕНИЯ + ПЕРЕГРУЗКА = ПЕРЕМЕЩЕНИЯ
TEST(ConstructorMove, Move1) {
  my_space::Vector<int> test1({1, 2, 3, 4, 5});
  my_space::Vector<int> test2(std::move(test1));
  vector<int> test3({1, 2, 3, 4, 5});
  vector<int> test4(std::move(test3));

  ASSERT_EQ(test1.Size(), 0);
  ASSERT_EQ(test1.Size(), test3.size());
  ASSERT_EQ(test2.Size(), 5);
  ASSERT_EQ(test2.Size(), test4.size());
  ASSERT_NE(test1.Size(), test2.Size());
  ASSERT_NE(test3.size(), test4.size());

  ASSERT_EQ(test1.Capacity(), 0);
  ASSERT_EQ(test1.Capacity(), test3.capacity());
  ASSERT_EQ(test2.Capacity(), 5);
  ASSERT_EQ(test2.Capacity(), test4.capacity());
  ASSERT_NE(test1.Capacity(), test2.Capacity());
  ASSERT_NE(test3.capacity(), test4.capacity());

  ASSERT_EQ(test1.Data(), nullptr);
  ASSERT_EQ(test1.Data(), test3.data());
  ASSERT_NE(test2.Data(), test1.Data());
  ASSERT_NE(test2.Data(), test3.data());
  ASSERT_NE(test2.Data(), test4.data());
  ASSERT_NE(test3.data(), test4.data());

  for (size_t i = 0; i < test2.Size(); i++) {
    ASSERT_EQ(test2.At(i), test4.at(i));
  }
}

TEST(ConstructorMove, Move2) {
  my_space::Vector<int> test1({1, 2, 3, 4, 5});
  my_space::Vector<int> test2;
  test2 = std::move(test1);
  vector<int> test3({1, 2, 3, 4, 5});
  vector<int> test4;
  test4 = std::move(test3);

  ASSERT_EQ(test1.Size(), 0);
  ASSERT_EQ(test1.Size(), test3.size());
  ASSERT_EQ(test2.Size(), 5);
  ASSERT_EQ(test2.Size(), test4.size());
  ASSERT_NE(test1.Size(), test2.Size());
  ASSERT_NE(test3.size(), test4.size());

  ASSERT_EQ(test1.Capacity(), 0);
  ASSERT_EQ(test1.Capacity(), test3.capacity());
  ASSERT_EQ(test2.Capacity(), 5);
  ASSERT_EQ(test2.Capacity(), test4.capacity());
  ASSERT_NE(test1.Capacity(), test2.Capacity());
  ASSERT_NE(test3.capacity(), test4.capacity());

  ASSERT_EQ(test1.Data(), nullptr);
  ASSERT_EQ(test1.Data(), test3.data());
  ASSERT_NE(test2.Data(), test1.Data());
  ASSERT_NE(test2.Data(), test3.data());
  ASSERT_NE(test2.Data(), test4.data());
  ASSERT_NE(test3.data(), test4.data());

  for (size_t i = 0; i < test2.Size(); i++) {
    ASSERT_EQ(test2.At(i), test4.at(i));
  }
}

TEST(ConstructorMove, Move3) {
  my_space::Vector<int> test1({1, 2, 3, 4, 5});
  my_space::Vector<int> test2(50);
  test2 = std::move(test1);
  vector<int> test3({1, 2, 3, 4, 5});
  vector<int> test4(50);
  test4 = std::move(test3);

  ASSERT_EQ(test1.Size(), 0);
  ASSERT_EQ(test1.Size(), test3.size());
  ASSERT_EQ(test2.Size(), 5);
  ASSERT_EQ(test2.Size(), test4.size());
  ASSERT_NE(test1.Size(), test2.Size());
  ASSERT_NE(test3.size(), test4.size());

  ASSERT_EQ(test1.Capacity(), 0);
  ASSERT_EQ(test1.Capacity(), test3.capacity());
  ASSERT_EQ(test2.Capacity(), 5);
  ASSERT_EQ(test2.Capacity(), test4.capacity());
  ASSERT_NE(test1.Capacity(), test2.Capacity());
  ASSERT_NE(test3.capacity(), test4.capacity());

  ASSERT_EQ(test1.Data(), nullptr);
  ASSERT_EQ(test1.Data(), test3.data());
  ASSERT_NE(test2.Data(), test1.Data());
  ASSERT_NE(test2.Data(), test3.data());
  ASSERT_NE(test2.Data(), test4.data());
  ASSERT_NE(test3.data(), test4.data());

  for (size_t i = 0; i < test2.Size(); i++) {
    ASSERT_EQ(test2.At(i), test4.at(i));
  }
}

TEST(ConstructorMove, Move4) {
  my_space::Vector<int> test1({1, 2, 3, 4, 5});
  my_space::Vector<int> test2(2);
  test2 = std::move(test1);
  vector<int> test3({1, 2, 3, 4, 5});
  vector<int> test4(2);
  test4 = std::move(test3);

  ASSERT_EQ(test1.Size(), 0);
  ASSERT_EQ(test1.Size(), test3.size());
  ASSERT_EQ(test2.Size(), 5);
  ASSERT_EQ(test2.Size(), test4.size());
  ASSERT_NE(test1.Size(), test2.Size());
  ASSERT_NE(test3.size(), test4.size());

  ASSERT_EQ(test1.Capacity(), 0);
  ASSERT_EQ(test1.Capacity(), test3.capacity());
  ASSERT_EQ(test2.Capacity(), 5);
  ASSERT_EQ(test2.Capacity(), test4.capacity());
  ASSERT_NE(test1.Capacity(), test2.Capacity());
  ASSERT_NE(test3.capacity(), test4.capacity());

  ASSERT_EQ(test1.Data(), nullptr);
  ASSERT_EQ(test1.Data(), test3.data());
  ASSERT_NE(test2.Data(), test1.Data());
  ASSERT_NE(test2.Data(), test3.data());
  ASSERT_NE(test2.Data(), test4.data());
  ASSERT_NE(test3.data(), test4.data());

  for (size_t i = 0; i < test2.Size(); i++) {
    ASSERT_EQ(test2.At(i), test4.at(i));
  }
}

TEST(ConstructorMove, Move5) {
  my_space::Vector<int> test1({1, 2, 3, 4, 5});
  my_space::Vector<int> test2(5);
  test2 = std::move(test1);
  vector<int> test3({1, 2, 3, 4, 5});
  vector<int> test4(5);
  test4 = std::move(test3);

  ASSERT_EQ(test1.Size(), 0);
  ASSERT_EQ(test1.Size(), test3.size());
  ASSERT_EQ(test2.Size(), 5);
  ASSERT_EQ(test2.Size(), test4.size());
  ASSERT_NE(test1.Size(), test2.Size());
  ASSERT_NE(test3.size(), test4.size());

  ASSERT_EQ(test1.Capacity(), 0);
  ASSERT_EQ(test1.Capacity(), test3.capacity());
  ASSERT_EQ(test2.Capacity(), 5);
  ASSERT_EQ(test2.Capacity(), test4.capacity());
  ASSERT_NE(test1.Capacity(), test2.Capacity());
  ASSERT_NE(test3.capacity(), test4.capacity());

  ASSERT_EQ(test1.Data(), nullptr);
  ASSERT_EQ(test1.Data(), test3.data());
  ASSERT_NE(test2.Data(), test1.Data());
  ASSERT_NE(test2.Data(), test3.data());
  ASSERT_NE(test2.Data(), test4.data());
  ASSERT_NE(test3.data(), test4.data());

  for (size_t i = 0; i < test2.Size(); i++) {
    ASSERT_EQ(test2.At(i), test4.at(i));
  }
}

TEST(ConstructorMove, Move6) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3), a4("a4", 4), a5("a5", 5);
  my_space::Vector<TestObj> test1({a1, a2, a3, a4, a5});
  my_space::Vector<TestObj> test2(std::move(test1));
  vector<TestObj> test3({a1, a2, a3, a4, a5});
  vector<TestObj> test4(std::move(test3));

  ASSERT_EQ(test1.Size(), 0);
  ASSERT_EQ(test1.Size(), test3.size());
  ASSERT_EQ(test2.Size(), 5);
  ASSERT_EQ(test2.Size(), test4.size());
  ASSERT_NE(test1.Size(), test2.Size());
  ASSERT_NE(test3.size(), test4.size());

  ASSERT_EQ(test1.Capacity(), 0);
  ASSERT_EQ(test1.Capacity(), test3.capacity());
  ASSERT_EQ(test2.Capacity(), 5);
  ASSERT_EQ(test2.Capacity(), test4.capacity());
  ASSERT_NE(test1.Capacity(), test2.Capacity());
  ASSERT_NE(test3.capacity(), test4.capacity());

  ASSERT_EQ(test1.Data(), nullptr);
  ASSERT_EQ(test1.Data(), test3.data());
  ASSERT_NE(test2.Data(), test1.Data());
  ASSERT_NE(test2.Data(), test3.data());
  ASSERT_NE(test2.Data(), test4.data());
  ASSERT_NE(test3.data(), test4.data());

  for (size_t i = 0; i < test2.Size(); i++) {
    ASSERT_EQ(test2.At(i).GetNum(), test4.at(i).GetNum());
  }
}

TEST(ConstructorMove, Move7) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3), a4("a4", 4), a5("a5", 5);
  my_space::Vector<TestObj> test1({a1, a2, a3, a4, a5});
  my_space::Vector<TestObj> test2;
  test2 = std::move(test1);
  vector<TestObj> test3({a1, a2, a3, a4, a5});
  vector<TestObj> test4;
  test4 = std::move(test3);

  ASSERT_EQ(test1.Size(), 0);
  ASSERT_EQ(test1.Size(), test3.size());
  ASSERT_EQ(test2.Size(), 5);
  ASSERT_EQ(test2.Size(), test4.size());
  ASSERT_NE(test1.Size(), test2.Size());
  ASSERT_NE(test3.size(), test4.size());

  ASSERT_EQ(test1.Capacity(), 0);
  ASSERT_EQ(test1.Capacity(), test3.capacity());
  ASSERT_EQ(test2.Capacity(), 5);
  ASSERT_EQ(test2.Capacity(), test4.capacity());
  ASSERT_NE(test1.Capacity(), test2.Capacity());
  ASSERT_NE(test3.capacity(), test4.capacity());

  ASSERT_EQ(test1.Data(), nullptr);
  ASSERT_EQ(test1.Data(), test3.data());
  ASSERT_NE(test2.Data(), test1.Data());
  ASSERT_NE(test2.Data(), test3.data());
  ASSERT_NE(test2.Data(), test4.data());
  ASSERT_NE(test3.data(), test4.data());

  for (size_t i = 0; i < test2.Size(); i++) {
    ASSERT_EQ(test2.At(i).GetNum(), test4.at(i).GetNum());
  }
}

TEST(ConstructorMove, Move8) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3), a4("a4", 4), a5("a5", 5);
  my_space::Vector<TestObj> test1({a1, a2, a3, a4, a5});
  my_space::Vector<TestObj> test2(50);
  test2 = std::move(test1);
  vector<TestObj> test3({a1, a2, a3, a4, a5});
  vector<TestObj> test4(50);
  test4 = std::move(test3);

  ASSERT_EQ(test1.Size(), 0);
  ASSERT_EQ(test1.Size(), test3.size());
  ASSERT_EQ(test2.Size(), 5);
  ASSERT_EQ(test2.Size(), test4.size());
  ASSERT_NE(test1.Size(), test2.Size());
  ASSERT_NE(test3.size(), test4.size());

  ASSERT_EQ(test1.Capacity(), 0);
  ASSERT_EQ(test1.Capacity(), test3.capacity());
  ASSERT_EQ(test2.Capacity(), 5);
  ASSERT_EQ(test2.Capacity(), test4.capacity());
  ASSERT_NE(test1.Capacity(), test2.Capacity());
  ASSERT_NE(test3.capacity(), test4.capacity());

  ASSERT_EQ(test1.Data(), nullptr);
  ASSERT_EQ(test1.Data(), test3.data());
  ASSERT_NE(test2.Data(), test1.Data());
  ASSERT_NE(test2.Data(), test3.data());
  ASSERT_NE(test2.Data(), test4.data());
  ASSERT_NE(test3.data(), test4.data());

  for (size_t i = 0; i < test2.Size(); i++) {
    ASSERT_EQ(test2.At(i).GetNum(), test4.at(i).GetNum());
  }
}

TEST(ConstructorMove, Move9) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3), a4("a4", 4), a5("a5", 5);
  my_space::Vector<TestObj> test1({a1, a2, a3, a4, a5});
  my_space::Vector<TestObj> test2(2);
  test2 = std::move(test1);
  vector<TestObj> test3({a1, a2, a3, a4, a5});
  vector<TestObj> test4(2);
  test4 = std::move(test3);

  ASSERT_EQ(test1.Size(), 0);
  ASSERT_EQ(test1.Size(), test3.size());
  ASSERT_EQ(test2.Size(), 5);
  ASSERT_EQ(test2.Size(), test4.size());
  ASSERT_NE(test1.Size(), test2.Size());
  ASSERT_NE(test3.size(), test4.size());

  ASSERT_EQ(test1.Capacity(), 0);
  ASSERT_EQ(test1.Capacity(), test3.capacity());
  ASSERT_EQ(test2.Capacity(), 5);
  ASSERT_EQ(test2.Capacity(), test4.capacity());
  ASSERT_NE(test1.Capacity(), test2.Capacity());
  ASSERT_NE(test3.capacity(), test4.capacity());

  ASSERT_EQ(test1.Data(), nullptr);
  ASSERT_EQ(test1.Data(), test3.data());
  ASSERT_NE(test2.Data(), test1.Data());
  ASSERT_NE(test2.Data(), test3.data());
  ASSERT_NE(test2.Data(), test4.data());
  ASSERT_NE(test3.data(), test4.data());

  for (size_t i = 0; i < test2.Size(); i++) {
    ASSERT_EQ(test2.At(i).GetNum(), test4.at(i).GetNum());
  }
}

TEST(ConstructorMove, Move10) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3), a4("a4", 4), a5("a5", 5);
  my_space::Vector<TestObj> test1({a1, a2, a3, a4, a5});
  my_space::Vector<TestObj> test2(5);
  test2 = std::move(test1);
  vector<TestObj> test3({a1, a2, a3, a4, a5});
  vector<TestObj> test4(5);
  test4 = std::move(test3);

  ASSERT_EQ(test1.Size(), 0);
  ASSERT_EQ(test1.Size(), test3.size());
  ASSERT_EQ(test2.Size(), 5);
  ASSERT_EQ(test2.Size(), test4.size());
  ASSERT_NE(test1.Size(), test2.Size());
  ASSERT_NE(test3.size(), test4.size());

  ASSERT_EQ(test1.Capacity(), 0);
  ASSERT_EQ(test1.Capacity(), test3.capacity());
  ASSERT_EQ(test2.Capacity(), 5);
  ASSERT_EQ(test2.Capacity(), test4.capacity());
  ASSERT_NE(test1.Capacity(), test2.Capacity());
  ASSERT_NE(test3.capacity(), test4.capacity());

  ASSERT_EQ(test1.Data(), nullptr);
  ASSERT_EQ(test1.Data(), test3.data());
  ASSERT_NE(test2.Data(), test1.Data());
  ASSERT_NE(test2.Data(), test3.data());
  ASSERT_NE(test2.Data(), test4.data());
  ASSERT_NE(test3.data(), test4.data());

  for (size_t i = 0; i < test2.Size(); i++) {
    ASSERT_EQ(test2.At(i).GetNum(), test4.at(i).GetNum());
  }
}

//// At
TEST(MethodsAt, At1) {
  my_space::Vector<int> test1({2, 5, 7, 9, 11});
  std::vector<int> test2({2, 5, 7, 9, 11});
  ASSERT_NE(test1.Data(), test2.data());
  for (size_t i = 0; i < test1.Size() && i < test2.size(); i++) {
    ASSERT_EQ(test1.At(i), test2.at(i));
  }
  EXPECT_THROW(test1.At(-2), out_of_range);
  EXPECT_THROW(test2.at(-2), out_of_range);
  EXPECT_THROW(test1.At(10), out_of_range);
  EXPECT_THROW(test2.at(10), out_of_range);
}

TEST(MethodsAt, At2) {
  my_space::Vector<int> test1;
  std::vector<int> test2;
  EXPECT_THROW(test1.At(0), out_of_range);
  EXPECT_THROW(test2.at(0), out_of_range);
  EXPECT_THROW(test1.At(-2), out_of_range);
  EXPECT_THROW(test2.at(-2), out_of_range);
  EXPECT_THROW(test1.At(10), out_of_range);
  EXPECT_THROW(test2.at(10), out_of_range);
}

TEST(MethodsAt, At3) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3), a4("a4", 4), a5("a5", 5);
  my_space::Vector<TestObj> test1({a1, a2, a3, a4, a5});
  std::vector<TestObj> test2({a1, a2, a3, a4, a5});
  ASSERT_NE(test1.Data(), test2.data());
  for (size_t i = 0; i < test1.Size() && i < test2.size(); i++) {
    ASSERT_EQ(test1.At(i).GetNum(), test2.at(i).GetNum());
  }
  EXPECT_THROW(test1.At(-2), out_of_range);
  EXPECT_THROW(test2.at(-2), out_of_range);
  EXPECT_THROW(test1.At(10), out_of_range);
  EXPECT_THROW(test2.at(10), out_of_range);
}

TEST(MethodsAt, At4) {
  my_space::Vector<TestObj> test1;
  std::vector<TestObj> test2;
  EXPECT_THROW(test1.At(0).GetNum(), out_of_range);
  EXPECT_THROW(test2.at(0).GetNum(), out_of_range);
  EXPECT_THROW(test1.At(-2), out_of_range);
  EXPECT_THROW(test2.at(-2), out_of_range);
  EXPECT_THROW(test1.At(10), out_of_range);
  EXPECT_THROW(test2.at(10), out_of_range);
}

//// Bracket
TEST(OverloadBracket, Bracket) {
  my_space::Vector<int> test1({2, 5, 7, 9, 11});
  std::vector<int> test2({2, 5, 7, 9, 11});
  ASSERT_NE(test1.Data(), test2.data());
  for (size_t i = 0; i < test1.Size() && i < test2.size(); i++) {
    ASSERT_EQ(test1[i], test2[i]);
  }
  for (size_t i = 0; i < test1.Size() && i < test2.size(); i++) {
    test1[i] = i;
    test2[i] = i;
  }
  for (size_t i = 0; i < test1.Size() && i < test2.size(); i++) {
    ASSERT_EQ(test1[i], test2[i]);
  }
}

//// Front
TEST(MethodsFront, Front1) {
  my_space::Vector<int> test1({1, 2, 3, 4, 5});
  std::vector<int> test2({1, 2, 3, 4, 5});
  ASSERT_EQ(test1.Front(), test2.front());
}

TEST(MethodsFront, Front2) {
  my_space::Vector<int> test1({25});
  std::vector<int> test2({25});
  test1.PopBack();
  test2.pop_back();
  ASSERT_EQ(test1.Front(), test2.front());
  ;
}

//// Back
TEST(MethodsBack, Back1) {
  my_space::Vector<int> test1{1, 2, 3, 4, 5};
  std::vector<int> test2{1, 2, 3, 4, 5};
  ASSERT_EQ(test1.Back(), test2.back());
}

TEST(MethodsBack, Back2) {
  my_space::Vector<int> test1({25});
  std::vector<int> test2({25});
  ASSERT_EQ(test1.Back(), test2.back());
}

//// Data
TEST(MethodsData, Data1) {
  my_space::Vector<int> test1({1, 2, 3, 4, 5});
  std::vector<int> test2({1, 2, 3, 4, 5});
  ASSERT_NE(test1.Data(), test2.data());
  ;
  for (size_t i = 0; i < test1.Size() && i < test2.size(); i++) {
    ASSERT_EQ(*(test1.Data() + i), *(test2.data() + i));
  }
}

TEST(MethodsData, Data2) {
  my_space::Vector<int> test1;
  std::vector<int> test2;
  ASSERT_EQ(test1.Data(), nullptr);
  ASSERT_EQ(test1.Data(), test2.data());
}

TEST(MethodsData, Data3) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3), a4("a4", 4), a5("a5", 5);
  my_space::Vector<TestObj> test1({a1, a2, a3, a4, a5});
  std::vector<TestObj> test2({a1, a2, a3, a4, a5});
  ASSERT_NE(test1.Data(), test2.data());
  for (size_t i = 0; i < test1.Size() && i < test2.size(); i++) {
    ASSERT_EQ((test1.Data() + i)->GetNum(), (test2.data() + i)->GetNum());
  }
}

TEST(MethodsData, Data4) {
  my_space::Vector<TestObj> test1;
  std::vector<TestObj> test2;
  ASSERT_EQ(test1.Data(), nullptr);
  ASSERT_EQ(test1.Data(), test2.data());
}

//// Begin
TEST(MethodsBegin, Begin1) {
  my_space::Vector<int> test1({1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
  std::vector<int> test2({1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
  ASSERT_EQ(*(test1.Begin()), *(test2.begin()));
  ASSERT_EQ(*(test1.Begin() + 2), 3);
  ASSERT_EQ(*(test1.Begin() + 6), *(test2.begin() + 6));
  ASSERT_EQ(test1.Begin(), test1.Data());
  ASSERT_NE(test1.Begin(), test1.End());
  ASSERT_NE(test2.begin(), test2.end());
}

TEST(MethodsBegin, Begin2) {
  my_space::Vector<int> test1;
  std::vector<int> test2;
  ASSERT_EQ(test1.Begin(), test1.Data());
  ASSERT_EQ(test1.Begin(), test1.End());
  ASSERT_EQ(test2.begin(), test2.end());
}

TEST(MethodsBegin, Begin3) {
  my_space::Vector<int> test1(5);
  std::vector<int> test2(5);
  ASSERT_EQ(test1.Begin(), test1.Data());
  ASSERT_NE(test1.Begin(), test1.End());
  ASSERT_NE(test2.begin(), test2.end());
}

TEST(MethodsBegin, Begin4) {
  my_space::Vector<int> test1({1});
  std::vector<int> test2({1});
  test1.PopBack();
  test2.pop_back();
  ASSERT_EQ(test1.Begin(), test1.Data());
  ASSERT_EQ(test1.Begin(), test1.End());
  ASSERT_EQ(test2.begin(), test2.end());
}

TEST(MethodsBegin, Begin5) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3), a4("a4", 4), a5("a5", 5);
  my_space::Vector<TestObj> test1({a1, a2, a3, a4, a5});
  std::vector<TestObj> test2({a1, a2, a3, a4, a5});
  ASSERT_EQ((test1.Begin())->GetNum(), (test2.begin())->GetNum());
  ASSERT_EQ((test1.Begin() + 2)->GetNum(), 3);
  ASSERT_EQ((test1.Begin() + 4)->GetNum(), (test2.begin() + 4)->GetNum());
  ASSERT_EQ(test1.Begin(), test1.Data());
  ASSERT_NE(test1.Begin(), test1.End());
  ASSERT_NE(test2.begin(), test2.end());
}

TEST(MethodsBegin, Begin6) {
  my_space::Vector<TestObj> test1;
  std::vector<TestObj> test2;
  ASSERT_EQ(test1.Begin(), test1.Data());
  ASSERT_EQ(test1.Begin(), test1.End());
  ASSERT_EQ(test2.begin(), test2.end());
}

TEST(MethodsBegin, Begin7) {
  my_space::Vector<TestObj> test1(5);
  std::vector<TestObj> test2(5);
  ASSERT_EQ(test1.Begin(), test1.Data());
  ASSERT_NE(test1.Begin(), test1.End());
  ASSERT_NE(test2.begin(), test2.end());
}

TEST(MethodsBegin, Begin8) {
  TestObj a1("a1", 1);
  my_space::Vector<TestObj> test1({a1});
  std::vector<TestObj> test2({a1});
  test1.PopBack();
  test2.pop_back();
  ASSERT_EQ(test1.Begin(), test1.Data());
  ASSERT_EQ(test1.Begin(), test1.End());
  ASSERT_EQ(test2.begin(), test2.end());
}

//// End
TEST(MethodsEnd, End1) {
  my_space::Vector<int> test1({1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
  std::vector<int> test2({1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
  ASSERT_EQ(*(test1.End() - 2), 9);
  ASSERT_EQ(*(test1.End() - 6), *(test2.end() - 6));
}

TEST(MethodsEnd, End2) {
  my_space::Vector<int> test1;
  ASSERT_EQ(test1.End(), nullptr);
  ASSERT_EQ(test1.End(), test1.Begin());
}

TEST(MethodsEnd, End3) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3), a4("a4", 4), a5("a5", 5);
  my_space::Vector<TestObj> test1({a1, a2, a3, a4, a5});
  ASSERT_EQ(test1.End() - 2, test1.Data() + 3);
  ASSERT_EQ(test1.End() - 2, test1.Data() + 3);
}

TEST(MethodsEnd, End4) {
  my_space::Vector<TestObj> test1;
  ASSERT_EQ(test1.End(), nullptr);
  ASSERT_EQ(test1.End(), test1.Begin());
}

//// Empty
TEST(MethodsEmpty, Empty1) {
  my_space::Vector<int> test1;
  std::vector<int> test2;
  test1.PushBack(15);
  test1.PushBack(15);
  test2.push_back(15);
  test2.push_back(15);
  ASSERT_EQ(test1.Empty(), false);
  ASSERT_EQ(test1.Empty(), test2.empty());
}

TEST(MethodsEmpty, Empty2) {
  my_space::Vector<int> test1({25});
  std::vector<int> test2({25});
  test1.PopBack();
  test2.pop_back();
  ASSERT_EQ(test1.Empty(), true);
  ASSERT_EQ(test1.Empty(), test2.empty());
}

TEST(MethodsEmpty, Empty3) {
  my_space::Vector<int> test1;
  std::vector<int> test2;
  ASSERT_EQ(test1.Empty(), true);
  ASSERT_EQ(test1.Empty(), test2.empty());
}

TEST(MethodsEmpty, Empty4) {
  TestObj a1("a1", 1), a2("a2", 2);
  my_space::Vector<TestObj> test1;
  std::vector<TestObj> test2;
  test1.PushBack(a1);
  test1.PushBack(a2);
  test2.push_back(a1);
  test2.push_back(a2);
  ASSERT_EQ(test1.Empty(), false);
  ASSERT_EQ(test1.Empty(), test2.empty());
}

TEST(MethodsEmpty, Empty5) {
  TestObj a1("a1", 1);
  my_space::Vector<TestObj> test1({a1});
  std::vector<TestObj> test2({a1});
  test1.PopBack();
  test2.pop_back();
  ASSERT_EQ(test1.Empty(), true);
  ASSERT_EQ(test1.Empty(), test2.empty());
}

TEST(MethodsEmpty, Empty6) {
  my_space::Vector<TestObj> test1;
  std::vector<TestObj> test2;
  ASSERT_EQ(test1.Empty(), true);
  ASSERT_EQ(test1.Empty(), test2.empty());
}

//// MaxSize
TEST(MethodsMaxSize, MaxSize1) {
  my_space::Vector<int> test1;
  std::vector<int> test2;
  ASSERT_EQ(test1.MaxSize(), test2.max_size());
}

TEST(MethodsMaxSize, MaxSize2) {
  my_space::Vector<TestObj> test1;
  std::vector<TestObj> test2;
  ASSERT_EQ(test1.MaxSize(), test2.max_size());
}

//// Reserve
TEST(MethodsReserve, Reserve1) {
  my_space::Vector<int> test1({1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
  std::vector<int> test2({1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
  ASSERT_EQ(test1.Size(), 10);
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Capacity(), 10);
  ASSERT_EQ(test1.Capacity(), test2.capacity());
  test1.Reserve(50);
  test2.reserve(50);
  ASSERT_EQ(test1.Size(), 10);
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Capacity(), 50);
  ASSERT_EQ(test1.Capacity(), test2.capacity());
  for (int i = 0; i < test1.Size(); ++i) {
    ASSERT_EQ(test1.At(i), test2.at(i));
  }
}

TEST(MethodsReserve, Reserve2) {
  my_space::Vector<int> test1({1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
  std::vector<int> test2({1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
  EXPECT_THROW(test1.Reserve(-50), length_error);
  EXPECT_THROW(test2.reserve(-50), length_error);
  EXPECT_THROW(test1.Reserve(test1.MaxSize() + 1), length_error);
  EXPECT_THROW(test2.reserve(test2.max_size() + 1), length_error);
}

TEST(MethodsReserve, Reserve3) {
  my_space::Vector<int> test1({1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
  std::vector<int> test2({1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
  test1.Reserve(5);
  test2.reserve(5);
  ASSERT_EQ(test1.Size(), 10);
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Capacity(), 10);
  ASSERT_EQ(test1.Capacity(), test2.capacity());
  for (int i = 0; i < test1.Size(); ++i) {
    ASSERT_EQ(test1.At(i), test2.at(i));
  }
}

TEST(MethodsReserve, Reserve4) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3), a4("a4", 4), a5("a5", 5),
      a6("a6", 6), a7("a7", 7), a8("a8", 8), a9("a9", 9), a10("a10", 10);
  my_space::Vector<TestObj> test1({a1, a2, a3, a4, a5, a6, a7, a8, a9, a10});
  std::vector<TestObj> test2({a1, a2, a3, a4, a5, a6, a7, a8, a9, a10});
  ASSERT_EQ(test1.Size(), 10);
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Capacity(), 10);
  ASSERT_EQ(test1.Capacity(), test2.capacity());
  test1.Reserve(50);
  test2.reserve(50);
  ASSERT_EQ(test1.Size(), 10);
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Capacity(), 50);
  ASSERT_EQ(test1.Capacity(), test2.capacity());
  for (size_t i = 0; i < test1.Size(); i++) {
    ASSERT_EQ(test1.At(i).GetNum(), test2.at(i).GetNum());
  }
}

TEST(MethodsReserve, Reserve5) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3), a4("a4", 4), a5("a5", 5),
      a6("a6", 6), a7("a7", 7), a8("a8", 8), a9("a9", 9), a10("a10", 10);
  my_space::Vector<TestObj> test1({a1, a2, a3, a4, a5, a6, a7, a8, a9, a10});
  std::vector<TestObj> test2({a1, a2, a3, a4, a5, a6, a7, a8, a9, a10});
  EXPECT_THROW(test1.Reserve(-50), length_error);
  EXPECT_THROW(test2.reserve(-50), length_error);
  EXPECT_THROW(test1.Reserve(test1.MaxSize() + 1), length_error);
  EXPECT_THROW(test2.reserve(test2.max_size() + 1), length_error);
}

TEST(MethodsReserve, Reserve6) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3), a4("a4", 4), a5("a5", 5),
      a6("a6", 6), a7("a7", 7), a8("a8", 8), a9("a9", 9), a10("a10", 10);
  my_space::Vector<TestObj> test1({a1, a2, a3, a4, a5, a6, a7, a8, a9, a10});
  std::vector<TestObj> test2({a1, a2, a3, a4, a5, a6, a7, a8, a9, a10});
  test1.Reserve(5);
  test2.reserve(5);
  ASSERT_EQ(test1.Size(), 10);
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Capacity(), 10);
  ASSERT_EQ(test1.Capacity(), test2.capacity());
  for (size_t i = 0; i < test1.Size(); i++) {
    ASSERT_EQ(test1.At(i).GetNum(), test2.at(i).GetNum());
  }
}

//// ShrinkToFit
TEST(MethodsShrinkToFit1, ShrinkToFit1) {
  my_space::Vector<int> test1({1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
  std::vector<int> test2({1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
  test1.Reserve(50);
  test2.reserve(50);
  test1.PushBack(11);
  test2.push_back(11);
  ASSERT_EQ(test1.Size(), 11);
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Capacity(), 50);
  ASSERT_EQ(test1.Capacity(), test2.capacity());
  test1.ShrinkToFit();
  test2.shrink_to_fit();
  ASSERT_EQ(test1.Size(), 11);
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Capacity(), 11);
  ASSERT_EQ(test1.Capacity(), test2.capacity());
  for (int i = 0; i < test1.Size(); ++i) {
    ASSERT_EQ(test1.At(i), test2.at(i));
  }
}

TEST(MethodsShrinkToFit1, ShrinkToFit2) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3), a4("a4", 4), a5("a5", 5),
      a6("a6", 6), a7("a7", 7), a8("a8", 8), a9("a9", 9), a10("a10", 10),
      a11("a11", 11);
  my_space::Vector<TestObj> test1({a1, a2, a3, a4, a5, a6, a7, a8, a9, a10});
  std::vector<TestObj> test2({a1, a2, a3, a4, a5, a6, a7, a8, a9, a10});
  test1.Reserve(50);
  test2.reserve(50);
  test1.PushBack(a11);
  test2.push_back(a11);
  ASSERT_EQ(test1.Size(), 11);
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Capacity(), 50);
  ASSERT_EQ(test1.Capacity(), test2.capacity());
  test1.ShrinkToFit();
  test2.shrink_to_fit();
  ASSERT_EQ(test1.Size(), 11);
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Capacity(), 11);
  ASSERT_EQ(test1.Capacity(), test2.capacity());
  for (size_t i = 0; i < test1.Size(); i++) {
    ASSERT_EQ(test1.At(i).GetNum(), test2.at(i).GetNum());
  }
}

//// clear
TEST(MethodsClear, Clear1) {
  my_space::Vector<int> test1({1, 2, 3, 4, 5});
  std::vector<int> test2({1, 2, 3, 4, 5});
  test1.Clear();
  test2.clear();
  ASSERT_EQ(test1.Size(), 0);
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Capacity(), 5);
  ASSERT_EQ(test1.Capacity(), test2.capacity());
}

TEST(MethodsClear, Clear2) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3), a4("a4", 4), a5("a5", 5);
  my_space::Vector<TestObj> test1({a1, a2, a3, a4, a5});
  std::vector<TestObj> test2({a1, a2, a3, a4, a5});
  test1.Clear();
  test2.clear();
  ASSERT_EQ(test1.Size(), 0);
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Capacity(), 5);
  ASSERT_EQ(test1.Capacity(), test2.capacity());
}

//// Insert
TEST(MethodsIter, Insert1) {
  my_space::Vector<int> test1(3);
  std::vector<int> test2(3);
  test1.Reserve(10);
  test2.reserve(10);
  test1.Insert(test1.Begin(), 21);
  test2.insert(test2.begin(), 21);
  ASSERT_EQ(test1.Size(), 4);
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Capacity(), 10);
  ASSERT_EQ(test1.Capacity(), test2.capacity());
  for (int i = 0; i < test1.Size(); ++i) {
    ASSERT_EQ(test1.At(i), test2.at(i));
  }
  EXPECT_THROW(test1.Insert(test1.Begin() - 1, -43), out_of_range);
  EXPECT_THROW(test1.Insert(test1.Begin() + 5, -43), out_of_range);
  EXPECT_THROW(test1.Insert(test1.End() + 1, -43), out_of_range);
}

TEST(MethodsIter, Insert2) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3), a4("a4", 4);
  my_space::Vector<TestObj> test1({a1, a2, a3});
  std::vector<TestObj> test2({a1, a2, a3});
  test1.Reserve(10);
  test2.reserve(10);
  test1.Insert(test1.Begin(), a4);
  test2.insert(test2.begin(), a4);
  ASSERT_EQ(test1.Size(), 4);
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Capacity(), 10);
  ASSERT_EQ(test1.Capacity(), test2.capacity());
  for (int i = 0; i < test1.Size(); ++i) {
    ASSERT_EQ(test1.At(i).GetNum(), test2.at(i).GetNum());
  }
}

TEST(MethodsIter, Insert3) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3), a4("a4", 4);
  my_space::Vector<TestObj> test1({a1, a2, a3});
  std::vector<TestObj> test2({a1, a2, a3});
  test1.Insert(test1.Begin(), a4);
  test2.insert(test2.begin(), a4);
  ASSERT_EQ(test1.Size(), 4);
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Capacity(), 6);
  ASSERT_EQ(test1.Capacity(), test2.capacity());
  for (int i = 0; i < test1.Size(); ++i) {
    ASSERT_EQ(test1.At(i).GetNum(), test2.at(i).GetNum());
  }
  EXPECT_THROW(test1.Insert(test1.Begin() - 1, a1), out_of_range);
  EXPECT_THROW(test1.Insert(test1.Begin() + 6, a1), out_of_range);
  EXPECT_THROW(test1.Insert(test1.End() + 1, a1), out_of_range);
}

TEST(MethodsIter, Insert4) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3), a4("a4", 4);
  my_space::Vector<TestObj> test1({a1, a2, a3});
  std::vector<TestObj> test2({a1, a2, a3});
  test1.Insert(test1.Begin() + 1, a4);
  test2.insert(test2.begin() + 1, a4);
  ASSERT_EQ(test1.Size(), 4);
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Capacity(), 6);
  ASSERT_EQ(test1.Capacity(), test2.capacity());
  for (int i = 0; i < test1.Size(); ++i) {
    ASSERT_EQ(test1.At(i).GetNum(), test2.at(i).GetNum());
  }
}

TEST(MethodsIter, Insert5) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3), a4("a4", 4);
  my_space::Vector<TestObj> test1({a1, a2, a3});
  std::vector<TestObj> test2({a1, a2, a3});
  test1.Insert(test1.End(), a4);
  test2.insert(test2.end(), a4);
  ASSERT_EQ(test1.Size(), 4);
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Capacity(), 6);
  ASSERT_EQ(test1.Capacity(), test2.capacity());
  for (int i = 0; i < test1.Size(); ++i) {
    ASSERT_EQ(test1.At(i).GetNum(), test2.at(i).GetNum());
  }
}

TEST(MethodsIter, Insert6) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3), a4("a4", 4);
  my_space::Vector<TestObj> test1({a1, a2, a3});
  std::vector<TestObj> test2({a1, a2, a3});
  test1.Reserve(6);
  test2.reserve(6);
  test1.Insert(test1.End(), a4);
  test2.insert(test2.end(), a4);
  ASSERT_EQ(test1.Size(), 4);
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Capacity(), 6);
  ASSERT_EQ(test1.Capacity(), test2.capacity());
  for (int i = 0; i < test1.Size(); ++i) {
    ASSERT_EQ(test1.At(i).GetNum(), test2.at(i).GetNum());
  }
}

//// Erase
TEST(MethodsIter, Erase1) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3);
  my_space::Vector<TestObj> test1({a1, a2, a3});
  std::vector<TestObj> test2({a1, a2, a3});
  test1.Erase(test1.Begin());
  test2.erase(test2.begin());
  ASSERT_EQ(test1.Size(), 2);
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Capacity(), 3);
  ASSERT_EQ(test1.Capacity(), test2.capacity());
  for (int i = 0; i < test1.Size() && i < test2.size(); ++i) {
    ASSERT_EQ(test1.At(i).GetNum(), test2.at(i).GetNum());
  }
}

TEST(MethodsIter, Erase2) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3);
  my_space::Vector<TestObj> test1({a1, a2, a3});
  std::vector<TestObj> test2({a1, a2, a3});
  test1.Erase(test1.Begin() + 1);
  test2.erase(test2.begin() + 1);
  ASSERT_EQ(test1.Size(), 2);
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Capacity(), 3);
  ASSERT_EQ(test1.Capacity(), test2.capacity());
  for (int i = 0; i < test1.Size() && i < test2.size(); ++i) {
    ASSERT_EQ(test1.At(i).GetNum(), test2.at(i).GetNum());
  }
}

TEST(MethodsIter, Erase3) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3);
  my_space::Vector<TestObj> test1({a1, a2, a3});
  std::vector<TestObj> test2({a1, a2, a3});
  test1.Erase(test1.Begin() + 2);
  test2.erase(test2.begin() + 2);
  ASSERT_EQ(test1.Size(), 2);
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Capacity(), 3);
  ASSERT_EQ(test1.Capacity(), test2.capacity());
  for (int i = 0; i < test1.Size() && i < test2.size(); ++i) {
    ASSERT_EQ(test1.At(i).GetNum(), test2.at(i).GetNum());
  }
}

TEST(MethodsIter, Erase4) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3);
  my_space::Vector<TestObj> test1({a1, a2, a3});
  std::vector<TestObj> test2({a1, a2, a3});
  test1.Erase(test1.End());
  test2.erase(test2.end());
  ASSERT_EQ(test1.Size(), 2);
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Capacity(), 3);
  ASSERT_EQ(test1.Capacity(), test2.capacity());
  for (int i = 0; i < test1.Size() && i < test2.size(); ++i) {
    ASSERT_EQ(test1.At(i).GetNum(), test2.at(i).GetNum());
  }
}

TEST(MethodsIter, Erase5) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3);
  my_space::Vector<TestObj> test1({a1, a2, a3});
  std::vector<TestObj> test2({a1, a2, a3});
  test1.Erase(test1.End() + 666);
  test2.erase(test2.end() + 666);
  ASSERT_EQ(test1.Size(), 2);
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Capacity(), 3);
  ASSERT_EQ(test1.Capacity(), test2.capacity());
  for (int i = 0; i < test1.Size() && i < test2.size(); ++i) {
    ASSERT_EQ(test1.At(i).GetNum(), test2.at(i).GetNum());
  }
}

//// PushBack
TEST(MethodsPush, PushBack1) {
  my_space::Vector<int> test1;
  std::vector<int> test2;
  test1.PushBack(11);
  test2.push_back(11);
  ASSERT_EQ(test1.Size(), 1);
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Capacity(), 1);
  ASSERT_EQ(test1.Capacity(), test2.capacity());
  for (int i = 0; i < test1.Size() && i < test2.size(); ++i) {
    ASSERT_EQ(test1.At(i), test2.at(i));
  }

  test1.PushBack(12);
  test2.push_back(12);
  ASSERT_EQ(test1.Size(), 2);
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Capacity(), 2);
  ASSERT_EQ(test1.Capacity(), test2.capacity());
  for (int i = 0; i < test1.Size() && i < test2.size(); ++i) {
    ASSERT_EQ(test1.At(i), test2.at(i));
  }

  test1.PushBack(13);
  test2.push_back(13);
  ASSERT_EQ(test1.Size(), 3);
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Capacity(), 4);
  ASSERT_EQ(test1.Capacity(), test2.capacity());
  for (int i = 0; i < test1.Size() && i < test2.size(); ++i) {
    ASSERT_EQ(test1.At(i), test2.at(i));
  }

  test1.Erase(test1.Begin() + 1);
  test2.erase(test2.begin() + 1);
  test1.PushBack(14);
  test2.push_back(14);
  ASSERT_EQ(test1.Size(), 3);
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Capacity(), 4);
  ASSERT_EQ(test1.Capacity(), test2.capacity());
  for (int i = 0; i < test1.Size() && i < test2.size(); ++i) {
    ASSERT_EQ(test1.At(i), test2.at(i));
  }

  test1.Reserve(50);
  test2.reserve(50);
  test1.PushBack(15);
  test2.push_back(15);
  ASSERT_EQ(test1.Size(), 4);
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Capacity(), 50);
  ASSERT_EQ(test1.Capacity(), test2.capacity());
  for (int i = 0; i < test1.Size() && i < test2.size(); ++i) {
    ASSERT_EQ(test1.At(i), test2.at(i));
  }
}

TEST(MethodsPush, PushBack2) {
  my_space::Vector<int> test1({1, 2, 3});
  std::vector<int> test2({1, 2, 3});
  test1.PushBack(11);
  test2.push_back(11);
  ASSERT_EQ(test1.Size(), 4);
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Capacity(), 6);
  ASSERT_EQ(test1.Capacity(), test2.capacity());
  for (int i = 0; i < test1.Size() && i < test2.size(); ++i) {
    ASSERT_EQ(test1.At(i), test2.at(i));
  }

  test1.PushBack(12);
  test2.push_back(12);
  ASSERT_EQ(test1.Size(), 5);
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Capacity(), 6);
  ASSERT_EQ(test1.Capacity(), test2.capacity());
  for (int i = 0; i < test1.Size() && i < test2.size(); ++i) {
    ASSERT_EQ(test1.At(i), test2.at(i));
  }

  test1.PushBack(13);
  test2.push_back(13);
  ASSERT_EQ(test1.Size(), 6);
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Capacity(), 6);
  ASSERT_EQ(test1.Capacity(), test2.capacity());
  for (int i = 0; i < test1.Size() && i < test2.size(); ++i) {
    ASSERT_EQ(test1.At(i), test2.at(i));
  }

  test1.Erase(test1.Begin() + 1);
  test2.erase(test2.begin() + 1);
  test1.PushBack(14);
  test2.push_back(14);
  ASSERT_EQ(test1.Size(), 6);
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Capacity(), 6);
  ASSERT_EQ(test1.Capacity(), test2.capacity());
  for (int i = 0; i < test1.Size() && i < test2.size(); ++i) {
    ASSERT_EQ(test1.At(i), test2.at(i));
  }

  test1.Reserve(50);
  test2.reserve(50);
  test1.PushBack(15);
  test2.push_back(15);
  ASSERT_EQ(test1.Size(), 7);
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Capacity(), 50);
  ASSERT_EQ(test1.Capacity(), test2.capacity());
  for (int i = 0; i < test1.Size() && i < test2.size(); ++i) {
    ASSERT_EQ(test1.At(i), test2.at(i));
  }
}

TEST(MethodsPush, PushBack3) {
  my_space::Vector<int> test1(2);
  std::vector<int> test2(2);
  test1.PushBack(11);
  test2.push_back(11);
  ASSERT_EQ(test1.Size(), 3);
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Capacity(), 4);
  ASSERT_EQ(test1.Capacity(), test2.capacity());
  for (int i = 0; i < test1.Size() && i < test2.size(); ++i) {
    ASSERT_EQ(test1.At(i), test2.at(i));
  }

  test1.PushBack(12);
  test2.push_back(12);
  ASSERT_EQ(test1.Size(), 4);
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Capacity(), 4);
  ASSERT_EQ(test1.Capacity(), test2.capacity());
  for (int i = 0; i < test1.Size() && i < test2.size(); ++i) {
    ASSERT_EQ(test1.At(i), test2.at(i));
  }

  test1.PushBack(13);
  test2.push_back(13);
  ASSERT_EQ(test1.Size(), 5);
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Capacity(), 8);
  ASSERT_EQ(test1.Capacity(), test2.capacity());
  for (int i = 0; i < test1.Size() && i < test2.size(); ++i) {
    ASSERT_EQ(test1.At(i), test2.at(i));
  }
}

TEST(MethodsPush, PushBack4) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3), a4("a4", 4), a5("a5", 5);
  my_space::Vector<TestObj> test1;
  std::vector<TestObj> test2;

  test1.PushBack(a1);
  test2.push_back(a1);
  ASSERT_EQ(test1.Size(), 1);
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Capacity(), 1);
  ASSERT_EQ(test1.Capacity(), test2.capacity());
  for (int i = 0; i < test1.Size() && i < test2.size(); ++i) {
    ASSERT_EQ(test1.At(i).GetNum(), test2.at(i).GetNum());
  }

  test1.PushBack(a2);
  test2.push_back(a2);
  ASSERT_EQ(test1.Size(), 2);
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Capacity(), 2);
  ASSERT_EQ(test1.Capacity(), test2.capacity());
  for (int i = 0; i < test1.Size() && i < test2.size(); ++i) {
    ASSERT_EQ(test1.At(i).GetNum(), test2.at(i).GetNum());
  }

  test1.PushBack(a3);
  test2.push_back(a3);
  ASSERT_EQ(test1.Size(), 3);
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Capacity(), 4);
  ASSERT_EQ(test1.Capacity(), test2.capacity());
  for (int i = 0; i < test1.Size() && i < test2.size(); ++i) {
    ASSERT_EQ(test1.At(i).GetNum(), test2.at(i).GetNum());
  }

  test1.Erase(test1.Begin() + 1);
  test2.erase(test2.begin() + 1);
  test1.PushBack(a4);
  test2.push_back(a4);
  ASSERT_EQ(test1.Size(), 3);
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Capacity(), 4);
  ASSERT_EQ(test1.Capacity(), test2.capacity());
  for (int i = 0; i < test1.Size() && i < test2.size(); ++i) {
    ASSERT_EQ(test1.At(i).GetNum(), test2.at(i).GetNum());
  }

  test1.Reserve(50);
  test2.reserve(50);
  test1.PushBack(a5);
  test2.push_back(a5);
  ASSERT_EQ(test1.Size(), 4);
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Capacity(), 50);
  ASSERT_EQ(test1.Capacity(), test2.capacity());
  for (int i = 0; i < test1.Size() && i < test2.size(); ++i) {
    ASSERT_EQ(test1.At(i).GetNum(), test2.at(i).GetNum());
  }
}

TEST(MethodsPush, PushBack5) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3), a4("a4", 4), a5("a5", 5),
      a6("a6", 6), a7("a7", 7), a8("a8", 8);
  my_space::Vector<TestObj> test1({a1, a2, a3});
  std::vector<TestObj> test2({a1, a2, a3});

  test1.PushBack(a4);
  test2.push_back(a4);
  ASSERT_EQ(test1.Size(), 4);
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Capacity(), 6);
  ASSERT_EQ(test1.Capacity(), test2.capacity());
  for (int i = 0; i < test1.Size() && i < test2.size(); ++i) {
    ASSERT_EQ(test1.At(i).GetNum(), test2.at(i).GetNum());
  }

  test1.PushBack(a5);
  test2.push_back(a5);
  ASSERT_EQ(test1.Size(), 5);
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Capacity(), 6);
  ASSERT_EQ(test1.Capacity(), test2.capacity());
  for (int i = 0; i < test1.Size() && i < test2.size(); ++i) {
    ASSERT_EQ(test1.At(i).GetNum(), test2.at(i).GetNum());
  }

  test1.PushBack(a6);
  test2.push_back(a6);
  ASSERT_EQ(test1.Size(), 6);
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Capacity(), 6);
  ASSERT_EQ(test1.Capacity(), test2.capacity());
  for (int i = 0; i < test1.Size() && i < test2.size(); ++i) {
    ASSERT_EQ(test1.At(i).GetNum(), test2.at(i).GetNum());
  }

  test1.Erase(test1.Begin() + 1);
  test2.erase(test2.begin() + 1);
  test1.PushBack(a7);
  test2.push_back(a7);
  ASSERT_EQ(test1.Size(), 6);
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Capacity(), 6);
  ASSERT_EQ(test1.Capacity(), test2.capacity());
  for (int i = 0; i < test1.Size() && i < test2.size(); ++i) {
    ASSERT_EQ(test1.At(i).GetNum(), test2.at(i).GetNum());
  }

  test1.Reserve(50);
  test2.reserve(50);
  test1.PushBack(a8);
  test2.push_back(a8);
  ASSERT_EQ(test1.Size(), 7);
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Capacity(), 50);
  ASSERT_EQ(test1.Capacity(), test2.capacity());
  for (int i = 0; i < test1.Size() && i < test2.size(); ++i) {
    ASSERT_EQ(test1.At(i).GetNum(), test2.at(i).GetNum());
  }
}

TEST(MethodsPush, PushBack6) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3);
  my_space::Vector<TestObj> test1(2);
  std::vector<TestObj> test2(2);

  test1.PushBack(a1);
  test2.push_back(a1);
  ASSERT_EQ(test1.Size(), 3);
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Capacity(), 4);
  ASSERT_EQ(test1.Capacity(), test2.capacity());
  for (int i = 0; i < test1.Size() && i < test2.size(); ++i) {
    ASSERT_EQ(test1.At(i).GetNum(), test2.at(i).GetNum());
  }

  test1.PushBack(a2);
  test2.push_back(a2);
  ASSERT_EQ(test1.Size(), 4);
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Capacity(), 4);
  ASSERT_EQ(test1.Capacity(), test2.capacity());
  for (int i = 0; i < test1.Size() && i < test2.size(); ++i) {
    ASSERT_EQ(test1.At(i).GetNum(), test2.at(i).GetNum());
  }

  test1.PushBack(a3);
  test2.push_back(a3);
  ASSERT_EQ(test1.Size(), 5);
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Capacity(), 8);
  ASSERT_EQ(test1.Capacity(), test2.capacity());
  for (int i = 0; i < test1.Size() && i < test2.size(); ++i) {
    ASSERT_EQ(test1.At(i).GetNum(), test2.at(i).GetNum());
  }
}

//// PopBack
TEST(MethodsPop, PopBack1) {
  my_space::Vector<int> test1(1);
  std::vector<int> test2(1);

  test1.PopBack();
  test2.pop_back();
  ASSERT_EQ(test1.Size(), 0);
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Capacity(), 1);
  ASSERT_EQ(test1.Capacity(), test2.capacity());
}

TEST(MethodsPop, PopBack2) {
  my_space::Vector<int> test1(10);
  std::vector<int> test2(10);

  test1.PopBack();
  test2.pop_back();
  ASSERT_EQ(test1.Size(), 9);
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Capacity(), 10);
  ASSERT_EQ(test1.Capacity(), test2.capacity());
  for (int i = 0; i < test1.Size() && i < test2.size(); ++i) {
    ASSERT_EQ(test1.At(i), test2.at(i));
  }
}

TEST(MethodsPop, PopBack3) {
  my_space::Vector<int> test1({1, 2, 3});
  std::vector<int> test2({1, 2, 3});

  test1.PopBack();
  test2.pop_back();
  ASSERT_EQ(test1.Size(), 2);
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Capacity(), 3);
  ASSERT_EQ(test1.Capacity(), test2.capacity());
  for (int i = 0; i < test1.Size() && i < test2.size(); ++i) {
    ASSERT_EQ(test1.At(i), test2.at(i));
  }
}

TEST(MethodsPop, PopBack4) {
  my_space::Vector<TestObj> test1(1);
  std::vector<TestObj> test2(1);

  test1.PopBack();
  test2.pop_back();
  ASSERT_EQ(test1.Size(), 0);
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Capacity(), 1);
  ASSERT_EQ(test1.Capacity(), test2.capacity());
}

TEST(MethodsPop, PopBack5) {
  my_space::Vector<TestObj> test1(10);
  std::vector<TestObj> test2(10);

  test1.PopBack();
  test2.pop_back();
  ASSERT_EQ(test1.Size(), 9);
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Capacity(), 10);
  ASSERT_EQ(test1.Capacity(), test2.capacity());
  for (int i = 0; i < test1.Size() && i < test2.size(); ++i) {
    ASSERT_EQ(test1.At(i).GetNum(), test2.at(i).GetNum());
  }
}

TEST(MethodsPop, PopBack6) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3);
  my_space::Vector<TestObj> test1({a1, a2, a3});
  std::vector<TestObj> test2({a1, a2, a3});

  test1.PopBack();
  test2.pop_back();
  ASSERT_EQ(test1.Size(), 2);
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Capacity(), 3);
  ASSERT_EQ(test1.Capacity(), test2.capacity());
  for (int i = 0; i < test1.Size() && i < test2.size(); ++i) {
    ASSERT_EQ(test1.At(i).GetNum(), test2.at(i).GetNum());
  }
}

//// EmplaceBack
TEST(MethodsEmplaceBack, EmplaceBack1) {
  my_space::Vector<int> test1;
  std::vector<int> test2;
  test1.EmplaceBack(11);
  test2.emplace_back(11);
  ASSERT_EQ(test1.Size(), 1);
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Capacity(), 1);
  ASSERT_EQ(test1.Capacity(), test2.capacity());
  for (int i = 0; i < test1.Size() && i < test2.size(); ++i) {
    ASSERT_EQ(test1.At(i), test2.at(i));
  }

  test1.EmplaceBack(12);
  test2.emplace_back(12);
  ASSERT_EQ(test1.Size(), 2);
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Capacity(), 2);
  ASSERT_EQ(test1.Capacity(), test2.capacity());
  for (int i = 0; i < test1.Size() && i < test2.size(); ++i) {
    ASSERT_EQ(test1.At(i), test2.at(i));
  }

  test1.EmplaceBack(13);
  test2.emplace_back(13);
  ASSERT_EQ(test1.Size(), 3);
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Capacity(), 4);
  ASSERT_EQ(test1.Capacity(), test2.capacity());
  for (int i = 0; i < test1.Size() && i < test2.size(); ++i) {
    ASSERT_EQ(test1.At(i), test2.at(i));
  }

  test1.Erase(test1.Begin() + 1);
  test2.erase(test2.begin() + 1);
  test1.EmplaceBack(14);
  test2.emplace_back(14);
  ASSERT_EQ(test1.Size(), 3);
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Capacity(), 4);
  ASSERT_EQ(test1.Capacity(), test2.capacity());
  for (int i = 0; i < test1.Size() && i < test2.size(); ++i) {
    ASSERT_EQ(test1.At(i), test2.at(i));
  }

  test1.Reserve(50);
  test2.reserve(50);
  test1.PushBack(15);
  test2.push_back(15);
  ASSERT_EQ(test1.Size(), 4);
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Capacity(), 50);
  ASSERT_EQ(test1.Capacity(), test2.capacity());
  for (int i = 0; i < test1.Size() && i < test2.size(); ++i) {
    ASSERT_EQ(test1.At(i), test2.at(i));
  }
}

TEST(MethodsEmplaceBack, EmplaceBack2) {
  my_space::Vector<int> test1({1, 2, 3});
  std::vector<int> test2({1, 2, 3});
  test1.EmplaceBack(11);
  test2.emplace_back(11);
  ASSERT_EQ(test1.Size(), 4);
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Capacity(), 6);
  ASSERT_EQ(test1.Capacity(), test2.capacity());
  for (int i = 0; i < test1.Size() && i < test2.size(); ++i) {
    ASSERT_EQ(test1.At(i), test2.at(i));
  }

  test1.EmplaceBack(12);
  test2.emplace_back(12);
  ASSERT_EQ(test1.Size(), 5);
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Capacity(), 6);
  ASSERT_EQ(test1.Capacity(), test2.capacity());
  for (int i = 0; i < test1.Size() && i < test2.size(); ++i) {
    ASSERT_EQ(test1.At(i), test2.at(i));
  }

  test1.EmplaceBack(13);
  test2.emplace_back(13);
  ASSERT_EQ(test1.Size(), 6);
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Capacity(), 6);
  ASSERT_EQ(test1.Capacity(), test2.capacity());
  for (int i = 0; i < test1.Size() && i < test2.size(); ++i) {
    ASSERT_EQ(test1.At(i), test2.at(i));
  }

  test1.Erase(test1.Begin() + 1);
  test2.erase(test2.begin() + 1);
  test1.EmplaceBack(14);
  test2.emplace_back(14);
  ASSERT_EQ(test1.Size(), 6);
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Capacity(), 6);
  ASSERT_EQ(test1.Capacity(), test2.capacity());
  for (int i = 0; i < test1.Size() && i < test2.size(); ++i) {
    ASSERT_EQ(test1.At(i), test2.at(i));
  }

  test1.Reserve(50);
  test2.reserve(50);
  test1.EmplaceBack(15);
  test2.emplace_back(15);
  ASSERT_EQ(test1.Size(), 7);
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Capacity(), 50);
  ASSERT_EQ(test1.Capacity(), test2.capacity());
  for (int i = 0; i < test1.Size() && i < test2.size(); ++i) {
    ASSERT_EQ(test1.At(i), test2.at(i));
  }
}

TEST(MethodsEmplaceBack, EmplaceBack3) {
  my_space::Vector<int> test1(2);
  std::vector<int> test2(2);
  test1.EmplaceBack(11);
  test2.emplace_back(11);
  ASSERT_EQ(test1.Size(), 3);
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Capacity(), 4);
  ASSERT_EQ(test1.Capacity(), test2.capacity());
  for (int i = 0; i < test1.Size() && i < test2.size(); ++i) {
    ASSERT_EQ(test1.At(i), test2.at(i));
  }

  test1.EmplaceBack(12);
  test2.emplace_back(12);
  ASSERT_EQ(test1.Size(), 4);
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Capacity(), 4);
  ASSERT_EQ(test1.Capacity(), test2.capacity());
  for (int i = 0; i < test1.Size() && i < test2.size(); ++i) {
    ASSERT_EQ(test1.At(i), test2.at(i));
  }

  test1.EmplaceBack(13);
  test2.emplace_back(13);
  ASSERT_EQ(test1.Size(), 5);
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Capacity(), 8);
  ASSERT_EQ(test1.Capacity(), test2.capacity());
  for (int i = 0; i < test1.Size() && i < test2.size(); ++i) {
    ASSERT_EQ(test1.At(i), test2.at(i));
  }
}

TEST(MethodsEmplaceBack, EmplaceBack4) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3), a4("a4", 4), a5("a5", 5);
  my_space::Vector<TestObj> test1;
  std::vector<TestObj> test2;

  test1.EmplaceBack(a1);
  test2.emplace_back(a1);
  ASSERT_EQ(test1.Size(), 1);
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Capacity(), 1);
  ASSERT_EQ(test1.Capacity(), test2.capacity());
  for (int i = 0; i < test1.Size() && i < test2.size(); ++i) {
    ASSERT_EQ(test1.At(i).GetNum(), test2.at(i).GetNum());
  }

  test1.EmplaceBack(a2);
  test2.emplace_back(a2);
  ASSERT_EQ(test1.Size(), 2);
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Capacity(), 2);
  ASSERT_EQ(test1.Capacity(), test2.capacity());
  for (int i = 0; i < test1.Size() && i < test2.size(); ++i) {
    ASSERT_EQ(test1.At(i).GetNum(), test2.at(i).GetNum());
  }

  test1.EmplaceBack(a3);
  test2.emplace_back(a3);
  ASSERT_EQ(test1.Size(), 3);
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Capacity(), 4);
  ASSERT_EQ(test1.Capacity(), test2.capacity());
  for (int i = 0; i < test1.Size() && i < test2.size(); ++i) {
    ASSERT_EQ(test1.At(i).GetNum(), test2.at(i).GetNum());
  }

  test1.Erase(test1.Begin() + 1);
  test2.erase(test2.begin() + 1);
  test1.EmplaceBack(a4);
  test2.emplace_back(a4);
  ASSERT_EQ(test1.Size(), 3);
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Capacity(), 4);
  ASSERT_EQ(test1.Capacity(), test2.capacity());
  for (int i = 0; i < test1.Size() && i < test2.size(); ++i) {
    ASSERT_EQ(test1.At(i).GetNum(), test2.at(i).GetNum());
  }

  test1.Reserve(50);
  test2.reserve(50);
  test1.EmplaceBack(a5);
  test2.emplace_back(a5);
  ASSERT_EQ(test1.Size(), 4);
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Capacity(), 50);
  ASSERT_EQ(test1.Capacity(), test2.capacity());
  for (int i = 0; i < test1.Size() && i < test2.size(); ++i) {
    ASSERT_EQ(test1.At(i).GetNum(), test2.at(i).GetNum());
  }
}

TEST(MethodsEmplaceBack, EmplaceBack5) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3), a4("a4", 4), a5("a5", 5),
      a6("a6", 6), a7("a7", 7), a8("a8", 8);
  my_space::Vector<TestObj> test1({a1, a2, a3});
  std::vector<TestObj> test2({a1, a2, a3});

  test1.EmplaceBack(a4);
  test2.emplace_back(a4);
  ASSERT_EQ(test1.Size(), 4);
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Capacity(), 6);
  ASSERT_EQ(test1.Capacity(), test2.capacity());
  for (int i = 0; i < test1.Size() && i < test2.size(); ++i) {
    ASSERT_EQ(test1.At(i).GetNum(), test2.at(i).GetNum());
  }

  test1.EmplaceBack(a5);
  test2.emplace_back(a5);
  ASSERT_EQ(test1.Size(), 5);
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Capacity(), 6);
  ASSERT_EQ(test1.Capacity(), test2.capacity());
  for (int i = 0; i < test1.Size() && i < test2.size(); ++i) {
    ASSERT_EQ(test1.At(i).GetNum(), test2.at(i).GetNum());
  }

  test1.EmplaceBack(a6);
  test2.emplace_back(a6);
  ASSERT_EQ(test1.Size(), 6);
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Capacity(), 6);
  ASSERT_EQ(test1.Capacity(), test2.capacity());
  for (int i = 0; i < test1.Size() && i < test2.size(); ++i) {
    ASSERT_EQ(test1.At(i).GetNum(), test2.at(i).GetNum());
  }

  test1.Erase(test1.Begin() + 1);
  test2.erase(test2.begin() + 1);
  test1.EmplaceBack(a7);
  test2.emplace_back(a7);
  ASSERT_EQ(test1.Size(), 6);
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Capacity(), 6);
  ASSERT_EQ(test1.Capacity(), test2.capacity());
  for (int i = 0; i < test1.Size() && i < test2.size(); ++i) {
    ASSERT_EQ(test1.At(i).GetNum(), test2.at(i).GetNum());
  }

  test1.Reserve(50);
  test2.reserve(50);
  test1.EmplaceBack(a8);
  test2.emplace_back(a8);
  ASSERT_EQ(test1.Size(), 7);
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Capacity(), 50);
  ASSERT_EQ(test1.Capacity(), test2.capacity());
  for (int i = 0; i < test1.Size() && i < test2.size(); ++i) {
    ASSERT_EQ(test1.At(i).GetNum(), test2.at(i).GetNum());
  }
}

TEST(MethodsEmplaceBack, EmplaceBack6) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3);
  my_space::Vector<TestObj> test1(2);
  std::vector<TestObj> test2(2);

  test1.EmplaceBack(a1);
  test2.emplace_back(a1);
  ASSERT_EQ(test1.Size(), 3);
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Capacity(), 4);
  ASSERT_EQ(test1.Capacity(), test2.capacity());
  for (int i = 0; i < test1.Size() && i < test2.size(); ++i) {
    ASSERT_EQ(test1.At(i).GetNum(), test2.at(i).GetNum());
  }

  test1.EmplaceBack(a2);
  test2.emplace_back(a2);
  ASSERT_EQ(test1.Size(), 4);
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Capacity(), 4);
  ASSERT_EQ(test1.Capacity(), test2.capacity());
  for (int i = 0; i < test1.Size() && i < test2.size(); ++i) {
    ASSERT_EQ(test1.At(i).GetNum(), test2.at(i).GetNum());
  }

  test1.EmplaceBack(a3);
  test2.emplace_back(a3);
  ASSERT_EQ(test1.Size(), 5);
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Capacity(), 8);
  ASSERT_EQ(test1.Capacity(), test2.capacity());
  for (int i = 0; i < test1.Size() && i < test2.size(); ++i) {
    ASSERT_EQ(test1.At(i).GetNum(), test2.at(i).GetNum());
  }
}

//// Emplace
TEST(MethodsEmplace, Emplace1) {
  my_space::Vector<int> test1(3);
  std::vector<int> test2(3);
  test1.Reserve(10);
  test2.reserve(10);
  auto iter1 = test1.Emplace(test1.Begin(), 21);
  auto iter2 = test2.emplace(test2.begin(), 21);
  ASSERT_EQ(test1.Size(), 4);
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Capacity(), 10);
  ASSERT_EQ(test1.Capacity(), test2.capacity());
  ASSERT_EQ(iter1, test1.Begin());
  ASSERT_EQ(iter2, test2.begin());
  for (int i = 0; i < test1.Size(); ++i) {
    ASSERT_EQ(test1.At(i), test2.at(i));
  }
  EXPECT_THROW(test1.Insert(test1.Begin() - 1, -43), out_of_range);
  EXPECT_THROW(test1.Insert(test1.Begin() + 5, -43), out_of_range);
  EXPECT_THROW(test1.Insert(test1.End() + 1, -43), out_of_range);
}

TEST(MethodsEmplace, Emplace2) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3), a4("a4", 4);
  my_space::Vector<TestObj> test1({a1, a2, a3});
  std::vector<TestObj> test2({a1, a2, a3});
  test1.Reserve(10);
  test2.reserve(10);
  auto iter1 = test1.Emplace(test1.Begin(), a4);
  auto iter2 = test2.emplace(test2.begin(), a4);
  ASSERT_EQ(test1.Size(), 4);
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Capacity(), 10);
  ASSERT_EQ(test1.Capacity(), test2.capacity());
  ASSERT_EQ(iter1, test1.Begin());
  ASSERT_EQ(iter2, test2.begin());
  for (int i = 0; i < test1.Size(); ++i) {
    ASSERT_EQ(test1.At(i).GetNum(), test2.at(i).GetNum());
  }
}

TEST(MethodsEmplace, Emplace3) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3);
  my_space::Vector<TestObj> test1({a1, a2, a3});
  std::vector<TestObj> test2({a1, a2, a3});
  auto iter1 = test1.Emplace(test1.Begin(), "a5", 5);
  auto iter2 = test2.emplace(test2.begin(), "a5", 5);
  ASSERT_EQ(test1.Size(), 4);
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Capacity(), 6);
  ASSERT_EQ(test1.Capacity(), test2.capacity());
  ASSERT_EQ(iter1, test1.Begin());
  ASSERT_EQ(iter2, test2.begin());
  for (int i = 0; i < test1.Size(); ++i) {
    ASSERT_EQ(test1.At(i).GetNum(), test2.at(i).GetNum());
  }
  EXPECT_THROW(test1.Insert(test1.Begin() - 1, a1), out_of_range);
  EXPECT_THROW(test1.Insert(test1.Begin() + 6, a1), out_of_range);
  EXPECT_THROW(test1.Insert(test1.End() + 1, a1), out_of_range);
}

TEST(MethodsEmplace, Emplace4) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3);
  my_space::Vector<TestObj> test1({a1, a2, a3});
  std::vector<TestObj> test2({a1, a2, a3});
  auto iter1 = test1.Emplace(test1.Begin() + 1, "a5", 5);
  auto iter2 = test2.emplace(test2.begin() + 1, "a5", 5);
  ASSERT_EQ(test1.Size(), 4);
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Capacity(), 6);
  ASSERT_EQ(test1.Capacity(), test2.capacity());
  ASSERT_EQ(iter1, test1.Begin() + 1);
  ASSERT_EQ(iter2, test2.begin() + 1);
  for (int i = 0; i < test1.Size(); ++i) {
    ASSERT_EQ(test1.At(i).GetNum(), test2.at(i).GetNum());
  }
}

TEST(MethodsEmplace, Emplace5) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3);
  my_space::Vector<TestObj> test1({a1, a2, a3});
  std::vector<TestObj> test2({a1, a2, a3});
  auto iter1 = test1.Emplace(test1.End(), "a5", 5);
  auto iter2 = test2.emplace(test2.end(), "a5", 5);
  ASSERT_EQ(test1.Size(), 4);
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Capacity(), 6);
  ASSERT_EQ(test1.Capacity(), test2.capacity());
  ASSERT_NE(iter1, test1.End());
  ASSERT_NE(iter2, test2.end());
  for (int i = 0; i < test1.Size(); ++i) {
    ASSERT_EQ(test1.At(i).GetNum(), test2.at(i).GetNum());
  }
}

TEST(MethodsEmplace, Emplace6) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3);
  my_space::Vector<TestObj> test1({a1, a2, a3});
  std::vector<TestObj> test2({a1, a2, a3});
  test1.Reserve(6);
  test2.reserve(6);
  auto iter1 = test1.Emplace(test1.End(), "a5", 5);
  auto iter2 = test2.emplace(test2.end(), "a5", 5);
  ASSERT_EQ(test1.Size(), 4);
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Capacity(), 6);
  ASSERT_EQ(test1.Capacity(), test2.capacity());
  ASSERT_NE(iter1, test1.End());
  ASSERT_NE(iter2, test2.end());
  for (int i = 0; i < test1.Size(); ++i) {
    ASSERT_EQ(test1.At(i).GetNum(), test2.at(i).GetNum());
  }
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
