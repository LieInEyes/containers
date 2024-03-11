#include <gtest/gtest.h>

#include <map>

#include "../containers.h"

using namespace my_space;

// region not my tests
TEST(TestEraseEasy, case1) {
  Map<int, int> mp;
  mp.Insert({4, 6});
  mp.InsertOrAssign(4, 9);
  mp.InsertOrAssign(5, 8);
  mp.Insert({5, 9});
  Map<int, int>::iterator iter = mp.Begin();
  ++iter;
  mp.Erase(iter);

  // std
  std::map<int, int> mp_eq;
  mp_eq.insert({4, 6});
  mp_eq.insert_or_assign(4, 9);
  mp_eq.insert_or_assign(5, 8);
  mp_eq.insert({5, 9});
  auto iter_std = mp_eq.begin();
  ++iter_std;
  mp_eq.erase(iter_std);

  ASSERT_EQ(mp.Size(), mp_eq.size());
  ASSERT_EQ(mp.At(4), mp_eq.at(4));
}

TEST(TestEraseEasy, case2) {
  Map<int, int> mp;
  mp.Insert({7, 6});
  mp.Insert({3, 8});
  mp.Insert({9, 9});
  mp.Insert({2, 1});
  mp.Insert({5, 4});
  mp.Insert({8, 0});
  mp.Insert({1, 5});
  mp.Insert({4, 3});
  mp.Insert({6, 2});
  Map<int, int>::iterator iter = mp.Begin();
  ++iter;
  mp.Erase(iter);

  // std
  std::map<int, int> mp_eq;
  mp_eq.insert({7, 6});
  mp_eq.insert({3, 8});
  mp_eq.insert({9, 9});
  mp_eq.insert({2, 1});
  mp_eq.insert({5, 4});
  mp_eq.insert({8, 0});
  mp_eq.insert({1, 5});
  mp_eq.insert({4, 3});
  mp_eq.insert({6, 2});
  auto iter_std = mp_eq.begin();
  ++iter_std;
  mp_eq.erase(iter_std);

  ASSERT_EQ(mp.Size(), mp_eq.size());
  ASSERT_EQ(mp.At(7), mp_eq.at(7));
  ASSERT_EQ(mp.At(3), mp_eq.at(3));
  ASSERT_EQ(mp.At(9), mp_eq.at(9));
  EXPECT_THROW(mp.At(2), std::out_of_range);
  EXPECT_THROW(mp_eq.at(2), std::out_of_range);
  ASSERT_EQ(mp.At(5), mp_eq.at(5));
  ASSERT_EQ(mp.At(8), mp_eq.at(8));
  ASSERT_EQ(mp.At(1), mp_eq.at(1));
  ASSERT_EQ(mp.At(4), mp_eq.at(4));
  ASSERT_EQ(mp.At(6), mp_eq.at(6));
}

TEST(TestClearMap, case1) {
  Map<int, int> mp;
  mp.Insert(4, 6);
  mp.Insert(1, 9);
  mp.Clear();
  ASSERT_EQ(mp.Size(), 0);
}

TEST(TestInsert, case1) {
  Map<int, int> mp;
  std::map<int, int> mp_eq;
  int i = 25;
  int j = 24;
  while (i > 0) {
    mp.Insert({i, i + 10});
    mp.Insert({j, i + 10});
    mp_eq.insert({i, i + 10});
    mp_eq.insert({j, i + 10});
    --i;
    ++j;
  }
  Map<int, int>::iterator iter = mp.Begin();
  auto iter_std = mp_eq.begin();
  for (; iter_std != mp_eq.end(); ++iter_std, ++iter) {
    ASSERT_EQ(iter->first, iter_std->first);
  }
}

TEST(TestInsert, case2) {
  Map<int, int> mp;
  std::map<int, int> mp_eq;
  int i = 25;
  int j = 24;
  while (i > 0) {
    mp.Insert({i, i + 10});
    mp.Insert({j, i + 10});
    mp_eq.insert({i, i + 10});
    mp_eq.insert({j, i + 10});
    --i;
    ++j;
  }
  auto iter = mp.End();
  --iter;
  auto iter_std = mp_eq.end();
  --iter_std;
  for (; iter_std != mp_eq.begin(); --iter_std, --iter) {
    std::cout << iter->first << " " << iter_std->first << std::endl;
    ASSERT_EQ(iter->first, iter_std->first);
  }
}

