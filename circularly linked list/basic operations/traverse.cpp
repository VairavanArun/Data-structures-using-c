/*Circular linked list traversal*/

/*Circular linked list creation*/

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	node* next;
};

node* createCLL(node* head,node** last)
{
	node* temp;
	node* newNode;
	newNode=NULL;
	temp=head;
	int data;
	printf("\nEnter data to be added to circular linked list, enter -1 to end: ");
	scanf("%d",&data);
	if(data==-1)
	  return head;
	while(data!=-1)
	{
		newNode=(node*)malloc(sizeof(node));
		newNode->data=data;
		if(head==NULL)
		{
			head=newNode;
			newNode->next=NULL;
		}
		else
		{
			temp=head;
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
	newNode->next=head;
	*last=newNode;
	return head;
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

int main()
{
	node* head=NULL;
	node* last=NULL;
	head=createCLL(head,&last);
	if(head)
	{
		traverse(head);
	}
	else
	{
		printf("\nEmpty List");
	}
}
