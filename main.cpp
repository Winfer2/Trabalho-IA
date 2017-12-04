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
/// TESTE DE TEMPO DOS METODOS NAO ORDENADOS
int main(){
    int n_pecas;
    N_inf *n_inf;

    ofstream arq;
    string nomeArq = "ordenada_2.txt";
    float valor;
    double tempo_total;

    clock_t tInicio, tFim;

    arq.open(nomeArq.c_str(), ofstream::app);

    for(int i = 1; i <= 12; i++){
        n_pecas = i;
        arq << n_pecas;

        for(int k = 0; k < 32; k++){
            n_inf = new N_inf(n_pecas);

            tInicio = clock();

            if(n_inf->ordenada()) cout << i << "\t" << k << endl;
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
*/

/// TESTE DE MEMORIA DOS METODOS NAO ORDENADOS
int main(){
    int n_pecas;
    N_inf *n_inf;

    ofstream arq;
    string nomeArq = "ordenada_memoria.txt";

    arq.open(nomeArq.c_str(), ofstream::app);

    for(int i = 1; i <= 12; i++){
        n_pecas = i;
        arq << n_pecas;

        n_inf = new N_inf(n_pecas);

        if(n_inf->ordenada()) cout << i << endl;
        else cout << "\n\nPROBLEMA IMPOSSIVEL\n\n";

        arq << "\t" << n_inf->get_tam_lista();
        delete n_inf;
        arq << endl;
    }
    arq.close();
    return 0;
}
