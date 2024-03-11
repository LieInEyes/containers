#include <gtest/gtest.h>

#include <set>

#include "../containersplus.h"

using namespace my_space;

TEST(MultisetConstructor, DefaultConstuct) {
  MultiSet<int> my_set;
  std::multiset<int> std_set;
  ASSERT_EQ(my_set.Size(), std_set.size());
}

TEST(MultisetConstructor, ParameterConstructor) {
  MultiSet<int> my_set({1, 1, 2, 3, 4});
  std::multiset<int> std_set({1, 1, 2, 3, 4});
  ASSERT_EQ(my_set.Size(), std_set.size());
}

TEST(MultisetConstructor, CopyConstructor) {
  MultiSet<int> my_set_old({1, 2, 3, 4});
  std::multiset<int> std_set_old({1, 2, 3, 4});
  MultiSet<int> my_set(my_set_old);
  std::multiset<int> std_set(std_set_old);
  ASSERT_EQ(my_set.Size(), std_set.size());
}

TEST(MultisetConstructor, MoveConstructor) {
  MultiSet<int> my_set_old({1, 2, 3, 4});
  std::multiset<int> std_set_old({1, 2, 3, 4});
  MultiSet<int> my_set = std::move(my_set_old);
  std::multiset<int> std_set = std::move(std_set_old);
  ASSERT_EQ(my_set.Size(), std_set.size());
}

TEST(MultisetBegin, NotEmpty) {
  MultiSet<int> my_set({1, 2, 3, 4});
  std::multiset<int> std_set({1, 2, 3, 4});
  ASSERT_EQ(*my_set.Begin(), *std_set.begin());
}

TEST(MultisetEnd, NotEmpty) {
  MultiSet<int> my_set({1, 2, 3, 4});
  std::multiset<int> std_set({1, 2, 3, 4});
  ASSERT_EQ(*(--my_set.End()), *(--std_set.end()));
}

TEST(MultisetEmpty, Empty) {
  MultiSet<int> my_set;
  std::multiset<int> std_set;
  ASSERT_EQ(my_set.Empty(), std_set.empty());
}

TEST(MultisetEmpty, NotEmpty) {
  MultiSet<int> my_set({1, 2, 3, 4});
  std::multiset<int> std_set({1, 2, 3, 4});
  ASSERT_EQ(my_set.Empty(), std_set.empty());
}

TEST(MultisetSize, Empty) {
  MultiSet<int> my_set;
  std::multiset<int> std_set;
  ASSERT_EQ(my_set.Size(), std_set.size());
}

TEST(MultisetSize, NotEmpty) {
  MultiSet<int> my_set({1, 2, 3, 4});
  std::multiset<int> std_set({1, 2, 3, 4});
  ASSERT_EQ(my_set.Size(), std_set.size());
}

TEST(MultisetMaxSize, Empty) {
  MultiSet<int> my_set;
  std::multiset<int> std_set;
  ASSERT_EQ(my_set.Maxsize(), std_set.max_size());
}

TEST(MultisetMaxSize, NotEmpty) {
  MultiSet<int> my_set({1, 2, 3, 4});
  std::multiset<int> std_set({1, 2, 3, 4});
  ASSERT_EQ(my_set.Maxsize(), std_set.max_size());
}

TEST(MultisetClear, Empty) {
  MultiSet<int> my_set;
  std::multiset<int> std_set;
  my_set.Clear();
  std_set.clear();
  ASSERT_EQ(my_set.Size(), std_set.size());
}

TEST(MultisetClear, NotEmpty) {
  MultiSet<int> my_set({1, 2, 3, 4});
  std::multiset<int> std_set({1, 2, 3, 4});
  my_set.Clear();
  std_set.clear();
  ASSERT_EQ(my_set.Size(), std_set.size());
}

TEST(MultisetInsert, Empty) {
  MultiSet<int> my_set;
  std::multiset<int> std_set;
  my_set.Insert(1);
  std_set.insert(1);
  ASSERT_EQ(my_set.Size(), std_set.size());
}

TEST(MultisetInsert, NotEmpty) {
  MultiSet<int> my_set({1, 2, 3, 4});
  std::multiset<int> std_set({1, 2, 3, 4});
  auto my_result = my_set.Insert(5);
  auto std_result = std_set.insert(5);
  ASSERT_EQ(my_set.Size(), std_set.size());
}

TEST(MultisetInsert, Duoble) {
  MultiSet<int> my_set({1, 2, 3, 4});
  std::multiset<int> std_set({1, 2, 3, 4});
  auto my_result = my_set.Insert(1);
  auto std_result = std_set.insert(1);
  ASSERT_EQ(my_set.Size(), std_set.size());
}

