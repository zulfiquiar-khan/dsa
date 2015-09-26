#include<stdlib.h>
#include"../Stack/LinkedListStack.h"

int isOperator(char);

struct binaryExpressionNode{
    int data;
    struct binaryExpressionNode* left;
    struct binaryExpressionNode* right;
};

typedef struct binaryExpressionNode expressionNode;

expressionNode* createExpressionTree(int postfix[],int length){
    int i=0;
    struct Stack* s=createStack();
    expressionNode* newNode=NULL;
    expressionNode* popped1=NULL;
    expressionNode* popped2=NULL;
    
    while(i<length){
        if(!isOperator(postfix[i])){
            newNode=(expressionNode*)malloc(sizeof(expressionNode));
            if(newNode==NULL){printf("Memory Error\n");return NULL;}
            newNode->data=postfix[i];
            newNode->right=newNode->left=NULL;
            push(s,newNode);
        }
        else{
            newNode=(expressionNode*)malloc(sizeof(expressionNode));
            if(newNode==NULL){printf("Memory Error\n");return NULL;}
            popped1=pop(s);
            popped2=pop(s);
            newNode->data=postfix[i];
            newNode->left=popped1;
            newNode->right=popped2;
            push(s,newNode);
        }
        i++;
    }
    return pop(s);
}


int isOperator(char symbol){
	char operator[5]={'+','-','%','/','*'};
	int i=0;
	int flag=0;
	
	while(i<5){
		if(operator[i]==symbol){flag=1;break;}
		i++;
	}
	
	return flag;
}


void inOrderTraversalRecursive(expressionNode* root){
    if(root!=NULL){
        inOrderTraversalRecursive(root->left);
        printf("%c",root->data);
        inOrderTraversalRecursive(root->right);
    }
}