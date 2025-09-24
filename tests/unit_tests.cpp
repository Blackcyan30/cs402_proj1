#include <gtest/gtest.h>

#include "../include/talha_khan_proj1.hpp"
#include "testing.hpp"

// TEST(SimpleTest, Basic) { EXPECT_EQ(1, 1); }

TEST(QuickSort, EmptyList) {
  std::vector<int> list = {};
  quicksort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(QuickSort, SingleElement) {
  std::vector<int> list = {5};
  quicksort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
  EXPECT_EQ(list, std::vector<int>({5}));
}

TEST(QuickSort, AscendingAlreadySorted) {
  std::vector<int> list = gen_ascending_list(10);
  std::vector<int> original = list;
  quicksort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
  EXPECT_EQ(list, original);
}

TEST(QuickSort, DescendingAlreadySorted) {
  std::vector<int> list = gen_descending_list(10);
  quicksort(list, true);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end(), std::greater<int>()));
}

TEST(QuickSort, RandomListAscending) {
  std::vector<int> list = gen_random_list(100);
  quicksort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(QuickSort, RandomListDescending) {
  std::vector<int> list = gen_random_list(100);
  quicksort(list, true);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end(), std::greater<int>()));
}

TEST(QuickSort, UniqueShuffledAscending) {
  std::vector<int> list = gen_unique_list(50);
  quicksort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
  // Check all unique
  auto it = std::unique(list.begin(), list.end());
  EXPECT_EQ(it, list.end());
}

TEST(QuickSort, ManyDuplicates) {
  std::vector<int> list = gen_many_dupes_list(50);
  quicksort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(QuickSort, AllEqual) {
  std::vector<int> list = gen_all_equal_list(20);
  std::vector<int> original = list;
  quicksort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
  EXPECT_EQ(list, original);
}

TEST(QuickSort, NearlySorted) {
  std::vector<int> list = gen_ascending_3swap_list(30);
  quicksort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(QuickSort, OnePercentRandom) {
  std::vector<int> list = gen_one_percent_rand_list(100);
  quicksort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}