TEST(MultisetErase, Contains) {
  MultiSet<int> my_set({1, 2, 3, 4});
  std::multiset<int> std_set({1, 2, 3, 4});
  auto my_iter = ++my_set.Begin();
  auto std_iter = ++std_set.begin();
  my_set.Erase(my_iter);
  std_set.erase(std_iter);
  ASSERT_EQ(my_set.Size(), std_set.size());
}

TEST(MultisetSwap, Empty) {
  MultiSet<int> my_set_one;
  std::multiset<int> std_set_one;
  MultiSet<int> my_set_two;
  std::multiset<int> std_set_two;
  my_set_one.Swap(my_set_two);
  std_set_one.swap(std_set_two);
  ASSERT_EQ(my_set_one.Size(), std_set_one.size());
}

TEST(MultisetSwap, NotEmpty) {
  MultiSet<int> my_set_one({1, 2, 3});
  std::multiset<int> std_set_one({1, 2, 3});
  MultiSet<int> my_set_two({4, 5});
  std::multiset<int> std_set_two({4, 5});
  my_set_one.Swap(my_set_two);
  std_set_one.swap(std_set_two);
  ASSERT_EQ(my_set_one.Size(), std_set_one.size());
  ASSERT_EQ(my_set_two.Size(), std_set_two.size());
}

TEST(MultisetMerge, NotContains) {
  MultiSet<int> my_set({1, 2, 3, 4});
  std::multiset<int> std_set({1, 2, 3, 4});
  MultiSet<int> my_temp({5, 6, 7, 8});
  std::multiset<int> std_temp({5, 6, 7, 8});
  my_set.Merge(my_temp);
  std_set.merge(std_temp);
  ASSERT_EQ(my_set.Size(), std_set.size());
}

TEST(MultisetMerge, Contains) {
  MultiSet<int> my_set({1, 2, 3, 4});
  std::multiset<int> std_set({1, 2, 3, 4});
  MultiSet<int> my_temp({4, 5, 6, 7, 8});
  std::multiset<int> std_temp({4, 5, 6, 7, 8});
  my_set.Merge(my_temp);
  std_set.merge(std_temp);
  ASSERT_EQ(my_set.Size(), std_set.size());
}

TEST(MultisetMerge, WithEmpty) {
  MultiSet<int> my_set({1, 2, 3, 4});
  std::multiset<int> std_set({1, 2, 3, 4});
  MultiSet<int> my_temp;
  std::multiset<int> std_temp;
  my_set.Merge(my_temp);
  std_set.merge(std_temp);
  ASSERT_EQ(my_set.Size(), std_set.size());
}

TEST(MultisetFind, Contains) {
  MultiSet<int> my_set({1, 2, 3, 4});
  std::multiset<int> std_set({1, 2, 3, 4});
  ASSERT_EQ(*my_set.Find(1), *std_set.find(1));
}

TEST(MultisetFind, NotContains) {
  MultiSet<int> my_set({1, 2, 3, 4});
  ASSERT_EQ(my_set.Find(7), my_set.End());
}

TEST(MultisetComtains, Contains) {
  MultiSet<int> my_set({1, 2, 3, 4});
  std::multiset<int> std_set({1, 2, 3, 4});
  ASSERT_EQ(my_set.Contains(1), true);
}

TEST(MultisetFinComtainsd, NotContains) {
  MultiSet<int> my_set({1, 2, 3, 4});
  std::multiset<int> std_set({1, 2, 3, 4});
  ASSERT_EQ(my_set.Contains(7), false);
}

TEST(MultisetBonus, Emplace) {
  MultiSet<int> my_multiset;
  auto my_result = my_multiset.Emplace(1);
  ASSERT_EQ(my_result.second, true);
  ASSERT_EQ(*my_result.first, 1);
}

// region not my tests
TEST(TestEraseEasy, case2) {
  MultiSet<int> mp;
  mp.Insert(7);
  mp.Insert(3);
  mp.Insert(9);
  mp.Insert(2);
  mp.Insert(5);
  mp.Insert(8);
  mp.Insert(1);
  mp.Insert(4);
  mp.Insert(6);
  MultiSet<int>::iterator iter = mp.Begin();
  ++iter;
  mp.Erase(iter);

  // std
  std::multiset<int> mp_eq;
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
  MultiSet<int> mp;
  mp.Insert(4);
  mp.Insert(1);
  mp.Clear();
  ASSERT_EQ(mp.Size(), 0);
}

