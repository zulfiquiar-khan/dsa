#include<stdio.h>
#include<stdlib.h>
#include "DynamicArrayStack.h"
//Returns 1 if priority of operator 2 is less than the
//prority of operator 1 otherwise returns 0
int isLowerPriority(char operator1,char operator2){
	char operator[5]={'+','-','%','/','*'};
	int priority[5]={12,12,13,13,13};
	int i=0;
	int priority1=0;
	int priority2=0;
	int flag=0;
	while(i<5){
		if(operator1==operator[i]){priority1=priority[i];}
		else if(operator2=operator[i]){priority2=priority[i];}
		
		if(priority1!=0 && priority2!=0){break;}
		i++;
	}
	
	if(priority1>priority2){flag=1;}
	
	return flag;
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


char*  getPostfixFromInfix(char *expr){
		int i=0;
        char postfixExpr[264];
        int counter=0;
		struct Stack *S=createStack();
		while(expr[i]!='\0'){
				if(expr[i]==')'){
					while(top(S)!='('){postfixExpr[counter++]=pop(S);}
					if(top(S)=='('){pop(S);}
				}
				else if(expr[i]=='('){push(S,expr[i]);}
				else if(isOperator(expr[i])){
					while(1){
						if(isEmptyStack(S)||
						   isLowerPriority(expr[i],top(S)) ||
						   top(S)=='('){
							   push(S,expr[i]);
								break;
						   }
						  postfixExpr[counter++]=pop(S);
					}
					
				}
				else{
					push(S,expr[i]);
				}
			i++;	
		}
		
		if(!isEmptyStack(S)){
			while(!isEmptyStack(S)){postfixExpr[counter++]=pop(S);}
		}
		
		postfixExpr[counter]='\0';
        
        return postfixExpr;
	}



int evaluatePostfixExpression(char * expr){
    struct Stack *S=createStack();
    int i=0;
    int retValue=0;
    while(expr[i]!='\0'){
        if(isOperator(expr[i])){
            int operand1=pop(S);
            int operand2=pop(S);
            
            if(expr[i]=='+'){
                    retValue=operand1+operand2;
            }else if(expr[i]=='-'){
                retValue=operand1-operand2;
            }else if(expr[i]=='*'){
                retValue=operand1*operand2;
            }else if(expr[i]=='/'){
                retValue=operand1/operand2;
            }
                     push(S,retValue);
        }
        else{
            push(S,expr[i]);
        }
        i++;
    }
    
    return pop(S);
}






