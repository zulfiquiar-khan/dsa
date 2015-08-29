#include"MiscQueueProblems.h"


void testReverseQueueUsingStack(){
    struct SimpleQueue* queue=createSimpleQueue(5);
    displaySimpleQueue(queue);
    enqueueSimpleQueue(queue,1);
    enqueueSimpleQueue(queue,2);
    enqueueSimpleQueue(queue,3);
    enqueueSimpleQueue(queue,4);
    enqueueSimpleQueue(queue,5);
    displaySimpleQueue(queue);
    reverseAqueueUsingStack(queue);
    displaySimpleQueue(queue);
}