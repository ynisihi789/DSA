#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>
#include <iomanip>
#include <functional>

/*
 * DSA - Sorting Algorithms in C++
 *
 * Concepts Covered:
 * 1. Bubble Sort - O(n²) time complexity
 * 2. Selection Sort - O(n²) time complexity
 * 3. Insertion Sort - O(n²) time complexity
 * 4. Quick Sort - O(n log n) average time complexity
 * 5. Merge Sort - O(n log n) time complexity
 * 6. std::sort (Intro Sort - hybrid algorithm)
 * 7. Performance comparison with timing
 * 8. Stability analysis
 */

using namespace std;
using namespace chrono;

// Function to display vector elements
void displayVector(const vector<int>& arr) {
    cout << "[";
    for (size_t i = 0; i < arr.size(); i++) {
        cout << arr[i];
        if (i < arr.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

// BUBBLE SORT - O(n²) time complexity
// Stable sorting algorithm
// Best case: O(n) when already sorted
pair<long long, long long> bubbleSort(vector<int>& arr) {
    cout << "\n--- Bubble Sort ---" << endl;
    long long comparisons = 0, swaps = 0;
    bool swapped = true;

    for (size_t i = 0; i < arr.size() - 1 && swapped; i++) {
        swapped = false;

        for (size_t j = 0; j < arr.size() - i - 1; j++) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swaps++;
                swapped = true;
            }
        }
    }

    cout << "Comparisons: " << comparisons << ", Swaps: " << swaps << endl;
    return {comparisons, swaps};
}

// SELECTION SORT - O(n²) time complexity
// Unstable sorting algorithm
// Always O(n²) time complexity
pair<long long, long long> selectionSort(vector<int>& arr) {
    cout << "\n--- Selection Sort ---" << endl;
    long long comparisons = 0, swaps = 0;

    for (size_t i = 0; i < arr.size() - 1; i++) {
        size_t minIndex = i;

        // Find minimum element in unsorted part
        for (size_t j = i + 1; j < arr.size(); j++) {
            comparisons++;
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Swap if minimum element is not at current position
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
            swaps++;
        }
    }

    cout << "Comparisons: " << comparisons << ", Swaps: " << swaps << endl;
    return {comparisons, swaps};
}

// INSERTION SORT - O(n²) time complexity
// Stable sorting algorithm
// Best case: O(n) when already sorted
pair<long long, long long> insertionSort(vector<int>& arr) {
    cout << "\n--- Insertion Sort ---" << endl;
    long long comparisons = 0, shifts = 0;

    for (size_t i = 1; i < arr.size(); i++) {
        int key = arr[i];
        int j = static_cast<int>(i) - 1;

        // Move elements greater than key to one position ahead
        while (j >= 0 && arr[j] > key) {
            comparisons++;
            arr[j + 1] = arr[j];
            shifts++;
            j--;
        }

        if (j >= 0) comparisons++;  // Count the final comparison
        arr[j + 1] = key;
    }

    cout << "Comparisons: " << comparisons << ", Shifts: " << shifts << endl;
    return {comparisons, shifts};
}

// QUICK SORT - O(n log n) average time complexity
// Unstable sorting algorithm
// Worst case: O(n²) when array is already sorted/reverse sorted

// Partition function for Quick Sort
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];  // Choose last element as pivot
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Quick Sort recursive function
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);

        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

// Wrapper function for Quick Sort
void quickSortWrapper(vector<int>& arr) {
    cout << "\n--- Quick Sort ---" << endl;
    quickSort(arr, 0, static_cast<int>(arr.size()) - 1);
    cout << "Quick sort completed" << endl;
}

// MERGE SORT - O(n log n) time complexity
// Stable sorting algorithm
// Always O(n log n) time complexity

// Merge function for Merge Sort
void merge(vector<int>& arr, int left, int mid, int right) {
    vector<int> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0;

    // Merge two sorted subarrays
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    // Copy remaining elements
    while (i <= mid) {
        temp[k++] = arr[i++];
    }
    while (j <= right) {
        temp[k++] = arr[j++];
    }

    // Copy back to original array
    for (int p = 0; p < k; p++) {
        arr[left + p] = temp[p];
    }
}

// Merge Sort recursive function
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

// Wrapper function for Merge Sort
void mergeSortWrapper(vector<int>& arr) {
    cout << "\n--- Merge Sort ---" << endl;
    mergeSort(arr, 0, static_cast<int>(arr.size()) - 1);
    cout << "Merge sort completed" << endl;
}

// STD::SORT - Intro Sort (hybrid algorithm)
// Uses Quick Sort + Heap Sort + Insertion Sort
// O(n log n) time complexity
void stdSortWrapper(vector<int>& arr) {
    cout << "\n--- std::sort (Intro Sort) ---" << endl;
    sort(arr.begin(), arr.end());
    cout << "std::sort completed" << endl;
}

// Function to measure execution time
template<typename Func>
double measureTime(Func&& func, vector<int> arr) {
    auto start = high_resolution_clock::now();
    func(arr);
    auto end = high_resolution_clock::now();
    return duration_cast<microseconds>(end - start).count() / 1000.0;  // Convert to milliseconds
}

// Function to generate random vector
vector<int> generateRandomVector(size_t size, int minVal = 0, int maxVal = 10000) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(minVal, maxVal);

    vector<int> arr(size);
    for (size_t i = 0; i < size; i++) {
        arr[i] = dis(gen);
    }
    return arr;
}

