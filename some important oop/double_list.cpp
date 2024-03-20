#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

struct dnode{
	int data;
	struct dnode *next,*prev;
};

void insert_begin(struct dnode **head,int num)
{
	struct dnode *temp;
	temp=(struct dnode*)malloc(sizeof(struct dnode));
	if((*head)==NULL)
	{
		temp->next=NULL;
		temp->data=num;
		temp->prev=	NULL;
	
		}	
		
	else{
		temp->next=(*head);
		temp->prev=NULL;
		temp->data=num;
		(*head)->prev=temp;
	}	
		(*head)=temp;
}

void insert_end(struct dnode **head,int num)
{
	struct dnode *temp,*r;
	r=(*head);
	temp=(struct dnode *)malloc(sizeof(struct dnode));
	if((*head)==NULL)
	{
		temp->data=num;
		temp->next=NULL;
		temp->prev=NULL;
		(*head)=temp;
	}
else{
	

	while(r->next!=NULL)
	{
		r=r->next;
	}
	temp->prev=r;
	temp->data=num;
	temp->next=NULL;
	r->next=temp;
}
}

void insert_middle(struct dnode **head,int num,int pos)
{
	struct dnode *temp,*r=(*head);
	
	temp=(struct dnode*)malloc(sizeof(struct dnode));
	if(pos==-1)
	{
		temp->data=num;
		temp->next=r;
		temp->prev=NULL;
		(*head)=temp;
	}
	else{
		int i=0;
		while(i!=pos)
		{
			r=r->next;
			i++;
		}
		temp->data=num;
		temp->next=r->next;
		r->next->prev=temp;
		temp->prev=r;
		r->next=temp;
		if(r->next==NULL)
		{
			temp->next=NULL;
			temp->data=num;
			r->next=temp;
			temp->prev=r;
		}
	}
}

void display(struct dnode *head)
{
	while(head!=NULL)
	{
		cout<<head->data<<"\t";
		head=head->next;
	}
}


void insert_middle1(struct dnode **head,int num,int num1)
{
	struct dnode *temp,*r=(*head);
	temp=(struct dnode*)malloc(sizeof(struct dnode));
	temp->data=num;
	if(r->data==num1)
	{
		temp->prev=NULL;
		temp->next=r;
		r->prev=temp;
	 	(*head)=temp;
	}
	else{
		while(r->data!=num1 && r->next!=NULL )
		{
			r=r->next;
		}
		
	
		temp->next=r;
		temp->prev=r->prev->next;
		r->prev->next=temp;
		r->prev=temp;
	}
	
	
}

void del_node(struct dnode **head,struct dnode *del)
{
	struct dnode *temp;
	temp=*head;
	
	while(temp!=NULL && temp->data!=del->data)
	{
		temp=temp->next;
		
	}
	if(temp==*head)
	{
		(*head)=(*head)->next;
		(*head)->prev=NULL;
	}
	else if(temp ->next == NULL)
	{
		temp->prev->next=NULL;
	}
	else{
		temp->prev->next=temp->next;
		temp->next->prev=temp->prev;
	}
	free(temp);
	
}

void duplicate(struct dnode **head)
{
    struct dnode *ptr1;
    struct dnode *ptr2;
    
   for(ptr1=*head;ptr1!=NULL;ptr1=ptr1->next)
   {
        ptr2=ptr1->next;
        while(ptr2!=NULL)
        {
            if(ptr1->data==ptr2->data)
            {
                struct dnode *ptr3=ptr2->next;
                del_node(head,ptr2);
                ptr2=ptr3;
            }
            else
            ptr2=ptr2->next;
        }
        
    }
    
}


int main()
{
	struct dnode *head=NULL;
	insert_begin(&head,10);
	insert_begin(&head,20);
	insert_begin(&head,30);
	insert_begin(&head,40);
	insert_begin(&head,10);
//	insert_middle1(&head,69,30);
	display(head);
//	del_node(&head,50);
duplicate(&head);
	cout<<endl;
	display(head);
}
