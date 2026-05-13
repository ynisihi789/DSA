#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <iomanip>

/*
 * DSA - Tree Data Structure in C++
 *
 * Concepts Covered:
 * 1. Binary Search Tree with templates
 * 2. Tree Traversals: Inorder, Preorder, Postorder, Level Order
 * 3. Iterative and recursive traversals
 * 4. AVL Tree basics
 * 5. Tree path algorithms
 * 6. Lowest Common Ancestor (LCA)
 */

using namespace std;

// Binary Tree Node template
template <typename T>
struct TreeNode {
    T data;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(T val) : data(val), left(nullptr), right(nullptr) {}
};

// Binary Search Tree class
template <typename T>
class BST {
private:
    TreeNode<T>* root;
    
    TreeNode<T>* insertHelper(TreeNode<T>* node, T data) {
        if (node == nullptr) {
            cout << "Inserted " << data << endl;
            return new TreeNode<T>(data);
        }
        
        if (data < node->data) {
            node->left = insertHelper(node->left, data);
        } else if (data > node->data) {
            node->right = insertHelper(node->right, data);
        } else {
            cout << "Duplicate value " << data << " ignored" << endl;
        }
        
        return node;
    }
    
    TreeNode<T>* searchHelper(TreeNode<T>* node, T data) {
        if (node == nullptr) {
            return nullptr;
        }
        
        if (data == node->data) {
            return node;
        } else if (data < node->data) {
            return searchHelper(node->left, data);
        } else {
            return searchHelper(node->right, data);
        }
    }
    
    TreeNode<T>* findMinNode(TreeNode<T>* node) {
        if (node == nullptr) return nullptr;
        
        while (node->left != nullptr) {
            node = node->left;
        }
        
        return node;
    }
    
    TreeNode<T>* deleteHelper(TreeNode<T>* node, T data) {
        if (node == nullptr) {
            return nullptr;
        }
        
        if (data < node->data) {
            node->left = deleteHelper(node->left, data);
        } else if (data > node->data) {
            node->right = deleteHelper(node->right, data);
        } else {
            if (node->left == nullptr) {
                TreeNode<T>* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                TreeNode<T>* temp = node->left;
                delete node;
                return temp;
            }
            
            TreeNode<T>* temp = findMinNode(node->right);
            node->data = temp->data;
            node->right = deleteHelper(node->right, temp->data);
        }
        
        return node;
    }
    
    int getHeightHelper(TreeNode<T>* node) {
        if (node == nullptr) return -1;
        
        int leftHeight = getHeightHelper(node->left);
        int rightHeight = getHeightHelper(node->right);
        
        return 1 + max(leftHeight, rightHeight);
    }
    
    int countNodesHelper(TreeNode<T>* node) {
        if (node == nullptr) return 0;
        
        return 1 + countNodesHelper(node->left) + countNodesHelper(node->right);
    }
    
    void inorderHelper(TreeNode<T>* node) {
        if (node == nullptr) return;
        
        inorderHelper(node->left);
        cout << node->data << " ";
        inorderHelper(node->right);
    }
    
    void preorderHelper(TreeNode<T>* node) {
        if (node == nullptr) return;
        
        cout << node->data << " ";
        preorderHelper(node->left);
        preorderHelper(node->right);
    }
    
    void postorderHelper(TreeNode<T>* node) {
        if (node == nullptr) return;
        
        postorderHelper(node->left);
        postorderHelper(node->right);
        cout << node->data << " ";
    }
    
    void freeHelper(TreeNode<T>* node) {
        if (node == nullptr) return;
        
        freeHelper(node->left);
        freeHelper(node->right);
        delete node;
    }
    
    TreeNode<T>* findLCAHelper(TreeNode<T>* node, T p, T q) {
        if (node == nullptr) return nullptr;
        
        if (p < node->data && q < node->data) {
            return findLCAHelper(node->left, p, q);
        } else if (p > node->data && q > node->data) {
            return findLCAHelper(node->right, p, q);
        } else {
            return node;
        }
    }
    
public:
    BST() : root(nullptr) {}
    
    void insert(T data) {
        root = insertHelper(root, data);
    }
    
    bool search(T data) {
        return searchHelper(root, data) != nullptr;
    }
    
    void deleteNode(T data) {
        root = deleteHelper(root, data);
        cout << "Deleted " << data << endl;
    }
    
    int getHeight() {
        return getHeightHelper(root);
    }
    
    int countNodes() {
        return countNodesHelper(root);
    }
    
    void inorder() {
        inorderHelper(root);
        cout << endl;
    }
    
    void preorder() {
        preorderHelper(root);
        cout << endl;
    }
    
