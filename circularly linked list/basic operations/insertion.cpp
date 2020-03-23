/*Circular linked list insertion*/

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	node* next;
};

node* createCLL(node** head,node* last)
{
	node* temp;
	node* newNode;
	newNode=NULL;
	temp=*head;
	int data;
	printf("\nEnter data to be added to circular linked list, enter -1 to end: ");
	scanf("%d",&data);
	if(data==-1)
	  return last;
	while(data!=-1)
	{
		newNode=(node*)malloc(sizeof(node));
		newNode->data=data;
		if(*head==NULL)
		{
			*head=newNode;
			newNode->next=NULL;
		}
		else
		{
			temp=*head;
			while(temp->next)
			{
				temp=temp->next;
			}
			temp->next=newNode;
			newNode->next=NULL;
		}
		printf("\nEnter the data: ");
		scanf("%d",&data);
	}
	newNode->next=*head;
	last=newNode;
	return last;
}

void traverse(node* head)
{
	node* temp=head;
	printf("\nContents of circularly linked list: ");
	do
	{
		printf("\n%d",temp->data);
		temp=temp->next;
	}while(temp!=head);
}

node* insertFront(node* last)
{
	node* temp;
	temp=(node* )malloc(sizeof(node));
	int data;
	printf("\nEnter the data to be inserted in front: ");
	scanf("%d",&data);
	temp->data=data;
	temp->next=last->next;
	last->next=temp;
	return last->next;
}

node* insertLast(node* last)
{
	node* temp;
	temp=(node*)malloc(sizeof(node));
	int data;
	printf("\nEnter the data to be inserted in last: ");
	scanf("%d",&data);
	temp->data=data;
	temp->next=last->next;
	last->next=temp;
	last=temp;
	return last;
}

node* insertPosition(struct node* last)
{
	node* temp;
	node* prev;
	temp=last->next;
	int data;
	int position;
	int k=1;
	printf("\nEnter the position to be inserted: ");
	scanf("%d",&position);
	while(k<position)
	{
		k++;
		prev=temp;
		temp=temp->next;
	}
	if(temp==last)
	{
		last=insertLast(last);
		return last;
	}
	if(temp==last->next)
	{
		last->next=insertFront(last);
		return last;
	}
	printf("\nEnter the data to be inserted: ");
	scanf("%d",&data);
	node* newNode;
	newNode=(node*)malloc(sizeof(newNode));
	newNode->data=data;
	newNode->next=temp;
	prev->next=newNode;
	return last;
	
}
int main()
{
	node* head=NULL;
	node* last=NULL;
	last=createCLL(&head,last);
	if(last)
	{
		traverse(last->next);
		head=insertFront(last);
		last=insertLast(last);
		last=insertPosition(last);
		traverse(last->next);
	}
	else
	{
		printf("\nEmpty List");
	}
}
