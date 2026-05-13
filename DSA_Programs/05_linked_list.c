#include <stdio.h>
#include <stdlib.h>

/*
 * DSA - Linked List Data Structure in C
 *
 * Concepts Covered:
 * 1. Singly Linked List
 * 2. Node creation and memory management
 * 3. Insertion operations: at beginning, at end, at position
 * 4. Deletion operations: from beginning, from end, from position
 * 5. Searching and traversal - O(n)
 * 6. List reversal
 * 7. Detecting cycles
 */

typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Create a new node
Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Insert at the beginning
Node* insertAtBeginning(Node* head, int data) {
    Node* newNode = createNode(data);
    newNode->next = head;
    printf("Inserted %d at the beginning\n", data);
    return newNode;
}

// Insert at the end
Node* insertAtEnd(Node* head, int data) {
    Node* newNode = createNode(data);
    
    if (head == NULL) {
        printf("Inserted %d at the end\n", data);
        return newNode;
    }
    
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    temp->next = newNode;
    printf("Inserted %d at the end\n", data);
    return head;
}

// Insert at a specific position (1-indexed)
Node* insertAtPosition(Node* head, int data, int position) {
    if (position == 1) {
        return insertAtBeginning(head, data);
    }
    
    Node* temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    
    if (temp == NULL) {
        printf("Position out of range!\n");
        return head;
    }
    
    Node* newNode = createNode(data);
    newNode->next = temp->next;
    temp->next = newNode;
    printf("Inserted %d at position %d\n", data, position);
    return head;
}

// Delete from beginning
Node* deleteFromBeginning(Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return NULL;
    }
    
    Node* temp = head;
    printf("Deleted %d from the beginning\n", head->data);
    head = head->next;
    free(temp);
    return head;
}

// Delete from end
Node* deleteFromEnd(Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return NULL;
    }
    
    if (head->next == NULL) {
        printf("Deleted %d from the end\n", head->data);
        free(head);
        return NULL;
    }
    
    Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    
    printf("Deleted %d from the end\n", temp->next->data);
    free(temp->next);
    temp->next = NULL;
    return head;
}

// Delete at a specific position
Node* deleteAtPosition(Node* head, int position) {
    if (head == NULL) {
        printf("List is empty!\n");
        return NULL;
    }
    
    if (position == 1) {
        return deleteFromBeginning(head);
    }
    
    Node* temp = head;
    for (int i = 1; i < position - 1 && temp->next != NULL; i++) {
        temp = temp->next;
    }
    
    if (temp->next == NULL) {
        printf("Position out of range!\n");
        return head;
    }
    
    Node* nodeToDelete = temp->next;
    printf("Deleted %d from position %d\n", nodeToDelete->data, position);
    temp->next = nodeToDelete->next;
    free(nodeToDelete);
    return head;
}

// Display the linked list
void displayList(Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    
    printf("Linked List: ");
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Get list length
int getLength(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Search for an element
int search(Node* head, int value) {
    int position = 1;
    Node* temp = head;
    
    while (temp != NULL) {
        if (temp->data == value) {
            return position;
        }
        temp = temp->next;
        position++;
    }
    
    return -1;
}

// Reverse the linked list
Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;
    
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    printf("List reversed!\n");
    return prev;
}

// Check if list has a cycle (Floyd's cycle detection)
int hasCycle(Node* head) {
    if (head == NULL) return 0;
    
    Node* slow = head;
    Node* fast = head;
    
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        
        if (slow == fast) {
            return 1;  // Cycle detected
        }
    }
    
    return 0;  // No cycle
}

// Find the middle of the list
Node* findMiddle(Node* head) {
    if (head == NULL) return NULL;
    
    Node* slow = head;
    Node* fast = head;
    
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow;
}

// Merge two sorted lists
Node* mergeSorted(Node* head1, Node* head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;
    
    Node* mergedHead;
    
    if (head1->data <= head2->data) {
        mergedHead = head1;
        mergedHead->next = mergeSorted(head1->next, head2);
    } else {
        mergedHead = head2;
        mergedHead->next = mergeSorted(head1, head2->next);
    }
    
    return mergedHead;
}

// Clear the entire list
void clearList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
    printf("List cleared!\n");
}

int main() {
    printf("==========================================\n");
    printf("   DSA - Linked List (C)\n");
    printf("==========================================\n");

    Node* head = NULL;

    // 1. Insert at end
    printf("\n1. Insert Operations (at end):\n");
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);
    head = insertAtEnd(head, 40);
    head = insertAtEnd(head, 50);
    displayList(head);

    // 2. Get length
    printf("\n2. List Length: %d\n", getLength(head));

    // 3. Insert at beginning
    printf("\n3. Insert at Beginning:\n");
    head = insertAtBeginning(head, 5);
    head = insertAtBeginning(head, 1);
    displayList(head);

    // 4. Insert at specific position
    printf("\n4. Insert at Specific Position:\n");
    head = insertAtPosition(head, 15, 3);
    displayList(head);

    // 5. Search
    printf("\n5. Search Operations:\n");
    int pos = search(head, 30);
    if (pos != -1) {
        printf("Element 30 found at position %d\n", pos);
    } else {
        printf("Element 30 not found\n");
    }
    
    pos = search(head, 100);
    if (pos != -1) {
        printf("Element 100 found at position %d\n", pos);
    } else {
        printf("Element 100 not found\n");
    }

    // 6. Find middle
    printf("\n6. Find Middle Element:\n");
    Node* middle = findMiddle(head);
    printf("Middle element: %d\n", middle->data);

    // 7. Delete from beginning
    printf("\n7. Delete from Beginning:\n");
    head = deleteFromBeginning(head);
    displayList(head);

    // 8. Delete from end
    printf("\n8. Delete from End:\n");
    head = deleteFromEnd(head);
    displayList(head);

    // 9. Delete from position
    printf("\n9. Delete from Position:\n");
    head = deleteAtPosition(head, 3);
    displayList(head);

    // 10. Reverse list
    printf("\n10. Reverse Linked List:\n");
    head = reverseList(head);
    displayList(head);

    // 11. Reverse again to restore
    printf("\n11. Reverse Again:\n");
    head = reverseList(head);
    displayList(head);

    // 12. Merge two sorted lists
    printf("\n12. Merge Two Sorted Lists:\n");
    Node* head1 = NULL;
    head1 = insertAtEnd(head1, 1);
    head1 = insertAtEnd(head1, 3);
    head1 = insertAtEnd(head1, 5);
    
    Node* head2 = NULL;
    head2 = insertAtEnd(head2, 2);
    head2 = insertAtEnd(head2, 4);
    head2 = insertAtEnd(head2, 6);
    
    printf("List 1: ");
    displayList(head1);
    printf("List 2: ");
    displayList(head2);
    
    Node* merged = mergeSorted(head1, head2);
    printf("Merged: ");
    displayList(merged);

    // 13. Cycle detection
    printf("\n13. Cycle Detection (Floyd's Algorithm):\n");
    printf("Current list has cycle: %s\n", hasCycle(head) ? "Yes" : "No");

    // 14. List operations summary
    printf("\n14. Linked List Summary:\n");
    printf("Final list: ");
    displayList(head);
    printf("Final length: %d\n", getLength(head));

    // 15. Clear list
    printf("\n15. Clear List:\n");
    clearList(head);
    displayList(head);

    printf("\n==========================================\n");
    printf("Program completed successfully!\n");
    printf("==========================================\n");

    return 0;
}
