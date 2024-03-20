#include<stdio.h>
#include<stdlib.h>
int partition(int *a,int low,int up)
{
	int i,j,pivot,temp;
	pivot=a[low];
	i=low+1;
	j=up;
	while(i<=j)
	{
		while(a[i]<pivot&&i<up)
		{
			i++;
		}
		while(a[j]>pivot)
		{
			j--;
		}
		if(i<j)
		{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
			i++;
			j--;
		}
		else{
			i++;
		}
	}
	a[low]=a[j];
	a[j]=pivot;
	return j;
}


void quick(int *a,int low,int up)
{
	if(low>=up)
	{
		return;
	}
	int ploc;
	ploc=partition(a,low,up);
	quick(a,ploc+1,up);
	quick(a,low,ploc-1);
}



	
int main()
{
		int a[]={10,4,6,3,2,1};
		quick(a,0,5);
	for(int i=0;i<6;i++)
	{
		printf("%d\t",a[i]);
	}
}
	
