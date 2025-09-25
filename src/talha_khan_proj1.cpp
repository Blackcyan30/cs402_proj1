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
  return;  // Temporary fix to prevent segfault
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
  int n = list.size();
  if (n <= 1) return;  // No sorting needed

  for (int i = 0; i < n - 1; i++) {
    int swap_index = i;
    for (int j = i + 1; j < n; j++) {
      if (descending) {
        // If descending order, find the maximum
        if (list[j] > list[swap_index]) {
          swap_index = j;
        }
      } else {
        // If ascending order, find the minimum
        if (list[j] < list[swap_index]) {
          swap_index = j;
        }
      }
    }
    // Swap with the first ith element
    if (swap_index != i) {
      T temp = list[i];
      list[i] = list[swap_index];
      list[swap_index] = temp;
    }
  }
  // Time Complexity : O(n^2)
  // Space Complexity : O(1)
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
  size_t n = list.size();
  for (size_t i = 1; i < n; ++i) {
    T key = list[i];
    int j = i - 1;

    // Move elements that are greater than key (for ascending) or less than key
    // (for descending) to one position ahead of their current position
    while (j >= 0 &&
           ((descending && list[j] < key) || (!descending && list[j] > key))) {
      list[j + 1] = list[j];
      --j;
    }
    list[j + 1] = key;
  }
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
void merge_sort(std::vector<T> &list, bool descending) {
  std::uint64_t n = list.size();
  if (n <= 1) return;
  if (descending) {
    if (std::is_sorted(list.begin(), list.end(), std::greater<T>())) return;
  } else {
    if (std::is_sorted(list.begin(), list.end())) return;
  }
  std::vector<T> left(list.begin(), list.begin() + n / 2);
  std::vector<T> right(list.begin() + n / 2, list.end());
  merge_sort(left, descending);
  merge_sort(right, descending);
  merge(left, right, list, descending);
}

template <typename T>
void merge(std::vector<T> &left, std::vector<T> &right, std::vector<T> &list,
           bool descending) {
  list.clear();
  std::uint64_t i{0}, j{0}, k{0};
  std::uint64_t left_size{left.size()}, right_size{right.size()};
  while (i < left_size && j < right_size) {
    if (descending) {
      if (left[i] > right[j]) {
        list.push_back(left[i]);
        i++;
      } else {
        list.push_back(right[j]);
        j++;
      }
    } else {
      if (left[i] < right[j]) {
        list.push_back(left[i]);
        i++;
      } else {
        list.push_back(right[j]);
        j++;
      }
    }
  }

  for (; i < left_size; i++) {
    list.push_back(left[i]);
  }
  for (; j < right_size; j++) {
    list.push_back(right[j]);
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
  return;
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
  return;
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
  size_t n = list.size();
  if (n <= 1) return;

  // Minimum run size calculation (similar to Python's TimSort)
  size_t min_run = 32;
  while (min_run * 2 < n) {
    min_run *= 2;
  }

  // Find natural runs and extend small runs with insertion sort
  std::vector<std::pair<size_t, size_t>> runs;
  size_t i = 0;
  while (i < n) {
    size_t start = i;

    // Find the end of the current run
    if (i + 1 < n) {
      bool ascending =
          (descending) ? (list[i] >= list[i + 1]) : (list[i] <= list[i + 1]);
      i++;
      while (i < n && ((descending && list[i - 1] >= list[i]) ||
                       (!descending && list[i - 1] <= list[i]))) {
        i++;
      }
    } else {
      i++;
    }

    size_t end = i - 1;
    size_t run_size = end - start + 1;

    // If run is too small, extend it using insertion sort
    if (run_size < min_run && end + (min_run - run_size) < n) {
      end = std::min(n - 1, start + min_run - 1);
    }

    // Sort the run if it's not already sorted or if we extended it
    if (run_size < min_run || (start > 0 && end < n - 1)) {
      insertion_sort_run(list, start, end, descending);
    }

    runs.push_back({start, end});
    i = end + 1;
  }

  // Merge runs using a stack-based approach
  while (runs.size() > 1) {
    // Find the best runs to merge (similar to TimSort's merge strategy)
    size_t best_idx = runs.size() - 2;
    if (runs.size() >= 3) {
      size_t len1 =
          runs[runs.size() - 3].second - runs[runs.size() - 3].first + 1;
      size_t len2 =
          runs[runs.size() - 2].second - runs[runs.size() - 2].first + 1;
      size_t len3 =
          runs[runs.size() - 1].second - runs[runs.size() - 1].first + 1;

      // Prefer merging smaller runs first
      if (len1 <= len2 + len3) {
        best_idx = runs.size() - 3;
      }
    }

    // Merge the selected runs
    auto [start1, end1] = runs[best_idx];
    auto [start2, end2] = runs[best_idx + 1];
    merge_runs(list, start1, end1, start2, end2, descending);

    // Update the runs vector
    runs[best_idx] = {start1, end2};
    runs.erase(runs.begin() + best_idx + 1);
  }
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
  return;
}

template <typename T>
void insertion_sort_run(std::vector<T> &list, size_t start, size_t end,
                        bool descending) {
  for (size_t i = start + 1; i <= end; ++i) {
    T key = list[i];
    size_t j = i;
    while (j > start && ((descending && list[j - 1] < key) ||
                         (!descending && list[j - 1] > key))) {
      list[j] = list[j - 1];
      --j;
    }
    list[j] = key;
  }
}

template <typename T>
void merge_runs(std::vector<T> &list, size_t start1, size_t end1, size_t start2,
                size_t end2, bool descending) {
  std::vector<T> temp;
  temp.reserve((end1 - start1 + 1) + (end2 - start2 + 1));

  size_t i = start1, j = start2;
  while (i <= end1 && j <= end2) {
    if (descending) {
      if (list[i] > list[j]) {
        temp.push_back(list[i++]);
      } else {
        temp.push_back(list[j++]);
      }
    } else {
      if (list[i] < list[j]) {
        temp.push_back(list[i++]);
      } else {
        temp.push_back(list[j++]);
      }
    }
  }

  while (i <= end1) {
    temp.push_back(list[i++]);
  }
  while (j <= end2) {
    temp.push_back(list[j++]);
  }

  // Copy back to original list
  for (size_t k = 0; k < temp.size(); ++k) {
    list[start1 + k] = temp[k];
  }
}

int random_num(int min, int max) {
  std::random_device
      rd;  // Hardware-based entropy (true randomness if supported)
  std::mt19937 gen(rd());  // Mersenne Twister seeded with rd
  std::uniform_int_distribution<> dis(
      min, max);  // Uniform distribution in [min, max]
  return dis(gen);
}