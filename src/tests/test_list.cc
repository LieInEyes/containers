#include <gtest/gtest.h>

#include <list>

#include "../containers.h"
#include "test_class.h"

using namespace std;

//// ДЕФОЛТНЫЙ КОНСТРУКТОР
TEST(ConstructorDef, Default1) {
  my_space::List<int> test1;
  list<int> test2;

  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());
  ASSERT_EQ(test1.Begin(), test1.End());
  ASSERT_EQ(test2.begin(), test2.end());
}

TEST(ConstructorDef, Default2) {
  my_space::List<TestObj> test1;
  list<TestObj> test2;

  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());
  ASSERT_EQ(test1.Begin(), test1.End());
  ASSERT_EQ(test2.begin(), test2.end());
}

//// КОНСТРУКТОР С УКАЗАНИЕМ РАЗМЕРА И ИНИЦИАЛИЗАЦИЕЙ ДЕФОЛТНЫМИ ЗНАЧЕНИЯМИ ТИПА
///КОНТЕЙНЕРА
TEST(ConstructorSize, WithSize1) {
  my_space::List<int> test1(50);
  list<int> test2(50);

  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());
  ASSERT_NE(test1.Begin(), test1.End());
  ASSERT_NE(test2.begin(), test2.end());
  auto iter1 = test1.Begin();
  auto iter2 = test2.begin();
  for (size_t i = 0; i < test1.Size(); ++i, ++iter1, ++iter2) {
    ASSERT_EQ(*iter1, *iter2);
  }
}

TEST(ConstructorSize, WithSize2) {
  my_space::List<int> test1(0);
  list<int> test2(0);

  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());
  ASSERT_EQ(test1.Begin(), test1.End());
  ASSERT_EQ(test2.begin(), test2.end());
}

TEST(ConstructorSize, WithSize3) {
  my_space::List<TestObj> test1(50);
  list<TestObj> test2(50);

  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());
  ASSERT_NE(test1.Begin(), test1.End());
  ASSERT_NE(test2.begin(), test2.end());
  auto iter1 = test1.Begin();
  auto iter2 = test2.begin();
  for (size_t i = 0; i < test1.Size(); ++i, ++iter1, ++iter2) {
    ASSERT_EQ(iter1->GetNum(), iter2->GetNum());
  }
}

TEST(ConstructorSize, WithSize4) {
  my_space::List<TestObj> test1(0);
  list<TestObj> test2(0);

  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());
  ASSERT_EQ(test1.Begin(), test1.End());
  ASSERT_EQ(test2.begin(), test2.end());
}

//// КОНСТРУКТОР С ИНИЦИАЛИЗАЦИЕЙ ЗНАЧЕНИЙ
TEST(ConstructorInit, Init1) {
  my_space::List<int> test1({4, 5, 2});
  list<int> test2({4, 5, 2});

  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());
  ASSERT_EQ(test1.Front(), test2.front());
  ASSERT_EQ(test1.Back(), test2.back());
  ASSERT_NE(test1.Begin(), test1.End());
  ASSERT_NE(test2.begin(), test2.end());

  auto iter1 = test1.Begin();
  auto iter2 = test2.begin();
  for (size_t i = 0; i < test1.Size(); ++i, ++iter1, ++iter2) {
    ASSERT_EQ(*iter1, *iter2);
  }
}

TEST(ConstructorInit, Init2) {
  my_space::List<int> test1({1});
  list<int> test2({1});

  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());
  ASSERT_EQ(test1.Front(), test2.front());
  ASSERT_EQ(test1.Back(), test2.back());
  ASSERT_NE(test1.Begin(), test1.End());
  ASSERT_NE(test2.begin(), test2.end());

  auto iter1 = test1.Begin();
  auto iter2 = test2.begin();
  for (size_t i = 0; i < test1.Size(); ++i, ++iter1, ++iter2) {
    ASSERT_EQ(*iter1, *iter2);
  }
}

TEST(ConstructorInit, Init3) {
  my_space::List<int> test1({});
  list<int> test2({});
  ASSERT_EQ(test1.Size(), 0);
  ASSERT_EQ(test1.Size(), test2.size());

  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());
  ASSERT_EQ(test1.Begin(), test1.End());
  ASSERT_EQ(test2.begin(), test2.end());
}

TEST(ConstructorInit, Init4) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3);
  my_space::List<TestObj> test1({a1, a2, a3});
  list<TestObj> test2({a1, a2, a3});

  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());
  ASSERT_EQ(test1.Front().GetNum(), test2.front().GetNum());
  ASSERT_EQ(test1.Back().GetNum(), test2.back().GetNum());
  ASSERT_NE(test1.Begin(), test1.End());
  ASSERT_NE(test2.begin(), test2.end());

  auto iter1 = test1.Begin();
  auto iter2 = test2.begin();
  for (size_t i = 0; i < test1.Size(); ++i, ++iter1, ++iter2) {
    ASSERT_EQ(iter1->GetNum(), iter2->GetNum());
  }
}

TEST(ConstructorInit, Init5) {
  TestObj a1("a1", 1);
  my_space::List<TestObj> test1({a1});
  list<TestObj> test2({a1});

  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());
  ASSERT_EQ(test1.Front().GetNum(), test2.front().GetNum());
  ASSERT_EQ(test1.Back().GetNum(), test2.back().GetNum());
  ASSERT_NE(test1.Begin(), test1.End());
  ASSERT_NE(test2.begin(), test2.end());

  auto iter1 = test1.Begin();
  auto iter2 = test2.begin();
  for (size_t i = 0; i < test1.Size(); ++i, ++iter1, ++iter2) {
    ASSERT_EQ(iter1->GetNum(), iter2->GetNum());
  }
}

TEST(ConstructorInit, Init6) {
  my_space::List<TestObj> test1({});
  list<TestObj> test2({});

  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());
  ASSERT_EQ(test1.Begin(), test1.End());
  ASSERT_EQ(test2.begin(), test2.end());
}

TEST(ConstructorInit, Init7) {
  my_space::List<int> list_int({777, -3, 1, 2, 2});
  std::list<int> std_list_int({777, -3, 1, 2, 2});
  ASSERT_EQ(list_int.Size(), std_list_int.size());
  ASSERT_EQ(list_int.Front(), std_list_int.front());
  ASSERT_EQ(list_int.Back(), std_list_int.back());
}

TEST(ConstructorInit, Init8) {
  my_space::List<std::string> list_string({"Hello", "I'm", "wifi"});
  std::list<std::string> std_list_string({"Hello", "I'm", "wifi"});
  ASSERT_EQ(list_string.Size(), std_list_string.size());
  ASSERT_EQ(list_string.Front(), std_list_string.front());
  ASSERT_EQ(list_string.Back(), std_list_string.back());
}

//// КОНСТРУКТОР КОПИРОВАНИЕ + ПЕРЕГРУЗКА = КОПИРОВАНИЯ
TEST(ConstructorCopy, Copy1) {
  my_space::List<int> test1({1, 2, 3, 4, 5});
  my_space::List<int> test2(test1);
  list<int> test3({1, 2, 3, 4, 5});
  list<int> test4(test3);

  ASSERT_EQ(test1.Size(), test2.Size());
  ASSERT_EQ(test1.Size(), test4.size());
  ASSERT_EQ(test2.Size(), test3.size());
  ASSERT_EQ(test2.Size(), test4.size());
  ASSERT_EQ(test3.size(), test4.size());

  ASSERT_EQ(test1.Empty(), test3.empty());
  ASSERT_EQ(test2.Empty(), test4.empty());

  ASSERT_EQ(test1.Front(), test3.front());
  ASSERT_EQ(test2.Front(), test4.front());

  ASSERT_EQ(test1.Back(), test3.back());
  ASSERT_EQ(test2.Back(), test4.back());

  ASSERT_NE(test1.Begin(), test2.Begin());
  ASSERT_NE(test1.End(), test2.End());
  ASSERT_NE(test3.begin(), test4.end());
  ASSERT_NE(test3.begin(), test4.end());

  auto iter1 = test1.Begin();
  auto iter2 = test2.Begin();
  auto iter3 = test3.begin();
  auto iter4 = test4.begin();
  for (size_t i = 0; i < test1.Size();
       ++i, ++iter1, ++iter2, ++iter3, ++iter4) {
    ASSERT_EQ(*iter1, *iter2);
    ASSERT_EQ(*iter3, *iter4);
    ASSERT_EQ(*iter2, *iter4);
  }
}

TEST(ConstructorCopy, Copy2) {
  my_space::List<int> test1({1, 2, 3, 4, 5});
  my_space::List<int> test2(50);
  test2 = test1;
  list<int> test3({1, 2, 3, 4, 5});
  list<int> test4(50);
  test4 = test3;

  ASSERT_EQ(test1.Size(), test2.Size());
  ASSERT_EQ(test1.Size(), test4.size());
  ASSERT_EQ(test2.Size(), test3.size());
  ASSERT_EQ(test2.Size(), test4.size());
  ASSERT_EQ(test3.size(), test4.size());

  ASSERT_EQ(test1.Empty(), test3.empty());
  ASSERT_EQ(test2.Empty(), test4.empty());

  ASSERT_EQ(test1.Front(), test3.front());
  ASSERT_EQ(test2.Front(), test4.front());

  ASSERT_EQ(test1.Back(), test3.back());
  ASSERT_EQ(test2.Back(), test4.back());

  ASSERT_NE(test1.Begin(), test2.Begin());
  ASSERT_NE(test1.End(), test2.End());
  ASSERT_NE(test3.begin(), test4.end());
  ASSERT_NE(test3.begin(), test4.end());

  auto iter1 = test1.Begin();
  auto iter2 = test2.Begin();
  auto iter3 = test3.begin();
  auto iter4 = test4.begin();
  for (size_t i = 0; i < test1.Size();
       ++i, ++iter1, ++iter2, ++iter3, ++iter4) {
    ASSERT_EQ(*iter1, *iter2);
    ASSERT_EQ(*iter3, *iter4);
    ASSERT_EQ(*iter2, *iter4);
  }
}

TEST(ConstructorCopy, Copy3) {
  my_space::List<int> test1({1, 2, 3, 4, 5});
  my_space::List<int> test2(2);
  test2 = test1;
  list<int> test3({1, 2, 3, 4, 5});
  list<int> test4(2);
  test4 = test3;

  ASSERT_EQ(test1.Size(), test2.Size());
  ASSERT_EQ(test1.Size(), test4.size());
  ASSERT_EQ(test2.Size(), test3.size());
  ASSERT_EQ(test2.Size(), test4.size());
  ASSERT_EQ(test3.size(), test4.size());

  ASSERT_EQ(test1.Empty(), test3.empty());
  ASSERT_EQ(test2.Empty(), test4.empty());

  ASSERT_EQ(test1.Front(), test3.front());
  ASSERT_EQ(test2.Front(), test4.front());

  ASSERT_EQ(test1.Back(), test3.back());
  ASSERT_EQ(test2.Back(), test4.back());

  ASSERT_NE(test1.Begin(), test2.Begin());
  ASSERT_NE(test1.End(), test2.End());
  ASSERT_NE(test3.begin(), test4.end());
  ASSERT_NE(test3.begin(), test4.end());

  auto iter1 = test1.Begin();
  auto iter2 = test2.Begin();
  auto iter3 = test3.begin();
  auto iter4 = test4.begin();
  for (size_t i = 0; i < test1.Size();
       ++i, ++iter1, ++iter2, ++iter3, ++iter4) {
    ASSERT_EQ(*iter1, *iter2);
    ASSERT_EQ(*iter3, *iter4);
    ASSERT_EQ(*iter2, *iter4);
  }
}

