/**
* Program to find Prime number using Sieve of Eratosthenes
* using Parallel Process
* @Author Sanjeev
* @ID 984970
*/
#include<math.h>
#define MAX_NUM 10000
#define MAX_PROCESS 100

boolean Primes[MAX_NUM+1];
int maxbound;
int stream primeChannel[MAX_PROCESS];
int worker_thread=MAX_PROCESS-1;

void worker(int channel)
{
	int i,i1=0, bound_lower, bound_upper, current;
	boolean receiving=true;
	if (channel ==0)
	{
		for(i=1;i<=MAX_NUM;i++)
		{
			Primes[i]=true;
		}

		for(i1=2;i1<=maxbound;i1++)
		{
			if(Primes[i1])
			{
				send(primeChannel[channel+1],i1);
			}
		}

		send(primeChannel[channel+1],0);


	}
	else
	{

		bound_lower =  (channel-1)*(MAX_NUM/(worker_thread))+1;
		bound_upper =  (channel)*(MAX_NUM/(worker_thread))+1;

		while(receiving)
		{
			recv(primeChannel[channel],i1);

			if(channel<MAX_PROCESS-1)
			{
				send(primeChannel[channel+1],i1);
			}

			if(i1==0)
			{
				receiving=false;
				break;
			}
		
			current = i1+i1;
			while(bound_lower<=bound_upper&&current<=bound_upper)
			{
				Primes[current]=false;
				current=current+i1;
			}


		}


	}

}

void displayPrimes()
{
	int i;
	for(i=1;i<=MAX_NUM;i++)
	{
		if(Primes[i])
		{
			cout<<i<<endl;
		}
	}
}

int main()
{
	int i=0;
	maxbound=(int) sqrt(MAX_NUM);

	forall i=0 to MAX_PROCESS-1 do
	{
		worker(i);
	}

	displayPrimes();

}