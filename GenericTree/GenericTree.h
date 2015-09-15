#include<stdlib.h>
#include"../Queue/LinkedListQueue.h"

typedef  struct TreeNode genericnode;

struct TreeNode{
    int data;
    genericnode* firstChild;
    genericnode* sibling;
};


int  sumOfAllElementsRecursive(genericnode* root){
    if(root==NULL){
        return 0;
    }
    return (root->data+sumOfAllElementsRecursive(root->firstChild)+sumOfAllElementsRecursive(root->sibling));
}


int  sumOfAllElementsIterative(genericnode* root){
   if(root==NULL){
        return 0;
    }
    struct LinkedQueue* queue=createLinkedQueue();
    enqueueLinkedQueue(queue,root);
    displayLinkedQueue(queue);
    int sum=0;
    while(!isEmptyLinkedQueue(queue)){
        root=(genericnode*) dequeueLinkedQueue(queue);
        sum=sum+root->data;
        if(root->firstChild!=NULL){
            enqueueLinkedQueue(queue,root->firstChild);
        }
        if(root->sibling!=NULL){
            enqueueLinkedQueue(queue,root->sibling);
        }
    }
    deleteLinkedQueue(queue);
    return sum;
}


int countSiblings(genericnode* node){
    int count=0;
    if(node==NULL){
        return count;
    }
    node=node->sibling;
    while(node!=NULL){
        count++;
        node=node->sibling;
    }
    return count;
}
