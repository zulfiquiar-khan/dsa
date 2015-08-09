#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include"FindNthNodeFromEnd.h"

void createList(struct singlyNode **head){
    
    insert(head,1,1);
    insert(head,2,2); 
    insert(head,3,3);
    insert(head,4,4);
    insert(head,5,3);
    
    traverseList(head);
    
    printf("Size : %d\n",getListSize(head));
    
}

void  testFindNthNodeBruteForce(){
    
    struct  singlyNode *header;
    struct singlyNode **head;
    struct singlyNode* nthNode;
    int n;
    header=NULL;
    head=&header;
    
    createList(head);
    
    n=1;
    nthNode=findNthNodeBruteForce(head,n);
    printf("%d node from end is %u and has data %d\n",n,nthNode,nthNode->data);
    
    n=2;
    nthNode=findNthNodeBruteForce(head,n);
    printf("%d node from end is %u and has data %d\n",n,nthNode,nthNode->data);
    
    n=3;
    nthNode=findNthNodeBruteForce(head,n);
    printf("%d node from end is %u and has data %d\n",n,nthNode,nthNode->data);
    
    n=4;
    nthNode=findNthNodeBruteForce(head,n);
    printf("%d node from end is %u and has data %d\n",n,nthNode,nthNode->data);
    
    n=5;
    nthNode=findNthNodeBruteForce(head,n);
    printf("%d node from end is %u and has data %d\n",n,nthNode,nthNode->data);
    
    n=6;
    nthNode=findNthNodeBruteForce(head,n);
    printf("%d node from end is %u and has data %d\n",n,nthNode,nthNode!=NULL?nthNode->data:0);
    
    n=0;
    nthNode=findNthNodeBruteForce(head,n);
    printf("%d node from end is %u and has data %d\n",n,nthNode,nthNode!=NULL?nthNode->data:0);
    
    
}

void testFinNthNodeHashMapStrategy(){
    
    struct  singlyNode *header;
    struct singlyNode **head;
    struct singlyNode* nthNode;
    int n;
    header=NULL;
    head=&header;
    
    createList(head);
    
    n=1;
    nthNode=findNthNodeHashMapStrategy(head,n);
    printf("%d node from end is %u and has data %d\n",n,nthNode,nthNode->data);
    
    n=2;
    nthNode=findNthNodeHashMapStrategy(head,n);
    printf("%d node from end is %u and has data %d\n",n,nthNode,nthNode->data);
    
    n=3;
    nthNode=findNthNodeHashMapStrategy(head,n);
    printf("%d node from end is %u and has data %d\n",n,nthNode,nthNode->data);
    
    n=4;
    nthNode=findNthNodeHashMapStrategy(head,n);
    printf("%d node from end is %u and has data %d\n",n,nthNode,nthNode->data);
    
    n=5;
    nthNode=findNthNodeHashMapStrategy(head,n);
    printf("%d node from end is %u and has data %d\n",n,nthNode,nthNode->data);
    
    n=6;
    nthNode=findNthNodeHashMapStrategy(head,n);
    printf("%d node from end is %u and has data %d\n",n,nthNode,nthNode!=NULL?nthNode->data:0);
    
    n=0;
    nthNode=findNthNodeHashMapStrategy(head,n);
    printf("%d node from end is %u and has data %d\n",n,nthNode,nthNode!=NULL?nthNode->data:0);
    

}



void testFindNthNodeCountingNodeStrategy(){
    
    struct  singlyNode *header;
    struct singlyNode **head;
    struct singlyNode* nthNode;
    int n;
    header=NULL;
    head=&header;
    
    createList(head);
    
    n=1;
    nthNode=findNthNodeCountingNodeStrategy(head,n);
    printf("%d node from end is %u and has data %d\n",n,nthNode,nthNode->data);
    
    n=2;
    nthNode=findNthNodeCountingNodeStrategy(head,n);
    printf("%d node from end is %u and has data %d\n",n,nthNode,nthNode->data);
    
    n=3;    nthNode=findNthNodeCountingNodeStrategy(head,n);
    nthNode=findNthNodeCountingNodeStrategy(head,n);
    printf("%d node from end is %u and has data %d\n",n,nthNode,nthNode->data);
    
    n=4;
    nthNode=findNthNodeCountingNodeStrategy(head,n);
    printf("%d node from end is %u and has data %d\n",n,nthNode,nthNode->data);
    
    n=5;
    nthNode=findNthNodeCountingNodeStrategy(head,n);
    printf("%d node from end is %u and has data %d\n",n,nthNode,nthNode->data);
    
    n=6;
    nthNode=findNthNodeCountingNodeStrategy(head,n);
    printf("%d node from end is %u and has data %d\n",n,nthNode,nthNode!=NULL?nthNode->data:0);
    
    n=0;
    nthNode=findNthNodeCountingNodeStrategy(head,n);
    printf("%d node from end is %u and has data %d\n",n,nthNode,nthNode!=NULL?nthNode->data:0);
    

}


void testFindNthNodePointerDifferenceStrategy(){
    
    struct  singlyNode *header;
    struct singlyNode **head;
    struct singlyNode* nthNode;
    int n;
    header=NULL;
    head=&header;
    
    createList(head);
    
    n=1;
    nthNode=findNthNodePointerDifferenceStrategy(head,n);
    printf("%d node from end is %u and has data %d\n",n,nthNode,nthNode->data);

    n=2;
    nthNode=findNthNodePointerDifferenceStrategy(head,n);
    printf("%d node from end is %u and has data %d\n",n,nthNode,nthNode->data);
    
    n=3;
    nthNode=findNthNodePointerDifferenceStrategy(head,n);
    printf("%d node from end is %u and has data %d\n",n,nthNode,nthNode->data);
    
    n=4;
    nthNode=findNthNodePointerDifferenceStrategy(head,n);
    printf("%d node from end is %u and has data %d\n",n,nthNode,nthNode->data);
    
    n=5;
    nthNode=findNthNodePointerDifferenceStrategy(head,n);
    printf("%d node from end is %u and has data %d\n",n,nthNode,nthNode->data);
    
   n=6;
    nthNode=findNthNodePointerDifferenceStrategy(head,n);
    printf("%d node from end is %u and has data %d\n",n,nthNode,nthNode!=NULL?nthNode->data:0);
    
    n=0;
    
    nthNode=findNthNodePointerDifferenceStrategy(head,n);
    printf("%d node from end is %u and has data %d\n",n,nthNode,nthNode!=NULL?nthNode->data:0);

}