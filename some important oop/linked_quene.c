#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *next;
};

void link_quene(struct node **front,struct node **rear,int x)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	if(temp==NULL)
	{
		printf("quene is full");
	}

		temp->data=x;
		temp->next=NULL;
		
	if(*front==NULL)
	{
		*front=temp;
		*rear=temp;
	}
	else{
		(*rear)->next=temp;
		(*rear)=temp;
	}
}

int link_delquene(struct node **front,struct node **rear)
{
	struct node *temp;
	int item;
	if(*front==NULL)
	{
		printf("empty");
		return NULL;
	}
	temp=*front;
	item=temp->data;
	if(*front==*rear)
	{
		*front==NULL;
		*rear=NULL;
	}
	else{
		(*front)=(*front)->next;
	}
	free(temp);
}

void display(struct node *front)
{
	;
	
	while(front->next!=NULL)
	{
		printf("%d\t",front->data);
		front=front->next;
	}
	printf("%d",front->data);
	
}

int main()
{
	struct node *front=NULL;
		struct node*rear=NULL;
	link_quene(&front,&rear,10);
	link_quene(&front,&rear,11);
	link_quene(&front,&rear,15);
	link_quene(&front,&rear,14);
	link_quene(&front,&rear,17);
	display(front);
	link_delquene(&front,&rear);
	display(front);
	
}