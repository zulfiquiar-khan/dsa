#include<stdio.h>
#include<stdlib.h>
#include"FindCycleInLinkedList.h"

void createListWithCycle(struct singlyNode **head){
    
    struct singlyNode *firstNode;
    struct singlyNode *secondNode;
    
    insert(head,1,1);
    insert(head,2,2); 
    insert(head,3,3);
    insert(head,4,4);
    insert(head,5,5);
    insert(head,6,6); 
    insert(head,7,7);
    insert(head,8,8);
    insert(head,9,9);
    
    firstNode=getNodeFromList(head,4);
    printf("First node selected is %u->%d\n",firstNode,firstNode!=NULL?firstNode->data:0);
    secondNode=getNodeFromList(head,9);
    printf("Second node selected is %u->%d\n",secondNode,secondNode!=NULL?secondNode->data:0);
    
    secondNode->next=firstNode;
    
    printf("List with cycle created\n");
}

void createList(struct singlyNode **head){
    
    insert(head,1,1);
    insert(head,2,2); 
    insert(head,3,3);
    insert(head,4,4);
    insert(head,5,5);
    insert(head,6,6); 
    insert(head,7,7);
    insert(head,8,8);
    insert(head,9,9);
    
    traverseList(head);
    
    printf("Size : %d\n",getListSize(head));
    
}

void displayResult(int result){
    if(result==0){
        printf("List does not have cycle\n");
    }
    else if(result==1){
        printf("List has cycle\n");
    }else if(result==-1){
        printf("Error cant compute result\n");
    }
}

void testFindWetherListHasCycleHashMapStrategy(){
    
   struct  singlyNode *header;
    struct singlyNode **head;
    header=NULL;
    head=&header;
    
    createListWithCycle(head);
    int result=findWetherListHasCycleHashMapStrategy(head);
    displayResult(result);
    
    struct  singlyNode *header1;
    struct singlyNode **head1;
    header1=NULL;
    head1=&header1;
    createList(head1);
    int result1=findWetherListHasCycleHashMapStrategy(head1);
    displayResult(result1);
}

