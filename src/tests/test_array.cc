#include <gtest/gtest.h>

#include <array>

#include "../containersplus.h"
#include "test_class.h"

using namespace std;

//// ДЕФОЛТНЫЙ КОНСТРУКТОР
TEST(ConstructorDef, Defolt1) {
  my_space::Array<int, 0> test1;
  array<int, 0> test2;
  ASSERT_EQ(test1.Size(), 0);
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), true);
  ASSERT_EQ(test1.Empty(), test2.empty());
}

TEST(ConstructorDef, Defolt2) {
  my_space::Array<int, 4> test1;
  array<int, 4> test2;
  ASSERT_EQ(test1.Size(), 4);
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), false);
  ASSERT_EQ(test1.Empty(), test2.empty());
}

TEST(ConstructorDef, Defolt3) {
  my_space::Array<TestObj, 0> test1;
  array<TestObj, 0> test2;
  ASSERT_EQ(test1.Size(), 0);
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), true);
  ASSERT_EQ(test1.Empty(), test2.empty());
}

TEST(ConstructorDef, Defolt4) {
  my_space::Array<TestObj, 4> test1;
  array<TestObj, 4> test2;
  ASSERT_EQ(test1.Size(), 4);
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), false);
  ASSERT_EQ(test1.Empty(), test2.empty());
}

////  КОНСТРУКТОР ИНИЦИАЛИЗАЦИИ
TEST(ConstructorInit, Init1) {
  my_space::Array<int, 0> test1({});
  array<int, 0> test2({});
  ASSERT_EQ(test1.Size(), 0);
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), true);
  ASSERT_EQ(test1.Empty(), test2.empty());
}

TEST(ConstructorInit, Init2) {
  my_space::Array<int, 4> test1({22, 44, 77, 33});
  array<int, 4> test2({22, 44, 77, 33});
  ASSERT_EQ(test1.Size(), 4);
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), false);
  ASSERT_EQ(test1.Empty(), test2.empty());
  for (ssize_t i = 0; i < test1.Size(); ++i) {
    ASSERT_EQ(test1[i], test2[i]);
  }
}

TEST(ConstructorInit, Init3) {
  my_space::Array<int, 7> test1({22, 44, 77, 33});
  array<int, 7> test2({22, 44, 77, 33});
  ASSERT_EQ(test1.Size(), 7);
  ASSERT_EQ(test1.Size(), test2.size());
  for (ssize_t i = 0; i < test1.Size(); ++i) {
    ASSERT_EQ(test1[i], test2[i]);
  }
}

TEST(ConstructorInit, Init4) {
  my_space::Array<TestObj, 0> test1({});
  array<TestObj, 0> test2({});
  ASSERT_EQ(test1.Size(), 0);
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), true);
  ASSERT_EQ(test1.Empty(), test2.empty());
}

TEST(ConstructorInit, Init5) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3), a4("a4", 4);
  my_space::Array<TestObj, 4> test1({a1, a2, a3, a4});
  array<TestObj, 4> test2({a1, a2, a3, a4});
  ASSERT_EQ(test1.Size(), 4);
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), false);
  ASSERT_EQ(test1.Empty(), test2.empty());
  for (ssize_t i = 0; i < test1.Size(); ++i) {
    ASSERT_EQ(test1[i].GetNum(), test2[i].GetNum());
  }
}

TEST(ConstructorInit, Init6) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3), a4("a4", 4);
  my_space::Array<TestObj, 7> test1({a1, a2, a3, a4});
  array<TestObj, 7> test2({a1, a2, a3, a4});
  ASSERT_EQ(test1.Size(), 7);
  ASSERT_EQ(test1.Size(), test2.size());
  for (ssize_t i = 0; i < test1.Size(); ++i) {
    ASSERT_EQ(test1[i].GetNum(), test2[i].GetNum());
  }
}

//// КОНСТРУКТОР КОПИРОВАНИЯ и ПЕРЕГРУЗКА = КОПИРОВАНИЯ
TEST(ConstructorCopy, Copy1) {
  my_space::Array<int, 4> test1({22, 44, 77, 33});
  my_space::Array<int, 4> test3(test1);
  array<int, 4> test2({22, 44, 77, 33});
  array<int, 4> test4(test2);
  ASSERT_EQ(test1.Size(), 4);
  ASSERT_EQ(test1.Size(), test3.Size());
  ASSERT_EQ(test2.size(), 4);
  ASSERT_EQ(test2.size(), test4.size());
  for (ssize_t i = 0; i < test1.Size(); ++i) {
    ASSERT_EQ(test2[i], test4[i]);
  }
}

