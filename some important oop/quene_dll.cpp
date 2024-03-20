#include<iostream>
using namespace std;

struct dnode{
    int data;
    struct dnode *next;
    struct dnode *prev;
};

void enquene(struct dnode **front,struct dnode **rear,int num)
{
    struct dnode *temp;
    temp=(struct dnode *)malloc(sizeof(struct dnode));
    temp->data=num;
    temp->prev=NULL;
    temp->next=NULL;
    if((*rear)==NULL)
    {
        
        (*rear)=temp;
        (*front)=temp;
    }
    else{
       (*rear)->next=temp;
        temp->prev=(*rear);
    }
    (*rear)=temp;
}

int dequene(struct dnode **front,struct dnode **rear)
{
    int item;
    struct dnode *temp=(*front);
    item=temp->data;
    if((*front)==(*rear))
    {
        (*front)=NULL;
        (*rear)=NULL;
    }
    else{
        (*front)=(*front)->next;
    }
    free(temp);
    return item;
}

void display(struct dnode *front)
{
    
    while(front!=NULL)
    {
        cout<<front->data;
        front=front->next;
    }
}

int main()
{
    struct dnode *f=NULL;
    struct dnode *r=NULL;
    enquene(&f,&r,10);
    enquene(&f,&r,20);
    enquene(&f,&r,30);
    dequene(&f,&r);
    display(f);
}