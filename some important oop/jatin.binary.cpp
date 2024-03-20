#include<iostream>
using namespace std;

int main()
{
	int arr[]={1,2,3,4,6,7,8,9};
	int low,mid,high;
	low=0;
	int element;
	cout<<"enter the element to be found;"<<endl;
	cin>>element;
	int n;
	cout<<"size of the array is "<<endl;
	cin>>n;
	
	high=n-1;
	int found;
	
	while(low<=high)
	{
		mid=(high+low)/2;
		if(arr[mid]==element)
		{
		cout<<"the position of the  element is"<<mid<<endl;
		}
		if(arr[mid]<element)
		{
			low=mid;
		}
		
		else
		{
			high=mid;
		}
	}
	return 0;
	
}