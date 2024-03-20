#inluude<iostrem>
using namespace std;
#inlcude<stdio.h>
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
	display(head);