TEST(ConstructorCopy, Copy4) {
  my_space::List<int> test1({1, 2, 3, 4, 5});
  my_space::List<int> test2(5);
  test2 = test1;
  list<int> test3({1, 2, 3, 4, 5});
  list<int> test4(5);
  test4 = test3;

  ASSERT_EQ(test1.Size(), test2.Size());
  ASSERT_EQ(test1.Size(), test4.size());
  ASSERT_EQ(test2.Size(), test3.size());
  ASSERT_EQ(test2.Size(), test4.size());
  ASSERT_EQ(test3.size(), test4.size());

  ASSERT_EQ(test1.Empty(), test3.empty());
  ASSERT_EQ(test2.Empty(), test4.empty());

  ASSERT_EQ(test1.Front(), test3.front());
  ASSERT_EQ(test2.Front(), test4.front());

  ASSERT_EQ(test1.Back(), test3.back());
  ASSERT_EQ(test2.Back(), test4.back());

  ASSERT_NE(test1.Begin(), test2.Begin());
  ASSERT_NE(test1.End(), test2.End());
  ASSERT_NE(test3.begin(), test4.end());
  ASSERT_NE(test3.begin(), test4.end());

  auto iter1 = test1.Begin();
  auto iter2 = test2.Begin();
  auto iter3 = test3.begin();
  auto iter4 = test4.begin();
  for (size_t i = 0; i < test1.Size();
       ++i, ++iter1, ++iter2, ++iter3, ++iter4) {
    ASSERT_EQ(*iter1, *iter2);
    ASSERT_EQ(*iter3, *iter4);
    ASSERT_EQ(*iter2, *iter4);
  }
}

TEST(ConstructorCopy, Copy5) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3), a4("a4", 4), a5("a5", 5);
  my_space::List<TestObj> test1({a1, a2, a3, a4, a5});
  my_space::List<TestObj> test2(test1);
  list<TestObj> test3({a1, a2, a3, a4, a5});
  list<TestObj> test4(test3);

  ASSERT_EQ(test1.Size(), test2.Size());
  ASSERT_EQ(test1.Size(), test4.size());
  ASSERT_EQ(test2.Size(), test3.size());
  ASSERT_EQ(test2.Size(), test4.size());
  ASSERT_EQ(test3.size(), test4.size());

  ASSERT_EQ(test1.Empty(), test3.empty());
  ASSERT_EQ(test2.Empty(), test4.empty());

  ASSERT_EQ(test1.Front().GetNum(), test3.front().GetNum());
  ASSERT_EQ(test2.Front().GetNum(), test4.front().GetNum());

  ASSERT_EQ(test1.Back().GetNum(), test3.back().GetNum());
  ASSERT_EQ(test2.Back().GetNum(), test4.back().GetNum());

  ASSERT_NE(test1.Begin(), test2.Begin());
  ASSERT_NE(test1.End(), test2.End());
  ASSERT_NE(test3.begin(), test4.end());
  ASSERT_NE(test3.begin(), test4.end());

  auto iter1 = test1.Begin();
  auto iter2 = test2.Begin();
  auto iter3 = test3.begin();
  auto iter4 = test4.begin();
  for (size_t i = 0; i < test1.Size();
       ++i, ++iter1, ++iter2, ++iter3, ++iter4) {
    ASSERT_EQ(iter1->GetNum(), iter2->GetNum());
    ASSERT_EQ(iter3->GetNum(), iter4->GetNum());
    ASSERT_EQ(iter2->GetNum(), iter4->GetNum());
  }
}

TEST(ConstructorCopy, Copy6) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3), a4("a4", 4), a5("a5", 5);
  my_space::List<TestObj> test1({a1, a2, a3, a4, a5});
  my_space::List<TestObj> test2(50);
  test2 = test1;
  list<TestObj> test3({a1, a2, a3, a4, a5});
  list<TestObj> test4(50);
  test4 = test3;

  ASSERT_EQ(test1.Size(), test2.Size());
  ASSERT_EQ(test1.Size(), test4.size());
  ASSERT_EQ(test2.Size(), test3.size());
  ASSERT_EQ(test2.Size(), test4.size());
  ASSERT_EQ(test3.size(), test4.size());

  ASSERT_EQ(test1.Empty(), test3.empty());
  ASSERT_EQ(test2.Empty(), test4.empty());

  ASSERT_EQ(test1.Front().GetNum(), test3.front().GetNum());
  ASSERT_EQ(test2.Front().GetNum(), test4.front().GetNum());

  ASSERT_EQ(test1.Back().GetNum(), test3.back().GetNum());
  ASSERT_EQ(test2.Back().GetNum(), test4.back().GetNum());

  ASSERT_NE(test1.Begin(), test2.Begin());
  ASSERT_NE(test1.End(), test2.End());
  ASSERT_NE(test3.begin(), test4.end());
  ASSERT_NE(test3.begin(), test4.end());

  auto iter1 = test1.Begin();
  auto iter2 = test2.Begin();
  auto iter3 = test3.begin();
  auto iter4 = test4.begin();
  for (size_t i = 0; i < test1.Size();
       ++i, ++iter1, ++iter2, ++iter3, ++iter4) {
    ASSERT_EQ(iter1->GetNum(), iter2->GetNum());
    ASSERT_EQ(iter3->GetNum(), iter4->GetNum());
    ASSERT_EQ(iter2->GetNum(), iter4->GetNum());
  }
}

TEST(ConstructorCopy, Copy7) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3), a4("a4", 4), a5("a5", 5);
  my_space::List<TestObj> test1({a1, a2, a3, a4, a5});
  my_space::List<TestObj> test2(2);
  test2 = test1;
  list<TestObj> test3({a1, a2, a3, a4, a5});
  list<TestObj> test4(2);
  test4 = test3;

  ASSERT_EQ(test1.Size(), test2.Size());
  ASSERT_EQ(test1.Size(), test4.size());
  ASSERT_EQ(test2.Size(), test3.size());
  ASSERT_EQ(test2.Size(), test4.size());
  ASSERT_EQ(test3.size(), test4.size());

  ASSERT_EQ(test1.Empty(), test3.empty());
  ASSERT_EQ(test2.Empty(), test4.empty());

  ASSERT_EQ(test1.Front().GetNum(), test3.front().GetNum());
  ASSERT_EQ(test2.Front().GetNum(), test4.front().GetNum());

  ASSERT_EQ(test1.Back().GetNum(), test3.back().GetNum());
  ASSERT_EQ(test2.Back().GetNum(), test4.back().GetNum());

  ASSERT_NE(test1.Begin(), test2.Begin());
  ASSERT_NE(test1.End(), test2.End());
  ASSERT_NE(test3.begin(), test4.end());
  ASSERT_NE(test3.begin(), test4.end());

  auto iter1 = test1.Begin();
  auto iter2 = test2.Begin();
  auto iter3 = test3.begin();
  auto iter4 = test4.begin();
  for (size_t i = 0; i < test1.Size();
       ++i, ++iter1, ++iter2, ++iter3, ++iter4) {
    ASSERT_EQ(iter1->GetNum(), iter2->GetNum());
    ASSERT_EQ(iter3->GetNum(), iter4->GetNum());
    ASSERT_EQ(iter2->GetNum(), iter4->GetNum());
  }
}

TEST(ConstructorCopy, Copy8) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3), a4("a4", 4), a5("a5", 5);
  my_space::List<TestObj> test1({a1, a2, a3, a4, a5});
  my_space::List<TestObj> test2(5);
  test2 = test1;
  list<TestObj> test3({a1, a2, a3, a4, a5});
  list<TestObj> test4(5);
  test4 = test3;

  ASSERT_EQ(test1.Size(), test2.Size());
  ASSERT_EQ(test1.Size(), test4.size());
  ASSERT_EQ(test2.Size(), test3.size());
  ASSERT_EQ(test2.Size(), test4.size());
  ASSERT_EQ(test3.size(), test4.size());

  ASSERT_EQ(test1.Empty(), test3.empty());
  ASSERT_EQ(test2.Empty(), test4.empty());

  ASSERT_EQ(test1.Front().GetNum(), test3.front().GetNum());
  ASSERT_EQ(test2.Front().GetNum(), test4.front().GetNum());

  ASSERT_EQ(test1.Back().GetNum(), test3.back().GetNum());
  ASSERT_EQ(test2.Back().GetNum(), test4.back().GetNum());

  ASSERT_NE(test1.Begin(), test2.Begin());
  ASSERT_NE(test1.End(), test2.End());
  ASSERT_NE(test3.begin(), test4.end());
  ASSERT_NE(test3.begin(), test4.end());

  auto iter1 = test1.Begin();
  auto iter2 = test2.Begin();
  auto iter3 = test3.begin();
  auto iter4 = test4.begin();
  for (size_t i = 0; i < test1.Size();
       ++i, ++iter1, ++iter2, ++iter3, ++iter4) {
    ASSERT_EQ(iter1->GetNum(), iter2->GetNum());
    ASSERT_EQ(iter3->GetNum(), iter4->GetNum());
    ASSERT_EQ(iter2->GetNum(), iter4->GetNum());
  }
}

TEST(ConstructorCopy, Copy9) {
  my_space::List<int> list_int({777, -3, 1, 2, 5});
  my_space::List<int> list_int2(list_int);
  //// std
  std::list<int> std_list_int({777, -3, 1, 2, 5});
  std::list<int> std_list_int2(std_list_int);

  ASSERT_EQ(list_int.Size(), std_list_int.size());
  ASSERT_EQ(list_int.Front(), std_list_int.front());
  ASSERT_EQ(list_int.Back(), std_list_int.back());
  ASSERT_EQ(list_int2.Size(), std_list_int2.size());
  ASSERT_EQ(list_int2.Front(), std_list_int2.front());
  ASSERT_EQ(list_int2.Back(), std_list_int2.back());

  auto iter_int = list_int2.Begin();
  auto iter_int_end = list_int2.End();
  --iter_int_end;

  auto std_iter_int = std_list_int2.begin();
  auto std_iter_int_end = std_list_int2.end();
  --std_iter_int_end;

  ASSERT_EQ(*iter_int, *std_iter_int);
  ASSERT_EQ(*iter_int_end, *std_iter_int_end);
}

TEST(ConstructorCopy, Copy10) {
  my_space::List<std::string> list_string({"am", "I", "Ivan"});
  my_space::List<std::string> list_string2(list_string);
  //// std
  std::list<std::string> std_list_string({"am", "I", "Ivan"});
  std::list<std::string> std_list_string2(std_list_string);

  ASSERT_EQ(list_string.Size(), std_list_string.size());
  ASSERT_EQ(list_string.Front(), std_list_string.front());
  ASSERT_EQ(list_string.Back(), std_list_string.back());
  ASSERT_EQ(list_string2.Size(), std_list_string2.size());
  ASSERT_EQ(list_string2.Front(), std_list_string2.front());
  ASSERT_EQ(list_string2.Back(), std_list_string2.back());

  auto iter = list_string2.Begin();
  auto iter_end = list_string2.End();
  --iter_end;

  auto std_iter = std_list_string2.begin();
  auto std_iter_end = std_list_string2.end();
  --std_iter_end;

  ASSERT_EQ(*iter, *std_iter);
  ASSERT_EQ(*iter_end, *std_iter_end);
}

//// КОНСТРУКТОР ПЕРЕМЕЩЕНИЯ + ПЕРЕГРУЗКА = ПЕРЕМЕЩЕНИЯ
TEST(ConstructorMove, Move1) {
  my_space::List<int> test1({1, 2, 3, 4, 5});
  my_space::List<int> test2(std::move(test1));
  list<int> test3({1, 2, 3, 4, 5});
  list<int> test4(std::move(test3));

  ASSERT_NE(test1.Size(), test2.Size());
  ASSERT_EQ(test1.Size(), test3.size());
  ASSERT_EQ(test2.Size(), test4.size());
  ASSERT_NE(test3.size(), test4.size());

  ASSERT_EQ(test1.Empty(), test3.empty());
  ASSERT_EQ(test2.Empty(), test4.empty());
}

