/*postfix to infix expressions*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Stack
{
	int top;
	unsigned int capacity;
	char** array;
};

struct Stack* createStack(unsigned int capacity)
{
	struct Stack* stack=(struct Stack*)malloc(sizeof(struct Stack));
	stack->top=-1;
	stack->capacity=capacity;
	stack->array=(char**)malloc(sizeof(char*)*capacity);
	return stack;
}

int isEmpty(struct Stack* stack)
{
	return stack->top==-1;
}

void push(struct Stack* stack,char exp)
{
	stack->array[++stack->top]=(char*)malloc(sizeof(char));
	*(stack->array[stack->top])=exp;
	*(stack->array[stack->top]+1)='\0';
}

void pushExpression(struct Stack* stack,char* exp)
{
	stack->array[++stack->top]=(char*)malloc(sizeof(char)*strlen(exp));
	strcpy(stack->array[stack->top],exp);
	stack->array[stack->top][strlen(exp)]='\0';
}

char* pop(struct Stack* stack)
{
	return stack->array[stack->top--];
}
 
char* peek(struct Stack* stack)
{
	return stack->array[stack->top];
} 
 
int isOperand(char exp)
{
 	return (exp>='a' && exp<='z')||(exp>='A' && exp<='Z');
}
 
int postfixToInfix(char* exp)
{
 	struct Stack* stack=createStack(strlen(exp));
	char* current;
	char* operand1;
	char* operand2;
 	int i;
 	for(i=0;i<strlen(exp);i++)
 	{
 		if(isOperand(exp[i]))
 		{
 			push(stack,exp[i]);
		}
		else
		{
			operand1=(char*)malloc(sizeof(char)*strlen(peek(stack)));
			strcpy(operand1,pop(stack));
			operand2=(char*)malloc(sizeof(char)*strlen(peek(stack)));
			strcpy(operand2,pop(stack));
			current=(char*)malloc(sizeof(char)*(strlen(operand1)+strlen(operand2)+3));
			//3 indicates one space for '(', one space for ')',one space for '/0'
			current[0]='(';
			current[1]='\0';
			strcat(current,operand2);
			current[strlen(current)]=exp[i];
			current[strlen(current)]='\0';
			strcat(current,operand1);
			char end[]=")";
			strcat(current,end);
			pushExpression(stack,current);
			free(operand1);
			free(operand2);
			free(current);	
		}
    }
    
    exp=pop(stack);
    if(!isEmpty(stack))
    {
    	printf("Invalid expression");
    	return -1;
	}
	printf("\npostfix expression: %s",exp);
	free(stack);
 }
 
 int main()
 {
 	char exp[]="abcd/e+*+";
 	postfixToInfix(exp);
 }





