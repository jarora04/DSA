#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

void insert(struct node **q,int x)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=x;
	temp->next=*q;
	*q=temp;
}

int transerve(struct node *ptr)
{

	while(ptr->next!=	NULL)
	{
	sum+=ptr->data;
		printf("element is :%d\n",ptr->data);
	
		if(ptr->next==NULL ||ptr==NULL)
		break;
		ptr=ptr->next->next;
	}
	return sum;
}
struct node *insertAt(struct node *head,int x)
{
	struct node *ptr=(struct node*)malloc(sizeof(struct node));
	ptr->data=x;
	ptr->next=head;
	return ptr;
};

struct node *inBetween(struct node *head,int x,int index)
{
	struct node *ptr =(struct node*)malloc(sizeof(struct node));
	struct node *p=head;
	int i=0;
	while(i!=index-1)
	{
		p=p->next;
		i++;
	}
	
	ptr->data=x;
	ptr->next=p->next;
	p->next=ptr;
	return head;
	
};

struct node *atend(struct node *head,int x)
{
	struct node *ptr=(struct node*)malloc(sizeof(struct node));
	struct node *p = head;
	while(p->next!=NULL)
	{
		p=p->next;
	}
	ptr->data=x;

	ptr->next=NULL;
	p->next=ptr;
	return head;
}
int main()
{
	struct node *head=NULL;
	insert(&head,10);
	insert(&head,14);
	insert(&head,15);
	insert(&head,16);
	insert(&head,17);
	insert(&head,18);
	insert(&head,19);
	printf("%d",transerve(head));
//	head =insertAt(head,51);
	printf("----------------------------\n");
	//head =inBetween(head,45,3);
//	head=atend(head,34);	
//	transerve(head);
}