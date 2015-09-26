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

void insertAnElementIterative(bstNode* root,int data){
    if(root==NULL){
        return;
    }
    bstNode* element=(bstNode*)malloc(sizeof(bstNode));
    element->data=data;
    element->left=element->right=NULL;
    while(1){
        if(root->data<data){
            if(root->right==NULL){
                root->right=element;
                break;
            }
            else{
                root=root->right;
            }
        }
        else if(root->data>data){
            if(root->left==NULL){
                root->left=element;
                break;
            }
            else{
                root=root->left;
            }
        }
    }
    return;
}

void traverseInorder(bstNode* root){
    if(root==NULL){
        return;
    }
    traverseInorder(root->left);
    printf("%d ",root->data);
    traverseInorder(root->right);
}

bstNode* deleteRecursive(bstNode* root,int data){
    if(root==NULL){return NULL;}
    bstNode* temp=NULL;
    if(root->data<data){root->right=deleteRecursive(root->right,data);}
    else if(root->data>data){root->left=deleteRecursive(root->left,data);}
    else{
        if(root->left!=NULL && root->right!=NULL){
            temp=findMaximumElementIterative(root->left);
            root->data=temp->data;
            root->left=deleteRecursive(root->left,root->data);
        }
        else{
            if(root->left==NULL&&root->right==NULL){return NULL;}
            if(root->left==NULL)return root->right;
            if(root->right==NULL)return root->left;
        }
    }
    return root;
}