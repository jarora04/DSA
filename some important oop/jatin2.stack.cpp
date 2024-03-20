#include<iostream>
using namespace std;
#define MAX 10
class stack{
	public:
		char arr[MAX];
		int top=-1;
		 int isfull()
		 {
		 	if(top==MAX-1)
		 	{
		 		return 1;
			 }
			 else {
			 	return 0;
			 }
		 }
		 
		 int isempty(){
		 	if(top==-1)
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
		 		cout<<"overflow"<<endl;
			 }
			 else{
			 	top++;
			 	arr[top]=x;
			 }
		 }
		 
		 char pop()
		 {
		 	if(isempty())
		 	{
		 		cout<<"underflow"<<endl;
		 		return -1;
			 }
			 
			 else{
			 	char value =arr[top];
				 top--;
				 return value; 
			 }
		 }
		 
		 int match(char a, char b)
		 {
		 	if(a=='{'&& b=='}')
		 	{
		 		return 1;
			 }
			 	if(a=='['&& b==']')
		 	{
		 		return 1;
			 }
			 	if(a=='('&& b==')')
		 	{
		 		return 1;
			 }
			 
			 return 0;
		 }
		 
		 int parenthesis(char *p)
		 {
		 	int i;
		 	for(i=0;p[i]!='\0';i++)
		 	{
		 		if(p[i]=='{'||p[i]=='['||p[i]=='(')
		 		{
		 			push(p[i]);
				 }
				 
				 else if(p[i]=='}'||p[i]==']'||p[i]==')')
				 {
				 	if(isempty())
				 	{
				 		cout<<"underflow"<<endl;
				 		return 0;
					 }
					 char popped=pop();
					 if(!match(popped,p[i]))
					 {
					 	return 0;
					 }
				 }
			 }
			 if(isempty())
			 {
			 	return 1;
			 }
			 else{
			 	return 0;
			 }
		 }
	
};

int main()
{
	class stack s1;
	char *emp= "[[4-6]((8){(9-8])})";
	if(s1.parenthesis(emp))
	{
		cout<<"matches"<<endl;
	}
	
	else{
		cout<<"dont "<<endl;
	}
}