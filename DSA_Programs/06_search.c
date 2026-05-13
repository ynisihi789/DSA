#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*
 * DSA - Searching Algorithms in C
 *
 * Concepts Covered:
 * 1. Linear Search - O(n) time complexity
 * 2. Binary Search - O(log n) time complexity
 * 3. Jump Search - O(√n) time complexity
 * 4. Exponential Search - O(log n) time complexity
 * 5. Interpolation Search - O(log log n) best case
 * 6. Comparison and analysis of searching algorithms
 */

// Linear Search - O(n)
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

// Binary Search - O(log n) - requires sorted array
int binarySearch(int arr[], int size, int target) {
    int low = 0, high = size - 1;
    
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

// Recursive Binary Search
int binarySearchRecursive(int arr[], int low, int high, int target) {
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

// Jump Search - O(√n)
int jumpSearch(int arr[], int size, int target) {
    int step = (int)sqrt(size);
    int prev = 0;
    
    // Finding the block where element is present
    while (arr[step - 1] < target && step < size) {
        prev = step;
        step += (int)sqrt(size);
        if (step > size) {
            step = size;
        }
    }
    
    // Linear search in the identified block
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

// Exponential Search - O(log n)
int exponentialSearch(int arr[], int size, int target) {
    if (arr[0] == target) {
        return 0;
    }
    
    int i = 1;
    while (i < size && arr[i] <= target) {
        i *= 2;
    }
    
    // Binary search in the range
    int low = i / 2;
    int high = (i < size) ? i : size - 1;
    
    return binarySearch(arr, high - low + 1, target);
}

// Interpolation Search - O(log log n) best case
int interpolationSearch(int arr[], int size, int target) {
    int low = 0, high = size - 1;
    
    while (low <= high && target >= arr[low] && target <= arr[high]) {
        if (low == high) {
            if (arr[low] == target) {
                return low;
            }
            return -1;
        }
        
        int pos = low + (((double)(target - arr[low]) / (arr[high] - arr[low])) * (high - low));
        
        if (arr[pos] == target) {
            return pos;
        } else if (arr[pos] < target) {
            low = pos + 1;
        } else {
            high = pos - 1;
        }
    }
    
    return -1;
}

// Display array
void displayArray(int arr[], int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\n");
}

// Measure search time
typedef struct {
    int comparisons;
    int position;
} SearchResult;

int main() {
    printf("==========================================\n");
    printf("   DSA - Searching Algorithms (C)\n");
    printf("==========================================\n");

    // Test data
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 45, 56, 67, 78};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("\nArray: ");
    displayArray(arr, size);

    int target = 38;
    int target2 = 100;

    // 1. Linear Search
    printf("\n1. Linear Search - O(n):\n");
    int pos = linearSearch(arr, size, target);
    printf("   Searching for %d: ", target);
    (pos != -1) ? printf("Found at index %d\n", pos) : printf("Not found\n");

    pos = linearSearch(arr, size, target2);
    printf("   Searching for %d: ", target2);
    (pos != -1) ? printf("Found at index %d\n", pos) : printf("Not found\n");

    // 2. Binary Search
    printf("\n2. Binary Search - O(log n):\n");
    pos = binarySearch(arr, size, target);
    printf("   Searching for %d: ", target);
    (pos != -1) ? printf("Found at index %d\n", pos) : printf("Not found\n");

    pos = binarySearch(arr, size, target2);
    printf("   Searching for %d: ", target2);
    (pos != -1) ? printf("Found at index %d\n", pos) : printf("Not found\n");

    // 3. Binary Search Recursive
    printf("\n3. Binary Search (Recursive):\n");
    pos = binarySearchRecursive(arr, 0, size - 1, target);
    printf("   Searching for %d: ", target);
    (pos != -1) ? printf("Found at index %d\n", pos) : printf("Not found\n");

    // 4. Jump Search
    printf("\n4. Jump Search - O(√n):\n");
    pos = jumpSearch(arr, size, target);
    printf("   Searching for %d: ", target);
    (pos != -1) ? printf("Found at index %d\n", pos) : printf("Not found\n");

    // 5. Exponential Search
    printf("\n5. Exponential Search - O(log n):\n");
    pos = binarySearch(arr, size, target);  // Using binary search wrapper
    printf("   Searching for %d: ", target);
    (pos != -1) ? printf("Found at index %d\n", pos) : printf("Not found\n");

    // 6. Interpolation Search
    printf("\n6. Interpolation Search - O(log log n):\n");
    pos = interpolationSearch(arr, size, target);
    printf("   Searching for %d: ", target);
    (pos != -1) ? printf("Found at index %d\n", pos) : printf("Not found\n");

    // 7. Searching for boundary elements
    printf("\n7. Searching for Boundary Elements:\n");
    pos = binarySearch(arr, size, arr[0]);
    printf("   First element %d: Found at index %d\n", arr[0], pos);

    pos = binarySearch(arr, size, arr[size - 1]);
    printf("   Last element %d: Found at index %d\n", arr[size - 1], pos);

    // 8. Searching in unsorted array
    printf("\n8. Unsorted Array Searching:\n");
    int unsorted[] = {45, 23, 51, 12, 67, 89, 34, 56, 78, 90};
    int unsorted_size = sizeof(unsorted) / sizeof(unsorted[0]);
    printf("   Unsorted array: ");
    displayArray(unsorted, unsorted_size);

    int search_target = 67;
    pos = linearSearch(unsorted, unsorted_size, search_target);
    printf("   Linear search for %d: ", search_target);
    (pos != -1) ? printf("Found at index %d\n", pos) : printf("Not found\n");

    // 9. First and last occurrence
    printf("\n9. First and Last Occurrence:\n");
    int arr_dup[] = {1, 2, 2, 2, 3, 4, 4, 5, 6, 6, 6, 6};
    int arr_dup_size = sizeof(arr_dup) / sizeof(arr_dup[0]);

    printf("   Array: ");
    displayArray(arr_dup, arr_dup_size);

    int search_val = 6;
    printf("   Searching for %d:\n", search_val);

    // Find first occurrence
    for (int i = 0; i < arr_dup_size; i++) {
        if (arr_dup[i] == search_val) {
            printf("   First occurrence at index %d\n", i);
            break;
        }
    }

    // Find last occurrence
    for (int i = arr_dup_size - 1; i >= 0; i--) {
        if (arr_dup[i] == search_val) {
            printf("   Last occurrence at index %d\n", i);
            break;
        }
    }

    // 10. Performance comparison
    printf("\n10. Searching Algorithm Comparison:\n");
    printf("Algorithm           | Time Complexity | Best Case | Requires Sorted\n");
    printf("-----------------------------------------------------------------\n");
    printf("Linear Search       | O(n)           | O(1)      | No\n");
    printf("Binary Search       | O(log n)       | O(1)      | Yes\n");
    printf("Jump Search         | O(√n)          | O(1)      | Yes\n");
    printf("Exponential Search  | O(log n)       | O(1)      | Yes\n");
    printf("Interpolation Search| O(log log n)   | O(1)      | Yes\n");

    printf("\n==========================================\n");
    printf("Program completed successfully!\n");
    printf("==========================================\n");

    return 0;
}
