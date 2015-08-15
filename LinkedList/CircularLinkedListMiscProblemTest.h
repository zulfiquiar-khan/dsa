#include"CircularLinkedListMIscProblem.h"


void createCircularLinkedList(struct singlyNode** head1,struct singlyNode** head2){
    
    insertNode(head1,1,1);
    insertNode(head1,2,2);
    insertNode(head1,3,3);
    insertNode(head1,4,4);
    insertNode(head1,5,5);
    insertNode(head1,6,6);
    
    insertNode(head2,1,1);
    insertNode(head2,2,2);
    insertNode(head2,3,3);
    insertNode(head2,4,4);
    insertNode(head2,5,5);
    
    traverseList(head1);
    traverseList(head2);
    
    
}

void testSplitCircularLinkedListInHalf(){
    
    struct  singlyNode *header1;
    struct singlyNode **head1;
    header1=NULL;
    head1=&header1;
    
    struct  singlyNode *header2;
    struct singlyNode **head2;
    header2=NULL;
    head2=&header2;
    
    struct  singlyNode *header1_1;
    struct singlyNode **head1_1;
    header1_1=NULL;
    head1_1=&header1_1;
    
    struct  singlyNode *header2_1;
    struct singlyNode **head2_1;
    header2_1=NULL;
    head2_1=&header2_1;
    
    struct  singlyNode *header1_2;
    struct singlyNode **head1_2;
    header1_2=NULL;
    head1_2=&header1_2;
    
    struct  singlyNode *header2_2;
    struct singlyNode **head2_2;
    header2_2=NULL;
    head2_2=&header2_2;
    
    createCircularLinkedList(head1,head2);
    
    splitCircularLinkedListInHalf(head1,head1_1,head1_2);
    traverseList(head1_1);
    traverseList(head1_2);
    
    splitCircularLinkedListInHalf(head2,head2_1,head2_2);
    traverseList(head2_1);
    traverseList(head2_2);
    
    
}