TEST(ConstructorMove, Move2) {
  my_space::List<int> test1({1, 2, 3, 4, 5});
  my_space::List<int> test2;
  test2 = std::move(test1);
  list<int> test3({1, 2, 3, 4, 5});
  list<int> test4;
  test4 = std::move(test3);

  ASSERT_NE(test1.Size(), test2.Size());
  ASSERT_EQ(test1.Size(), test3.size());
  ASSERT_EQ(test2.Size(), test4.size());
  ASSERT_NE(test3.size(), test4.size());

  ASSERT_EQ(test1.Empty(), test3.empty());
  ASSERT_EQ(test2.Empty(), test4.empty());
}

TEST(ConstructorMove, Move3) {
  my_space::List<int> test1({1, 2, 3, 4, 5});
  my_space::List<int> test2(50);
  test2 = std::move(test1);
  list<int> test3({1, 2, 3, 4, 5});
  list<int> test4(50);
  test4 = std::move(test3);

  ASSERT_NE(test1.Size(), test2.Size());
  ASSERT_EQ(test1.Size(), test3.size());
  ASSERT_EQ(test2.Size(), test4.size());
  ASSERT_NE(test3.size(), test4.size());

  ASSERT_EQ(test1.Empty(), test3.empty());
  ASSERT_EQ(test2.Empty(), test4.empty());
}

TEST(ConstructorMove, Move4) {
  my_space::List<int> test1({1, 2, 3, 4, 5});
  my_space::List<int> test2(2);
  test2 = std::move(test1);
  list<int> test3({1, 2, 3, 4, 5});
  list<int> test4(2);
  test4 = std::move(test3);

  ASSERT_NE(test1.Size(), test2.Size());
  ASSERT_EQ(test1.Size(), test3.size());
  ASSERT_EQ(test2.Size(), test4.size());
  ASSERT_NE(test3.size(), test4.size());

  ASSERT_EQ(test1.Empty(), test3.empty());
  ASSERT_EQ(test2.Empty(), test4.empty());
}

TEST(ConstructorMove, Move5) {
  my_space::List<int> test1({1, 2, 3, 4, 5});
  my_space::List<int> test2(5);
  test2 = std::move(test1);
  list<int> test3({1, 2, 3, 4, 5});
  list<int> test4(5);
  test4 = std::move(test3);

  ASSERT_NE(test1.Size(), test2.Size());
  ASSERT_EQ(test1.Size(), test3.size());
  ASSERT_EQ(test2.Size(), test4.size());
  ASSERT_NE(test3.size(), test4.size());

  ASSERT_EQ(test1.Empty(), test3.empty());
  ASSERT_EQ(test2.Empty(), test4.empty());
}

TEST(ConstructorMove, Move6) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3), a4("a4", 4), a5("a5", 5);
  my_space::List<TestObj> test1({a1, a2, a3, a4, a5});
  my_space::List<TestObj> test2(std::move(test1));
  list<TestObj> test3({a1, a2, a3, a4, a5});
  list<TestObj> test4(std::move(test3));

  ASSERT_NE(test1.Size(), test2.Size());
  ASSERT_EQ(test1.Size(), test3.size());
  ASSERT_EQ(test2.Size(), test4.size());
  ASSERT_NE(test3.size(), test4.size());

  ASSERT_EQ(test1.Empty(), test3.empty());
  ASSERT_EQ(test2.Empty(), test4.empty());
}

TEST(ConstructorMove, Move7) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3), a4("a4", 4), a5("a5", 5);
  my_space::List<TestObj> test1({a1, a2, a3, a4, a5});
  my_space::List<TestObj> test2;
  test2 = std::move(test1);
  list<TestObj> test3({a1, a2, a3, a4, a5});
  list<TestObj> test4;
  test4 = std::move(test3);

  ASSERT_NE(test1.Size(), test2.Size());
  ASSERT_EQ(test1.Size(), test3.size());
  ASSERT_EQ(test2.Size(), test4.size());
  ASSERT_NE(test3.size(), test4.size());

  ASSERT_EQ(test1.Empty(), test3.empty());
  ASSERT_EQ(test2.Empty(), test4.empty());
}

TEST(ConstructorMove, Move8) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3), a4("a4", 4), a5("a5", 5);
  my_space::List<TestObj> test1({a1, a2, a3, a4, a5});
  my_space::List<TestObj> test2(50);
  test2 = std::move(test1);
  list<TestObj> test3({a1, a2, a3, a4, a5});
  list<TestObj> test4(50);
  test4 = std::move(test3);

  ASSERT_NE(test1.Size(), test2.Size());
  ASSERT_EQ(test1.Size(), test3.size());
  ASSERT_EQ(test2.Size(), test4.size());
  ASSERT_NE(test3.size(), test4.size());

  ASSERT_EQ(test1.Empty(), test3.empty());
  ASSERT_EQ(test2.Empty(), test4.empty());
}

TEST(ConstructorMove, Move9) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3), a4("a4", 4), a5("a5", 5);
  my_space::List<TestObj> test1({a1, a2, a3, a4, a5});
  my_space::List<TestObj> test2(2);
  test2 = std::move(test1);
  list<TestObj> test3({a1, a2, a3, a4, a5});
  list<TestObj> test4(2);
  test4 = std::move(test3);

  ASSERT_NE(test1.Size(), test2.Size());
  ASSERT_EQ(test1.Size(), test3.size());
  ASSERT_EQ(test2.Size(), test4.size());
  ASSERT_NE(test3.size(), test4.size());

  ASSERT_EQ(test1.Empty(), test3.empty());
  ASSERT_EQ(test2.Empty(), test4.empty());
}

TEST(ConstructorMove, Move10) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3), a4("a4", 4), a5("a5", 5);
  my_space::List<TestObj> test1({a1, a2, a3, a4, a5});
  my_space::List<TestObj> test2(5);
  test2 = std::move(test1);
  list<TestObj> test3({a1, a2, a3, a4, a5});
  list<TestObj> test4(5);
  test4 = std::move(test3);

  ASSERT_NE(test1.Size(), test2.Size());
  ASSERT_EQ(test1.Size(), test3.size());
  ASSERT_EQ(test2.Size(), test4.size());
  ASSERT_NE(test3.size(), test4.size());

  ASSERT_EQ(test1.Empty(), test3.empty());
  ASSERT_EQ(test2.Empty(), test4.empty());
}

TEST(ConstructorMove, Move11) {
  my_space::List<int> list_int({777, -3, 1, 2, 5});
  my_space::List<int> list_int2(std::move(list_int));
  //// std
  std::list<int> std_list_int({777, -3, 1, 2, 5});
  std::list<int> std_list_int2(std::move(std_list_int));

  ASSERT_EQ(list_int.Size(), std_list_int.size());
  ////    std::cout << std_list_int.front() << std::endl; not segmantion
  /// standart
  ASSERT_EQ(list_int2.Size(), std_list_int2.size());
  ASSERT_EQ(list_int2.Front(), std_list_int2.front());
  ASSERT_EQ(list_int2.Back(), std_list_int2.back());

  auto iter_int = list_int2.Begin();
  auto iter_int_end = list_int2.End();
  --iter_int_end;

  auto std_iter_int = std_list_int2.begin();
  auto std_iter_int_end = std_list_int2.end();
  --std_iter_int_end;

  ASSERT_EQ(*iter_int, *std_iter_int);
  ASSERT_EQ(*iter_int_end, *std_iter_int_end);
}

TEST(ConstructorMove, Move12) {
  my_space::List<std::string> list_string({"am", "I", "Ivan"});
  my_space::List<std::string> list_string2(std::move(list_string));
  //// std
  std::list<std::string> std_list_string({"am", "I", "Ivan"});
  std::list<std::string> std_list_string2(std::move(std_list_string));

  ASSERT_EQ(list_string.Size(), std_list_string.size());
  ////  std::cout << std_list_string.front() << std::endl; segmantion in
  /// standart
  ASSERT_EQ(list_string2.Size(), std_list_string2.size());
  ASSERT_EQ(list_string2.Front(), std_list_string2.front());
  ASSERT_EQ(list_string2.Back(), std_list_string2.back());

  auto iter = list_string2.Begin();
  auto iter_end = list_string2.End();
  --iter_end;

  auto std_iter = std_list_string2.begin();
  auto std_iter_end = std_list_string2.end();
  --std_iter_end;

  ASSERT_EQ(*iter, *std_iter);
  ASSERT_EQ(*iter_end, *std_iter_end);
}

//// ListIterator
TEST(ListIterator, ListIterator1) {
  my_space::List<int> test1({1, 2, 3, 4, 5});
  list<int> test2({1, 2, 3, 4, 5});

  my_space::List<int>::iterator iter1;
  list<int>::iterator iter2;

  my_space::List<int>::iterator iter3(test1.Begin());
  list<int>::iterator iter4(test2.begin());
  for (size_t i = 0; i < test1.Size(); ++i, ++iter3, ++iter4) {
    ASSERT_EQ(*iter3, *iter4);
    ASSERT_EQ(*iter3 == *iter4, true);
    ASSERT_EQ(*iter3 != *iter4, false);
  }

  my_space::List<int>::iterator iter5 = test1.Begin();
  my_space::List<int>::iterator iter51 = test1.Begin();
  my_space::List<int>::const_iterator iter52 = test1.CBegin();
  list<int>::iterator iter6 = test2.begin();
  list<int>::iterator iter61 = test2.begin();
  list<int>::const_iterator iter62 = test2.cbegin();
  for (size_t i = 0; i < test1.Size();
       ++i, iter5++, iter6++, iter51++, iter52++, iter61++, iter62++) {
    ASSERT_EQ(*iter5, *iter6);
    ASSERT_EQ(*iter5 == *iter6, true);
    ASSERT_EQ(*iter5 != *iter6, false);
    ASSERT_EQ(iter5 == iter51, true);
    ASSERT_EQ(iter5 == iter52, true);
    ASSERT_EQ(iter6 == iter61, true);
    ASSERT_EQ(iter6 == iter62, true);
    ASSERT_EQ(iter5 != iter51, false);
    ASSERT_EQ(iter5 != iter52, false);
    ASSERT_EQ(iter6 != iter61, false);
    ASSERT_EQ(iter6 != iter62, false);
  }

  my_space::List<int>::iterator iter7 = std::move(test1.Begin());
  list<int>::iterator iter8 = std::move(test2.begin());
  for (size_t i = 0; i < test1.Size(); ++i, ++iter7, ++iter8) {
    ASSERT_EQ(*iter7, *iter8);
  }

  my_space::List<int>::iterator iter9 = test1.Begin();
  my_space::List<int>::iterator iter91 = std::move(iter9);
  list<int>::iterator iter10 = test2.begin();
  list<int>::iterator iter101 = std::move(iter10);
  for (size_t i = 0; i < test1.Size(); ++i, ++iter91, ++iter101) {
    ASSERT_EQ(*iter91, *iter101);
  }

  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3);
  my_space::List<TestObj> test11({a1, a2, a3});
  my_space::List<TestObj>::iterator iter11 = test11.Begin();
  my_space::List<TestObj>::iterator iter111 = std::move(iter11);
  list<TestObj> test21({a1, a2, a3});
  list<TestObj>::iterator iter12 = test21.begin();
  list<TestObj>::iterator iter121 = std::move(iter12);

  for (size_t i = 0; i < test11.Size(); ++i, ++iter111, ++iter121) {
    ASSERT_EQ(iter111->GetNum(), iter121->GetNum());
  }
}

