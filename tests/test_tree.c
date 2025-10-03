 
 
 
 // Test cases checked by - Satyam Jha, Saurav Thakur, Rinklepreet, Shaurya Saxena,Komalpreet



#include <stdio.h>
#include <stdlib.h>
#include "..//src/tree.c"

int main() {
   
    
    // ======================================================
    // Test Binary Tree
    // ======================================================
    BinaryTree* bt = createBinaryTree();
    insertBinaryTree(bt, 0, 10, 1);   // root = 10
    insertBinaryTree(bt, 10, 20, 1);  // 20 left or 10
    insertBinaryTree(bt, 10, 30, 0);  // 30 right of 10
    insertBinaryTree(bt, 20, 40, 1);  // 40 left og 20
    insertBinaryTree(bt, 20, 50, 0);  // 50 right of 20

    printf("Binary Tree Traversals:\n");
    printf("Inorder: "); inorderTraversalBinaryTree(bt); printf("\n");
    printf("Preorder: "); preorderTraversalBinaryTree(bt); printf("\n");
    printf("Postorder: "); postorderTraversalBinaryTree(bt); printf("\n");
    printf("Level-order: "); levelOrderTraversalBinaryTree(bt); printf("\n");

    deleteBinaryTree(bt, 20);
    printf("\nAfter deleting 20 (BT Inorder): ");
    inorderTraversalBinaryTree(bt); printf("\n");

    freeBinaryTree(bt);

    // ======================================================
    // Test Binary Search Tree
    // ======================================================
    BinarySearchTree* bst = createBinarySearchTree();
    insertBinarySearchTree(bst, 50);
    insertBinarySearchTree(bst, 30);
    insertBinarySearchTree(bst, 70);
    insertBinarySearchTree(bst, 20);
    insertBinarySearchTree(bst, 40);
    insertBinarySearchTree(bst, 60);
    insertBinarySearchTree(bst, 80);

    printf("\nBinary Search Tree Traversals:\n");
    printf("Inorder: "); inorderTraversalBinarySearchTree(bst); printf("\n");

    deleteBinarySearchTree(bst, 30);
    printf("After deleting 30 (BST Inorder): ");
    inorderTraversalBinarySearchTree(bst); printf("\n");

    deleteBinarySearchTree(bst, 70);
    printf("After deleting 70 (BST Inorder): ");
    inorderTraversalBinarySearchTree(bst); printf("\n");

    int lca = findLowestCommonAncestor(bst, 20, 40);
    printf("Lowest Common Ancestor of 20 and 40: %d\n", lca);

    freeBinarySearchTree(bst);

    return 0;
}
