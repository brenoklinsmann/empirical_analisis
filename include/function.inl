#include <iostream>
#include <algorithm>
#include <random>
#include <vector>
#include <sstream>
#include <string>
#include <cstdlib> 	
#include <chrono>
//#include <cassert>
//#include <cmath>

using namespace std;

//buscaBin( V, x, 0, sz-1, comparaInt )

/*template <typename Obj>
int wrapper_bsearch( Obj a, Obj b )
{
	Obj x = ( Obj ) bsearch(); 
}

template <typename Obj>
int searchIte( vector<Obj> _V, Obj &x, int low, int high )
{
	while( low <= high)
	{
		int mid = (low + high)/2;
		if ( _V[mid] == x )
			return mid;
		else if (_V[mid] < x )
			low = mid + 1;
		else
			high = mid - 1;
	}
	return -1; // Indices invalidos
}*/
//int searchIte( vector<Obj> _V, Obj &x, int low, int high )
template<typename Obj>	
long int sSearchIte(vector<Obj> _V, const Obj x, long int low, long int high )
{
	for (; low <= high; low++)
	{
		if(_V[low] == x)
			return low;
	}
	return -1;
}

template<typename Obj>
long int bSearchRec(vector<Obj> _V, const Obj x, long int low, long int high)
{
	long int mid = ( low+ high )/2;
	if ( low > high)
		return -1;
	if ( _V[mid] == x )
		return mid;
	else if ( _V[mid] < x )
		return bSearchRec( _V, x,  mid+1, high);
	else
		return bSearchRec( _V,  x, low, mid-1);
}

template <typename Obj>
long int tSearchIte(vector<Obj> _V, const Obj x, long int low, long int high)
{
	while (low <= high)
	{
		long int T1 = low + ( high - low )*1/3;
		long int T2 = low + ( high - low )*2/3;
		if( _V[T1] == x )
			return T1;
		else if ( _V[T2] == x )
			return T2;
		else if ( _V[T1] > x )
			high = T1 -1;
		else if ( _V[T2] < x )
			low = T2 + 1;
		else{
			low = T1 + 1;
			high = T2 - 1;
		}
	}
	return -1;
}

template <typename Obj>
int comparar (const Obj x, const Obj y)
{
	Obj *b = (Obj *) y;
	Obj *a = (Obj *) x;
	if ( *a < *b ) return -1;
	else if ( *a > *b ) return 1;
	else return 0;

}
//void* bsearch( const void* key, const void* ptr, std::size_t count,
//std::size_t size, int (*comp)(const void*, const void*) );
template<typename Obj>
long int bWrapperSearch( vector<Obj> _V, const Obj x, long int low, long int high)
{
	Obj *a = (Obj *)bsearch( &x, _V.data(), high - low + 1, sizeof(Obj), comparar);
	if( a != NULL ) return (a - _V.data() );
	else return -1;
}

//PARTE_DE_JOHNNY
template <typename Obj>
long int sSearchRec(vector<Obj> _V, const Obj x, long int low, long int high )
{
    if( low > high )
        return -1;
    else if ( _V[low] == x )
        return 1;
    else
        return sSearchRec( _V, x, low+1, high );
}

template <typename Obj>
long int bSearchIte(vector<Obj> _V, const Obj x, long int low, long int high )
{
    while (low <= high ){
        int media = ( low + high )/2;
        if( _V[media] == x ){
            return media;
        } else if ( _V[media] < x ){
            low = media + 1;
        } else{
            high  = media - 1;
        }
    }

    return -1;
}

template <typename Obj>
long int bTernRec (vector<Obj> _V, const Obj x, long int low, long int high ) 
{
    long int media0 = ( high + (2*low) )/3;
    long int media1 = ( low + (2*high ) )/3;

    if(low > high )
        return -1;
    else if( x == _V[media0] ){
        return media0;
    } else if( x == _V[media1] ){
        return media1;
    } else if( x > _V[media1] ){
        return bTernRec( _V, x, media1+1, high );
    } else if( x < _V[media0]){
        return bTernRec( _V, x, low, media0-1);
    } else{
        return bTernRec( _V, x, media0+1, media1-1);
    }
}

/*long double calculateTime( vector<Obj> *_V, long int (*function)( Obj, long int, long int ), const  x, const low, const high )
{
    long double duration = 0;
    for (int i = 0; i < n; ++i)
    {
        auto start = steady_clock::now();
        function(v, x, l, r);
        auto end = steady_clock::now();
        auto diff = chrono::duration <double, std::milli> (end-start).count();
        duration += (diff-duration)/(i+1);
    }
    return duration;
}
*/
template <typename  Obj>
void randomFill(vector<Obj> &a, const int size, const int seed )
{
	//unsigned int small = 0, bigger = 1000;
	default_random_engine eng(seed);
	uniform_real_distribution <double> distr(0, 1000);
	for(int x=0;x<size;x++)
		a[x] = distr(eng);

}

/*template <typename  Obj>
void vetor (Obj *&a, Obj size)
{
	
	a = new long int[size] ;
	
		
}*/