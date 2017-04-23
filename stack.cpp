#include <stdlib.h>
#define SIZE 100
int stack[SIZE];
int top;
spinlock stackLock;

void Push(int x)
{
	Lock(stackLock);
	if(top+1==SIZE)
	{
		cout <<"Stack Overflow!"<<endl;
		return;
	}
	top++;
	stack[top] = x;
	Unlock(stackLock);

}

int Pop()
{
	int x;
		Lock(stackLock);

  if(top == -1) {
    cout << "Stack Underflow"<<endl;
    return 0;
  }
  top--;
  x= stack[top+1];
 Unlock(stackLock);
 return x;

}

void Clear()
{

	Lock(stackLock);
	top=-1;
	Unlock(stackLock);

}

void testStack(int i)
{
	int counter;
	int rPush=rand()%5;
	int rPop =  rand()%5;
	int val;
	cout <<"In Process : "<<i<<endl;

	for(counter=0;counter<rPush;counter++)
	{
		val=rand();
		cout << "Pushing "<<val<<endl;

		Push(val);
	} 

	for(counter=0;counter<rPush;counter++)
	{
		cout<<"Popped :"<<Pop()<<endl;
	}
	

}

main()
{
	int i=0;

	Clear();

	forall i=0 to 100 do
	{
		testStack(i);
	}


}