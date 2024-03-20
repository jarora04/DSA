#include<iostream>
using namespace std;
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

void display(struct node *q)
{
    while(q!=NULL)
    {
        cout<<q->data<<"\t";
        q=q->next;
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
	struct node *head=NULL;
	insert(&head,10);
	insert(&head,14);
	insert(&head,15);
	insert(&head,16);

	display(head);
    cout<<endl;
    cout<<iscir(head);
    
}