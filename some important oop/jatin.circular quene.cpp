#include<iostream>
using namespace std;
#define MAX 4

class quene{
	public:
		int a[MAX];
		int data,front,rear;
		
		void init()
		{
			front=-1;
			rear=-1;
		}
		
		
		void enquen(int x)
		{
			if(front==(rear+1)%MAX)
			{
				cout<<"overflow"<<endl;
			}
		
			
			else{
				rear=(rear+1)%MAX;
				a[rear]=x;
				if(front==-1)
				{
					front=0;
				}
			}
		}
		
		int dequene()
		{
			if(rear==front&&rear==-1)
			{
				cout<<"underflow"<<endl;
				return -1;
			}
			
			
			else{
				
				int item=-1;
				item=a[front];
				if(front==rear)
				{
					front=rear=-1;
					
				}
				else{
				front=(front+1)%MAX;
				}
				
				return item;
			}
		}
		void display()
		{
			if(rear<front){
			
			for(int i=front;i<MAX-1;i++)
			{
				cout<<"the elements are"<<a[i]<<endl;
			}
			for(int i=0;i<rear;i++){
					cout<<"the elements are"<<a[i]<<endl;
			}
		}
		else{
			for(int i=front;i<=rear;i++)
			{
					cout<<"the elements are"<<a[i]<<endl;
			}
		}
		}
		
		int peek(){
			if(rear==front&&rear==-1){
				cout<<"underflow"<<endl;
				return -1;
			}
			else{
				return a[front];
			}
		}
};

int main()
{
	class quene q;
	q.init();
	q.enquen(10);
	q.enquen(50);
	q.enquen(60);
	q.display();
	
	cout<<q.dequene()<<"\n";
	cout<<q.dequene()<<"\n";

	
	
	
	q.enquen(70);
	q.enquen(80);

	q.enquen(20);
	cout<<q.dequene()<<"\n";
	q.enquen(90);
	cout<<q.dequene()<<"\n";
	q.display();
	cout<<q.peek();
}