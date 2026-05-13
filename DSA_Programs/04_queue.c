#include <stdio.h>
#include <stdlib.h>

/*
 * DSA - Queue Data Structure in C
 *
 * Concepts Covered:
 * 1. Queue - FIFO (First In First Out)
 * 2. Enqueue operation - O(1)
 * 3. Dequeue operation - O(1)
 * 4. Circular queue implementation
 * 5. Queue applications: BFS, job scheduling, buffering
 * 6. Queue overflow and underflow handling
 */

#define MAX_SIZE 100

// Simple Queue
typedef struct {
    int arr[MAX_SIZE];
    int front;
    int rear;
} Queue;

// Initialize queue
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

// Check if queue is empty
int isEmpty(Queue* queue) {
    return queue->front == -1;
}

// Check if queue is full
int isFull(Queue* queue) {
    return queue->rear == MAX_SIZE - 1;
}

// Enqueue - Add element at rear
void enqueue(Queue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue Overflow! Cannot enqueue %d\n", value);
        return;
    }
    
    if (queue->front == -1) {
        queue->front = 0;
    }
    
    queue->arr[++queue->rear] = value;
    printf("Enqueued %d\n", value);
}

// Dequeue - Remove element from front
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue Underflow! Cannot dequeue\n");
        return -1;
    }
    
    int value = queue->arr[queue->front];
    
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    } else {
        queue->front++;
    }
    
    return value;
}

// Peek front element
int peekFront(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return -1;
    }
    return queue->arr[queue->front];
}

// Peek rear element
int peekRear(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return -1;
    }
    return queue->arr[queue->rear];
}

// Display queue
void displayQueue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue (front to rear): ");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->arr[i]);
    }
    printf("\n");
}

// Get queue size
int getSize(Queue* queue) {
    if (isEmpty(queue)) return 0;
    return queue->rear - queue->front + 1;
}

// Clear queue
void clearQueue(Queue* queue) {
    queue->front = queue->rear = -1;
    printf("Queue cleared!\n");
}

// Circular Queue
typedef struct {
    int arr[MAX_SIZE];
    int front;
    int rear;
    int size;
} CircularQueue;

// Create circular queue
CircularQueue* createCircularQueue() {
    CircularQueue* queue = (CircularQueue*)malloc(sizeof(CircularQueue));
    queue->front = -1;
    queue->rear = -1;
    queue->size = 0;
    return queue;
}

// Check if circular queue is empty
int isCircularEmpty(CircularQueue* queue) {
    return queue->size == 0;
}

// Check if circular queue is full
int isCircularFull(CircularQueue* queue) {
    return queue->size == MAX_SIZE;
}

// Enqueue in circular queue
void enqueueCircular(CircularQueue* queue, int value) {
    if (isCircularFull(queue)) {
        printf("Circular Queue Overflow! Cannot enqueue %d\n", value);
        return;
    }
    
    if (queue->front == -1) {
        queue->front = 0;
    }
    
    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->arr[queue->rear] = value;
    queue->size++;
    printf("Enqueued %d (Circular)\n", value);
}

// Dequeue from circular queue
int dequeueCircular(CircularQueue* queue) {
    if (isCircularEmpty(queue)) {
        printf("Circular Queue Underflow! Cannot dequeue\n");
        return -1;
    }
    
    int value = queue->arr[queue->front];
    
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % MAX_SIZE;
    }
    
    queue->size--;
    return value;
}

