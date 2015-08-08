#include <stdio.h>
#include<CircularLinkedList.h>

int main(int argc, char **argv)
{
	
    
    /**Singly Linked List Code START**/
/*    struct  singlyNode *header;
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
    printf("Size : %d\n",getListSize(head));*/

       /**Singly Linked List Code END**/
       
      /**Doubly Linked List Code START**/ 
/*    struct   doublyNode *header;
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
    printf("size : %d\n",getListSize(head));*/
    /**Doubly Linked List Code  END**/
    
    
    
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
	return 0;
}
