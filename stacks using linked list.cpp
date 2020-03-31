/*stacks using linked list*/
/*same as linked list except, we keep in track of the last inserted node instead  of head node*/

#include<stdio.h>
#include<stdlib.h>

struct stackNode
{
	int data;
	struct stackNode* next;
};

int isEmpty(struct stackNode* top)
{
	return top==NULL;
}

void push(struct stackNode** top,int data)
{
	struct stackNode* newNode=(struct stackNode*)malloc(sizeof(struct stackNode));
	newNode->data=data;
	newNode->next=*top;
	*top=newNode;
	printf("\n%d pushed into stack",(*top)->data);
}

int pop(struct stackNode** top,int* flag)
{
	if(isEmpty(*top))
	{
		printf("\nEmpty stack");
		*flag=0;
	}
	int data=(*top)->data;
	struct stackNode* temp=(*top)->next;
	free(*top);
	*top=temp;
	return data;
}

int main()
{
	struct stackNode* top=NULL;
	push(&top,1);
	push(&top,2);
	push(&top,3);
	int flag=1;
	while(flag)
	{
		int data=pop(&top,&flag);
		if(flag)
		{
			printf("\n%d popped from the stack",data);
		}
	}
}
