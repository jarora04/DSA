#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;
#define MAX 10
class stack{
	public:
		int top=-1;
		char a[MAX];
		int isempty()
		{
			if(top==-1)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		
		int isfull()
		{
			if(top==MAX-1)
			{
				return 1;
				
			}
			else{
				return 0;
			}
		}
		
		void push(int x)
		{
			if(isfull())
			{
				cout<<"stack is full"<<endl;
			}
			else{
				top++;
				a[top]=x;
			}
		}
		
		char pop()
		{
			if(isempty())
			{
				cout<<"underflow"<<endl;
			}
			else{
				char item;
				item=a[top];
				top--;
				return item;
			}
			
		}
		
int stacktop()
{
	return a[top];
}
int isoperator(char ch)
{
	if(ch=='+'||ch=='*'||ch=='-'||ch=='/')
	return 1;
	
	
	else
	return 0;
	
}

int precedence(char ch)
{
	if(ch=='*'||ch=='/')
	return 3;
	
	if(ch=='+'||ch=='-')
	return 2;
	
	else
	return 0;
}

char *infixtopostfix(char *infix)
{
	
	int i=0;
	int j=0;
	char *postfix=new char((strlen(infix)+1)*sizeof(char));
	while(infix[i]!='\0')
	{
		if(!isoperator(infix[i]))
		{
			postfix[j]=infix[i];
			i++;
			j++;
		}
		else{
		if(precedence(infix[i])>precedence(stacktop()))
		{
			push(infix[i]);
			i++;
		}
		else{
			postfix[j]=pop();
			j++;
		}
	}
	
	
		
	}
	while(!isempty())
	{
		postfix[j]=pop();
		j++;
	}
	postfix[j]='\0';
	return postfix;
}
};

int main()
{
	class stack s1;
	char ch[]="a+b*c";
	cout<<s1.infixtopostfix(ch);
}