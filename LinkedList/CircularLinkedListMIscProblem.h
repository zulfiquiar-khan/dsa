#include<stdio.h>
#include"CircularLinkedList.h"


 
void splitCircularLinkedListInHalf(struct circularNode** head,struct circularNode** head1,struct circularNode** head2){
    struct circularNode* slowPtr=*head;
    struct circularNode* fastPtr=*head;
    *head1=NULL;
    *head2=NULL;
    
    while(fastPtr->next!=*head && fastPtr->next->next!=*head){
            slowPtr=slowPtr->next;
            fastPtr=fastPtr->next->next;
    }
    
    if(fastPtr->next->next==*head){
            fastPtr=fastPtr->next;
    }
    
    *head1=*head;
    
    if((*head)->next!=*head){
        *head2=slowPtr->next;
    }
    
    slowPtr->next=*head1;
    fastPtr->next=*head2;
}
