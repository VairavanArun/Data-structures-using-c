/*linked list length calculation*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next;
};

int linkedlistLength(struct node* head)
{
	struct node* current=head;
	int count=0;
	while(current)
	{
		count++;
		current=current->next;
	}
	return count;
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
	int length=linkedlistLength(head);
	printf("length=%d",length);
}
