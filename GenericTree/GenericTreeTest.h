#include"GenericTree.h"

genericnode* createGenericTree(){
    genericnode* newNode1=(genericnode*)malloc(sizeof(genericnode));
    genericnode* newNode2=(genericnode*)malloc(sizeof(genericnode));
    genericnode* newNode3=(genericnode*)malloc(sizeof(genericnode));
    genericnode* newNode4=(genericnode*)malloc(sizeof(genericnode));
    genericnode* newNode5=(genericnode*)malloc(sizeof(genericnode));
    genericnode* newNode6=(genericnode*)malloc(sizeof(genericnode));
    genericnode* newNode7=(genericnode*)malloc(sizeof(genericnode));
    
    newNode1->data=1;
    newNode1->firstChild=NULL;
    newNode1->sibling=NULL;
    
    newNode2->data=2;
    newNode2->firstChild=NULL;
    newNode2->sibling=NULL;
    
    newNode3->data=3;
    newNode3->firstChild=NULL;
    newNode3->sibling=NULL;
    
    newNode4->data=4;
    newNode4->firstChild=NULL;
    newNode4->sibling=NULL;
    
    newNode5->data=5;
    newNode5->firstChild=NULL;
    newNode5->sibling=NULL;

    newNode6->data=6;
    newNode6->firstChild=NULL;
    newNode6->sibling=NULL;

    newNode7->data=7;
    newNode7->firstChild=NULL;
    newNode7->sibling=NULL;
    
    newNode1->firstChild=newNode2;
    newNode2->sibling=newNode3;
    newNode3->sibling=newNode4;
    newNode3->firstChild=newNode5;
    newNode5->sibling=newNode6;
    newNode6->sibling=newNode7;
    
    return newNode1;
}


void testSumOfAllElementsRecursive(){
    genericnode* root=createGenericTree();
    printf("%d\n",sumOfAllElementsRecursive(root));
}

void testSumOfAllElementsIterative(){
    genericnode* root=createGenericTree();
    printf("%d\n",sumOfAllElementsIterative(root));
}