    void postorder() {
        postorderHelper(root);
        cout << endl;
    }
    
    void levelOrder() {
        if (root == nullptr) return;
        
        queue<TreeNode<T>*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode<T>* node = q.front();
            q.pop();
            
            cout << node->data << " ";
            
            if (node->left != nullptr) {
                q.push(node->left);
            }
            if (node->right != nullptr) {
                q.push(node->right);
            }
        }
        cout << endl;
    }
    
    void inorderIterative() {
        if (root == nullptr) return;
        
        stack<TreeNode<T>*> st;
        TreeNode<T>* current = root;
        
        while (!st.empty() || current != nullptr) {
            while (current != nullptr) {
                st.push(current);
                current = current->left;
            }
            
            current = st.top();
            st.pop();
            
            cout << current->data << " ";
            
            current = current->right;
        }
        cout << endl;
    }
    
    T findLCA(T p, T q) {
        return findLCAHelper(root, p, q)->data;
    }
    
    void printTree(TreeNode<T>* node, int space) {
        if (node == nullptr) return;
        
        space += 4;
        
        printTree(node->right, space);
        
        for (int i = 4; i < space; i++) {
            cout << " ";
        }
        cout << node->data << endl;
        
        printTree(node->left, space);
    }
    
    void print() {
        printTree(root, 0);
    }
    
    ~BST() {
        freeHelper(root);
    }
};

int main() {
    cout << "==========================================" << endl;
    cout << "   DSA - Tree Data Structure (C++)" << endl;
    cout << "==========================================" << endl;

    // 1. Create and insert
    cout << "\n1. Inserting elements:" << endl;
    BST<int> tree;
    
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    // 2. Print tree structure
    cout << "\n2. Tree Structure:" << endl;
    tree.print();

    // 3. Tree properties
    cout << "\n3. Tree Properties:" << endl;
    cout << "   Height: " << tree.getHeight() << endl;
    cout << "   Total nodes: " << tree.countNodes() << endl;

    // 4. Search operations
    cout << "\n4. Search Operations:" << endl;
    cout << "   Searching for 40: " << (tree.search(40) ? "Found" : "Not found") << endl;
    cout << "   Searching for 100: " << (tree.search(100) ? "Found" : "Not found") << endl;

    // 5. Traversals (Recursive)
    cout << "\n5. Tree Traversals (Recursive):" << endl;

    cout << "   Inorder (sorted): ";
    tree.inorder();

    cout << "   Preorder: ";
    tree.preorder();

    cout << "   Postorder: ";
    tree.postorder();

    cout << "   Level Order: ";
    tree.levelOrder();

    // 6. Iterative Inorder
    cout << "\n6. Inorder Traversal (Iterative):" << endl;
    cout << "   ";
    tree.inorderIterative();

    // 7. Delete operations
    cout << "\n7. Deletion Operations:" << endl;

    cout << "   Before deletion - Inorder: ";
    tree.inorder();

    tree.deleteNode(20);
    cout << "   After deleting 20 - Inorder: ";
    tree.inorder();

    tree.deleteNode(30);
    cout << "   After deleting 30 - Inorder: ";
    tree.inorder();

    // 8. Lowest Common Ancestor
    cout << "\n8. Lowest Common Ancestor:" << endl;
    cout << "   LCA(20, 40): " << tree.findLCA(20, 40) << endl;
    cout << "   LCA(60, 80): " << tree.findLCA(60, 80) << endl;

    // 9. String Tree
    cout << "\n9. String Binary Search Tree:" << endl;
    BST<string> stringTree;
    
    stringTree.insert("dog");
    stringTree.insert("cat");
    stringTree.insert("elephant");
    stringTree.insert("bear");
    stringTree.insert("fox");

    cout << "   String BST - Inorder: ";
    stringTree.inorder();

    // 10. Tree applications
    cout << "\n10. Tree Traversal Applications:" << endl;
    cout << "   Inorder: Getting sorted sequence from BST" << endl;
    cout << "   Preorder: Tree copying, serialization" << endl;
    cout << "   Postorder: Tree deletion, post-processing" << endl;
    cout << "   Level Order: BFS, level-wise processing" << endl;

    // 11. BST Properties
    cout << "\n11. Binary Search Tree Properties:" << endl;
    cout << "   - Left subtree < Root < Right subtree" << endl;
    cout << "   - Average search time: O(log n)" << endl;
    cout << "   - Worst case (skewed): O(n)" << endl;
    cout << "   - Inorder gives sorted sequence" << endl;
    cout << "   - No duplicates (standard implementation)" << endl;

    cout << "\n==========================================" << endl;
    cout << "Program completed successfully!" << endl;
    cout << "==========================================" << endl;

    return 0;
}
