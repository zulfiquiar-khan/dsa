#include"BinarySiblingTree.h"

void testFillSibling(){
    struct BinarySiblingNode* root=(struct BinarySiblingNode*)malloc(sizeof(struct BinarySiblingNode));
    root->left=NULL;
    root->right=NULL;
    root->sibling=NULL;
    struct BinarySiblingNode* newNode1=(struct BinarySiblingNode*)malloc(sizeof(struct BinarySiblingNode));
    newNode1->left=NULL;
    newNode1->right=NULL;
    newNode1->sibling=NULL;
    struct BinarySiblingNode* newNode2=(struct BinarySiblingNode*)malloc(sizeof(struct BinarySiblingNode));
    newNode2->left=NULL;
    newNode2->right=NULL;
    newNode2->sibling=NULL;
    struct BinarySiblingNode* newNode3=(struct BinarySiblingNode*)malloc(sizeof(struct BinarySiblingNode));
    newNode3->left=NULL;
    newNode3->right=NULL;
    newNode3->sibling=NULL;
    struct BinarySiblingNode* newNode4=(struct BinarySiblingNode*)malloc(sizeof(struct BinarySiblingNode));
    newNode4->left=NULL;
    newNode4->right=NULL;
    newNode4->sibling=NULL; 
   struct BinarySiblingNode* newNode5=(struct BinarySiblingNode*)malloc(sizeof(struct BinarySiblingNode));
    newNode5->left=NULL;
    newNode5->right=NULL;
    newNode5->sibling=NULL;
    struct BinarySiblingNode* newNode6=(struct BinarySiblingNode*)malloc(sizeof(struct BinarySiblingNode));
    newNode6->left=NULL;
    newNode6->right=NULL;
    newNode6->sibling=NULL;
    
    root->data=1;
    newNode1->data=2;
    newNode2->data=3;
    newNode3->data=4;
    newNode4->data=5;
    newNode5->data=6;
    newNode6->data=7;
    
    root->left=newNode1;
    root->right=newNode2;
    newNode1->left=newNode3;
    newNode1->right=newNode4;
    newNode2->left=newNode5;
    newNode2->right=newNode6;

    fillSibling(root);
    
    printf("%d->%d\n",newNode1->data,newNode1->sibling->data);
    printf("%d->%d->%d->%d %d\n",newNode3->data,newNode3->sibling->data,newNode3->sibling->sibling->data,newNode3->sibling->sibling->sibling->data,newNode3->sibling->sibling->sibling->sibling);
}


void testFillSiblingRevursive(){
    struct BinarySiblingNode* root=(struct BinarySiblingNode*)malloc(sizeof(struct BinarySiblingNode));
    root->left=NULL;
    root->right=NULL;
    root->sibling=NULL;
    struct BinarySiblingNode* newNode1=(struct BinarySiblingNode*)malloc(sizeof(struct BinarySiblingNode));
    newNode1->left=NULL;
    newNode1->right=NULL;
    newNode1->sibling=NULL;
    struct BinarySiblingNode* newNode2=(struct BinarySiblingNode*)malloc(sizeof(struct BinarySiblingNode));
    newNode2->left=NULL;
    newNode2->right=NULL;
    newNode2->sibling=NULL;
    struct BinarySiblingNode* newNode3=(struct BinarySiblingNode*)malloc(sizeof(struct BinarySiblingNode));
    newNode3->left=NULL;
    newNode3->right=NULL;
    newNode3->sibling=NULL;
    struct BinarySiblingNode* newNode4=(struct BinarySiblingNode*)malloc(sizeof(struct BinarySiblingNode));
    newNode4->left=NULL;
    newNode4->right=NULL;
    newNode4->sibling=NULL; 
   struct BinarySiblingNode* newNode5=(struct BinarySiblingNode*)malloc(sizeof(struct BinarySiblingNode));
    newNode5->left=NULL;
    newNode5->right=NULL;
    newNode5->sibling=NULL;
    struct BinarySiblingNode* newNode6=(struct BinarySiblingNode*)malloc(sizeof(struct BinarySiblingNode));
    newNode6->left=NULL;
    newNode6->right=NULL;
    newNode6->sibling=NULL;
    
    root->data=1;
    newNode1->data=2;
    newNode2->data=3;
    newNode3->data=4;
    newNode4->data=5;
    newNode5->data=6;
    newNode6->data=7;
    
    root->left=newNode1;
    root->right=newNode2;
    newNode1->left=newNode3;
    newNode1->right=newNode4;
    newNode2->left=newNode5;
    newNode2->right=newNode6;

    fillSiblingRevursive(root);
    
    printf("%d->%d\n",newNode1->data,newNode1->sibling->data);
    printf("%d->%d->%d->%d %d\n",newNode3->data,newNode3->sibling->data,newNode3->sibling->sibling->data,newNode3->sibling->sibling->sibling->data,newNode3->sibling->sibling->sibling->sibling);
}