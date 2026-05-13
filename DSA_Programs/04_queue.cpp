#include <iostream>
#include <queue>
#include <deque>
#include <vector>
#include <iomanip>

/*
 * DSA - Queue Data Structure in C++
 *
 * Concepts Covered:
 * 1. std::queue - FIFO (First In First Out)
 * 2. Enqueue (push), Dequeue (pop), Front operations
 * 3. std::deque for flexible queue implementation
 * 4. Priority Queue implementation
 * 5. Circular queue with templates
 * 6. BFS implementation with queue
 */

using namespace std;

// Custom Queue template
template <typename T>
class CustomQueue {
private:
    deque<T> elements;
    
public:
    // Enqueue element at rear
    void enqueue(const T& value) {
        elements.push_back(value);
        cout << "Enqueued " << value << endl;
    }
    
    // Dequeue element from front
    T dequeue() {
        if (isEmpty()) {
            cerr << "Queue Underflow! Cannot dequeue" << endl;
            return T();
        }
        T value = elements.front();
        elements.pop_front();
        return value;
    }
    
    // Peek front element
    T peekFront() const {
        if (isEmpty()) {
            cerr << "Queue is empty!" << endl;
            return T();
        }
        return elements.front();
    }
    
    // Peek rear element
    T peekRear() const {
        if (isEmpty()) {
            cerr << "Queue is empty!" << endl;
            return T();
        }
        return elements.back();
    }
    
    // Check if empty
    bool isEmpty() const {
        return elements.empty();
    }
    
    // Get queue size
    int getSize() const {
        return elements.size();
    }
    
    // Display queue
    void display() const {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue (front to rear): ";
        for (const auto& elem : elements) {
            cout << elem << " ";
        }
        cout << endl;
    }
    
    // Clear queue
    void clear() {
        elements.clear();
        cout << "Queue cleared!" << endl;
    }
};

// Circular Queue with fixed size
template <typename T>
class CircularQueue {
private:
    vector<T> arr;
    int front, rear, size, capacity;
    
public:
    CircularQueue(int cap) : capacity(cap), size(0), front(-1), rear(-1) {
        arr.resize(cap);
    }
    
    bool isEmpty() const {
        return size == 0;
    }
    
    bool isFull() const {
        return size == capacity;
    }
    
    void enqueue(const T& value) {
        if (isFull()) {
            cerr << "Circular Queue Overflow!" << endl;
            return;
        }
        
        if (front == -1) front = 0;
        
        rear = (rear + 1) % capacity;
        arr[rear] = value;
        size++;
        cout << "Enqueued " << value << " (Circular)" << endl;
    }
    
    T dequeue() {
        if (isEmpty()) {
            cerr << "Circular Queue Underflow!" << endl;
            return T();
        }
        
        T value = arr[front];
        
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % capacity;
        }
        
        size--;
        return value;
    }
    
    void display() const {
        if (isEmpty()) {
            cout << "Circular Queue is empty!" << endl;
            return;
        }
        
        cout << "Circular Queue: ";
        int i = front;
        for (int count = 0; count < size; count++) {
            cout << arr[i] << " ";
            i = (i + 1) % capacity;
        }
        cout << endl;
    }
};

// BFS Graph traversal using queue
void graphBFS(int start, const vector<vector<int>>& adj) {
    int n = adj.size();
    vector<bool> visited(n, false);
    queue<int> q;
    
    q.push(start);
    visited[start] = true;
    
    cout << "BFS Traversal starting from node " << start << ": ";
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";
        
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    cout << endl;
}

// Process simulation using queue
void processSimulation(int numCustomers) {
    queue<int> customerQueue;
    
    cout << "\nCustomer Processing Simulation:" << endl;
    cout << "Processing " << numCustomers << " customers..." << endl;
    
    for (int i = 1; i <= numCustomers; i++) {
        customerQueue.push(i);
        cout << "Customer " << i << " arrived, Queue size: " << customerQueue.size() << endl;
    }
    
    cout << "\nProcessing customers:" << endl;
    int count = 1;
    while (!customerQueue.empty()) {
        int customer = customerQueue.front();
        customerQueue.pop();
        cout << "Processing Customer " << customer << ", Remaining: " << customerQueue.size() << endl;
    }
}

