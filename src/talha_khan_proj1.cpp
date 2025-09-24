
#include <algorithm>
#include <chrono>
#include <iostream>

// #include "testing.hpp"
#include "talha_khan_proj1.hpp"

// using namespace std;

/****************
 * INSTRUCTIONS *
 ****************
 *
 * - Replace all instances of "Firstname_Lastname" with your firstname and
 *   your last name. This include the .h and .cpp files, along with the
 *   header guards at the top of the .h file.
 *
 * - Implement the appropriate algorithms as described below.
 *   You must follow the specifications as written
 *   below (e.g., stability, in-place, etc.).
 *
 * - DO NOT MODIFY THE FUNCTION SIGNATURES!!!
 *
 * - You are allowed to add helper functions. Be sure to add the appropriate
 *   function prototypes in "Fistname_Lastname_project1.h".
 *
 * - The file "testing.cpp" has various functions you can utilize to test
 *   your code. You can also add your own tests!
 *
 * - If you are working in a group, please modify the comments directly below.
 *
 */

/*** GROUP PROJECT ***/
// Please list ALL of your other group members as comments below.
//   Member 1
//   Member 2

/* Bubble Sort
 *
 * 5 points
 *
 * Algorithm: Continuously compare adjacent elements and swap them if necessary.
 *            This is a stable, in-place sorting algorithm. Your implementation
 * must be in-place.
 *
 * Parameters:
 *  std::vector<T> &list: reference to a list of type T. You can assume this
 * type has all of the normal binary comparison operators such as <, >, ==, !=,
 * etc. bool decending:  if true, then sort in descending order; otherwise sort
 *                   in ascending order (the default)
 * */
template <typename T>
void bubble_sort(std::vector<T> &list, bool descending) {
  // Your code here!
}

/* Selection Sort
 *
 * 5 points
 *
 * Algorithm: Continuously finds the minimium (or maximum) element in the list,
 *            then swaps it with the first non-sorted element of the list.
 *            This is an unstable, in-place sorting algorithm. Your
 * implementation must be in-place.
 *
 * Parameters:
 *  std::vector<T> &list: reference to a list of type T. You can assume this
 * type has all of the normal binary comparison operators such as <, >, ==, !=,
 * etc. bool decending:  if true, then sort in descending order; otherwise sort
 *                   in ascending order (the default)
 * */
template <typename T>
void selection_sort(std::vector<T> &list, bool descending) {
  // Your code here!
}

/* Insertion Sort
 *
 * 5 points
 *
 * Algorithm: Iterates through the list and inserts the current element into
 *            the correct sorted position of the prefix of the list.
 *            This is a stable, in-place sorting algorithm. Your implementation
 *            does not need to be in-place.
 *
 * Parameters:
 *  std::vector<T> &list: reference to a list of type T. You can assume this
 * type has all of the normal binary comparison operators such as <, >, ==, !=,
 * etc. bool decending:  if true, then sort in descending order; otherwise sort
 *                   in ascending order (the default)
 * */
template <typename T>
void insertion_sort(std::vector<T> &list, bool descending) {
  // Your code here!
}

/* Quicksort
 *
 * 10 points
 *
 * Algorithm: Sorts by first choosing a random pivot from the list, then
 *            partitioning the list into two halves with respect to the
 *            pivot, then recursing on each half.
 *            This is an unstable sorting algorithm. Not required to be
 *            implemented as an in-place sort.
 *
 *
 * Parameters:
 *  std::vector<T> &list: reference to a list of type T. You can assume this
 * type has all of the normal binary comparison operators such as <, >, ==, !=,
 * etc. bool decending:  if true, then sort in descending order; otherwise sort
 *                   in ascending order (the default)
 *
 * */
template <typename T>
void quicksort(std::vector<T> &list, bool descending) {
  if (list.size() <= 1) return;
  if (is_sorted(list.begin(), list.end())) return;
  quicksort_helper(list, 0, list.size() - 1, descending);
}

/* Quick Partition
 *
 * Helper function for Quicksort. You will implement this to help with your
 * quicksort algorithm above.
 *
 */
template <typename T>
std::vector<T> &quick_partition(std::vector<T> &list, bool descending) {
  partition_helper(list, 0, list.size() - 1, descending);
  return list;
}

template <typename T>
void quicksort_helper(std::vector<T> &list, int low, int high,
                      bool descending) {
  if (low < high) {
    int j = partition_helper(list, low, high, descending);
    quicksort_helper(list, low, j, descending);
    quicksort_helper(list, j + 1, high, descending);
  }
}

template <typename T>
int partition_helper(std::vector<T> &list, int low, int high, bool descending) {
  std::swap(list[low], list[random_num(low, high)]);
  T pivot = list[low];
  int i = low - 1, j = high + 1;
  while (true) {
    do {
      ++i;
    } while (descending ? list[i] > pivot : list[i] < pivot);
    do {
      --j;
    } while (descending ? list[j] < pivot : list[j] > pivot);
    if (i >= j) return j;
    std::swap(list[i], list[j]);
  }
}

