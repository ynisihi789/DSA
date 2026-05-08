#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iomanip>

/*
 * DSA Fundamentals - Array Basics and Linear Search (C++ Version)
 *
 * Concepts Covered:
 * 1. std::vector (dynamic arrays)
 * 2. Traversing vectors
 * 3. Linear Search Algorithm (O(n) time complexity)
 * 4. Vector Insertion and Deletion
 * 5. C++ Standard Library algorithms
 */

using namespace std;

// Function to display vector elements
void displayVector(const vector<int>& arr) {
    cout << "\nVector Elements: ";
    for (size_t i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Linear Search - O(n) time complexity
int linearSearch(const vector<int>& arr, int target) {
    for (size_t i = 0; i < arr.size(); i++) {
        if (arr[i] == target) {
            return static_cast<int>(i);  // Element found at index i
        }
    }
    return -1;  // Element not found
}

// Insert element at a specific position
void insertElement(vector<int>& arr, size_t position, int value) {
    if (position > arr.size()) {
        cout << "Invalid position!" << endl;
        return;
    }

    arr.insert(arr.begin() + position, value);
    cout << "Inserted " << value << " at position " << position << endl;
}

// Delete element at a specific position
void deleteElement(vector<int>& arr, size_t position) {
    if (position >= arr.size()) {
        cout << "Invalid position!" << endl;
        return;
    }

    int deletedValue = arr[position];
    arr.erase(arr.begin() + position);
    cout << "Deleted " << deletedValue << " from position " << position << endl;
}

// Calculate sum of vector elements using std::accumulate
int vectorSum(const vector<int>& arr) {
    return accumulate(arr.begin(), arr.end(), 0);
}

// Find maximum element using std::max_element
int findMax(const vector<int>& arr) {
    if (arr.empty()) return INT_MIN;
    return *max_element(arr.begin(), arr.end());
}

// Find minimum element using std::min_element
int findMin(const vector<int>& arr) {
    if (arr.empty()) return INT_MAX;
    return *min_element(arr.begin(), arr.end());
}

// Reverse vector using std::reverse
void reverseVector(vector<int>& arr) {
    reverse(arr.begin(), arr.end());
    cout << "Vector reversed!" << endl;
}

// Sort vector using std::sort
void sortVector(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    cout << "Vector sorted!" << endl;
}

// Binary search (requires sorted vector) - O(log n) time complexity
int binarySearch(const vector<int>& arr, int target) {
    auto it = lower_bound(arr.begin(), arr.end(), target);
    if (it != arr.end() && *it == target) {
        return distance(arr.begin(), it);
    }
    return -1;
}

// Count occurrences of an element
int countOccurrences(const vector<int>& arr, int target) {
    return count(arr.begin(), arr.end(), target);
}

// Remove duplicates from vector
void removeDuplicates(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    auto last = unique(arr.begin(), arr.end());
    arr.erase(last, arr.end());
    cout << "Duplicates removed!" << endl;
}

// Find second largest element
int findSecondLargest(const vector<int>& arr) {
    if (arr.size() < 2) return INT_MIN;

    int largest = INT_MIN;
    int secondLargest = INT_MIN;

    for (int num : arr) {
        if (num > largest) {
            secondLargest = largest;
            largest = num;
        } else if (num > secondLargest && num != largest) {
            secondLargest = num;
        }
    }

    return secondLargest;
}

// Check if vector is sorted
bool isSorted(const vector<int>& arr) {
    for (size_t i = 1; i < arr.size(); i++) {
        if (arr[i] < arr[i-1]) {
            return false;
        }
    }
    return true;
}

// Rotate vector left by k positions
void rotateLeft(vector<int>& arr, int k) {
    if (arr.empty()) return;
    k = k % arr.size();
    rotate(arr.begin(), arr.begin() + k, arr.end());
    cout << "Vector rotated left by " << k << " positions!" << endl;
}

// Rotate vector right by k positions
void rotateRight(vector<int>& arr, int k) {
    if (arr.empty()) return;
    k = k % arr.size();
    rotate(arr.rbegin(), arr.rbegin() + k, arr.rend());
    cout << "Vector rotated right by " << k << " positions!" << endl;
}

int main() {
    // Initialize vector with sample data
    vector<int> arr = {15, 23, 8, 42, 16, 4, 99, 50, 12, 35};

    cout << "==========================================" << endl;
    cout << "   DSA Fundamentals - Array Basics (C++)" << endl;
    cout << "==========================================" << endl;

    // 1. Display original vector
    cout << "\n1. Original Vector:";
    displayVector(arr);

    // 2. Linear Search
    cout << "\n2. Linear Search:";
    int target = 42;
    int index = linearSearch(arr, target);
    if (index != -1) {
        cout << "   Element " << target << " found at index " << index << endl;
    } else {
        cout << "   Element " << target << " not found" << endl;
    }

    // 3. Search for element not in vector
    target = 100;
    index = linearSearch(arr, target);
    if (index != -1) {
        cout << "   Element " << target << " found at index " << index << endl;
    } else {
        cout << "   Element " << target << " not found" << endl;
    }

    // 4. Insert element
    cout << "\n3. Insertion Operation:";
    insertElement(arr, 3, 77);
    displayVector(arr);

    // 5. Delete element
    cout << "\n4. Deletion Operation:";
    deleteElement(arr, 5);
    displayVector(arr);

    // 6. Vector sum
    cout << "\n5. Vector Sum:";
    int sum = vectorSum(arr);
    cout << "   Sum of all elements: " << sum << endl;

    // 7. Find max and min
    cout << "\n6. Find Maximum and Minimum:";
    cout << "   Maximum element: " << findMax(arr) << endl;
    cout << "   Minimum element: " << findMin(arr) << endl;

    // 8. Reverse vector
    cout << "\n7. Reverse Vector:";
    reverseVector(arr);
    displayVector(arr);

    // 9. Sort vector
    cout << "\n8. Sort Vector:";
    sortVector(arr);
    displayVector(arr);

    // 10. Binary search (now that vector is sorted)
    cout << "\n9. Binary Search (on sorted vector):";
    target = 42;
    index = binarySearch(arr, target);
    if (index != -1) {
        cout << "   Element " << target << " found at index " << index << endl;
    } else {
        cout << "   Element " << target << " not found" << endl;
    }

    // 11. Count occurrences
    cout << "\n10. Count Occurrences:";
    target = 15;
    int count = countOccurrences(arr, target);
    cout << "   Element " << target << " appears " << count << " time(s)" << endl;

    // 12. Check if sorted
    cout << "\n11. Is Vector Sorted?";
    cout << "   " << (isSorted(arr) ? "Yes" : "No") << endl;

    // 13. Find second largest
    cout << "\n12. Second Largest Element:";
    int secondLargest = findSecondLargest(arr);
    if (secondLargest != INT_MIN) {
        cout << "   Second largest: " << secondLargest << endl;
    } else {
        cout << "   Not enough elements" << endl;
    }

    // 14. Average calculation
    cout << "\n13. Vector Average:";
    cout << fixed << setprecision(2);
    cout << "   Average: " << static_cast<double>(sum) / arr.size() << endl;

    // 15. Rotate operations
    cout << "\n14. Rotation Operations:";

    // Reset to original unsorted state for rotation demo
    arr = {15, 23, 8, 42, 16, 4, 99, 50, 12, 35};
    cout << "\n   Original for rotation: ";
    displayVector(arr);

    rotateLeft(arr, 3);
    displayVector(arr);

    rotateRight(arr, 2);
    displayVector(arr);

    // 16. Remove duplicates demo
    cout << "\n15. Remove Duplicates Demo:";
    vector<int> dupArr = {1, 2, 2, 3, 4, 4, 4, 5};
    cout << "   Vector with duplicates: ";
    displayVector(dupArr);
    removeDuplicates(dupArr);
    displayVector(dupArr);

    cout << "\n==========================================" << endl;
    cout << "Program completed successfully!" << endl;
    cout << "==========================================" << endl;

    return 0;
}