TEST(ConstructorCopy, Copy2) {
  my_space::Array<int, 40> test1({22, 44, 77, 33});
  my_space::Array<int, 40> test3(test1);
  array<int, 40> test2({22, 44, 77, 33});
  array<int, 40> test4(test2);
  ASSERT_EQ(test1.Size(), 40);
  ASSERT_EQ(test1.Size(), test3.Size());
  ASSERT_EQ(test2.size(), 40);
  ASSERT_EQ(test2.size(), test4.size());
  for (ssize_t i = 0; i < test1.Size(); ++i) {
    ASSERT_EQ(test2[i], test4[i]);
  }
}

TEST(ConstructorCopy, Copy3) {
  my_space::Array<int, 4> test1({22, 44, 77, 33});
  my_space::Array<int, 4> test3({444, 555, 666, 777});
  array<int, 4> test2({22, 44, 77, 33});
  array<int, 4> test4({444, 555, 666, 777});
  test3 = test1;
  test4 = test2;
  ASSERT_EQ(test1.Size(), 4);
  ASSERT_EQ(test1.Size(), test3.Size());
  ASSERT_EQ(test2.size(), 4);
  ASSERT_EQ(test2.size(), test4.size());
  for (ssize_t i = 0; i < test1.Size(); ++i) {
    ASSERT_EQ(test2[i], test4[i]);
  }
}

TEST(ConstructorCopy, Copy4) {
  my_space::Array<int, 40> test1({22, 44, 77, 33});
  my_space::Array<int, 40> test3;
  array<int, 40> test2({22, 44, 77, 33});
  array<int, 40> test4;
  test3 = test1;
  test4 = test2;
  ASSERT_EQ(test1.Size(), 40);
  ASSERT_EQ(test1.Size(), test3.Size());
  ASSERT_EQ(test2.size(), 40);
  ASSERT_EQ(test2.size(), test4.size());
  for (ssize_t i = 0; i < test1.Size(); ++i) {
    ASSERT_EQ(test2[i], test4[i]);
  }
}

TEST(ConstructorCopy, Copy5) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3), a4("a4", 4), a5("a5", 5);
  my_space::Array<TestObj, 4> test1({a1, a2, a3, a4});
  my_space::Array<TestObj, 4> test3(test1);
  array<TestObj, 4> test2({a1, a2, a3, a4});
  array<TestObj, 4> test4(test2);
  ASSERT_EQ(test1.Size(), 4);
  ASSERT_EQ(test1.Size(), test3.Size());
  ASSERT_EQ(test2.size(), 4);
  ASSERT_EQ(test2.size(), test4.size());
  for (ssize_t i = 0; i < test1.Size(); ++i) {
    ASSERT_EQ(test2[i].GetNum(), test4[i].GetNum());
  }
}

TEST(ConstructorCopy, Copy6) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3), a4("a4", 4), a5("a5", 5);
  my_space::Array<TestObj, 40> test1({a1, a2, a3, a4});
  my_space::Array<TestObj, 40> test3(test1);
  array<TestObj, 40> test2({a1, a2, a3, a4});
  array<TestObj, 40> test4(test2);
  ASSERT_EQ(test1.Size(), 40);
  ASSERT_EQ(test1.Size(), test3.Size());
  ASSERT_EQ(test2.size(), 40);
  ASSERT_EQ(test2.size(), test4.size());
  for (ssize_t i = 0; i < test1.Size(); ++i) {
    ASSERT_EQ(test2[i].GetNum(), test4[i].GetNum());
  }
}

TEST(ConstructorCopy, Copy7) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3), a4("a4", 4), a5("a5", 5);
  my_space::Array<TestObj, 4> test1({a1, a2, a3, a4});
  my_space::Array<TestObj, 4> test3({a5, a4, a3, a2});
  array<TestObj, 4> test2({a1, a2, a3, a4});
  array<TestObj, 4> test4({a5, a4, a3, a2});
  test3 = test1;
  test4 = test2;
  ASSERT_EQ(test1.Size(), 4);
  ASSERT_EQ(test1.Size(), test3.Size());
  ASSERT_EQ(test2.size(), 4);
  ASSERT_EQ(test2.size(), test4.size());
  for (ssize_t i = 0; i < test1.Size(); ++i) {
    ASSERT_EQ(test2[i].GetNum(), test4[i].GetNum());
  }
}

TEST(ConstructorCopy, Copy8) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3), a4("a4", 4), a5("a5", 5);
  my_space::Array<TestObj, 40> test1({a1, a2, a3, a4});
  my_space::Array<TestObj, 40> test3;
  array<TestObj, 40> test2({a1, a2, a3, a4});
  array<TestObj, 40> test4;
  test3 = test1;
  test4 = test2;
  ASSERT_EQ(test1.Size(), 40);
  ASSERT_EQ(test1.Size(), test3.Size());
  ASSERT_EQ(test2.size(), 40);
  ASSERT_EQ(test2.size(), test4.size());
  for (ssize_t i = 0; i < test1.Size(); ++i) {
    ASSERT_EQ(test2[i].GetNum(), test4[i].GetNum());
  }
}