TEST(TestErase, CaseDeleteLeftWithBlackTwoRedSon) {  // +
  Map<int, int> mp;
  int i = 25;
  int j = 24;
  while (i > 0) {
    mp.Insert({i, i + 10});
    mp.Insert({j, i + 10});
    --i;
    ++j;
  }
  Map<int, int>::iterator iter = mp.Begin();
  ++iter;
  mp.Erase(iter);
}

TEST(TestErase, CaseDeleteRightWithBlackTwoRedSon) {  // +
  Map<int, int> mp;
  int i = 25;
  int j = 24;
  while (i > 11) {
    mp.Insert({i, i + 10});
    mp.Insert({j, i + 10});
    --i;
    ++j;
  }
  Map<int, int>::iterator iter = mp.End();
  --iter;
  mp.Erase(iter);
}

TEST(TestErase, CaseDeleteLeftWithBlackOneRightRedSon) {  // +
  Map<int, int> mp;
  int i = 25;
  int j = 24;
  while (i > 0) {
    mp.Insert({i, i + 10});
    mp.Insert({j, i + 10});
    --i;
    ++j;
  }
  Map<int, int>::iterator iter = mp.Begin();
  mp.Erase(iter);

  Map<int, int>::iterator iter2 = mp.Begin();
  mp.Erase(iter2);
}

TEST(TestErase, CaseDeleteLeftWithBlackOneLeftRedSon) {  // +
  Map<int, int> mp;
  int i = 25;
  int j = 24;
  while (i > 0) {
    mp.Insert({i, i + 10});
    mp.Insert({j, i + 10});
    --i;
    ++j;
  }
  Map<int, int>::iterator iter = mp.Begin();
  ++iter;
  ++iter;
  mp.Erase(iter);

  Map<int, int>::iterator iter2 = mp.Begin();
  ++iter2;
  mp.Erase(iter2);
}

TEST(TestErase, CaseDeleteRightWithBlackOneRightRedSon) {  // +
  Map<int, int> mp;
  int i = 25;
  int j = 24;
  while (i > 11) {
    mp.Insert({i, i + 10});
    mp.Insert({j, i + 10});
    --i;
    ++j;
  }
  Map<int, int>::iterator iter = mp.End();
  --iter;
  --iter;
  mp.Erase(iter);

  Map<int, int>::iterator iter2 = mp.End();
  --iter2;
  mp.Erase(iter2);
}

TEST(TestErase, CaseDeleteRightWithBlackOneLeftRedSon) {  // +
  Map<int, int> mp;
  int i = 25;
  int j = 24;
  while (i > 11) {
    mp.Insert({i, i + 10});
    mp.Insert({j, i + 10});
    --i;
    ++j;
  }
  Map<int, int>::iterator iter = --mp.End();
  mp.Erase(iter);

  Map<int, int>::iterator iter2 = --mp.End();
  mp.Erase(iter2);
}

TEST(TestErase,
     CaseDeleteLeftBlackWithNotSonBrotherRightBlackNotSonParentRed) {  // +
  Map<int, int> mp;
  int i = 25;
  int j = 24;
  while (i > 0) {
    mp.Insert({i, i + 10});
    mp.Insert({j, i + 10});
    --i;
    ++j;
  }
  // 1
  Map<int, int>::iterator iter = mp.Begin();
  mp.Erase(iter);

  // 2
  Map<int, int>::iterator iter2 = mp.Begin();
  mp.Erase(iter2);

  // 3
  Map<int, int>::iterator iter3 = mp.Begin();
  mp.Erase(iter3);
}

TEST(TestErase,
     CaseDeleteRightBlackWithNotSonBrotherLeftBlackNotSonParentRed) {  // +
  Map<int, int> mp;
  int i = 25;
  int j = 24;
  while (i > 0) {
    mp.Insert({i, i + 10});
    mp.Insert({j, i + 10});
    --i;
    ++j;
  }
  // 1
  Map<int, int>::iterator iter = mp.Begin();
  mp.Erase(iter);

  // 2
  Map<int, int>::iterator iter2 = mp.Begin();
  mp.Erase(iter2);

  // 5
  Map<int, int>::iterator iter3 = mp.Begin();
  ++iter3;
  ++iter3;
  mp.Erase(iter3);
}

