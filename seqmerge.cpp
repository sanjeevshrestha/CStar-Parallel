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

int recBinarySearch(int sortedArray[], int first, int last, int key) {
   if (first <= last) {
       int mid = (first + last) / 2;  
       if (key == sortedArray[mid]) 
       {
       		cout << "mid "<<mid<<" ";
           return mid;   
       }
       else if (key < sortedArray[mid]) 
           return recBinarySearch(sortedArray, first, mid-1, key);
       else
           return recBinarySearch(sortedArray, mid+1, last, key);
   }
   cout <<"First : "<<first<<endl;
   return first;   
}


void parallelMerge()
{
	int iCounter=0;
	int mIndex=0;

	for (iCounter=0;iCounter<TOTALITEMS;iCounter++)
	{
			mIndex=iCounter+binarySearch(Y,0,TOTALITEMS-1,X[iCounter]);
		if(MERGED[mIndex]!=0)
			{
				mIndex++;
			}
			MERGED[mIndex]=X[iCounter];

		cout <<"mIndex : "<<mIndex<<" Value : "<<MERGED[mIndex]<<endl;

			mIndex=iCounter+binarySearch(X,0,TOTALITEMS-1,Y[iCounter]);
		if(MERGED[mIndex]!=0)
			{
				mIndex++;
			}
			MERGED[mIndex]=Y[iCounter];

		cout <<"mIndex : "<<mIndex<<" Value : "<<MERGED[mIndex]<<endl;
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
	parallelMerge();
	cout << "Nice Try! Could have been better..."<<endl;
	cout <<"Here is the merged list..."<<endl;
	displayData(MERGED,2*TOTALITEMS);

	
}