//// КОНСТРУКТОР ПЕРЕМЕЩЕНИЯ и ПЕРЕГРУЗКА = ПЕРЕМЕЩЕНИЯ
TEST(ConstructorMove, Move1) {
  my_space::Array<int, 4> test1({22, 44, 77, 33});
  my_space::Array<int, 4> test3(std::move(test1));
  array<int, 4> test2({22, 44, 77, 33});
  array<int, 4> test4(std::move(test2));
  ASSERT_EQ(test3.Size(), 4);
  ASSERT_EQ(test3.Size(), test4.size());
  for (ssize_t i = 0; i < test3.Size(); ++i) {
    ASSERT_EQ(test3[i], test4[i]);
  }
}

TEST(ConstructorMove, Move2) {
  my_space::Array<int, 40> test1({22, 44, 77, 33});
  my_space::Array<int, 40> test3(std::move(test1));
  array<int, 40> test2({22, 44, 77, 33});
  array<int, 40> test4(std::move(test2));
  ASSERT_EQ(test1.Size(), 40);
  ASSERT_EQ(test1.Size(), test3.Size());
  ASSERT_EQ(test2.size(), 40);
  ASSERT_EQ(test2.size(), test4.size());
  for (ssize_t i = 0; i < test1.Size(); ++i) {
    ASSERT_EQ(test2[i], test4[i]);
  }
}

TEST(ConstructorMove, Move3) {
  my_space::Array<int, 4> test1({22, 44, 77, 33});
  my_space::Array<int, 4> test3({444, 555, 666, 777});
  array<int, 4> test2({22, 44, 77, 33});
  array<int, 4> test4({444, 555, 666, 777});
  test3 = std::move(test1);
  test4 = std::move(test2);
  ASSERT_EQ(test1.Size(), 4);
  ASSERT_EQ(test1.Size(), test3.Size());
  ASSERT_EQ(test2.size(), 4);
  ASSERT_EQ(test2.size(), test4.size());
  for (ssize_t i = 0; i < test1.Size(); ++i) {
    ASSERT_EQ(test2[i], test4[i]);
  }
}

TEST(ConstructorMove, Move4) {
  my_space::Array<int, 40> test1({22, 44, 77, 33});
  my_space::Array<int, 40> test3;
  array<int, 40> test2({22, 44, 77, 33});
  array<int, 40> test4;
  test3 = std::move(test1);
  test4 = std::move(test2);
  ASSERT_EQ(test1.Size(), 40);
  ASSERT_EQ(test1.Size(), test3.Size());
  ASSERT_EQ(test2.size(), 40);
  ASSERT_EQ(test2.size(), test4.size());
  for (ssize_t i = 0; i < test1.Size(); ++i) {
    ASSERT_EQ(test2[i], test4[i]);
  }
}

TEST(ConstructorMove, Move5) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3), a4("a4", 4), a5("a5", 5);
  my_space::Array<TestObj, 4> test1({a1, a2, a3, a4});
  my_space::Array<TestObj, 4> test3(std::move(test1));
  array<TestObj, 4> test2({a1, a2, a3, a4});
  array<TestObj, 4> test4(std::move(test2));
  ASSERT_EQ(test1.Size(), 4);
  ASSERT_EQ(test1.Size(), test3.Size());
  ASSERT_EQ(test2.size(), 4);
  ASSERT_EQ(test2.size(), test4.size());
  for (ssize_t i = 0; i < test1.Size(); ++i) {
    ASSERT_EQ(test2[i].GetNum(), test4[i].GetNum());
  }
}

TEST(ConstructorMove, Move6) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3), a4("a4", 4), a5("a5", 5);
  my_space::Array<TestObj, 40> test1({a1, a2, a3, a4});
  my_space::Array<TestObj, 40> test3(std::move(test1));
  array<TestObj, 40> test2({a1, a2, a3, a4});
  array<TestObj, 40> test4(std::move(test2));
  ASSERT_EQ(test1.Size(), 40);
  ASSERT_EQ(test1.Size(), test3.Size());
  ASSERT_EQ(test2.size(), 40);
  ASSERT_EQ(test2.size(), test4.size());
  for (ssize_t i = 0; i < test1.Size(); ++i) {
    ASSERT_EQ(test2[i].GetNum(), test4[i].GetNum());
  }
}

