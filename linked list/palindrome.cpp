/*Check whether Linked List is a palindrome*/
/*Algorithm is:
Find the middle of the list
reverse the second half of the list 
use two pointers start and secondHalf
start = head
secondHalf=middle->next that is it points to the next node to the middle
check if start->data==secondHalf->data
if no its not a palindrome
loop until the end of the list
by making start=start->next and secondHalf=secondHalf->next
if still start->data==secondHalf->data
it is a palindrome*/

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

struct node* findMiddle(struct node* head)
{
	struct node* slowPtr;
	struct node* fastPtr;
	slowPtr=head;
	fastPtr=head;
	while(fastPtr!=NULL && fastPtr->next!=NULL)
	{
		slowPtr=slowPtr->next;
		fastPtr=fastPtr->next->next;
	}
	return slowPtr;
}

void reverse(struct node* middle)
{
	struct node* current;
	struct node* prev;
	struct node* next;
	prev=NULL;
	current=middle->next;
	while(current)
	{
		next=current->next;
		current->next=prev;
		prev=current;
		current=next;
	}
}
void checkPalindrome(struct node* head)
{
	if(head==NULL)
	{
		printf("\nempty list");
		return ;
	}
	struct node* start;
	struct node* middle;
	start=head;
	middle=findMiddle(head);
	reverse(middle);
	struct node* secondHalf=middle->next;
	while(secondHalf)
	{
		if(start->data!=secondHalf->data)
		{
			printf("\nNot a palindrome");
			return ;
		}
		start=start->next;
		secondHalf=secondHalf->next;
	}
	printf("\nIt is a palindrome");
	return ;
}

int main()
{
	struct node* head=NULL;
	head=createLL(head);
	checkPalindrome(head);
}


