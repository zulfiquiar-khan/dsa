#include<stdio.h>
#include<stdlib.h>
#include"DoublyLinkedList.h"

void testDoublyLinkedList(){
        
      /**Doubly Linked List Code START**/ 
    struct   doublyNode *header;
    struct   doublyNode  **head;
    header=NULL;
    head=&header;
    
    insertNode(head,1,1);
    traverseList(head);
    printf("size : %d\n",getListSize(head));
    
    insertNode(head,2,2);
    traverseList(head);
    printf("size : %d\n",getListSize(head));
    
    insertNode(head,3,3);
    traverseList(head);
    printf("size : %d\n",getListSize(head));
    
    insertNode(head,4,4);
    traverseList(head);
    printf("size : %d\n",getListSize(head));
    
    insertNode(head,5,2);
    traverseList(head);
    printf("size : %d\n",getListSize(head));
    
    insertNode(head,6,1);
    traverseList(head);
    printf("size : %d\n",getListSize(head));
    
    insertNode(head,8,8);
    traverseList(head);
    printf("size : %d\n",getListSize(head));
    
    printf(" deleteNode(head,6)\n");
    deleteNode(head,6);
    traverseList(head);
    printf("size : %d\n",getListSize(head));
    
     printf(" deleteNode(head,1)\n");
    deleteNode(head,1);
    traverseList(head);
    printf("size : %d\n",getListSize(head));
    
     printf(" deleteNode(head,1)\n");
    deleteNode(head,1);
    traverseList(head);
    printf("size : %d\n",getListSize(head));
    
     printf(" deleteNode(head,3)\n");
    deleteNode(head,3);
    traverseList(head);
    printf("size : %d\n",getListSize(head));
    
     printf(" deleteNode(head,2)\n");
    deleteNode(head,2);
    traverseList(head);
    printf("size : %d\n",getListSize(head));;
    
     printf(" deleteNode(head,1)\n");
    deleteNode(head,1);
    traverseList(head);
    printf("size : %d\n",getListSize(head));
    
     printf(" deleteNode(head,1)\n");
    deleteNode(head,1);
    traverseList(head);
    printf("size : %d\n",getListSize(head));
    /**Doubly Linked List Code  END**/


}