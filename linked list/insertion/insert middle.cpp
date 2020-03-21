/*Linked list insertion after a node*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next;
};
void insert(struct node* prev_node,int data)
{
	if(prev_node==NULL)
	{
		printf("prev_node cannot be NULL");
		return;
	}
	struct node* newNode;
	newNode=(struct node*)malloc(sizeof(struct node));
	newNode->data=data;
	newNode->next=prev_node->next;
	prev_node->next=newNode;
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
	printf("enter the data to be inserted : ");
	scanf("%d",&data);
	printf("enter position to be inserted\n 1.head    2.second    3.third\n");
	int pos;
	scanf("%d",&pos);
	switch(pos)
	{
		case 1:
			insert(head,data);
			break;
		case 2:
			insert(second,data);
			break;
		case 3:
			insert(third,data);
			break;
		default:
			printf("invalid position");
	}
	printf("linked list data after insertion: \n");
	traverse=head;
	while(traverse!=NULL)
	{
		printf("%d\n",traverse->data);
		traverse=traverse->next;
	}
}