//// ListConstIterator
TEST(ListConstIterator, ListConstIterator) {
  my_space::List<int> test1({1, 2, 3, 4, 5});
  list<int> test2({1, 2, 3, 4, 5});

  my_space::List<int>::const_iterator iter3(test1.CBegin());
  list<int>::const_iterator iter4(test2.cbegin());
  for (size_t i = 0; i < test1.Size(); ++i, ++iter3, ++iter4) {
    ASSERT_EQ(*iter3, *iter4);
    ASSERT_EQ(*iter3 == *iter4, true);
    ASSERT_EQ(*iter3 != *iter4, false);
  }

  my_space::List<int>::const_iterator iter5 = test1.CBegin();
  my_space::List<int>::const_iterator iter51 = test1.CBegin();
  my_space::List<int>::iterator iter52 = test1.Begin();
  list<int>::const_iterator iter6 = test2.cbegin();
  list<int>::const_iterator iter61 = test2.cbegin();
  list<int>::iterator iter62 = test2.begin();
  for (size_t i = 0; i < test1.Size();
       ++i, iter5++, iter6++, iter51++, iter52++, iter61++, iter62++) {
    ASSERT_EQ(*iter5, *iter6);
    ASSERT_EQ(*iter5 == *iter6, true);
    ASSERT_EQ(*iter5 != *iter6, false);
    ASSERT_EQ(iter5 == iter51, true);
    ASSERT_EQ(iter5 == iter52, true);
    ASSERT_EQ(iter6 == iter61, true);
    ASSERT_EQ(iter6 == iter62, true);
    ASSERT_EQ(iter5 != iter51, false);
    ASSERT_EQ(iter5 != iter52, false);
    ASSERT_EQ(iter6 != iter61, false);
    ASSERT_EQ(iter6 != iter62, false);
  }

  my_space::List<int>::iterator iter7 = std::move(test1.Begin());
  list<int>::iterator iter8 = std::move(test2.begin());
  for (size_t i = 0; i < test1.Size(); ++i, ++iter7, ++iter8) {
    ASSERT_EQ(*iter7, *iter8);
  }

  my_space::List<int>::iterator iter9 = test1.Begin();
  my_space::List<int>::iterator iter91 = std::move(iter9);
  list<int>::iterator iter10 = test2.begin();
  list<int>::iterator iter101 = std::move(iter10);
  for (size_t i = 0; i < test1.Size(); ++i, ++iter91, ++iter101) {
    ASSERT_EQ(*iter91, *iter101);
  }

  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3);
  my_space::List<TestObj> test11({a1, a2, a3});
  my_space::List<TestObj>::iterator iter11 = test11.Begin();
  my_space::List<TestObj>::iterator iter111 = std::move(iter11);
  list<TestObj> test21({a1, a2, a3});
  list<TestObj>::iterator iter12 = test21.begin();
  list<TestObj>::iterator iter121 = std::move(iter12);

  for (size_t i = 0; i < test11.Size(); ++i, ++iter111, ++iter121) {
    ASSERT_EQ(iter111->GetNum(), iter121->GetNum());
  }
}

//// MAXSIZE
TEST(MaxSize, MaxSize1) {
  my_space::List<int> test_int1;
  list<int> test_int2;
  ASSERT_EQ(test_int1.MaxSize(), test_int2.max_size());

  my_space::List<string> test_string1;
  list<string> test_string2;
  ASSERT_EQ(test_int1.MaxSize(), test_int2.max_size());

  my_space::List<TestObj> test_test_obj1;
  list<TestObj> test_test_obj2;
  ASSERT_EQ(test_int1.MaxSize(), test_int2.max_size());
}

//// CLEAR
TEST(Clear, Clear1) {
  my_space::List<int> test1({5, 1, 2, 3, 7});
  test1.Clear();
  std::list<int> test2({5, 1, 2, 3, 7});
  test2.clear();
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());
}

TEST(Clear, Clear2) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3);
  my_space::List<TestObj> test1({a1, a2, a3});
  std::list<TestObj> test2({a1, a2, a3});
  test1.Clear();
  test2.clear();

  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());
}

//// INSERT
TEST(Insert, Insert1) {
  my_space::List<int> test1;
  std::list<int> test2;
  auto iter_my_space = test1.Insert(test1.Begin(), 444);
  auto iter_std = test2.insert(test2.begin(), 444);
  ASSERT_EQ(*iter_my_space, *iter_std);

  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());

  auto iter1 = test1.Begin();
  auto iter2 = test2.begin();
  for (size_t i = 0; i < test1.Size(); ++i, ++iter1, ++iter2) {
    ASSERT_EQ(*iter1, *iter2);
  }
}

TEST(Insert, Insert2) {
  my_space::List<int> test1;
  std::list<int> test2;
  auto iter_my_space = test1.Insert(test1.End(), 444);
  auto iter_std = test2.insert(test2.end(), 444);
  ASSERT_EQ(*iter_my_space, *iter_std);

  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());

  auto iter1 = test1.Begin();
  auto iter2 = test2.begin();
  for (size_t i = 0; i < test1.Size(); ++i, ++iter1, ++iter2) {
    ASSERT_EQ(*iter1, *iter2);
  }
}

TEST(Insert, Insert3) {
  my_space::List<int> test1({23});
  std::list<int> test2({23});
  auto iter_my_space = test1.Insert(test1.Begin(), 444);
  auto iter_std = test2.insert(test2.begin(), 444);
  ASSERT_EQ(*iter_my_space, *iter_std);

  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());

  auto iter1 = test1.Begin();
  auto iter2 = test2.begin();
  for (size_t i = 0; i < test1.Size(); ++i, ++iter1, ++iter2) {
    ASSERT_EQ(*iter1, *iter2);
  }
}

TEST(Insert, Insert4) {
  my_space::List<int> test1({23});
  std::list<int> test2({23});
  auto iter_my_space = test1.Insert(test1.End(), 444);
  auto iter_std = test2.insert(test2.end(), 444);
  ASSERT_EQ(*iter_my_space, *iter_std);

  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());

  auto iter1 = test1.Begin();
  auto iter2 = test2.begin();
  for (size_t i = 0; i < test1.Size(); ++i, ++iter1, ++iter2) {
    ASSERT_EQ(*iter1, *iter2);
  }
}

TEST(Insert, Insert5) {
  my_space::List<int> test1({23, 47, -23});
  std::list<int> test2({23, 47, -23});
  auto iter1 = test1.Begin();
  auto iter2 = test2.begin();
  ++iter1;
  ++iter2;
  auto iter_my_space = test1.Insert(iter1, 444);
  auto iter_std = test2.insert(iter2, 444);
  ASSERT_EQ(*iter_my_space, *iter_std);

  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());

  auto iter3 = test1.Begin();
  auto iter4 = test2.begin();
  for (size_t i = 0; i < test1.Size(); ++i, ++iter3, ++iter4) {
    ASSERT_EQ(*iter3, *iter4);
  }
}

TEST(Insert, Insert6) {
  my_space::List<int> test1({23, 47, -23});
  std::list<int> test2({23, 47, -23});
  auto iter1 = test1.Begin();
  auto iter2 = test2.begin();
  ++iter1;
  ++iter1;
  ++iter2;
  ++iter2;
  auto iter_my_space = test1.Insert(iter1, 444);
  auto iter_std = test2.insert(iter2, 444);
  ASSERT_EQ(*iter_my_space, *iter_std);

  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());

  auto iter3 = test1.Begin();
  auto iter4 = test2.begin();
  for (size_t i = 0; i < test1.Size(); ++i, ++iter3, ++iter4) {
    ASSERT_EQ(*iter3, *iter4);
  }
}

TEST(Insert, Insert7) {
  my_space::List<int> test1({23, 47, -23});
  std::list<int> test2({23, 47, -23});
  auto iter_my_space = test1.Insert(test1.End(), 444);
  auto iter_std = test2.insert(test2.end(), 444);
  ASSERT_EQ(*iter_my_space, *iter_std);

  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());

  auto iter1 = test1.Begin();
  auto iter2 = test2.begin();
  for (size_t i = 0; i < test1.Size(); ++i, ++iter1, ++iter2) {
    ASSERT_EQ(*iter1, *iter2);
  }
}

TEST(Insert, Insert8) {
  TestObj a1("a1", 1);
  my_space::List<TestObj> test1;
  std::list<TestObj> test2;
  auto iter_my_space = test1.Insert(test1.Begin(), a1);
  auto iter_std = test2.insert(test2.begin(), a1);
  ASSERT_EQ(iter_my_space->GetNum(), iter_std->GetNum());

  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());

  auto iter1 = test1.Begin();
  auto iter2 = test2.begin();
  for (size_t i = 0; i < test1.Size(); ++i, ++iter1, ++iter2) {
    ASSERT_EQ(iter1->GetNum(), iter2->GetNum());
  }
}

TEST(Insert, Insert9) {
  TestObj a1("a1", 1);
  my_space::List<TestObj> test1;
  std::list<TestObj> test2;
  auto iter_my_space = test1.Insert(test1.End(), a1);
  auto iter_std = test2.insert(test2.end(), a1);
  ASSERT_EQ(iter_my_space->GetNum(), iter_std->GetNum());

  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());

  auto iter1 = test1.Begin();
  auto iter2 = test2.begin();
  for (size_t i = 0; i < test1.Size(); ++i, ++iter1, ++iter2) {
    ASSERT_EQ(iter1->GetNum(), iter2->GetNum());
  }
}

TEST(Insert, Insert10) {
  TestObj a1("a1", 1), a2("a2", 2);
  my_space::List<TestObj> test1({a1});
  std::list<TestObj> test2({a1});
  auto iter_my_space = test1.Insert(test1.Begin(), a2);
  auto iter_std = test2.insert(test2.begin(), a2);
  ASSERT_EQ(iter_my_space->GetNum(), iter_std->GetNum());

  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());

  auto iter1 = test1.Begin();
  auto iter2 = test2.begin();
  for (size_t i = 0; i < test1.Size(); ++i, ++iter1, ++iter2) {
    ASSERT_EQ(iter1->GetNum(), iter2->GetNum());
  }
}

TEST(Insert, Insert11) {
  TestObj a1("a1", 1), a2("a2", 2);
  my_space::List<TestObj> test1({a1});
  std::list<TestObj> test2({a1});
  auto iter_my_space = test1.Insert(test1.End(), a2);
  auto iter_std = test2.insert(test2.end(), a2);
  ASSERT_EQ(iter_my_space->GetNum(), iter_std->GetNum());

  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());

  auto iter1 = test1.Begin();
  auto iter2 = test2.begin();
  for (size_t i = 0; i < test1.Size(); ++i, ++iter1, ++iter2) {
    ASSERT_EQ(iter1->GetNum(), iter2->GetNum());
  }
}

TEST(Insert, Insert12) {
  TestObj a1("a1", 1), a2("a3", 3), a3("a3", 3), a4("a4", 4);
  my_space::List<TestObj> test1({a1, a2, a3});
  std::list<TestObj> test2({a1, a2, a3});
  auto iter1 = test1.Begin();
  auto iter2 = test2.begin();
  ++iter1;
  ++iter2;
  auto iter_my_space = test1.Insert(iter1, a4);
  auto iter_std = test2.insert(iter2, a4);
  ASSERT_EQ(iter_my_space->GetNum(), iter_std->GetNum());

  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());

  auto iter3 = test1.Begin();
  auto iter4 = test2.begin();
  for (size_t i = 0; i < test1.Size(); ++i, ++iter3, ++iter4) {
    ASSERT_EQ(iter3->GetNum(), iter4->GetNum());
  }
}

