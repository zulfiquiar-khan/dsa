#include<stdlib.h>
#include"../Stack/DynamicArrayStack.h"
#include"SimpleCircularArrayQueue.h"


void reverseAqueueUsingStack(struct SimpleQueue* queue){
    struct Stack* stack=createStack();
    int data=0;
    printf("queue in  routine\n");
    displaySimpleQueue(queue);
    printf("init data : %d\n",data);
    while(!isEmptySimpleQueue(queue)){
        data=dequeueSimpleQueue(queue);
        printf("data : %d\n",data);
        push(stack,data);
    }
    displayStack(stack);
    while(!isEmptyStack(stack)){
        data=pop(stack);
        enqueueSimpleQueue(queue,data);
    }
}
