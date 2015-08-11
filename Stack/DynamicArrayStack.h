#include<stdio.h>
#include<stdlib.h>

struct Stack{
        int top;
        int capacity;
        int *array;
};

//Creates a Stack of size passed as parameter
struct Stack* createStack(){
    struct Stack* S=NULL;
	S=(struct Stack*)
	malloc(sizeof(struct Stack));
	if(!S){return NULL;}
	S->top=-1;
	S->capacity=20;
	S->array=(int *)malloc(S->capacity*sizeof(int));
	if(!S->array){return NULL;}
	return S;
}

//Doubles the size of stack
void doubleStack(struct Stack *S){
	S->capacity*=2;
	int* array=realloc(S->array,S->capacity);
    if(array!=NULL){
        free(S->array);
        S->array=array;
    }else{
        printf("Unable to resize\n");
    }
}

//Adds an element to the stack if space is left ...  return 1 if success
void push(struct Stack *S,int data){
	if(isStackFull(S)){doubleStack(S);}
	S->array[++S->top]=data;
}

//Returns and removs the top element in the stack
//Returns 0 if stack is empty
int pop(struct Stack *S){
	if(isEmptyStack(S)){
	//	printf("Stack is Empty");
		return 0;
	}
	else{
		return	(S->array[S->top--]);
	}
}

int top(struct Stack *S){
	if(isEmptyStack(S)){
	//	printf("Stack is Empty");
		return 0;
	}
	else{
		return	(S->array[S->top]);
	}
}

int size(struct Stack *S){
	return S->top++;
}

//Checks wether the stack is empty or not
//Returns 1 if empty 
//Returns 0 if the stack is not empty
//Pre supposes that S is not NULL
int isEmptyStack(struct Stack *S){
	
	//returns 1 if condition is true else returns 0
	return (S->top==-1);
	
}

int isStackFull(struct Stack *S){
	return (S->top==S->capacity-1);
}
	
void deleteStack(struct Stack *S){	
	if(!S){
		if(!S->array){free(S->array);}
		free(S);
	}
}

void displayStack(struct Stack *S){
	int counter=S->top;
	if(!isEmptyStack(S)){
	printf("\nStack State : \n");
	for(;counter>=0;counter--){
		printf("|%d|\n",S->array[counter]);
	}
}
else{
	printf("\nStack is Empty\n");
}
}
