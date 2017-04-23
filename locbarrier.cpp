#define n 32
#define numiter 10

float A[n+2][n+2], B[n+2][n+2];
int i,x, k;

int count;

int stream higher[n+1], stream lower[n+1];

void barrier(int i)
{
	int dummy;

	if(i>1)
	{
		send(higher[i-1],1);
	}
	if(i<n)
	{
		send(lower[i+1],1);
		recv(higher[i],dummy);
	}
	if(i>1)
	{
		recv(lower[i],dummy);
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
		barrier(i);
		A[i]=B[i];
		barrier(i);
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