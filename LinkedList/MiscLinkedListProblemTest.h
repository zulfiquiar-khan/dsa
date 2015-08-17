#include<stdio.h>
#include<stdlib.h>
#include"MiscLinkedListProblem.h"


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
    insert(head,10,10);
    
    traverseList(head);
    
    printf("Size : %d\n",getListSize(head));
    
}

void createTwoSortedeLinkedList(struct singlyNode** head1,struct singlyNode** head2){
    insert(head1,1,1); 
    insert(head1,2,2);
    insert(head1,3,3);
    insert(head1,4,4);
    insert(head1,5,5);
    insert(head1,6,6);
    insert(head1,7,7);
    
    insert(head2,1,1); 
    insert(head2,2,2);
    insert(head2,3,3);
    insert(head2,4,4);
    
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



void testFindWetherListIsEvenOrOdd(){
    struct  singlyNode *header;
    struct   singlyNode **head;
    header=NULL;
    head=&header;
    createList(head);
    int result=findWetherListIsEvenOrOdd(head);
    if(result==0){printf("Odd\n");}
    else{printf("Even\n");}
}


void testMergeTwoSortedListInSortedOrderIterative(){
    
    struct  singlyNode *header1;
    struct   singlyNode **head1;
    header1=NULL;
    head1=&header1;
 
    struct  singlyNode *header2;
    struct   singlyNode **head2;
    header2=NULL;
    head2=&header2;
    
    createTwoSortedeLinkedList(head1,head2);
    
    struct singlyNode** newMergedList=mergeTwoSortedListInSortedOrderIterative(head1,head2);
    
    traverseList(newMergedList);
    
}

void testMergeTwoSortedListInSortedOrderRecursive(){
    
    struct  singlyNode *header1;
    struct   singlyNode **head1;
    header1=NULL;
    head1=&header1;
 
    struct  singlyNode *header2;
    struct   singlyNode **head2;
    header2=NULL;
    head2=&header2;
    
    createTwoSortedeLinkedList(head1,head2);
    
    struct singlyNode* newMergedList=mergeTwoSortedListInSortedOrderRecursive(*head1,*head2);
    
    traverseList(&newMergedList);
    
}

void testReverseLinkedListInPairsRecursive(){
    
    struct  singlyNode *header1;
    struct   singlyNode **head1;
    header1=NULL;
    head1=&header1;
 
    struct  singlyNode *header2;
    struct   singlyNode **head2;
    header2=NULL;
    head2=&header2;
    
    createTwoSortedeLinkedList(head1,head2);
    
    
    struct singlyNode* list1=reverseLinkedListInPairsRecursive(*head1);
    traverseList(&list1);
    list1=reverseLinkedListInPairsRecursive(*head2);
    traverseList(&list1);
    
}



void testReverseLinkedListInPairsIterative(){
    
    struct  singlyNode *header1;
    struct   singlyNode **head1;
    header1=NULL;
    head1=&header1;
 
    struct  singlyNode *header2;
    struct   singlyNode **head2;
    header2=NULL;
    head2=&header2;
    
    createTwoSortedeLinkedList(head1,head2);
    
    
    struct singlyNode* list1=reverseLinkedListInPairsIterative(head1);
    traverseList(&list1);
    list1=reverseLinkedListInPairsIterative(head2);
    traverseList(&list1);
    
}

void testCheckIfAlistIsPalindrome(){
    
    struct  singlyNode *header1;
    struct   singlyNode **head1;
    header1=NULL;
    head1=&header1;
 
    struct  singlyNode *header2;
    struct   singlyNode **head2;
    header2=NULL;
    head2=&header2;
   
 
    createTwoSortedeLinkedList(head1,head2);

    
    printf("Is Palindrome : %d \n",checkIfAlistIsPalindrome(head1));
    printf("Is Palindrome : %d\n",checkIfAlistIsPalindrome(head2));
    
}


void testReverseBolckOfKNodesInLinkedList(){
    
    struct  singlyNode *header1;
    struct   singlyNode **head1;
    header1=NULL;
    head1=&header1;
 
    struct  singlyNode *header2;
    struct   singlyNode **head2;
    header2=NULL;
    head2=&header2;
   
 
    createTwoSortedeLinkedList(head1,head2);
    traverseList(head1);
    *head1=reverseBlockofNodesInLinkedList(head1,4);
    traverseList(head1);

    
    //traverseList(head2);
   // reverseBolckOfKNodesInLinkedList(head2,2);
    //traverseList(head2);
    
}


void testFindLastModularNodeFromStart(){
    struct  singlyNode *header1;
    struct   singlyNode **head1;
    header1=NULL;
    head1=&header1;
    
    createList(head1);
    struct singlyNode* modularNode=NULL;
    modularNode=findLastModularNodeFromStart(*head1,3);
    printf("Modular Node is : %u->%d\n",modularNode,modularNode!=NULL?modularNode->data:0);


    modularNode=findLastModularNodeFromStart(*head1,1);
    printf("Modular Node is : %u->%d\n",modularNode,modularNode!=NULL?modularNode->data:0);

    modularNode=findLastModularNodeFromStart(*head1,0);
    printf("Modular Node is : %u->%d\n",modularNode,modularNode!=NULL?modularNode->data:0);

    modularNode=findLastModularNodeFromStart(*head1,5);
    printf("Modular Node is : %u->%d\n",modularNode,modularNode!=NULL?modularNode->data:0);

    modularNode=findLastModularNodeFromStart(*head1,4);
    printf("Modular Node is : %u->%d\n",modularNode,modularNode!=NULL?modularNode->data:0);

}