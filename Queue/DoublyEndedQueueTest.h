#include"DoublyEndedQueue.h"

void testDoublyEndedQueue(){
    struct DoublyEndedQueue* queue=createDoublyEndedQueue();
   
    enqueueDoublyEndedQueueEnd(queue,1);
    displayDoublyEndedQueue(queue);
    enqueueDoublyEndedQueueEnd(queue,2);
    displayDoublyEndedQueue(queue);
    enqueueDoublyEndedQueueEnd(queue,3);
    displayDoublyEndedQueue(queue);
    enqueueDoublyEndedQueueEnd(queue,4);
    displayDoublyEndedQueue(queue);
    
    dequeueDoublyEndedQueueEnd(queue);
    displayDoublyEndedQueue(queue);
    dequeueDoublyEndedQueueEnd(queue);
    displayDoublyEndedQueue(queue);
    dequeueDoublyEndedQueueEnd(queue);
    displayDoublyEndedQueue(queue);
    dequeueDoublyEndedQueueEnd(queue);
    displayDoublyEndedQueue(queue);
    dequeueDoublyEndedQueueEnd(queue);
    displayDoublyEndedQueue(queue);
    
    queue=createDoublyEndedQueue();
    
    enqueueDoublyEndedQueueStart(queue,1);
    displayDoublyEndedQueue(queue);
    enqueueDoublyEndedQueueStart(queue,2);
    displayDoublyEndedQueue(queue);
    enqueueDoublyEndedQueueStart(queue,3);
    displayDoublyEndedQueue(queue);
    enqueueDoublyEndedQueueStart(queue,4);
    displayDoublyEndedQueue(queue);
    
    dequeueDoublyEndedQueueStart(queue);
    displayDoublyEndedQueue(queue);
    dequeueDoublyEndedQueueStart(queue);
    displayDoublyEndedQueue(queue);
    dequeueDoublyEndedQueueStart(queue);
    displayDoublyEndedQueue(queue);
    dequeueDoublyEndedQueueStart(queue);
    displayDoublyEndedQueue(queue);
    dequeueDoublyEndedQueueStart(queue);
    displayDoublyEndedQueue(queue);
    
    queue=createDoublyEndedQueue();
    enqueueDoublyEndedQueueStart(queue,1);
    displayDoublyEndedQueue(queue);
    enqueueDoublyEndedQueueEnd(queue,2);
    displayDoublyEndedQueue(queue);
    enqueueDoublyEndedQueueEnd(queue,3);
    displayDoublyEndedQueue(queue);
    enqueueDoublyEndedQueueStart(queue,4);
    displayDoublyEndedQueue(queue);
    
    dequeueDoublyEndedQueueStart(queue);
    displayDoublyEndedQueue(queue);
    dequeueDoublyEndedQueueEnd(queue);
    displayDoublyEndedQueue(queue);
    dequeueDoublyEndedQueueStart(queue);
    displayDoublyEndedQueue(queue);
    dequeueDoublyEndedQueueEnd(queue);
    displayDoublyEndedQueue(queue);
    dequeueDoublyEndedQueueStart(queue);
    displayDoublyEndedQueue(queue);
            
}