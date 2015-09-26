#include<stdlib.h>

struct BinarySearchTreeNode{
    int data;
    struct BinarySearchTreeNode* left;
    struct BinarySearchTreeNode* right;
};

typedef struct BinarySearchTreeNode bstNode;

bstNode* findAnElementRecursive(bstNode* root,int data){
    if(root==NULL||root->data==data) return root;
    else if(root->data>data) findAnElementRecursive(root->left,data);
    else if(root->data<data) findAnElementRecursive(root->right,data);
}


