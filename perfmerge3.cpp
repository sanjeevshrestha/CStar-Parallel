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


int recBinarySearch(int sortedArray[], int first, int last, int key) {
   if (first <= last) {
       int mid = (first + last) / 2;  
       if (key == sortedArray[mid]) 
           return mid;   
       else if (key < sortedArray[mid]) 
           return recBinarySearch(sortedArray, first, mid-1, key);
       else
           return recBinarySearch(sortedArray, mid+1, last, key);
   }
   return first;   
}


void searchAndMerge(int iIndex)
{
	int mIndex=0;
	mIndex=iIndex+recBinarySearch(Y,0,TOTALITEMS-1,X[iIndex]);	
	if(MERGED[mIndex]!=0)
	{
		mIndex++;
	}
	
	MERGED[mIndex]=X[iIndex];

	mIndex=iIndex+recBinarySearch(X,0,TOTALITEMS-1,Y[iIndex]);
	if(MERGED[mIndex]!=0 )
	{
		mIndex++;
	}

	MERGED[mIndex]=Y[iIndex];

}

void parallelMerge()
{
	int iCounter=0;

	forall iCounter=0 to TOTALITEMS-1 grouping 10 do
	{
		searchAndMerge(iCounter);
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
	cout <<"Merging in Parallel..."<<endl;
	parallelMerge();
	cout << "Wow! That was fast..."<<endl;
	cout <<"Here is the merged list..."<<endl;
	displayData(MERGED,2*TOTALITEMS);


	
}