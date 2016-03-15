#include <iostream>
#include <cassert>
#include <random>
#include <vector>
#include <cstdlib> 	

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
int searchIte( vector<Obj> _V, Obj &x, int high )
{
	for (int z =0; z <= high; z++)
	{
		if(_V[z] == x)
			return z;
	}
	return -1;
}

template<typename Obj>
int bSearchRec(vector<Obj> _V, Obj &x, int low, int high)
{
	int mid = ( low+ high )/2;
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
int tSearchIte(vector<Obj> _V, Obj &x, int low, int high)
{
	while (low <= high)
	{
		int T1 = low + ( high - low )*1/3;
		int T2 = low + ( high - low )*2/3;
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

template<typename Obj>
int bSearch(Obj &x, vector<Obj> _V, )
{
	
}

template <typename  Obj>
void randomElements(vector<Obj> *&a, Obj size, const unsigned int seed )
{
	unsigned int small = 0, bigger = 1000;
	default_random_engine eng(seed);
	uniform_int_distribution <int> distr(small,bigger);
	for(int x=0;x<size;x++)
		a[x] = distr(eng);

}

template <typename  Obj>
void vetor (Obj *&a, Obj size)
{
	
	a = new long int[size] ;
	
		
}