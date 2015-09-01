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

void copyQueueToStackWithFrontAtTop(struct SimpleQueue* queue,struct Stack* stack){
    
    while(!isEmptySimpleQueue(queue)){
        push(stack,dequeueSimpleQueue(queue));
    }
    while(!isEmptyStack(stack)){
        enqueueSimpleQueue(queue,pop(stack));
    }
    
    while(!isEmptySimpleQueue(queue)){
        push(stack,dequeueSimpleQueue(queue));
    }

}


int findPairWiseStack(struct Stack* stack){
    if(isEmptyStack(stack)){
        printf("Stack is Empty\n");
        return -1;
    }
    struct SimpleQueue* queue=createSimpleQueue(size(stack));
    int pairWiseFlag=1;
    if(queue==NULL){
        printf("Error creating queue\n");
        return -1;
    }
    while(!isEmptyStack(stack)){
        enqueueSimpleQueue(queue,pop(stack));
    }
    while(!isEmptySimpleQueue(queue)){
        push(stack,dequeueSimpleQueue(queue));
    }
    while(!isEmptyStack(stack)){
        int n=pop(stack);
        enqueueSimpleQueue(queue,n);
        if(!isEmptyStack(stack)){
            int p=pop(stack);
            if(abs(n-p)!=1){
                pairWiseFlag=0;
            }
        }
    }
    while(!isEmptySimpleQueue(queue)){
        push(stack,dequeueSimpleQueue(queue));
    }
    
    return pairWiseFlag;
}

void interleaveTwoHalfsOfQueue(struct SimpleQueue* queue,int  size){
    if(queue==NULL||size%2!=0){
        return ;
    }
    
    int halfSize=size/2;
    int i=0;
    struct Stack* stack=createStack();
    while(i<halfSize){
        push(stack,dequeueSimpleQueue(queue));
        i++;
    }
    while(!isEmptyStack(stack)){
        enqueueSimpleQueue(queue,pop(stack));
    }
    i=0;
    while(i<halfSize){
        enqueueSimpleQueue(queue,dequeueSimpleQueue(queue));
        i++;
    }
    i=0;
    while(i<halfSize){
        push(stack,dequeueSimpleQueue(queue));
        i++;
    }
    while(!isEmptyStack(stack)){
        enqueueSimpleQueue(queue,pop(stack));
        enqueueSimpleQueue(queue,dequeueSimpleQueue(queue));
    }
}

void reverseFirstKelementsInQueue(struct SimpleQueue* queue,int size,int k){
    if(queue==NULL||k>size){
        return;
    }
    
    struct Stack* stack=createStack();
    int i=0;
    while(i<k){
        push(stack,dequeueSimpleQueue(queue));
        i++;
    }
    while(!isEmptyStack(stack)){
        enqueueSimpleQueue(queue,pop(stack));
    }
    i=0;
    while(i<(size-k)){
        enqueueSimpleQueue(queue,dequeueSimpleQueue(queue));
        i++;
 }
    
}