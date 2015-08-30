#include<stdlib.h>

struct QueueNode{
    int data;
    struct QueueNode* next;
};

struct DoublyEndedQueue{
    struct QueueNode* head;
};

struct DoublyEndedQueue* createDoublyEndedQueue(){
    struct DoublyEndedQueue* queue=(struct DoublyEndedQueue*)malloc(sizeof(struct DoublyEndedQueue));
    if(queue==NULL){
        printf("Memory error\n");
        return NULL;
    }
    queue->head=NULL;
    return queue;
}

int isEmptyDoublyEndedQueue(struct DoublyEndedQueue* queue){
    return (queue==NULL||queue->head==NULL);
}

void enqueueDoublyEndedQueueEnd(struct DoublyEndedQueue* queue,int data){
    struct QueueNode* newNode=(struct QueueNode*)malloc(sizeof(struct QueueNode));
    if(queue==NULL){
        printf("Queue is Empty\n");
        return NULL;
    }
    if(newNode==NULL){
        printf("Memory error allocating new node\n");
        return NULL;
    }
    
    newNode->next=NULL;
    newNode->data=data;
    
    if(queue->head==NULL){
        queue->head=newNode;
    }
    else{
            struct QueueNode* temp=queue->head;
            while(temp->next!=NULL){temp=temp->next;}
            temp->next=newNode;
    }
}

int dequeueDoublyEndedQueueEnd(struct DoublyEndedQueue* queue){
    int data=-1;
    if(isEmptyDoublyEndedQueue(queue)){
        printf("Queue is empty\n");
        return data;
    }
    struct QueueNode* temp1=queue->head;
    struct QueueNode* temp2=temp1;
    if(queue->head->next==NULL){
        data=queue->head->data;
        queue->head=NULL;
    }
    else{
        while(temp1->next!=NULL){
                temp2=temp1;
                temp1=temp1->next;
        }
        temp2->next=NULL;
        data=temp1->data;
        
    }

    return data;
}

void enqueueDoublyEndedQueueStart(struct DoublyEndedQueue* queue,int data){
    struct QueueNode* newNode=(struct QueueNode*)malloc(sizeof(struct QueueNode));
    if(queue==NULL){
        printf("Queue is Empty\n");
        return NULL;
    }
    if(newNode==NULL){
        printf("Memory error allocating new node\n");
        return NULL;
    }
    
    newNode->next=NULL;
    newNode->data=data;
    
    if(queue->head==NULL){
        queue->head=newNode;
    }
    else{
            struct QueueNode* temp=queue->head;
            queue->head=newNode;
            newNode->next=temp;
    }
}

int dequeueDoublyEndedQueueStart(struct DoublyEndedQueue* queue){
    int data=-1;
    if(isEmptyDoublyEndedQueue(queue)){
        printf("Queue is empty\n");
        return data;
    }
  
    data=queue->head->data;
    struct QueueNode* temp=queue->head;
    queue->head=queue->head->next;
    free(temp);
    return data;
}


void displayDoublyEndedQueue(struct DoublyEndedQueue* queue){
    if(isEmptyDoublyEndedQueue(queue)){
        printf("Queue is empty\n");
        return;
    }
    struct QueueNode* temp=queue->head;
    printf("Doubly Ended Queue : ");
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

