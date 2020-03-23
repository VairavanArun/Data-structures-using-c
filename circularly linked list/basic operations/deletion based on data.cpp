/*deletion based on value*/

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

node* deleteNode(node* last)
{
	node* current;
	node* prev;
	prev=last;
	current=last->next;//current is made to point to node
	int data;
	printf("\nEnter the data to be deleted: ");
	scanf("%d",&data);
	do
	{
		if(data==current->data)
		{
			if(current==last)
			{
				last=prev;
			}
			prev->next=current->next;
			free(current);
			printf("\nCircular linked list after deletion: ");
		    traverse(last->next);
			return last;
		}
		prev=current;
		current=current->next;
	}while(current!=last->next);
	printf("\nData not found");
	return last;
}

int main()
{
	node* head=NULL;
	node* last=NULL;
	int data;
	last=createCLL(&head,last);
	if(head)
	{
		printf("\nCircular linked list before deletion: ");
		traverse(last->next);
		last=deleteNode(last);
		head=last->next;//changing head if first node is deleted
	}
	else
	{
		printf("\nEmpty list");
	}
	
}
