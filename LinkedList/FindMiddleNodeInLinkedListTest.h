#include"FindMiddleNodeInLinkedList.h"

void createOddList(struct singlyNode **head){
    
    insert(head,1,1);
    insert(head,2,2); 
    insert(head,3,3);
    insert(head,4,4);
    insert(head,5,3);
    
    traverseList(head);
    
    printf("Size : %d\n",getListSize(head));
    
}

void createEvenList(struct singlyNode **head){
    
    insert(head,1,1);
    insert(head,2,2); 
    insert(head,3,3);
    insert(head,4,4);
    
    traverseList(head);
    
    printf("Size : %d\n",getListSize(head));
    
}

void  testFindMiddleNodeBruteForce(){
    
    struct  singlyNode *header;
    struct singlyNode **head;
    struct singlyNode* nthNode;
    header=NULL;
    head=&header;
    
    createOddList(head);
    
    nthNode=findMiddleNodeBruteForce(head);
    printf("Middle node from end is %u and has data %d\n",nthNode,nthNode!=NULL?nthNode->data:0);
    
    struct  singlyNode *header1;
    struct singlyNode **head1;
    struct singlyNode* nthNode1;
    header1=NULL;
    head1=&header1;
    
    createEvenList(head1);
    
    nthNode1=findMiddleNodeBruteForce(head1);
    printf("Middle node from end is %u and has data %d\n",nthNode1,nthNode1!=NULL?nthNode1->data:0);
    

}


void  testFindMiddleNodeTraverseStrategy(){
    
    struct  singlyNode *header;
    struct singlyNode **head;
    struct singlyNode* nthNode;
    header=NULL;
    head=&header;
    
    createOddList(head);
    
    nthNode=findMiddleNodeTraverseStrategy(head);
    printf("Middle node from end is %u and has data %d\n",nthNode,nthNode!=NULL?nthNode->data:0);
    
    struct  singlyNode *header1;
    struct singlyNode **head1;
    struct singlyNode* nthNode1;
    header1=NULL;
    head1=&header1;
    
    createEvenList(head1);
    
    nthNode1=findMiddleNodeTraverseStrategy(head1);
    printf("Middle node from end is %u and has data %d\n",nthNode1,nthNode1!=NULL?nthNode1->data:0);
    

}



void  testFindMiddleNodeHashMapStrategy()
{    
    struct  singlyNode *header;
    struct singlyNode **head;
    struct singlyNode* nthNode;
    header=NULL;
    head=&header;
    
    createOddList(head);
    
    nthNode=findMiddleNodeHashMapStrategy(head);
    printf("Middle node from end is %u and has data %d\n",nthNode,nthNode!=NULL?nthNode->data:0);
    
    struct  singlyNode *header1;
    struct singlyNode **head1;
    struct singlyNode* nthNode1;
    header1=NULL;
    head1=&header1;
    
    createEvenList(head1);
    
    nthNode1=findMiddleNodeHashMapStrategy(head1);
    printf("Middle node from end is %u and has data %d\n",nthNode1,nthNode1!=NULL?nthNode1->data:0);
    
}

void  testFindMiddleNodeSingleScanStrategy()
{    
    struct  singlyNode *header;
    struct singlyNode **head;
    struct singlyNode* nthNode;
    header=NULL;
    head=&header;
    
    createOddList(head);
    
    nthNode=findMiddleNodeSingleScanStrategy(head);
    printf("Middle node from end is %u and has data %d\n",nthNode,nthNode!=NULL?nthNode->data:0);
    
    struct  singlyNode *header1;
    struct singlyNode **head1;
    struct singlyNode* nthNode1;
    header1=NULL;
    head1=&header1;
    
    createEvenList(head1);
    
    nthNode1=findMiddleNodeSingleScanStrategy(head1);
    printf("Middle node from end is %u and has data %d\n",nthNode1,nthNode1!=NULL?nthNode1->data:0);
    
}