
#include <algorithm>
#include <chrono>
#include <iostream>
//#include <cassert>
//using namespace std;

#include "../tests/testing.hpp"
#include "../include/talha_khan_proj1.hpp"

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
  int n = list.size();
    if (n <= 1) return; // No sorting needed

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
  // Your code here!
}

/* Quick Partition
 *
 * Helper function for Quicksort. You will implement this to help with your
 * quicksort algorithm above.
 *
 */
template <typename T>
std::vector<T> &quick_partition(std::vector<T> &list, bool descending) {
  // Your code here!
  //
  // You can use the helper function
  //      unsigned int get_rand_index(unsigned int len)
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
  int size = list.size();
  const int bucket_size = 32;
  int i = 0;

  for (; i + bucket_size <= size; i += bucket_size){
    insertion_sort_helper(list, i, i + bucket_size, descending);
  }

  // For any remaining data
  if (i < size) {
    insertion_sort_helper(list, i, size , descending);
  }

  for (int n = bucket_size; n < size; n *= 2) {
    for (int left = 0; left < size; left += 2 * n) {
        int mid = left + n - 1;
        int right = left + 2 * n - 1;
        if (right >= size){
          right = size - 1;
        }
        if (mid < size - 1) {
            merge(list, left, mid, right, descending);
        }
    }
  }
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
// template <Integral T>
// void binary_radix_sort(std::vector<T> &list, bool descending) {
//   // Your code here!
// }

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
// template <Integral T>
// void radix_sort(std::vector<T> &list, unsigned int base, bool descending) {
//   // Your code here!
// }

// Helper function to print vector

int main() {
  /**** STUDENT CODE HERE ****/
  std:: cout << "Selection Sort Tests" << std::endl;
  std::vector<int> vec1 = {5, 2, 9, 1, 5, 6};
  std::cout << "Test 1 - Integers, Ascending:\nOriginal: ";
  print_vector(vec1);
  selection_sort(vec1, false);
  std::cout << "Sorted:   ";
  print_vector(vec1);
  std::cout << std::endl;

  // Test Case 2: Sorting integers in descending order
  std::vector<int> vec2 = {5, 2, 9, 1, 5, 6};
  std::cout << "Test 2 - Integers, Descending:\nOriginal: ";
  print_vector(vec2);
  selection_sort(vec2, true);
  std::cout << "Sorted:   ";
  print_vector(vec2);
  std::cout << std::endl;

  // Test Case 3: Empty vector
  std::vector<int> vec3 = {};
  std::cout << "Test 3 - Empty vector:\nOriginal: ";
  print_vector(vec3);
  selection_sort(vec3, false);
  std::cout << "Sorted:   ";
  print_vector(vec3);
  std::cout << std::endl;

  // Test Case 4: Single element
  std::vector<int> vec4 = {42};
  std::cout << "Test 4 - Single element:\nOriginal: ";
  print_vector(vec4);
  selection_sort(vec4, false);
  std::cout << "Sorted:   ";
  print_vector(vec4);
  std::cout << std::endl;

  // Test Case 5: Doubles in ascending order
  std::vector<double> vec5 = {3.14, 1.41, 2.71, 0.58};
  std::cout << "Test 5 - Doubles, Ascending:\nOriginal: ";
  print_vector(vec5);
  selection_sort(vec5, false);
  std::cout << "Sorted:   ";
  print_vector(vec5);
  std::cout << std::endl;

  // Test Case 6: Already sorted vector
  std::vector<int> vec6 = {1, 2, 3, 4, 5};
  std::cout << "Test 6 - Already sorted, Ascending:\nOriginal: ";
  print_vector(vec6);
  selection_sort(vec6, false);
  std::cout << "Sorted:   ";
  print_vector(vec6);
  std::cout << std::endl;

  std::cout << "All tests completed successfully!\n";

  std:: cout << "\nBucket Merge Sort Tests" << std::endl;
  std::vector<int> vec7 = {5, 2, 9, 1, 5, 6, 22, 4, 3, 11, 55, 10, 15};
  std::cout << "\nOriginal: ";
  print_vector(vec7);
  std::cout << "\nTest 1: Ascending\n";
  bucket_merge_sort(vec7, false);
  std::cout << "Sorted:   ";
  print_vector(vec7);

  std::cout << "\nTest 2: Descending\n";
  bucket_merge_sort(vec7, true);
  std::cout << "Sorted:   ";
  print_vector(vec7);
  /**** END STUDENT CODE ****/

  /***** DO NOT MODIFY BELOW THIS LINE *****/
  /*** INSTRUCTIONS ***
   *
   * Before submitting your code:
   *   - remove all code within the main function that you have written above
   * the `do-not-modify` line;
   *   - uncomment all lines below that begin with "//".
   *
   */
  //vector<int> test_list {5, 2, 1, 3, 4};
  // bubble_sort(test_list);
  // insertion_sort(test_list);
  // quicksort(test_list);
  // merge_sort(test_list);
  // bucket_merge_sort(test_list);
  // binary_radix_sort(test_list);
  // my_hybrid_sort(test_list);
  // radix_sort(test_list);
  // Test Case 1: Sorting integers in ascending order
  return 0;
}
