#include<iostream>
#include<string>
using namespace std;
#include<stdio.h>
#include<stdlib.h>
#define MAX 100

struct stk
{
    int q[MAX];
    int top;
} s,p;

void init(struct stk *s)
{
    s->top = -1;
}

void isFull(struct stk s)
{
    if (s.top == s.top - 1)
    {
        printf("full\n");
    }
    else
        printf("The stack is't full. :)\n");
}

void isEmpty(struct stk s)
{
    if (s.top == -1)
    {
        printf("the stack is empty :(\n");
    }
    else
        printf("The stack isn't empty. :)\n");
}

void push(struct stk *s, char n)
{
    if (s->top == MAX - 1)
    {
        printf("OVERFLOW");
    }
    else
    {
        s->top = s->top + 1;
        s->q[s->top] = n;
    }
}

char pop(struct stk *s)
{
    if (s->top == -1)
    {
        printf("UNDERFLOW\n");
        return NULL;
    }
    else
    {
        char item;
        item = s->q[s->top];
        s->top = s->top - 1;
        return item;
    }
}

void peek(struct stk *s)
{
    if (s->top == -1)
    {
        printf("Your stack is empty :(\n");
    }
    else
    {
        printf("%d\n", s->q[s->top]);
    }
}

void display(struct stk s)
{
	if(s.top==-1)
	{
		cout<<"stack is empty";
	}
    for (int i = s.top; i >= 0; i--)
    {
        printf("%d\n", pop(&s));
    }
}

int main()
{
	struct stk s1;
	init(&s1);
	
	char st[]="JATIN";
	int n=sizeof(st);

	for(int i=0;i<n;i++)
	{
		push(&s1,st[i]);
	}
	
	for(int i=n-1;i>=0;i--)
	{
		cout<<pop(&s1);
	}	
	
}
