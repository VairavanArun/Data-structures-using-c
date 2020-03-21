/*Linked list insertion in the beginning*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next;
};
/* Reason for using struct node** head in insertFront():
consider the location of first node in linked list is 1000.
Therefore 1000 will be stored in head, consider head's memory location is 500.
Now if we pass head to insert instead of &head the following thing happens.
Insert will create a copy of head, lets say its memory location is 2000 and the memory location of newly
created node be 4000. So after creation head's value is changed to 4000. but here head is stored in memory location 2000.
control returns to main function. Here the address of head is 500 and value in head is still 1000, but our motive is to have 4000 in head.
If address of head is passed this will happen.
Let insert function create head at memory location 2000 and it has value 500(address of head in main function).
Now new node is created and let it address be 4000. now we assign *head=newnode.
That is head contains 500, *head refers to memory location 500 and hence memory locatoin 500=4000.
Now control is transferred to main function and address of head is 500. We have 4000 in the memory location 500. 
Hence we need to pass address of head*/
void insertFront(struct node** head,int data)
{
	struct node* newNode;
	newNode=(struct node*)malloc(sizeof(struct node));
	newNode->data=data;
	newNode->next=*head;
	*head=newNode;
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
	printf("enter the data to be inserted in the front: ");
	scanf("%d",&data);
	insertFront(&head,data);
	printf("linked list data after insertion: \n");
	traverse=head;
		while(traverse!=NULL)
	{
		printf("%d\n",traverse->data);
		traverse=traverse->next;
	}
}

