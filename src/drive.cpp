#include "function.h"

using namespace std;

#define PATTERN_VECTOR 5 // tamanho padrão atribuído no vetor
#define MAX_VECTOR  29     // maior tamanho a ser alocado no vetor

int main(int argc, char const *argv[])
{
    auto arraySize(PATTERN_VECTOR);
    int seed = 1;
    //1 - ATRIBUIR VALOR PADRÃO AO VETOR DA LINHA DE COMANDO
    if(argc > 1){
        stringstream(argv[1]) >> arraySize;
    }
    //2 - VERIFICAR SE A QUANTIDADE DE TERMOS NO VETOR É VÁLIDA (size >= 5)
    if(arraySize < 5 || arraySize > MAX_VECTOR){
        cout << "TAMANHO DO VETOR DEVE SER MAIOR QUE 5 E MENOR QUE 31! O VALOR PADRAO SERÁ ATRIBUIDO" << endl;
        arraySize = PATTERN_VECTOR;
    }

    cout << ">>> Alocando Vetor..." << endl;
    arraySize = pow(2, arraySize);
    vector<long int> V(arraySize);
    cout << "\n>>> Alocação Concluida..." << endl;

    cout << "\n>>> Preenchendo Vetor" << endl;
    randomFill( V, arraySize, seed);
    long int elemento = 47;
	cout << "\n>>> Preenchimento Concluido" << endl;

    //3 - CONSTRUIR ARRAY DE FUNÇÕES

    long int (*funcArray[])(vector<long int> , long int, long int, long int) = {
       
        sSearchIte,
        bSearchRec,
        tSearchIte,
        bWrapperSearch,
        sSearchRec,
		bSearchIte,
		bTernRec,
	};
	
	for(auto &x : V)
		cout<<x<<" ";
	cout<< "\n>>> Function sSearchIte"<<endl;
	cout<<funcArray[0](V, elemento, 0, arraySize-1)<<endl;

	

	//sort(V.data(), V.data() + arraySize);
	cout<< "\n>>> Ordenando o Vetor"<<endl;
	sort(V.begin(), V.end() );

	for(auto &x : V)
		cout<<x<<" ";
	cout<<endl;

	cout<< "\n>>> Function bSearchRec"<<endl;
	cout<<"\n>>>The element "<< elemento <<" is in Position: "<<funcArray[1](V, elemento, 0, arraySize-1)<<endl;

	cout<< "\n>>> Function tSearchIte"<<endl;
	cout<<"\n>>>The element "<< elemento <<" is in Position: "<<funcArray[2](V, elemento, 0, arraySize-1)<<endl;

	cout<< "\n>>> Function bWrapperSearch"<<endl;
	cout<<"\n>>>The element "<< elemento <<" is in Position: "<<funcArray[3](V, elemento, 0, arraySize-1)<<endl;
	
	cout<< "\n>>> Function sSearchRec"<<endl;
	cout<<"\n>>>The element "<< elemento <<" is in Position: "<<funcArray[4](V, elemento, 0, arraySize-1)<<endl;
	
	cout<< "\n>>> Function bSearchIte"<<endl;
	cout<<"\n>>>The element "<< elemento <<" is in Position: "<<funcArray[5](V, elemento, 0, arraySize-1)<<endl;
	
	cout<< "\n>>> Function bTernRec"<<endl;
	cout<<"\n>>>The element "<< elemento <<" is in Position: "<<funcArray[6](V, elemento, 0, arraySize-1)<<endl;

    //long int *V;
    //V = new long int[arraySize];
    
    /*for(int n = 16; n < arraySize; n *= 2){
        for(int i=0; i < 3; ++i){
            calculateTime( elemento, 0, arraySize-1, funcArray[i] );
        }
    }*/

    //4 - ATRIBUIR VALOR TOTAL A SER UTILIZADO NO ARRAY, EM UMA VARIAVEL
    //5 - CRIAR VARIÁVEIS E ATRIBUIR VALOR DE MAIOR E MENOR A CADA

    return 0;
}
	/*vector<int> V = { 2, 4, 6, 8, 10, 12, 14 };
	auto size = pow( 2, 6 );
	cout << ">>> Alocando Vetor..." << endl;
	vector<long int> V(size);
	cout << "\n>>> Alocação Concluida..." << endl;
	//vetor(a, size);
	//int vlr =14;
	cout << "\n>>> Preenchendo Vetor" << endl;
	random_device seed;
	randomFill( V, size, seed() );
	cout << "\n>>> Preenchimento Concluido" << endl;

	for (auto x=0;x<size;x++)
	{
		cout << V[x] << endl;
	}								//searchIte( V, vlr, 0, size-1 )
	//cout << ">>> Resultado da busca: " << bWrapperSearch( V, vlr, 0, size-1 ) << endl;


	//delete [] V;*/

	
