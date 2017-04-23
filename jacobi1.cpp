#define numiter 10
#define n 32
float A[n+2][n+2], B[n+2][n+2];

int i,j,k;

void jacobi()
{
	for(i=0;i<=n+1;i++)
	{
		for(j=0;j<=n+1;j++)
		{
			cin>>A[i][j];
		}
	}

	B=A;

	for(k=0;k<numiter;k++)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				B[i][j]=(A[i-1][j]+A[i+1][j]+A[i][j-1]+A[i][j+1])/4;
			}
		}

		A=B;
	}

}

int main()
{
	cout <<"Jacobi Relaxation"<<endl;
	jacobi();
	return 0;
}