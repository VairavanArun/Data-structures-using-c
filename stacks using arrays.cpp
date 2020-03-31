/*Implementation of stacks using array*/
#include<stdio.h>
#include<stdlib.h>

struct Stack //stack properties which all stacks should possess
{
	int top;
	int* array;
	unsigned int capacity;
};

struct Stack* createStack(unsigned int capacity)
{
	struct Stack* stack=(struct Stack*)malloc(sizeof(struct Stack));
	stack->top=-1;
	stack->capacity=capacity;
	stack->array=(int*)malloc(sizeof(int)*stack->capacity);
	return stack;
}

int isFull(struct Stack* stack)
{
	return stack->top==stack->capacity-1;
}

int isEmpty(struct Stack* stack)
{
	return stack->top==-1;
}

void push(struct Stack* stack,int data)
{
	if(isFull(stack))
	{
		printf("\nStack is full");
		return ;
	}
	stack->array[++stack->top]=data;
	printf("\n%d pushed to stack",data);
	return;
}

int pop(struct Stack* stack,int* flag)
{
	if(isEmpty(stack))
	{
		printf("\nStack is empty");
		*flag=0;
		return 0;
	}
	return stack->array[stack->top--];
}

int peek(struct Stack* stack,int* flag)
{
	if(isEmpty(stack))
	{
		printf("\nEmpty stack");
		*flag=0;
		return INT_MIN;
	}
	return(stack->array[stack->top]);
}

int main()
{
	struct Stack* stack=createStack(4);
	push(stack,1);
	push(stack,2);
	push(stack,3);
	push(stack,4);
	push(stack,5);
	int flag=1;
	int data=pop(stack,&flag);
	if(flag)
	{
		printf("\n%d popped from stack",data);
	}
}

