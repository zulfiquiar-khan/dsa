#include<stdio.h>
#include<stdlib.h>
#include "DynamicArrayStack.h"

//Retruns 1 if the expression is balanced 
//Returns 0 if the expression is not balanced
int isExpressionBalanced(char *expr){

	char curve_open='(';
	char curve_close=')';
	char square_open='[';
	char square_close=']';
	char curly_open='{';
	char curly_close='}';

	struct Stack *S=createStack();

	if(!S){printf("Error creating Stack !!!!!\n");return 0;}
	else{printf("Stack created successfully !!!!\n");}
	
	/***Symbol balancing using stack START***/
	int i=0;
	int flag=1;
	while(expr[i]!='\0'){
		if(expr[i]==curve_open || 
		   expr[i]==curly_open ||
		   expr[i]==square_open)
		{push(S,expr[i]);}
		else if(expr[i]==curve_close || 
		        expr[i]==curly_close ||
		        expr[i]==square_close){
			if(isEmptyStack(S)){flag=0;}
			char popped=pop(S);
			if(expr[i]==curve_close){if(popped!=curve_open)flag=0;}
			else if(expr[i]==square_close){if(popped!=square_open)flag=0;}
			else if(expr[i]==curly_close){if(popped!=curly_open)flag=0;}
		}
		if(flag==0){break;}
		i++;
	}
	if(!isEmptyStack(S)){flag=0;}
	
	/***Symbol balancing using stack END***/ 
	
	return flag;
}











