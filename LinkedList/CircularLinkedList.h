#include<stdio.h>
#include<stdlib.h>


struct circularNode{
    int data;
    struct circularNode* next;
};

int insertNode(struct circularNode  **head,int data,int position){
    struct circularNode *temp,*newNode;
    temp=*head;
    int k=1;
    newNode=(struct circularNode *)malloc(sizeof(struct circularNode));
    if(!newNode){
        printf("Memory allocation error\n");
        return 0;
    }
    
    newNode->data=data;
    
    if(position==1){
        if(temp!=NULL){
            while(temp->next!=*head){
                temp=temp->next;
            }
            newNode->next=*head;
            temp->next=newNode;
            *head=newNode;
        }
        else{
            newNode->next=newNode;
            *head=newNode;
        }
        return 1;
    }
    
    while((k<position-1)&&(temp->next!=*head)){
        k++;
        temp=temp->next;
    }
    
    if(k!=position-1){
        printf("Position does not exists\n");
        return 0;
    }
    
    newNode->next=temp->next;
    temp->next=newNode;
    
}


int deleteNode(struct circularNode **head,int position){
    struct circularNode *temp=*head;
    int k=1;
    
    if((head==NULL)||(head!=NULL && *head==NULL)){
        printf("List is empty\n");
        return 0;
    }
    
    if(position==1){
        if(temp->next==*head){
            *head=NULL;
            free(temp);
            return 1;
        }
        while(temp->next!=*head){
            temp=temp->next;
        }
        temp->next=(*head)->next;
        *head=(*head)->next;
        return 1;
    }
    
    while((k<position-1)&&(temp->next!=*head)){
        k++;
        temp=temp->next;
    }
    
    if(k!=position-1){
        printf("Position does not exists\n");
        return 0;
    }
    
/*    if(temp->next->next==*head){
        free(temp->next);
        temp->next=*head;
    }*/
    struct circularNode *temp1=temp->next;
    temp->next=temp->next->next;
    free(temp1);
    return 1;
}


//Traverses the list and printf all the elements in each node
void traverseList(struct circularNode **head){
    
    if((head==NULL)||(head!=NULL && *head==NULL)){
        printf("List is empty\n");
    }
    else {
        struct circularNode *temp=*head;
        printf("List Elements : {");
       do{
            printf(" [%d ] ",temp->data);
            temp=temp->next;
        }while(temp!=*head);
        printf("}\n");
    }
}


//Returns the size of list i.e total no of elements currently in the list
int getListSize(struct circularNode **head){
    int count=0;
    if((head==NULL)||(head!=NULL && *head==NULL)){
        printf("List is empty\n");
        return count;
    }
    else {
        struct circularNode *temp=*head;
        do{
            count++;
            temp=temp->next;
        }while(temp!=*head);
        return count;
    }
}