TEST(TestErase, CaseDeleteRightBrotherLeftWithRedLeftSonParentBlack) {  // +
  Map<int, int> mp;
  int i = 25;
  int j = 24;
  while (i > 0) {
    mp.Insert({i, i + 10});
    mp.Insert({j, i + 10});
    --i;
    ++j;
  }

  // 1
  Map<int, int>::iterator iter = mp.Begin();
  mp.Erase(iter);

  // 2
  Map<int, int>::iterator iter2 = mp.Begin();
  mp.Erase(iter2);

  // 5
  Map<int, int>::iterator iter3 = mp.Begin();
  ++iter3;
  ++iter3;
  mp.Erase(iter3);

  // 7
  Map<int, int>::iterator iter4 = mp.Begin();
  ++iter4;
  ++iter4;
  ++iter4;
  mp.Erase(iter4);
}

TEST(TestErase, CaseDeleteLeftBrotherLeftBlackWithNotSonParentBlack) {  // +
  Map<int, int> mp;
  int i = 25;
  int j = 24;
  while (i > 0) {
    mp.Insert({i, i + 10});
    mp.Insert({j, i + 10});
    --i;
    ++j;
  }
  // 1
  Map<int, int>::iterator iter = mp.Begin();
  std::cout << iter->first << std::endl;
  mp.Erase(iter);

  // 2
  Map<int, int>::iterator iter2 = mp.Begin();
  std::cout << iter2->first << std::endl;
  mp.Erase(iter2);

  // 5
  Map<int, int>::iterator iter3 = mp.Begin();
  ++iter3;
  ++iter3;
  mp.Erase(iter3);

  Map<int, int>::iterator iter4 = mp.Begin();
  mp.Erase(iter4);

  Map<int, int>::iterator iter5 = mp.Begin();
  mp.Erase(iter5);
}

TEST(TestErase, CaseDeleteRightBrotherLeftWithRedSonRightParentRed) {  // +
  Map<int, int> mp;
  int i = 25;
  int j = 24;
  while (i > 0) {
    mp.Insert({i, i + 10});
    mp.Insert({j, i + 10});
    --i;
    ++j;
  }

  // 1
  Map<int, int>::iterator iter = mp.Begin();
  mp.Erase(iter);

  // 5
  Map<int, int>::iterator iter2 = mp.Begin();
  ++iter2;
  ++iter2;
  ++iter2;
  mp.Erase(iter2);
}

TEST(TestErase, CaseDeleteRightBrotherLeftRedWithTwoSonParentBlack) {  // +
  Map<int, int> mp;
  int i = 25;
  int j = 24;
  while (i > 0) {
    mp.Insert({i, i + 10});
    mp.Insert({j, i + 10});
    --i;
    ++j;
  }

  // 1
  Map<int, int>::iterator iter = mp.Begin();
  mp.Erase(iter);

  // 7
  Map<int, int>::iterator iter2 = mp.Begin();
  ++iter2;
  ++iter2;
  ++iter2;
  ++iter2;
  ++iter2;
  mp.Erase(iter2);
}

TEST(TestErase,
     CaseDeleteBlackRightBrotherLeftBlackWithNotSonParentBlack) {  // +
  Map<int, int> mp;
  int i = 25;
  int j = 24;
  while (i > 0) {
    mp.Insert({i, i + 10});
    mp.Insert({j, i + 10});
    --i;
    ++j;
  }

  // 1
  Map<int, int>::iterator iter = mp.Begin();
  mp.Erase(iter);

  // 3
  Map<int, int>::iterator iter2 = mp.Begin();
  ++iter2;
  mp.Erase(iter2);

  // 2
  Map<int, int>::iterator iter3 = mp.Begin();
  mp.Erase(iter3);

  // 5
  Map<int, int>::iterator iter4 = mp.Begin();
  ++iter4;
  mp.Erase(iter4);

  // 7
  Map<int, int>::iterator iter5 = mp.Begin();
  ++iter5;
  ++iter5;
  mp.Erase(iter5);
}

TEST(TestErase,
     CaseDeleteBlackLeftBrotherLeftBlackWithNotSonParentBlack) {  // +
  Map<int, int> mp;
  int i = 25;
  int j = 24;
  while (i > 0) {
    mp.Insert({i, i + 10});
    mp.Insert({j, i + 10});
    --i;
    ++j;
  }

  // 1
  Map<int, int>::iterator iter = mp.Begin();
  mp.Erase(iter);

  // 3
  Map<int, int>::iterator iter2 = mp.Begin();
  ++iter2;
  mp.Erase(iter2);

  // 2
  Map<int, int>::iterator iter3 = mp.Begin();
  mp.Erase(iter3);

  // 5
  Map<int, int>::iterator iter4 = mp.Begin();
  ++iter4;
  mp.Erase(iter4);

  // 4
  Map<int, int>::iterator iter5 = mp.Begin();
  mp.Erase(iter5);
}