TEST(Insert, Insert13) {
  TestObj a1("a1", 1), a2("a3", 3), a3("a3", 3), a4("a4", 4);
  my_space::List<TestObj> test1({a1, a2, a3});
  std::list<TestObj> test2({a1, a2, a3});
  auto iter1 = test1.Begin();
  auto iter2 = test2.begin();
  ++iter1;
  ++iter1;
  ++iter2;
  ++iter2;
  auto iter_my_space = test1.Insert(iter1, a4);
  auto iter_std = test2.insert(iter2, a4);
  ASSERT_EQ(iter_my_space->GetNum(), iter_std->GetNum());

  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());

  auto iter3 = test1.Begin();
  auto iter4 = test2.begin();
  for (size_t i = 0; i < test1.Size(); ++i, ++iter3, ++iter4) {
    ASSERT_EQ(iter3->GetNum(), iter4->GetNum());
  }
}

TEST(Insert, Insert14) {
  TestObj a1("a1", 1), a2("a3", 3), a3("a3", 3), a4("a4", 4);
  my_space::List<TestObj> test1({a1, a2, a3});
  std::list<TestObj> test2({a1, a2, a3});

  auto iter_my_space = test1.Insert(test1.End(), a4);
  auto iter_std = test2.insert(test2.end(), a4);
  ASSERT_EQ(iter_my_space->GetNum(), iter_std->GetNum());

  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());

  auto iter1 = test1.Begin();
  auto iter2 = test2.begin();
  for (size_t i = 0; i < test1.Size(); ++i, ++iter1, ++iter2) {
    ASSERT_EQ(iter1->GetNum(), iter2->GetNum());
  }
}

TEST(Insert, Insert15) {
  my_space::List<int> my_space_list_int({5, 1, 2, 3, 7});
  auto iter = my_space_list_int.Begin();
  auto iter_insert = my_space_list_int.Insert(iter, 77);
  //// std
  std::list<int> std_list_int({5, 1, 2, 3, 7});
  auto std_iter = std_list_int.begin();
  auto std_iter_insert = std_list_int.insert(std_iter, 77);

  ASSERT_EQ(*iter_insert, *std_iter_insert);

  ++iter;
  ++std_iter;
  auto iter_insert2 = my_space_list_int.Insert(iter, 171);
  auto std_iter_insert2 = std_list_int.insert(std_iter, 171);
  ASSERT_EQ(*iter_insert2, *std_iter_insert2);
}

//// ERASE
TEST(Erase, Erase1) {
  my_space::List<int> test1({1, 2, 3});
  std::list<int> test2({1, 2, 3});

  auto iter_my_space = test1.Begin();
  auto iter_std = test2.begin();

  test1.Erase(iter_my_space);
  test2.erase(iter_std);

  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());

  auto iter1 = test1.Begin();
  auto iter2 = test2.begin();
  for (size_t i = 0; i < test1.Size(); ++i, ++iter1, ++iter2) {
    ASSERT_EQ(*iter1, *iter2);
  }
}

TEST(Erase, Erase2) {
  my_space::List<int> test1({1, 2, 3});
  std::list<int> test2({1, 2, 3});

  auto iter_my_space = test1.Begin();
  auto iter_std = test2.begin();
  ++iter_my_space;
  ++iter_std;

  test1.Erase(iter_my_space);
  test2.erase(iter_std);

  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());

  auto iter1 = test1.Begin();
  auto iter2 = test2.begin();
  for (size_t i = 0; i < test1.Size(); ++i, ++iter1, ++iter2) {
    ASSERT_EQ(*iter1, *iter2);
  }
}

TEST(Erase, Erase3) {
  my_space::List<int> test1({1, 2, 3});
  std::list<int> test2({1, 2, 3});

  auto iter_my_space = test1.Begin();
  auto iter_std = test2.begin();
  ++iter_my_space;
  ++iter_my_space;
  ++iter_std;
  ++iter_std;

  test1.Erase(iter_my_space);
  test2.erase(iter_std);

  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());

  auto iter1 = test1.Begin();
  auto iter2 = test2.begin();
  for (size_t i = 0; i < test1.Size(); ++i, ++iter1, ++iter2) {
    ASSERT_EQ(*iter1, *iter2);
  }
}

TEST(Erase, Erase4) {
  TestObj a1("a1", 1), a2("a3", 3), a3("a3", 3);
  my_space::List<TestObj> test1({a1, a2, a3});
  std::list<TestObj> test2({a1, a2, a3});

  auto iter_my_space = test1.Begin();
  auto iter_std = test2.begin();

  test1.Erase(iter_my_space);
  test2.erase(iter_std);

  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());

  auto iter1 = test1.Begin();
  auto iter2 = test2.begin();
  for (size_t i = 0; i < test1.Size(); ++i, ++iter1, ++iter2) {
    ASSERT_EQ(iter1->GetNum(), iter2->GetNum());
  }
}

TEST(Erase, Erase5) {
  TestObj a1("a1", 1), a2("a3", 3), a3("a3", 3);
  my_space::List<TestObj> test1({a1, a2, a3});
  std::list<TestObj> test2({a1, a2, a3});

  auto iter_my_space = test1.Begin();
  auto iter_std = test2.begin();
  ++iter_my_space;
  ++iter_std;

  test1.Erase(iter_my_space);
  test2.erase(iter_std);

  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());

  auto iter1 = test1.Begin();
  auto iter2 = test2.begin();
  for (size_t i = 0; i < test1.Size(); ++i, ++iter1, ++iter2) {
    ASSERT_EQ(iter1->GetNum(), iter2->GetNum());
  }
}

TEST(Erase, Erase6) {
  TestObj a1("a1", 1), a2("a3", 3), a3("a3", 3);
  my_space::List<TestObj> test1({a1, a2, a3});
  std::list<TestObj> test2({a1, a2, a3});

  auto iter_my_space = test1.Begin();
  auto iter_std = test2.begin();
  ++iter_my_space;
  ++iter_my_space;
  ++iter_std;
  ++iter_std;

  test1.Erase(iter_my_space);
  test2.erase(iter_std);

  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());

  auto iter1 = test1.Begin();
  auto iter2 = test2.begin();
  for (size_t i = 0; i < test1.Size(); ++i, ++iter1, ++iter2) {
    ASSERT_EQ(iter1->GetNum(), iter2->GetNum());
  }
}

TEST(Erase, Erase7) {
  my_space::List<std::string> list_string({"am", "u", "kkk"});
  std::list<std::string> std_list_string({"am", "u", "kkk"});

  auto iter = list_string.Begin();
  auto std_iter = std_list_string.begin();

  ++iter;
  ++std_iter;

  list_string.Erase(iter);
  std_list_string.erase(std_iter);

  // after erase

  auto iter_after_erase = list_string.Begin();
  auto std_iter_after_erase = std_list_string.begin();

  ++iter_after_erase;
  ++std_iter_after_erase;

  ASSERT_EQ(*iter_after_erase, *std_iter_after_erase);

  list_string.Erase(iter_after_erase);
  std_list_string.erase(std_iter_after_erase);

  //// after erase 2

  auto iter_after_erase2 = list_string.Begin();
  auto std_iter_after_erase2 = std_list_string.begin();

  ASSERT_EQ(*iter_after_erase2, *std_iter_after_erase2);

  list_string.Erase(iter_after_erase2);
  std_list_string.erase(std_iter_after_erase2);

  ASSERT_TRUE(list_string.Empty());
  ASSERT_TRUE(std_list_string.empty());
}

//// если у стандарта ещё раз вызвать инкремент будет segmantion
TEST(Erase, Erase8) {
  my_space::List<std::string> list_string({"am", "I", "ttt"});
  std::list<std::string> std_list_string({"am", "I", "ttt"});

  auto iter = list_string.Begin();
  auto std_iter = std_list_string.begin();

  ++iter;
  ++iter;
  ++std_iter;
  ++std_iter;

  list_string.Erase(iter);
  std_list_string.erase(std_iter);

  //// after erase
  auto iter_after_erase = list_string.Begin();
  auto std_iter_after_erase = list_string.Begin();

  ++iter_after_erase;
  ++std_iter_after_erase;

  ASSERT_EQ(*iter_after_erase, *std_iter_after_erase);
}

//// PUSHBACK
TEST(PushBack, PushBack1) {
  my_space::List<int> test1;
  std::list<int> test2;

  test1.PushBack(444);
  test2.push_back(444);

  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());

  auto iter1 = test1.Begin();
  auto iter2 = test2.begin();
  for (size_t i = 0; i < test1.Size(); ++i, ++iter1, ++iter2) {
    ASSERT_EQ(*iter1, *iter2);
  }
}

TEST(PushBack, PushBack2) {
  my_space::List<int> test1(50);
  std::list<int> test2(50);

  test1.PushBack(444);
  test2.push_back(444);

  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());

  auto iter1 = test1.Begin();
  auto iter2 = test2.begin();
  for (size_t i = 0; i < test1.Size(); ++i, ++iter1, ++iter2) {
    ASSERT_EQ(*iter1, *iter2);
  }
}

TEST(PushBack, PushBack3) {
  my_space::List<int> test1({1, 2, 3});
  std::list<int> test2({1, 2, 3});

  test1.PushBack(444);
  test2.push_back(444);

  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());

  auto iter1 = test1.Begin();
  auto iter2 = test2.begin();
  for (size_t i = 0; i < test1.Size(); ++i, ++iter1, ++iter2) {
    ASSERT_EQ(*iter1, *iter2);
  }
}

TEST(PushBack, PushBack4) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3), a4("a4", 4);
  my_space::List<TestObj> test1({a1, a2, a3});
  std::list<TestObj> test2({a1, a2, a3});

  test1.PushBack(a4);
  test2.push_back(a4);

  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());

  auto iter1 = test1.Begin();
  auto iter2 = test2.begin();
  for (size_t i = 0; i < test1.Size(); ++i, ++iter1, ++iter2) {
    ASSERT_EQ(iter1->GetNum(), iter2->GetNum());
  }
}

TEST(PushBack, PushBack5) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3), a4("a4", 4);
  my_space::List<TestObj> test1({a1, a2, a3});
  std::list<TestObj> test2({a1, a2, a3});

  test1.PushBack(a4);
  test2.push_back(a4);
  ;

  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());

  auto iter1 = test1.Begin();
  auto iter2 = test2.begin();
  for (size_t i = 0; i < test1.Size(); ++i, ++iter1, ++iter2) {
    ASSERT_EQ(iter1->GetNum(), iter2->GetNum());
  }
}

TEST(PushBack, PushBack6) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3), a4("a4", 4);
  my_space::List<TestObj> test1({a1, a2, a3});
  std::list<TestObj> test2({a1, a2, a3});

  test1.PushBack(a4);
  test2.push_back(a4);

  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());

  auto iter1 = test1.Begin();
  auto iter2 = test2.begin();
  for (size_t i = 0; i < test1.Size(); ++i, ++iter1, ++iter2) {
    ASSERT_EQ(iter1->GetNum(), iter2->GetNum());
  }
}

//// POPBACK
TEST(PopBack, PopBack1) {
  my_space::List<int> test1(1);
  std::list<int> test2(1);

  test1.PopBack();
  test2.pop_back();
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());
}

TEST(PopBack, PopBack2) {
  my_space::List<int> test1(10);
  std::list<int> test2(10);

  test1.PopBack();
  test2.pop_back();
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());
  auto iter1 = test1.Begin();
  auto iter2 = test2.begin();
  for (size_t i = 0; i < test1.Size(); ++i, ++iter1, ++iter2) {
    ASSERT_EQ(*iter1, *iter2);
  }
}

TEST(PopBack, PopBack3) {
  my_space::List<int> test1({1, 2, 3});
  std::list<int> test2({1, 2, 3});

  test1.PopBack();
  test2.pop_back();
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());
  auto iter1 = test1.Begin();
  auto iter2 = test2.begin();
  for (size_t i = 0; i < test1.Size(); ++i, ++iter1, ++iter2) {
    ASSERT_EQ(*iter1, *iter2);
  }
}

