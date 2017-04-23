inline int my_binary_search( int value, int A[], int left, int right )
{
    long low  = left;
    long high = __max( left, right + 1 );
    while( low < high )
    {
        long mid = ( low + high ) / 2;
        if ( value <= a[ mid ] ) high = mid;
        else                        
            low  = mid + 1; 
    }
    return high;
}
