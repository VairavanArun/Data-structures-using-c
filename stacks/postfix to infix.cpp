/*postfix to infix expressions*/
/*algorithm for postfix to infix conversion*/
/*
step 1: read the post fix expression
step 2: if the charachter is an operand push into stack
step 3: if the charachter is an operator, pop two operands out of the stack, insert the operator in between the popped operands
and push the resultant expression onto the stack
step 4: repeat the process until the enter expression is read
At the end the top of the stack will be the resultant infix expression

Note:
1.Stack have been implemented using arrays.
2.IMPORTANT: The data which we are pushing into the stack is either an operand or an expression. 
Operand is of lenght one charachter, but expression is of variable length. The expression may be pushed into any location of the 
array. This indicates that each element of array should be of variable length i.e 2d dynamically allocated array is needed
That is why I have declared the array element of stack as a pointer to pointer. I have followed pointer to pointer method of dynamic 
allocation of 2D array. 
3.I have used two push functions, one for operand push another for expression push. The operand push pushes only one charachter onto the
stack, pushExpression pushes an expression to stack. Why there are two separate functions for operands and expressions. I have used 
strcpy() fucntion to copy the entire string on to the stack. strcpy() requires two char* and copies the source string upto first null to
destination string. If we use the same function for both operand and expression, the operand is passed as a single charachter and not as
charachter pointer, if we pass it as charachter pointer then strcpy() results in copying the exp string from the encountered operand to
the first null, that is the rest of the expression, which is undesired. That is why I have used two different functions for pushing 
operand and pushing expression
*/

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





