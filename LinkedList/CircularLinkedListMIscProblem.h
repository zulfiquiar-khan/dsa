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


struct circularNode* josephusCircle(){
    int m;
    int n;
    printf("Enter total number of candidates : ");
    scanf("%d",&n);
    printf("Enter M : ");
    scanf("%d",&m);
    
    struct circularNode* p=(struct circularNode* )malloc(sizeof(struct circularNode));
    p->data=1;
    struct circularNode* q=p;
    int i=2;
    for(;i<=n;i++){
        p->next=(struct circularNode* )malloc(sizeof(struct circularNode));
        p->next->data=i;
        p=p->next;
    }
    p->next=q;
    printf("Circular List at the start : ");
    traverseList(&q);

    int j=0;
    p=q;
    for(i=1;i<n;i++){
            for(j=0;j<m-1;j++){
                    p=p->next;
            }
             printf("\np is at %d \n",p->data);
            traverseList(&p);
            p->next=p->next->next;
            p=p->next;
            traverseList(&p);
    }
        return p;
}