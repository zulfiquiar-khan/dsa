#include<stdlib.h>

struct QueueNode{
    int data;
    struct QueueNode* next;
};

struct LinkedQueue{
    struct QueueNode* front;
    struct QueueNode* rear;
};


struct LinkedQueue* createLinkedQueue(){
    struct LinkedQueue* queue;
    queue=(struct LinkedQueue*)malloc(sizeof(struct LinkedQueue));
    if(queue==NULL){
        printf("Memory error\n");
        return NULL;
    }
    queue->front=NULL;
    queue->rear=NULL;
    
    return queue;
}

int isEmptyLinkedQueue(struct LinkedQueue* queue){
    return (queue->front==NULL);
}


void enqueueLinkedQueue(struct LinkedQueue* queue,int data){
    struct QueueNode* temp=(struct QueueNode*)malloc(sizeof(struct QueueNode));
    if(temp==NULL){
        printf("Memory error\n");
        return;
    }
    temp->data=data;
    temp->next=NULL;
    if(queue->rear==NULL){
                queue->rear=temp;
    }
    else{
        queue->rear->next=temp;
        queue->rear=queue->rear->next;
    }
    
    if(queue->front==NULL){
        queue->front=queue->rear;
    }

}

int dequeueLinkedQueue(struct LinkedQueue* queue){
    struct QueueNode* temp=NULL;
    if(queue==NULL || isEmptyLinkedQueue(queue)){
        return -1;
    }
    int data=queue->front->data;
    temp=queue->front;
    queue->front=queue->front->next;
    free(temp);
    return data;
}

int sizeLinkedQueue(struct LinkedQueue* queue){
        struct QueueNode* temp=queue->front;
        int size=0;
        while(temp!=NULL){
                temp=temp->next;
                size++;
        }
}

void deleteLinkedQueue(struct LinkedQueue* queue){
        struct QueueNode* temp=queue->front;
        struct QueueNode* temp2=NULL;
        while(temp!=NULL){
            temp2=temp->next;
            free(temp);
            temp=temp2;
        }
        free(queue);
}
    
void displayLinkedQueue(struct LinkedQueue* queue){
        struct QueueNode* temp=queue->front;
        printf("Queue : ");
        while(temp!=NULL){
                printf(" %d ",temp->data);
                temp=temp->next;
        }
        printf("\n");
}