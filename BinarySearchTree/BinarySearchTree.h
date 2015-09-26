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

bstNode* findInorderPredecessor(bstNode* root,bstNode* element){
    if(root==NULL||element==NULL)return NULL;
    bstNode* found=findAnElementIterative(root,element->data);
    if(found==NULL)return NULL;
    bstNode* predecessor=findMaximumElementIterative(found->left);
    return predecessor;
}

bstNode* findInorderSuccessor(bstNode* root,bstNode* element){
    if(root==NULL||element==NULL)return NULL;
    bstNode* found=findAnElementIterative(root,element->data);
    if(found==NULL)return NULL;
    bstNode* successor=findMinimumElementIterative(found->right);
    return successor;
}

bstNode* insertAnElementRecursive(bstNode* root,int data){
    if(root==NULL){
        root=(bstNode*)malloc(sizeof(bstNode));
        if(root==NULL){
            printf("Memory Errro\n");
            return NULL;
        }
        else{
            root->data=data;
            root->left=root->right=NULL;
        }       
    }
    else{
        if(root->data>data){
            root->left=insertAnElementRecursive(root->left,data);
        }
        else if(root->data<data){
            root->right=insertAnElementRecursive(root->right,data);
        }
    }
    return root;
}

void traverseInorder(bstNode* root){
    if(root==NULL){
        return;
    }
    traverseInorder(root->left);
    printf("%d ",root->data);
    traverseInorder(root->right);
}
