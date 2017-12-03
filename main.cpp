#include <iostream>
#include <math.h>
#include "Lista.h"
#include "Heuristica.h"
#include "Guloso.h"
#include "Movimento.h"
#include "nao_informados.h"
#include <fstream>
#include <time.h>

using namespace std;

/*
int main(){
    int n=5;
    int* estad = new int[(2*n)+1];
    int i = 0;
    for(; i<n ; i++){
        estad[i]=1;
    }
    estad[i]=0;
    i++;
    for(; i<(2*n)+1 ; i++){
        estad[i]=-1;
    }
    for(i=0; i<(2*n)+1 ; i++){
        //cout<<estad[i]<<endl;
    }
    Guloso* guloso = new Guloso(estad,n);
    guloso->resolve();
    guloso->caminho();

    cout << "\n\n\nHello world!" << endl;
    return 0;
}
*/

/*
/// TESTE DO BACKTRAKING
int main(){
    int n_pecas = 4;
    N_inf *n_inf = new N_inf(n_pecas);

    if(n_inf->backtracking()) cout << "\n\nSOLUCAO ENCONTRADA\n\n";
    else cout << "\n\nPROBLEMA IMPOSSIVEL\n\n";

    return 0;
}
*/

/*
/// TESTE DA BUSCA EM LARGURA
int main(){
    int n_pecas = 4;
    N_inf *n_inf = new N_inf(n_pecas);

    if(n_inf->largura()) cout << "\n\nSOLUCAO ENCONTRADA\n\n";
    else cout << "\n\nPROBLEMA IMPOSSIVEL\n\n";

    return 0;
}
*/

/// TESTE DA BUSCA EM PROFUNDIDADE
int main(){
    int n_pecas;
    N_inf *n_inf;

    ofstream arq;
    string nomeArq = "profundidade.txt";
    float valor;
    double tempo_total;

    clock_t tInicio, tFim;

    arq.open(nomeArq.c_str(), ofstream::app);

    for(int i = 0; i <= 20; i++){
        n_pecas = i;
        arq << n_pecas;

        for(int k = 0; k < 32; k++){
            n_inf = new N_inf(n_pecas);

            tInicio = clock();

            if(n_inf->profundidade()) cout << i << "\t" << k << endl;
            else cout << "\n\nPROBLEMA IMPOSSIVEL\n\n";

//            cin.get();

            tFim = clock();

            tempo_total = 1000*(((double)(tFim - tInicio)) / ((double)CLOCKS_PER_SEC));

            if(k != 0) arq << "\t" << tempo_total;
            delete n_inf;
        }
        arq << endl;
    }
    arq.close();
    return 0;
}
