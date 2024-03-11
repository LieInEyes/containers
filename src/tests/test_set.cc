#include <gtest/gtest.h>

#include <set>

#include "../containers.h"

using namespace my_space;

TEST(SetConstructor, DefaultConstuct) {
  Set<int> my_set;
  std::set<int> std_set;
  ASSERT_EQ(my_set.Size(), std_set.size());
}

TEST(SetConstructor, ParameterConstructor) {
  Set<int> my_set({1, 2, 3, 4});
  std::set<int> std_set({1, 2, 3, 4});
  ASSERT_EQ(my_set.Size(), std_set.size());
}

TEST(SetConstructor, CopyConstructor) {
  Set<int> my_set_old({1, 2, 3, 4});
  std::set<int> std_set_old({1, 2, 3, 4});
  Set<int> my_set(my_set_old);
  std::set<int> std_set(std_set_old);
  ASSERT_EQ(my_set.Size(), std_set.size());
}

TEST(SetConstructor, MoveConstructor) {
  Set<int> my_set_old({1, 2, 3, 4});
  std::set<int> std_set_old({1, 2, 3, 4});
  Set<int> my_set = std::move(my_set_old);
  std::set<int> std_set = std::move(std_set_old);
  ASSERT_EQ(my_set.Size(), std_set.size());
}

TEST(SetBegin, NotEmpty) {
  Set<int> my_set({1, 2, 3, 4});
  std::set<int> std_set({1, 2, 3, 4});
  ASSERT_EQ(*my_set.Begin(), *std_set.begin());
}

TEST(SetEnd, NotEmpty) {
  Set<int> my_set({1, 2, 3, 4});
  std::set<int> std_set({1, 2, 3, 4});
  ASSERT_EQ(*(--my_set.End()), *(--std_set.end()));
}

TEST(SetEmpty, Empty) {
  Set<int> my_set;
  std::set<int> std_set;
  ASSERT_EQ(my_set.Empty(), std_set.empty());
}

TEST(SetEmpty, NotEmpty) {
  Set<int> my_set({1, 2, 3, 4});
  std::set<int> std_set({1, 2, 3, 4});
  ASSERT_EQ(my_set.Empty(), std_set.empty());
}

TEST(SetSize, Empty) {
  Set<int> my_set;
  std::set<int> std_set;
  ASSERT_EQ(my_set.Size(), std_set.size());
}

TEST(SetSize, NotEmpty) {
  Set<int> my_set({1, 2, 3, 4});
  std::set<int> std_set({1, 2, 3, 4});
  ASSERT_EQ(my_set.Size(), std_set.size());
}

TEST(SetMaxSize, Empty) {
  Set<int> my_set;
  std::set<int> std_set;
  ASSERT_EQ(my_set.Maxsize(), std_set.max_size());
}

TEST(SetMaxSize, NotEmpty) {
  Set<int> my_set({1, 2, 3, 4});
  std::set<int> std_set({1, 2, 3, 4});
  ASSERT_EQ(my_set.Maxsize(), std_set.max_size());
}

TEST(SetClear, Empty) {
  Set<int> my_set;
  std::set<int> std_set;
  my_set.Clear();
  std_set.clear();
  ASSERT_EQ(my_set.Size(), std_set.size());
}

TEST(SetClear, NotEmpty) {
  Set<int> my_set({1, 2, 3, 4});
  std::set<int> std_set({1, 2, 3, 4});
  my_set.Clear();
  std_set.clear();
  ASSERT_EQ(my_set.Size(), std_set.size());
}

TEST(SetInsert, Empty) {
  Set<int> my_set;
  std::set<int> std_set;
  my_set.Insert(1);
  std_set.insert(1);
  ASSERT_EQ(my_set.Size(), std_set.size());
}

TEST(SetInsert, NotEmpty) {
  Set<int> my_set({1, 2, 3, 4});
  std::set<int> std_set({1, 2, 3, 4});
  auto my_result = my_set.Insert(5);
  auto std_result = std_set.insert(5);
  ASSERT_EQ(my_result.second, std_result.second);
  ASSERT_EQ(my_set.Size(), std_set.size());
}