TEST(TestErase, CaseRightDeleteLeftBrotherRightBlackWithNotSon) {  // +
  Map<int, int> mp;
  int i = 25;
  int j = 24;
  while (i > 0) {
    mp.Insert({i, i + 10});
    mp.Insert({j, i + 10});
    --i;
    ++j;
  }
  Map<int, int>::iterator iter = mp.Begin();
  mp.Erase(iter);

  Map<int, int>::iterator iter2 = mp.Begin();
  ++iter2;
  mp.Erase(iter2);

  Map<int, int>::iterator iter3 = mp.Begin();
  mp.Erase(iter3);

  Map<int, int>::iterator iter4 = mp.Begin();
  ++iter4;
  mp.Erase(iter4);

  Map<int, int>::iterator iter5 = mp.Begin();
  ++iter5;
  ++iter5;
  ++iter5;
  ++iter5;
  mp.Erase(iter5);
}

TEST(TestErase, CaseRightDeleteRightBrotherRightBlackWithNotSon) {  // +
  Map<int, int> mp;
  int i = 25;
  int j = 24;
  while (i > 0) {
    mp.Insert({i, i + 10});
    mp.Insert({j, i + 10});
    --i;
    ++j;
  }
  Map<int, int>::iterator iter = mp.Begin();
  mp.Erase(iter);

  Map<int, int>::iterator iter2 = mp.Begin();
  ++iter2;
  mp.Erase(iter2);

  Map<int, int>::iterator iter3 = mp.Begin();
  mp.Erase(iter3);

  Map<int, int>::iterator iter4 = mp.Begin();
  ++iter4;
  mp.Erase(iter4);

  Map<int, int>::iterator iter5 = mp.Begin();
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
  Map<int, int> mp;
  int i = 25;
  int j = 24;
  while (i > 0) {
    mp.Insert({i, i + 10});
    mp.Insert({j, i + 10});
    --i;
    ++j;
  }

  // 1
  Map<int, int>::iterator iter = mp.Begin();
  mp.Erase(iter);

  // 3
  Map<int, int>::iterator iter2 = mp.Begin();
  ++iter2;
  mp.Erase(iter2);

  // 2
  Map<int, int>::iterator iter3 = mp.Begin();
  mp.Erase(iter3);

  // 5
  Map<int, int>::iterator iter4 = mp.Begin();
  ++iter4;
  mp.Erase(iter4);

  // 4
  Map<int, int>::iterator iter5 = mp.Begin();
  mp.Erase(iter5);

  // 6
  Map<int, int>::iterator iter6 = mp.Begin();
  mp.Erase(iter6);

  // 7
  Map<int, int>::iterator iter7 = mp.Begin();
  mp.Erase(iter7);
}

TEST(TestErase, CaseLeftDeleteLeftNodeBrotherRightWithRightRedSon) {  // +
  Map<int, int> mp;
  int i = 25;
  int j = 24;
  while (i > 0) {
    mp.Insert({i, i + 10});
    mp.Insert({j, i + 10});
    --i;
    ++j;
  }

  // 45
  Map<int, int>::iterator iter = mp.End();
  --iter;
  --iter;
  --iter;
  std::cout << iter->first << std::endl;
  mp.Erase(iter);
}

TEST(TestErase, CaseLeftDeleteLeftNodeBrotherRightWithLeftRedSon) {  // +
  Map<int, int> mp;
  int i = 25;
  int j = 24;
  while (i > 0) {
    mp.Insert({i, i + 10});
    mp.Insert({j, i + 10});
    --i;
    ++j;
  }
  // 45
  Map<int, int>::iterator iter = mp.End();
  --iter;
  --iter;
  --iter;
  mp.Erase(iter);

  // 48
  Map<int, int>::iterator iter2 = --mp.End();
  mp.Erase(iter2);

  // 43
  Map<int, int>::iterator iter3 = mp.End();
  --iter3;
  --iter3;
  --iter3;
  mp.Erase(iter3);

  // 41
  Map<int, int>::iterator iter4 = mp.End();
  --iter4;
  --iter4;
  --iter4;
  --iter4;
  mp.Erase(iter4);

  // 42
  Map<int, int>::iterator iter5 = mp.End();
  --iter5;
  --iter5;
  --iter5;
  mp.Erase(iter5);
}

