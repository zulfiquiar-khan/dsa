#include<stdio.h>
#include<stdlib.h>
#include"SinglyLinkedList.h"


struct singlyNode*  insertNodeInSortedList(struct singlyNode *head,struct singlyNode* newNode){
    struct singlyNode *current=head,*temp=NULL;
    if(!head){
            return newNode;
    }
    while(current!=NULL && current->data<newNode->data){
        temp=current;
        current=current->next;
    }
    newNode->next=current;
    if(temp!=NULL)temp->next=newNode;
    else head=newNode;
    
    return head;
}


struct singlyNode*  reverseListRecursiveVersion(struct singlyNode*head){
        struct singlyNode* secondNode=NULL;
        struct singlyNode *reversedList=NULL;
        if(head==NULL){return NULL;}
        if(head->next==NULL){return head;}
        
        secondNode=head->next;
        head->next=NULL;
        reversedList=reverseList(secondNode);
        secondNode->next=head;
        return reversedList;
}
