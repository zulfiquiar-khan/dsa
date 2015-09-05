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

void testPostOrderTraversalRecursive(){
    node* root=createBinaryTree(7);
    printf("PostOrder : ");
    postOrderTraversalRecursive(root);
    printf("\n");
}

void testPostOrderTraversalIterative(){
    node* root=createBinaryTree(7);
    printf("PostOrder : ");
    postOrderTraversalIterative(root);
    printf("\n");
}

void testLevelOrderTraversalIteartive(){
    node* root=createBinaryTree(7);
    printf("Level Order : ");
    levelOrderTraversalIteartive(root);
    printf("\n");
}

void testFindMaxInBinaryTree(){
    node* root=createBinaryTree(7);
    printf("Max : %d\n",findMaxInBinaryTree(root));
}

void testFindMaxInBinaryTreeIterative(){
    node* root=createBinaryTree(7);
    printf("Max : %d\n",findMaxInBinaryTreeIterative(root));
}

void testSearchInBinaryTreeRecursive(){
    node* root=createBinaryTree(7);
    int data=7;
    node* found=NULL;
    printf("Trying to find %d\n",data);
    found=searchInBinaryTreeRecursive(root,data);
    (found==NULL)?printf("Not found\n"):printf("Found : %u->%d\n",found,found->data);
    data=10;
    printf("Trying to find %d\n",data);
    found=searchInBinaryTreeRecursive(root,data);
    (found==NULL)?printf("Not found\n"):printf("Found : %u->%d\n",found,found->data);
}


void testSearchInBinaryTreeIterative(){
    node* root=createBinaryTree(7);
    int data=7;
    node* found=NULL;
    printf("Trying to find %d\n",data);
    found=searchInBinaryTreeIterative(root,data);
    (found==NULL)?printf("Not found\n"):printf("Found : %u->%d\n",found,found->data);
    data=10;
    printf("Trying to find %d\n",data);
    found=searchInBinaryTreeIterative(root,data);
    (found==NULL)?printf("Not found\n"):printf("Found : %u->%d\n",found,found->data);
}

void testInsertNodeIntoBinaryTree(){
    node* root=createBinaryTree(7);
    printf("\n");
    levelOrderTraversalIteartive(root);
 printf("\n");   
 insertNodeIntoBinaryTree(root,8);
    levelOrderTraversalIteartive(root);
     printf("\n");
}

void testSizeOfBinaryTreeRecursive(){
    node* root=createBinaryTree(7);
    printf("\n");
    levelOrderTraversalIteartive(root);
    printf("\n");
    printf("Size : %d ",sizeOfBinaryTreeRecursive(root));
}


void testSizeOfBinaryTreeIterative(){
    node* root=createBinaryTree(7);
    printf("\n");
    levelOrderTraversalIteartive(root);
    printf("\n");
    printf("Size : %d ",sizeOfBinaryTreeIterative(root));
}