#include"QueueUsingTwoStacks.h"

void testQueueUsingTwoStacks(){
    
    struct QueueUsingStack* queue=createQueueUsingStack();
    
    //displayQueueUsingStack(queue);
    
    enqueueQueueUsingStack(queue,1);
    enqueueQueueUsingStack(queue,2);
    enqueueQueueUsingStack(queue,3);
    enqueueQueueUsingStack(queue,4);
    enqueueQueueUsingStack(queue,5);
    
    displayQueueUsingStack(queue);
    
    dequeueQueueUsingStack(queue);
    dequeueQueueUsingStack(queue);
    
    displayQueueUsingStack(queue);
    
    dequeueQueueUsingStack(queue);
    dequeueQueueUsingStack(queue);
    
    displayQueueUsingStack(queue);

}

