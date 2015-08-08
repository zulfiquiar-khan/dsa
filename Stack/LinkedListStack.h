#include<stdio.h>
#include<stdlib.h>


struct ListNode{
	int data;
	struct ListNode *next;
};

struct Stack{
	int size;
	struct ListNode *top;
};

struct Stack * createStack(){
	struct Stack *S=(struct Stack*)
	malloc(sizeof(struct Stack));
	S->top=NULL;
	return S;
}

int isEmptyStack(struct Stack *S){
	return (S->top==NULL);
}

void push(struct Stack *S,int data){
	struct ListNode *temp=(struct ListNode*)
	malloc(sizeof(struct ListNode));
	temp->data=data;
	temp->next=S->top;
	S->top=temp;
	S->size++;
}

int pop(struct Stack *S){
	int data=0;
	struct ListNode *temp;
	if(isEmptyStack(S)){
			printf("Stack is Empty");
			return 0;
		}
		else{
			temp=S->top;
			S->top=temp->next;
			data=temp->data;
			free(temp);
			S->size--;
			return data;
		}
}

int top(struct Stack *S){
	if(isEmptyStack(S)){
		printf("Stack is Empty");
		return 0;
	}
	return S->top->data;
}

int size(struct Stack *S){
	return S->size;
}

void deleteStack(struct Stack *S){
	struct ListNode *temp;
	struct ListNode *top;
	top=S->top;
	while(top!=NULL){
		temp=top;
		top=top->next;
		free(temp);
	}
	free(S);	
}


void displayStack(struct Stack *S){
	struct ListNode *temp;
	if(!isEmptyStack(S)){
		temp=S->top;
		printf("\nStack State\n");
		while(temp!=NULL){
			printf("|%d|\n",temp->data);
			temp=temp->next;
		}
	}
else{
	printf("\nStack is Empty\n");
}
}
