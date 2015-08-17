#include<stdio.h>
#include<stdlib.h>
#include"SinglyLinkedList.h"
//#include"CircularLinkedList.h"

struct singlyNode*  insertNodeInSortedList(struct singlyNode *head,struct singlyNode* newNode){
    struct singlyNode *current=head,*temp=NULL;
    if(!head){
            return newNode;
    }
    while(current!=NULL && current->data<newNode->data){
        temp=current;
        current=current->next;
    }
    newNode->next=current;
    if(temp!=NULL)temp->next=newNode;
    else head=newNode;
    
    return head;
}


struct singlyNode*  reverseListRecursiveVersion(struct singlyNode*head){
        struct singlyNode* secondNode=NULL;
        struct singlyNode *reversedList=NULL;
        if(head==NULL){return NULL;}
        if(head->next==NULL){return head;}
        
        secondNode=head->next;
        head->next=NULL;
        reversedList=reverseListRecursiveVersion(secondNode);
        secondNode->next=head;
        return reversedList;
}


struct singlyNode* reverseListIterativeVersion(struct singlyNode *head){
    struct singlyNode* temp=NULL;
    struct singlyNode* nextNode=NULL;
    while(head!=NULL){
        nextNode=head->next;
        head->next=temp;
        temp=head;
        head=nextNode;
    }
    return temp;
}


void traverseLinkedListFromEndToStart(struct singlyNode* head){
    struct singlyNode* temp=head;
    if(head==NULL){
        return ;
    }
    traverseLinkedListFromEndToStart(temp->next);
    printf("%u->%d \n",temp,temp->data);
}


int findWetherListIsEvenOrOdd(struct singlyNode** head){
    struct singlyNode* temp=*head;
    int flag=0; //0 means odd 1 means even
    
    while(temp!=NULL&&temp->next!=NULL){
        temp=temp->next->next;
    }
    if(temp==NULL){
        flag=1;
    }
    return flag;
}




struct singlyNode** mergeTwoSortedListInSortedOrderIterative(struct singlyNode** head1,struct singlyNode** head2){
    struct singlyNode* first1=*head1;
    struct singlyNode* first2=*head2;
    struct singlyNode* newNode=(struct singlyNode*) malloc(sizeof(struct singlyNode));
    struct singlyNode* temp=newNode;
    struct singlyNode* prevTemp=NULL;
    temp->next=NULL;
    
    while(first1!=NULL && first2!=NULL){
        if(first1->data<=first2->data){
            temp->next=first1;
            temp=temp->next;
            first1=first1->next;
        }
        else{
                   temp->next=first2;
                    temp=temp->next;
                    first2=first2->next;
        }
    }
    
    if(first1==NULL){
            temp->next=first2;
        }
    else{
        temp->next=first1;
    }
    
    temp=newNode;
    temp=temp->next;
    free(newNode);
    
    return &temp;
}


struct singlyNode* mergeTwoSortedListInSortedOrderRecursive(struct singlyNode* a,struct singlyNode* b){
    struct  singlyNode* result=NULL;
    if(a==NULL){return b;}
    if(b==NULL){return a;}
    if(a->data<=b->data){
        result=a;
        result->next=mergeTwoSortedListInSortedOrderRecursive(a->next,b);
    }
    else {
        result=b;
        result->next=mergeTwoSortedListInSortedOrderRecursive(a,b->next);
    }

    return result;
}

struct  singlyNode*  reverseLinkedListInPairsRecursive(struct singlyNode* head){
    struct singlyNode* temp=head;
    if(temp==NULL){
        return NULL;
    }
    if(temp->next==NULL){
        return temp;
    }
    
    temp=temp->next;
    head->next=temp->next;
    temp->next=head;
    head=temp;

    head->next->next=reverseLinkedListInPairsRecursive(head->next->next);
    
    return head;

}


struct singlyNode* reverseLinkedListInPairsIterative(struct singlyNode **head){
    struct singlyNode* temp1=NULL;
    struct singlyNode* temp2=NULL;
    struct singlyNode* current=*head;
    
    while(current!=NULL && current->next!=NULL){
        if(temp1!=NULL){
            temp1->next->next=current->next;
        }
        
        temp1=current->next;
        current->next=current->next->next;
        temp1->next=current;
        current=current->next;
        
        if(temp2==NULL){
            temp2=temp1;
        }
    }
            return temp2;
    }

