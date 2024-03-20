#include<iostream>
using namespace std;

int main()
{
	int a[3][3],b[3][3];
	int m[3][3];
	
	// input of a
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			cout<<"enter the elements:a"<<endl;
			cin>>a[i][j];
		}
	
	}
		// input of b
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			cout<<"enter the elements:b"<<endl;
			cin>>b[i][j];
		}
	
	}
	//	input of m
		for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
		
			m[i][j]=0;
		}
	
	}

	//display of a
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			cout<<a[i][j]<<"\t";
		}
		cout<<"\n";
	}
		//display of b
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			cout<<b[i][j]<<"\t";
		}
		cout<<"\n";
	}

	
//multiplication
			for(int i=0;i<3;++i)
	{
		for(int j=0;j<3;++j)
		{
			for(int k=0;k<3;++k)
		m[i][j]+=a[i][k]*b[k][j];
		}
	
	}
	//display
		for(int i=0;i<3;++i)
	{
		for(int j=0;j<3;++j)
		{
			cout<<m[i][j]<<"\t";
		}
		cout<<"\n";
	}
	
}