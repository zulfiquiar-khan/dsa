#include<stdio.h>
#include<stdlib.h>
#include"CircularLinkedList.h"


void testCircularLinkedList(){
    
      /**Circular Linked List Code START**/
    
        struct  circularNode *header;
        struct  circularNode **head;
        header=NULL;
        head=&header;
        
        insertNode(head,1,1);
        traverseList(head);
        printf("size : %d\n",getListSize(head));
        
        deleteNode(head,1);
        traverseList(head);
        printf("size : %d\n",getListSize(head));
        
        insertNode(head,2,1);
        traverseList(head);
        printf("size : %d\n",getListSize(head));
        
        insertNode(head,3,1);
        traverseList(head);        
        printf("size : %d\n",getListSize(head));
        
        insertNode(head,4,3);
        traverseList(head);
        printf("size : %d\n",getListSize(head));
        
        insertNode(head,5,2);
        traverseList(head);
        printf("size : %d\n",getListSize(head));
        
        insertNode(head,6,6);
        traverseList(head);        
        printf("size : %d\n",getListSize(head));

        insertNode(head,7,10);
        traverseList(head);        
        printf("size : %d\n",getListSize(head));
        
        deleteNode(head,4);
        traverseList(head);
        printf("size : %d\n",getListSize(head));
        
        deleteNode(head,2);
        traverseList(head);
        printf("size : %d\n",getListSize(head));
        
                insertNode(head,7,3);
        traverseList(head);        
        printf("size : %d\n",getListSize(head));
        
                insertNode(head,2,2);
        traverseList(head);        
        printf("size : %d\n",getListSize(head));
        
                deleteNode(head,20);
        traverseList(head);
        printf("size : %d\n",getListSize(head));
        
        
        
     /**Circular Linked List Code END**/

}