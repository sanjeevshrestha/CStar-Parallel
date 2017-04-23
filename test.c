// This version is borrowed from "Introduction to Algorithms" 3rd edition, p. 799.
template< class _Type >
inline int my_binary_search( _Type value, const _Type* a, int left, int right )
{
    long low  = left;
    long high = __max( left, right + 1 );
    while( low < high )
    {
        long mid = ( low + high ) / 2;
        if ( value <= a[ mid ] ) high = mid;
        else                        low  = mid + 1; // because we compared to a[mid] and the value was larger than a[mid].
                                                    // Thus, the next array element to the right from mid is the next possible
                                                    // candidate for low, and a[mid] can not possibly be that candidate.
    }
    return high;
}
template < class Item >
inline void exchange( Item& A, Item& B )
{
    Item t = A;
    A = B;
    B = t;
}
// Merge two ranges of source array T[ p1 .. r1 ] and T[ p2 .. r2 ] into destination array A starting at index p3.
// From 3rd ed. of "Introduction to Algorithms" p. 798-802
// Listing 2 (which also needs to include the binary search implementation as well)
template< class _Type >
inline void merge_dac( const _Type* t, int p1, int r1, int p2, int r2, _Type* a, int p3 )
{
    int length1 = r1 - p1 + 1;
    int length2 = r2 - p2 + 1;
    if ( length1 < length2 )
    {
        exchange(      p1,      p2 );
        exchange(      r1,      r2 );
        exchange( length1, length2 );
    }
    if ( length1 == 0 ) return;
    int q1 = ( p1 + r1 ) / 2;
    int q2 = my_binary_search( t[ q1 ], t, p2, r2 );
    int q3 = p3 + ( q1 - p1 ) + ( q2 - p2 );
    a[ q3 ] = t[ q1 ];
    merge_dac( t, p1,     q1 - 1, p2, q2 - 1, a, p3     );
    merge_dac( t, q1 + 1, r1,     q2, r2,     a, q3 + 1 );
}


inline void merge_dac( int A[], int B[], int C[], int p3 )
