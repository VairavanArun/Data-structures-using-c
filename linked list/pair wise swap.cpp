/*Pairwise swapping of elements*/
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

void pairWiseSwap(struct node** head)
{
	struct node* current;//current stores the first element in pair
	struct node* next;//next stores the second element in pair
	struct node* temp;
	current=*head;//first node
	next=current->next;//second node
	while(current && (next=current->next))//check whether both the nodes in the pair are present
	{
		if(next->next && next->next->next)//check if both elements are present in next pair
		{
			current->next=next->next->next;
			/*if present make current node to point to third node from current.
			consider the linked list 1->2->3->4->5
			afte pair wise swap, the linked list becomes 2->1->4->3->5
			if current node is 1, after swapping it is pointing to 4, that is three nodes away from 1*/
		}
		else
		{
			current->next=next->next;
			/*in case of odd number of elements, the last pair will contain only one node, and make the current node to point to it*/
		}
		temp=next->next;
		next->next=current;//make next node to point to current node, that is 2->1 after swapping
		if(current==*head)
		{
			*head=next;//if current node is head node, change head to next. that is change head to 2
		}
		current=temp;//make the first element in next pair as current node
	}
}

int main()
{
	struct node* head=NULL;
	head=createLL(head);
	if(head)
	{
		printf("\nLinked list before pairwise swap:");
		displayLL(head);
		pairWiseSwap(&head);
		printf("\nLinked list after pairwise swap");
		displayLL(head);
	}
}
