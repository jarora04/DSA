#include<stdio.h>
#include<stdlib.h>

void selection_sort(int *a,int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(a[i]>a[j])
			{
				int temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
}
void display(int *a,int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
}

int main()
{
	int a[]={8,3,1,5,2};
	int n=sizeof(a)/sizeof(a[0]);
	display(a,n);
	selection_sort(a,n);
	printf("\n");
	display(a,n);
}