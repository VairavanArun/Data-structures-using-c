/* insert at position specified by number*/
#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* next;
};

void insert(struct node** head_ref,int data,int position)
{
	struct node *newNode,*p,*q;
	newNode=(struct node*)malloc(sizeof(struct node));
	int k=1;
	newNode->data=data;
	if(position==1)
	{
		newNode->next=*head_ref;
		*head_ref=newNode;
	}
	else
	{
		p=*head_ref;
		while(p!=NULL && k<position)
		{
			k++;
			q=p;//q holds the node at k-1 position
			p=p->next;//node at kth position
		}
		q->next=newNode;//k-1 node will point to newNode
		newNode->next=p;//newNode will point to the node which was intially in the kth position, hence newNode is inserted at kth position
	}
}

int main()
{
	struct node* head;
	struct node* second;
	struct node* third;
	head=(struct node*)malloc(sizeof(struct node));
	second=(struct node*)malloc(sizeof(struct node));
	third=(struct node*)malloc(sizeof(struct node));
	head->data=1;
	head->next=second;
	second->data=2;
	second->next=third;
	third->data=3;
	third->next=NULL;
	struct node* traverse=head;
	printf("data in the list before insertion: \n");
	while(traverse)
	{
		printf("%d\n",traverse->data);
		traverse=traverse->next;
	}
	printf("enter the data to be inserted: ");
	int data;
	scanf("%d",&data);
	int position;
	printf("enter the position to be inserted: ");
	scanf("%d",&position);
	insert(&head,data,position);
	printf("data in the list after insertion: \n");
	traverse=head;
	while(traverse!=NULL)
	{
		printf("%d\n",traverse->data);
		traverse=traverse->next;
	}
}
