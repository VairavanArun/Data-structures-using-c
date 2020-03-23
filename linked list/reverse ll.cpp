/*Reverse a linked list*/

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

void reverse(struct node** head)
{
	struct node* current;
	struct node* prev;
	struct node* next;
	current=*head;
	prev=NULL;
	while(current->next)//loop until we reach last node
	{
		next=current->next;//finding the next node
		current->next=prev;//making current node to point to previous node(reversing)
		prev=current;//making current node as previous node
		current=next;//making next node as current node
	}
	current->next=prev;//making the last node to point to last before node
	*head=current;//making the last node as head 
}

int main()
{
	struct node* head=NULL;
	head=createLL(head);
	if(head)
	{
		printf("\nLinked list before reversing: ");
		displayLL(head);
		reverse(&head);
		printf("\nLinked list after reversing: ");
		displayLL(head);
	}
	else
	{
		printf("\nEmpty list");
	}
}
