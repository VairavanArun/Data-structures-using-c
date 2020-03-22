/*PROGRAM TO FIND THE MIDDLE OF THE GIVEN LINKED LIST
have two pointers fastPtr and slowPtr
fastPtr traverses two nodes at a time
slowPtr traverses one node at a time
when fastPtr reaches NULL(even number of nodes) or when fastPtr->next reaches NULL(odd number of nodes,
slowPtr must have reached the middle of the linked list
return slowPtr->data*/

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
	struct node* temp;
	int data;
	printf("\nEnter the data, enter -1 to end: ");
	scanf("%d",&data);
	while(data!=-1)
	{
		newNode=(struct node*)malloc(sizeof(struct node));
		if(newNode==NULL)
		{
			printf("Memory error");
			return head;
		}
		newNode->data=data;
		if(head==NULL)
		{
			newNode->next=NULL;
			head=newNode;
		}
		else
		{
			temp=head;
			while(temp->next!=NULL)
			temp=temp->next;
			newNode->next=NULL;
			temp->next=newNode;
		}
		printf("\nEnter the data: ");
		scanf("%d",&data);
	}
	return head;
}

int middle(struct node* head,int* flag)
{
	struct node* slowPtr;
	struct node* fastPtr;
	slowPtr=head;
	fastPtr=head;
	if(head==NULL)
	{
		printf("\nEmpty list");
		*flag=0;
		return 0;
	}
	while(fastPtr!=NULL && fastPtr->next!=NULL)
	{
		slowPtr=slowPtr->next;
		fastPtr=fastPtr->next->next;
	}
	return slowPtr->data;
}
int main()
{
	printf("****PROGRAM TO FIND THE MIDDLE OF A GIVEN LINKED LIST****");
	struct node* head=NULL;
	head=createLL(head);
	int flag=1;
	int data=middle(head,&flag);
	if(flag==1)
	{
		printf("\ndata=%d",data);
	}
}

