#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <iomanip>

/*
 * DSA - Stack Data Structure in C++
 *
 * Concepts Covered:
 * 1. std::stack - LIFO (Last In First Out)
 * 2. Push, Pop, Top operations
 * 3. Stack applications: Expression evaluation, backtracking, DFS
 * 4. Custom Stack implementation with templates
 * 5. Stack vs Queue comparison
 */

using namespace std;

// Custom Stack template implementation
template <typename T>
class CustomStack {
private:
    vector<T> elements;
    
public:
    // Push element onto stack
    void push(const T& value) {
        elements.push_back(value);
        cout << "Pushed " << value << " onto stack" << endl;
    }
    
    // Pop element from stack
    T pop() {
        if (isEmpty()) {
            cerr << "Stack Underflow! Cannot pop" << endl;
            return T();
        }
        T value = elements.back();
        elements.pop_back();
        return value;
    }
    
    // Peek top element
    T peek() const {
        if (isEmpty()) {
            cerr << "Stack is empty!" << endl;
            return T();
        }
        return elements.back();
    }
    
    // Check if empty
    bool isEmpty() const {
        return elements.empty();
    }
    
    // Get stack size
    int getSize() const {
        return elements.size();
    }
    
    // Display stack
    void display() const {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Stack (top to bottom): ";
        for (auto it = elements.rbegin(); it != elements.rend(); ++it) {
            cout << *it << " ";
        }
        cout << endl;
    }
    
    // Clear stack
    void clear() {
        elements.clear();
        cout << "Stack cleared!" << endl;
    }
};

// Check if parentheses are balanced
bool areParenthesesBalanced(const string& expr) {
    stack<char> st;
    
    for (char ch : expr) {
        if (ch == '(' || ch == '[' || ch == '{') {
            st.push(ch);
        } else if (ch == ')' || ch == ']' || ch == '}') {
            if (st.empty()) return false;
            
            char top = st.top();
            st.pop();
            
            if ((ch == ')' && top != '(') ||
                (ch == ']' && top != '[') ||
                (ch == '}' && top != '{')) {
                return false;
            }
        }
    }
    
    return st.empty();
}

// Reverse a string using stack
void reverseString(const string& str) {
    stack<char> st;
    
    cout << "Original string: " << str << endl;
    
    for (char ch : str) {
        st.push(ch);
    }
    
    cout << "Reversed string: ";
    while (!st.empty()) {
        cout << st.top();
        st.pop();
    }
    cout << endl;
}

// Decimal to binary conversion
void decimalToBinary(int num) {
    if (num == 0) {
        cout << "Binary: 0" << endl;
        return;
    }
    
    stack<int> st;
    int original = num;
    
    while (num > 0) {
        st.push(num % 2);
        num /= 2;
    }
    
    cout << "Decimal " << original << " to Binary: ";
    while (!st.empty()) {
        cout << st.top();
        st.pop();
    }
    cout << endl;
}

// Evaluate postfix expression
int evaluatePostfix(const string& expr) {
    stack<int> st;
    
    for (char ch : expr) {
        if (isdigit(ch)) {
            st.push(ch - '0');
        } else {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            
            switch (ch) {
                case '+': st.push(a + b); break;
                case '-': st.push(a - b); break;
                case '*': st.push(a * b); break;
                case '/': st.push(a / b); break;
            }
        }
    }
    
    return st.top();
}

// Next greater element using stack
vector<int> nextGreaterElement(const vector<int>& arr) {
    vector<int> result(arr.size(), -1);
    stack<int> st;
    
    for (int i = arr.size() - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= arr[i]) {
            st.pop();
        }
        
        if (!st.empty()) {
            result[i] = st.top();
        }
        
        st.push(arr[i]);
    }
    
    return result;
}

