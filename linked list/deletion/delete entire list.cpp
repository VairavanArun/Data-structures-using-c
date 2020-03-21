/*delete the entire list*/
/*assumption is that the list is not empty*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next;
};

void deleteList(struct node** head_ref)
{
	struct node* current=*head_ref;
	struct node* next;
	while(current!=NULL)
	{
		next=current->next;
		free(current);
		current=next;
	}
	*head_ref=NULL;
}

int main()
{
	struct node* head;
	struct node* second;
	struct node* third;
	struct node* fourth;
	head=(struct node*)malloc(sizeof(struct node));
	second=(struct node*)malloc(sizeof(struct node));
	third=(struct node*)malloc(sizeof(struct node));
	head->data=1;
	head->next=second;
	second->data=2;
	second->next=third;
	third->data=3;
	third->next=NULL;
	int position;
	printf("data in list before deleting: \n");
	struct node* traverse=head;
	while(traverse)
	{
		printf("%d\n",traverse->data);
		traverse=traverse->next;
	}
	deleteList(&head);
	printf("data in list after deleting: \n");
	traverse=head;
	while(traverse)
	{
		printf("%d\n",traverse->data);
		traverse=traverse->next;
	}
}
