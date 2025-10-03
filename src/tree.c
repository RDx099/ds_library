//
// Created by rahul on 06-09-2025.
//
//
// tree.c
// Implementation of Binary Tree and Binary Search Tree functions
//

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "queue.h"
#include "tree.h"

// -----------------------------------------------------
// Definition of TreeNode structure
// -----------------------------------------------------
struct TreeNode {
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
};

// -----------------------------------------------------
// Definition of BinaryTree structure
// -----------------------------------------------------
struct BinaryTree {
    TreeNode* root;
};

// -----------------------------------------------------
// Definition of BinarySearchTree structure
// -----------------------------------------------------
struct BinarySearchTree {
    TreeNode* root;
};

// -----------------------------------------------------
// Utility function to create a new node
// -----------------------------------------------------
static TreeNode* createNode(int value) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    if (!node) return NULL;
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// ======================================================================
// ======================== Binary Tree Functions =======================
// ======================================================================

// Function to create an empty Binary Tree
BinaryTree* createBinaryTree() {
    BinaryTree* bt = (BinaryTree*)malloc(sizeof(BinaryTree));
    if (!bt) return NULL;
    bt->root = NULL;
    return bt;
}

// Function to insert a node in the Binary Tree
void insertBinaryTree(BinaryTree* bt, int parentValue, int value, int isLeft) {
    if (!bt) return;

    // If tree is empty, new node becomes root
    if (!bt->root) {
        bt->root = createNode(value);
        return;
    }

    Queue* q = createQueue();
    enqueue(q, bt->root);

    while (!isQueueEmpty(q)) {
        TreeNode* current = dequeue(q);

        if (current->value == parentValue) {
            if (isLeft && !current->left) {
                current->left = createNode(value);
            } else if (!isLeft && !current->right) {
                current->right = createNode(value);
            }
            break;
        }

        if (current->left) enqueue(q, current->left);
        if (current->right) enqueue(q, current->right);
    }

    freeQueue(q);
}

// Function to delete a node from Binary Tree (basic version)
void deleteBinaryTree(BinaryTree* bt, int value) {
    if (!bt || !bt->root) return;

    // Special case: root delete
    if (bt->root->value == value && !bt->root->left && !bt->root->right) {
        free(bt->root);
        bt->root = NULL;
        return;
    }

    Queue* q = createQueue();
    enqueue(q, bt->root);

    TreeNode* target = NULL;
    TreeNode* last = NULL;
    TreeNode* parent = NULL;

    while (!isQueueEmpty(q)) {
        TreeNode* current = dequeue(q);

        if (current->value == value) {
            target = current;
        }
        if (current->left) {
            parent = current;
            enqueue(q, current->left);
        }
        if (current->right) {
            parent = current;
            enqueue(q, current->right);
        }
        last = current;
    }

    if (target && last) {
        target->value = last->value;

        if (parent->left == last) {
            free(parent->left);
            parent->left = NULL;
        } else if (parent->right == last) {
            free(parent->right);
            parent->right = NULL;
        }
    }

    freeQueue(q);
}

// Function to perform inorder traversal of Binary Tree
void inorderTraversalBinaryTree(BinaryTree* bt) {
    void inorder(TreeNode* node) {
        if (!node) return;
        inorder(node->left);
        printf("%d ", node->value);
        inorder(node->right);
    }
    if (bt) inorder(bt->root);
}

// Function to perform preorder traversal of Binary Tree
void preorderTraversalBinaryTree(BinaryTree* bt) {
    void preorder(TreeNode* node) {
        if (!node) return;
        printf("%d ", node->value);
        preorder(node->left);
        preorder(node->right);
    }
    if (bt) preorder(bt->root);
}

// Function to perform postorder traversal of Binary Tree
void postorderTraversalBinaryTree(BinaryTree* bt) {
    void postorder(TreeNode* node) {
        if (!node) return;
        postorder(node->left);
        postorder(node->right);
        printf("%d ", node->value);
    }
    if (bt) postorder(bt->root);
}

// Function to perform level order traversal of Binary Tree
void levelOrderTraversalBinaryTree(BinaryTree* bt) {
    if (!bt || !bt->root) return;

    Queue* q = createQueue();
    enqueue(q, bt->root);

    while (!isQueueEmpty(q)) {
        TreeNode* current = dequeue(q);
        printf("%d ", current->value);

        if (current->left) enqueue(q, current->left);
        if (current->right) enqueue(q, current->right);
    }

    freeQueue(q);
}

// Function to free the Binary Tree
void freeBinaryTree(BinaryTree* bt) {
    void freeNodes(TreeNode* node) {
        if (!node) return;
        freeNodes(node->left);
        freeNodes(node->right);
        free(node);
    }
    if (!bt) return;
    freeNodes(bt->root);
    free(bt);
}

// ======================================================================
// ==================== Binary Search Tree Functions ====================
// ======================================================================

// Function to create an empty Binary Search Tree
BinarySearchTree* createBinarySearchTree() {
    BinarySearchTree* bst = (BinarySearchTree*)malloc(sizeof(BinarySearchTree));
    if (!bst) return NULL;
    bst->root = NULL;
    return bst;
}

// Function to insert a node in the Binary Search Tree
static TreeNode* insertBST(TreeNode* root, int value) {
    if (!root) return createNode(value);
    if (value < root->value) {
        root->left = insertBST(root->left, value);
    } else if (value > root->value) {
        root->right = insertBST(root->right, value);
    }
    return root;
}
void insertBinarySearchTree(BinarySearchTree* bst, int value) {
    if (!bst) return;
    bst->root = insertBST(bst->root, value);
}

// Function to delete a node from Binary Search Tree
static TreeNode* deleteBSTNode(TreeNode* root, int value) {
    if (!root) return NULL;

    if (value < root->value) {
        root->left = deleteBSTNode(root->left, value);
    } else if (value > root->value) {
        root->right = deleteBSTNode(root->right, value);
    } else {
        // Node found
        if (!root->left) {
            TreeNode* temp = root->right;
            free(root);
            return temp;
        } else if (!root->right) {
            TreeNode* temp = root->left;
            free(root);
            return temp;
        }
        // Two children: inorder successor
        TreeNode* succ = root->right;
        while (succ->left) succ = succ->left;
        root->value = succ->value;
        root->right = deleteBSTNode(root->right, succ->value);
    }
    return root;
}
void deleteBinarySearchTree(BinarySearchTree* bst, int value) {
    if (!bst) return;
    bst->root = deleteBSTNode(bst->root, value);
}

// Function to perform inorder traversal of Binary Search Tree
void inorderTraversalBinarySearchTree(BinarySearchTree* bst) {
    void inorder(TreeNode* node) {
        if (!node) return;
        inorder(node->left);
        printf("%d ", node->value);
        inorder(node->right);
    }
    if (bst) inorder(bst->root);
}

// Function to find Lowest Common Ancestor in BST
int findLowestCommonAncestor(BinarySearchTree* bst, int value1, int value2) {
    if (!bst || !bst->root) return INT_MIN;

    TreeNode* current = bst->root;
    while (current) {
        if (value1 < current->value && value2 < current->value) {
            current = current->left;
        } else if (value1 > current->value && value2 > current->value) {
            current = current->right;
        } else {
            return current->value;
        }
    }
    return INT_MIN;
}

// Function to free the Binary Search Tree
void freeBinarySearchTree(BinarySearchTree* bst) {
    void freeNodes(TreeNode* node){
        if (!node) return;
        freeNodes(node->left);
        freeNodes(node->right);
        free(node);
    }
    if (!bst) return;
    freeNodes(bst->root);
    free(bst);
}  