TEST(TestInsert, case2) {
  MultiSet<int> mp;
  std::multiset<int> mp_eq;
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
  MultiSet<int> mp;
  int i = 25;
  int j = 24;
  while (i > 0) {
    mp.Insert(i);
    mp.Insert(j);
    --i;
    ++j;
  }
  MultiSet<int>::iterator iter = mp.Begin();
  ++iter;
  mp.Erase(iter);
}

TEST(TestErase, CaseDeleteRightWithBlackTwoRedSon) {  // +
  MultiSet<int> mp;
  int i = 25;
  int j = 24;
  while (i > 11) {
    mp.Insert(i);
    mp.Insert(j);
    --i;
    ++j;
  }
  MultiSet<int>::iterator iter = mp.End();
  --iter;
  mp.Erase(iter);
}

TEST(TestErase, CaseDeleteLeftWithBlackOneRightRedSon) {  // +
  MultiSet<int> mp;
  int i = 25;
  int j = 24;
  while (i > 0) {
    mp.Insert(i);
    mp.Insert(j);
    --i;
    ++j;
  }
  MultiSet<int>::iterator iter = mp.Begin();
  mp.Erase(iter);

  MultiSet<int>::iterator iter2 = mp.Begin();
  mp.Erase(iter2);
}

TEST(TestErase, CaseDeleteLeftWithBlackOneLeftRedSon) {  // +
  MultiSet<int> mp;
  int i = 25;
  int j = 24;
  while (i > 0) {
    mp.Insert(i);
    mp.Insert(j);
    --i;
    ++j;
  }
  MultiSet<int>::iterator iter = mp.Begin();
  ++iter;
  ++iter;
  mp.Erase(iter);

  MultiSet<int>::iterator iter2 = mp.Begin();
  ++iter2;
  mp.Erase(iter2);
}

TEST(TestErase, CaseDeleteRightWithBlackOneRightRedSon) {  // +
  MultiSet<int> mp;
  int i = 25;
  int j = 24;
  while (i > 11) {
    mp.Insert(i);
    mp.Insert(j);
    --i;
    ++j;
  }
  MultiSet<int>::iterator iter = mp.End();
  --iter;
  --iter;
  mp.Erase(iter);

  MultiSet<int>::iterator iter2 = mp.End();
  --iter2;
  mp.Erase(iter2);
}

TEST(TestErase, CaseDeleteRightWithBlackOneLeftRedSon) {  // +
  MultiSet<int> mp;
  int i = 25;
  int j = 24;
  while (i > 11) {
    mp.Insert(i);
    mp.Insert(j);
    --i;
    ++j;
  }
  MultiSet<int>::iterator iter = --mp.End();
  mp.Erase(iter);

  MultiSet<int>::iterator iter2 = --mp.End();
  mp.Erase(iter2);
}

TEST(TestErase,
     CaseDeleteLeftBlackWithNotSonBrotherRightBlackNotSonParentRed) {  // +
  MultiSet<int> mp;
  int i = 25;
  int j = 24;
  while (i > 0) {
    mp.Insert(i);
    mp.Insert(j);
    --i;
    ++j;
  }
  // 1
  MultiSet<int>::iterator iter = mp.Begin();
  mp.Erase(iter);

  // 2
  MultiSet<int>::iterator iter2 = mp.Begin();
  mp.Erase(iter2);

  // 3
  MultiSet<int>::iterator iter3 = mp.Begin();
  mp.Erase(iter3);
}

TEST(TestErase,
     CaseDeleteRightBlackWithNotSonBrotherLeftBlackNotSonParentRed) {  // +
  MultiSet<int> mp;
  int i = 25;
  int j = 24;
  while (i > 0) {
    mp.Insert(i);
    mp.Insert(j);
    --i;
    ++j;
  }
  // 1
  MultiSet<int>::iterator iter = mp.Begin();
  mp.Erase(iter);

  // 2
  MultiSet<int>::iterator iter2 = mp.Begin();
  mp.Erase(iter2);

  // 5
  MultiSet<int>::iterator iter3 = mp.Begin();
  ++iter3;
  ++iter3;
  mp.Erase(iter3);
}

TEST(TestErase, CaseDeleteRightBrotherLeftWithRedLeftSonParentBlack) {  // +
  MultiSet<int> mp;
  int i = 25;
  int j = 24;
  while (i > 0) {
    mp.Insert(i);
    mp.Insert(j);
    --i;
    ++j;
  }

  // 1
  MultiSet<int>::iterator iter = mp.Begin();
  mp.Erase(iter);

  // 2
  MultiSet<int>::iterator iter2 = mp.Begin();
  mp.Erase(iter2);

  // 5
  MultiSet<int>::iterator iter3 = mp.Begin();
  ++iter3;
  ++iter3;
  mp.Erase(iter3);

  // 7
  MultiSet<int>::iterator iter4 = mp.Begin();
  ++iter4;
  ++iter4;
  ++iter4;
  mp.Erase(iter4);
}

