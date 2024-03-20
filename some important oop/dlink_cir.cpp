#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

struct dnode_cir{
    int data;
    struct dnode_cir *next,*prev;
};
    
void insert(struct dnode_cir **head,struct dnode_cir **last ,int num)
{
    struct dnode_cir *temp;
    temp=(struct dnode_cir*)malloc(sizeof(struct dnode_cir));
    temp->data=num;
    if(*head==NULL)
    {
        temp->next=temp;
        temp->prev=temp;
        (*head)=temp;
        (*last)=temp;
    }

    else{
        temp->prev=*last;
        temp->next=*head;
        (*head)->prev=temp;
        (*last)->next=temp;
        (*head)=temp;
    }

}

void del_node(struct dnode_cir **head,struct dnode_cir **last ,int num)
{
     struct dnode_cir *temp=*head;
     while(temp->data!=num)
     {
        temp=temp->next;
     }
     if(temp==*head)
     {
        *head=(*head)->next;
        (*head)->prev=*last;
        (*last)->next=*head;
     }
     else if(temp->next==*head)
     {
        *last=(*last)->prev;
        (*last)->next=*head;
        (*head)->prev=*last;
     }
     else{
       temp->prev->next=temp->next;
		temp->next->prev=temp->prev;
     }
     free(temp);
}
void display(struct dnode_cir *head)
{
cout<<head->data<<"\t";
struct dnode_cir *temp=head->next;
while(temp!=(head))
{
    cout<<temp->data<<"\t";
    temp=temp->next;
}
}


int main()
{
    struct dnode_cir *head,*last;
    last=NULL;
    head=NULL;
    insert(&head,&last,30);
    insert(&head,&last,40);
    insert(&head,&last,50); 
    insert(&head,&last,60);
    insert(&head,&last,70);
    insert(&head,&last,80);   
    display(head); 
    del_node(&head,&last,50);
    cout<<endl;
    display(head);

}