TEST(SetInsert, Duoble) {
  Set<int> my_set({1, 2, 3, 4});
  std::set<int> std_set({1, 2, 3, 4});
  auto my_result = my_set.Insert(1);
  auto std_result = std_set.insert(1);
  ASSERT_EQ(my_result.second, std_result.second);
  ASSERT_EQ(my_set.Size(), std_set.size());
}

TEST(SetErase, Contains) {
  Set<int> my_set({1, 2, 3, 4});
  std::set<int> std_set({1, 2, 3, 4});
  auto my_iter = ++my_set.Begin();
  auto std_iter = ++std_set.begin();
  my_set.Erase(my_iter);
  std_set.erase(std_iter);
  ASSERT_EQ(my_set.Size(), std_set.size());
}

TEST(SetSwap, Empty) {
  Set<int> my_set_one;
  std::set<int> std_set_one;
  Set<int> my_set_two;
  std::set<int> std_set_two;
  my_set_one.Swap(my_set_two);
  std_set_one.swap(std_set_two);
  ASSERT_EQ(my_set_one.Size(), std_set_one.size());
}

TEST(SetSwap, NotEmpty) {
  Set<int> my_set_one({1, 2, 3});
  std::set<int> std_set_one({1, 2, 3});
  Set<int> my_set_two({4, 5});
  std::set<int> std_set_two({4, 5});
  my_set_one.Swap(my_set_two);
  std_set_one.swap(std_set_two);
  ASSERT_EQ(my_set_one.Size(), std_set_one.size());
  ASSERT_EQ(my_set_two.Size(), std_set_two.size());
}

TEST(SetMerge, NotContains) {
  Set<int> my_set({1, 2, 3, 4});
  std::set<int> std_set({1, 2, 3, 4});
  Set<int> my_temp({5, 6, 7, 8});
  std::set<int> std_temp({5, 6, 7, 8});
  my_set.Merge(my_temp);
  std_set.merge(std_temp);
  ASSERT_EQ(my_set.Size(), std_set.size());
}

TEST(SetMerge, Contains) {
  Set<int> my_set({1, 2, 3, 4});
  std::set<int> std_set({1, 2, 3, 4});
  Set<int> my_temp({4, 5, 6, 7, 8});
  std::set<int> std_temp({4, 5, 6, 7, 8});
  my_set.Merge(my_temp);
  std_set.merge(std_temp);
  ASSERT_EQ(my_set.Size(), std_set.size());
}

TEST(SetMerge, WithEmpty) {
  Set<int> my_set({1, 2, 3, 4});
  std::set<int> std_set({1, 2, 3, 4});
  Set<int> my_temp;
  std::set<int> std_temp;
  my_set.Merge(my_temp);
  std_set.merge(std_temp);
  ASSERT_EQ(my_set.Size(), std_set.size());
}

TEST(SetFind, Contains) {
  Set<int> my_set({1, 2, 3, 4});
  std::set<int> std_set({1, 2, 3, 4});
  ASSERT_EQ(*my_set.Find(1), *std_set.find(1));
}

TEST(SetFind, NotContains) {
  Set<int> my_set({1, 2, 3, 4});
  ASSERT_EQ(my_set.Find(7), my_set.End());
}

TEST(SetComtains, Contains) {
  Set<int> my_set({1, 2, 3, 4});
  std::set<int> std_set({1, 2, 3, 4});
  ASSERT_EQ(my_set.Contains(1), true);
}

TEST(SetFinComtainsd, NotContains) {
  Set<int> my_set({1, 2, 3, 4});
  std::set<int> std_set({1, 2, 3, 4});
  ASSERT_EQ(my_set.Contains(7), false);
}

TEST(MultisetBonus, Emplace) {
  Set<int> my_set;
  auto my_result = my_set.Emplace(1);
  ASSERT_EQ(my_result.second, true);
  ASSERT_EQ(*my_result.first, 1);
}