// Display circular queue
void displayCircularQueue(CircularQueue* queue) {
    if (isCircularEmpty(queue)) {
        printf("Circular Queue is empty!\n");
        return;
    }
    
    printf("Circular Queue: ");
    int i = queue->front;
    for (int count = 0; count < queue->size; count++) {
        printf("%d ", queue->arr[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("\n");
}

int main() {
    printf("==========================================\n");
    printf("   DSA - Queue Data Structure (C)\n");
    printf("==========================================\n");

    // 1. Create and test simple queue
    printf("\n1. Simple Queue Operations:\n");
    Queue* queue = createQueue();
    
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50);
    displayQueue(queue);

    // 2. Peek operations
    printf("\n2. Peek Operations:\n");
    printf("Front element: %d\n", peekFront(queue));
    printf("Rear element: %d\n", peekRear(queue));

    // 3. Get size
    printf("\n3. Queue Size: %d\n", getSize(queue));

    // 4. Dequeue operations
    printf("\n4. Dequeue Operations:\n");
    printf("Dequeued: %d\n", dequeue(queue));
    printf("Dequeued: %d\n", dequeue(queue));
    displayQueue(queue);

    // 5. Check empty and full
    printf("\n5. Queue Status:\n");
    printf("Is Empty? %s\n", isEmpty(queue) ? "Yes" : "No");
    printf("Is Full? %s\n", isFull(queue) ? "Yes" : "No");

    // 6. Dequeue all
    printf("\n6. Dequeue All Elements:\n");
    while (!isEmpty(queue)) {
        printf("Dequeued: %d\n", dequeue(queue));
    }
    displayQueue(queue);

    // 7. Clear queue
    printf("\n7. Clear Queue:\n");
    enqueue(queue, 100);
    enqueue(queue, 200);
    displayQueue(queue);
    clearQueue(queue);
    displayQueue(queue);

    // 8. Circular Queue
    printf("\n8. Circular Queue Operations:\n");
    CircularQueue* circQueue = createCircularQueue();
    
    printf("Enqueueing: 1, 2, 3, 4, 5\n");
    enqueueCircular(circQueue, 1);
    enqueueCircular(circQueue, 2);
    enqueueCircular(circQueue, 3);
    enqueueCircular(circQueue, 4);
    enqueueCircular(circQueue, 5);
    displayCircularQueue(circQueue);

    // 9. Dequeue from circular queue
    printf("\n9. Circular Queue Dequeue:\n");
    printf("Dequeued: %d\n", dequeueCircular(circQueue));
    printf("Dequeued: %d\n", dequeueCircular(circQueue));
    displayCircularQueue(circQueue);

    // 10. Re-enqueue in circular (demonstrates wrapping)
    printf("\n10. Circular Queue - Re-enqueue (wrapping):\n");
    enqueueCircular(circQueue, 6);
    enqueueCircular(circQueue, 7);
    displayCircularQueue(circQueue);

    // 11. FIFO demonstration
    printf("\n11. FIFO (First In First Out) Demonstration:\n");
    Queue* fifoQueue = createQueue();
    printf("Enqueuing: A, B, C, D (represented as 1, 2, 3, 4)\n");
    
    for (int i = 1; i <= 4; i++) {
        enqueue(fifoQueue, i);
    }
    displayQueue(fifoQueue);
    
    printf("Dequeuing in FIFO order:\n");
    while (!isEmpty(fifoQueue)) {
        printf("Dequeued: %d\n", dequeue(fifoQueue));
    }

    // 12. Queue space management
    printf("\n12. Queue Space Management (Limitation of Simple Queue):\n");
    Queue* limitedQueue = createQueue();
    
    // Fill and partially empty
    for (int i = 1; i <= 5; i++) {
        enqueue(limitedQueue, i * 10);
    }
    displayQueue(limitedQueue);
    
    printf("After dequeuing 2 elements:\n");
    dequeue(limitedQueue);
    dequeue(limitedQueue);
    displayQueue(limitedQueue);
    
    printf("Attempting to enqueue when rear is full (even though front has space):\n");
    printf("Front index: %d, Rear index: %d\n", limitedQueue->front, limitedQueue->rear);
    printf("This is why Circular Queue is better!\n");

    printf("\n=========================================\n");
    printf("   Queue Applications Summary\n");
    printf("=========================================\n");
    printf("1. Breadth-First Search (BFS)\n");
    printf("2. Job scheduling\n");
    printf("3. Print queue management\n");
    printf("4. Data buffering\n");
    printf("5. Asynchronous data transfer\n");
    printf("6. Traffic simulation\n");

    free(queue);
    free(circQueue);
    free(fifoQueue);
    free(limitedQueue);

    printf("\nProgram completed successfully!\n");
    return 0;
}
