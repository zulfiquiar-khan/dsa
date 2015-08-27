#include<SimpleCircularArrayQueue.h>



void testSimpleQueue(){
    
    struct SimpleQueue* queue=createSimpleQueue(5);
    displaySimpleQueue(queue);
    enqueueSimpleQueue(queue,1);
    enqueueSimpleQueue(queue,2);
    enqueueSimpleQueue(queue,3);
    enqueueSimpleQueue(queue,4);
    enqueueSimpleQueue(queue,5);
    displaySimpleQueue(queue);
    dequeueSimpleQueue(queue);
    deleteSimpleQueue(queue);
    displaySimpleQueue(queue);
    enqueueSimpleQueue(queue,6);
    enqueueSimpleQueue(queue,6);
    displaySimpleQueue(queue);

}

