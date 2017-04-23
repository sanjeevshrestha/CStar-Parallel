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

int recBinarySearch(int sortedArray[], int first, int last, int key,int xmid) {
   if (first <= last) {
       int mid = (first + last) / 2;  
       if (key == sortedArray[mid]) 
           return mid;   
       else if (key < sortedArray[mid]) 
           return recBinarySearch(sortedArray, first, mid-1, key,mid);
       else
           return recBinarySearch(sortedArray, mid+1, last, key,mid);
   }
   return xmid;   
}


void parallelMerge()
{
	
}

/**
* Display outputlist
*/
void displayInput(int INP[])
{
	int counter=0;
	for(counter=0; counter<TOTALITEMS;counter++)
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
	cout << recBinarySearch(X,0,TOTALITEMS,3924,0);

	
}