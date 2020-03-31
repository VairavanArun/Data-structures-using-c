/*Infix to postfix conversion*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Stack
{
	int top;
	unsigned capacity;
	char *array;
};

struct Stack* createStack(unsigned int capacity)
{
	struct Stack* stack=(struct Stack*)malloc(sizeof(struct Stack));
	stack->top=-1;
	stack->capacity=capacity;
	stack->array=(char*)malloc(sizeof(char)*capacity);
	return stack;
}

int isEmpty(struct Stack* stack)
{
	return stack->top==-1;
}

void push(struct Stack* stack,char data)
{
	stack->array[++stack->top]= data;
}

char pop(struct Stack* stack)
{
	if(!isEmpty(stack))
	{
		return(stack->array[stack->top--]);
	}
}

char peek(struct Stack* stack)
{
	if(!isEmpty(stack))
	{
		return(stack->array[stack->top]);
	}
}


int isOperand(char exp)
{
	return (exp>='a' && exp<='z')||(exp>='A'&& exp<='Z');
}

int priority(char exp)
{
	switch(exp)
	{
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 2;
	}
	return -1; //for '(' and ')'
}

int infixToPostfix(char* exp)
{
	struct Stack* stack=createStack(strlen(exp));
	int i,k;
	for(i=0,k=-1;exp[i];i++)
	{
		if(isOperand(exp[i]))
		{
			exp[++k]=exp[i];
		}
		
		else if(exp[i]=='(')
		{
			push(stack,exp[i]);
		}
		else if(exp[i]==')')
		{
			while(!isEmpty(stack)&& peek(stack)!='(')
			{
				exp[++k]=pop(stack);
			}
			if(!isEmpty(stack) && peek(stack)!='(')
			{
				printf("Invalid expression");
				return -1;
			}
			pop(stack);
		}
		else
		{
			while(!isEmpty(stack)&& priority(exp[i])<=priority(peek(stack)))
			{
				exp[++k]=pop(stack);
			}
			push(stack,exp[i]);
		}
	}
	
	while(!isEmpty(stack))
	 exp[++k]=pop(stack);
	exp[++k]='\0';
	printf("\n%s",exp);
}

int main()
{
	char exp[]="a+b*(c/d+e)";
	infixToPostfix(exp);
}