TEST(ConstructorMove, Move7) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3), a4("a4", 4), a5("a5", 5);
  my_space::Array<TestObj, 4> test1({a1, a2, a3, a4});
  my_space::Array<TestObj, 4> test3({a5, a4, a3, a2});
  array<TestObj, 4> test2({a1, a2, a3, a4});
  array<TestObj, 4> test4({a5, a4, a3, a2});
  test3 = std::move(test1);
  test4 = std::move(test2);
  ASSERT_EQ(test1.Size(), 4);
  ASSERT_EQ(test1.Size(), test3.Size());
  ASSERT_EQ(test2.size(), 4);
  ASSERT_EQ(test2.size(), test4.size());
  for (ssize_t i = 0; i < test1.Size(); ++i) {
    ASSERT_EQ(test2[i].GetNum(), test4[i].GetNum());
  }
}

TEST(ConstructorMove, Move8) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3), a4("a4", 4), a5("a5", 5);
  my_space::Array<TestObj, 40> test1({a1, a2, a3, a4});
  my_space::Array<TestObj, 40> test3;
  array<TestObj, 40> test2({a1, a2, a3, a4});
  array<TestObj, 40> test4;
  test3 = std::move(test1);
  test4 = std::move(test2);
  ASSERT_EQ(test1.Size(), 40);
  ASSERT_EQ(test1.Size(), test3.Size());
  ASSERT_EQ(test2.size(), 40);
  ASSERT_EQ(test2.size(), test4.size());
  for (ssize_t i = 0; i < test1.Size(); ++i) {
    ASSERT_EQ(test2[i].GetNum(), test4[i].GetNum());
  }
}

//// AT
TEST(MethodAt, at1) {
  my_space::Array<int, 5> test1({777, 333, 23, -56, 36});
  array<int, 5> test2({777, 333, 23, -56, 36});
  ASSERT_EQ(test1.Size(), 5);
  ASSERT_EQ(test1.Size(), test2.size());
  for (ssize_t i = 0; i < test1.Size(); ++i) {
    ASSERT_EQ(test1.At(i), test2.at(i));
  }
}

TEST(MethodAt, at2) {
  my_space::Array<int, 10> test1({777, 333, 23, -56, 36});
  array<int, 10> test2({777, 333, 23, -56, 36});
  ASSERT_EQ(test1.Size(), 10);
  ASSERT_EQ(test1.Size(), test2.size());
  for (ssize_t i = 0; i < test1.Size(); ++i) {
    ASSERT_EQ(test1.At(i), test2.at(i));
  }
  EXPECT_THROW(test1.At(10), out_of_range);
  EXPECT_THROW(test2.at(10), out_of_range);
}

TEST(MethodAt, at3) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3), a4("a4", 4), a5("a5", 5);
  my_space::Array<TestObj, 5> test1({a1, a2, a3, a4, a5});
  array<TestObj, 5> test2({a1, a2, a3, a4, a5});
  ASSERT_EQ(test1.Size(), 5);
  ASSERT_EQ(test1.Size(), test2.size());
  for (ssize_t i = 0; i < test1.Size(); ++i) {
    ASSERT_EQ(test1.At(i).GetNum(), test2.at(i).GetNum());
  }
}

TEST(MethodAt, at4) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3), a4("a4", 4), a5("a5", 5);
  my_space::Array<TestObj, 10> test1({a1, a2, a3, a4, a5});
  array<TestObj, 10> test2({a1, a2, a3, a4, a5});
  ASSERT_EQ(test1.Size(), 10);
  ASSERT_EQ(test1.Size(), test2.size());
  for (ssize_t i = 0; i < test1.Size(); ++i) {
    ASSERT_EQ(test1.At(i).GetNum(), test2.at(i).GetNum());
  }
  EXPECT_THROW(test1.At(10).GetNum(), out_of_range);
  EXPECT_THROW(test2.at(10).GetNum(), out_of_range);
}

//// ПЕРЕГРУЗКА []
TEST(OverloadBracket, Bracket1) {
  my_space::Array<int, 5> test1({777, 333, 23, -56, 36});
  array<int, 5> test2({777, 333, 23, -56, 36});
  ASSERT_EQ(test1.Size(), 5);
  ASSERT_EQ(test1.Size(), test2.size());
  for (ssize_t i = 0; i < test1.Size(); ++i) {
    ASSERT_EQ(test1[i], test2[i]);
  }
}

TEST(OverloadBracket, Bracket2) {
  my_space::Array<int, 10> test1({777, 333, 23, -56, 36});
  array<int, 10> test2({777, 333, 23, -56, 36});
  ASSERT_EQ(test1.Size(), 10);
  ASSERT_EQ(test1.Size(), test2.size());
  for (ssize_t i = 0; i < test1.Size(); ++i) {
    ASSERT_EQ(test1[i], test2[i]);
  }
}

