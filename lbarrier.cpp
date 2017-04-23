#define n 32
#define numiter 10

float A[n+2][n+2], B[n+2][n+2];
int i,x, k;

int count;
spinlock Arrival, Departure;

void barrier()
{
	Lock(Arrival);
	count++;
	if(count<n)
	{
		Unlock(Arrival);
	}
	else
	{
		Unlock(Departure);
	}

	Lock(Departure);
	count--;

	if(count>0)
	{
		Unlock(Departure);
	}
	else
	{
		Unlock(Arrival);
	}

}

void jacobi()
{
	for(i=0;i<=n+1;i++)
	{
		for(x=0;x<=n+1;x++)
		{
			cin>>A[i][x];
		}
	}

	B=A;
	
	forall i=1 to n do{
		int j,k;
		for(k=1;k<=numiter;k++)
		{
			for(j=1;j<=n;j++)
			{
				B[i][j]=(A[i-1][j]+A[i+1][j]+A[i][j-1]+A[i][j+1])/4;
			}
		}
		barrier();
		A[i]=B[i];
		barrier();
	}

for(i=0;i<=n+1;i++)
	{
		for(x=0;x<=n+1;x++)
		{
			cout<<A[i][x]<<endl;
		}
	}

}


main()
{
	cout<<"Jacobi Relaxation";
	count=0;
	Unlock(Arrival);
	Lock(Departure);
	jacobi();

}