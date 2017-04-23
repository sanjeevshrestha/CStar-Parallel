#define n 32
#define numiter 10

float A[n+2][n+2], B[n+2][n+2];
int i,x, k;

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

	for(k=1;k<=numiter;k++)
	{
		forall i=1 to n do
		{
			int j;
			for(j=1;j<=n;j++)
			{
				B[i][j]=(A[i-1][j]+A[i+1][j]+A[i][j-1]+A[i][j+1])/4;
			}
		}


		forall i=1 to n do
		{
			A[i]=B[i];
			}
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
	cout<<"Jacobi Relaxation Parallel";
	jacobi();
	return 0;
}