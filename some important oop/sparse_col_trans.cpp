#include<iostream>
using namespace std;

int main()
{
	int a[5][6]={
	{0,3,0,0,0,0},
	{0,0,0,1,0,0},
	{1,0,0,0,0,0},
	{0,0,2,0,0,0},
	{0,0,0,0,3,0},
	};
	
	int res[30][3];
	int h=0;
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<6;j++)
		{
			if(a[i][j]!=0)
			{
				res[h][0]=i;
				res[h][1]=j;
				res[h][2]=a[i][j];
				h++;
			}
		}
	}
	
	
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<3;j++)
		{
			cout<<res[i][j];
			cout<<"\t";
		}
		cout<<"\n";
	}
	
	
	int trans[30][3];
	int t=0;
	for(int j=0;j<6;j++)
	{
			for(int i=0;i<5;i++)
		{
			if(a[i][j]!=0)
			{
				trans[t][0]=j;
				trans[t][1]=i;
				trans[t][2]=a[i][j];
				t++;
			}
		}
	}
	cout<<"\n";
		for(int i=0;i<t;i++)
	{
		for(int j=0;j<3;j++)
		{
			cout<<trans[i][j];
			cout<<"\t";
		}
		cout<<"\n";
	}
}