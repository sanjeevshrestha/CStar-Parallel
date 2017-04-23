#define n 32
#define numiter 10

float A[n+2][n+2], B[n+2][n+2];
int i,x, k;

int count;

int stream synchan[n];

void barrier(int chan)
{
	int position, dummy;

position=1;
	while(chan/position%2==0 && position<n)
	{
		recv(synchan[chan],dummy);
		position=position*2;
	}

	if(chan!=0)
	{
		send(synchan[chan-position],1);
		recv(synchan[chan],dummy);
	}

	while(position>1)
	{
		position=position/2;
		send(synchan[chan+position],1);

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
		barrier(i-1);
		A[i]=B[i];
		barrier(i-1);
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
	cout<<"Jacobi Relaxation Tree Barrier";
	jacobi();

}