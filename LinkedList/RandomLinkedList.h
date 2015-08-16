#include<stdio.h>
#include<stdlib.h>


struct randomNode{
    int data;
    struct randomNode* next;
    struct randomNode* random;
};


int insertInRandomList(struct randomNode**head,int data,int position){
    
    int flag=0;
    int k=1;
    struct randomNode *temp,*newNode;

    temp=*head;
    newNode=(struct randomNode*)malloc(sizeof(struct randomNode));
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


//Return the nth node from list if present else return NULL
struct randomNode* getNodeFromRandomList(struct randomNode  **head,int n){
    struct randomNode *temp=*head;
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



struct  randomNode** createRandomList(){
    struct  singlyNode *header;
    struct singlyNode **head;
    header=NULL;
    head=&header;
    
    insertInRandomList(head,1,1);
    insertInRandomList(head,2,2);
    insertInRandomList(head,3,3);
    insertInRandomList(head,4,4);
    insertInRandomList(head,5,5);
                
    struct randomNode *temp1=getNodeFromRandomList(head,1);
    struct randomNode* temp2=getNodeFromRandomList(head,5);
    temp1->random=temp2;
    
    temp1=getNodeFromRandomList(head,2);
    temp2=getNodeFromRandomList(head,4);
    temp1->random=temp2;
    
    temp1=getNodeFromRandomList(head,3);
    temp2=getNodeFromRandomList(head,5);
    temp1->random=temp2;
    
    temp1=getNodeFromRandomList(head,4);
    temp2=getNodeFromRandomList(head,1);
    temp1->random=temp2;

    temp1=getNodeFromRandomList(head,5);
    temp2=getNodeFromRandomList(head,2);
    temp1->random=temp2;
    
    temp1=getNodeFromRandomList(head,5);
    temp1->next=NULL;
    
    printf("Random List created successfully\n");
        
    traverseRandomList(head);   
    
    return head;
}


void traverseRandomList(struct randomNode** head){
    

    if((head==NULL)||(head!=NULL && *head==NULL)){
        printf("List is empty\n");
    }
    else {
        struct randomNode *temp=*head;
        printf("List Elements : {");
        while(temp!=NULL){
            printf(" ( [%d ] -- [%d] ) -> ",temp->data,temp->random->data);
            temp=temp->next;
        }
        printf("}\n");
    }

}