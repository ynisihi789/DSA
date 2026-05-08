#include <stdio.h>
#include <stdlib.h>

/*
 * DSA Fundamentals - Array Basics and Linear Search
 * 
 * Concepts Covered:
 * 1. Array Declaration and Initialization
 * 2. Traversing an Array
 * 3. Linear Search Algorithm (O(n) time complexity)
 * 4. Array Insertion and Deletion
 */

#define MAX_SIZE 100

// Function to display array elements
void displayArray(int arr[], int size) {
    printf("\nArray Elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Linear Search - O(n) time complexity
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;  // Element found at index i
        }
    }
    return -1;  // Element not found
}

// Insert element at a specific position
void insertElement(int arr[], int *size, int position, int value) {
    if (*size >= MAX_SIZE) {
        printf("Array is full! Cannot insert.\n");
        return;
    }
    
    if (position < 0 || position > *size) {
        printf("Invalid position!\n");
        return;
    }
    
    // Shift elements to the right
    for (int i = *size - 1; i >= position; i--) {
        arr[i + 1] = arr[i];
    }
    
    arr[position] = value;
    (*size)++;
    printf("Inserted %d at position %d\n", value, position);
}

// Delete element at a specific position
void deleteElement(int arr[], int *size, int position) {
    if (position < 0 || position >= *size) {
        printf("Invalid position!\n");
        return;
    }
    
    int deletedValue = arr[position];
    
    // Shift elements to the left
    for (int i = position; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    
    (*size)--;
    printf("Deleted %d from position %d\n", deletedValue, position);
}

// Calculate sum of array elements
int arraySum(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

// Find maximum element in array
int findMax(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Find minimum element in array
int findMin(int arr[], int size) {
    int min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

// Reverse an array
void reverseArray(int arr[], int size) {
    int start = 0, end = size - 1;
    
    while (start < end) {
        // Swap elements
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        
        start++;
        end--;
    }
    printf("Array reversed!\n");
}

int main() {
    int arr[MAX_SIZE] = {15, 23, 8, 42, 16, 4, 99, 50, 12, 35};
    int size = 10;
    
    printf("========================================\n");
    printf("   DSA Fundamentals - Array Basics\n");
    printf("========================================\n");
    
    // 1. Display original array
    printf("\n1. Original Array:");
    displayArray(arr, size);
    
    // 2. Linear Search
    printf("\n2. Linear Search:");
    int target = 42;
    int index = linearSearch(arr, size, target);
    if (index != -1) {
        printf("   Element %d found at index %d\n", target, index);
    } else {
        printf("   Element %d not found\n", target);
    }
    
    // 3. Search for element not in array
    target = 100;
    index = linearSearch(arr, size, target);
    if (index != -1) {
        printf("   Element %d found at index %d\n", target, index);
    } else {
        printf("   Element %d not found\n", target);
    }
    
    // 4. Insert element
    printf("\n3. Insertion Operation:");
    insertElement(arr, &size, 3, 77);
    displayArray(arr, size);
    
    // 5. Delete element
    printf("\n4. Deletion Operation:");
    deleteElement(arr, &size, 5);
    displayArray(arr, size);
    
    // 6. Array sum
    printf("\n5. Array Sum:");
    int sum = arraySum(arr, size);
    printf("   Sum of all elements: %d\n", sum);
    
    // 7. Find max and min
    printf("\n6. Find Maximum and Minimum:");
    printf("   Maximum element: %d\n", findMax(arr, size));
    printf("   Minimum element: %d\n", findMin(arr, size));
    
    // 8. Reverse array
    printf("\n7. Reverse Array:");
    reverseArray(arr, size);
    displayArray(arr, size);
    
    // 9. Average calculation
    printf("\n8. Array Average:");
    printf("   Average: %.2f\n", (float)sum / size);
    
    printf("\n========================================\n");
    printf("Program completed successfully!\n");
    printf("========================================\n");
    
    return 0;
}
