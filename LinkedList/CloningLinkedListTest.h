#include"CloningLinkedList.h"

void testCloneHashMapStrategy(){
    
    struct randomNode** head=createRandomList();
      struct randomNode* head1;
    head1=cloneHashMapStrategy(*head);
    
    printf("Going to taverse\n");
    traverseRandomList(&head1);
    
}