int main() {
    cout << "==========================================" << endl;
    cout << "   DSA - Stack Data Structure (C++)" << endl;
    cout << "==========================================" << endl;

    // 1. Using std::stack
    cout << "\n1. Using std::stack (STL):" << endl;
    stack<int> stdStack;
    
    stdStack.push(10);
    stdStack.push(20);
    stdStack.push(30);
    stdStack.push(40);
    stdStack.push(50);
    
    cout << "Pushed: 10, 20, 30, 40, 50" << endl;
    cout << "Size: " << stdStack.size() << endl;
    cout << "Top element: " << stdStack.top() << endl;

    // 2. Custom Stack template
    cout << "\n2. Custom Stack Implementation:" << endl;
    CustomStack<int> myStack;
    
    myStack.push(100);
    myStack.push(200);
    myStack.push(300);
    myStack.display();
    
    cout << "Peek: " << myStack.peek() << endl;
    cout << "Size: " << myStack.getSize() << endl;

    // 3. Pop operations
    cout << "\n3. Pop Operations:" << endl;
    cout << "Popped: " << myStack.pop() << endl;
    cout << "Popped: " << myStack.pop() << endl;
    myStack.display();

    // 4. STL Stack pop demonstration
    cout << "\n4. STL Stack - Pop All:" << endl;
    while (!stdStack.empty()) {
        cout << "Popped: " << stdStack.top() << endl;
        stdStack.pop();
    }
    cout << "Stack empty: " << (stdStack.empty() ? "Yes" : "No") << endl;

    // 5. Balanced parentheses
    cout << "\n5. Balanced Parentheses Check:" << endl;
    vector<string> expressions = {"({[]})", "({[}])", "({[)]}"};
    for (const auto& expr : expressions) {
        cout << "Expression: " << expr << " - " 
             << (areParenthesesBalanced(expr) ? "Balanced" : "Not Balanced") << endl;
    }

    // 6. String reversal
    cout << "\n6. String Reversal:" << endl;
    reverseString("HELLO");
    reverseString("STACK");
    reverseString("WORLD");

    // 7. Decimal to binary
    cout << "\n7. Decimal to Binary Conversion:" << endl;
    decimalToBinary(10);
    decimalToBinary(25);
    decimalToBinary(100);
    decimalToBinary(255);

    // 8. Postfix expression evaluation
    cout << "\n8. Postfix Expression Evaluation:" << endl;
    string postfixExpr = "23*54*+";  // (2*3) + (5*4) = 26
    cout << "Postfix: " << postfixExpr << " = " << evaluatePostfix(postfixExpr) << endl;
    
    postfixExpr = "512*+3-";  // (5 + (1*2)) - 3 = 4
    cout << "Postfix: " << postfixExpr << " = " << evaluatePostfix(postfixExpr) << endl;

    // 9. Next greater element
    cout << "\n9. Next Greater Element:" << endl;
    vector<int> arr = {4, 5, 2, 25, 7, 8};
    cout << "Array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;
    
    vector<int> result = nextGreaterElement(arr);
    cout << "Next Greater Element: ";
    for (int x : result) cout << x << " ";
    cout << endl;

    // 10. Stack with different data types
    cout << "\n10. Custom Stack with Different Data Types:" << endl;
    
    CustomStack<double> doubleStack;
    doubleStack.push(3.14);
    doubleStack.push(2.71);
    doubleStack.push(1.41);
    doubleStack.display();

    // 11. Stack memory demonstration
    cout << "\n11. Stack Memory Behavior:" << endl;
    CustomStack<string> stringStack;
    stringStack.push("First");
    stringStack.push("Second");
    stringStack.push("Third");
    stringStack.display();
    cout << "LIFO - Last pushed (Third) will pop first!" << endl;

    // 12. Recursive function stack (depth demonstration)
    cout << "\n12. Call Stack Demonstration:" << endl;
    cout << "Function calls use internal stacks for recursion" << endl;
    cout << "Example: factorial(5) creates a call stack of depth 6" << endl;

    cout << "\n==========================================" << endl;
    cout << "   Stack Applications Summary" << endl;
    cout << "==========================================" << endl;
    cout << "1. Expression evaluation (infix to postfix)" << endl;
    cout << "2. Backtracking algorithms" << endl;
    cout << "3. Depth-First Search (DFS)" << endl;
    cout << "4. Function call management" << endl;
    cout << "5. Undo/Redo functionality" << endl;
    cout << "6. Browser history" << endl;

    cout << "\nProgram completed successfully!" << endl;
    return 0;
}
