#include<stdio.h>
#include<stdlib.h>

struct  singlyNode{
    
    int data;
    struct  singlyNode * next;

};

//Inserts a new node at the postion passed in the parameter in the list
//Returns 1 if insertion successfull else returns 0
int insert(struct  singlyNode **head,int data,int position){
    int flag=0;
    int k=1;
    struct singlyNode *temp,*newNode;

    temp=*head;
    newNode=(struct singlyNode*)malloc(sizeof(struct singlyNode));
    newNode->data=data;
    
    if(!newNode){
        printf("Memory allocation error ... \n");
        return 0;
    }

    if(position==1){
        newNode->next=*head;
        *head=newNode;
        return 1;
    }
    
    if(position>0&&*head==NULL){
        printf("Position does not exists \n");
        return 0;
    }
    
    while((k<position-1)&&temp!=NULL){
        temp=temp->next;
        k++;
    }
    
    if(k!=position-1){
        printf("Position does not exists \n");
        return 0;
    }
    
    newNode->next=temp->next;
    temp->next=newNode;
    return 1;
}

//Deletes a node at the position passed in the parameter from the list
//Returns 1 if deletion successfull else returns 0
int deleteNode(struct singlyNode **head,int position){
    struct singlyNode *p,*q;
    int k=1;
    
    if((head==NULL)||(head!=NULL && *head==NULL)){
        printf("List is empty\n");
        return 0;
    }
    
    p=*head;
    
    //Node to be deleted is first node
    if(position==1){
        *head=p->next;
        free(p);
        return 0;
    }
    
    //Node to be delted is either last or middel node
    while((k<position)&&(p->next!=NULL)){
        q=p;
        p=p->next;
        k++;
    }
    
    if(k!=position){
        printf("Position does not exists\n");
        return 0;
    }
    
    q->next=p->next;
    free(p);
    return 1;
}

//Traverses the list and printf all the elements in each node
void traverseList(struct singlyNode **head){
    
    if((head==NULL)||(head!=NULL && *head==NULL)){
        printf("List is empty\n");
    }
    else {
        struct singlyNode *temp=*head;
        printf("List Elements : {");
        while(temp!=NULL){
            printf(" [%d ] ",temp->data);
            temp=temp->next;
        }
        printf("}\n");
    }
}


//Returns the size of list i.e total no of elements currently in the list
int getListSize(struct singlyNode **head){
    int count=0;
    if((head==NULL)||(head!=NULL && *head==NULL)){
        printf("List is empty\n");
        return count;
    }
    else {
        struct singlyNode *temp=*head;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        return count;
    }
}

//Return the nth node from list if present else return NULL
struct singlyNode* getNodeFromList(struct singlyNode  **head,int n){
    struct singlyNode *temp=*head;
    int count=1;
    
    while(count<n){
        if(temp==NULL){
            printf("%d node does not exists\n",n);
            return NULL;
        }
        temp=temp->next;
        count++;
    }
    
    return temp;
}