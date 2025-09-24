#include <concepts>
#include <random>
#include <type_traits>
#include <vector>

#ifndef TALHA_KHAN_PROJECT1
#define TALHA_KHAN_PROJECT1

using namespace std;

/*** Helper Functions ***/
unsigned int get_rand_index(unsigned int len) {
  std::srand(std::time(nullptr));
  return static_cast<unsigned int>(std::rand() % len);
}

/*** STUDENT HELPER FUNCTIONS HERE ***/

template <typename T>
void insertion_sort_helper(std::vector<T> &list, int start, int end, bool descending) {
    for (int i = start + 1; i < end; i++) {
        T key = list[i];
        int j = i;
        if (descending) {
            while (j > start && list[j - 1] < key) {
                list[j] = list[j - 1];
                j--;
            }
        } else {
            while (j > start && list[j - 1] > key) {
                list[j] = list[j - 1];
                j--;
            }
        }
        list[j] = key;
    }
}

template <typename T>
void merge(std::vector<T>& list, int left, int mid, int right, bool descending) {
    // For small segments simply do insertion sort
    if (right - left <= 32) {
        insertion_sort_helper(list, left, right + 1, descending);
        return;
    }

    int i = left;   // left 
    int j = mid + 1; // right 

    while (i <= mid && j <= right) {
        bool advance_left = false;
        // Check if we've exhausted the right segment
        if (j > right) {
            advance_left = true;
        } else {
            if (descending) {
                // For descending order, keep list[i] if it's >= list[j]
                if (list[i] >= list[j]) {
                    advance_left = true;
                }
            } else {
                // For ascending order, keep list[i] if it's <= list[j]
                if (list[i] <= list[j]) {
                    advance_left = true;
                }
            }
        }

        if (advance_left) {
            // Just move to the left
            ++i;
        } else {
            // Insert list[j] at position i and shift elements
            T temp = list[j];
            for (size_t k = j; k > i; --k) {
                list[k] = list[k - 1];
            }
            list[i] = temp;
            ++i;
            ++j;
            ++mid;
        }
    }
}


/*** END STUDENT HELPER FUNCTIONS ***/

/*** DO NOT MODIFY BELOW ***/
/*** Main Functions for Students to Implement ***/

/** Helper type for integrals only **/
//template <class T>
//concept Integral = is_integral<T>::value;

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
// template <Integral T>
// void binary_radix_sort(vector<T> &list, bool descending = false);

/* Your Hybrid Sort */
template <typename T>
void my_hybrid_sort(vector<T> &list, bool descending = false);

// Talha
/* Base B Radix Sort */
// template <Integral T>
// void radix_sort(vector<T> &list, unsigned int base = 10,
//                bool descending = false);

#endif
