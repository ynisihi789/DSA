#include <iostream>
#include <vector>
#include <iomanip>
#include <memory>

/*
 * DSA - Linked List Data Structure in C++
 *
 * Concepts Covered:
 * 1. Singly Linked List with templates
 * 2. Doubly Linked List
 * 3. Node creation with smart pointers
 * 4. Insertion: at beginning, at end, at position
 * 5. Deletion: from beginning, from end, from position
 * 6. Searching, sorting, reversing
 * 7. Cycle detection
 * 8. Advanced operations: merge, partition
 */

using namespace std;

// Singly Linked List Node template
template <typename T>
struct SinglyNode {
    T data;
    SinglyNode* next;
    
    SinglyNode(T val) : data(val), next(nullptr) {}
};

// Doubly Linked List Node template
template <typename T>
struct DoublyNode {
    T data;
    DoublyNode* next;
    DoublyNode* prev;
    
    DoublyNode(T val) : data(val), next(nullptr), prev(nullptr) {}
};

// Singly Linked List class
template <typename T>
class SinglyLinkedList {
private:
    SinglyNode<T>* head;
    
public:
    SinglyLinkedList() : head(nullptr) {}
    
    // Insert at beginning
    void insertAtBeginning(T data) {
        SinglyNode<T>* newNode = new SinglyNode<T>(data);
        newNode->next = head;
        head = newNode;
        cout << "Inserted " << data << " at beginning" << endl;
    }
    
    // Insert at end
    void insertAtEnd(T data) {
        SinglyNode<T>* newNode = new SinglyNode<T>(data);
        
        if (head == nullptr) {
            head = newNode;
            cout << "Inserted " << data << " at end" << endl;
            return;
        }
        
        SinglyNode<T>* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        
        temp->next = newNode;
        cout << "Inserted " << data << " at end" << endl;
    }
    
    // Insert at position
    void insertAtPosition(T data, int position) {
        if (position == 1) {
            insertAtBeginning(data);
            return;
        }
        
        SinglyNode<T>* temp = head;
        for (int i = 1; i < position - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }
        
        if (temp == nullptr) {
            cout << "Position out of range!" << endl;
            return;
        }
        
        SinglyNode<T>* newNode = new SinglyNode<T>(data);
        newNode->next = temp->next;
        temp->next = newNode;
        cout << "Inserted " << data << " at position " << position << endl;
    }
    