int main() {
    cout << "==========================================" << endl;
    cout << "   DSA - Sorting Algorithms in C++" << endl;
    cout << "==========================================" << endl;

    // Test data
    vector<int> original = {64, 34, 25, 12, 22, 11, 90, 5, 77, 30};

    cout << "\nOriginal Vector: ";
    displayVector(original);

    // Test each sorting algorithm with a copy of the original vector
    vector<int> testVector;

    // Bubble Sort
    testVector = original;
    bubbleSort(testVector);
    cout << "Sorted: ";
    displayVector(testVector);

    // Selection Sort
    testVector = original;
    selectionSort(testVector);
    cout << "Sorted: ";
    displayVector(testVector);

    // Insertion Sort
    testVector = original;
    insertionSort(testVector);
    cout << "Sorted: ";
    displayVector(testVector);

    // Quick Sort
    testVector = original;
    quickSortWrapper(testVector);
    cout << "Sorted: ";
    displayVector(testVector);

    // Merge Sort
    testVector = original;
    mergeSortWrapper(testVector);
    cout << "Sorted: ";
    displayVector(testVector);

    // std::sort
    testVector = original;
    stdSortWrapper(testVector);
    cout << "Sorted: ";
    displayVector(testVector);

    // Performance comparison with larger arrays
    cout << "\n==========================================" << endl;
    cout << "   Performance Comparison (1000 elements)" << endl;
    cout << "==========================================" << endl;

    vector<int> largeArray = generateRandomVector(1000);

    // Test Quick Sort
    double quickTime = measureTime([](vector<int> arr) {
        quickSort(arr, 0, static_cast<int>(arr.size()) - 1);
    }, largeArray);
    cout << fixed << setprecision(3);
    cout << "Quick Sort: " << quickTime << " ms" << endl;

    // Test Merge Sort
    double mergeTime = measureTime([](vector<int> arr) {
        mergeSort(arr, 0, static_cast<int>(arr.size()) - 1);
    }, largeArray);
    cout << "Merge Sort: " << mergeTime << " ms" << endl;

    // Test std::sort
    double stdSortTime = measureTime([](vector<int> arr) {
        sort(arr.begin(), arr.end());
    }, largeArray);
    cout << "std::sort: " << stdSortTime << " ms" << endl;

    // Performance comparison with even larger arrays
    cout << "\n==========================================" << endl;
    cout << "   Performance Comparison (10000 elements)" << endl;
    cout << "==========================================" << endl;

    vector<int> hugeArray = generateRandomVector(10000);

    // Test Quick Sort
    quickTime = measureTime([](vector<int> arr) {
        quickSort(arr, 0, static_cast<int>(arr.size()) - 1);
    }, hugeArray);
    cout << "Quick Sort: " << quickTime << " ms" << endl;

    // Test Merge Sort
    mergeTime = measureTime([](vector<int> arr) {
        mergeSort(arr, 0, static_cast<int>(arr.size()) - 1);
    }, hugeArray);
    cout << "Merge Sort: " << mergeTime << " ms" << endl;

    // Test std::sort
    stdSortTime = measureTime([](vector<int> arr) {
        sort(arr.begin(), arr.end());
    }, hugeArray);
    cout << "std::sort: " << stdSortTime << " ms" << endl;

    cout << "\n==========================================" << endl;
    cout << "   Sorting Algorithm Summary" << endl;
    cout << "==========================================" << endl;
    cout << left << setw(15) << "Algorithm"
         << setw(18) << "Time Complexity"
         << setw(12) << "Stability"
         << "Best Case" << endl;
    cout << string(60, '-') << endl;
    cout << left << setw(15) << "Bubble Sort"
         << setw(18) << "O(n²)"
         << setw(12) << "Stable"
         << "O(n)" << endl;
    cout << left << setw(15) << "Selection Sort"
         << setw(18) << "O(n²)"
         << setw(12) << "Unstable"
         << "O(n²)" << endl;
    cout << left << setw(15) << "Insertion Sort"
         << setw(18) << "O(n²)"
         << setw(12) << "Stable"
         << "O(n)" << endl;
    cout << left << setw(15) << "Quick Sort"
         << setw(18) << "O(n log n) avg"
         << setw(12) << "Unstable"
         << "O(n log n)" << endl;
    cout << left << setw(15) << "Merge Sort"
         << setw(18) << "O(n log n)"
         << setw(12) << "Stable"
         << "O(n log n)" << endl;
    cout << left << setw(15) << "std::sort"
         << setw(18) << "O(n log n)"
         << setw(12) << "Depends"
         << "O(n log n)" << endl;

    cout << "\n==========================================" << endl;
    cout << "   Stability Demonstration" << endl;
    cout << "==========================================" << endl;

    // Demonstrate stability with custom objects (pairs)
    vector<pair<int, string>> stableTest = {
        {3, "first"}, {1, "second"}, {3, "third"}, {1, "fourth"}
    };

    cout << "\nBefore sorting (by first element):" << endl;
    for (const auto& p : stableTest) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << endl;

    // Stable sort (merge sort maintains relative order)
    stable_sort(stableTest.begin(), stableTest.end());
    cout << "\nAfter stable_sort:" << endl;
    for (const auto& p : stableTest) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << endl;

    // Unstable sort (quick sort may change relative order)
    stableTest = {{3, "first"}, {1, "second"}, {3, "third"}, {1, "fourth"}};
    sort(stableTest.begin(), stableTest.end());  // std::sort is not guaranteed stable
    cout << "\nAfter sort (may be unstable):" << endl;
    for (const auto& p : stableTest) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << endl;

    cout << "\nProgram completed successfully!" << endl;
    return 0;
}
