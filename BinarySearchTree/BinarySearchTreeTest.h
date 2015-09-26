#include"BinarySearchTree.h"

bstNode* createBstForTest(){
    bstNode* newNode1=(bstNode*)malloc(sizeof(bstNode));
    bstNode* newNode2=(bstNode*)malloc(sizeof(bstNode));
    bstNode* newNode3=(bstNode*)malloc(sizeof(bstNode));
    bstNode* newNode4=(bstNode*)malloc(sizeof(bstNode));
    bstNode* newNode5=(bstNode*)malloc(sizeof(bstNode));
    bstNode* newNode6=(bstNode*)malloc(sizeof(bstNode));
    bstNode* newNode7=(bstNode*)malloc(sizeof(bstNode));
    
    newNode1->data=7;
    newNode1->left=newNode1->right=NULL;

    newNode2->data=4;
    newNode2->left=newNode2->right=NULL;
    
    newNode3->data=9;
    newNode3->left=newNode3->right=NULL;

    newNode4->data=2;
    newNode4->left=newNode4->right=NULL;
    
    newNode5->data=5;
    newNode5->left=newNode5->right=NULL;
    
    newNode6->data=8;
    newNode6->left=newNode6->right=NULL;
    
    newNode7->data=11;
    newNode7->left=newNode7->right=NULL;
    
    newNode1->left=newNode2;
    newNode1->right=newNode3;
    newNode2->left=newNode4;
    newNode2->right=newNode5;
    newNode3->left=newNode6;
    newNode3->right=newNode7;
    
    return newNode1;
}
void testFindAnElementRecursive(){
    bstNode* root=createBstForTest();
    bstNode* element=findAnElementRecursive(root,5);
    if(element!=NULL)printf("%d \n",element->data);
    else printf("Not Found\n");
    
    element=findAnElementRecursive(root,2);
    if(element!=NULL)printf("%d \n",element->data);
    else printf("Not Found\n");
    
    element=findAnElementRecursive(root,8);
    if(element!=NULL)printf("%d \n",element->data);
    else printf("Not Found\n");
    
    element=findAnElementRecursive(root,11);
    if(element!=NULL)printf("%d \n",element->data);
    else printf("Not Found\n");
    
    element=findAnElementRecursive(root,25);
    if(element!=NULL)printf("%d \n",element->data);
    else printf("Not Found\n");
}