/* Merge Sort
 *
 * 10 points
 *
 * Algorithm: Sorts the list by recursively sorting the left and right
 *            halves, then merging the two left and right halves together.
 *            This is a stable sorting algorithm. Not required to be implemented
 *            as an in-place sort.
 *
 * Parameters:
 *  std::vector<T> &list: reference to a list of type T. You can assume this
 * type has all of the normal binary comparison operators such as <, >, ==, !=,
 * etc. bool decending:  if true, then sort in descending order; otherwise sort
 *                   in ascending order (the default)
 *
 * */
template <typename T>
void merge_sort(std::vector<T> &list, bool decending) {
  // Your code here!
  std::uint64_t n = list.size();
  if (n <= 1) return;
  if (is_sorted(list.begin(), list.end())) return;
  std::vector<T> left(list.begin(), list.begin() + n / 2);
  std::vector<T> right(list.begin() + n / 2, list.end());
  merge_sort(left, descending);
  merge_sort(right, descending);
  merge(left, right, list, descending);
}

template <typename T>
void merge(std::vector<T> &left, std::vector<T> &right, std::vector<T> &list,
           bool descending) {
  std::uint64_t i{0}, j{0}, k{0};
  if (left[i] < right[j]) {
    list.push_back()
  }
}

/* Bucket Merge Sort
 *
 * 20 points
 *
 * Algorithm: Bucket Merge Sort we discussed in class. Works by
 *            partitioning the input list into small, fixed-length segments,
 *            sorting each of those segments using some fast algorithm, then
 *            merging each of the segments together.
 *            This is a stable, in-place sorting algorithm.
 *
 * Parameters:
 *  std::vector<T> &list: reference to a list of type T. You can assume this
 * type has all of the normal binary comparison operators such as <, >, ==, !=,
 * etc. bool decending:  if true, then sort in descending order; otherwise sort
 *                   in ascending order (the default)
 *
 *
 */
template <typename T>
void bucket_merge_sort(std::vector<T> &list, bool descending) {
  // Your code here!
}

/* Binary Radix Sort
 *
 * 20 points
 *
 * Algorithm:
 *
 * Parameters:
 *   std::vector<T> &list: reference to a list of type T.
 *                    IMPORTANT: this type T is assumed to be *integral*. It
 *                    can be any of the following integral types in C++:
 *                      - (unsigned) short int
 *                      - (unsigned) int
 *                      - (unsigned) long int
 */
template <Integral T>
void binary_radix_sort(std::vector<T> &list, bool descending) {
  // Your code here!
}

/* Your Hybrid Sort
 *
 * 25 points
 *
 * Algorithm: Your own custom Hybrid Sorting algorithm! Remember, a hybrid
 *            sort tries to take advantage of two (or more) sorting algorithms
 *            to speed up data processing.
 *
 * Parameters:
 *  std::vector<T> &list: reference to a list of type T. You can assume this
 * type has all of the normal binary comparison operators such as <, >, ==, !=,
 * etc. bool decending:  if true, then sort in descending order; otherwise sort
 *                   in ascending order (the default)
 *
 */
template <typename T>
void my_hybrid_sort(std::vector<T> &list, bool descending) {
  // Your code here!
}

/* Base B Radix Sort
 *
 * 25 Points
 *
 * Algorithm: Implement Radix Sort as discussed in class, but with
 *            respect to any unspecified base.
 *
 * Parameters:
 *   std::vector<T> &list: reference to a list of type T.
 *                    IMPORTANT: this type T is assumed to be *integral*. It
 *                    can be any of the following integral types in C++:
 *                      - (unsigned) short int
 *                      - (unsigned) int
 *                      - (unsigned) long int
 *
 *   unsigned int base: the base with which to implement the radix sort.
 *                      Note that base should be at least 2. The default
 *                      base is 10.
 *
 *   bool decending: if true, then sort in descending order; otherwise sort
 *                   in ascending order (the default).
 *
 *
 * Additional Information:
 *   - If you are enrolled in the graduate section of this course, you MUST
 *     implement this function (i.e., it counts towards your total grade).
 *
 *   - If you are enrolled in the undergraduate section of this course, this
 *     function is optional and worth extra credit.
 *
 *
 */
template <Integral T>
void radix_sort(std::vector<T> &list, unsigned int base, bool descending) {
  // Your code here!
}

int random_num(int min, int max) {
  std::random_device
      rd;  // Hardware-based entropy (true randomness if supported)
  std::mt19937 gen(rd());  // Mersenne Twister seeded with rd
  std::uniform_int_distribution<> dis(
      min, max);  // Uniform distribution in [min, max]
  return dis(gen);
}

template void quicksort<int>(std::vector<int> &, bool);
template std::vector<int> &quick_partition<int>(std::vector<int> &, bool);