TEST(PopBack, PopBack4) {
  my_space::List<TestObj> test1(1);
  std::list<TestObj> test2(1);

  test1.PopBack();
  test2.pop_back();
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());
}

TEST(PopBack, PopBack5) {
  my_space::List<TestObj> test1(10);
  std::list<TestObj> test2(10);

  test1.PopBack();
  test2.pop_back();
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());
  auto iter1 = test1.Begin();
  auto iter2 = test2.begin();
  for (size_t i = 0; i < test1.Size(); ++i, ++iter1, ++iter2) {
    ASSERT_EQ(iter1->GetNum(), iter2->GetNum());
  }
}

TEST(PopBack, PopBack6) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3);
  my_space::List<TestObj> test1({a1, a2, a3});
  std::list<TestObj> test2({a1, a2, a3});

  test1.PopBack();
  test2.pop_back();
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());
  auto iter1 = test1.Begin();
  auto iter2 = test2.begin();
  for (size_t i = 0; i < test1.Size(); ++i, ++iter1, ++iter2) {
    ASSERT_EQ(iter1->GetNum(), iter2->GetNum());
  }
}

//// PUSHFRONT
TEST(PushFront, PushFront1) {
  my_space::List<int> test1;
  std::list<int> test2;

  test1.PushFront(444);
  test2.push_front(444);

  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());

  auto iter1 = test1.Begin();
  auto iter2 = test2.begin();
  for (size_t i = 0; i < test1.Size(); ++i, ++iter1, ++iter2) {
    ASSERT_EQ(*iter1, *iter2);
  }
}

TEST(PushFront, PushFront2) {
  my_space::List<int> test1(50);
  std::list<int> test2(50);

  test1.PushFront(444);
  test2.push_front(444);

  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());

  auto iter1 = test1.Begin();
  auto iter2 = test2.begin();
  for (size_t i = 0; i < test1.Size(); ++i, ++iter1, ++iter2) {
    ASSERT_EQ(*iter1, *iter2);
  }
}

TEST(PushFront, PushFront3) {
  my_space::List<int> test1({1, 2, 3});
  std::list<int> test2({1, 2, 3});

  test1.PushFront(444);
  test2.push_front(444);

  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());

  auto iter1 = test1.Begin();
  auto iter2 = test2.begin();
  for (size_t i = 0; i < test1.Size(); ++i, ++iter1, ++iter2) {
    ASSERT_EQ(*iter1, *iter2);
  }
}

TEST(PushFront, PushFront4) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3), a4("a4", 4);
  my_space::List<TestObj> test1({a1, a2, a3});
  std::list<TestObj> test2({a1, a2, a3});

  test1.PushFront(a4);
  test2.push_front(a4);

  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());

  auto iter1 = test1.Begin();
  auto iter2 = test2.begin();
  for (size_t i = 0; i < test1.Size(); ++i, ++iter1, ++iter2) {
    ASSERT_EQ(iter1->GetNum(), iter2->GetNum());
  }
}

TEST(PushFront, PushFront5) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3), a4("a4", 4);
  my_space::List<TestObj> test1({a1, a2, a3});
  std::list<TestObj> test2({a1, a2, a3});

  test1.PushFront(a4);
  test2.push_front(a4);
  ;

  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());

  auto iter1 = test1.Begin();
  auto iter2 = test2.begin();
  for (size_t i = 0; i < test1.Size(); ++i, ++iter1, ++iter2) {
    ASSERT_EQ(iter1->GetNum(), iter2->GetNum());
  }
}

TEST(PushFront, PushFront6) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3), a4("a4", 4);
  my_space::List<TestObj> test1({a1, a2, a3});
  std::list<TestObj> test2({a1, a2, a3});

  test1.PushFront(a4);
  test2.push_front(a4);

  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());

  auto iter1 = test1.Begin();
  auto iter2 = test2.begin();
  for (size_t i = 0; i < test1.Size(); ++i, ++iter1, ++iter2) {
    ASSERT_EQ(iter1->GetNum(), iter2->GetNum());
  }
}

//// POPFRONT
TEST(PopFront, PopFront1) {
  my_space::List<int> test1(1);
  std::list<int> test2(1);

  test1.PopFront();
  test2.pop_front();
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());
}

TEST(PopFront, PopFront2) {
  my_space::List<int> test1(10);
  std::list<int> test2(10);

  test1.PopFront();
  test2.pop_front();
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());
  auto iter1 = test1.Begin();
  auto iter2 = test2.begin();
  for (size_t i = 0; i < test1.Size(); ++i, ++iter1, ++iter2) {
    ASSERT_EQ(*iter1, *iter2);
  }
}

TEST(PopFront, PopFront3) {
  my_space::List<int> test1({1, 2, 3});
  std::list<int> test2({1, 2, 3});

  test1.PopFront();
  test2.pop_front();
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());
  auto iter1 = test1.Begin();
  auto iter2 = test2.begin();
  for (size_t i = 0; i < test1.Size(); ++i, ++iter1, ++iter2) {
    ASSERT_EQ(*iter1, *iter2);
  }
}

TEST(PopFront, PopFront4) {
  my_space::List<TestObj> test1(1);
  std::list<TestObj> test2(1);

  test1.PopFront();
  test2.pop_front();
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());
}

TEST(PopFront, PopFront5) {
  my_space::List<TestObj> test1(10);
  std::list<TestObj> test2(10);

  test1.PopFront();
  test2.pop_front();
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());
  auto iter1 = test1.Begin();
  auto iter2 = test2.begin();
  for (size_t i = 0; i < test1.Size(); ++i, ++iter1, ++iter2) {
    ASSERT_EQ(iter1->GetNum(), iter2->GetNum());
  }
}

TEST(PopFront, PopFront6) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3);
  my_space::List<TestObj> test1({a1, a2, a3});
  std::list<TestObj> test2({a1, a2, a3});

  test1.PopFront();
  test2.pop_front();
  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());
  auto iter1 = test1.Begin();
  auto iter2 = test2.begin();
  for (size_t i = 0; i < test1.Size(); ++i, ++iter1, ++iter2) {
    ASSERT_EQ(iter1->GetNum(), iter2->GetNum());
  }
}

//// SWAP
TEST(Swap, Swap1) {
  my_space::List<int> test1({0, 0, 0});
  my_space::List<int> test2({1, 2, 1, 3, 4});
  test1.Swap(test2);

  list<int> test3({0, 0, 0});
  list<int> test4({1, 2, 1, 3, 4});
  test3.swap(test4);

  ASSERT_EQ(test1.Size(), test3.size());
  ASSERT_EQ(test2.Size(), test4.size());

  auto iter1 = test1.Begin();
  auto iter2 = test2.Begin();
  auto iter3 = test3.begin();
  auto iter4 = test4.begin();

  for (size_t i = 0; i < test1.Size(); ++i, ++iter1, ++iter3) {
    ASSERT_EQ(*iter1, *iter3);
  }

  for (size_t i = 0; i < test2.Size(); ++i, ++iter2, ++iter4) {
    ASSERT_EQ(*iter2, *iter4);
  }
}

TEST(Swap, Swap2) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3), a4("a4", 4), a5("a5", 5),
      a6("a6", 6);
  my_space::List<TestObj> test1({a6, a1, a5});
  my_space::List<TestObj> test2({a1, a2, a1, a3, a4});
  test1.Swap(test2);

  list<TestObj> test3({a6, a1, a5});
  list<TestObj> test4({a1, a2, a1, a3, a4});
  test3.swap(test4);

  ASSERT_EQ(test1.Size(), test3.size());
  ASSERT_EQ(test2.Size(), test4.size());

  auto iter1 = test1.Begin();
  auto iter2 = test2.Begin();
  auto iter3 = test3.begin();
  auto iter4 = test4.begin();

  for (size_t i = 0; i < test1.Size(); ++i, ++iter1, ++iter3) {
    ASSERT_EQ(iter1->GetNum(), iter3->GetNum());
  }

  for (size_t i = 0; i < test2.Size(); ++i, ++iter2, ++iter4) {
    ASSERT_EQ(iter2->GetNum(), iter4->GetNum());
  }
}

//// SORT and MERGE
TEST(Sort, Sort1) {
  my_space::List<double> test1({0.5, -3.9, 11.5, 2.3});
  my_space::List<double> test2({-0.5, 777, 25.9, 33.1});
  std::list<double> test3({0.5, -3.9, 11.5, 2.3});
  std::list<double> test4({-0.5, 777, 25.9, 33.1});

  //// sort
  test1.Sort();
  test2.Sort();
  test3.sort();
  test4.sort();

  auto iter1 = test1.Begin();
  auto iter2 = test2.Begin();
  auto iter3 = test3.begin();
  auto iter4 = test4.begin();

  for (size_t i = 0; i < test1.Size(); ++i, ++iter1, ++iter3) {
    ASSERT_EQ(*iter1, *iter3);
  }
  for (size_t i = 0; i < test2.Size(); ++i, ++iter2, ++iter4) {
    ASSERT_EQ(*iter2, *iter4);
  }

  //// merge
  test1.Merge(test2);
  test3.merge(test4);

  auto iter5 = test1.Begin();
  auto iter6 = test2.Begin();
  auto iter7 = test3.begin();
  auto iter8 = test4.begin();

  for (size_t i = 0; i < test1.Size(); ++i, ++iter5, ++iter7) {
    ASSERT_EQ(*iter5, *iter7);
  }

  ASSERT_EQ(test2.Empty(), test4.empty());
}

TEST(Sort, Sort2) {
  TestObj a1("a1", 0.5), a2("a2", -3.9), a3("a3", 11.5), a4("a4", 2.3),
      a5("a5", -0.5), a6("a6", 777), a7("a7", 25.9), a8("a8", 33.1);
  my_space::List<TestObj> test1({a1, a2, a3, a4});
  my_space::List<TestObj> test2({a5, a6, a7, a8});
  std::list<TestObj> test3({a1, a2, a3, a4});
  std::list<TestObj> test4({a5, a6, a7, a8});

  //// sort
  test1.Sort();
  test2.Sort();
  test3.sort();
  test4.sort();

  auto iter1 = test1.Begin();
  auto iter2 = test2.Begin();
  auto iter3 = test3.begin();
  auto iter4 = test4.begin();

  for (size_t i = 0; i < test1.Size(); ++i, ++iter1, ++iter3) {
    ASSERT_EQ(iter1->GetNum(), iter3->GetNum());
  }
  for (size_t i = 0; i < test2.Size(); ++i, ++iter2, ++iter4) {
    ASSERT_EQ(iter2->GetNum(), iter4->GetNum());
  }

  //// merge
  test1.Merge(test2);
  test3.merge(test4);

  auto iter5 = test1.Begin();
  auto iter6 = test2.Begin();
  auto iter7 = test3.begin();
  auto iter8 = test4.begin();

  for (size_t i = 0; i < test1.Size(); ++i, ++iter5, ++iter7) {
    ASSERT_EQ(iter5->GetNum(), iter7->GetNum());
  }

  ASSERT_EQ(test2.Empty(), test4.empty());
}

//// SPLICE
TEST(ListModifiers, Splice1) {
  my_space::List<char> list_char({'a', 'c', 'b'});
  my_space::List<char> list_char2({'1', '!', '4', '5'});

  std::list<char> std_list_char({'a', 'c', 'b'});
  std::list<char> std_list_char2({'1', '!', '4', '5'});

  auto iter = list_char.CEnd();
  --iter;

  auto std_iter = std_list_char.end();
  --std_iter;

  list_char.Splice(iter, list_char2);
  std_list_char.splice(std_iter, std_list_char2);

  ASSERT_EQ(list_char.Front(), std_list_char.front());
  ASSERT_EQ(list_char.Back(), std_list_char.back());
  ASSERT_EQ(list_char2.Empty(), std_list_char2.empty());
}

