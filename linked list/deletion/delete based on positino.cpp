/*delete a node at a given position*/
/*assumption is that the list is not empty*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next;
};

void deleteNode(struct node** head_ref,int position)
{
	struct node* temp,*prev;
	int k=1;
	temp=*head_ref;
	if(position==1)
	{
		*head_ref=temp->next;
		free(temp);
		return;
	}
	else
	{
		while(temp!=NULL && k<position)
		{
			k++;
			prev=temp;
			temp=temp->next;
		}
		prev->next=temp->next;
		free(temp);
	}
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
	printf("enter the position: ");
	scanf("%d",&position);
	deleteNode(&head,position);
	printf("data in list after deleting: \n");
	traverse=head;
	while(traverse)
	{
		printf("%d\n",traverse->data);
		traverse=traverse->next;
	}
}
