#include<stdio.h>
#include"SinglyLinkedList.h"
#include"HashMap.h"
#include"../Stack/DynamicArrayStack.h"

struct singlyNode* findMergingPointBruteForce(struct singlyNode** list1,struct singlyNode** list2){
    struct singlyNode* temp1=*list1;
    struct singlyNode* temp2=NULL;
    struct singlyNode* mergingNode=NULL;
    while(temp1!=NULL){
            temp2=*list2;
        printf("%d  : ",temp1->data);
        while(temp2!=NULL){
            printf("%d ",temp2->data);
            if(temp1==temp2){
                mergingNode=temp2;
                break;
            }
            temp2=temp2->next;
        }
        if(mergingNode!=NULL){break;}
        printf("\n");
        temp1=temp1->next;
    }
    return mergingNode;
}


struct singlyNode* findMergingPointHashTableStrategy(struct singlyNode** list1,struct singlyNode** list2){
    hashmap* map=hashmapCreate(20);
    struct singlyNode* temp1=*list1;
    struct singlyNode* temp2=*list2;
    struct singlyNode* mergingNode=NULL;
    while(temp1!=NULL){
        hashmapInsert(map,temp1,temp1);
        temp1=temp1->next;
    }
    
    while(temp2!=NULL){
        mergingNode=hashmapGet(map,temp2);
        if(mergingNode!=NULL){
            break;
        }
        temp2=temp2->next;
    }
    
    return mergingNode;
}


struct singlyNode* findMergingPointStackStrategy(struct singlyNode** list1,struct singlyNode** list2){
    struct singlyNode* temp1=*list1;
    struct singlyNode* temp2=*list2;
    struct Stack* stack1=createStack();
    struct Stack* stack2=createStack();
    struct singlyNode* mergingNode=NULL;
    
    while(temp1!=NULL){
        push(stack1,temp1);
        temp1=temp1->next;
    }
    
    while(temp2!=NULL){
        push(stack2,temp2);
        temp2=temp2->next;
    }
    
    while(!isEmptyStack(stack1)&&!isEmptyStack(stack2)){
        if(top(stack1)==top(stack2)){
            mergingNode=pop(stack1);
            break;
        }
        else{
            pop(stack1);
            pop(stack2);
        }
    }
    
    return mergingNode;
}


struct singlyNode* findMergingPointEfficientApproach(struct singlyNode** list1,struct singlyNode** list2){
    struct singlyNode* temp1=NULL;
    struct singlyNode* temp2=NULL;
    struct singlyNode* mergingNode=NULL;
    
    int list1Size=getListSize(list1);
    int list2Size=getListSize(list2);
    int diff=list1Size-list2Size;
    
    if(diff<0){
        temp1=*list2;
        temp2=*list1;
    }else{
        temp1=*list1;
        temp2=*list2;
    }
    int k=1;
    while(k<=diff){
        temp1=temp1->next;
        k++;
    }
    
    while(1){
        if(temp1==NULL || temp2==NULL){
            break;
        }
        if(temp1==temp2){
            mergingNode=temp1;
            break;
        }
        temp1=temp1->next;
        temp2=temp2->next;
    }

    return mergingNode;
}