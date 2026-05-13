#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * DSA - Recursion Fundamentals in C
 *
 * Concepts Covered:
 * 1. Basic recursion concepts
 * 2. Factorial, Fibonacci
 * 3. Tree traversals (recursive)
 * 4. Backtracking algorithms
 * 5. Tail recursion optimization
 * 6. Dynamic programming vs Recursion
 * 7. Common recursion pitfalls and optimization
 */

// 1. Simple Factorial - Recursive
long long factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

// 2. Factorial with Tail Recursion
long long factorialTail(int n, long long acc) {
    if (n <= 1) return acc;
    return factorialTail(n - 1, n * acc);
}

// 3. Fibonacci - Basic Recursion (Inefficient)
long long fibonacciBasic(int n) {
    if (n <= 1) return n;
    return fibonacciBasic(n - 1) + fibonacciBasic(n - 2);
}

// 4. Fibonacci - Memoization (Optimization)
long long memo[100] = {0};

long long fibonacciMemo(int n) {
    if (n <= 1) return n;
    
    if (memo[n] != 0) {
        return memo[n];
    }
    
    memo[n] = fibonacciMemo(n - 1) + fibonacciMemo(n - 2);
    return memo[n];
}

// 5. Power function - O(log n)
long long power(int base, int exp) {
    if (exp == 0) return 1;
    if (exp == 1) return base;
    
    long long halfPower = power(base, exp / 2);
    
    if (exp % 2 == 0) {
        return halfPower * halfPower;
    } else {
        return base * halfPower * halfPower;
    }
}

// 6. Sum of array elements
int sumArray(int arr[], int n) {
    if (n == 0) return 0;
    return arr[n - 1] + sumArray(arr, n - 1);
}

// 7. Search in array (Linear search recursive)
int linearSearchRecursive(int arr[], int n, int target, int index) {
    if (index == n) return -1;
    if (arr[index] == target) return index;
    return linearSearchRecursive(arr, n, target, index + 1);
}

// 8. Binary search recursive
int binarySearchRecursive(int arr[], int target, int low, int high) {
    if (low > high) return -1;
    
    int mid = low + (high - low) / 2;
    
    if (arr[mid] == target) {
        return mid;
    } else if (arr[mid] < target) {
        return binarySearchRecursive(arr, target, mid + 1, high);
    } else {
        return binarySearchRecursive(arr, target, low, mid - 1);
    }
}

// 9. String reversal recursive
void reverseString(char str[], int start, int end) {
    if (start >= end) return;
    
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    
    reverseString(str, start + 1, end - 1);
}

// 10. Check if palindrome
int isPalindrome(char str[], int start, int end) {
    if (start >= end) return 1;
    
    if (str[start] != str[end]) return 0;
    
    return isPalindrome(str, start + 1, end - 1);
}

// 11. GCD (Greatest Common Divisor) - Euclidean Algorithm
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

// 12. Count digits
int countDigits(int n) {
    if (n == 0) return 0;
    return 1 + countDigits(n / 10);
}

// 13. Print all subsets (Backtracking)
void printSubsets(int arr[], int n, int index, int subset[], int subsetSize) {
    printf("{ ");
    for (int i = 0; i < subsetSize; i++) {
        printf("%d ", subset[i]);
    }
    printf("}\n");
    
    for (int i = index; i < n; i++) {
        subset[subsetSize] = arr[i];
        printSubsets(arr, n, i + 1, subset, subsetSize + 1);
    }
}

// 14. N-Queens problem (Backtracking) - Simple version
int canPlace(int board[8][8], int row, int col, int n) {
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) return 0;
    }
    
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) return 0;
    }
    
    for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 1) return 0;
    }
    
    return 1;
}

// 15. Tower of Hanoi
void hanoi(int n, char source, char destination, char auxiliary) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }
    
    hanoi(n - 1, source, auxiliary, destination);
    printf("Move disk %d from %c to %c\n", n, source, destination);
    hanoi(n - 1, auxiliary, destination, source);
}

