#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * DSA - Tree Data Structure in C
 *
 * Concepts Covered:
 * 1. Binary Tree fundamentals
 * 2. Binary Search Tree (BST)
 * 3. Tree Traversals: Inorder, Preorder, Postorder, Level Order
 * 4. BST operations: Insert, Delete, Search - O(log n) average
 * 5. Tree properties and height calculation
 * 6. Finding min/max elements
 */

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Create a new node
TreeNode* createNode(int data) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Insert in BST
TreeNode* insert(TreeNode* root, int data) {
    if (root == NULL) {
        printf("Inserted %d\n", data);
        return createNode(data);
    }
    
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    } else {
        printf("Duplicate value %d ignored\n", data);
    }
    
    return root;
}

// Search in BST
TreeNode* search(TreeNode* root, int data) {
    if (root == NULL) {
        return NULL;
    }
    
    if (data == root->data) {
        return root;
    } else if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

// Find minimum value (leftmost node)
TreeNode* findMin(TreeNode* root) {
    if (root == NULL) return NULL;
    
    while (root->left != NULL) {
        root = root->left;
    }
    
    return root;
}

// Find maximum value (rightmost node)
TreeNode* findMax(TreeNode* root) {
    if (root == NULL) return NULL;
    
    while (root->right != NULL) {
        root = root->right;
    }
    
    return root;
}

// Delete a node from BST
TreeNode* deleteNode(TreeNode* root, int data) {
    if (root == NULL) {
        return NULL;
    }
    
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        // Node with only one child or no child
        if (root->left == NULL) {
            TreeNode* temp = root->right;
            free(root);
            printf("Deleted %d (no left child)\n", data);
            return temp;
        } else if (root->right == NULL) {
            TreeNode* temp = root->left;
            free(root);
            printf("Deleted %d (no right child)\n", data);
            return temp;
        }
        
        // Node with two children: get inorder successor (smallest in right subtree)
        TreeNode* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
        printf("Deleted %d (had two children)\n", data);
    }
    
    return root;
}

// Inorder Traversal (Left, Root, Right) - gives sorted order for BST
void inorderTraversal(TreeNode* root) {
    if (root == NULL) return;
    
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

// Preorder Traversal (Root, Left, Right)
void preorderTraversal(TreeNode* root) {
    if (root == NULL) return;
    
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Postorder Traversal (Left, Right, Root)
void postorderTraversal(TreeNode* root) {
    if (root == NULL) return;
    
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}

// Level Order Traversal (Breadth-First)
void levelOrderTraversal(TreeNode* root) {
    if (root == NULL) return;
    
    // Simple queue using array (for demo)
    TreeNode** queue = (TreeNode**)malloc(1000 * sizeof(TreeNode*));
    int front = 0, rear = 0;
    
    queue[rear++] = root;
    
    while (front < rear) {
        TreeNode* node = queue[front++];
        printf("%d ", node->data);
        
        if (node->left != NULL) {
            queue[rear++] = node->left;
        }
        if (node->right != NULL) {
            queue[rear++] = node->right;
        }
    }
    
    free(queue);
}

// Calculate height of tree
int getHeight(TreeNode* root) {
    if (root == NULL) return -1;
    
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Count total nodes
int countNodes(TreeNode* root) {
    if (root == NULL) return 0;
    
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Check if tree is balanced
int isBalanced(TreeNode* root) {
    if (root == NULL) return 1;
    
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    
    if (abs(leftHeight - rightHeight) > 1) {
        return 0;
    }
    
    return isBalanced(root->left) && isBalanced(root->right);
}

// Check if tree is BST
int isBST(TreeNode* root, int minVal, int maxVal) {
    if (root == NULL) return 1;
    
    if (root->data <= minVal || root->data >= maxVal) {
        return 0;
    }
    
    return isBST(root->left, minVal, root->data) &&
           isBST(root->right, root->data, maxVal);
}

// Print tree structure
void printTree(TreeNode* root, int space) {
    if (root == NULL) return;
    
    space += 4;
    
    printTree(root->right, space);
    
    for (int i = 4; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", root->data);
    
    printTree(root->left, space);
}

// Free tree memory
void freeTree(TreeNode* root) {
    if (root == NULL) return;
    
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    printf("==========================================\n");
    printf("   DSA - Tree Data Structure (C)\n");
    printf("==========================================\n");

    TreeNode* root = NULL;

    // 1. Insert elements
    printf("\n1. Inserting elements:\n");
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    // 2. Print tree structure
    printf("\n2. Tree Structure:\n");
    printTree(root, 0);

    // 3. Tree properties
    printf("\n3. Tree Properties:\n");
    printf("   Height: %d\n", getHeight(root));
    printf("   Total nodes: %d\n", countNodes(root));
    printf("   Is Balanced: %s\n", isBalanced(root) ? "Yes" : "No");
    printf("   Is BST: %s\n", isBST(root, -1, 1000) ? "Yes" : "No");

    // 4. Find min and max
    printf("\n4. Min and Max Elements:\n");
    printf("   Minimum: %d\n", findMin(root)->data);
    printf("   Maximum: %d\n", findMax(root)->data);

    // 5. Search operations
    printf("\n5. Search Operations:\n");
    TreeNode* found = search(root, 40);
    printf("   Searching for 40: %s\n", found != NULL ? "Found" : "Not found");

    found = search(root, 100);
    printf("   Searching for 100: %s\n", found != NULL ? "Found" : "Not found");

    // 6. Traversals
    printf("\n6. Tree Traversals:\n");

    printf("   Inorder (sorted): ");
    inorderTraversal(root);
    printf("\n");

    printf("   Preorder: ");
    preorderTraversal(root);
    printf("\n");

    printf("   Postorder: ");
    postorderTraversal(root);
    printf("\n");

    printf("   Level Order: ");
    levelOrderTraversal(root);
    printf("\n");

    // 7. Delete leaf node
    printf("\n7. Delete Leaf Node (20):\n");
    root = deleteNode(root, 20);
    printf("   Inorder after deletion: ");
    inorderTraversal(root);
    printf("\n");

    // 8. Delete node with one child
    printf("\n8. Delete Node with One Child:\n");
    printf("   After deleting 30: ");
    root = deleteNode(root, 30);
    inorderTraversal(root);
    printf("\n");

    // 9. Delete node with two children
    printf("\n9. Delete Node with Two Children (50 - root):\n");
    printf("   After deleting 50: ");
    root = deleteNode(root, 50);
    inorderTraversal(root);
    printf("\n");

    // 10. Final tree status
    printf("\n10. Final Tree Status:\n");
    printf("   Height: %d\n", getHeight(root));
    printf("   Total nodes: %d\n", countNodes(root));
    printf("   Inorder: ");
    inorderTraversal(root);
    printf("\n");

    // 11. Tree traversal applications
    printf("\n11. Traversal Applications:\n");
    printf("   Inorder: Used to get sorted sequence from BST\n");
    printf("   Preorder: Used for tree copying, expression tree evaluation\n");
    printf("   Postorder: Used for tree deletion, post-processing\n");
    printf("   Level Order: Used for level-by-level processing, BFS\n");

    freeTree(root);

    printf("\n==========================================\n");
    printf("Program completed successfully!\n");
    printf("==========================================\n");

    return 0;
}
