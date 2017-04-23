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


void parallelMerge()
{
	int iCounter=0;
	int mIndex=0;

	for (iCounter=0;iCounter<TOTALITEMS;iCounter++)
	{
			mIndex=iCounter+recBinarySearch(Y,0,TOTALITEMS-1,X[iCounter]);
		if(MERGED[mIndex]!=0 && mIndex<TOTALITEMS-2)
			{
				mIndex++;
			}
			MERGED[mIndex]=X[iCounter];

			mIndex=iCounter+recBinarySearch(X,0,TOTALITEMS-1,Y[iCounter]);
		if(MERGED[mIndex]!=0 && mIndex<TOTALITEMS-2)
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
	parallelMerge();
	cout << "Nice Try! Could have been better..."<<endl;
	cout <<"Here is the merged list..."<<endl;
	displayData(MERGED,2*TOTALITEMS);

	
}