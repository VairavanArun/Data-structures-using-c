/*Program to make last node as first node*/
#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* next;
};

struct node* createLL(struct node* head)
{
	struct node* newNode;
	struct node* previous;
	int data;
	printf("\nEnter the data to inserted, enter -1 to end: ");
	scanf("%d",&data);
	while(data!=-1)
	{
		newNode=(struct node*)malloc(sizeof(struct node));
		newNode->data=data;
		if(head==NULL)
		{
			newNode->next=NULL;
			head=newNode;
		}
		else
		{
			previous=head;//after head is created the head is assigned to previous node;
			while(previous->next!=NULL)//go through the linked list until the last node is reached
			previous=previous->next;//make previous to point to the next node, loop until last node is reached(last node is reached when node->next==NULL
			previous->next=newNode;//make the last node to point to the newly created node
			newNode->next=NULL;
		}
		printf("\nEnter the data: ");
		scanf("%d",&data);
	}
	return head;
}

void displayLL(struct node* head)
{
	struct node* temp=head;
	printf("\nData in the linked list is: ");
	while(temp!=NULL)
	{
		printf("\n%d",temp->data);
		temp=temp->next;
	}
}

void frontToEnd(struct node** head)
{
	struct node* temp;
	struct node* prev;
	temp=*head;
	while(temp->next!=NULL)//check if we have reached last node
	{
		prev=temp;
		temp=temp->next;
		/*we have not reached the last node of the list
		Hence assign the current node to prev
		make temp to point to next node until temp->next=NULL, that is until we reach the last node*/
	}
	prev->next=NULL;
	temp->next=*head;
	*head=temp;
}

int main()
{
	struct node* head=NULL;
	head=createLL(head);
	if(head)
	{
		printf("\nLinked list before swapping:");
		displayLL(head);
		frontToEnd(&head);
		printf("\nLinked list after swapping:");
		displayLL(head);
	}
	else
	{
		printf("\nEmpty list");
	}
}
