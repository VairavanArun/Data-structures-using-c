/*PROGRAM TO DETECT CYCLES IN LINKED LIST*/
/*The algorithm is as follows*/
/*Use two pointers slowPtr and fastPtr, slowPtr points to the next node
fastPtr jumps two nodes at a time. If slowPtr and fastPtr meet at a point then there is a loop*/

#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next;
};

void detectLoop(struct node* head)
{
	struct node* slowPtr;
	struct node* fastPtr;
	slowPtr=head;
	fastPtr=head;
	while(slowPtr&&fastPtr&&fastPtr->next)
	{
		if(slowPtr==fastPtr)
		{
			printf("Cylce found");
			return ;
	    }
		slowPtr=slowPtr->next;
		fastPtr=fastPtr->next->next;
	}
	printf("Cylce not found");
}

int main()
{
	struct node* head;
	struct node* first;
	struct node* second;
	struct node* third;
	head=(struct node*)malloc(sizeof(struct node));
	first=(struct node*)malloc(sizeof(struct node));
	second=(struct node*)malloc(sizeof(struct node));
	third=(struct node*)malloc(sizeof(struct node));
	head->data=1;
	head->next=first;
	first->data=2;
	first->next=second;
	second->data=3;
	second->next=third;
	third->data=4;
	third->next=first;//loop created
	/*linked list representation
    
    head          first        second         third
    ----  ---     ----  ---    ----  ---      ----  ---
      1 |   ----->  2 |   ---->  3 |   ------>  4 |   ---- 
    ----  ---     ----  ---    ----  ---      ----  ---  |
                    ^                                    |
					|                                     |
					-------------------------------------- 
	*/
	detectLoop(head);				                         
}
