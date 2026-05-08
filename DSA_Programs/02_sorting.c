#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * DSA - Sorting Algorithms in C
 *
 * Concepts Covered:
 * 1. Bubble Sort - O(n²) time complexity
 * 2. Selection Sort - O(n²) time complexity
 * 3. Insertion Sort - O(n²) time complexity
 * 4. Quick Sort - O(n log n) average time complexity
 * 5. Merge Sort - O(n log n) time complexity
 * 6. Time complexity analysis
 * 7. Stability of sorting algorithms
 */

#define MAX_SIZE 100

// Function to display array elements
void displayArray(int arr[], int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\n");
}

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// BUBBLE SORT - O(n²) time complexity
// Stable sorting algorithm
// Best case: O(n) when already sorted
void bubbleSort(int arr[], int size) {
    printf("\n--- Bubble Sort ---\n");
    int comparisons = 0, swaps = 0;

    for (int i = 0; i < size - 1; i++) {
        int swapped = 0;  // Optimization: stop if no swaps in a pass

        for (int j = 0; j < size - i - 1; j++) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swaps++;
                swapped = 1;
            }
        }

        if (!swapped) break;  // Array is already sorted
    }

    printf("Comparisons: %d, Swaps: %d\n", comparisons, swaps);
}

// SELECTION SORT - O(n²) time complexity
// Unstable sorting algorithm
// Always O(n²) time complexity
void selectionSort(int arr[], int size) {
    printf("\n--- Selection Sort ---\n");
    int comparisons = 0, swaps = 0;

    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;

        // Find minimum element in unsorted part
        for (int j = i + 1; j < size; j++) {
            comparisons++;
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Swap if minimum element is not at current position
        if (minIndex != i) {
            swap(&arr[i], &arr[minIndex]);
            swaps++;
        }
    }

    printf("Comparisons: %d, Swaps: %d\n", comparisons, swaps);
}

// INSERTION SORT - O(n²) time complexity
// Stable sorting algorithm
// Best case: O(n) when already sorted
void insertionSort(int arr[], int size) {
    printf("\n--- Insertion Sort ---\n");
    int comparisons = 0, shifts = 0;

    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;

        // Move elements greater than key to one position ahead
        while (j >= 0 && arr[j] > key) {
            comparisons++;
            arr[j + 1] = arr[j];
            shifts++;
            j--;
        }

        if (j >= 0) comparisons++;  // Count the final comparison that stops the loop
        arr[j + 1] = key;
    }

    printf("Comparisons: %d, Shifts: %d\n", comparisons, shifts);
}

// QUICK SORT - O(n log n) average time complexity
// Unstable sorting algorithm
// Worst case: O(n²) when array is already sorted/reverse sorted

// Partition function for Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Choose last element as pivot
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// Quick Sort recursive function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);

        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

// Wrapper function for Quick Sort
void quickSortWrapper(int arr[], int size) {
    printf("\n--- Quick Sort ---\n");
    quickSort(arr, 0, size - 1);
    printf("Quick sort completed\n");
}

// MERGE SORT - O(n log n) time complexity
// Stable sorting algorithm
// Always O(n log n) time complexity

// Merge function for Merge Sort
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    int* L = (int*)malloc(n1 * sizeof(int));
    int* R = (int*)malloc(n2 * sizeof(int));

    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[left..right]
    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of L[]
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy remaining elements of R[]
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

// Merge Sort recursive function
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

// Wrapper function for Merge Sort
void mergeSortWrapper(int arr[], int size) {
    printf("\n--- Merge Sort ---\n");
    mergeSort(arr, 0, size - 1);
    printf("Merge sort completed\n");
}

// Function to copy array
void copyArray(int source[], int dest[], int size) {
    for (int i = 0; i < size; i++) {
        dest[i] = source[i];
    }
}

// Function to measure execution time (in milliseconds)
double measureTime(void (*sortFunc)(int[], int), int arr[], int size) {
    clock_t start = clock();
    sortFunc(arr, size);
    clock_t end = clock();
    return ((double)(end - start) / CLOCKS_PER_SEC) * 1000;
}

int main() {
    printf("==========================================\n");
    printf("   DSA - Sorting Algorithms in C\n");
    printf("==========================================\n");

    // Test data
    int original[] = {64, 34, 25, 12, 22, 11, 90, 5, 77, 30};
    int size = sizeof(original) / sizeof(original[0]);

    printf("\nOriginal Array: ");
    displayArray(original, size);

    // Test each sorting algorithm with a copy of the original array
    int testArray[MAX_SIZE];

    // Bubble Sort
    copyArray(original, testArray, size);
    bubbleSort(testArray, size);
    printf("Sorted: ");
    displayArray(testArray, size);

    // Selection Sort
    copyArray(original, testArray, size);
    selectionSort(testArray, size);
    printf("Sorted: ");
    displayArray(testArray, size);

    // Insertion Sort
    copyArray(original, testArray, size);
    insertionSort(testArray, size);
    printf("Sorted: ");
    displayArray(testArray, size);

    // Quick Sort
    copyArray(original, testArray, size);
    quickSortWrapper(testArray, size);
    printf("Sorted: ");
    displayArray(testArray, size);

    // Merge Sort
    copyArray(original, testArray, size);
    mergeSortWrapper(testArray, size);
    printf("Sorted: ");
    displayArray(testArray, size);

    // Performance comparison with larger array
    printf("\n==========================================\n");
    printf("   Performance Comparison\n");
    printf("==========================================\n");

    // Create a larger random array for performance testing
    int largeArray[1000];
    srand(time(NULL));
    for (int i = 0; i < 1000; i++) {
        largeArray[i] = rand() % 10000;
    }

    int testLarge[MAX_SIZE];

    // Test Bubble Sort (commented out for large arrays as it's slow)
    // copyArray(largeArray, testLarge, 1000);
    // double bubbleTime = measureTime(bubbleSort, testLarge, 1000);
    // printf("Bubble Sort (1000 elements): %.2f ms\n", bubbleTime);

    // Test Quick Sort
    copyArray(largeArray, testLarge, 1000);
    double quickTime = measureTime(quickSortWrapper, testLarge, 1000);
    printf("Quick Sort (1000 elements): %.2f ms\n", quickTime);

    // Test Merge Sort
    copyArray(largeArray, testLarge, 1000);
    double mergeTime = measureTime(mergeSortWrapper, testLarge, 1000);
    printf("Merge Sort (1000 elements): %.2f ms\n", mergeTime);

    printf("\n==========================================\n");
    printf("   Sorting Algorithm Summary\n");
    printf("==========================================\n");
    printf("Algorithm     | Time Complexity | Stability | Best Case\n");
    printf("--------------|----------------|-----------|-----------\n");
    printf("Bubble Sort   | O(n²)          | Stable    | O(n)\n");
    printf("Selection Sort| O(n²)          | Unstable  | O(n²)\n");
    printf("Insertion Sort| O(n²)          | Stable    | O(n)\n");
    printf("Quick Sort    | O(n log n) avg | Unstable  | O(n log n)\n");
    printf("Merge Sort    | O(n log n)     | Stable    | O(n log n)\n");

    printf("\nProgram completed successfully!\n");
    return 0;
}
