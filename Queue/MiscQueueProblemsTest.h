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

void testFindPairWiseStack(){
    struct Stack* stack=createStack();
    push(stack,1);
    push(stack,2);
    push(stack,3);
    push(stack,4);
    push(stack,5);

    printf("%d ",findPairWiseStack(stack));

    stack=createStack();
    push(stack,1);
    push(stack,2);
    push(stack,3);
    push(stack,4);

    printf("%d ",findPairWiseStack(stack));
}

void testInterleaveTwoHalfsOfQueue(){
    struct SimpleQueue* queue=createSimpleQueue(6);
    enqueueSimpleQueue(queue,1);
    enqueueSimpleQueue(queue,2);
    enqueueSimpleQueue(queue,3);
    enqueueSimpleQueue(queue,4);
    enqueueSimpleQueue(queue,5);
    enqueueSimpleQueue(queue,6);
    
    interleaveTwoHalfsOfQueue(queue,6);

    displaySimpleQueue(queue);
}

void testReverseFirstKelementsOfQueue(){
    struct SimpleQueue* queue=createSimpleQueue(6);
    enqueueSimpleQueue(queue,1);
    enqueueSimpleQueue(queue,2);
    enqueueSimpleQueue(queue,3);
    enqueueSimpleQueue(queue,4);
    enqueueSimpleQueue(queue,5);
    enqueueSimpleQueue(queue,6);
    
    reverseFirstKelementsInQueue(queue,6,3);

    displaySimpleQueue(queue);

}