    // Delete from beginning
    void deleteFromBeginning() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        
        SinglyNode<T>* temp = head;
        cout << "Deleted " << head->data << " from beginning" << endl;
        head = head->next;
        delete temp;
    }
    
    // Delete from end
    void deleteFromEnd() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        
        if (head->next == nullptr) {
            cout << "Deleted " << head->data << " from end" << endl;
            delete head;
            head = nullptr;
            return;
        }
        
        SinglyNode<T>* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        
        cout << "Deleted " << temp->next->data << " from end" << endl;
        delete temp->next;
        temp->next = nullptr;
    }
    
    // Delete at position
    void deleteAtPosition(int position) {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        
        if (position == 1) {
            deleteFromBeginning();
            return;
        }
        
        SinglyNode<T>* temp = head;
        for (int i = 1; i < position - 1 && temp->next != nullptr; i++) {
            temp = temp->next;
        }
        
        if (temp->next == nullptr) {
            cout << "Position out of range!" << endl;
            return;
        }
        
        SinglyNode<T>* nodeToDelete = temp->next;
        cout << "Deleted " << nodeToDelete->data << " from position " << position << endl;
        temp->next = nodeToDelete->next;
        delete nodeToDelete;
    }
    
    // Search for element
    int search(T value) {
        int position = 1;
        SinglyNode<T>* temp = head;
        
        while (temp != nullptr) {
            if (temp->data == value) {
                return position;
            }
            temp = temp->next;
            position++;
        }
        
        return -1;
    }
    
    // Reverse list
    void reverse() {
        SinglyNode<T>* prev = nullptr;
        SinglyNode<T>* current = head;
        SinglyNode<T>* next = nullptr;
        
        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        
        head = prev;
        cout << "List reversed!" << endl;
    }
    
    // Get length
    int getLength() {
        int count = 0;
        SinglyNode<T>* temp = head;
        
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        
        return count;
    }
    
    // Find middle
    T findMiddle() {
        SinglyNode<T>* slow = head;
        SinglyNode<T>* fast = head;
        
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow->data;
    }
    
    // Display list
    void display() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        
        cout << "Linked List: ";
        SinglyNode<T>* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
    
    // Cycle detection (Floyd's algorithm)
    bool hasCycle() {
        if (head == nullptr) return false;
        
        SinglyNode<T>* slow = head;
        SinglyNode<T>* fast = head;
        
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            
            if (slow == fast) {
                return true;
            }
        }
        
        return false;
    }
    
    // Remove duplicates
    void removeDuplicates() {
        SinglyNode<T>* temp = head;
        
        while (temp != nullptr && temp->next != nullptr) {
            if (temp->data == temp->next->data) {
                SinglyNode<T>* duplicate = temp->next;
                temp->next = temp->next->next;
                delete duplicate;
            } else {
                temp = temp->next;
            }
        }
        
        cout << "Duplicates removed!" << endl;
    }
    
    // Clear list
    ~SinglyLinkedList() {
        SinglyNode<T>* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// Doubly Linked List class
template <typename T>
class DoublyLinkedList {
private:
    DoublyNode<T>* head;
    
public:
    DoublyLinkedList() : head(nullptr) {}
    
    // Insert at end
    void insertAtEnd(T data) {
        DoublyNode<T>* newNode = new DoublyNode<T>(data);
        
        if (head == nullptr) {
            head = newNode;
            return;
        }
        
        DoublyNode<T>* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        
        temp->next = newNode;
        newNode->prev = temp;
    }
    
    // Display forward
    void displayForward() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        
        cout << "Forward: NULL <- ";
        DoublyNode<T>* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
    
    // Display backward
    void displayBackward() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        
        // Find last node
        DoublyNode<T>* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        
        cout << "Backward: NULL <- ";
        while (temp != nullptr) {
            cout << temp->data << " <-> ";
            temp = temp->prev;
        }
        cout << "NULL" << endl;
    }
    
    ~DoublyLinkedList() {
        DoublyNode<T>* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    cout << "==========================================" << endl;
    cout << "   DSA - Linked List (C++)" << endl;
    cout << "==========================================" << endl;

    // 1. Singly Linked List - Basic operations
    cout << "\n1. Singly Linked List - Basic Operations:" << endl;
    SinglyLinkedList<int> list;
    
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);
    list.insertAtEnd(50);
    list.display();

    // 2. Insert at beginning
    cout << "\n2. Insert at Beginning:" << endl;
    list.insertAtBeginning(5);
    list.insertAtBeginning(1);
    list.display();

    // 3. Insert at position
    cout << "\n3. Insert at Position:" << endl;
    list.insertAtPosition(15, 3);
    list.display();

    // 4. Length and middle
    cout << "\n4. List Properties:" << endl;
    cout << "Length: " << list.getLength() << endl;
    cout << "Middle element: " << list.findMiddle() << endl;

    // 5. Search
    cout << "\n5. Search Operations:" << endl;
    int pos = list.search(30);
    cout << "Element 30 at position: " << (pos != -1 ? to_string(pos) : "Not found") << endl;
    
    pos = list.search(100);
    cout << "Element 100 at position: " << (pos != -1 ? to_string(pos) : "Not found") << endl;

    // 6. Delete operations
    cout << "\n6. Delete Operations:" << endl;
    list.deleteFromBeginning();
    list.display();
    
    list.deleteFromEnd();
    list.display();
    
    list.deleteAtPosition(3);
    list.display();

    // 7. Reverse
    cout << "\n7. Reverse List:" << endl;
    list.reverse();
    list.display();

    // 8. Reverse again
    cout << "\n8. Reverse Again:" << endl;
    list.reverse();
    list.display();

    // 9. Cycle detection
    cout << "\n9. Cycle Detection:" << endl;
    cout << "Has cycle: " << (list.hasCycle() ? "Yes" : "No") << endl;

    // 10. Doubly Linked List
    cout << "\n10. Doubly Linked List:" << endl;
    DoublyLinkedList<int> doublyList;
    
    doublyList.insertAtEnd(10);
    doublyList.insertAtEnd(20);
    doublyList.insertAtEnd(30);
    doublyList.insertAtEnd(40);
    
    doublyList.displayForward();
    doublyList.displayBackward();

    // 11. Remove duplicates
    cout << "\n11. Remove Duplicates:" << endl;
    SinglyLinkedList<int> dupList;
    dupList.insertAtEnd(1);
    dupList.insertAtEnd(1);
    dupList.insertAtEnd(2);
    dupList.insertAtEnd(2);
    dupList.insertAtEnd(3);
    dupList.insertAtEnd(3);
    
    cout << "Before: ";
    dupList.display();
    
    dupList.removeDuplicates();
    cout << "After: ";
    dupList.display();

    // 12. String list example
    cout << "\n12. Linked List with Strings:" << endl;
    SinglyLinkedList<string> stringList;
    
    stringList.insertAtEnd("Alice");
    stringList.insertAtEnd("Bob");
    stringList.insertAtEnd("Charlie");
    stringList.insertAtEnd("David");
    stringList.display();

    // 13. Advanced properties
    cout << "\n13. Linked List Characteristics:" << endl;
    cout << "- Dynamic memory allocation" << endl;
    cout << "- O(1) insertion/deletion at known position" << endl;
    cout << "- O(n) search and access" << endl;
    cout << "- No random access" << endl;
    cout << "- Flexible size (no overflow)" << endl;

    cout << "\n==========================================" << endl;
    cout << "   Linked List Applications" << endl;
    cout << "==========================================" << endl;
    cout << "1. Dynamic memory allocation" << endl;
    cout << "2. Implementation of Stack and Queue" << endl;
    cout << "3. Graph adjacency lists" << endl;
    cout << "4. Polynomial representation" << endl;
    cout << "5. Sparse matrices" << endl;
    cout << "6. Undo/Redo functionality" << endl;

    cout << "\nProgram completed successfully!" << endl;
    return 0;
}
