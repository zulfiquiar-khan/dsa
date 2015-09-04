#include"LinkedBinaryTree.h"

void testCreateBinaryTree(){
    	node* binaryTree=createBinaryTree(7);
}

void testPreOrderTraversalRecursive(){
    node* root=createBinaryTree(7);
    printf("PreOrder : ");
    preOrderTraversalRecursive(root);
    printf("\n");
}

void testPreOrderTraversalIterative(){
    node* root=createBinaryTree(7);
    printf("PreOrder : ");
    preOrderTraversalIterative(root);
    printf("\n");
}


void testInOrderTraversalRecursive(){
    node* root=createBinaryTree(7);
    printf("InOrder : ");
   inOrderTraversalRecursive(root);
    printf("\n");
}


void testInOrderTraversalIterative(){
    node* root=createBinaryTree(7);
    printf("InOrder : ");
    inOrderTraversalIterative(root);
    printf("\n");
}