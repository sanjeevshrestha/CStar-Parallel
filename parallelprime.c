/**
* 
*/
#include<math.h>
#define MAX_NUM 100
#define MAX_PROCESS 10

boolean Primes[MAX_NUM+1];
struct Work{
	int start;
	int end;
	int step;
};

struct Work stream channelStream[MAX_PROCESS];


void worker(int channel)
{

	int i;
	struct Work recvWork;
	boolean receiving=true;
	while(receiving)
	{
		recv(channelStream[channel], recvWork);
		if(recvWork.start==0 && recvWork.end==0)
		{
			receiving=false;
			break;
		}

		cout<<"Work : S :"<<recvWork.start<<" E :"<<recvWork.end<<" step :"<<recvWork.step<<endl;

		for(i=recvWork.start;i<=recvwork.end; i+=recvWork.step)
		{
			Primes[i]=false;
		}
	}
	

}

void displayPrimes()
{ int i;
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
	int j;
	int start;
	int maxbound = (int)sqrt(MAX_NUM);
	cout<<"Parallel Prime Seive"<<endl<<"============================="<<endl;

	for(i=1;i<=MAX_NUM;i++)
	{
		Primes[i]=true;
	}

	for(i=2;i<=maxbound;i++)
	{
		if(Primes[i])
		{
			for(j=1;j<=MAX_PROCESS;j++)
			{
				if(j==1)
				{
					start= i*i;
				}
				else
				{
					start = (j-1)*MAX_NUM/MAX_PROCESS;
				}

				struct Work sendWork;
				sendWork.start=start;
				sendWork.end= j*MAX_NUM/MAX_PROCESS;
				sendWork.step=i;
				send(channelStream[j-1],sendwork);
			}

		}

	}


	forall i=0 to MAX_PROCESS-1 do
	{
		struct Work sendWork;
		sendWork.start=0;
		sendWork.end=0;
		sendWork.step=0;
		send(channelStream[i],sendWork);
		worker(i);
	}
	displayPrimes();

}