#include"LinkedListQueue.h"



void testLinkedQueue(){
    
    struct LinkedQueue* queue=createLinkedQueue(5);
    displayLinkedQueue(queue);
    
    enqueueLinkedQueue(queue,1);
    enqueueLinkedQueue(queue,2);
    enqueueLinkedQueue(queue,3);
    enqueueLinkedQueue(queue,4);
    enqueueLinkedQueue(queue,5);
    
    displayLinkedQueue(queue);
    
    dequeueLinkedQueue(queue);
    dequeueLinkedQueue(queue);
    
    displayLinkedQueue(queue);
    
    enqueueLinkedQueue(queue,6);
    enqueueLinkedQueue(queue,6);
    
    displayLinkedQueue(queue);
    
    enqueueLinkedQueue(queue,7);
    enqueueLinkedQueue(queue,8);
    enqueueLinkedQueue(queue,9);
    enqueueLinkedQueue(queue,10);
    enqueueLinkedQueue(queue,9);
    
    displayLinkedQueue(queue);
   
}

