#include<stdio.h>
#include<stdlib.h>
#include"RandomLinkedList.h"
#include"HashMap.h"

struct randomNode* cloneHashMapStrategy(struct randomNode* head){
    struct randomNode* temp=head;
    struct randomNode* temp1=NULL;
    struct randomNode* newList=NULL;
    hashmap* map=hashmapCreate(20);

    while(temp!=NULL){
        temp1=(struct randomNode*)malloc(sizeof(struct randomNode*));
        temp1->data=temp->data;
        temp1->next=NULL;
        temp1->random=NULL;
        printf("temp : %u->%d  temp1 : %u->%d  \n",temp,temp->data,temp1,temp1->data);
        hashmapInsert(map,temp1,temp);
        temp1=(struct randomNode*)hashmapGet(map,temp);
        printf("temp : %u->%d  temp1 : %u->%d  \n",temp,temp->data,temp1,temp1->data);
        printf("*head  : %u\n\n",head);
        temp=temp->next;
    }
    

    printf("temp after loop  :  %u\n",temp);
    printf("head  after loop  :  %u\n",head);
    printf("\n");
    
    temp=head;
    
    while(temp!=NULL){
        temp1=hashmapGet(map,temp);
        temp1->next=hashmapGet(map,temp->next);
        temp1->random=hashmapGet(map,temp->random);
        temp=temp->next;
    }
    printf("Done\n");
    newList=hashmapGet(map,head);
    //printf("cloned list : \n");
    //traverseRandomList(&newList);
   
    return  newList;
}



struct randomNode* cloneTraverseStrategy(struct randomNode* head){
    struct randomNode* temp=head;
    struct randomNode* temp1=NULL;
    struct randomNode* cloneList=NULL;
    while(temp!=NULL){
        temp1=(struct randomNode*)malloc(sizeof(struct randomNode*));
        if(cloneList==NULL){cloneList=temp1;}
        temp1->data=temp->data;
        temp1->next=temp->random;
        temp1->random=NULL;
        temp->random=temp1;
        
        temp=temp->next;
    }
    
    temp=head;
    while(temp!=NULL){  
        temp1=temp->random;
        temp1->random=temp1->next->random;
        temp=temp->next;
    }
        
    temp=head;
    while(temp!=NULL){
        temp1=temp->random;
        temp->random=temp1->next;
        if(temp->next!=NULL){
            temp1->next=temp->next->random;
        }
        else {
            temp1->next=temp->next;
        }
        temp=temp->next;
    }
    
    return cloneList;
}

