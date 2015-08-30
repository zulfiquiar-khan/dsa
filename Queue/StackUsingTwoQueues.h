#include<stdlib.h>
#include"LinkedListQueue.h"


struct StackUsingQueue{
    struct LinkedQueue* queue1;
    struct LinkedQueue* queue2;
};

struct StackUsingQueue* createStackUsingQueue(){
    struct StackUsingQueue* stack=(struct StackUsingQueue*)malloc(sizeof(struct StackUsingQueue));
    if(stack==NULL){
        printf("Memory error in stack\n");
        return NULL;
    }
    stack->queue1=createLinkedQueue();
    if(stack->queue1==NULL){
        printf("Memory error in queue1\n");
        return NULL;
    }   
 stack->queue2=createLinkedQueue();
    if(stack->queue2==NULL){
        printf("Memory error in queue2\n");
        return NULL;
    }
    return stack;
}


void push(struct StackUsingQueue* stack,int data){
    if(isEmptyLinkedQueue(stack->queue2)){
        enqueueLinkedQueue(stack->queue1,data);
    }
    else {
        enqueueLinkedQueue(stack->queue2,data);
    }
}

int pop(struct StackUsingQueue* stack){
    if(isEmptyLinkedQueue(stack->queue1)&&isEmptyLinkedQueue(stack->queue2)){
        printf("Stack is empty\n");
        return -1;
    }
        int i=0;
        int size=0;
        int data=-1;
    if(!isEmptyLinkedQueue(stack->queue1)){
            size=sizeLinkedQueue(stack->queue1);
            while(i<size-1){
                enqueueLinkedQueue(stack->queue2,dequeueLinkedQueue(stack->queue1));
                i++;
            }
            data=dequeueLinkedQueue(stack->queue1);
    }
    else{
            size=sizeLinkedQueue(stack->queue2);
            while(i<size-1){
                enqueueLinkedQueue(stack->queue1,dequeueLinkedQueue(stack->queue2));
                i++;
            }
            data=dequeueLinkedQueue(stack->queue2);        
    }
    return data;
}