int checkIfAlistIsPalindrome(struct singlyNode** head){
    
    struct singlyNode* fastPtr=*head;
    struct singlyNode* slowPtr=*head;
     struct singlyNode* list1=*head;
    struct singlyNode* list2=NULL;
    while(fastPtr->next!=NULL&&fastPtr->next->next!=NULL){
        fastPtr=fastPtr->next->next;
        slowPtr=slowPtr->next;
    }
                printf("%d \n",slowPtr->data);
                list2=slowPtr->next;
                list2=reverseListIterativeVersion(list2);
                slowPtr->next=list2;
                slowPtr=slowPtr->next;

                int flag=1;
                
                printf("%d \n",slowPtr->data);
                
                traverseList(&list1);
                traverseList(&list2);
                
                while(list1!=NULL&&list2!=NULL&&list1!=slowPtr){
                    printf("list1 : %d list2 : %d\n",list1->data,list2->data);
                        if(list1->data!=list2->data){
                            flag=0;
                            break;
                        }
                        list1=list1->next;
                        list2=list2->next;
                        printf("list1 test : %d   list2 test : %d\n",list1!=slowPtr,list2!=NULL);
                }
                
                return flag;
}


struct singlyNode** getKPlusOnethNode(struct singlyNode* head,int k){
    struct singlyNode* kthNode=head;
    int i=1;
    
    while(kthNode!=NULL && i<k){
            kthNode=kthNode->next;
            i++;
    }
    
    if(kthNode!=NULL){
        return kthNode->next;
    }
    return NULL;
}

int hasKNodes(struct singlyNode* head,int k){
    struct singlyNode* temp=head;
    int i=1;
    while(temp!=NULL && i<k){
            temp=temp->next;
            i++;
    }
    if(temp!=NULL && i==k){
            return 1;
    }
    return 0;
}

struct singlyNode* reverseBlockofNodesInLinkedList(struct singlyNode** head,int k ){
    struct  singlyNode* temp;
    struct  singlyNode* curr=*head;
    struct  singlyNode* newHead;
    struct  singlyNode* before=NULL;
    struct  singlyNode* next;
    
    if(k==0||k==1){
        return *head;
    }
    if(!hasKNodes(curr,k)){
        return *head;
    }
    else {
            newHead=getKPlusOnethNode(curr,k-1);
    }
    
    while(curr!=NULL && hasKNodes(curr,k)){
            temp=getKPlusOnethNode(curr,k);
            int i=0;
            while(i<k){
                    next=curr->next;
                    curr->next=temp;
                    temp=curr;
                    curr=next;
                    i++;

            }
            if(before!=NULL){
                before->next=temp;
            }
              before=getKPlusOnethNode(temp,k-1);
            traverseList(&newHead);
    }
    
    return newHead;
}


struct singlyNode* findLastModularNodeFromStart(struct singlyNode* head,int k){
    struct singlyNode* modularNode=NULL;
    if(head==NULL || k<=0){
        return NULL;
    }
    
    int i=1;
    
    while(head!=NULL){
        if(i%k==0){modularNode=head;}
        head=head->next;
        i++;
    }
    
    return modularNode;

}


struct singlyNode* findFractionalNode(struct singlyNode* head,int k){
    struct singlyNode* fractionalNode=NULL;
    int i=0;
    if(k<=0){
        return NULL;
    }
    while(head!=NULL){
        printf("i : %d  k: %d  head : %d\n",i,k,head->data);
        if(i%k==0){
            if(fractionalNode==NULL){
                printf("fractional node : %d\n",head->data);
                fractionalNode=head;
            }
            else{
                fractionalNode=fractionalNode->next;
                printf("moved fractional node : %d\n",fractionalNode->data);
            }
        }
        head=head->next;
        i++;
    }
    return fractionalNode;
}

struct singlyNode* findSquareRootNodeInList(struct singlyNode* head){
    struct singlyNode* sqrtNode=NULL;
    int i=1,j=1;
    
    while(head!=NULL){
        printf("i : %d  j: %d  head : %d \n",i,j,head->data);
        if(i==j*j){
            if(sqrtNode==NULL){
                sqrtNode=head;
                printf("sqrt : %d\n",sqrtNode->data);
        }
            else{
                sqrtNode=sqrtNode->next;
                printf("moved sqrt : %d\n",sqrtNode->data);
            }
            j++;
        }
        i++;
        head=head->next;
    }
    return sqrtNode;
}