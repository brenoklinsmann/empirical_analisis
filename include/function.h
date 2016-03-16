//#ifndef _COMPACT_H_
//#define _COMPACT_H_

#include "function.inl"

template<typename Obj>
long int sSearchIte( vector<Obj>, const Obj, long int, long int  );

template<typename Obj>
long int bSearchRec( vector<Obj>, const Obj, long int, long int );

template<typename Obj>
long int tSearchIte( vector<Obj>, const Obj , long int, long int );

template<typename Obj>
long int bWrapperSearch( vector<Obj>, const Obj, long int, long int );

template<typename Obj>
long int sSearchRec(vector<Obj>, Obj, long int , long int );

template<typename Obj>
long int bSearchIte(vector<Obj>, Obj, long int , long int );

template<typename Obj>
long int bTernRec (vector<Obj>, Obj, long int , long int );

template<typename Obj>
void randomFill( vector<Obj> &, Obj, const unsigned int );

//template <typename Obj>
//long double calculateTime( vector<Obj> *_V, long int (*function)( Obj, long int, long int ), const  x, const low, const high )
//template<typename Obj>
//void vetor ( Obj &, Obj );

template<typename Obj>
int comparar ( const Obj, const Obj );

//#endif