#include"DynamicCircularArrayQueue.h"



void testDynamicQueue(){
    
    struct DynamicQueue* queue=createDynamicQueue(5);
    displayDynamicQueue(queue);
    
    enqueueDynamicQueue(queue,1);
    enqueueDynamicQueue(queue,2);
    enqueueDynamicQueue(queue,3);
    enqueueDynamicQueue(queue,4);
    enqueueDynamicQueue(queue,5);
    
    displayDynamicQueue(queue);
    
    dequeueDynamicQueue(queue);
    dequeueDynamicQueue(queue);
    
    displayDynamicQueue(queue);
    
    enqueueDynamicQueue(queue,6);
    enqueueDynamicQueue(queue,6);
    
    displayDynamicQueue(queue);
    
    enqueueDynamicQueue(queue,7);
    enqueueDynamicQueue(queue,8);
    enqueueDynamicQueue(queue,9);
    enqueueDynamicQueue(queue,10);
    enqueueDynamicQueue(queue,9);
    
    displayDynamicQueue(queue);
   
}

