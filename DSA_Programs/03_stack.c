#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * DSA - Stack Data Structure in C
 *
 * Concepts Covered:
 * 1. Stack - LIFO (Last In First Out)
 * 2. Push operation - O(1)
 * 3. Pop operation - O(1)
 * 4. Peek operation - O(1)
 * 5. Stack applications: Expression evaluation, backtracking
 * 6. Stack overflow and underflow handling
 */

#define MAX_SIZE 100

typedef struct {
    int arr[MAX_SIZE];
    int top;
} Stack;

// Initialize stack
Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = -1;
    return stack;
}

// Check if stack is empty
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Check if stack is full
int isFull(Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

// Push element onto stack
void push(Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack Overflow! Cannot push %d\n", value);
        return;
    }
    stack->arr[++stack->top] = value;
    printf("Pushed %d onto stack\n", value);
}

// Pop element from stack
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow! Cannot pop\n");
        return -1;
    }
    return stack->arr[stack->top--];
}

// Peek top element
int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty!\n");
        return -1;
    }
    return stack->arr[stack->top];
}

// Display stack elements
void displayStack(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack (top to bottom): ");
    for (int i = stack->top; i >= 0; i--) {
        printf("%d ", stack->arr[i]);
    }
    printf("\n");
}

// Get stack size
int getSize(Stack* stack) {
    return stack->top + 1;
}

// Clear stack
void clearStack(Stack* stack) {
    stack->top = -1;
    printf("Stack cleared!\n");
}

// Check if parentheses are balanced
int areParenthesesBalanced(char* expr) {
    Stack* stack = createStack();
    
    for (int i = 0; expr[i] != '\0'; i++) {
        if (expr[i] == '(' || expr[i] == '[' || expr[i] == '{') {
            push(stack, expr[i]);
        } else if (expr[i] == ')' || expr[i] == ']' || expr[i] == '}') {
            if (isEmpty(stack)) {
                free(stack);
                return 0;
            }
            
            int top = pop(stack);
            if ((expr[i] == ')' && top != '(') ||
                (expr[i] == ']' && top != '[') ||
                (expr[i] == '}' && top != '{')) {
                free(stack);
                return 0;
            }
        }
    }
    
    int balanced = isEmpty(stack);
    free(stack);
    return balanced;
}

// Reverse a string using stack
void reverseString(char* str) {
    Stack* stack = createStack();
    int len = strlen(str);
    
    printf("Original string: %s\n", str);
    
    for (int i = 0; i < len; i++) {
        push(stack, str[i]);
    }
    
    printf("Reversed string: ");
    while (!isEmpty(stack)) {
        printf("%c", pop(stack));
    }
    printf("\n");
    
    free(stack);
}

// Decimal to binary conversion
void decimalToBinary(int num) {
    if (num == 0) {
        printf("Binary: 0\n");
        return;
    }
    
    Stack* stack = createStack();
    
    while (num > 0) {
        push(stack, num % 2);
        num /= 2;
    }
    
    printf("Binary: ");
    while (!isEmpty(stack)) {
        printf("%d", pop(stack));
    }
    printf("\n");
    
    free(stack);
}

int main() {
    printf("==========================================\n");
    printf("   DSA - Stack Data Structure (C)\n");
    printf("==========================================\n");

    // Create a stack
    Stack* stack = createStack();

    // 1. Basic push and display
    printf("\n1. Push Operations:\n");
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    push(stack, 40);
    push(stack, 50);
    displayStack(stack);

    // 2. Peek operation
    printf("\n2. Peek (top element): %d\n", peek(stack));

    // 3. Get size
    printf("\n3. Stack Size: %d\n", getSize(stack));

    // 4. Pop operations
    printf("\n4. Pop Operations:\n");
    printf("Popped: %d\n", pop(stack));
    printf("Popped: %d\n", pop(stack));
    displayStack(stack);

    // 5. Check empty and full
    printf("\n5. Stack Status:\n");
    printf("Is Empty? %s\n", isEmpty(stack) ? "Yes" : "No");
    printf("Is Full? %s\n", isFull(stack) ? "Yes" : "No");

    // 6. Clear stack
    printf("\n6. Clearing Stack:\n");
    clearStack(stack);
    displayStack(stack);

    // 7. Push again
    printf("\n7. Push After Clear:\n");
    for (int i = 1; i <= 3; i++) {
        push(stack, i * 100);
    }
    displayStack(stack);

    // 8. Pop until empty
    printf("\n8. Pop All Elements:\n");
    while (!isEmpty(stack)) {
        printf("Popped: %d\n", pop(stack));
    }
    printf("Stack is now empty: %s\n", isEmpty(stack) ? "Yes" : "No");

    // 9. Balanced parentheses check
    printf("\n9. Balanced Parentheses Check:\n");
    char expr1[] = "({[]})";
    char expr2[] = "({[}])";
    char expr3[] = "({[)]}";
    
    printf("Expression: %s - %s\n", expr1, areParenthesesBalanced(expr1) ? "Balanced" : "Not Balanced");
    printf("Expression: %s - %s\n", expr2, areParenthesesBalanced(expr2) ? "Balanced" : "Not Balanced");
    printf("Expression: %s - %s\n", expr3, areParenthesesBalanced(expr3) ? "Balanced" : "Not Balanced");

    // 10. String reversal using stack
    printf("\n10. String Reversal:\n");
    reverseString("HELLO");
    reverseString("STACK");

    // 11. Decimal to binary conversion
    printf("\n11. Decimal to Binary Conversion:\n");
    decimalToBinary(10);
    decimalToBinary(25);
    decimalToBinary(100);

    // 12. Stack overflow test
    printf("\n12. Testing Stack Overflow:\n");
    Stack* smallStack = createStack();
    for (int i = 0; i < MAX_SIZE + 2; i++) {
        push(smallStack, i);
    }

    free(stack);
    free(smallStack);

    printf("\n==========================================\n");
    printf("Program completed successfully!\n");
    printf("==========================================\n");

    return 0;
}
