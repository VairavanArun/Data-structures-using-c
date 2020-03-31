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


void insertFront(struct node** head)
{
	int data;
	struct node* newNode;
	struct node* temp=*head;
	newNode=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter the data to be inserted in the front: ");
	scanf("%d",&data);
	newNode->data=data;
	newNode->previous=NULL;
	newNode->next=temp;
	temp->previous=newNode;
	*head=newNode;
}

void insertEnd(struct node* head)
{
	struct node* temp;
	struct node* newNode;
	int data;
	printf("\nEnter the data to be inserted at the end: ");
	scanf("%d",&data);
	temp=head;
	while(temp->next)
	  temp=temp->next;
	newNode=(struct node*)malloc(sizeof(struct node));
	newNode->data=data;
	newNode->next=NULL;
	newNode->previous=temp;
	temp->next=newNode;
}

void insertPosition(struct node** head)
{
	struct node* temp;
	struct node* newNode;
	int position;
	int data;
	int k=1;
	temp=*head;
	printf("\nEnter the position to enter the data: ");
	scanf("%d",&position);
	if(position<=1)
	{
		printf("\nInserting data in the front");
		insertFront(head);
	}
	else
	{
		while(k<position && temp->next!=NULL)
		{
			temp=temp->next;
			k++;
		}
		if(temp->next==NULL)
		{
			printf("\nInserting data at the end: ");
		    insertEnd(*head);
		}
		else
		{
			printf("\nEnter the data to be inserted: ");
			scanf("%d",&data);
			newNode=(struct node*)malloc(sizeof(newNode));
			newNode->data=data;
			newNode->next=temp;
			newNode->previous=temp->previous;
			temp->previous->next=newNode; //make the previous node to point to the newNode
			temp->previous=newNode;
		}
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
		int position;
		printf("\nEnter your option: \n1.Insert at front.\n2.Insertion based on position.\n3.Insert at the last\nEnter your option: ");
		scanf("%d",&position);
		switch(position)
		{
			case 1:
				insertFront(&head);
				displayDLL(head);
				break;
			case 2:
				insertPosition(&head);
				displayDLL(head);
				break;
			case 3:
				insertEnd(head);
				displayDLL(head);
				break;
			default:
				printf("Invalid option");
		}
	}
	else
	{
		printf("\nEmpty list");
	}
}
