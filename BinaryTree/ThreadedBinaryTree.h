#include<stdlib.h>
#include"LinkedBinaryTree.h"

typedef struct threaded_node threaded_node;

struct threaded_node{
    int data;
    int lTag;
    int rTag;
    struct threaded_node* left;
    struct threaded_node* right;
};

threaded_node* copyBinaryTreeToThreadedBinaryTree(node*);
threaded_node* createInorderThreadedBinaryTree(node*);
void displayThreadedBinaryTree(threaded_node*);

threaded_node* createInorderThreadedBinaryTree(node* root){
    if(root==NULL ){
        return NULL;
    }
    threaded_node* newRoot=(threaded_node*)malloc(sizeof(threaded_node));
    newRoot->lTag=1;
    newRoot->rTag=1;
    newRoot->right=newRoot;
    newRoot->left=NULL;
    
    int array[20];
    int length=0;
    
     newRoot->left=copyBinaryTreeToThreadedBinaryTree(root);
     produceInorderSequence(newRoot->left,array,&length);
     threadInorder(array,length,newRoot);
     
     return  newRoot;
}

threaded_node* copyBinaryTreeToThreadedBinaryTree(node* root){
    if(root==NULL){
        return NULL;
    }
    threaded_node* threaded_root=(threaded_node*)malloc(sizeof(threaded_node));
    threaded_root->data=root->data;
    threaded_root->lTag=1;
    threaded_root->rTag=1;
    threaded_root->left=copyBinaryTreeToThreadedBinaryTree(root->left);
    threaded_root->right=copyBinaryTreeToThreadedBinaryTree(root->right);
    return threaded_root;
}

void produceInorderSequence(threaded_node* root,int array[],int * length){
    if(root==NULL){
        return;
    }
    produceInorderSequence(root->left,array,length);
    array[*length]=root;
    *length=*length+1;
    produceInorderSequence(root->right,array,length);
}

void  threadInorder(int array[],int length,threaded_node* newRoot){
    int i=0;
    threaded_node* temp=NULL;
    for(i=0;i<length;i++){
        temp=(threaded_node*)array[i];
        if(temp==NULL){return;}
        if(i==0){
            temp->left=newRoot;
            temp->lTag=0;
            if(temp->right==NULL){temp->right=array[i+1];temp->rTag=0;}
        }
        else if(i==length-1){
            if(temp->left==NULL){temp->left=array[i-1];temp->lTag=0;}
            temp->right=newRoot;
            temp->rTag=0;
        }
        else{
            if(temp->left==NULL){temp->left=array[i-1];temp->lTag=0;}
            if(temp->right==NULL){temp->right=array[i+1];temp->rTag=0;}
        }
    }
    
    for(i=0;i<length;i++){
        temp=(threaded_node*)array[i];
        printf("Node : %u->%d  lTag: %d rTag: %d Left : %d Right : %d \n",temp,temp->data,temp->lTag,temp->rTag,(temp->left==newRoot)?0:temp->left->data,(temp->right==newRoot)?0:temp->right->data);
    }
}


threaded_node* findInorderSuccesor(threaded_node* root){
    if(root==NULL){
        return NULL;
    }
    threaded_node* position=NULL;
    if(root->rTag==0){return root->right;}
    else{
        position=root->right;
        while(position->lTag==1){position=position->left;}
        return position;
    }
}

void inorderTraversal(threaded_node* root){
    threaded_node* P=findInorderSuccesor(root);
    while(1){
        printf("%d ",P->data);
        P=findInorderSuccesor(P);
        if(P==root){break;}
    }
    printf("\n");
}

threaded_node* findPreOrderSuccesor(threaded_node* root){
    threaded_node* position=NULL;
    if(root->lTag==1){
        return root->left;
    }
    position=root;
    while(position->rTag==0){
        position=position->right;
    }
    return position->right;
}