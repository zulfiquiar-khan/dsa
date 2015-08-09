#include<stdio.h>
#include<stdlib.h>
#include"SinglyLinkedList.h"
#include"HashMap.h"

/*Finds wether a list has cycle or not using hash map
 * Return 0 if no cycle is present
 * Return 1 if cycle is present 
 * Return -1 in case of any error
 * 
 * Time Complexity :O(n)  as we scan the list only once
 * Space Complexity : O(n)  as we create as hash map with n entries at most
 * Where n is the size of linked list
 */
int findWetherListHasCycleHashMapStrategy(struct  singlyNode **head){
    int flag=0;
    struct singlyNode *temp=*head;
    hashmap *map=NULL;
    if(head==NULL||*head==NULL){
        printf("List is empty\n");
        return -1;
    }
    
    map=hashmapCreate(20);
    printf("Going in loop\n");
    while(temp!=NULL){
        printf("%u->%d\n",temp,temp->data);
        if(hashmapGet(map,temp)!=NULL){
                flag=1;
                break;
            }
        hashmapInsert(map,&temp,temp);
        temp=temp->next;
    }
    return flag;
}

/*Finds wether a list has cycle or not Floyd Cycle Finding Algorithm
 * Return 0 if no cycle is present
 * Return 1 if cycle is present 
 * Return -1 in case of any error
 * 
 * Time Complexity :O(n)  as we scan the list only once
 * Space Complexity : O(1)  no extra space created
 * Where n is the size of linked list
 */
int findWetherListHasCycleFloydCycleFindingAlgorithm(struct singlyNode **head){
    
    struct singlyNode *slowPtr=*head;
    struct singlyNode *fastPtr=*head;
    
    if(head==NULL||*head==NULL){
        printf("List is empty\n");
        return -1;
    }
    
    while(slowPtr && fastPtr && fastPtr->next){
        slowPtr=slowPtr->next;
        fastPtr=fastPtr->next->next;
        
        if(slowPtr==fastPtr){
            return 1;
        }
    }
    
    return 0;
}


/*Finds wether a list has cycle or not Floyd Cycle Finding Algorithm
 * Return NULL if no cycle is present or any error occurs
 * Return pointer to the  start node of loop if cycle is present 
 * 
 * Time Complexity :O(n)  as we scan the list only once
 * Space Complexity : O(1)  no extra space created
 * Where n is the size of linked list
 */
struct singlyNode* findStartNodeOfLoopFloydCycleFindingAlgorithm(struct singlyNode **head){
    
    struct singlyNode *slowPtr=*head;
    struct singlyNode *fastPtr=*head;
    
    if(head==NULL||*head==NULL){
        printf("List is empty\n");
        return NULL;
    }
    
    while(slowPtr && fastPtr && fastPtr->next){
        slowPtr=slowPtr->next;
        fastPtr=fastPtr->next->next;
        
        if(slowPtr==fastPtr){
            break;
        }
    }
    
    if(slowPtr==fastPtr){
        slowPtr=*head;
        while(slowPtr!=fastPtr){
            slowPtr=slowPtr->next;
            fastPtr=fastPtr->next;
        }
        return slowPtr;
    }
    
    return NULL;
    
}



/*Finds wether a list has cycle or not Floyd Cycle Finding Algorithm
 * Return 0 if no cycle is present or any error occurs
 * Return  loop  size if cycle is present 
 * 
 * Time Complexity :O(n)  as we scan the list only once
 * Space Complexity : O(1)  no extra space created
 * Where n is the size of linked list
 */
int  findLoopSizeFloydCycleFindingAlgorithm(struct singlyNode **head){
    
    struct singlyNode *slowPtr=*head;
    struct singlyNode *fastPtr=*head;
    
    if(head==NULL||*head==NULL){
        printf("List is empty\n");
        return 0;
    }
    
    while(slowPtr && fastPtr && fastPtr->next){
        slowPtr=slowPtr->next;
        fastPtr=fastPtr->next->next;
        
        if(slowPtr==fastPtr){
            break;
        }
    }
    
    int loopSize=1;
    
    if(slowPtr==fastPtr){
        slowPtr=slowPtr->next;
        while(slowPtr!=fastPtr){
            slowPtr=slowPtr->next;
            loopSize++;
        }
        return loopSize;
    }
    
    return  0;
    
}