TEST(TestErase, case_dop1) {  // -
  Map<int, int> mp;
  int i = 25;
  int j = 24;
  while (i > 0) {
    mp.Insert({i, i + 10});
    mp.Insert({j, i + 10});
    --i;
    ++j;
  }
  Map<int, int>::iterator iter = mp.Begin();
  mp.Erase(iter);

  Map<int, int>::iterator iter2 = mp.Begin();
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
  Map<int, int> mp;
  int i = 25;
  int j = 24;
  while (i > 0) {
    mp.Insert({i, i + 10});
    mp.Insert({j, i + 10});
    --i;
    ++j;
  }
  Map<int, int>::iterator iter = mp.Begin();
  mp.Erase(iter);

  Map<int, int>::iterator iter2 = mp.Begin();
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

// region my tests
TEST(MapConstructor, Default) {
  Map<int, int> my_map;
  std::map<int, int> std_map;
  ASSERT_EQ(my_map.Size(), std_map.size());
  ASSERT_EQ(my_map.Empty(), std_map.empty());
}

TEST(MapConstructor, InitializerList) {
  Map<int, int> my_map({{1, 1}, {2, 2}, {3, 3}, {4, 4}});
  std::map<int, int> std_map({{1, 1}, {2, 2}, {3, 3}, {4, 4}});
  ASSERT_EQ(my_map.Size(), std_map.size());
  ASSERT_EQ(my_map.Empty(), std_map.empty());
}

TEST(MapConstructor, CopyConstuctor) {
  Map<int, int> my_map_old({{1, 1}, {2, 2}, {3, 3}, {4, 4}});
  std::map<int, int> std_map_old({{1, 1}, {2, 2}, {3, 3}, {4, 4}});
  Map<int, int> my_map(my_map_old);
  std::map<int, int> std_map(std_map_old);
  ASSERT_EQ(my_map.Size(), std_map.size());
  ASSERT_EQ(my_map.Empty(), std_map.empty());
}

TEST(MapConstructor, MoveConstructor) {
  Map<int, int> my_map_old({{1, 1}, {2, 2}, {3, 3}, {4, 4}});
  std::map<int, int> std_map_old({{1, 1}, {2, 2}, {3, 3}, {4, 4}});
  Map<int, int> my_map = std::move(my_map_old);
  std::map<int, int> std_map = std::move(std_map_old);
  ASSERT_EQ(my_map.Size(), std_map.size());
  ASSERT_EQ(my_map.Empty(), std_map.empty());
}

TEST(MapGetValue, MethodAt) {
  Map<int, int> my_map({{1, 1}, {2, 2}, {3, 3}, {4, 4}});
  std::map<int, int> std_map({{1, 1}, {2, 2}, {3, 3}, {4, 4}});
  ASSERT_EQ(my_map.At(1), std_map.at(1));
  ASSERT_EQ(my_map.At(4), std_map.at(4));
  ASSERT_THROW(my_map.At(8), std::out_of_range);
}

TEST(MapGetValue, MethodBorder) {
  Map<int, int> my_map({{1, 1}, {2, 2}, {3, 3}, {4, 4}});
  std::map<int, int> std_map({{1, 1}, {2, 2}, {3, 3}, {4, 4}});
  ASSERT_EQ(my_map[1], std_map[1]);
  ASSERT_EQ(my_map[4], std_map[4]);
}

TEST(MapIterator, Begin) {
  Map<int, int> my_map({{1, 1}, {2, 2}, {3, 3}, {4, 4}});
  std::map<int, int> std_map({{1, 1}, {2, 2}, {3, 3}, {4, 4}});
  auto my_iter = my_map.Begin();
  auto std_iter = std_map.begin();
  for (; my_iter != my_map.End() && std_iter != std_map.end();
       ++my_iter, ++std_iter) {
    ASSERT_EQ(my_iter->first, std_iter->first);
    ASSERT_EQ(my_iter->second, std_iter->second);
  }
}

TEST(MapIterator, End) {
  Map<int, int> my_map({{1, 1}, {2, 2}, {3, 3}, {4, 4}});
  std::map<int, int> std_map({{1, 1}, {2, 2}, {3, 3}, {4, 4}});
  auto my_iter = my_map.End();
  auto std_iter = std_map.end();
  --my_iter;
  --std_iter;
  for (; my_iter != my_map.Begin() && std_iter != std_map.begin();
       --my_iter, --std_iter) {
    ASSERT_EQ(my_iter->first, std_iter->first);
    ASSERT_EQ(my_iter->second, std_iter->second);
  }
}

TEST(MapCopasity, Maxsize) {
  Map<int, int> my_map;
  std::map<int, int> std_map;
  ASSERT_EQ(my_map.Maxsize(), std_map.max_size());
}

TEST(MapModifiers, Clear) {
  Map<int, int> my_map({{1, 1}, {2, 2}, {3, 3}, {4, 4}});
  std::map<int, int> std_map({{1, 1}, {2, 2}, {3, 3}, {4, 4}});
  my_map.Clear();
  std_map.clear();
  ASSERT_EQ(my_map.Empty(), std_map.empty());
  ASSERT_EQ(my_map.Size(), std_map.size());
}

TEST(MapModifiers, Insert) {
  Map<int, int> my_map({{1, 1}, {2, 2}, {3, 3}, {4, 4}});
  std::map<int, int> std_map({{1, 1}, {2, 2}, {3, 3}, {4, 4}});
  my_map.Insert({5, 5});
  my_map.Insert(6, 6);
  std_map.insert({5, 5});
  std_map.insert({6, 6});
  ASSERT_EQ(my_map.Empty(), std_map.empty());
  ASSERT_EQ(my_map.Size(), std_map.size());
}

TEST(MapModifiers, Erase) {
  Map<int, int> my_map({{1, 1}, {2, 2}, {3, 3}, {4, 4}});
  std::map<int, int> std_map({{1, 1}, {2, 2}, {3, 3}, {4, 4}});
  my_map.Erase(my_map.Begin());
  std_map.erase(std_map.begin());
  ASSERT_EQ(my_map.Empty(), std_map.empty());
  ASSERT_EQ(my_map.Size(), std_map.size());
}

TEST(MapModifiers, Swap) {
  Map<int, int> my_map_one({{1, 1}, {2, 2}, {3, 3}, {4, 4}});
  Map<int, int> my_map_two({{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}});
  std::map<int, int> std_map_one({{1, 1}, {2, 2}, {3, 3}, {4, 4}});
  std::map<int, int> std_map_two({{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}});
  my_map_one.Swap(my_map_two);
  std_map_one.swap(std_map_two);
  ASSERT_EQ(my_map_one.Empty(), std_map_one.empty());
  ASSERT_EQ(my_map_one.Size(), std_map_one.size());
  ASSERT_EQ(my_map_two.Empty(), std_map_two.empty());
  ASSERT_EQ(my_map_two.Size(), std_map_two.size());
}

TEST(MapModifiers, Merge) {
  Map<int, int> my_map_one({{1, 1}, {2, 2}, {3, 3}, {4, 4}});
  Map<int, int> my_map_two({{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}});
  std::map<int, int> std_map_one({{1, 1}, {2, 2}, {3, 3}, {4, 4}});
  std::map<int, int> std_map_two({{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}});
  my_map_one.Merge(my_map_two);
  std_map_one.merge(std_map_two);
  ASSERT_EQ(my_map_one.Empty(), std_map_one.empty());
  ASSERT_EQ(my_map_one.Size(), std_map_one.size());
  ASSERT_EQ(my_map_two.Empty(), std_map_two.empty());
  ASSERT_EQ(my_map_two.Size(), std_map_two.size());
}

TEST(MapLookup, Contains) {
  Map<int, int> my_map({{1, 1}, {2, 2}, {3, 3}, {4, 4}});
  ASSERT_EQ(my_map.Contains(1), true);
  ASSERT_EQ(my_map.Contains(2), true);
  ASSERT_EQ(my_map.Contains(3), true);
  ASSERT_EQ(my_map.Contains(4), true);
  ASSERT_EQ(my_map.Contains(5), false);
}

TEST(MapBonus, Emplace) {
  Map<int, int> my_map;
  std::map<int, int> std_map;
  auto my_result = my_map.Emplace(1, 1);
  auto std_result = std_map.emplace(1, 1);
  ASSERT_EQ(my_result.second, std_result.second);
  ASSERT_EQ(my_result.first->first, std_result.first->first);
}
// endregion

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
