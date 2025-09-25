#include <gtest/gtest.h>

#include "../include/talha_khan_proj1.hpp"
#include "../src/talha_khan_proj1.cpp"
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

TEST(QuickSort, EmptyListShort) {
  std::vector<short> list = {};
  quicksort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(QuickSort, RandomListShort) {
  std::vector<short> list(gen_random_list(100).begin(),
                          gen_random_list(100).end());
  quicksort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(QuickSort, DescendingRandomListShort) {
  std::vector<short> list(gen_random_list(100).begin(),
                          gen_random_list(100).end());
  quicksort(list, true);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end(), std::greater<short>()));
}

TEST(QuickSort, EmptyListLong) {
  std::vector<long> list = {};
  quicksort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(QuickSort, RandomListLong) {
  std::vector<long> list(gen_random_list(100).begin(),
                         gen_random_list(100).end());
  quicksort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(QuickSort, DescendingRandomListLong) {
  std::vector<long> list(gen_random_list(100).begin(),
                         gen_random_list(100).end());
  quicksort(list, true);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end(), std::greater<long>()));
}

TEST(QuickSort, EmptyListLongLong) {
  std::vector<long long> list = {};
  quicksort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(QuickSort, RandomListLongLong) {
  std::vector<long long> list(gen_random_list(100).begin(),
                              gen_random_list(100).end());
  quicksort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(QuickSort, DescendingRandomListLongLong) {
  std::vector<long long> list(gen_random_list(100).begin(),
                              gen_random_list(100).end());
  quicksort(list, true);
  EXPECT_TRUE(
      std::is_sorted(list.begin(), list.end(), std::greater<long long>()));
}

TEST(QuickSort, EmptyListUnsignedInt) {
  std::vector<unsigned int> list = {};
  quicksort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(QuickSort, RandomListUnsignedInt) {
  std::vector<unsigned int> list(gen_random_list(100).begin(),
                                 gen_random_list(100).end());
  quicksort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(QuickSort, DescendingRandomListUnsignedInt) {
  std::vector<unsigned int> list(gen_random_list(100).begin(),
                                 gen_random_list(100).end());
  quicksort(list, true);
  EXPECT_TRUE(
      std::is_sorted(list.begin(), list.end(), std::greater<unsigned int>()));
}

TEST(QuickSort, EmptyListUnsignedLong) {
  std::vector<unsigned long> list = {};
  quicksort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(QuickSort, RandomListUnsignedLong) {
  std::vector<unsigned long> list;
  for (int v : gen_random_list(100)) list.push_back(v);
  quicksort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(QuickSort, DescendingRandomListUnsignedLong) {
  std::vector<unsigned long> list;
  for (int v : gen_random_list(100)) list.push_back(v);
  quicksort(list, true);
  EXPECT_TRUE(
      std::is_sorted(list.begin(), list.end(), std::greater<unsigned long>()));
}

TEST(QuickSort, EmptyListChar) {
  std::vector<char> list = {};
  quicksort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(QuickSort, RandomListChar) {
  std::vector<char> list;
  for (int v : gen_random_list(100)) list.push_back(static_cast<char>(v));
  quicksort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(QuickSort, DescendingRandomListChar) {
  std::vector<char> list;
  for (int v : gen_random_list(100)) list.push_back(static_cast<char>(v));
  quicksort(list, true);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end(), std::greater<char>()));
}

TEST(QuickSort, EmptyListSignedChar) {
  std::vector<signed char> list = {};
  quicksort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(QuickSort, RandomListSignedChar) {
  std::vector<signed char> list;
  for (int v : gen_random_list(100))
    list.push_back(static_cast<signed char>(v));
  quicksort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(QuickSort, DescendingRandomListSignedChar) {
  std::vector<signed char> list;
  for (int v : gen_random_list(100))
    list.push_back(static_cast<signed char>(v));
  quicksort(list, true);
  EXPECT_TRUE(
      std::is_sorted(list.begin(), list.end(), std::greater<signed char>()));
}

TEST(QuickSort, EmptyListUnsignedChar) {
  std::vector<unsigned char> list = {};
  quicksort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(QuickSort, RandomListUnsignedChar) {
  std::vector<unsigned char> list;
  for (int v : gen_random_list(100))
    list.push_back(static_cast<unsigned char>(v));
  quicksort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(QuickSort, DescendingRandomListUnsignedChar) {
  std::vector<unsigned char> list;
  for (int v : gen_random_list(100))
    list.push_back(static_cast<unsigned char>(v));
  quicksort(list, true);
  EXPECT_TRUE(
      std::is_sorted(list.begin(), list.end(), std::greater<unsigned char>()));
}

TEST(QuickSort, EmptyListUnsignedShort) {
  std::vector<unsigned short> list = {};
  quicksort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(QuickSort, RandomListUnsignedShort) {
  std::vector<unsigned short> list;
  for (int v : gen_random_list(100))
    list.push_back(static_cast<unsigned short>(v));
  quicksort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(QuickSort, DescendingRandomListUnsignedShort) {
  std::vector<unsigned short> list;
  for (int v : gen_random_list(100))
    list.push_back(static_cast<unsigned short>(v));
  quicksort(list, true);
  EXPECT_TRUE(
      std::is_sorted(list.begin(), list.end(), std::greater<unsigned short>()));
}

TEST(QuickSort, EmptyListUnsignedLongLong) {
  std::vector<unsigned long long> list = {};
  quicksort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(QuickSort, RandomListUnsignedLongLong) {
  std::vector<unsigned long long> list;
  for (int v : gen_random_list(100))
    list.push_back(static_cast<unsigned long long>(v));
  quicksort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(QuickSort, DescendingRandomListUnsignedLongLong) {
  std::vector<unsigned long long> list = {3000000000000000000ULL,
                                          1000000000000000000ULL};
  quicksort(list, true);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end(),
                             std::greater<unsigned long long>()));
}

TEST(MergeSort, EmptyList) {
  std::vector<int> list = {};
  merge_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(MergeSort, SingleElement) {
  std::vector<int> list = {5};
  merge_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
  EXPECT_EQ(list, std::vector<int>({5}));
}

TEST(MergeSort, AscendingAlreadySorted) {
  std::vector<int> list = gen_ascending_list(10);
  std::vector<int> original = list;
  merge_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
  EXPECT_EQ(list, original);
}

TEST(MergeSort, DescendingAlreadySorted) {
  std::vector<int> list = gen_descending_list(10);
  merge_sort(list, true);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end(), std::greater<int>()));
}

TEST(MergeSort, RandomListAscending) {
  std::vector<int> list = gen_random_list(100);
  merge_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(MergeSort, RandomListDescending) {
  std::vector<int> list = gen_random_list(100);
  merge_sort(list, true);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end(), std::greater<int>()));
}

TEST(MergeSort, UniqueShuffledAscending) {
  std::vector<int> list = gen_unique_list(50);
  merge_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
  // Check all unique
  auto it = std::unique(list.begin(), list.end());
  EXPECT_EQ(it, list.end());
}

TEST(MergeSort, ManyDuplicates) {
  std::vector<int> list = gen_many_dupes_list(50);
  merge_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(MergeSort, AllEqual) {
  std::vector<int> list = gen_all_equal_list(20);
  std::vector<int> original = list;
  merge_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
  EXPECT_EQ(list, original);
}

TEST(MergeSort, NearlySorted) {
  std::vector<int> list = gen_ascending_3swap_list(30);
  merge_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(MergeSort, OnePercentRandom) {
  std::vector<int> list = gen_one_percent_rand_list(100);
  merge_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

// Additional exhaustive tests for other integral types
TEST(MergeSort, EmptyListShort) {
  std::vector<short> list = {};
  merge_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(MergeSort, RandomListShort) {
  std::vector<short> list = {3, 1, 4, 1, 5, 9, 2, 6};
  merge_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(MergeSort, DescendingRandomListShort) {
  std::vector<short> list = {3, 1, 4, 1, 5, 9, 2, 6};
  merge_sort(list, true);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end(), std::greater<short>()));
}

TEST(MergeSort, EmptyListLong) {
  std::vector<long> list = {};
  merge_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(MergeSort, RandomListLong) {
  std::vector<long> list = {3000000000L, 1000000000L, 4000000000L, 1000000000L,
                            5000000000L};
  merge_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(MergeSort, DescendingRandomListLong) {
  std::vector<long> list = {3000000000L, 1000000000L, 4000000000L};
  merge_sort(list, true);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end(), std::greater<long>()));
}

TEST(MergeSort, EmptyListLongLong) {
  std::vector<long long> list = {};
  merge_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(MergeSort, RandomListLongLong) {
  std::vector<long long> list = {3000000000000000000LL, 1000000000000000000LL,
                                 4000000000000000000LL};
  merge_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(MergeSort, DescendingRandomListLongLong) {
  std::vector<long long> list = {3000000000000000000LL, 1000000000000000000LL};
  merge_sort(list, true);
  EXPECT_TRUE(
      std::is_sorted(list.begin(), list.end(), std::greater<long long>()));
}

TEST(MergeSort, EmptyListUnsignedInt) {
  std::vector<unsigned int> list = {};
  merge_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(MergeSort, RandomListUnsignedInt) {
  std::vector<unsigned int> list = {3000000000U, 1000000000U, 4000000000U};
  merge_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(MergeSort, DescendingRandomListUnsignedInt) {
  std::vector<unsigned int> list = {3000000000U, 1000000000U};
  merge_sort(list, true);
  EXPECT_TRUE(
      std::is_sorted(list.begin(), list.end(), std::greater<unsigned int>()));
}

TEST(MergeSort, EmptyListUnsignedLong) {
  std::vector<unsigned long> list = {};
  merge_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(MergeSort, RandomListUnsignedLong) {
  std::vector<unsigned long> list = {3000000000UL, 1000000000UL, 4000000000UL};
  merge_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(MergeSort, DescendingRandomListUnsignedLong) {
  std::vector<unsigned long> list = {3000000000UL, 1000000000UL};
  merge_sort(list, true);
  EXPECT_TRUE(
      std::is_sorted(list.begin(), list.end(), std::greater<unsigned long>()));
}

TEST(MergeSort, EmptyListChar) {
  std::vector<char> list = {};
  merge_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(MergeSort, RandomListChar) {
  std::vector<char> list = {'c', 'a', 'b'};
  merge_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(MergeSort, DescendingRandomListChar) {
  std::vector<char> list = {'c', 'a'};
  merge_sort(list, true);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end(), std::greater<char>()));
}

TEST(MergeSort, EmptyListSignedChar) {
  std::vector<signed char> list = {};
  merge_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(MergeSort, RandomListSignedChar) {
  std::vector<signed char> list = {3, 1, 2};
  merge_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(MergeSort, DescendingRandomListSignedChar) {
  std::vector<signed char> list = {3, 1};
  merge_sort(list, true);
  EXPECT_TRUE(
      std::is_sorted(list.begin(), list.end(), std::greater<signed char>()));
}

TEST(MergeSort, EmptyListUnsignedChar) {
  std::vector<unsigned char> list = {};
  merge_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(MergeSort, RandomListUnsignedChar) {
  std::vector<unsigned char> list = {3, 1, 2};
  merge_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(MergeSort, DescendingRandomListUnsignedChar) {
  std::vector<unsigned char> list = {3, 1};
  merge_sort(list, true);
  EXPECT_TRUE(
      std::is_sorted(list.begin(), list.end(), std::greater<unsigned char>()));
}

TEST(MergeSort, EmptyListUnsignedShort) {
  std::vector<unsigned short> list = {};
  merge_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(MergeSort, RandomListUnsignedShort) {
  std::vector<unsigned short> list = {300, 100, 400};
  merge_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(MergeSort, DescendingRandomListUnsignedShort) {
  std::vector<unsigned short> list = {300, 100};
  merge_sort(list, true);
  EXPECT_TRUE(
      std::is_sorted(list.begin(), list.end(), std::greater<unsigned short>()));
}

TEST(MergeSort, EmptyListUnsignedLongLong) {
  std::vector<unsigned long long> list = {};
  merge_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(MergeSort, RandomListUnsignedLongLong) {
  std::vector<unsigned long long> list = {3000000000000000000ULL,
                                          1000000000000000000ULL};
  merge_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(MergeSort, DescendingRandomListUnsignedLongLong) {
  std::vector<unsigned long long> list = {3000000000000000000ULL,
                                          1000000000000000000ULL};
  merge_sort(list, true);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end(),
                             std::greater<unsigned long long>()));
}

TEST(BubbleSort, EmptyList) {
  std::vector<int> list = {};
  bubble_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(BubbleSort, SingleElement) {
  std::vector<int> list = {5};
  bubble_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
  EXPECT_EQ(list, std::vector<int>({5}));
}

TEST(BubbleSort, AscendingAlreadySorted) {
  std::vector<int> list = gen_ascending_list(10);
  std::vector<int> original = list;
  bubble_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
  EXPECT_EQ(list, original);
}

TEST(BubbleSort, DescendingAlreadySorted) {
  std::vector<int> list = gen_descending_list(10);
  bubble_sort(list, true);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end(), std::greater<int>()));
}

TEST(BubbleSort, RandomListAscending) {
  std::vector<int> list = gen_random_list(100);
  bubble_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(BubbleSort, RandomListDescending) {
  std::vector<int> list = gen_random_list(100);
  bubble_sort(list, true);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end(), std::greater<int>()));
}

TEST(BubbleSort, UniqueShuffledAscending) {
  std::vector<int> list = gen_unique_list(50);
  bubble_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
  // Check all unique
  auto it = std::unique(list.begin(), list.end());
  EXPECT_EQ(it, list.end());
}

TEST(BubbleSort, ManyDuplicates) {
  std::vector<int> list = gen_many_dupes_list(50);
  bubble_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(BubbleSort, AllEqual) {
  std::vector<int> list = gen_all_equal_list(20);
  std::vector<int> original = list;
  bubble_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
  EXPECT_EQ(list, original);
}

TEST(BubbleSort, NearlySorted) {
  std::vector<int> list = gen_ascending_3swap_list(30);
  bubble_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(BubbleSort, OnePercentRandom) {
  std::vector<int> list = gen_one_percent_rand_list(100);
  bubble_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

// Additional exhaustive tests for other integral types
TEST(BubbleSort, EmptyListShort) {
  std::vector<short> list = {};
  bubble_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(BubbleSort, RandomListShort) {
  std::vector<short> list = {3, 1, 4, 1, 5, 9, 2, 6};
  bubble_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(BubbleSort, DescendingRandomListShort) {
  std::vector<short> list = {3, 1, 4, 1, 5, 9, 2, 6};
  bubble_sort(list, true);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end(), std::greater<short>()));
}

TEST(BubbleSort, EmptyListLong) {
  std::vector<long> list = {};
  bubble_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(BubbleSort, RandomListLong) {
  std::vector<long> list = {3000000000L, 1000000000L, 4000000000L, 1000000000L,
                            5000000000L};
  bubble_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(BubbleSort, DescendingRandomListLong) {
  std::vector<long> list = {3000000000L, 1000000000L, 4000000000L};
  bubble_sort(list, true);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end(), std::greater<long>()));
}

TEST(BubbleSort, EmptyListLongLong) {
  std::vector<long long> list = {};
  bubble_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(BubbleSort, RandomListLongLong) {
  std::vector<long long> list = {3000000000000000000LL, 1000000000000000000LL,
                                 4000000000000000000LL};
  bubble_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(BubbleSort, DescendingRandomListLongLong) {
  std::vector<long long> list = {3000000000000000000LL, 1000000000000000000LL};
  bubble_sort(list, true);
  EXPECT_TRUE(
      std::is_sorted(list.begin(), list.end(), std::greater<long long>()));
}

TEST(BubbleSort, EmptyListUnsignedInt) {
  std::vector<unsigned int> list = {};
  bubble_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(BubbleSort, RandomListUnsignedInt) {
  std::vector<unsigned int> list = {3000000000U, 1000000000U, 4000000000U};
  bubble_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(BubbleSort, DescendingRandomListUnsignedInt) {
  std::vector<unsigned int> list = {3000000000U, 1000000000U};
  bubble_sort(list, true);
  EXPECT_TRUE(
      std::is_sorted(list.begin(), list.end(), std::greater<unsigned int>()));
}

TEST(BubbleSort, EmptyListUnsignedLong) {
  std::vector<unsigned long> list = {};
  bubble_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(BubbleSort, RandomListUnsignedLong) {
  std::vector<unsigned long> list = {3000000000UL, 1000000000UL, 4000000000UL};
  bubble_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(BubbleSort, DescendingRandomListUnsignedLong) {
  std::vector<unsigned long> list = {3000000000UL, 1000000000UL};
  bubble_sort(list, true);
  EXPECT_TRUE(
      std::is_sorted(list.begin(), list.end(), std::greater<unsigned long>()));
}

TEST(BubbleSort, EmptyListChar) {
  std::vector<char> list = {};
  bubble_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(BubbleSort, RandomListChar) {
  std::vector<char> list = {'c', 'a', 'b'};
  bubble_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(BubbleSort, DescendingRandomListChar) {
  std::vector<char> list = {'c', 'a'};
  bubble_sort(list, true);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end(), std::greater<char>()));
}

TEST(BubbleSort, EmptyListSignedChar) {
  std::vector<signed char> list = {};
  bubble_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(BubbleSort, RandomListSignedChar) {
  std::vector<signed char> list = {3, 1, 2};
  bubble_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(BubbleSort, DescendingRandomListSignedChar) {
  std::vector<signed char> list = {3, 1};
  bubble_sort(list, true);
  EXPECT_TRUE(
      std::is_sorted(list.begin(), list.end(), std::greater<signed char>()));
}

TEST(BubbleSort, EmptyListUnsignedChar) {
  std::vector<unsigned char> list = {};
  bubble_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(BubbleSort, RandomListUnsignedChar) {
  std::vector<unsigned char> list = {3, 1, 2};
  bubble_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(BubbleSort, DescendingRandomListUnsignedChar) {
  std::vector<unsigned char> list = {3, 1};
  bubble_sort(list, true);
  EXPECT_TRUE(
      std::is_sorted(list.begin(), list.end(), std::greater<unsigned char>()));
}

TEST(BubbleSort, EmptyListUnsignedShort) {
  std::vector<unsigned short> list = {};
  bubble_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(BubbleSort, RandomListUnsignedShort) {
  std::vector<unsigned short> list = {300, 100, 400};
  bubble_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(BubbleSort, DescendingRandomListUnsignedShort) {
  std::vector<unsigned short> list = {300, 100};
  bubble_sort(list, true);
  EXPECT_TRUE(
      std::is_sorted(list.begin(), list.end(), std::greater<unsigned short>()));
}

TEST(BubbleSort, EmptyListUnsignedLongLong) {
  std::vector<unsigned long long> list = {};
  bubble_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(BubbleSort, RandomListUnsignedLongLong) {
  std::vector<unsigned long long> list = {3000000000000000000ULL,
                                          1000000000000000000ULL};
  bubble_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(BubbleSort, DescendingRandomListUnsignedLongLong) {
  std::vector<unsigned long long> list = {3000000000000000000ULL,
                                          1000000000000000000ULL};
  bubble_sort(list, true);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end(),
                             std::greater<unsigned long long>()));
}

TEST(SelectionSort, EmptyList) {
  std::vector<int> list = {};
  selection_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(SelectionSort, SingleElement) {
  std::vector<int> list = {5};
  selection_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
  EXPECT_EQ(list, std::vector<int>({5}));
}

TEST(SelectionSort, AscendingAlreadySorted) {
  std::vector<int> list = gen_ascending_list(10);
  std::vector<int> original = list;
  selection_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
  EXPECT_EQ(list, original);
}

TEST(SelectionSort, DescendingAlreadySorted) {
  std::vector<int> list = gen_descending_list(10);
  selection_sort(list, true);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end(), std::greater<int>()));
}

TEST(SelectionSort, RandomListAscending) {
  std::vector<int> list = gen_random_list(100);
  selection_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(SelectionSort, RandomListDescending) {
  std::vector<int> list = gen_random_list(100);
  selection_sort(list, true);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end(), std::greater<int>()));
}

TEST(SelectionSort, UniqueShuffledAscending) {
  std::vector<int> list = gen_unique_list(50);
  selection_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
  // Check all unique
  auto it = std::unique(list.begin(), list.end());
  EXPECT_EQ(it, list.end());
}

TEST(SelectionSort, ManyDuplicates) {
  std::vector<int> list = gen_many_dupes_list(50);
  selection_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(SelectionSort, AllEqual) {
  std::vector<int> list = gen_all_equal_list(20);
  std::vector<int> original = list;
  selection_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
  EXPECT_EQ(list, original);
}

TEST(SelectionSort, NearlySorted) {
  std::vector<int> list = gen_ascending_3swap_list(30);
  selection_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(SelectionSort, OnePercentRandom) {
  std::vector<int> list = gen_one_percent_rand_list(100);
  selection_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

// Additional exhaustive tests for other integral types
TEST(SelectionSort, EmptyListShort) {
  std::vector<short> list = {};
  selection_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(SelectionSort, RandomListShort) {
  std::vector<short> list = {3, 1, 4, 1, 5, 9, 2, 6};
  selection_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(SelectionSort, DescendingRandomListShort) {
  std::vector<short> list = {3, 1, 4, 1, 5, 9, 2, 6};
  selection_sort(list, true);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end(), std::greater<short>()));
}

TEST(SelectionSort, EmptyListLong) {
  std::vector<long> list = {};
  selection_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(SelectionSort, RandomListLong) {
  std::vector<long> list = {3000000000L, 1000000000L, 4000000000L, 1000000000L,
                            5000000000L};
  selection_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(SelectionSort, DescendingRandomListLong) {
  std::vector<long> list = {3000000000L, 1000000000L, 4000000000L};
  selection_sort(list, true);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end(), std::greater<long>()));
}

TEST(SelectionSort, EmptyListLongLong) {
  std::vector<long long> list = {};
  selection_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(SelectionSort, RandomListLongLong) {
  std::vector<long long> list = {3000000000000000000LL, 1000000000000000000LL,
                                 4000000000000000000LL};
  selection_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(SelectionSort, DescendingRandomListLongLong) {
  std::vector<long long> list = {3000000000000000000LL, 1000000000000000000LL};
  selection_sort(list, true);
  EXPECT_TRUE(
      std::is_sorted(list.begin(), list.end(), std::greater<long long>()));
}

TEST(SelectionSort, EmptyListUnsignedInt) {
  std::vector<unsigned int> list = {};
  selection_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(SelectionSort, RandomListUnsignedInt) {
  std::vector<unsigned int> list = {3000000000U, 1000000000U, 4000000000U};
  selection_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(SelectionSort, DescendingRandomListUnsignedInt) {
  std::vector<unsigned int> list = {3000000000U, 1000000000U};
  selection_sort(list, true);
  EXPECT_TRUE(
      std::is_sorted(list.begin(), list.end(), std::greater<unsigned int>()));
}

TEST(SelectionSort, EmptyListUnsignedLong) {
  std::vector<unsigned long> list = {};
  selection_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(SelectionSort, RandomListUnsignedLong) {
  std::vector<unsigned long> list = {3000000000UL, 1000000000UL, 4000000000UL};
  selection_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(SelectionSort, DescendingRandomListUnsignedLong) {
  std::vector<unsigned long> list = {3000000000UL, 1000000000UL};
  selection_sort(list, true);
  EXPECT_TRUE(
      std::is_sorted(list.begin(), list.end(), std::greater<unsigned long>()));
}

TEST(SelectionSort, EmptyListChar) {
  std::vector<char> list = {};
  selection_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(SelectionSort, RandomListChar) {
  std::vector<char> list = {'c', 'a', 'b'};
  selection_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(SelectionSort, DescendingRandomListChar) {
  std::vector<char> list = {'c', 'a'};
  selection_sort(list, true);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end(), std::greater<char>()));
}

TEST(SelectionSort, EmptyListSignedChar) {
  std::vector<signed char> list = {};
  selection_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(SelectionSort, RandomListSignedChar) {
  std::vector<signed char> list = {3, 1, 2};
  selection_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(SelectionSort, DescendingRandomListSignedChar) {
  std::vector<signed char> list = {3, 1};
  selection_sort(list, true);
  EXPECT_TRUE(
      std::is_sorted(list.begin(), list.end(), std::greater<signed char>()));
}

TEST(SelectionSort, EmptyListUnsignedChar) {
  std::vector<unsigned char> list = {};
  selection_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(SelectionSort, RandomListUnsignedChar) {
  std::vector<unsigned char> list = {3, 1, 2};
  selection_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(SelectionSort, DescendingRandomListUnsignedChar) {
  std::vector<unsigned char> list = {3, 1};
  selection_sort(list, true);
  EXPECT_TRUE(
      std::is_sorted(list.begin(), list.end(), std::greater<unsigned char>()));
}

TEST(SelectionSort, EmptyListUnsignedShort) {
  std::vector<unsigned short> list = {};
  selection_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(SelectionSort, RandomListUnsignedShort) {
  std::vector<unsigned short> list = {300, 100, 400};
  selection_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(SelectionSort, DescendingRandomListUnsignedShort) {
  std::vector<unsigned short> list = {300, 100};
  selection_sort(list, true);
  EXPECT_TRUE(
      std::is_sorted(list.begin(), list.end(), std::greater<unsigned short>()));
}

TEST(SelectionSort, EmptyListUnsignedLongLong) {
  std::vector<unsigned long long> list = {};
  selection_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(SelectionSort, RandomListUnsignedLongLong) {
  std::vector<unsigned long long> list = {3000000000000000000ULL,
                                          1000000000000000000ULL};
  selection_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(SelectionSort, DescendingRandomListUnsignedLongLong) {
  std::vector<unsigned long long> list = {3000000000000000000ULL,
                                          1000000000000000000ULL};
  selection_sort(list, true);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end(),
                             std::greater<unsigned long long>()));
}

TEST(InsertionSort, EmptyList) {
  std::vector<int> list = {};
  insertion_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(InsertionSort, SingleElement) {
  std::vector<int> list = {5};
  insertion_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
  EXPECT_EQ(list, std::vector<int>({5}));
}

TEST(InsertionSort, AscendingAlreadySorted) {
  std::vector<int> list = gen_ascending_list(10);
  std::vector<int> original = list;
  insertion_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
  EXPECT_EQ(list, original);
}

TEST(InsertionSort, DescendingAlreadySorted) {
  std::vector<int> list = gen_descending_list(10);
  insertion_sort(list, true);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end(), std::greater<int>()));
}

TEST(InsertionSort, RandomListAscending) {
  std::vector<int> list = gen_random_list(100);
  insertion_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(InsertionSort, RandomListDescending) {
  std::vector<int> list = gen_random_list(100);
  insertion_sort(list, true);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end(), std::greater<int>()));
}

TEST(InsertionSort, UniqueShuffledAscending) {
  std::vector<int> list = gen_unique_list(50);
  insertion_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
  // Check all unique
  auto it = std::unique(list.begin(), list.end());
  EXPECT_EQ(it, list.end());
}

TEST(InsertionSort, ManyDuplicates) {
  std::vector<int> list = gen_many_dupes_list(50);
  insertion_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(InsertionSort, AllEqual) {
  std::vector<int> list = gen_all_equal_list(20);
  std::vector<int> original = list;
  insertion_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
  EXPECT_EQ(list, original);
}

TEST(InsertionSort, NearlySorted) {
  std::vector<int> list = gen_ascending_3swap_list(30);
  insertion_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(InsertionSort, OnePercentRandom) {
  std::vector<int> list = gen_one_percent_rand_list(100);
  insertion_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

// Additional exhaustive tests for other integral types
TEST(InsertionSort, EmptyListShort) {
  std::vector<short> list = {};
  insertion_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(InsertionSort, RandomListShort) {
  std::vector<short> list = {3, 1, 4, 1, 5, 9, 2, 6};
  insertion_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(InsertionSort, DescendingRandomListShort) {
  std::vector<short> list = {3, 1, 4, 1, 5, 9, 2, 6};
  insertion_sort(list, true);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end(), std::greater<short>()));
}

TEST(InsertionSort, EmptyListLong) {
  std::vector<long> list = {};
  insertion_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(InsertionSort, RandomListLong) {
  std::vector<long> list = {3000000000L, 1000000000L, 4000000000L, 1000000000L,
                            5000000000L};
  insertion_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(InsertionSort, DescendingRandomListLong) {
  std::vector<long> list = {3000000000L, 1000000000L, 4000000000L};
  insertion_sort(list, true);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end(), std::greater<long>()));
}

TEST(InsertionSort, EmptyListLongLong) {
  std::vector<long long> list = {};
  insertion_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(InsertionSort, RandomListLongLong) {
  std::vector<long long> list = {3000000000000000000LL, 1000000000000000000LL,
                                 4000000000000000000LL};
  insertion_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(InsertionSort, DescendingRandomListLongLong) {
  std::vector<long long> list = {3000000000000000000LL, 1000000000000000000LL};
  insertion_sort(list, true);
  EXPECT_TRUE(
      std::is_sorted(list.begin(), list.end(), std::greater<long long>()));
}

TEST(InsertionSort, EmptyListUnsignedInt) {
  std::vector<unsigned int> list = {};
  insertion_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(InsertionSort, RandomListUnsignedInt) {
  std::vector<unsigned int> list = {3000000000U, 1000000000U, 4000000000U};
  insertion_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(InsertionSort, DescendingRandomListUnsignedInt) {
  std::vector<unsigned int> list = {3000000000U, 1000000000U};
  insertion_sort(list, true);
  EXPECT_TRUE(
      std::is_sorted(list.begin(), list.end(), std::greater<unsigned int>()));
}

TEST(InsertionSort, EmptyListUnsignedLong) {
  std::vector<unsigned long> list = {};
  insertion_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(InsertionSort, RandomListUnsignedLong) {
  std::vector<unsigned long> list = {3000000000UL, 1000000000UL, 4000000000UL};
  insertion_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(InsertionSort, DescendingRandomListUnsignedLong) {
  std::vector<unsigned long> list = {3000000000UL, 1000000000UL};
  insertion_sort(list, true);
  EXPECT_TRUE(
      std::is_sorted(list.begin(), list.end(), std::greater<unsigned long>()));
}

TEST(InsertionSort, EmptyListChar) {
  std::vector<char> list = {};
  insertion_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(InsertionSort, RandomListChar) {
  std::vector<char> list = {'c', 'a', 'b'};
  insertion_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(InsertionSort, DescendingRandomListChar) {
  std::vector<char> list = {'c', 'a'};
  insertion_sort(list, true);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end(), std::greater<char>()));
}

TEST(InsertionSort, EmptyListSignedChar) {
  std::vector<signed char> list = {};
  insertion_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(InsertionSort, RandomListSignedChar) {
  std::vector<signed char> list = {3, 1, 2};
  insertion_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(InsertionSort, DescendingRandomListSignedChar) {
  std::vector<signed char> list = {3, 1};
  insertion_sort(list, true);
  EXPECT_TRUE(
      std::is_sorted(list.begin(), list.end(), std::greater<signed char>()));
}

TEST(InsertionSort, EmptyListUnsignedChar) {
  std::vector<unsigned char> list = {};
  insertion_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(InsertionSort, RandomListUnsignedChar) {
  std::vector<unsigned char> list = {3, 1, 2};
  insertion_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(InsertionSort, DescendingRandomListUnsignedChar) {
  std::vector<unsigned char> list = {3, 1};
  insertion_sort(list, true);
  EXPECT_TRUE(
      std::is_sorted(list.begin(), list.end(), std::greater<unsigned char>()));
}

TEST(InsertionSort, EmptyListUnsignedShort) {
  std::vector<unsigned short> list = {};
  insertion_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(InsertionSort, RandomListUnsignedShort) {
  std::vector<unsigned short> list = {300, 100, 400};
  insertion_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(InsertionSort, DescendingRandomListUnsignedShort) {
  std::vector<unsigned short> list = {300, 100};
  insertion_sort(list, true);
  EXPECT_TRUE(
      std::is_sorted(list.begin(), list.end(), std::greater<unsigned short>()));
}

TEST(InsertionSort, EmptyListUnsignedLongLong) {
  std::vector<unsigned long long> list = {};
  insertion_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(InsertionSort, RandomListUnsignedLongLong) {
  std::vector<unsigned long long> list = {3000000000000000000ULL,
                                          1000000000000000000ULL};
  insertion_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(InsertionSort, DescendingRandomListUnsignedLongLong) {
  std::vector<unsigned long long> list = {3000000000000000000ULL,
                                          1000000000000000000ULL};
  insertion_sort(list, true);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end(),
                             std::greater<unsigned long long>()));
}

TEST(BucketMergeSort, EmptyList) {
  std::vector<int> list = {};
  bucket_merge_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(BucketMergeSort, SingleElement) {
  std::vector<int> list = {5};
  bucket_merge_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
  EXPECT_EQ(list, std::vector<int>({5}));
}

TEST(BucketMergeSort, AscendingAlreadySorted) {
  std::vector<int> list = gen_ascending_list(10);
  std::vector<int> original = list;
  bucket_merge_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
  EXPECT_EQ(list, original);
}

TEST(BucketMergeSort, DescendingAlreadySorted) {
  std::vector<int> list = gen_descending_list(10);
  bucket_merge_sort(list, true);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end(), std::greater<int>()));
}

TEST(BucketMergeSort, RandomListAscending) {
  std::vector<int> list = gen_random_list(100);
  bucket_merge_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(BucketMergeSort, RandomListDescending) {
  std::vector<int> list = gen_random_list(100);
  bucket_merge_sort(list, true);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end(), std::greater<int>()));
}

TEST(BucketMergeSort, UniqueShuffledAscending) {
  std::vector<int> list = gen_unique_list(50);
  bucket_merge_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
  // Check all unique
  auto it = std::unique(list.begin(), list.end());
  EXPECT_EQ(it, list.end());
}

TEST(BucketMergeSort, ManyDuplicates) {
  std::vector<int> list = gen_many_dupes_list(50);
  bucket_merge_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(BucketMergeSort, AllEqual) {
  std::vector<int> list = gen_all_equal_list(20);
  std::vector<int> original = list;
  bucket_merge_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
  EXPECT_EQ(list, original);
}

TEST(BucketMergeSort, NearlySorted) {
  std::vector<int> list = gen_ascending_3swap_list(30);
  bucket_merge_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(BucketMergeSort, OnePercentRandom) {
  std::vector<int> list = gen_one_percent_rand_list(100);
  bucket_merge_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

// Additional exhaustive tests for other integral types
TEST(BucketMergeSort, EmptyListShort) {
  std::vector<short> list = {};
  bucket_merge_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(BucketMergeSort, RandomListShort) {
  std::vector<short> list = {3, 1, 4, 1, 5, 9, 2, 6};
  bucket_merge_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(BucketMergeSort, DescendingRandomListShort) {
  std::vector<short> list = {3, 1, 4, 1, 5, 9, 2, 6};
  bucket_merge_sort(list, true);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end(), std::greater<short>()));
}

TEST(BucketMergeSort, EmptyListLong) {
  std::vector<long> list = {};
  bucket_merge_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(BucketMergeSort, RandomListLong) {
  std::vector<long> list = {3000000000L, 1000000000L, 4000000000L, 1000000000L,
                            5000000000L};
  bucket_merge_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(BucketMergeSort, DescendingRandomListLong) {
  std::vector<long> list = {3000000000L, 1000000000L, 4000000000L};
  bucket_merge_sort(list, true);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end(), std::greater<long>()));
}

TEST(BucketMergeSort, EmptyListLongLong) {
  std::vector<long long> list = {};
  bucket_merge_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(BucketMergeSort, RandomListLongLong) {
  std::vector<long long> list = {3000000000000000000LL, 1000000000000000000LL,
                                 4000000000000000000LL};
  bucket_merge_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(BucketMergeSort, DescendingRandomListLongLong) {
  std::vector<long long> list = {3000000000000000000LL, 1000000000000000000LL};
  bucket_merge_sort(list, true);
  EXPECT_TRUE(
      std::is_sorted(list.begin(), list.end(), std::greater<long long>()));
}

TEST(BucketMergeSort, EmptyListUnsignedInt) {
  std::vector<unsigned int> list = {};
  bucket_merge_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(BucketMergeSort, RandomListUnsignedInt) {
  std::vector<unsigned int> list = {3000000000U, 1000000000U, 4000000000U};
  bucket_merge_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(BucketMergeSort, DescendingRandomListUnsignedInt) {
  std::vector<unsigned int> list = {3000000000U, 1000000000U};
  bucket_merge_sort(list, true);
  EXPECT_TRUE(
      std::is_sorted(list.begin(), list.end(), std::greater<unsigned int>()));
}

TEST(BucketMergeSort, EmptyListUnsignedLong) {
  std::vector<unsigned long> list = {};
  bucket_merge_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(BucketMergeSort, RandomListUnsignedLong) {
  std::vector<unsigned long> list = {3000000000UL, 1000000000UL, 4000000000UL};
  bucket_merge_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(BucketMergeSort, DescendingRandomListUnsignedLong) {
  std::vector<unsigned long> list = {3000000000UL, 1000000000UL};
  bucket_merge_sort(list, true);
  EXPECT_TRUE(
      std::is_sorted(list.begin(), list.end(), std::greater<unsigned long>()));
}

TEST(BucketMergeSort, EmptyListChar) {
  std::vector<char> list = {};
  bucket_merge_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(BucketMergeSort, RandomListChar) {
  std::vector<char> list = {'c', 'a', 'b'};
  bucket_merge_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(BucketMergeSort, DescendingRandomListChar) {
  std::vector<char> list = {'c', 'a'};
  bucket_merge_sort(list, true);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end(), std::greater<char>()));
}

TEST(BucketMergeSort, EmptyListSignedChar) {
  std::vector<signed char> list = {};
  bucket_merge_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(BucketMergeSort, RandomListSignedChar) {
  std::vector<signed char> list = {3, 1, 2};
  bucket_merge_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(BucketMergeSort, DescendingRandomListSignedChar) {
  std::vector<signed char> list = {3, 1};
  bucket_merge_sort(list, true);
  EXPECT_TRUE(
      std::is_sorted(list.begin(), list.end(), std::greater<signed char>()));
}

TEST(BucketMergeSort, EmptyListUnsignedChar) {
  std::vector<unsigned char> list = {};
  bucket_merge_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(BucketMergeSort, RandomListUnsignedChar) {
  std::vector<unsigned char> list = {3, 1, 2};
  bucket_merge_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(BucketMergeSort, DescendingRandomListUnsignedChar) {
  std::vector<unsigned char> list = {3, 1};
  bucket_merge_sort(list, true);
  EXPECT_TRUE(
      std::is_sorted(list.begin(), list.end(), std::greater<unsigned char>()));
}

TEST(BucketMergeSort, EmptyListUnsignedShort) {
  std::vector<unsigned short> list = {};
  bucket_merge_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(BucketMergeSort, RandomListUnsignedShort) {
  std::vector<unsigned short> list = {300, 100, 400};
  bucket_merge_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(BucketMergeSort, DescendingRandomListUnsignedShort) {
  std::vector<unsigned short> list = {300, 100};
  bucket_merge_sort(list, true);
  EXPECT_TRUE(
      std::is_sorted(list.begin(), list.end(), std::greater<unsigned short>()));
}

TEST(BucketMergeSort, EmptyListUnsignedLongLong) {
  std::vector<unsigned long long> list = {};
  bucket_merge_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(BucketMergeSort, RandomListUnsignedLongLong) {
  std::vector<unsigned long long> list = {3000000000000000000ULL,
                                          1000000000000000000ULL};
  bucket_merge_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(BucketMergeSort, DescendingRandomListUnsignedLongLong) {
  std::vector<unsigned long long> list = {3000000000000000000ULL,
                                          1000000000000000000ULL};
  bucket_merge_sort(list, true);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end(),
                             std::greater<unsigned long long>()));
}

TEST(MyHybridSort, EmptyList) {
  std::vector<int> list = {};
  my_hybrid_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(MyHybridSort, SingleElement) {
  std::vector<int> list = {5};
  my_hybrid_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
  EXPECT_EQ(list, std::vector<int>({5}));
}

TEST(MyHybridSort, AscendingAlreadySorted) {
  std::vector<int> list = gen_ascending_list(10);
  std::vector<int> original = list;
  my_hybrid_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
  EXPECT_EQ(list, original);
}

TEST(MyHybridSort, DescendingAlreadySorted) {
  std::vector<int> list = gen_descending_list(10);
  my_hybrid_sort(list, true);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end(), std::greater<int>()));
}

TEST(MyHybridSort, RandomListAscending) {
  std::vector<int> list = gen_random_list(100);
  my_hybrid_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(MyHybridSort, RandomListDescending) {
  std::vector<int> list = gen_random_list(100);
  my_hybrid_sort(list, true);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end(), std::greater<int>()));
}

TEST(MyHybridSort, UniqueShuffledAscending) {
  std::vector<int> list = gen_unique_list(50);
  my_hybrid_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
  // Check all unique
  auto it = std::unique(list.begin(), list.end());
  EXPECT_EQ(it, list.end());
}

TEST(MyHybridSort, ManyDuplicates) {
  std::vector<int> list = gen_many_dupes_list(50);
  my_hybrid_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(MyHybridSort, AllEqual) {
  std::vector<int> list = gen_all_equal_list(20);
  std::vector<int> original = list;
  my_hybrid_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
  EXPECT_EQ(list, original);
}

TEST(MyHybridSort, NearlySorted) {
  std::vector<int> list = gen_ascending_3swap_list(30);
  my_hybrid_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(MyHybridSort, OnePercentRandom) {
  std::vector<int> list = gen_one_percent_rand_list(100);
  my_hybrid_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

// Additional exhaustive tests for other integral types
TEST(MyHybridSort, EmptyListShort) {
  std::vector<short> list = {};
  my_hybrid_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(MyHybridSort, RandomListShort) {
  std::vector<short> list = {3, 1, 4, 1, 5, 9, 2, 6};
  my_hybrid_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(MyHybridSort, DescendingRandomListShort) {
  std::vector<short> list = {3, 1, 4, 1, 5, 9, 2, 6};
  my_hybrid_sort(list, true);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end(), std::greater<short>()));
}

TEST(MyHybridSort, EmptyListLong) {
  std::vector<long> list = {};
  my_hybrid_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(MyHybridSort, RandomListLong) {
  std::vector<long> list = {3000000000L, 1000000000L, 4000000000L, 1000000000L,
                            5000000000L};
  my_hybrid_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(MyHybridSort, DescendingRandomListLong) {
  std::vector<long> list = {3000000000L, 1000000000L, 4000000000L};
  my_hybrid_sort(list, true);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end(), std::greater<long>()));
}

TEST(MyHybridSort, EmptyListLongLong) {
  std::vector<long long> list = {};
  my_hybrid_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(MyHybridSort, RandomListLongLong) {
  std::vector<long long> list = {3000000000000000000LL, 1000000000000000000LL,
                                 4000000000000000000LL};
  my_hybrid_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(MyHybridSort, DescendingRandomListLongLong) {
  std::vector<long long> list = {3000000000000000000LL, 1000000000000000000LL};
  my_hybrid_sort(list, true);
  EXPECT_TRUE(
      std::is_sorted(list.begin(), list.end(), std::greater<long long>()));
}

TEST(MyHybridSort, EmptyListUnsignedInt) {
  std::vector<unsigned int> list = {};
  my_hybrid_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(MyHybridSort, RandomListUnsignedInt) {
  std::vector<unsigned int> list = {3000000000U, 1000000000U, 4000000000U};
  my_hybrid_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(MyHybridSort, DescendingRandomListUnsignedInt) {
  std::vector<unsigned int> list = {3000000000U, 1000000000U};
  my_hybrid_sort(list, true);
  EXPECT_TRUE(
      std::is_sorted(list.begin(), list.end(), std::greater<unsigned int>()));
}

TEST(MyHybridSort, EmptyListUnsignedLong) {
  std::vector<unsigned long> list = {};
  my_hybrid_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(MyHybridSort, RandomListUnsignedLong) {
  std::vector<unsigned long> list = {3000000000UL, 1000000000UL, 4000000000UL};
  my_hybrid_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(MyHybridSort, DescendingRandomListUnsignedLong) {
  std::vector<unsigned long> list = {3000000000UL, 1000000000UL};
  my_hybrid_sort(list, true);
  EXPECT_TRUE(
      std::is_sorted(list.begin(), list.end(), std::greater<unsigned long>()));
}

TEST(MyHybridSort, EmptyListChar) {
  std::vector<char> list = {};
  my_hybrid_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(MyHybridSort, RandomListChar) {
  std::vector<char> list = {'c', 'a', 'b'};
  my_hybrid_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(MyHybridSort, DescendingRandomListChar) {
  std::vector<char> list = {'c', 'a'};
  my_hybrid_sort(list, true);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end(), std::greater<char>()));
}

TEST(MyHybridSort, EmptyListSignedChar) {
  std::vector<signed char> list = {};
  my_hybrid_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(MyHybridSort, RandomListSignedChar) {
  std::vector<signed char> list = {3, 1, 2};
  my_hybrid_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(MyHybridSort, DescendingRandomListSignedChar) {
  std::vector<signed char> list = {3, 1};
  my_hybrid_sort(list, true);
  EXPECT_TRUE(
      std::is_sorted(list.begin(), list.end(), std::greater<signed char>()));
}

TEST(MyHybridSort, EmptyListUnsignedChar) {
  std::vector<unsigned char> list = {};
  my_hybrid_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(MyHybridSort, RandomListUnsignedChar) {
  std::vector<unsigned char> list = {3, 1, 2};
  my_hybrid_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(MyHybridSort, DescendingRandomListUnsignedChar) {
  std::vector<unsigned char> list = {3, 1};
  my_hybrid_sort(list, true);
  EXPECT_TRUE(
      std::is_sorted(list.begin(), list.end(), std::greater<unsigned char>()));
}

TEST(MyHybridSort, EmptyListUnsignedShort) {
  std::vector<unsigned short> list = {};
  my_hybrid_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(MyHybridSort, RandomListUnsignedShort) {
  std::vector<unsigned short> list = {300, 100, 400};
  my_hybrid_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(MyHybridSort, DescendingRandomListUnsignedShort) {
  std::vector<unsigned short> list = {300, 100};
  my_hybrid_sort(list, true);
  EXPECT_TRUE(
      std::is_sorted(list.begin(), list.end(), std::greater<unsigned short>()));
}

TEST(MyHybridSort, EmptyListUnsignedLongLong) {
  std::vector<unsigned long long> list = {};
  my_hybrid_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(MyHybridSort, RandomListUnsignedLongLong) {
  std::vector<unsigned long long> list = {3000000000000000000ULL,
                                          1000000000000000000ULL};
  my_hybrid_sort(list, false);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}

TEST(MyHybridSort, DescendingRandomListUnsignedLongLong) {
  std::vector<unsigned long long> list = {3000000000000000000ULL,
                                          1000000000000000000ULL};
  my_hybrid_sort(list, true);
  EXPECT_TRUE(std::is_sorted(list.begin(), list.end(),
                             std::greater<unsigned long long>()));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
