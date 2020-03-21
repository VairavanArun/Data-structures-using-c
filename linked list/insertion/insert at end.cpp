/*Linked list insertion at the end*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next;
};
void insertLast(struct node* head,int data)
{
	struct node* current=head;
	while(current->next!=NULL)//if current-> next is NULL then current will be the last node else keep on traversing
	{
		current=current->next;
	}
	struct node* newNode;
	newNode=(struct node*)malloc(sizeof(struct node));
	newNode->data=data;
	newNode->next=NULL;
	current->next=newNode;
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
	struct node* traverse;
	traverse=head;
	printf("linked list data before insertion: \n");
	while(traverse!=NULL)
	{
		printf("%d\n",traverse->data);
		traverse=traverse->next;
	}
	int data;
	printf("enter the data to be inserted in the last: ");
	scanf("%d",&data);
	insertLast(head,data);
	printf("linked list data after insertion: \n");
	traverse=head;
	while(traverse!=NULL)
	{
		printf("%d\n",traverse->data);
		traverse=traverse->next;
	}
}
