#include<stdlib.h>
#include"../Stack/DynamicArrayStack.h"

struct QueueUsingStack{
    struct Stack* stack1;
    struct Stack* stack2;
};

struct QueueUsingStack*   createQueueUsingStack(){
    struct QueueUsingStack* queue=(struct QueueUsingStack*)malloc(sizeof(struct QueueUsingStack));
    if(queue==NULL){
        printf("Memory error\n");
        return NULL;
    }
    
    queue->stack1=createStack();
   if(queue->stack1==NULL){
        printf("Memory error\n");
        return NULL;
    }
  
   queue->stack2=createStack();
   if(queue->stack2==NULL){
        printf("Memory error\n");
        return NULL;
    }
    
    return queue;
 
}

void enqueueQueueUsingStack(struct QueueUsingStack* queue,int data){
        //printf("going to push data %d on stack1\n",data);
        push(queue->stack1,data);
        //printf("after pushing data");
    }

int dequeueQueueUsingStack(struct QueueUsingStack* queue){
    if(isEmptyStack(queue->stack2)){
        if(isEmptyStack(queue->stack1)){
            return -1;
        }
        else{
            while(!isEmptyStack(queue->stack1)){
                push(queue->stack2,pop(queue->stack1));
            }
        }
    }
    return pop(queue->stack2);
}

void displayQueueUsingStack(struct QueueUsingStack* queue){
    if(queue==NULL || queue->stack1==NULL || queue->stack2==NULL){
        printf("Queue is empty \n");
        return;
    }
    printf("Stack1 : ");
    displayStack(queue->stack1);
    printf("Stack2 : ");
    displayStack(queue->stack2);
    printf("\n");
}

