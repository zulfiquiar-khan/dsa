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


