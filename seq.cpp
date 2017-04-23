#define TOTALITEMS 100

int X[TOTALITEMS],Y[TOTALITEMS],MERGED[2*TOTALITEMS];

/**
* Read Input from Infile
*/
void readInput()
{
	int counter=0;
	for(counter=0; counter<TOTALITEMS;counter++)
	{
		cin>>X[counter];
	}

	for(counter=0; counter<TOTALITEMS;counter++)
	{
		cin>>Y[counter];
	}
}

int max(int a,int b)
{
	if (a>=b)
	 return a;
	
	return b;
}

int recBinarySearch(int sortedArray[], int first, int last, int key) {

	int low =  first;
	int high = max(first,last+1);

	 while( low < high )
    {
        int mid = ( low + high ) / 2;
        if ( key <= sortedArray[ mid ] ) 
        	high = mid;
        else 
        	low  = mid + 1;                                        
    }
    
    return high;
  
}


void parallelMerge()
{
	int iCounter=0;
	int mIndex=0;

	for (iCounter=0;iCounter<TOTALITEMS;iCounter++)
	{
			mIndex=iCounter+recBinarySearch(Y,0,TOTALITEMS,X[iCounter]);
			cout << "M Index : "<<mIndex<< " Value : "<<X[iCounter]<<endl;
			MERGED[mIndex]=X[iCounter];
	}

	for (iCounter=0;iCounter<TOTALITEMS;iCounter++)
	{
			mIndex=iCounter+recBinarySearch(X,0,TOTALITEMS,Y[iCounter]);
						cout << "M Index : "<<mIndex<< " Value : "<<Y[iCounter]<<endl;
			if(MERGED[mIndex]!=0)
			{
				mIndex++;
			}

			MERGED[mIndex]=Y[iCounter];
	}
}

/**
* Display outputlist
*/
void displayData(int INP[],int size)
{
	int counter=0;
	for(counter=0; counter<size;counter++)
	{
		cout << INP[counter] ;
		cout << endl;
	}

}


int main()
{
	cout<<"Parallel Merge Sort Program" << endl<< "============================"<<endl;
	cout << "Reading Input ... "<<endl;
	readInput();
	parallelMerge();

	displayData(MERGED,TOTALITEMS);

	
}