TEST(OverloadBracket, Bracket3) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3), a4("a4", 4), a5("a5", 5);
  my_space::Array<TestObj, 5> test1({a1, a2, a3, a4, a5});
  array<TestObj, 5> test2({a1, a2, a3, a4, a5});
  ASSERT_EQ(test1.Size(), 5);
  ASSERT_EQ(test1.Size(), test2.size());
  for (ssize_t i = 0; i < test1.Size(); ++i) {
    ASSERT_EQ(test1[i].GetNum(), test2[i].GetNum());
  }
}

TEST(OverloadBracket, Bracket4) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3), a4("a4", 4), a5("a5", 5);
  my_space::Array<TestObj, 10> test1({a1, a2, a3, a4, a5});
  array<TestObj, 10> test2({a1, a2, a3, a4, a5});
  ASSERT_EQ(test1.Size(), 10);
  ASSERT_EQ(test1.Size(), test2.size());
  for (ssize_t i = 0; i < test1.Size(); ++i) {
    ASSERT_EQ(test1[i].GetNum(), test2[i].GetNum());
  }
}

//// FRONT
TEST(MethodFront, Front1) {
  my_space::Array<int, 5> test1({777, 333, 23, -56, 36});
  array<int, 5> test2({777, 333, 23, -56, 36});
  ASSERT_EQ(test1.Front(), test2.front());
}

TEST(MethodFront, Front2) {
  my_space::Array<int, 10> test1({777, 333, 23, -56, 36});
  array<int, 10> test2({777, 333, 23, -56, 36});
  ASSERT_EQ(test1.Front(), test2.front());
}

//// BACK
TEST(MethodBack, Back1) {
  my_space::Array<int, 5> test1({777, 333, 23, -56, 36});
  array<int, 5> test2({777, 333, 23, -56, 36});
  ASSERT_EQ(test1.Back(), test2.back());
}

//// DATA
TEST(MethodData, Data1) {
  my_space::Array<int, 5> test1({777, 333, 23, -56, 36});
  array<int, 5> test2({777, 333, 23, -56, 36});
  ASSERT_EQ(test1.Data(), &(test1.Front()));
  ASSERT_EQ(test2.data(), &(test2.front()));
}

TEST(MethodData, Data2) {
  my_space::Array<int, 10> test1({777, 333, 23, -56, 36});
  array<int, 10> test2({777, 333, 23, -56, 36});
  ASSERT_EQ(test1.Data(), &(test1.Front()));
  ASSERT_EQ(test2.data(), &(test2.front()));
}

TEST(MethodData, Data3) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3), a4("a4", 4), a5("a5", 5);
  my_space::Array<TestObj, 5> test1({a1, a2, a3, a4, a5});
  array<TestObj, 5> test2({a1, a2, a3, a4, a5});
  ASSERT_EQ(test1.Data(), &(test1.Front()));
  ASSERT_EQ(test2.data(), &(test2.front()));
}

TEST(MethodData, Data4) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3), a4("a4", 4), a5("a5", 5);
  my_space::Array<TestObj, 10> test1({a1, a2, a3, a4, a5});
  array<TestObj, 10> test2({a1, a2, a3, a4, a5});
  ASSERT_EQ(test1.Data(), &(test1.Front()));
  ASSERT_EQ(test2.data(), &(test2.front()));
}

//// BEGIN
TEST(MethodBegin, Begin1) {
  my_space::Array<int, 5> test1({777, 333, 23, -56, 36});
  array<int, 5> test2({777, 333, 23, -56, 36});
  ASSERT_EQ(test1.Begin(), test1.Data());
  ASSERT_EQ(test2.begin(), test2.data());
}

TEST(MethodBegin, Begin2) {
  my_space::Array<int, 10> test1({777, 333, 23, -56, 36});
  array<int, 10> test2({777, 333, 23, -56, 36});
  ASSERT_EQ(test1.Begin(), test1.Data());
  ASSERT_EQ(test2.begin(), test2.data());
}

TEST(MethodBegin, Begin3) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3), a4("a4", 4), a5("a5", 5);
  my_space::Array<TestObj, 5> test1({a1, a2, a3, a4, a5});
  array<TestObj, 5> test2({a1, a2, a3, a4, a5});
  ASSERT_EQ(test1.Begin(), test1.Data());
  ASSERT_EQ(test2.begin(), test2.data());
}

TEST(MethodBegin, Begin4) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3), a4("a4", 4), a5("a5", 5);
  my_space::Array<TestObj, 10> test1({a1, a2, a3, a4, a5});
  array<TestObj, 10> test2({a1, a2, a3, a4, a5});
  ASSERT_EQ(test1.Begin(), test1.Data());
  ASSERT_EQ(test2.begin(), test2.data());
}

//// END
TEST(MethodEnd, End1) {
  my_space::Array<int, 5> test1({777, 333, 23, -56, 36});
  array<int, 5> test2({777, 333, 23, -56, 36});
  ASSERT_EQ(test1.End(), test1.Data() + test1.Size());
  ASSERT_EQ(test2.end(), test2.data() + test2.size());
}

