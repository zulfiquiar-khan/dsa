#include<stdio.h>
#include<stdlib.h>
#include"MiscLinkedListProblem.h"


void createList(struct singlyNode **head){
    
    insert(head,2,1); 
    insert(head,4,2);
    insert(head,5,3);
    insert(head,6,4);
    
    traverseList(head);
    
    printf("Size : %d\n",getListSize(head));
    
}

void testInsertNodeInSortedList(){
    
    struct  singlyNode *header;
    struct singlyNode **head;
    struct singlyNode* nthNode;
    header=NULL;
    head=&header;
    createList(head);
    
    struct singlyNode *newNode1=(struct singlyNode *)malloc(sizeof(struct singlyNode));
    newNode1->data=3;
    newNode1->next=NULL;
    *head=insertNodeInSortedList(*head,newNode1);
    traverseList(head);
    
    struct singlyNode *newNode2=(struct singlyNode *)malloc(sizeof(struct singlyNode));
    newNode2->data=7;
    newNode2->next=NULL;
    *head=insertNodeInSortedList(*head,newNode2);
    traverseList(head);
    
    struct singlyNode *newNode3=(struct singlyNode *)malloc(sizeof(struct singlyNode));
    newNode3->data=1;
    newNode3->next=NULL;
    *head=insertNodeInSortedList(*head,newNode3);
     traverseList(head);
}

void testreverseListIterativeVersion(){
    
    struct  singlyNode *header;
    struct singlyNode **head;
    header=NULL;
    head=&header;
    createList(head);
    
    *head=reverseListIterativeVersion(*head);
      traverseList(head);

}

void testreverseListRecursiveVersion(){
    
    struct  singlyNode *header;
    struct   singlyNode **head;
    header=NULL;
    head=&header;
    createList(head);
    
    *head=reverseListRecursiveVersion(*head);
      traverseList(head);

}


void testTraverseLinkedListFromEndToStart(){
    struct  singlyNode *header;
    struct   singlyNode **head;
    header=NULL;
    head=&header;
    createList(head);
    traverseLinkedListFromEndToStart(*head);
}