TEST(TestErase, CaseDeleteLeftBrotherLeftBlackWithNotSonParentBlack) {  // +
  MultiSet<int> mp;
  int i = 25;
  int j = 24;
  while (i > 0) {
    mp.Insert(i);
    mp.Insert(j);
    --i;
    ++j;
  }
  // 1
  MultiSet<int>::iterator iter = mp.Begin();
  mp.Erase(iter);

  // 2
  MultiSet<int>::iterator iter2 = mp.Begin();
  mp.Erase(iter2);

  // 5
  MultiSet<int>::iterator iter3 = mp.Begin();
  ++iter3;
  ++iter3;
  mp.Erase(iter3);

  MultiSet<int>::iterator iter4 = mp.Begin();
  mp.Erase(iter4);

  MultiSet<int>::iterator iter5 = mp.Begin();
  mp.Erase(iter5);
}

TEST(TestErase, CaseDeleteRightBrotherLeftWithRedSonRightParentRed) {  // +
  MultiSet<int> mp;
  int i = 25;
  int j = 24;
  while (i > 0) {
    mp.Insert(i);
    mp.Insert(j);
    --i;
    ++j;
  }

  // 1
  MultiSet<int>::iterator iter = mp.Begin();
  mp.Erase(iter);

  // 5
  MultiSet<int>::iterator iter2 = mp.Begin();
  ++iter2;
  ++iter2;
  ++iter2;
  mp.Erase(iter2);
}

TEST(TestErase, CaseDeleteRightBrotherLeftRedWithTwoSonParentBlack) {  // +
  MultiSet<int> mp;
  int i = 25;
  int j = 24;
  while (i > 0) {
    mp.Insert(i);
    mp.Insert(j);
    --i;
    ++j;
  }

  // 1
  MultiSet<int>::iterator iter = mp.Begin();
  mp.Erase(iter);

  // 7
  MultiSet<int>::iterator iter2 = mp.Begin();
  ++iter2;
  ++iter2;
  ++iter2;
  ++iter2;
  ++iter2;
  mp.Erase(iter2);
}

TEST(TestErase,
     CaseDeleteBlackRightBrotherLeftBlackWithNotSonParentBlack) {  // +
  MultiSet<int> mp;
  int i = 25;
  int j = 24;
  while (i > 0) {
    mp.Insert(i);
    mp.Insert(j);
    --i;
    ++j;
  }

  // 1
  MultiSet<int>::iterator iter = mp.Begin();
  mp.Erase(iter);

  // 3
  MultiSet<int>::iterator iter2 = mp.Begin();
  ++iter2;
  mp.Erase(iter2);

  // 2
  MultiSet<int>::iterator iter3 = mp.Begin();
  mp.Erase(iter3);

  // 5
  MultiSet<int>::iterator iter4 = mp.Begin();
  ++iter4;
  mp.Erase(iter4);

  // 7
  MultiSet<int>::iterator iter5 = mp.Begin();
  ++iter5;
  ++iter5;
  mp.Erase(iter5);
}

TEST(TestErase,
     CaseDeleteBlackLeftBrotherLeftBlackWithNotSonParentBlack) {  // +
  MultiSet<int> mp;
  int i = 25;
  int j = 24;
  while (i > 0) {
    mp.Insert(i);
    mp.Insert(j);
    --i;
    ++j;
  }

  // 1
  MultiSet<int>::iterator iter = mp.Begin();
  mp.Erase(iter);

  // 3
  MultiSet<int>::iterator iter2 = mp.Begin();
  ++iter2;
  mp.Erase(iter2);

  // 2
  MultiSet<int>::iterator iter3 = mp.Begin();
  mp.Erase(iter3);

  // 5
  MultiSet<int>::iterator iter4 = mp.Begin();
  ++iter4;
  mp.Erase(iter4);

  // 4
  MultiSet<int>::iterator iter5 = mp.Begin();
  mp.Erase(iter5);
}

