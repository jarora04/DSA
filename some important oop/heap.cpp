#include<iostream>
using namespace std;
#include<stdio.h>
#include<stdlib.h>

void insert_max_heap(int heap[],int s,int ele)
{
    int p=(s-1)/2;
    while(s>0 && heap[p]<ele)
    {
        heap[s]=heap[p];
        s=p;
        p=(s-1)/2;
    }
    heap[s]=ele;
}
void heapify(int heap[],int n,int i)
{
    int t,large,leftchild,rightchild;
    large=i;
    leftchild=2*i+1;
    rightchild=2*i+2;

    if(leftchild<n && heap[leftchild]>heap[large])
    {
        large=leftchild;
    }
    if(rightchild<n&&heap[rightchild]>heap[large])
    {
        large=rightchild;
    }
    if(large!=i)
    {
        t=heap[i];
        heap[i]=heap[large];
        heap[large]=t;
        heapify(heap,n,large);

    }

}


void build_heap(int heap[],int n)
{
    int lastnonleaf=n/2-1,i;
    
    for (i = lastnonleaf; i >=0; i--)
    {
       
        heapify(heap,n,i);
    }
   
    
}

void heap_sort(int x[],int n)
{
    
    build_heap(x,n);
    
    int t;
    while(n!=1)
    {
        t=x[0];
        x[0]=x[n-1];
        x[n-1]=t;
        n--;
        heapify(x,n,0);

    }

}

void display(int heap[],int n)
{
    for (int i = 0; i < n; i++)
    {
        cout<<heap[i]<<endl;
    }
    
}

int main()
{
    int heap[9]={25,57,48,37,12,92,110,5,6};
    for (int  i = 0; i < 9; i++)
    {
        insert_max_heap(heap,i,heap[i]);
    }
    display(heap,9);
    heap_sort(heap,9);
    display(heap,9);
    
}