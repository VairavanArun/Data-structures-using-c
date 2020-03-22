/*get nth node in a linked list*/
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
int nthNode(struct node* head,int n,int* flag)
{
	struct node* current;
	int count=1;
	current=head;
	while(current!=NULL)
	{
		if(count==n)
		{
			return current->data;
		}
		current=current->next;
		count++;
	}
	*flag=0;
	return 0;
}

int main()
{
	struct node* head=NULL;
	head=createLL(head);
	int nth;
	int flag=1;
	printf("\nEnter the value of n: ");
	scanf("%d",&nth);
	int data= nthNode(head,nth,&flag);
	if(flag==0)
	{
		printf("\nGiven index is out of range");
	}
	else
	{
		printf("\ndata= %d",data);
	}
}
