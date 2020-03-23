/*swapping in linked list without swapping data*/
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

void swap(struct node** head,int x,int y)
{
	struct node* prevX=NULL;
	struct node* prevY=NULL;
	struct node* xnode=NULL;
	struct node* ynode=NULL;
	struct node* temp=*head;
	while(temp)
	{
		if((!xnode && temp->next) && (temp->data==x || temp->next->data==x))
		{
			if(temp==*head && temp->data==x)
			{
				xnode=temp;
			}
			else
			{
				prevX=temp;
				xnode=temp->next;
			}
		}
		if((!ynode && temp->next) && (temp->data==y || temp->next->data==y))
		{
			if(temp==*head && temp->data==y)
			{
				ynode=temp;
			}
			else
			{
				prevY=temp;
				ynode=temp->next;
			}	
		}
		temp=temp->next;
		if(xnode && ynode)
		  break;           //if x and y found before end of linked list exit the loop
	}
	if(!xnode || !ynode)
	{
		printf("\nOne of the element was not found");
		return ;
	}
	if(xnode==*head)
	{
		*head=ynode;
	}
	else
	{
		prevX->next=ynode;
	}
	if(ynode==*head)
	{
		*head=xnode;
	}
	else
	{
		prevY->next=xnode;
	}
	temp=xnode->next;
	xnode->next=ynode->next;
	ynode->next=temp;
	printf("\nLinked list after swapping");
	displayLL(*head);
}

int main()
{
	struct node* head=NULL;
	head=createLL(head);
	if(head)
	{
		printf("\nLinked list before swapping:");
		displayLL(head);
		int x,y;
		printf("\nx and y values will be swapped.\nEnter the value of x: ");
		scanf("%d",&x);
		printf("\nEnter the value of y:");
		scanf("%d",&y);
		swap(&head,x,y);
	}
	else
	{
		printf("\nEmpty list");
	}
}
