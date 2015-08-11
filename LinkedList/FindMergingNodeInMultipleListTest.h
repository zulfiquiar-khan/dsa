#include"FindMergingNodeInMultipleList.h"

void createMergingList(struct  singlyNode** list1,struct singlyNode** list2){
    
    insert(list1,1,1);
    insert(list1,2,2); 
    insert(list1,3,3);
    insert(list1,4,4);
    insert(list1,5,5);
    insert(list1,6,6); 
    insert(list1,7,7);
    insert(list1,8,8);
    insert(list1,9,9);
    
    insert(list2,11,1);
    insert(list2,22,2); 
    insert(list2,33,3);
    insert(list2,44,4);
    
    struct singlyNode* mergeNode=getNodeFromList(list1,7);
    struct singlyNode* nodeFrom=getNodeFromList(list2,4);
    nodeFrom->next=mergeNode;
    
    traverseList(list1);
    printf("Size : %d\n",getListSize(list1));
    traverseList(list2);
    printf("Size : %d\n",getListSize(list2));
    

}


void testFindMergingPointBruteForce(){
    struct  singlyNode *header1;
    struct singlyNode **head1;
    header1=NULL;
    head1=&header1;
    
    struct  singlyNode *header2;
    struct singlyNode **head2;
    header2=NULL;
    head2=&header2;

    createMergingList(head1,head2);
    

    struct singlyNode* mergingNode=findMergingPointBruteForce(head1,head2);
    printf("Merging node is %u->%d\n",mergingNode,mergingNode!=NULL?mergingNode->data:0);
}


void testFindMergingPointHashTableStrategy(){
        struct  singlyNode *header1;
    struct singlyNode **head1;
    header1=NULL;
    head1=&header1;
    
    struct  singlyNode *header2;
    struct singlyNode **head2;
    header2=NULL;
    head2=&header2;

    createMergingList(head1,head2);
    

    struct singlyNode* mergingNode=findMergingPointHashTableStrategy(head1,head2);
    printf("Merging node is %u->%d\n",mergingNode,mergingNode!=NULL?mergingNode->data:0);

}


void testFindMergingPointStackStrategy(){
    struct  singlyNode *header1;
    struct singlyNode **head1;
    header1=NULL;
    head1=&header1;
    
    struct  singlyNode *header2;
    struct singlyNode **head2;
    header2=NULL;
    head2=&header2;

    createMergingList(head1,head2);
    

    struct singlyNode* mergingNode=findMergingPointStackStrategy(head1,head2);
    printf("Merging node is %u->%d\n",mergingNode,mergingNode!=NULL?mergingNode->data:0);

}



void testFindMergingPointEfficientApproach(){
    struct  singlyNode *header1;
    struct singlyNode **head1;
    header1=NULL;
    head1=&header1;
    
    struct  singlyNode *header2;
    struct singlyNode **head2;
    header2=NULL;
    head2=&header2;

    createMergingList(head1,head2);
    

    struct singlyNode* mergingNode=findMergingPointEfficientApproach(head1,head2);
    printf("Merging node is %u->%d\n",mergingNode,mergingNode!=NULL?mergingNode->data:0);

}


