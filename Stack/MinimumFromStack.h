#include "DynamicArrayStack.h"
#include <stdlib.h>

struct AdvanceStrack{
    struct Stack *elementStack;
    struct Stack *minStack;
};

struct  AdvanceStrack* createAdvanceStack(){
    struct AdvanceStrack *S=(struct AdvanceStrack*)malloc(sizeof(struct AdvanceStrack));
    S->elementStack=(struct Stack*)malloc(sizeof(struct Stack));
    S->minStack=(struct Stack*)malloc(sizeof(struct Stack));
}


void pushAdvanceStack(struct AdvanceStrack *S,int data){
    push(S->elementStack,data);
    if(isEmptyStack(S->elementStack) || top(S->elementStack)<top(S->minStack) ){
        push(S->minStack,data);
    }
    else{
        push(S->minStack,top(S->minStack));
    }
}

int  popAdvanceStack(struct  AdvanceStrack *S){
    if(isEmptyStack(S->elementStack)){return -1;}
    pop(S->minStack);
    return pop(S->elementStack);
}

//Returns 1 if empty else returns 0
int isEmptyAdvanceStack(struct AdvanceStrack *S){
        return (isEmptyStack(S->elementStack));
}

int getMinimum(struct AdvanceStrack *S){
        if(isEmptyStack(S->elementStack)){
                return -1;
        }
        return top(S->minStack);
}