TEST(ListModifiers, Splice2) {
  my_space::List<char> list_char({'a', 'c', 'b'});
  my_space::List<char> list_char2({'1', '!', '4', '5'});

  std::list<char> std_list_char({'a', 'c', 'b'});
  std::list<char> std_list_char2({'1', '!', '4', '5'});

  auto iter = list_char.CBegin();

  auto std_iter = std_list_char.cbegin();

  list_char.Splice(iter, list_char2);
  std_list_char.splice(std_iter, std_list_char2);

  ASSERT_EQ(list_char.Front(), std_list_char.front());
  ASSERT_EQ(list_char.Back(), std_list_char.back());
  ASSERT_EQ(list_char2.Empty(), std_list_char2.empty());
}

TEST(ListModifiers, Splice3) {
  my_space::List<char> list_char({'a', 'c', 'b'});
  my_space::List<char> list_char2({'1', '!', '4', '5'});

  std::list<char> std_list_char({'a', 'c', 'b'});
  std::list<char> std_list_char2({'1', '!', '4', '5'});

  auto iter = list_char.CEnd();

  auto std_iter = std_list_char.cend();

  list_char.Splice(iter, list_char2);
  std_list_char.splice(std_iter, std_list_char2);

  ASSERT_EQ(list_char.Front(), std_list_char.front());
  ASSERT_EQ(list_char2.Empty(), std_list_char2.empty());
}

//// REVERS
TEST(Reverse, Reverse1) {
  my_space::List<double> test1({0.5, -3.9, 11.5, 2.3});
  std::list<double> test2{0.5, -3.9, 11.5, 2.3};

  test1.Reverse();

  test2.reverse();
  ASSERT_DOUBLE_EQ(test1.Front(), test2.front());
  ASSERT_DOUBLE_EQ(test1.Back(), test2.back());
}

TEST(Reverse, Reverse2) {
  my_space::List<std::string> my_space_list_string{"am", "I", "uuu"};
  std::list<std::string> list_string{"am", "I", "uuu"};
  my_space_list_string.Reverse();
  list_string.reverse();
  ASSERT_EQ(my_space_list_string.Front(), list_string.front());
  ASSERT_EQ(my_space_list_string.Back(), list_string.back());
}

//// UNIQUI
TEST(Uniqui, Uniqui1) {
  TestObj a1("a1", 0.5), a2("a2", -3.9), a3("a3", 11.5), a4("a4", 2.3),
      a5("a5", -0.5), a6("a6", 777), a7("a7", 25.9);
  my_space::List<TestObj> test1(
      {a1, a2, a2, a3, a3, a3, a4, a5, a5, a6, a6, a6, a7});
  std::list<TestObj> test2(
      {a1, a2, a2, a3, a3, a3, a4, a5, a5, a6, a6, a6, a7});
  test1.Unique();
  test2.unique();
  ASSERT_EQ(test1.Size(), test2.size());
  auto it_my_space = test1.Begin();
  auto it_orig = test2.begin();
  for (size_t i = 0; i < test1.Size(); ++i, ++it_my_space, ++it_orig) {
    ASSERT_EQ(it_my_space->GetNum(), it_orig->GetNum());
  }
}

//// EMPLACEBACK
TEST(EmplaceBack, EmplaceBack1) {
  my_space::List<int> test1;
  std::list<int> test2;

  test1.EmplaceBack(444);
  test2.emplace_back(444);

  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());

  auto iter1 = test1.Begin();
  auto iter2 = test2.begin();
  for (size_t i = 0; i < test1.Size(); ++i, ++iter1, ++iter2) {
    ASSERT_EQ(*iter1, *iter2);
  }
}

TEST(EmplaceBack, EmplaceBack2) {
  my_space::List<int> test1(50);
  std::list<int> test2(50);

  test1.EmplaceBack(444);
  test2.emplace_back(444);

  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());

  auto iter1 = test1.Begin();
  auto iter2 = test2.begin();
  for (size_t i = 0; i < test1.Size(); ++i, ++iter1, ++iter2) {
    ASSERT_EQ(*iter1, *iter2);
  }
}

TEST(EmplaceBack, EmplaceBack3) {
  my_space::List<int> test1({1, 2, 3});
  std::list<int> test2({1, 2, 3});

  test1.EmplaceBack(444);
  test2.emplace_back(444);

  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());

  auto iter1 = test1.Begin();
  auto iter2 = test2.begin();
  for (size_t i = 0; i < test1.Size(); ++i, ++iter1, ++iter2) {
    ASSERT_EQ(*iter1, *iter2);
  }
}

TEST(EmplaceBack, EmplaceBack4) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3), a4("a4", 4);
  my_space::List<TestObj> test1({a1, a2, a3});
  std::list<TestObj> test2({a1, a2, a3});

  test1.EmplaceBack("a6", 6);
  test2.emplace_back("a6", 6);

  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());

  auto iter1 = test1.Begin();
  auto iter2 = test2.begin();
  for (size_t i = 0; i < test1.Size(); ++i, ++iter1, ++iter2) {
    ASSERT_EQ(iter1->GetNum(), iter2->GetNum());
  }
}

TEST(EmplaceBack, EmplaceBack5) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3), a4("a4", 4);
  my_space::List<TestObj> test1({a1, a2, a3});
  std::list<TestObj> test2({a1, a2, a3});

  test1.EmplaceBack("a6", 6);
  test2.emplace_back("a6", 6);
  ;

  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());

  auto iter1 = test1.Begin();
  auto iter2 = test2.begin();
  for (size_t i = 0; i < test1.Size(); ++i, ++iter1, ++iter2) {
    ASSERT_EQ(iter1->GetNum(), iter2->GetNum());
  }
}

TEST(EmplaceBack, EmplaceBack6) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3), a4("a4", 4);
  my_space::List<TestObj> test1({a1, a2, a3});
  std::list<TestObj> test2({a1, a2, a3});

  test1.EmplaceBack("a6", 6);
  test2.emplace_back("a6", 6);

  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());

  auto iter1 = test1.Begin();
  auto iter2 = test2.begin();
  for (size_t i = 0; i < test1.Size(); ++i, ++iter1, ++iter2) {
    ASSERT_EQ(iter1->GetNum(), iter2->GetNum());
  }
}

//// EMPLACEFRONT
TEST(EmplaceFront, EmplaceFront1) {
  my_space::List<int> test1;
  std::list<int> test2;

  test1.EmplaceFront(444);
  test2.emplace_front(444);

  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());

  auto iter1 = test1.Begin();
  auto iter2 = test2.begin();
  for (size_t i = 0; i < test1.Size(); ++i, ++iter1, ++iter2) {
    ASSERT_EQ(*iter1, *iter2);
  }
}

TEST(EmplaceFront, EmplaceFront2) {
  my_space::List<int> test1(50);
  std::list<int> test2(50);

  test1.EmplaceFront(444);
  test2.emplace_front(444);

  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());

  auto iter1 = test1.Begin();
  auto iter2 = test2.begin();
  for (size_t i = 0; i < test1.Size(); ++i, ++iter1, ++iter2) {
    ASSERT_EQ(*iter1, *iter2);
  }
}

TEST(EmplaceFront, EmplaceFront3) {
  my_space::List<int> test1({1, 2, 3});
  std::list<int> test2({1, 2, 3});

  test1.EmplaceFront(444);
  test2.emplace_front(444);

  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());

  auto iter1 = test1.Begin();
  auto iter2 = test2.begin();
  for (size_t i = 0; i < test1.Size(); ++i, ++iter1, ++iter2) {
    ASSERT_EQ(*iter1, *iter2);
  }
}

TEST(EmplaceFront, EmplaceFront4) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3), a4("a4", 4);
  my_space::List<TestObj> test1({a1, a2, a3});
  std::list<TestObj> test2({a1, a2, a3});

  test1.EmplaceFront("a6", 6);
  test2.emplace_front("a6", 6);

  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());

  auto iter1 = test1.Begin();
  auto iter2 = test2.begin();
  for (size_t i = 0; i < test1.Size(); ++i, ++iter1, ++iter2) {
    ASSERT_EQ(iter1->GetNum(), iter2->GetNum());
  }
}

TEST(EmplaceFront, EmplaceFront5) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3), a4("a4", 4);
  my_space::List<TestObj> test1({a1, a2, a3});
  std::list<TestObj> test2({a1, a2, a3});

  test1.EmplaceFront("a6", 6);
  test2.emplace_front("a6", 6);
  ;

  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());

  auto iter1 = test1.Begin();
  auto iter2 = test2.begin();
  for (size_t i = 0; i < test1.Size(); ++i, ++iter1, ++iter2) {
    ASSERT_EQ(iter1->GetNum(), iter2->GetNum());
  }
}

TEST(EmplaceFront, EmplaceFront6) {
  TestObj a1("a1", 1), a2("a2", 2), a3("a3", 3), a4("a4", 4);
  my_space::List<TestObj> test1({a1, a2, a3});
  std::list<TestObj> test2({a1, a2, a3});

  test1.EmplaceFront("a6", 6);
  test2.emplace_front("a6", 6);

  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());

  auto iter1 = test1.Begin();
  auto iter2 = test2.begin();
  for (size_t i = 0; i < test1.Size(); ++i, ++iter1, ++iter2) {
    ASSERT_EQ(iter1->GetNum(), iter2->GetNum());
  }
}

////EMPLACE
TEST(Emplace, Emplace1) {
  my_space::List<int> test1;
  std::list<int> test2;
  auto iter_my_space = test1.Emplace(test1.CBegin(), 444);
  auto iter_std = test2.emplace(test2.cbegin(), 444);
  ASSERT_EQ(*iter_my_space, *iter_std);

  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());

  auto iter1 = test1.Begin();
  auto iter2 = test2.begin();
  for (size_t i = 0; i < test1.Size(); ++i, ++iter1, ++iter2) {
    ASSERT_EQ(*iter1, *iter2);
  }
}

TEST(Emplace, Emplac2) {
  my_space::List<int> test1;
  std::list<int> test2;
  auto iter_my_space = test1.Emplace(test1.CEnd(), 444);
  auto iter_std = test2.emplace(test2.cend(), 444);
  ASSERT_EQ(*iter_my_space, *iter_std);

  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());

  auto iter1 = test1.Begin();
  auto iter2 = test2.begin();
  for (size_t i = 0; i < test1.Size(); ++i, ++iter1, ++iter2) {
    ASSERT_EQ(*iter1, *iter2);
  }
}

TEST(Emplace, Emplace3) {
  my_space::List<int> test1({23});
  std::list<int> test2({23});
  auto iter_my_space = test1.Emplace(test1.CBegin(), 444);
  auto iter_std = test2.emplace(test2.cbegin(), 444);
  ASSERT_EQ(*iter_my_space, *iter_std);

  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());

  auto iter1 = test1.Begin();
  auto iter2 = test2.begin();
  for (size_t i = 0; i < test1.Size(); ++i, ++iter1, ++iter2) {
    ASSERT_EQ(*iter1, *iter2);
  }
}

TEST(Emplace, Emplace4) {
  my_space::List<int> test1({23});
  std::list<int> test2({23});
  auto iter_my_space = test1.Emplace(test1.CEnd(), 444);
  auto iter_std = test2.emplace(test2.cend(), 444);
  ASSERT_EQ(*iter_my_space, *iter_std);

  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());

  auto iter1 = test1.Begin();
  auto iter2 = test2.begin();
  for (size_t i = 0; i < test1.Size(); ++i, ++iter1, ++iter2) {
    ASSERT_EQ(*iter1, *iter2);
  }
}