TEST(TestErase, CaseRightDeleteLeftBrotherRightBlackWithNotSon) {  // +
  MultiSet<int> mp;
  int i = 25;
  int j = 24;
  while (i > 0) {
    mp.Insert(i);
    mp.Insert(j);
    --i;
    ++j;
  }
  MultiSet<int>::iterator iter = mp.Begin();
  mp.Erase(iter);

  MultiSet<int>::iterator iter2 = mp.Begin();
  ++iter2;
  mp.Erase(iter2);

  MultiSet<int>::iterator iter3 = mp.Begin();
  mp.Erase(iter3);

  MultiSet<int>::iterator iter4 = mp.Begin();
  ++iter4;
  mp.Erase(iter4);

  MultiSet<int>::iterator iter5 = mp.Begin();
  ++iter5;
  ++iter5;
  ++iter5;
  ++iter5;
  mp.Erase(iter5);
}

TEST(TestErase, CaseRightDeleteRightBrotherRightBlackWithNotSon) {  // +
  MultiSet<int> mp;
  int i = 25;
  int j = 24;
  while (i > 0) {
    mp.Insert(i);
    mp.Insert(j);
    --i;
    ++j;
  }
  MultiSet<int>::iterator iter = mp.Begin();
  mp.Erase(iter);

  MultiSet<int>::iterator iter2 = mp.Begin();
  ++iter2;
  mp.Erase(iter2);

  MultiSet<int>::iterator iter3 = mp.Begin();
  mp.Erase(iter3);

  MultiSet<int>::iterator iter4 = mp.Begin();
  ++iter4;
  mp.Erase(iter4);

  MultiSet<int>::iterator iter5 = mp.Begin();
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
  MultiSet<int> mp;
  int i = 25;
  int j = 24;
  while (i > 0) {
    mp.Insert(i);
    mp.Insert(j);
    --i;
    ++j;
  }

  // 1
  MultiSet<int>::iterator iter = mp.Begin();
  mp.Erase(iter);

  // 3
  MultiSet<int>::iterator iter2 = mp.Begin();
  ++iter2;
  mp.Erase(iter2);

  // 2
  MultiSet<int>::iterator iter3 = mp.Begin();
  mp.Erase(iter3);

  // 5
  MultiSet<int>::iterator iter4 = mp.Begin();
  ++iter4;
  mp.Erase(iter4);

  // 4
  MultiSet<int>::iterator iter5 = mp.Begin();
  mp.Erase(iter5);

  // 6
  MultiSet<int>::iterator iter6 = mp.Begin();
  mp.Erase(iter6);

  // 7
  MultiSet<int>::iterator iter7 = mp.Begin();
  mp.Erase(iter7);
}

TEST(TestErase, CaseLeftDeleteLeftNodeBrotherRightWithRightRedSon) {  // +
  MultiSet<int> mp;
  int i = 25;
  int j = 24;
  while (i > 0) {
    mp.Insert(i);
    mp.Insert(j);
    --i;
    ++j;
  }

  // 45
  MultiSet<int>::iterator iter = mp.End();
  --iter;
  --iter;
  --iter;
  mp.Erase(iter);
}

TEST(TestErase, CaseLeftDeleteLeftNodeBrotherRightWithLeftRedSon) {  // +
  MultiSet<int> mp;
  int i = 25;
  int j = 24;
  while (i > 0) {
    mp.Insert(i);
    mp.Insert(j);
    --i;
    ++j;
  }
  // 45
  MultiSet<int>::iterator iter = mp.End();
  --iter;
  --iter;
  --iter;
  mp.Erase(iter);

  // 48
  MultiSet<int>::iterator iter2 = --mp.End();
  mp.Erase(iter2);

  // 43
  MultiSet<int>::iterator iter3 = mp.End();
  --iter3;
  --iter3;
  --iter3;
  mp.Erase(iter3);

  // 41
  MultiSet<int>::iterator iter4 = mp.End();
  --iter4;
  --iter4;
  --iter4;
  --iter4;
  mp.Erase(iter4);

  // 42
  MultiSet<int>::iterator iter5 = mp.End();
  --iter5;
  --iter5;
  --iter5;
  mp.Erase(iter5);
}

TEST(TestErase, case_dop1) {  // -
  MultiSet<int> mp;
  int i = 25;
  int j = 24;
  while (i > 0) {
    mp.Insert(i);
    mp.Insert(j);
    --i;
    ++j;
  }
  MultiSet<int>::iterator iter = mp.Begin();
  mp.Erase(iter);

  MultiSet<int>::iterator iter2 = mp.Begin();
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
  MultiSet<int> mp;
  int i = 25;
  int j = 24;
  while (i > 0) {
    mp.Insert(i);
    mp.Insert(j);
    --i;
    ++j;
  }
  MultiSet<int>::iterator iter = mp.Begin();
  mp.Erase(iter);

  MultiSet<int>::iterator iter2 = mp.Begin();
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