TEST(MethodEnd, End2) {
  my_space::Array<int, 10> test1({777, 333, 23, -56, 36});
  array<int, 10> test2({777, 333, 23, -56, 36});
  ASSERT_EQ(test1.End(), test1.Data() + test1.Size());
  ASSERT_EQ(test2.end(), test2.data() + test2.size());
}

TEST(MethodEnd, End3) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3), a4("a4", 4), a5("a5", 5);
  my_space::Array<TestObj, 5> test1({a1, a2, a3, a4, a5});
  array<TestObj, 5> test2({a1, a2, a3, a4, a5});
  ASSERT_EQ(test1.End(), test1.Data() + test1.Size());
  ASSERT_EQ(test2.end(), test2.data() + test2.size());
}

TEST(MethodEnd, End4) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3), a4("a4", 4), a5("a5", 5);
  my_space::Array<TestObj, 10> test1({a1, a2, a3, a4, a5});
  array<TestObj, 10> test2({a1, a2, a3, a4, a5});
  ASSERT_EQ(test1.End(), test1.Data() + test1.Size());
  ASSERT_EQ(test2.end(), test2.data() + test2.size());
}

//// EMPTY
TEST(MethodEmpty, Empty1) {
  my_space::Array<int, 0> test1;
  array<int, 0> test2;
  ASSERT_EQ(test1.Empty(), true);
  ASSERT_EQ(test1.Empty(), test2.empty());
}

TEST(MethodEmpty, Empty2) {
  my_space::Array<int, 5> test1;
  array<int, 5> test2;
  ASSERT_EQ(test1.Empty(), false);
  ASSERT_EQ(test1.Empty(), test2.empty());
}

TEST(MethodEmpty, Empty3) {
  my_space::Array<int, 5> test1({1, 2, 3, 4, 5});
  array<int, 5> test2({1, 2, 3, 4, 5});
  ASSERT_EQ(test1.Empty(), false);
  ASSERT_EQ(test1.Empty(), test2.empty());
}

TEST(MethodEmpty, Empty4) {
  my_space::Array<int, 50> test1({1, 2, 3, 4, 5});
  array<int, 50> test2({1, 2, 3, 4, 5});
  ASSERT_EQ(test1.Empty(), false);
  ASSERT_EQ(test1.Empty(), test2.empty());
}

TEST(MethodEmpty, Empty5) {
  my_space::Array<TestObj, 0> test1;
  array<TestObj, 0> test2;
  ASSERT_EQ(test1.Empty(), true);
  ASSERT_EQ(test1.Empty(), test2.empty());
}

TEST(MethodEmpty, Empty6) {
  my_space::Array<TestObj, 5> test1;
  array<TestObj, 5> test2;
  ASSERT_EQ(test1.Empty(), false);
  ASSERT_EQ(test1.Empty(), test2.empty());
}

TEST(MethodEmpty, Empty7) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3), a4("a4", 4), a5("a5", 5);
  my_space::Array<TestObj, 5> test1({a1, a2, a3, a4, a5});
  array<TestObj, 5> test2({a1, a2, a3, a4, a5});
  ASSERT_EQ(test1.Empty(), false);
  ASSERT_EQ(test1.Empty(), test2.empty());
}

TEST(MethodEmpty, Empty8) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3), a4("a4", 4), a5("a5", 5);
  my_space::Array<TestObj, 50> test1({a1, a2, a3, a4, a5});
  array<TestObj, 50> test2({a1, a2, a3, a4, a5});
  ASSERT_EQ(test1.Empty(), false);
  ASSERT_EQ(test1.Empty(), test2.empty());
}

//// SIZE
TEST(MethodSize, Size1) {
  my_space::Array<int, 0> test1;
  array<int, 0> test2;
  ASSERT_EQ(test1.Size(), 0);
  ASSERT_EQ(test1.Size(), test2.size());
}

TEST(MethodSize, Size2) {
  my_space::Array<int, 5> test1;
  array<int, 5> test2;
  ASSERT_EQ(test1.Size(), 5);
  ASSERT_EQ(test1.Size(), test2.size());
}

TEST(MethodSize, Size3) {
  my_space::Array<int, 5> test1({1, 2, 3, 4, 5});
  array<int, 5> test2({1, 2, 3, 4, 5});
  ASSERT_EQ(test1.Size(), 5);
  ASSERT_EQ(test1.Size(), test2.size());
}

TEST(MethodSize, Size4) {
  my_space::Array<int, 50> test1({1, 2, 3, 4, 5});
  array<int, 50> test2({1, 2, 3, 4, 5});
  ASSERT_EQ(test1.Size(), 50);
  ASSERT_EQ(test1.Size(), test2.size());
}