TEST(Emplace, Emplace5) {
  my_space::List<int> test1({23, 47, -23});
  std::list<int> test2({23, 47, -23});
  auto iter1 = test1.CBegin();
  auto iter2 = test2.cbegin();
  ++iter1;
  ++iter2;
  auto iter_my_space = test1.Emplace(iter1, 444);
  auto iter_std = test2.emplace(iter2, 444);
  ASSERT_EQ(*iter_my_space, *iter_std);

  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());

  auto iter3 = test1.Begin();
  auto iter4 = test2.begin();
  for (size_t i = 0; i < test1.Size(); ++i, ++iter3, ++iter4) {
    ASSERT_EQ(*iter3, *iter4);
  }
}

TEST(Emplace, Emplace6) {
  my_space::List<int> test1({23, 47, -23});
  std::list<int> test2({23, 47, -23});
  auto iter1 = test1.CBegin();
  auto iter2 = test2.cbegin();
  ++iter1;
  ++iter1;
  ++iter2;
  ++iter2;
  auto iter_my_space = test1.Emplace(iter1, 444);
  auto iter_std = test2.emplace(iter2, 444);
  ASSERT_EQ(*iter_my_space, *iter_std);

  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());

  auto iter3 = test1.Begin();
  auto iter4 = test2.begin();
  for (size_t i = 0; i < test1.Size(); ++i, ++iter3, ++iter4) {
    ASSERT_EQ(*iter3, *iter4);
  }
}

TEST(Emplace, Emplace7) {
  my_space::List<int> test1({23, 47, -23});
  std::list<int> test2({23, 47, -23});
  auto iter_my_space = test1.Emplace(test1.CEnd(), 444);
  auto iter_std = test2.emplace(test2.cend(), 444);
  ASSERT_EQ(*iter_my_space, *iter_std);

  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());

  auto iter1 = test1.Begin();
  auto iter2 = test2.begin();
  for (size_t i = 0; i < test1.Size(); ++i, ++iter1, ++iter2) {
    ASSERT_EQ(*iter1, *iter2);
  }
}

TEST(Emplace, Emplace8) {
  my_space::List<TestObj> test1;
  std::list<TestObj> test2;
  auto iter_my_space = test1.Emplace(test1.CBegin(), "a1", 1);
  auto iter_std = test2.emplace(test2.cbegin(), "a1", 1);
  ASSERT_EQ(iter_my_space->GetNum(), iter_std->GetNum());

  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());

  auto iter1 = test1.Begin();
  auto iter2 = test2.begin();
  for (size_t i = 0; i < test1.Size(); ++i, ++iter1, ++iter2) {
    ASSERT_EQ(iter1->GetNum(), iter2->GetNum());
  }
}

TEST(Emplace, Emplace9) {
  my_space::List<TestObj> test1;
  std::list<TestObj> test2;
  auto iter_my_space = test1.Emplace(test1.CEnd(), "a1", 1);
  auto iter_std = test2.emplace(test2.cend(), "a1", 1);
  ASSERT_EQ(iter_my_space->GetNum(), iter_std->GetNum());

  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());

  auto iter1 = test1.Begin();
  auto iter2 = test2.begin();
  for (size_t i = 0; i < test1.Size(); ++i, ++iter1, ++iter2) {
    ASSERT_EQ(iter1->GetNum(), iter2->GetNum());
  }
}

TEST(Emplace, Emplace10) {
  TestObj a1("a1", 1);
  my_space::List<TestObj> test1({a1});
  std::list<TestObj> test2({a1});
  auto iter_my_space = test1.Emplace(test1.CBegin(), "a2", 2);
  auto iter_std = test2.emplace(test2.cbegin(), "a2", 2);
  ASSERT_EQ(iter_my_space->GetNum(), iter_std->GetNum());

  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());

  auto iter1 = test1.Begin();
  auto iter2 = test2.begin();
  for (size_t i = 0; i < test1.Size(); ++i, ++iter1, ++iter2) {
    ASSERT_EQ(iter1->GetNum(), iter2->GetNum());
  }
}

TEST(Emplace, Emplace11) {
  TestObj a1("a1", 1);
  my_space::List<TestObj> test1({a1});
  std::list<TestObj> test2({a1});
  auto iter_my_space = test1.Emplace(test1.CEnd(), "a2", 2);
  auto iter_std = test2.emplace(test2.cend(), "a2", 2);
  ASSERT_EQ(iter_my_space->GetNum(), iter_std->GetNum());

  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());

  auto iter1 = test1.Begin();
  auto iter2 = test2.begin();
  for (size_t i = 0; i < test1.Size(); ++i, ++iter1, ++iter2) {
    ASSERT_EQ(iter1->GetNum(), iter2->GetNum());
  }
}

TEST(Emplace, Emplace12) {
  TestObj a1("a1", 1), a2("a3", 3), a3("a3", 3);
  my_space::List<TestObj> test1({a1, a2, a3});
  std::list<TestObj> test2({a1, a2, a3});
  auto iter1 = test1.CBegin();
  auto iter2 = test2.cbegin();
  ++iter1;
  ++iter2;
  auto iter_my_space = test1.Emplace(iter1, "a4", 4);
  auto iter_std = test2.emplace(iter2, "a4", 4);
  ASSERT_EQ(iter_my_space->GetNum(), iter_std->GetNum());

  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());

  auto iter3 = test1.Begin();
  auto iter4 = test2.begin();
  for (size_t i = 0; i < test1.Size(); ++i, ++iter3, ++iter4) {
    ASSERT_EQ(iter3->GetNum(), iter4->GetNum());
  }
}

TEST(Emplace, Emplace13) {
  TestObj a1("a1", 1), a2("a3", 3), a3("a3", 3);
  my_space::List<TestObj> test1({a1, a2, a3});
  std::list<TestObj> test2({a1, a2, a3});
  auto iter1 = test1.CBegin();
  auto iter2 = test2.cbegin();
  ++iter1;
  ++iter1;
  ++iter2;
  ++iter2;
  auto iter_my_space = test1.Emplace(iter1, "a4", 4);
  auto iter_std = test2.emplace(iter2, "a4", 4);
  ASSERT_EQ(iter_my_space->GetNum(), iter_std->GetNum());

  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());

  auto iter3 = test1.Begin();
  auto iter4 = test2.begin();
  for (size_t i = 0; i < test1.Size(); ++i, ++iter3, ++iter4) {
    ASSERT_EQ(iter3->GetNum(), iter4->GetNum());
  }
}

TEST(Emplace, Emplace14) {
  TestObj a1("a1", 1), a2("a3", 3), a3("a3", 3);
  my_space::List<TestObj> test1({a1, a2, a3});
  std::list<TestObj> test2({a1, a2, a3});

  auto iter_my_space = test1.Emplace(test1.CEnd(), "a4", 4);
  auto iter_std = test2.emplace(test2.cend(), "a4", 4);
  ASSERT_EQ(iter_my_space->GetNum(), iter_std->GetNum());

  ASSERT_EQ(test1.Size(), test2.size());
  ASSERT_EQ(test1.Empty(), test2.empty());

  auto iter1 = test1.Begin();
  auto iter2 = test2.begin();
  for (size_t i = 0; i < test1.Size(); ++i, ++iter1, ++iter2) {
    ASSERT_EQ(iter1->GetNum(), iter2->GetNum());
  }
}

TEST(Emplace, Emplace15) {
  my_space::List<int> my_space_list_int({5, 1, 2, 3, 7});
  auto iter = my_space_list_int.CBegin();
  auto iter_insert = my_space_list_int.Emplace(iter, 77);
  //// std
  std::list<int> std_list_int({5, 1, 2, 3, 7});
  auto std_iter = std_list_int.cbegin();
  auto std_iter_insert = std_list_int.emplace(std_iter, 77);

  ASSERT_EQ(*iter_insert, *std_iter_insert);

  ++iter;
  ++std_iter;
  auto iter_insert2 = my_space_list_int.Emplace(iter, 171);
  auto std_iter_insert2 = std_list_int.emplace(std_iter, 171);
  ASSERT_EQ(*iter_insert2, *std_iter_insert2);
}

//// ************** Pop **************
TEST(ListModifiers, PopInt) {
  my_space::List<int> list_int;
  list_int.PushBack(1);
  list_int.PushBack(2);
  list_int.PushBack(3);
  list_int.PopBack();
  //// std
  std::list<int> std_list_int;
  std_list_int.push_back(1);
  std_list_int.push_back(2);
  std_list_int.push_back(3);
  std_list_int.pop_back();

  ASSERT_EQ(list_int.Size(), std_list_int.size());
  ASSERT_EQ(list_int.Back(), std_list_int.back());
}

//// ************** Operator1 **************
TEST(ListOverload, OperatorEqualInt) {
  my_space::List<int> list_int({777, -3, 1, 2, 5});
  my_space::List<int> list_int2;
  list_int2 = list_int;
  //// std
  std::list<int> std_list_int({777, -3, 1, 2, 5});
  std::list<int> std_list_int2;
  std_list_int2 = std_list_int;

  ASSERT_EQ(list_int.Size(), std_list_int.size());
  ASSERT_EQ(list_int.Front(), std_list_int.front());
  ASSERT_EQ(list_int.Back(), std_list_int.back());
  ASSERT_EQ(list_int2.Size(), std_list_int2.size());
  ASSERT_EQ(list_int2.Front(), std_list_int2.front());
  ASSERT_EQ(list_int2.Back(), std_list_int2.back());
}

TEST(ListOverload, OperatorEqualDouble) {
  my_space::List<double> list_double({0.5, -3.9, 1.5, 2.3});
  my_space::List<double> list_double2({100.1, 100.2});
  list_double2 = list_double;
  //// std
  std::list<double> std_list_double({0.5, -3.9, 1.5, 2.3});
  std::list<double> std_list_double2({100.1, 100.2});
  std_list_double2 = std_list_double;

  ASSERT_EQ(list_double.Size(), std_list_double.size());
  ASSERT_DOUBLE_EQ(list_double.Front(), std_list_double.front());
  ASSERT_DOUBLE_EQ(list_double.Back(), std_list_double.back());
  ASSERT_EQ(list_double2.Size(), std_list_double2.size());
  ASSERT_DOUBLE_EQ(list_double2.Front(), std_list_double2.front());
  ASSERT_DOUBLE_EQ(list_double2.Back(), std_list_double2.back());
}

TEST(ListOverload, OperatorEqualMoveString) {
  my_space::List<std::string> list_string({"am", "I", "fff"});
  my_space::List<std::string> list_string2({"Aboba", "to", "and", "Ababo"});
  list_string2 = std::move(list_string);
  //// std
  std::list<std::string> std_list_string({"am", "I", "fff"});
  std::list<std::string> std_list_string2({"Aboba", "to", "and", "Ababo"});
  std_list_string2 = std::move(std_list_string);

  ASSERT_EQ(list_string.Size(), std_list_string.size());
  ASSERT_EQ(list_string2.Size(), std_list_string2.size());

  auto iter = list_string2.Begin();
  auto iter_end = list_string2.End();
  //// std
  auto std_iter = std_list_string2.begin();
  auto std_iter_end = std_list_string2.end();

  --iter_end;
  --std_iter_end;

  ASSERT_EQ(*iter, *std_iter);
  ASSERT_EQ(*iter_end, *std_iter_end);
}

//// ************** Iterator **************
TEST(ListModifiers, Iterator) {
  my_space::List<int> list_int({1, 2, 3});
  my_space::List<int> list_int2({1, 2, 1, 3, 4});
  my_space::List<int>::iterator iter;
  my_space::List<int>::iterator iter2;
  ////  iter = list_int.Begin();
  ////  iter2 = list_int2.Begin();
  ////  ASSERT_EQ(false, iter == iter2);
  ////  ASSERT_EQ(*iter, *iter2);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
