#include<stdio.h>
#include<stdlib.h>


struct doublyNode{
    int data;
    struct doublyNode *next;
    struct doublyNode *prev;
};

//Inserts a new node at the postion passed in the parameter in the list
//Returns 1 if insertion successfull else returns 0
int insertNode(struct doublyNode **head,int data,int position){
    struct doublyNode *temp,*newNode;
    int k=1;
    temp=*head;
    newNode=(struct doublyNode *)malloc(sizeof(struct doublyNode));
    if(!newNode){
        printf("Memory allocation error \n");
        return 0;
    }
    
    newNode->data=data;
    newNode->next=newNode;
    if(position==1){
        newNode->prev=NULL;
        newNode->next=temp;
        if(temp!=NULL)
            temp->prev=newNode;
        *head=newNode;
        return 1;
    }
    
    while((k<position-1)&&(temp->next!=NULL)){
        temp=temp->next;
        k++;
    }
    
    if(k!=position-1){
        printf("Position does not exists\n");
        return 0;
    }
    
    newNode->prev=temp;
    newNode->next=temp->next;
    if(temp->next!=NULL){
        temp->next->prev=newNode;
    }
    temp->next=newNode;
    return 1;
}

//Deletes node at the postion passed in the parameter in the list
//Returns 1 if insertion successfull else returns 0
int deleteNode(struct  doublyNode **head,int position){
    
    struct doublyNode *temp=*head;
    int k=1;
    if((head==NULL)||(head!=NULL && *head==NULL)){
        printf("List is empty\n");
        return 0;
    }
    
    if(position==1){
        if(temp->next!=NULL){
            temp->next->prev=NULL;
        }
        *head=temp->next;
        free(temp);
        return 1;
    }
    
    while((k<position)&&(temp!=NULL)){
        k++;
        temp=temp->next;
    }
    
    if(k!=position){
        printf("Position does not exists\n");
        return 0;
    }
    
    if(temp->next!=NULL){
        temp->next->prev=temp->prev;
    }
    temp->prev->next=temp->next;
    free(temp);
    return 1;
    
}


//Traverses the list and printf all the elements in each node
void traverseList(struct doublyNode **head){
    
    if((head==NULL)||(head!=NULL && *head==NULL)){
        printf("List is empty\n");
    }
    else {
        struct doublyNode *temp=*head;
        printf("List Elements : {");
        while(temp!=NULL){
            printf(" [%d ] ",temp->data);
            temp=temp->next;
        }
        printf("}\n");
    }
}


//Returns the size of list i.e total no of elements currently in the list
int getListSize(struct doublyNode **head){
    int count=0;
    if((head==NULL)||(head!=NULL && *head==NULL)){
        printf("List is empty\n");
        return count;
    }
    else {
        struct doublyNode *temp=*head;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        return count;
    }
}