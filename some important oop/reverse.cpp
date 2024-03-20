#include<iostream>
using namespace std;


void display(int *a,int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<endl;
	}
}

void reverse(int *a,int &n)
{
	int i=0;
	int j=n-1;
	while(i<j)
	{
		int temp=a[i];
		a[i]=a[j];
		a[j]=temp;
		i++;
		j--;
	}
}
int main()
{
	int a[]={1,4,5,6,7,8};
	int n=6;
	
	display(a,n);
	reverse(a,n);
	cout<<"-----------"<<endl;
	display(a,n);
}