// region not my tests
TEST(TestEraseEasy, case1) {
  Set<int> mp;
  mp.Insert(4);
  mp.Insert(5);
  Set<int>::iterator iter = mp.Begin();
  ++iter;
  mp.Erase(iter);

  // std
  std::set<int> mp_eq;
  mp_eq.insert({4, 6});
  mp_eq.insert({5, 9});
  auto iter_std = mp_eq.begin();
  ++iter_std;
  mp_eq.erase(iter_std);

  ASSERT_EQ(mp.Size(), mp_eq.size());
}

TEST(TestEraseEasy, case2) {
  Set<int> mp;
  mp.Insert(7);
  mp.Insert(3);
  mp.Insert(9);
  mp.Insert(2);
  mp.Insert(5);
  mp.Insert(8);
  mp.Insert(1);
  mp.Insert(4);
  mp.Insert(6);
  Set<int>::iterator iter = mp.Begin();
  ++iter;
  mp.Erase(iter);

  // std
  std::set<int> mp_eq;
  mp_eq.insert(7);
  mp_eq.insert(3);
  mp_eq.insert(9);
  mp_eq.insert(2);
  mp_eq.insert(5);
  mp_eq.insert(8);
  mp_eq.insert(1);
  mp_eq.insert(4);
  mp_eq.insert(6);
  auto iter_std = mp_eq.begin();
  ++iter_std;
  mp_eq.erase(iter_std);

  ASSERT_EQ(mp.Size(), mp_eq.size());
}

TEST(TestClearMap, case1) {
  Set<int> mp;
  mp.Insert(4);
  mp.Insert(1);
  mp.Clear();
  ASSERT_EQ(mp.Size(), 0);
}

TEST(TestInsert, case1) {
  Set<int> mp;
  std::set<int> mp_eq;
  int i = 25;
  int j = 24;
  while (i > 0) {
    mp.Insert(i);
    mp.Insert(j);
    mp_eq.insert(i);
    mp_eq.insert(j);
    --i;
    ++j;
  }
  Set<int>::iterator iter = mp.Begin();
  auto iter_std = mp_eq.begin();
  for (; iter_std != mp_eq.end(); ++iter_std, ++iter) {
    ASSERT_EQ(*iter, *iter_std);
  }
}

TEST(TestInsert, case2) {
  Set<int> mp;
  std::set<int> mp_eq;
  int i = 25;
  int j = 24;
  while (i > 0) {
    mp.Insert(i);
    mp.Insert(j);
    mp_eq.insert(i);
    mp_eq.insert(j);
    --i;
    ++j;
  }
  auto iter = mp.End();
  --iter;
  auto iter_std = mp_eq.end();
  --iter_std;
  for (; iter_std != mp_eq.begin(); --iter_std, --iter) {
    ASSERT_EQ(*iter, *iter_std);
  }
}

TEST(TestErase, CaseDeleteLeftWithBlackTwoRedSon) {  // +
  Set<int> mp;
  int i = 25;
  int j = 24;
  while (i > 0) {
    mp.Insert(i);
    mp.Insert(j);
    --i;
    ++j;
  }
  Set<int>::iterator iter = mp.Begin();
  ++iter;
  mp.Erase(iter);
}

TEST(TestErase, CaseDeleteRightWithBlackTwoRedSon) {  // +
  Set<int> mp;
  int i = 25;
  int j = 24;
  while (i > 11) {
    mp.Insert(i);
    mp.Insert(j);
    --i;
    ++j;
  }
  Set<int>::iterator iter = mp.End();
  --iter;
  mp.Erase(iter);
}

TEST(TestErase, CaseDeleteLeftWithBlackOneRightRedSon) {  // +
  Set<int> mp;
  int i = 25;
  int j = 24;
  while (i > 0) {
    mp.Insert(i);
    mp.Insert(j);
    --i;
    ++j;
  }
  Set<int>::iterator iter = mp.Begin();
  mp.Erase(iter);

  Set<int>::iterator iter2 = mp.Begin();
  mp.Erase(iter2);
}

TEST(TestErase, CaseDeleteLeftWithBlackOneLeftRedSon) {  // +
  Set<int> mp;
  int i = 25;
  int j = 24;
  while (i > 0) {
    mp.Insert(i);
    mp.Insert(j);
    --i;
    ++j;
  }
  Set<int>::iterator iter = mp.Begin();
  ++iter;
  ++iter;
  mp.Erase(iter);

  Set<int>::iterator iter2 = mp.Begin();
  ++iter2;
  mp.Erase(iter2);
}

