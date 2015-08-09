/*This header file includes all the plausible solution for finding the 
 * Nth node from the end of the linked list. For exampe if we have below mentioned linked list
 * 1->2->3->4->5
 * then 2nd node from end of list is 4 and we have to find that node
 * Each solution is expressed as an 
 * function.Each function in its comment also has the time and space complexities of 
 * the solution
*/

#include<stdio.h>
#include<stdlib.h>
#include"SinglyLinkedList.h"
#include"HashMap.h"

/*Time Complexity : O(n^2)
 * Space Complexity : O(1)
 */
struct singlyNode*  findNthNodeBruteForce(struct  singlyNode **head ,int n){
        struct singlyNode * temp1,*temp2,*result;
        int count=1;
        temp1=*head;
        temp2=temp1;
        int flag=0; //indicates wether the nth node has been found or not
        if(head==NULL || *head==NULL){
            printf("List is Empty\n");
        }
        else{
            while(temp1!=NULL&&flag==0){
                temp2=temp1->next;
                count=0;
                while(temp2!=NULL){
                    temp2=temp2->next;
                    count++;
                }
                if(count<n-1){printf("%d the node does not exists\n",n);result=NULL;break;}
                else if(count==n-1){result=temp1;flag=1;}
                else {result=NULL;}
                temp1=temp1->next;
            }
            return result;
        }
        
}


/*Time Complexity : O(m)
 * Space Complexity : O(m) as hash map of size m is created as extra space
 * Where m is the size of list
 */
struct singlyNode* findNthNodeHashMapStrategy(struct singlyNode **head,int n){
    int size=0;
    int count=0;
    int nthNode=0;
    struct singlyNode *temp=*head;
    struct singlyNode *result=NULL;
    hashmap *map=NULL;
    if(head==NULL||*head==NULL){
        printf("List is empty\n");
    }
    else{
        map=hashmapCreate(10);
        while(temp!=NULL){
            count++;
            hashmapInsert(map,temp,count);
            temp=temp->next;
        }
    
        nthNode=count-n+1;
        result=hashmapGet(map,nthNode);
    
        if(result==NULL){
            printf("%d node from end does not exists\n",n);
        }
    }
    return result;
}

/*Time Complexity : O(m)
 * Space Complexity : O(1) as no extra space created
 * Where m is the size of list
 */
struct singlyNode* findNthNodeCountingNodeStrategy(struct singlyNode **head,int n){
    struct  singlyNode * temp=*head;
    struct singlyNode  *result=NULL;
    int count=0;
    int size=0;
    int nthNodeFromEnd=0;
    if(head==NULL||*head==NULL){
        printf("List is empty\n");
    }
    else{
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        size=count;
        nthNodeFromEnd=size-n+1;
        if(nthNodeFromEnd<=0){
            printf("%d node from end does not exists\n");
            return result;
        }
        count=1;
        temp=*head;
        while(count<nthNodeFromEnd){
            temp=temp->next;
            count++;
        }
        
        result=temp;
        return result;
    }
}



/*Time Complexity : O(m)
 * Space Complexity : O(1) as no extra space created
 * Where m is the size of list
 */
struct singlyNode* findNthNodePointerDifferenceStrategy(struct singlyNode **head,int n){
        
    struct singlyNode *fastPtr=*head;
    struct singlyNode *slowPtr=*head;
    int counter=1;
    
    if(head==NULL||*head==NULL){
        printf("List is empty\n");
        return NULL;
    }
    
    while(counter<=n && fastPtr!=NULL){
        fastPtr=fastPtr->next;
        counter++;
    }
    
    if(counter<n+1&&fastPtr==NULL){
        printf("%d mode from the end does not exists\n");
        return NULL;
    }
    
    while(fastPtr!=NULL){
            fastPtr=fastPtr->next;
            slowPtr=slowPtr->next;
    }
            return slowPtr;
}