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