#define TOTALITEMS 2000

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

int max(int a, int b)
{
	if (a>=b)
	{
		return a;
	}

	return b;
}



 int binarySearch( int sortedArray[],  int left, int right,int key )
{
    int low  = left;
    int high = max( left, right + 1 );
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

int findNextEmptySlot(int index)
{
	while(MERGED[index]!=0)
	{
		index++;
	}
}

void sequentialMerge()
{
	int iCounter=0;
	int mIndex=0;
	int searchMax;

	for (iCounter=0;iCounter<TOTALITEMS;iCounter++)
	{
		searchmax=binarySearch(Y,0,TOTALITEMS-1,X[iCounter]);
		mIndex=iCounter+searchmax;
		while(MERGED[mIndex]!=0)
		{
			mIndex++;
		}

		MERGED[mIndex]=X[iCounter];

		searchmax=binarySearch(X,0,TOTALITEMS-1,Y[iCounter]);
		
		mIndex=iCounter+searchmax;
		while(MERGED[mIndex]!=0)
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
	cout <<"Read All Input..."<<endl;
	cout <<"Merging in Sequential..."<<endl;
	sequentialMerge();
	cout << "Nice Try! Could have been better..."<<endl;
	cout <<"Here is the merged list..."<<endl;
	displayData(MERGED,2*TOTALITEMS);

	
}