#include<stdlib.h>
#include"../Stack/DynamicArrayStack.h"

struct BinaryTreeNode{
    int data;
    struct BinaryTreeNode* left;
    struct BinaryTreeNode* right;
};

typedef struct BinaryTreeNode node;

node* createBinaryTree(int size){
    node* root=(node*)malloc(sizeof(node));
    int i=1;
    if(root==NULL){
        printf("Memory error\n");
        return NULL;
    }
    root->data=i;
    root->left=NULL;
    root->right=NULL;
    i++;
    int flag=0;
    while(i<=size){
        printf("inserting %d \n",i);
        printf("----------------------\n");
        insert(root,i,flag);
        printf("inserted %d \n",i);
        printf("----------------------\n");
        if(flag==0){flag=1;}
        else{flag=0;}
        i++;
    }
    return root;
}

void insert(node* root,int data,int flag){
    node* newNode=(node*)malloc(sizeof(node));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    while(root!=NULL){
        if(root->left==NULL && root->right==NULL){
            if(flag==0){
                root->left=newNode;
                printf("inserted in left of %d \n",root->data);
                }
            else{
                root->right=newNode;
                printf("inserted in right of %d\n",root->data);
            }
            break;
        }
        else if(root->left==NULL){
            root->left=newNode;
            printf("inserted in left of %d\n",root->data);
            break;
        }
        else if(root->right==NULL){
            root->right=newNode;
            printf("inserted in right of %d\n",root->data);
            break;
        }
        else{
            if(flag==0){
                root=root->left;
                printf("moved to left\n");
            }
            if(flag==1){
                root=root->right;
                printf("moved to right\n");
            }
        }
    }
}

void preOrderTraversalRecursive(node* root){
    if(root!=NULL){
        printf("%d ",root->data);
        preOrderTraversalRecursive(root->left);
        preOrderTraversalRecursive(root->right);
    }
}

void preOrderTraversalIterative(node* root){
    struct Stack* stack=NULL;
    if(root!=NULL){
        stack=createStack();
        while(1){
            while(root!=NULL){
                printf("%d ",root->data);
                push(stack,root);
                root=root->left;
            }
            if(isEmptyStack(stack))break;
                root=pop(stack);
                root=root->right;
        }
        deleteStack(stack);
    }
}

void inOrderTraversalRecursive(node* root){
    if(root!=NULL){
        inOrderTraversalRecursive(root->left);
        printf("%d ",root->data);
        inOrderTraversalRecursive(root->right);
    }
}

void inOrderTraversalIterative(node* root){
    struct Stack* stack=NULL;
    if(root!=NULL){
        stack=createStack();
        while(1){
            while(root!=NULL){
                push(stack,root);
                root=root->left;
            }
            if(isEmptyStack(stack))break;
                root=pop(stack);
                printf("%d ",root->data);
                root=root->right;
        }
        deleteStack(stack);
    }    
}

void postOrderTraversalRecursive(node* root){
    if(root!=NULL){
        postOrderTraversalRecursive(root->left);
        postOrderTraversalRecursive(root->right);
        printf("%d ",root->data);
    }
}

void postOrderTraversalIterative(node* root){
    if(root==NULL){return;}
    node* current=NULL;
    node* previous=NULL;
    struct Stack* stack=createStack();
    push(stack,root);
    
    while(!isEmptyStack(stack)){
        current=(node *)top(stack);
        if(previous==NULL || previous->left==current||previous->right==current){
            if(current->left!=NULL){
                push(stack,current->left);
            }
            else if(current->right!=NULL){
                push(stack,current->right);
            }
        }
        else if(current->left==previous){
            if(current->right!=NULL){
                push(stack,current->right);
            }
        }
        else{
            printf("%d ",current->data);
            pop(stack);
        }
        previous=current;
    }
    
}

