
#include<iostream>
using namespace std;

struct dnode{
    int data;
    struct dnode *next;
    struct dnode *prev;
};

void push(struct dnode **top,int num)
{
    struct dnode *temp;
    temp=(struct dnode *)malloc(sizeof(struct dnode));
    temp->data=num;
    temp->next=NULL;
    temp->prev=NULL;
    if((*top)==NULL)
    {
        (*top)=temp;
    }
    else{
        temp->next=(*top);
        (*top)->prev=temp;
    }
    (*top)=temp;
}

int pop(struct dnode **top)
{
    int item;
    struct dnode *temp=*top;
    item=(*top)->data;
    (*top)=(*top)->next;
    free(temp);
    return item;
}
void display(struct dnode *top)
{
    while(top!=NULL)
    {
        cout<<top->data;
        top=top->next;
    }
}

int main()
{
    struct dnode *top=NULL;
    push(&top,10);
    push(&top,20);
    push(&top,40);
    //pop(&top);
    display(top);
}

