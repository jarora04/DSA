#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

struct node {
	int data;
	struct node *next;
};

void cirlink(struct node **front,struct node **rear,int x)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));

		temp->data=x;
		temp->next=NULL;
		
	if(*front==NULL)
	{
		*front=temp;
	
	}
	else{
		(*rear)->next=temp;
		
	}
	(*rear)=temp;
	(*rear)->next=(*front);
}

int cirlink_del(struct node **front,struct node **rear)
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
		free(temp);
		return item;
		*front==NULL;
		*rear=NULL;
	}
	else{
		(*front)=(*front)->next;
		(*rear)->next=(*front);\
		free(temp);
		return item;
	}

}

void display(struct node *front)
{
	struct node *temp=front->next;
		printf("%d",front->data);
	while(temp!=front)
	{
		printf("%d\t",temp->data);
		temp=temp->next;
	}

	
}

int iscir(struct node *q)
{
	struct node *ptr=q;

	while(ptr!=NULL && ptr->next!=q)
	{
	  ptr=ptr->next;
	}
	if(ptr==NULL)
	{
		cout<<"not circular"<<endl;
		return 1;
	}
	else if(ptr->next==q){
		cout<<"circular"<<endl;
		return 0;
	}
}

int main()
{
	struct node *front=NULL;
	struct node*rear=NULL;
	cirlink(&front,&rear,10);
	cirlink(&front,&rear,11);
	cirlink(&front,&rear,15);
	cirlink(&front,&rear,14);
	cirlink(&front,&rear,17);
	display(front);
	cout<<iscir(front);

	
	
}