int main() {
    cout << "==========================================" << endl;
    cout << "   DSA - Queue Data Structure (C++)" << endl;
    cout << "==========================================" << endl;

    // 1. Using std::queue (STL)
    cout << "\n1. Using std::queue (STL):" << endl;
    queue<int> stdQueue;
    
    stdQueue.push(10);
    stdQueue.push(20);
    stdQueue.push(30);
    stdQueue.push(40);
    stdQueue.push(50);
    
    cout << "Enqueued: 10, 20, 30, 40, 50" << endl;
    cout << "Size: " << stdQueue.size() << endl;
    cout << "Front: " << stdQueue.front() << endl;
    cout << "Rear: " << stdQueue.back() << endl;

    // 2. Dequeue from STL queue
    cout << "\n2. Dequeue Operations (FIFO):" << endl;
    while (!stdQueue.empty()) {
        cout << "Dequeued: " << stdQueue.front() << endl;
        stdQueue.pop();
    }

    // 3. Custom Queue template
    cout << "\n3. Custom Queue Implementation:" << endl;
    CustomQueue<int> myQueue;
    
    myQueue.enqueue(100);
    myQueue.enqueue(200);
    myQueue.enqueue(300);
    myQueue.display();

    // 4. Peek operations
    cout << "\n4. Peek Operations:" << endl;
    cout << "Front: " << myQueue.peekFront() << endl;
    cout << "Rear: " << myQueue.peekRear() << endl;
    cout << "Size: " << myQueue.getSize() << endl;

    // 5. Dequeue operations
    cout << "\n5. Dequeue from Custom Queue:" << endl;
    cout << "Dequeued: " << myQueue.dequeue() << endl;
    cout << "Dequeued: " << myQueue.dequeue() << endl;
    myQueue.display();

    // 6. Circular Queue
    cout << "\n6. Circular Queue:" << endl;
    CircularQueue<int> circQueue(5);
    
    for (int i = 1; i <= 5; i++) {
        circQueue.enqueue(i * 10);
    }
    circQueue.display();

    // 7. Circular Queue - Dequeue and Re-enqueue
    cout << "\n7. Circular Queue - Dequeue and Re-enqueue:" << endl;
    cout << "Dequeued: " << circQueue.dequeue() << endl;
    cout << "Dequeued: " << circQueue.dequeue() << endl;
    circQueue.display();
    
    circQueue.enqueue(60);
    circQueue.enqueue(70);
    circQueue.display();

    // 8. Custom Queue with different types
    cout << "\n8. Custom Queue with Different Types:" << endl;
    CustomQueue<double> doubleQueue;
    
    doubleQueue.enqueue(3.14);
    doubleQueue.enqueue(2.71);
    doubleQueue.enqueue(1.41);
    doubleQueue.display();

    // 9. String Queue
    cout << "\n9. String Queue:" << endl;
    CustomQueue<string> stringQueue;
    
    stringQueue.enqueue("First");
    stringQueue.enqueue("Second");
    stringQueue.enqueue("Third");
    stringQueue.display();
    
    cout << "Dequeued: " << stringQueue.dequeue() << endl;
    stringQueue.display();

    // 10. Priority Queue
    cout << "\n10. Priority Queue (Max-Heap):" << endl;
    priority_queue<int> pq;
    
    pq.push(10);
    pq.push(5);
    pq.push(20);
    pq.push(15);
    pq.push(3);
    
    cout << "Priority Queue (dequeue in priority order): ";
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;

    // 11. Graph BFS using Queue
    cout << "\n11. Graph BFS Traversal:" << endl;
    vector<vector<int>> adj = {
        {1, 2},        // Node 0: connected to 1, 2
        {0, 3},        // Node 1: connected to 0, 3
        {0, 4},        // Node 2: connected to 0, 4
        {1},           // Node 3: connected to 1
        {2, 5},        // Node 4: connected to 2, 5
        {4}            // Node 5: connected to 4
    };
    
    graphBFS(0, adj);

    // 12. Real-world simulation
    cout << "\n12. Real-World Queue Simulation:" << endl;
    processSimulation(3);

    // 13. FIFO Demonstration
    cout << "\n13. FIFO (First In First Out) Behavior:" << endl;
    queue<int> fifoDemo;
    fifoDemo.push(1);
    fifoDemo.push(2);
    fifoDemo.push(3);
    fifoDemo.push(4);
    
    cout << "Pushed: 1, 2, 3, 4" << endl;
    cout << "Popping (should be 1, 2, 3, 4): ";
    while (!fifoDemo.empty()) {
        cout << fifoDemo.front() << " ";
        fifoDemo.pop();
    }
    cout << endl;

    cout << "\n==========================================" << endl;
    cout << "   Queue Applications Summary" << endl;
    cout << "==========================================" << endl;
    cout << "1. Breadth-First Search (BFS) in graphs" << endl;
    cout << "2. Job scheduling" << endl;
    cout << "3. Printer queue management" << endl;
    cout << "4. CPU scheduling (Round Robin)" << endl;
    cout << "5. Data buffering" << endl;
    cout << "6. Asynchronous data transfer" << endl;
    cout << "7. Customer service systems" << endl;

    cout << "\nProgram completed successfully!" << endl;
    return 0;
}
