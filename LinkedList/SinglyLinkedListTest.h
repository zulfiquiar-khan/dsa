#include<stdio.h>
#include<stdlib.h>
#include"SinglyLinkedList.h"

void testSinglyLinkedList()
{
    
    /**Singly Linked List Code START**/
    struct  singlyNode *header;
    struct singlyNode **head;
    header=NULL;
    head=&header;
    
    
    
    insert(head,1,1);
    traverseList(head);
    printf("Size : %d\n",getListSize(head));
    
    insert(head,2,2);
    traverseList(head);
    printf("Size : %d\n",getListSize(head));
    
    insert(head,3,3);
    traverseList(head);
    printf("Size : %d\n",getListSize(head));
    
    insert(head,4,4);
    traverseList(head);
    printf("Size : %d\n",getListSize(head));
    
    insert(head,5,3);
    traverseList(head);
    printf("Size : %d\n",getListSize(head));
    
    printf("deleteNode(head,1)\n");
    deleteNode(head,1);
    traverseList(head);
    printf("Size : %d\n",getListSize(head));
    
     printf("deleteNode(head,4)\n");
    deleteNode(head,4);
    traverseList(head); 
    printf("Size : %d\n",getListSize(head));
    
     printf("deleteNode(head,2)\n");
    deleteNode(head,2);
    traverseList(head);   
    printf("Size : %d\n",getListSize(head));
    
     printf("deleteNode(head,2)\n");
    deleteNode(head,2);
    traverseList(head);   
    printf("Size : %d\n",getListSize(head));
    
     printf("deleteNode(head,2)\n");
    deleteNode(head,2);
    traverseList(head);   
    printf("Size : %d\n",getListSize(head));
    
     printf("deleteNode(head,1)\n");
    deleteNode(head,1);
    traverseList(head);   
    printf("Size : %d\n",getListSize(head));
    
    
     printf("deleteNode(head,1)\n");
    deleteNode(head,1);
    traverseList(head);   
    printf("Size : %d\n",getListSize(head));

       /**Singly Linked List Code END**/


}