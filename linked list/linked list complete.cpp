/*Linked list creation and complete operations*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next;
};

struct node* head=NULL;
struct node* createLL(struct node* head);//fucntion to create a linked list
void displayLL(struct node* head);//function to display the linked list
void insertBeginning(struct node** head_ref);//function to insert a new node in the beginning
void insertEnd(struct node* head_ref);//function to insert a new node at the last
void insertPosition(struct node** head_ref);//function to insert a node at a particular position
int deleteBeginning(struct node** head_ref);//fucntion to delete a node in the beginning and return the value in deleted node
int deleteEnd(struct node* head_ref);//function to delete a node at the end and return the value in the deleted node
int deletePosition(struct node** head_ref,int* flag);//function to delete the node based on position and return the value in deleted node

int main()
{
	int option;
	int data;
	do
	{
		printf("\n******MAIN MENU******");
		printf("\n1.Create linked list");
		printf("\n2.Display linked list");
		printf("\n3.Insert a node in the beginning");
		printf("\n4.Insert a node at the end");
		printf("\n5.Insert a node based on a position");
		printf("\n6.Delete a node at the beginning");
		printf("\n7.Delete a node at the end");
		printf("\n8.Delete a node based on position");
		printf("\nEnter your choice: ");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
				head=createLL(head);
				break;
			case 2:
				displayLL(head);
				break;
			case 3:
				insertBeginning(&head);
				break;
			case 4:
				insertEnd(head);
				break;
			case 5:
				insertPosition(&head);
				break;
			case 6:
				data = deleteBeginning(&head);
				printf("\nDeleted data is: %d",data);
				break;
			case 7:
				data = deleteEnd(head);
				printf("\nDeleted data is: %d",data);
				break;
			case 8:
				int flag=1;
				data = deletePosition(&head,&flag);
				if(flag==1)
				printf("\nDeleted data is: %d",data);
				break;
		}
	}while(option<9);
	return 0;
}

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

void insertBeginning(struct node** head_ref)
{
	struct node* temp;
	int data;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter the data to insert in the beginning: ");
	scanf("%d",&data);
	temp->data=data;
	temp->next=*head_ref;
	*head_ref=temp;
}

void insertEnd(struct node* head)
{
	int data;
	struct node* temp;
	struct node *newNode=(struct node*)malloc(sizeof(struct node));
	temp=head;
	while(temp->next)
	 temp=temp->next;
	
	printf("\nEnter the data to inserted at the last: ");
	scanf("%d",&data);
	newNode->data=data;
	newNode->next=NULL;
	temp->next=newNode;
}

void insertPosition(struct node** head_ref)
{
	struct node* temp;
	struct node* prev;
	struct node* newNode;
	int k=1;
	int position,data;
	printf("\nEnter the position to insert data: ");
	scanf("%d",&position);
	printf("\nEnter the data to be inserted: ");
	scanf("%d",&data);
	if(position==1)//insert in the beginning
	{
		insertBeginning(head_ref);
		return;
	}
	else
	{
		temp=*head_ref;
		while(temp && k<position)
		{
			k++;
			prev=temp;
			temp=temp->next;
		}
		if(k!=position)
		{
			printf("\nEntered position is greater than list length. Entered data will be inserted at the end of the list");
		}
		newNode=(struct node*)malloc(sizeof(struct node));
		newNode->data=data;
		newNode->next=temp;
		prev->next=newNode;
	}
}

int deleteBeginning(struct node** head_ref)
{
	int data;
	struct node* temp;
	temp=*head_ref;
	*head_ref=temp->next;
	data=temp->data;
	free(temp);
	return data;
}

int deleteEnd(struct node* head_ref)
{
	int data;
	struct node* temp;
	struct node* prev;
	temp=head_ref;
	while(temp->next)
	{
		prev=temp;
		temp=temp->next;
	}
	data=temp->data;
	free(temp);
	prev->next=NULL;
	return data;
}

int deletePosition(struct node** head_ref,int* flag)
{
	int data;
	int position;
	int k=1;
	struct node* temp;
	struct node* prev;
	printf("\nEnter the position to be deleted: ");
	scanf("%d",&position);
	if(position==1)
	{
		data=deleteBeginning(head_ref);
		return data;
	}
	else
	{
		temp=*head_ref;
		while(temp->next && k<position)
		{
			k++;
			prev=temp;
			temp=temp->next;
		}
		if(k!=position)//indicating that the entered position is out of range
		{
			*flag=0;
			printf("\nEntered position out of range.");
		}
		prev->next=temp->next;
		data=temp->data;
		free(temp);
		return data;
	}
}


