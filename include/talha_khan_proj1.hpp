#include <concepts>
#include <random>
#include <type_traits>
#include <vector>
#include <cstdlib>
#include <ctime>

#pragma once
using namespace std;

/*** Helper Functions ***/
inline unsigned int get_rand_index(unsigned int len) {
  srand(static_cast<unsigned int>(time(nullptr)));
  return static_cast<unsigned int>(std::rand() % len);
}

/*** STUDENT HELPER FUNCTIONS HERE ***/

int random_num(int min, int max);
template <typename T>
void quicksort_helper(std::vector<T> &list, int low, int high, bool descending);

template <typename T>
int partition_helper(std::vector<T> &list, int low, int high, bool descending);

template <typename T>
void merge(std::vector<T> &left, std::vector<T> &right, std::vector<T> &list,
           bool descending);
/*** END STUDENT HELPER FUNCTIONS ***/

/*** DO NOT MODIFY BELOW ***/
/*** Main Functions for Students to Implement ***/

/** Helper type for integrals only **/
template <class T>
concept Integral = is_integral<T>::value;

/* Bubble Sort */
template <typename T>
void bubble_sort(vector<T> &list, bool descending = false);

/* Selection Sort */
template <typename T>
void selection_sort(vector<T> &list, bool descending = false);

/* Insertion Sort */
template <typename T>
void insertion_sort(vector<T> &list, bool descending = false);

// Talha
/* Quick Sort */
template <typename T>
vector<T> &quick_partition(vector<T> &list, bool descending = false);

template <typename T>
void quicksort(vector<T> &list, bool descending = false);

// talha
/* Merge Sort */
template <typename T>
void merge_sort(vector<T> &list, bool descending = false);

/* Bucket Merge Sort  */
template <typename T>
void bucket_merge_sort(vector<T> &list, bool descending = false);

/* Binary Radix Sort */
template <Integral T>
void binary_radix_sort(vector<T> &list, bool descending = false);

/* Your Hybrid Sort */
template <typename T>
void my_hybrid_sort(vector<T> &list, bool descending = false);

// Talha
/* Base B Radix Sort */
template <Integral T>
void radix_sort(vector<T> &list, unsigned int base = 10,
                bool descending = false);