int main() {
    printf("==========================================\n");
    printf("   DSA - Recursion Fundamentals (C)\n");
    printf("==========================================\n");

    // 1. Factorial
    printf("\n1. Factorial (Recursive):\n");
    for (int i = 0; i <= 5; i++) {
        printf("   %d! = %lld\n", i, factorial(i));
    }

    // 2. Factorial with Tail Recursion
    printf("\n2. Factorial (Tail Recursion):\n");
    printf("   5! = %lld (using tail recursion)\n", factorialTail(5, 1));

    // 3. Fibonacci - Basic
    printf("\n3. Fibonacci (Basic Recursion - Slow):\n");
    for (int i = 0; i <= 6; i++) {
        printf("   fib(%d) = %lld\n", i, fibonacciBasic(i));
    }

    // 4. Fibonacci - Memoization
    printf("\n4. Fibonacci (Memoization - Fast):\n");
    for (int i = 0; i <= 10; i++) {
        printf("   fib(%d) = %lld\n", i, fibonacciMemo(i));
    }

    // 5. Power function
    printf("\n5. Power Function (Fast - O(log n)):\n");
    printf("   2^10 = %lld\n", power(2, 10));
    printf("   3^5 = %lld\n", power(3, 5));

    // 6. Sum of array
    printf("\n6. Sum of Array (Recursive):\n");
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("   Array: [1, 2, 3, 4, 5]\n");
    printf("   Sum: %d\n", sumArray(arr, size));

    // 7. Linear search recursive
    printf("\n7. Linear Search (Recursive):\n");
    int pos = linearSearchRecursive(arr, size, 3, 0);
    printf("   Searching for 3: Found at index %d\n", pos);

    // 8. Binary search recursive
    printf("\n8. Binary Search (Recursive):\n");
    int sorted[] = {2, 5, 8, 12, 16, 23, 38};
    int sorted_size = sizeof(sorted) / sizeof(sorted[0]);
    pos = binarySearchRecursive(sorted, 23, 0, sorted_size - 1);
    printf("   Searching for 23: Found at index %d\n", pos);

    // 9. String reversal
    printf("\n9. String Reversal (Recursive):\n");
    char str[] = "RECURSION";
    printf("   Original: %s\n", str);
    reverseString(str, 0, strlen(str) - 1);
    printf("   Reversed: %s\n", str);

    // 10. Palindrome check
    printf("\n10. Palindrome Check (Recursive):\n");
    char pal1[] = "racecar";
    char pal2[] = "hello";
    printf("   '%s' is palindrome: %s\n", pal1, isPalindrome(pal1, 0, strlen(pal1) - 1) ? "Yes" : "No");
    printf("   '%s' is palindrome: %s\n", pal2, isPalindrome(pal2, 0, strlen(pal2) - 1) ? "Yes" : "No");

    // 11. GCD
    printf("\n11. GCD (Greatest Common Divisor):\n");
    printf("   GCD(48, 18) = %d\n", gcd(48, 18));
    printf("   GCD(100, 25) = %d\n", gcd(100, 25));

    // 12. Count digits
    printf("\n12. Count Digits (Recursive):\n");
    printf("   Number of digits in 12345: %d\n", countDigits(12345));

    // 13. Subsets
    printf("\n13. All Subsets of {1, 2, 3}:\n");
    int subset_arr[] = {1, 2, 3};
    int subset[10];
    printSubsets(subset_arr, 3, 0, subset, 0);

    // 14. Tower of Hanoi
    printf("\n14. Tower of Hanoi (3 disks):\n");
    hanoi(3, 'A', 'C', 'B');

    // 15. Recursion vs Iteration
    printf("\n15. Recursion vs Iteration:\n");
    printf("   Recursion:\n");
    printf("   - Easy to understand and implement\n");
    printf("   - Can cause stack overflow\n");
    printf("   - Slower due to function call overhead\n");
    printf("   Iteration:\n");
    printf("   - More efficient\n");
    printf("   - Uses loops instead of calls\n");
    printf("   - Better for large inputs\n");

    printf("\n==========================================\n");
    printf("Program completed successfully!\n");
    printf("==========================================\n");

    return 0;
}
