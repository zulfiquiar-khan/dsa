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

void testCopyQueueToStackWithFrontAtTop(){
    struct SimpleQueue* queue=createSimpleQueue(5);
    struct Stack* stack=createStack();
    displaySimpleQueue(queue);
    enqueueSimpleQueue(queue,1);
    enqueueSimpleQueue(queue,2);
    enqueueSimpleQueue(queue,3);
    enqueueSimpleQueue(queue,4);
    enqueueSimpleQueue(queue,5);
    displaySimpleQueue(queue);
    copyQueueToStackWithFrontAtTop(queue,stack);
    displaySimpleQueue(queue);
    displayStack(stack);

}