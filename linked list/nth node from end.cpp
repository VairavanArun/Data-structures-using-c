/*nth node from end*/
/*use two pointers
main pointer and reference pointer
intially both point to head
move the reference pointer  nth nodes from beginning
check whether reference pointer has reached NULL, if it has reached null, then return index out of range
else do the following
now move both the reference pointer and main pointer to next node until reference pointer becomes null
return data of main pointer*/

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

int nthNodeEnd(struct node* head,int n,int* flag)
{
	if(head==NULL)
	{
		printf("\nEmpty list");
		*flag=0;
		return 0;
	}
	struct node* main;
	struct node* ref;
	main=head;
	ref=head;
	int count=1;
	int data;
	while(ref!=NULL && count<n)
	{
		count++;
		ref=ref->next;
	}
	if(ref==NULL)
	{
		*flag=0;
		printf("\nGiven index out of range");
		return 0;
	}
	else
	{
		while(ref->next!=NULL)
		{
			main=main->next;
			ref=ref->next;
		}
		data = main->data;
		return data;
	}
}

int main()
{
	printf("****PROGRAM TO FIND NTH FROM END****");
	struct node* head=NULL;
	head=createLL(head);
	int nth;
	int flag=1;
	printf("\nEnter the value of n: ");
	scanf("%d",&nth);
	int data= nthNodeEnd(head,nth,&flag);
	if(flag==1)
	{
		printf("\ndata= %d",data);
	}
}
