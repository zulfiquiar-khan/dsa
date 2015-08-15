#include<stdio.h>
#include"SinglyLinkedList.h"
#include"HashMap.h"

struct singlyNode* findMiddleNodeBruteForce(struct singlyNode** head){
    struct singlyNode* temp=*head;
    struct singlyNode* temp1=NULL;
    struct singlyNode* midNode=NULL;
    int n=1;
    int m=1;
    
    while(temp->next!=NULL){
        m=1;
        temp1=temp->next;
        while(temp1->next!=NULL){
            m++;
            temp1=temp1->next;
        }
        printf("n:%d  m:%d\n",n,m);
        if((n-1==m)||(n==m)){   
                midNode=temp;
                break;
            }
        n++;
        temp=temp->next;
    }
    
    return midNode;
}

struct singlyNode* findMiddleNodeTraverseStrategy(struct singlyNode** head){
    struct singlyNode* temp=*head;
    struct singlyNode* midNode=NULL;
    int count=1;
    int node=0;
    while(temp->next!=NULL){
        temp=temp->next;
        count++;
    }
    if(count%2==0){
        node=count/2;
    }
    else{node=count/2+1;}
    int k=1;
    temp=*head;
    while(k<node){
        k++;
        temp=temp->next;
    }
    return temp;

}


struct  singlyNode* findMiddleNodeHashMapStrategy(struct singlyNode** head){
    hashmap* map=hashmapCreate(20);
    struct singlyNode* temp=*head;
    struct singlyNode* midNode=NULL;
    int counter=0;
    int mid=0;
    while(temp!=NULL){
        counter++;
        hashmapInsert(map,temp,counter);
        temp=temp->next;
    }
    
    if(counter==0){
        return NULL;
    }
        if(counter%2==0){
            mid=counter/2;
        }else{
            mid=1+counter/2;
        }
        
        midNode=hashmapGet(map,mid);
        
    return midNode;

}

    struct singlyNode* findMiddleNodeSingleScanStrategy(struct singlyNode** head){
    struct singlyNode* slowPtr=*head;
    struct singlyNode* fastPtr=*head;
    
    if(head==NULL||*head==NULL){
        return NULL;
    }
    
    while(fastPtr->next!=NULL){
        fastPtr=fastPtr->next;
        if(fastPtr->next!=NULL){
            slowPtr=slowPtr->next;
            fastPtr=fastPtr->next;
            }
    }
    
    return slowPtr;
}












