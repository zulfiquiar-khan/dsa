#include<stdio.h>
#include<stdlib.h>


struct SimpleQueue{
    int rear;
    int front;
    int capacity;
    int *array;
    
};

struct SimpleQueue* createSimpleQueue(int size){
            struct SimpleQueue* queue=(struct SimpleQueue*)malloc(sizeof(struct SimpleQueue));
            if(queue==NULL){
                printf("Memory error while creating queue\n");
                return NULL;
            }
            queue->front=-1;
            queue->rear=-1;
            queue->capacity=size;
            queue->array=(int *)malloc(sizeof(int)*size);
            if(queue->array==NULL){
                printf("Memory error while creating queue\n");
                return NULL;
            }
            return queue;
}


int isEmptySimpleQueue(struct SimpleQueue* queue){
    return (queue->front==-1);
}

int isFullSimpleQueue(struct SimpleQueue* queue){
    return ((queue->rear+1)%queue->capacity==queue->front);
}


int sizeSimpleQueue(struct SimpleQueue* queue){
    return (queue->capacity-queue->front+queue->rear+1)%queue->capacity;
}

void enqueueSimpleQueue(struct SimpleQueue* queue,int data){
    if(isFullSimpleQueue(queue)){
        printf("Queue is full\n");
    }
    else {
        queue->rear=(queue->rear+1)%queue->capacity;
        queue->array[queue->rear]=data;
        if(queue->front==-1){
            queue->front=queue->rear;
        }
    }
}

int dequeueSimpleQueue(struct SimpleQueue* queue){
        if(isEmptySimpleQueue(queue)){
            printf("Queue is empty\n");
            return 0;
        }
        
        int data=queue->array[queue->front];
        if(queue->front==queue->rear){
            queue->front=queue->rear=-1;
        }
        else{
           // printf("front : %d front+1 : %d front man : %d ",queue->front,queue->front+1,((queue->front)+1)%queue->capacity);
            queue->front=((queue->front)+1)%queue->capacity;
            //printf("front : %d \n",queue->front);
        }
        
}

void deleteSimpleQueue(struct SimpleQueue* queue){
    
    if(queue!=NULL){
        if(queue->array!=NULL)
            free(queue->array);
        free(queue);
    }
    
}

void displaySimpleQueue(struct SimpleQueue*  queue){
    int i=0;
    if(queue==NULL||queue->array==NULL){
        printf("Queue is empty\n");
    }
    else {
        printf("Queue rear : %d  front :  %d  data : ",queue->rear,queue->front);
        while(i<queue->capacity){
            printf(" %d ",queue->array[i]);
            i++;
        }
        printf("\n");
    }
}