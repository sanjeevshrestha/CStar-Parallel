/**
* Parallel Merge of 2000 Items in two sorted list 
* @author Sanjeev Shrestha
* @email sanjeevshrestha2004@gmail.com
* @studentID : 984970
* @date : 17 March 2017
* 
*/
#define TOTALITEMS 2000

int X[TOTALITEMS],Y[TOTALITEMS],MERGED[2*TOTALITEMS];

spinlock indexLock;

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

/** 
* Not used.  uses less processor but is slower
*/
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



/**
* Search for right position in the other array.
*/
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



void searchAndMerge(int index, int A[], int B[])
{
	int iIndex=0;
	int s=recBinarySearch(B,0,TOTALITEMS-1,A[index]);
	iIndex=index+s;

	Lock(indexLock);
	while(MERGED[iIndex]!=0) 
	{
		iIndex++;
	}
	MERGED[iIndex]=A[index];
	Unlock(indexLock);
}

/**
* Parallel Merge Main Handler
*/
void parallelMerge()
{
	int iCounter=0;
	

	for (iCounter = 0; iCounter<TOTALITEMS;iCounter++)
	{
		FORK searchAndMerge(iCounter,X,Y);
		FORK searchAndMerge(iCounter,Y,X);
		
	}

	for (iCounter = 0; iCounter<TOTALITEMS;iCounter++)
	{
		JOIN;
		JOIN;
		
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

/**
* This is the main 
*/
int main()
{
	cout<<"Parallel Merge Sort Program" << endl<< "============================"<<endl;
	cout << "Reading Input ... "<<endl;
	readInput();
	cout <<"Read All Input..."<<endl;
	cout <<"Merging in Parallel..."<<endl;
	parallelMerge();
	cout << "Wow! That was fast but could be better..."<<endl;
	cout <<"Here is the merged list..."<<endl;
	displayData(MERGED,2*TOTALITEMS);

	
}