TEST(MethodSize, Size5) {
  my_space::Array<TestObj, 0> test1;
  array<TestObj, 0> test2;
  ASSERT_EQ(test1.Size(), 0);
  ASSERT_EQ(test1.Size(), test2.size());
}

TEST(MethodSize, Size6) {
  my_space::Array<TestObj, 5> test1;
  array<TestObj, 5> test2;
  ASSERT_EQ(test1.Size(), 5);
  ASSERT_EQ(test1.Size(), test2.size());
}

TEST(MethodSize, Size7) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3), a4("a4", 4), a5("a5", 5);
  my_space::Array<TestObj, 5> test1({a1, a2, a3, a4, a5});
  array<TestObj, 5> test2({a1, a2, a3, a4, a5});
  ASSERT_EQ(test1.Size(), 5);
  ASSERT_EQ(test1.Size(), test2.size());
}

TEST(MethodSize, Size8) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3), a4("a4", 4), a5("a5", 5);
  my_space::Array<TestObj, 50> test1({a1, a2, a3, a4, a5});
  array<TestObj, 50> test2({a1, a2, a3, a4, a5});
  ASSERT_EQ(test1.Size(), 50);
  ASSERT_EQ(test1.Size(), test2.size());
}

//// MAXSIZE
TEST(MethodMaxSize, MaxSize1) {
  my_space::Array<int, 0> test1;
  array<int, 0> test2;
  ASSERT_EQ(test1.MaxSize(), 0);
  ASSERT_EQ(test1.MaxSize(), test1.Size());
  ASSERT_EQ(test1.MaxSize(), test2.max_size());
}

TEST(MethodMaxSize, MaxSize2) {
  my_space::Array<int, 5> test1;
  array<int, 5> test2;
  ASSERT_EQ(test1.MaxSize(), 5);
  ASSERT_EQ(test1.MaxSize(), test1.Size());
  ASSERT_EQ(test1.MaxSize(), test2.max_size());
}

TEST(MethodMaxSize, MaxSize3) {
  my_space::Array<int, 5> test1({1, 2, 3, 4, 5});
  array<int, 5> test2({1, 2, 3, 4, 5});
  ASSERT_EQ(test1.MaxSize(), 5);
  ASSERT_EQ(test1.MaxSize(), test1.Size());
  ASSERT_EQ(test1.MaxSize(), test2.max_size());
}

TEST(MethodMaxSize, MaxSize4) {
  my_space::Array<int, 50> test1({1, 2, 3, 4, 5});
  array<int, 50> test2({1, 2, 3, 4, 5});
  ASSERT_EQ(test1.MaxSize(), 50);
  ASSERT_EQ(test1.MaxSize(), test1.Size());
  ASSERT_EQ(test1.MaxSize(), test2.max_size());
}

TEST(MethodMaxSize, MaxSize5) {
  my_space::Array<TestObj, 0> test1;
  array<TestObj, 0> test2;
  ASSERT_EQ(test1.MaxSize(), 0);
  ASSERT_EQ(test1.MaxSize(), test1.Size());
  ASSERT_EQ(test1.MaxSize(), test2.max_size());
}

TEST(MethodMaxSize, MaxSize6) {
  my_space::Array<TestObj, 5> test1;
  array<TestObj, 5> test2;
  ASSERT_EQ(test1.MaxSize(), 5);
  ASSERT_EQ(test1.MaxSize(), test1.Size());
  ASSERT_EQ(test1.MaxSize(), test2.max_size());
}

TEST(MethodMaxSize, MaxSize7) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3), a4("a4", 4), a5("a5", 5);
  my_space::Array<TestObj, 5> test1({a1, a2, a3, a4, a5});
  array<TestObj, 5> test2({a1, a2, a3, a4, a5});
  ASSERT_EQ(test1.MaxSize(), 5);
  ASSERT_EQ(test1.MaxSize(), test1.Size());
  ASSERT_EQ(test1.MaxSize(), test2.max_size());
}

TEST(MethodMaxSize1, MaxSize8) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3), a4("a4", 4), a5("a5", 5);
  my_space::Array<TestObj, 50> test1({a1, a2, a3, a4, a5});
  array<TestObj, 50> test2({a1, a2, a3, a4, a5});
  ASSERT_EQ(test1.MaxSize(), 50);
  ASSERT_EQ(test1.MaxSize(), test1.Size());
  ASSERT_EQ(test1.MaxSize(), test2.max_size());
}

