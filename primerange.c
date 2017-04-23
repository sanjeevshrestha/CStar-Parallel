/**
* Program to find prime numbers by
* Sieve Algorithm
*/
#include <math.h>
#define MAX_NUM 65
#define START 50
boolean Primes[MAX_NUM+1];
int i, num, loc;

void displayPrimes()
{
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
	cout <<"Prime Numbers"<<endl;

	for (i=START;i<=MAX_NUM;i++)
	{
		Primes[i]=true;
		for(num=START;num<=MAX_NUM;num++)
		{
			if(Primes[num]){
				loc= num+num;
				while(loc<=MAX_NUM)
				{
					Primes[loc]=false;
					loc=loc+num;
				}
			}
		}
	}
	displayPrimes();
}