TEST(TestErase, CaseDeleteRightWithBlackOneRightRedSon) {  // +
  Set<int> mp;
  int i = 25;
  int j = 24;
  while (i > 11) {
    mp.Insert(i);
    mp.Insert(j);
    --i;
    ++j;
  }
  Set<int>::iterator iter = mp.End();
  --iter;
  --iter;
  mp.Erase(iter);

  Set<int>::iterator iter2 = mp.End();
  --iter2;
  mp.Erase(iter2);
}

TEST(TestErase, CaseDeleteRightWithBlackOneLeftRedSon) {  // +
  Set<int> mp;
  int i = 25;
  int j = 24;
  while (i > 11) {
    mp.Insert(i);
    mp.Insert(j);
    --i;
    ++j;
  }
  Set<int>::iterator iter = --mp.End();
  mp.Erase(iter);

  Set<int>::iterator iter2 = --mp.End();
  mp.Erase(iter2);
}

TEST(TestErase,
     CaseDeleteLeftBlackWithNotSonBrotherRightBlackNotSonParentRed) {  // +
  Set<int> mp;
  int i = 25;
  int j = 24;
  while (i > 0) {
    mp.Insert(i);
    mp.Insert(j);
    --i;
    ++j;
  }
  // 1
  Set<int>::iterator iter = mp.Begin();
  mp.Erase(iter);

  // 2
  Set<int>::iterator iter2 = mp.Begin();
  mp.Erase(iter2);

  // 3
  Set<int>::iterator iter3 = mp.Begin();
  mp.Erase(iter3);
}

TEST(TestErase,
     CaseDeleteRightBlackWithNotSonBrotherLeftBlackNotSonParentRed) {  // +
  Set<int> mp;
  int i = 25;
  int j = 24;
  while (i > 0) {
    mp.Insert(i);
    mp.Insert(j);
    --i;
    ++j;
  }
  // 1
  Set<int>::iterator iter = mp.Begin();
  mp.Erase(iter);

  // 2
  Set<int>::iterator iter2 = mp.Begin();
  mp.Erase(iter2);

  // 5
  Set<int>::iterator iter3 = mp.Begin();
  ++iter3;
  ++iter3;
  mp.Erase(iter3);
}

TEST(TestErase, CaseDeleteRightBrotherLeftWithRedLeftSonParentBlack) {  // +
  Set<int> mp;
  int i = 25;
  int j = 24;
  while (i > 0) {
    mp.Insert(i);
    mp.Insert(j);
    --i;
    ++j;
  }

  // 1
  Set<int>::iterator iter = mp.Begin();
  mp.Erase(iter);

  // 2
  Set<int>::iterator iter2 = mp.Begin();
  mp.Erase(iter2);

  // 5
  Set<int>::iterator iter3 = mp.Begin();
  ++iter3;
  ++iter3;
  mp.Erase(iter3);

  // 7
  Set<int>::iterator iter4 = mp.Begin();
  ++iter4;
  ++iter4;
  ++iter4;
  mp.Erase(iter4);
}

TEST(TestErase, CaseDeleteLeftBrotherLeftBlackWithNotSonParentBlack) {  // +
  Set<int> mp;
  int i = 25;
  int j = 24;
  while (i > 0) {
    mp.Insert(i);
    mp.Insert(j);
    --i;
    ++j;
  }
  // 1
  Set<int>::iterator iter = mp.Begin();
  mp.Erase(iter);

  // 2
  Set<int>::iterator iter2 = mp.Begin();
  mp.Erase(iter2);

  // 5
  Set<int>::iterator iter3 = mp.Begin();
  ++iter3;
  ++iter3;
  mp.Erase(iter3);

  Set<int>::iterator iter4 = mp.Begin();
  mp.Erase(iter4);

  Set<int>::iterator iter5 = mp.Begin();
  mp.Erase(iter5);
}

