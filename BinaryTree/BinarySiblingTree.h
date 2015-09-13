#include<stdlib.h>
#include"../Queue/LinkedListQueue.h"

struct BinarySiblingNode{
    int data;
    struct BinarySiblingNode* left;
    struct BinarySiblingNode* right;
    struct BinarySiblingNode* sibling;
}

void fillSibling(struct BinarySiblingNode* root){
        if(root==NULL){
            return NULL;
        }
        struct LinkedQueue* queue=createLinkedQueue();
        
}