//// SWAP
TEST(MethodSwap, Swap1) {
  my_space::Array<int, 5> test1({1, 2, 3, 4, 5});
  my_space::Array<int, 5> test2({12, 23, 34, 45, 56});
  array<int, 5> test3({1, 2, 3, 4, 5});
  array<int, 5> test4({12, 23, 34, 45, 56});
  test1.Swap(test2);
  test3.swap(test4);
  for (size_t i = 0; i < test1.Size(); ++i) {
    ASSERT_EQ(test1.At(i), test3.at(i));
    ASSERT_EQ(test2.At(i), test4.at(i));
  }
}

TEST(MethodSwap, Swap2) {
  my_space::Array<int, 50> test1({1, 2, 3, 4, 5});
  my_space::Array<int, 50> test2({12, 23, 34, 45, 56});
  array<int, 50> test3({1, 2, 3, 4, 5});
  array<int, 50> test4({12, 23, 34, 45, 56});
  test1.Swap(test2);
  test3.swap(test4);
  for (size_t i = 0; i < test1.Size(); ++i) {
    ASSERT_EQ(test1.At(i), test3.at(i));
    ASSERT_EQ(test2.At(i), test4.at(i));
  }
}

TEST(MethodSwap, Swap3) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3), a4("a4", 4), a5("a5", 5);
  my_space::Array<TestObj, 5> test1({a1, a2, a3, a4, a5});
  my_space::Array<TestObj, 5> test2({a3, a4, a5, a4, a3});
  array<TestObj, 5> test3({a1, a2, a3, a4, a5});
  array<TestObj, 5> test4({a3, a4, a5, a4, a3});
  test1.Swap(test2);
  test3.swap(test4);
  for (size_t i = 0; i < test1.Size(); ++i) {
    ASSERT_EQ(test1.At(i).GetNum(), test3.at(i).GetNum());
    ASSERT_EQ(test2.At(i).GetNum(), test4.at(i).GetNum());
  }
}

TEST(MethodSwap, Swap4) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3), a4("a4", 4), a5("a5", 5);
  my_space::Array<TestObj, 50> test1({a1, a2, a3, a4, a5});
  my_space::Array<TestObj, 50> test2({a3, a4, a5, a4, a3});
  array<TestObj, 50> test3({a1, a2, a3, a4, a5});
  array<TestObj, 50> test4({a3, a4, a5, a4, a3});
  test1.Swap(test2);
  test3.swap(test4);
  for (size_t i = 0; i < test1.Size(); ++i) {
    ASSERT_EQ(test1.At(i).GetNum(), test3.at(i).GetNum());
    ASSERT_EQ(test2.At(i).GetNum(), test4.at(i).GetNum());
  }
}

//// FILL
TEST(MethodFill, Fill1) {
  my_space::Array<int, 5> test1({1, 2, 3, 4, 5});
  array<int, 5> test2({1, 2, 3, 4, 5});
  test1.Fill(444);
  test2.fill(444);
  ASSERT_EQ(test1.Size(), test2.size());
  for (size_t i = 0; i < test1.Size(); ++i) {
    ASSERT_EQ(test1.At(i), test2.at(i));
  }
}
TEST(MethodFill, Fill2) {
  my_space::Array<int, 50> test1({1, 2, 3, 4, 5});
  array<int, 50> test2({1, 2, 3, 4, 5});
  test1.Fill(444);
  test2.fill(444);
  ASSERT_EQ(test1.Size(), test2.size());
  for (size_t i = 0; i < test1.Size(); ++i) {
    ASSERT_EQ(test1.At(i), test2.at(i));
  }
}
//// ???
TEST(MethodFill, Fill3) {
  my_space::Array<int, 0> test1;
  array<int, 0> test2;
  test1.Fill(444);
  test2.fill(444);
  ASSERT_EQ(test1.Size(), test2.size());
}

TEST(MethodFill, Fill4) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3), a4("a4", 4), a5("a5", 5);
  my_space::Array<TestObj, 4> test1({a1, a2, a3, a4});
  array<TestObj, 4> test2({a1, a2, a3, a4});
  test1.Fill(a5);
  test2.fill(a5);
  ASSERT_EQ(test1.Size(), test2.size());
  for (size_t i = 0; i < test1.Size(); ++i) {
    ASSERT_EQ(test1.At(i).GetNum(), test2.at(i).GetNum());
  }
}
TEST(MethodFill, Fill5) {
  my_space::Array<int, 50> test1({1, 2, 3, 4, 5});
  array<int, 50> test2({1, 2, 3, 4, 5});
  test1.Fill(444);
  test2.fill(444);
  ASSERT_EQ(test1.Size(), test2.size());
  for (size_t i = 0; i < test1.Size(); ++i) {
    ASSERT_EQ(test1.At(i), test2.at(i));
  }
}
//// ????
TEST(MethodFill, Fill6) {
  my_space::Array<int, 0> test1;
  array<int, 0> test2;
  test1.Fill(444);
  test2.fill(444);
  ASSERT_EQ(test1.Size(), test2.size());
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
