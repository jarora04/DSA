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

void transverse(struct node *ptr)
{
	while(ptr!=NULL)
	{
		printf("element: %d\n",ptr->data);
		ptr=ptr->next;
	}
}

struct node *atfirst(struct node *head)
{
	struct node *ptr=head;
	head=head->next;
	free(ptr);
	return head; 
}

struct node *inbetween(struct node *head,int index)
{
	struct node *p=head;
	struct node *q=p->next;
	for(int i=0;i<index-1;i++)
	{
		p=p->next;
		q=q->next;
	}
	p->next=q->next;
	free(q);
	return head;
}

struct node *end(struct node *head)
{
	struct node *p=head;
	struct node *q=head->next;
	while(q->next!=NULL)
	{
			p=p->next;
			q=q->next;
	}
	
	p->next=NULL;
	free(q);
	return head;
}

struct node *between(struct node *head,int x)
{
	struct node *ptr=head;
	struct node *q=head->next;
	while(q->data!=x&&q->next!=NULL)
	{
		q=q->next;
		ptr=ptr->next;
	}
	if(q->data==x)
	{
		ptr->next=q->next;
		free(q);
	}
	return head;
}
int main(){
	struct node *head=NULL;
	insert(&head,14);
	insert(&head,15);
	insert(&head,16);
	insert(&head,17);
	insert(&head,13);
	transverse(head);
	printf("-------------");
	
	//head=atfirst(head);
	//head=inbetween(head,3);
//	head=end(head);
	head=between(head,16);
		transverse(head);
	
}