TEST(TestErase, CaseDeleteRightBrotherLeftWithRedSonRightParentRed) {  // +
  Set<int> mp;
  int i = 25;
  int j = 24;
  while (i > 0) {
    mp.Insert(i);
    mp.Insert(j);
    --i;
    ++j;
  }

  // 1
  Set<int>::iterator iter = mp.Begin();
  mp.Erase(iter);

  // 5
  Set<int>::iterator iter2 = mp.Begin();
  ++iter2;
  ++iter2;
  ++iter2;
  mp.Erase(iter2);
}

TEST(TestErase, CaseDeleteRightBrotherLeftRedWithTwoSonParentBlack) {  // +
  Set<int> mp;
  int i = 25;
  int j = 24;
  while (i > 0) {
    mp.Insert(i);
    mp.Insert(j);
    --i;
    ++j;
  }

  // 1
  Set<int>::iterator iter = mp.Begin();
  mp.Erase(iter);

  // 7
  Set<int>::iterator iter2 = mp.Begin();
  ++iter2;
  ++iter2;
  ++iter2;
  ++iter2;
  ++iter2;
  mp.Erase(iter2);
}

TEST(TestErase,
     CaseDeleteBlackRightBrotherLeftBlackWithNotSonParentBlack) {  // +
  Set<int> mp;
  int i = 25;
  int j = 24;
  while (i > 0) {
    mp.Insert(i);
    mp.Insert(j);
    --i;
    ++j;
  }

  // 1
  Set<int>::iterator iter = mp.Begin();
  mp.Erase(iter);

  // 3
  Set<int>::iterator iter2 = mp.Begin();
  ++iter2;
  mp.Erase(iter2);

  // 2
  Set<int>::iterator iter3 = mp.Begin();
  mp.Erase(iter3);

  // 5
  Set<int>::iterator iter4 = mp.Begin();
  ++iter4;
  mp.Erase(iter4);

  // 7
  Set<int>::iterator iter5 = mp.Begin();
  ++iter5;
  ++iter5;
  mp.Erase(iter5);
}

TEST(TestErase,
     CaseDeleteBlackLeftBrotherLeftBlackWithNotSonParentBlack) {  // +
  Set<int> mp;
  int i = 25;
  int j = 24;
  while (i > 0) {
    mp.Insert(i);
    mp.Insert(j);
    --i;
    ++j;
  }

  // 1
  Set<int>::iterator iter = mp.Begin();
  mp.Erase(iter);

  // 3
  Set<int>::iterator iter2 = mp.Begin();
  ++iter2;
  mp.Erase(iter2);

  // 2
  Set<int>::iterator iter3 = mp.Begin();
  mp.Erase(iter3);

  // 5
  Set<int>::iterator iter4 = mp.Begin();
  ++iter4;
  mp.Erase(iter4);

  // 4
  Set<int>::iterator iter5 = mp.Begin();
  mp.Erase(iter5);
}

TEST(TestErase, CaseRightDeleteLeftBrotherRightBlackWithNotSon) {  // +
  Set<int> mp;
  int i = 25;
  int j = 24;
  while (i > 0) {
    mp.Insert(i);
    mp.Insert(j);
    --i;
    ++j;
  }
  Set<int>::iterator iter = mp.Begin();
  mp.Erase(iter);

  Set<int>::iterator iter2 = mp.Begin();
  ++iter2;
  mp.Erase(iter2);

  Set<int>::iterator iter3 = mp.Begin();
  mp.Erase(iter3);

  Set<int>::iterator iter4 = mp.Begin();
  ++iter4;
  mp.Erase(iter4);

  Set<int>::iterator iter5 = mp.Begin();
  ++iter5;
  ++iter5;
  ++iter5;
  ++iter5;
  mp.Erase(iter5);
}

