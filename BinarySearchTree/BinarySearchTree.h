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

bstNode* findAnElementIterative(bstNode* root,int data){
    while(root!=NULL){
        if(root->data==data)return root;
        else if(root->data>data) root=root->left;
        else root=root->right;
    }
    return root;
}

bstNode* findMinimumElementRecursive(bstNode* root){
    if(root->left==NULL||root==NULL)return root;
    else findMinimumElementRecursive(root->left);
}

bstNode* findMinimumElementIterative(bstNode* root){
    while(root!=NULL&&root->left!=NULL){root=root->left;}
    return root;
}


bstNode* findMaximumElementRecursive(bstNode* root){
    if(root->right==NULL||root==NULL)return root;
    else findMaximumElementRecursive(root->right);
}

bstNode* findMaximumElementIterative(bstNode* root){
    while(root!=NULL&&root->right!=NULL){root=root->right;}
    return root;
}
