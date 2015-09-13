#include<stdlib.h>
#include"LinkedBinaryTree.h"

struct BinarySiblingNode{
    int data;
    struct BinarySiblingNode* left;
    struct BinarySiblingNode* right;
    struct BinarySiblingNode* sibling;
};

void fillSibling(struct BinarySiblingNode* root){
        if(root==NULL){
            return NULL;
        }
        int flag=1;
        struct BinarySiblingNode* temp=NULL;
        struct LinkedQueue* queue=createLinkedQueue();
        enqueueLinkedQueue(queue,root);
        enqueueLinkedQueue(queue,NULL);
        while(!isEmptyLinkedQueue(queue)){
            root=dequeueLinkedQueue(queue);
            if(root==NULL){
                if(!isEmptyLinkedQueue(queue)){
                    enqueueLinkedQueue(queue,NULL);
                }
                flag=1;
            }
            else{
                            if(flag==1){
                                temp=root;
                                flag=0;
                            }
                            else{
                                temp->sibling=root;
                                temp=root;
                            }
                    if(root->left!=NULL){
                        enqueueLinkedQueue(queue,root->left);
                    }
                    if(root->right!=NULL){
                        enqueueLinkedQueue(queue,root->right);
                    }
            }
            
        }
}