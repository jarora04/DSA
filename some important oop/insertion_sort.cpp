#include<iostream>
using namespace std;


void inertsort(int arr[])
{
int temp;
int j;
	for(int i=0;i<4;i++)
	{
		
		temp=arr[i];
		j=i;
		while(j>0 && arr[j-1]>temp)
		{
			arr[j]=arr[j-1];
			j--;
			arr[j]=temp;
		
		}
	}
}
void display(int arr[])
{
	for(int i=0;i<4;i++)
	{
		cout<<"the element value is"<<arr[i]<<"\n";
	}
}

int main()
{
	int arr[]={1,6,4,3};
	display(arr);
	cout<<"-------------"<<endl;
	inertsort(arr);
	display(arr);
}