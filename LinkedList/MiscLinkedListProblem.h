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
        reversedList=reverseListRecursiveVersion(secondNode);
        secondNode->next=head;
        return reversedList;
}


struct singlyNode* reverseListIterativeVersion(struct singlyNode *head){
    struct singlyNode* temp=NULL;
    struct singlyNode* nextNode=NULL;
    while(head!=NULL){
        nextNode=head->next;
        head->next=temp;
        temp=head;
        head=nextNode;
    }
    return temp;
}


void traverseLinkedListFromEndToStart(struct singlyNode* head){
    struct singlyNode* temp=head;
    if(head==NULL){
        return ;
    }
    traverseLinkedListFromEndToStart(temp->next);
    printf("%u->%d \n",temp,temp->data);
}


int findWetherListIsEvenOrOdd(struct singlyNode** head){
    struct singlyNode* temp=*head;
    int flag=0; //0 means odd 1 means even
    
    while(temp!=NULL&&temp->next!=NULL){
        temp=temp->next->next;
    }
    if(temp==NULL){
        flag=1;
    }
    return flag;
}




struct singlyNode** mergeTwoSortedListInSortedOrderIterative(struct singlyNode** head1,struct singlyNode** head2){
    struct singlyNode* first1=*head1;
    struct singlyNode* first2=*head2;
    struct singlyNode* newNode=(struct singlyNode*) malloc(sizeof(struct singlyNode));
    struct singlyNode* temp=newNode;
    struct singlyNode* prevTemp=NULL;
    temp->next=NULL;
    
    while(first1!=NULL && first2!=NULL){
        if(first1->data<=first2->data){
            temp->next=first1;
            temp=temp->next;
            first1=first1->next;
        }
        else{
                   temp->next=first2;
                    temp=temp->next;
                    first2=first2->next;
        }
    }
    
    if(first1==NULL){
            temp->next=first2;
        }
    else{
        temp->next=first1;
    }
    
    temp=newNode;
    temp=temp->next;
    free(newNode);
    
    return &temp;
}