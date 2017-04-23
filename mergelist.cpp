/**
* Parallel Merge of 100 Items in two sorted list
* @author Sanjeev Shrestha
* @email sanjeevshrestha2004@gmail.com
* @studentID : 984970
* @date : 17 March 2017
* 
*/
#define TOTALITEMS 100

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
	int s=binarySearch(B,0,TOTALITEMS-1,A[index]);
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
	forall iCounter =  0 to TOTALITEMS -1 do
	{
		searchAndMerge(iCounter,X,Y);
		searchAndMerge(iCounter,Y,X);
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