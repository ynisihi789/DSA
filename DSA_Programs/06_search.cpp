#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <chrono>
#include <iomanip>

/*
 * DSA - Searching Algorithms in C++
 *
 * Concepts Covered:
 * 1. Linear Search with STL
 * 2. Binary Search with STL
 * 3. Custom search implementations
 * 4. Performance analysis and timing
 * 5. Template-based generic searches
 * 6. Real-world search applications
 */

using namespace std;
using namespace chrono;

// Template for Linear Search
template <typename T>
int linearSearch(const vector<T>& arr, const T& target) {
    for (size_t i = 0; i < arr.size(); i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

// Template for Binary Search
template <typename T>
int binarySearch(const vector<T>& arr, const T& target) {
    int low = 0, high = arr.size() - 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    return -1;
}

// Recursive Binary Search template
template <typename T>
int binarySearchRecursive(const vector<T>& arr, int low, int high, const T& target) {
    if (low > high) {
        return -1;
    }
    
    int mid = low + (high - low) / 2;
    
    if (arr[mid] == target) {
        return mid;
    } else if (arr[mid] < target) {
        return binarySearchRecursive(arr, mid + 1, high, target);
    } else {
        return binarySearchRecursive(arr, low, mid - 1, target);
    }
}

// Jump Search
template <typename T>
int jumpSearch(const vector<T>& arr, const T& target) {
    int size = arr.size();
    int step = (int)sqrt(size);
    int prev = 0;
    
    while (arr[step - 1] < target && step < size) {
        prev = step;
        step += (int)sqrt(size);
        if (step > size) {
            step = size;
        }
    }
    
    while (arr[prev] < target) {
        prev++;
        if (prev == step) {
            return -1;
        }
    }
    
    if (arr[prev] == target) {
        return prev;
    }
    
    return -1;
}

// STL find function
template <typename T>
int stlFind(const vector<T>& arr, const T& target) {
    auto it = find(arr.begin(), arr.end(), target);
    if (it != arr.end()) {
        return distance(arr.begin(), it);
    }
    return -1;
}

// STL binary_search
template <typename T>
bool stlBinarySearch(const vector<T>& arr, const T& target) {
    return binary_search(arr.begin(), arr.end(), target);
}

// Lower bound (first element >= target)
template <typename T>
int lowerBound(const vector<T>& arr, const T& target) {
    auto it = lower_bound(arr.begin(), arr.end(), target);
    if (it != arr.end()) {
        return distance(arr.begin(), it);
    }
    return -1;
}

// Upper bound (first element > target)
template <typename T>
int upperBound(const vector<T>& arr, const T& target) {
    auto it = upper_bound(arr.begin(), arr.end(), target);
    if (it != arr.end()) {
        return distance(arr.begin(), it);
    }
    return -1;
}

// Display vector
template <typename T>
void displayVector(const vector<T>& arr) {
    cout << "[";
    for (size_t i = 0; i < arr.size(); i++) {
        cout << arr[i];
        if (i < arr.size() - 1) cout << ", ";
    }
    cout << "]\n";
}

// Performance measurement
template <typename Func, typename T>
double measureTime(Func&& func, const vector<T>& arr, const T& target) {
    auto start = high_resolution_clock::now();
    func(arr, target);
    auto end = high_resolution_clock::now();
    return duration_cast<nanoseconds>(end - start).count();
}

int main() {
    cout << "==========================================" << endl;
    cout << "   DSA - Searching Algorithms (C++)" << endl;
    cout << "==========================================" << endl;

    // Test data
    vector<int> arr = {2, 5, 8, 12, 16, 23, 38, 45, 56, 67, 78};

    cout << "\nArray: ";
    displayVector(arr);

    int target = 38;
    int target2 = 100;

    // 1. Linear Search
    cout << "\n1. Linear Search - O(n):" << endl;
    int pos = linearSearch(arr, target);
    cout << "   Searching for " << target << ": ";
    (pos != -1) ? cout << "Found at index " << pos << endl : cout << "Not found" << endl;

    pos = linearSearch(arr, target2);
    cout << "   Searching for " << target2 << ": ";
    (pos != -1) ? cout << "Found at index " << pos << endl : cout << "Not found" << endl;

    // 2. Binary Search (Iterative)
    cout << "\n2. Binary Search (Iterative) - O(log n):" << endl;
    pos = binarySearch(arr, target);
    cout << "   Searching for " << target << ": ";
    (pos != -1) ? cout << "Found at index " << pos << endl : cout << "Not found" << endl;

    // 3. Binary Search (Recursive)
    cout << "\n3. Binary Search (Recursive):" << endl;
    pos = binarySearchRecursive(arr, 0, arr.size() - 1, target);
    cout << "   Searching for " << target << ": ";
    (pos != -1) ? cout << "Found at index " << pos << endl : cout << "Not found" << endl;

    // 4. Jump Search
    cout << "\n4. Jump Search - O(√n):" << endl;
    pos = jumpSearch(arr, target);
    cout << "   Searching for " << target << ": ";
    (pos != -1) ? cout << "Found at index " << pos << endl : cout << "Not found" << endl;

    // 5. STL find
    cout << "\n5. STL find():" << endl;
    pos = stlFind(arr, target);
    cout << "   Searching for " << target << ": ";
    (pos != -1) ? cout << "Found at index " << pos << endl : cout << "Not found" << endl;

    // 6. STL binary_search
    cout << "\n6. STL binary_search():" << endl;
    bool found = stlBinarySearch(arr, target);
    cout << "   Searching for " << target << ": ";
    cout << (found ? "Found" : "Not found") << endl;

    // 7. Lower bound and Upper bound
    cout << "\n7. Lower Bound and Upper Bound:" << endl;
    vector<int> arr_dup = {1, 2, 2, 2, 3, 4, 4, 5, 6, 6, 6, 6};
    cout << "   Array: ";
    displayVector(arr_dup);

    int search_val = 6;
    int lower = lowerBound(arr_dup, search_val);
    int upper = upperBound(arr_dup, search_val);
    cout << "   Lower bound of " << search_val << ": index " << lower << endl;
    cout << "   Upper bound of " << search_val << ": index " << upper << endl;

    // 8. String searching
    cout << "\n8. String Searching:" << endl;
    vector<string> names = {"Alice", "Bob", "Charlie", "David", "Eve"};
    cout << "   Names: ";
    displayVector(names);

    string search_name = "Charlie";
    int name_pos = linearSearch(names, search_name);
    cout << "   Searching for '" << search_name << "': ";
    (name_pos != -1) ? cout << "Found at index " << name_pos << endl : cout << "Not found" << endl;

    // 9. Double searching
    cout << "\n9. Double Searching:" << endl;
    vector<double> doubles = {1.1, 2.2, 3.3, 4.4, 5.5};
    cout << "   Doubles: ";
    displayVector(doubles);

    double search_double = 3.3;
    int double_pos = binarySearch(doubles, search_double);
    cout << "   Searching for " << fixed << setprecision(1) << search_double << ": ";
    (double_pos != -1) ? cout << "Found at index " << double_pos << endl : cout << "Not found" << endl;

    // 10. Performance comparison
    cout << "\n10. Performance Comparison (Large Array):" << endl;
    vector<int> largeArr(10000);
    for (int i = 0; i < 10000; i++) {
        largeArr[i] = i * 2;
    }

    int searchTarget = 9998;

    cout << fixed << setprecision(2);
    double linearTime = measureTime([](const vector<int>& a, const int& t) {
        linearSearch(a, t);
    }, largeArr, searchTarget);

    double binaryTime = measureTime([](const vector<int>& a, const int& t) {
        binarySearch(a, t);
    }, largeArr, searchTarget);

    cout << "   Array size: 10000 elements" << endl;
    cout << "   Linear Search: " << linearTime << " ns" << endl;
    cout << "   Binary Search: " << binaryTime << " ns" << endl;
    cout << "   Speed up: " << (linearTime / binaryTime) << "x faster" << endl;

    // 11. Search summary
    cout << "\n11. Searching Algorithm Comparison:" << endl;
    cout << left << setw(20) << "Algorithm"
         << setw(18) << "Time Complexity"
         << setw(12) << "Best Case"
         << "Sorted Required" << endl;
    cout << string(65, '-') << endl;
    cout << left << setw(20) << "Linear Search"
         << setw(18) << "O(n)"
         << setw(12) << "O(1)"
         << "No" << endl;
    cout << left << setw(20) << "Binary Search"
         << setw(18) << "O(log n)"
         << setw(12) << "O(1)"
         << "Yes" << endl;
    cout << left << setw(20) << "Jump Search"
         << setw(18) << "O(√n)"
         << setw(12) << "O(1)"
         << "Yes" << endl;

    cout << "\n==========================================" << endl;
    cout << "Program completed successfully!" << endl;
    cout << "==========================================" << endl;

    return 0;
}
