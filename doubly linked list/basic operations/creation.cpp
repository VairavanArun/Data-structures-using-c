/*Doubly linked list creation*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* previous;
	struct node* next;
};

struct node* createDLL(struct node* head)
{
	struct node* temp;
	struct node* newNode;
	int data;
	printf("\nEnter data to be inserted, enter -1 to end: ");
	scanf("%d",&data);
	while(data!=-1)
	{
		newNode=(struct node*)malloc(sizeof(struct node));
		newNode->data=data;
		if(head==NULL)
		{
			head=newNode;
			head->previous=NULL;
			head->next=NULL;
		}
		else
		{
			temp=head;
			while(temp->next)  //traverse the linked list until we reach the last node
			  temp=temp->next;
			newNode->previous=temp;
			newNode->next=NULL;
			temp->next=newNode;
		}
		printf("\nEnter the data: ");
		scanf("%d",&data);
	}
	return head;
}

void displayDLL(struct node* head)
{
	struct node* temp;
	temp=head;
	printf("\nDoubly linked list data: ");
	while(temp)
	{
		printf("\n%d",temp->data);
		temp=temp->next;
	}
}

int main()
{
	struct node* head;
	head=NULL;
	head=createDLL(head);
	if(head)
	{
		displayDLL(head);
	}
	else
	{
		printf("\nEmpty list");
	}
}
