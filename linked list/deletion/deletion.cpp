/*delete a node with given value*/
/*assumption is that the list is not empty*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next;
};

void deleteNode(struct node** head_ref,int key)
{
	struct node* current; //node to keep track of current node
	struct node* prev;//node to keep track of previously visited node
	current=*head_ref;
	if(current->data==key)
	{
		current=current->next;
		free(current);
		return;
	}
	while(current!=NULL && current->data!=key)
	{
		prev=current;
		current=current->next;
	}
	if(current==NULL)
	{
		printf("element not found");
	}
	else
	{
		prev->next=current->next;
		free(current);
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
	int key;
	printf("data in list before deleting: \n");
	struct node* traverse=head;
	while(traverse)
	{
		printf("%d\n",traverse->data);
		traverse=traverse->next;
	}
	printf("enter the key value: ");
	scanf("%d",&key);
	deleteNode(&head,key);
	printf("data in list after deleting: \n");
	traverse=head;
	while(traverse)
	{
		printf("%d\n",traverse->data);
		traverse=traverse->next;
	}
}
