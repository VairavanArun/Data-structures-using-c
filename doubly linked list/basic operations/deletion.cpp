/*deletion in doubly linked list*/
/*whenever u delete a node, u have to have the previous and next pointer being changed*/
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

int deleteFront(struct node** head)
{
	struct node* temp;
	int data;
	temp=*head;
	temp->next->previous=NULL; //when the head node is deleted, the next node will become head, hence it's previous node is null
	data=temp->data;
	*head=temp->next;
	free(temp);
	return data;
}

int deleteEnd(struct node* head)
{
	struct node* temp;
	int data;
	temp=head;
	while(temp->next)
	{
		temp=temp->next;
	}
	data=temp->data;
	temp->previous->next=NULL; //make last before node as null
	free(temp);
	return data;
}

int deletePosition(struct node** head,int* flag)
{
	int k=1;
	int data;
	int position;
	struct node* temp;
	temp=*head;
	printf("\nEnter the position to delete the node: ");
	scanf("%d",&position);
	if(position==1)
	{
		printf("\nDeleting the head node");
		return deleteFront(head);
	}
	else
	{
		while(k<position && temp->next)
		{
			k++;
			temp=temp->next;
		}
		if(k==position)
		{
			if(temp->next==NULL)
			{
				//delete last node;
				return deleteEnd(*head);
			}
			else
			temp->previous->next=temp->next;
			temp->next->previous=temp->previous;
			data=temp->data;
			free(temp);
		}
		else
		{
			printf("\nThe given position out of range");
			*flag=0;
			return 0;
		}
	}
}

int main()
{
	struct node* head;
	struct node* temp;
	head=NULL;
	head=createDLL(head);
	if(head)
	{
		displayDLL(head);
		int option;
		int flag=1;
		int data;
		printf("\nEnter your option\n1.Delete first node\n2.Delete the last node.\n3.Delete based on position of node\nEnter your option: ");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
				printf("\nData deleted: %d",deleteFront(&head));
				displayDLL(head);
				break;
			case 2:
				printf("\nData deleted: %d",deleteEnd(head));
				displayDLL(head);
				break;
			case 3:
				data=deletePosition(&head,&flag);
				if(flag)
				{
					printf("\nData deleted: %d",data);
					displayDLL(head);
				}
				break;
			default:
				printf("Invalid option");
		}
		temp=head;
		while(temp->next)
		{
			temp=temp->next;
			free(temp->previous);
		}
		free(temp);
	}
	else
	{
		printf("\nEmpty list");
	}
}
