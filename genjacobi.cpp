#include <stdlib.h>
#define num 34

main()
{
	int i,j;
	for(i=0;i<num;i++)
	{
		for(j=0;j<num;j++)
		{
			cout<< rand() % 20;
			cout<<endl;
		}
	}
}