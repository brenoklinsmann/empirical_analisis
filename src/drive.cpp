#include "function.h"

using namespace std;



	
int main ()
{
	vector<int> V = { 2, 4, 6, 8, 10, 12, 14 };
	int size = 7;
	//vector<long int> *a;
	//vetor(a, size);
	//random_device r;
	int vlr =14;
	//randomElements(a, size,r());
	/*for (int x=0;x<20;x++)
	{
		cout << a[x] << endl;
	}*/									//searchIte( V, vlr, 0, size-1 )
	cout << ">>> Resultado da busca: " << tSearchIte( V, vlr, 0, size-1 ) << endl;


	//delete [] a;

	
}