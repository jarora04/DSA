#include<iostream>
using namespace std;
#include<stdlib.h>
#include<stdio.h>
#define MAX 10



struct quene{
    int arr[MAX];
    int front,rear;
};

void init(struct quene *q)
{
    q->front=-1;
    q->rear=-1;
}

void enquene(struct quene *q,int x)
{
    if(q->rear==MAX-1)
    {
        cout<<"the quene is full"<<endl;
    }
    else{
        q->rear++;
        q->arr[q->rear]=x;
        if(q->front==-1)
        {
            q->front=0;
        }
    }
}

int dequene(struct quene *q)
{
    if(q->front==-1)
    {
        cout<<"the quene is empty"<<endl;
    }
    else{
        int item;
        item=q->arr[q->front];
        q->front++;
        return item;
    }
}

void display1(struct quene q)
{
    while(q.front!=MAX-1)
    {
        cout<<q.arr[q.front]<<endl;
        q.front++;
    }
}

struct stack{
    int top=-1;
    int arr[MAX];
};

void push(struct stack *s ,int x)
{
    if(s->top==MAX-1)
    {
        cout<<"stack is full"<<endl;
    }
    else{
        s->top++;
        s->arr[s->top]=x;
    }
}

int pop(struct stack *s)
{
    if(s->top==-1)
    {
        cout<<"the stack is empty"<<endl;
    }
    else{
        int item;
        item=s->arr[s->top];
        s->top--;
        return item;
    }
}

void display(struct stack s)
{
    while(s.top!=-1)
    {
        cout<<s.arr[s.top]<<endl;
        s.top--;
    }
}



int main()
{
    struct stack s;
    struct quene q;
    init(&q);
    enquene(&q,10);
    enquene(&q,20);
    enquene(&q,30);
    push(&s,dequene(&q));
    push(&s,dequene(&q));
    push(&s,dequene(&q));
    enquene(&q,pop(&s));
    enquene(&q,pop(&s));
    enquene(&q,pop(&s));
    display1(q);
    return 0;

}