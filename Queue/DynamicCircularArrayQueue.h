#include<stdio.h>
#include<stdlib.h>

struct DynamicQueue{
    int capacity;
    int front;
    int rear;
    int *array;
};


struct DynamicQueue* createDynamicQueue(int size){
    struct DynamicQueue* queue=(struct DynamicQueue*)malloc(sizeof(struct DynamicQueue));
    if(queue==NULL){
        printf("Memory error while creating queue\n");
        return NULL;
    }
    queue->capacity=size;
    queue->front=-1;
    queue->rear=-1;
    queue->array=(int *)malloc(sizeof(int)*size);
    if(queue->array==NULL){
        printf("Memory error while creating queue\n");
        return NULL;
    }
    return queue;
}

int isEmptyDynamicQueue(struct DynamicQueue* queue){
    return (queue->front==-1);
}

int isFullDynamicQueue(struct DynamicQueue* queue){
    return ((queue->rear+1)%queue->capacity==queue->front);
}

int sizeDynamicQueue(struct DynamicQueue* queue){
    return (queue->capacity-queue->front+queue->rear+1)%queue->capacity;
}

void resizeDynamicQueue(struct DynamicQueue* queue){
    int size=queue->capacity;
    queue->capacity=queue->capacity*2;
    printf("capacity : %d ",queue->capacity);
    queue->array=(int *)realloc(queue->array,queue->capacity);
    if(queue->array==NULL){
        printf("Memory error \n");
        return;
    }
    int i=0;
    if(queue->front>queue->rear){
        for(i=0;i<queue->front;i++){
            queue->array[i+size]=queue->array[i];
        }
        queue->rear=queue->rear+size;
    }
}

void enqueueDynamicQueue(struct DynamicQueue* queue,int data){
    if(isFullDynamicQueue(queue)){
        resizeDynamicQueue(queue);
    }
    queue->rear=(queue->rear+1)%queue->capacity;
    queue->array[queue->rear]=data;
    if(queue->front==-1){
        queue->front=queue->rear;
    }
}

int dequeueDynamicQueue(struct DynamicQueue* queue){
        if(isEmptyDynamicQueue(queue)){
            printf("Queue is empty \n");
            return -1;
        }
        int data=queue->array[queue->front];
        if(queue->front==queue->rear){
            queue->front=queue->rear=-1;
        }
        else {
            queue->front=(queue->front+1)%queue->capacity;
        }
}

void deleteDynamicQueue(struct DynamicQueue* queue){
    
    if(queue!=NULL){
        if(queue->array!=NULL)
            free(queue->array);
        free(queue);
    }
    
}

void displayDynamicQueue(struct DynamicQueue*  queue){
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