TEST(TestErase, CaseRightDeleteRightBrotherRightBlackWithNotSon) {  // +
  Set<int> mp;
  int i = 25;
  int j = 24;
  while (i > 0) {
    mp.Insert(i);
    mp.Insert(j);
    --i;
    ++j;
  }
  Set<int>::iterator iter = mp.Begin();
  mp.Erase(iter);

  Set<int>::iterator iter2 = mp.Begin();
  ++iter2;
  mp.Erase(iter2);

  Set<int>::iterator iter3 = mp.Begin();
  mp.Erase(iter3);

  Set<int>::iterator iter4 = mp.Begin();
  ++iter4;
  mp.Erase(iter4);

  Set<int>::iterator iter5 = mp.Begin();
  ++iter5;
  ++iter5;
  ++iter5;
  ++iter5;
  ++iter5;
  ++iter5;
  mp.Erase(iter5);
}

// delete left node

TEST(TestErase, CaseDeleteLeftNodeBrotherRightWithNotSonParentRed) {  // +
  Set<int> mp;
  int i = 25;
  int j = 24;
  while (i > 0) {
    mp.Insert(i);
    mp.Insert(j);
    --i;
    ++j;
  }

  // 1
  Set<int>::iterator iter = mp.Begin();
  mp.Erase(iter);

  // 3
  Set<int>::iterator iter2 = mp.Begin();
  ++iter2;
  mp.Erase(iter2);

  // 2
  Set<int>::iterator iter3 = mp.Begin();
  mp.Erase(iter3);

  // 5
  Set<int>::iterator iter4 = mp.Begin();
  ++iter4;
  mp.Erase(iter4);

  // 4
  Set<int>::iterator iter5 = mp.Begin();
  mp.Erase(iter5);

  // 6
  Set<int>::iterator iter6 = mp.Begin();
  mp.Erase(iter6);

  // 7
  Set<int>::iterator iter7 = mp.Begin();
  mp.Erase(iter7);
}

TEST(TestErase, CaseLeftDeleteLeftNodeBrotherRightWithRightRedSon) {  // +
  Set<int> mp;
  int i = 25;
  int j = 24;
  while (i > 0) {
    mp.Insert(i);
    mp.Insert(j);
    --i;
    ++j;
  }

  // 45
  Set<int>::iterator iter = mp.End();
  --iter;
  --iter;
  --iter;
  mp.Erase(iter);
}

TEST(TestErase, CaseLeftDeleteLeftNodeBrotherRightWithLeftRedSon) {  // +
  Set<int> mp;
  int i = 25;
  int j = 24;
  while (i > 0) {
    mp.Insert(i);
    mp.Insert(j);
    --i;
    ++j;
  }
  // 45
  Set<int>::iterator iter = mp.End();
  --iter;
  --iter;
  --iter;
  mp.Erase(iter);

  // 48
  Set<int>::iterator iter2 = --mp.End();
  mp.Erase(iter2);

  // 43
  Set<int>::iterator iter3 = mp.End();
  --iter3;
  --iter3;
  --iter3;
  mp.Erase(iter3);

  // 41
  Set<int>::iterator iter4 = mp.End();
  --iter4;
  --iter4;
  --iter4;
  --iter4;
  mp.Erase(iter4);

  // 42
  Set<int>::iterator iter5 = mp.End();
  --iter5;
  --iter5;
  --iter5;
  mp.Erase(iter5);
}

TEST(TestErase, case_dop1) {  // -
  Set<int> mp;
  int i = 25;
  int j = 24;
  while (i > 0) {
    mp.Insert(i);
    mp.Insert(j);
    --i;
    ++j;
  }
  Set<int>::iterator iter = mp.Begin();
  mp.Erase(iter);

  Set<int>::iterator iter2 = mp.Begin();
  ++iter2;
  ++iter2;
  ++iter2;
  ++iter2;
  ++iter2;
  ++iter2;
  ++iter2;
  ++iter2;
  ++iter2;
  mp.Erase(iter2);
}

TEST(TestErase, case_dop2) {
  Set<int> mp;
  int i = 25;
  int j = 24;
  while (i > 0) {
    mp.Insert(i);
    mp.Insert(j);
    --i;
    ++j;
  }
  Set<int>::iterator iter = mp.Begin();
  mp.Erase(iter);

  Set<int>::iterator iter2 = mp.Begin();
  ++iter2;
  ++iter2;
  ++iter2;
  ++iter2;
  ++iter2;
  ++iter2;
  ++iter2;
  mp.Erase(iter2);
}
// endregion

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
