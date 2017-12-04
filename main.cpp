#include <iostream>
<<<<<<< HEAD
#include <time.h>
=======
#include <math.h>
>>>>>>> be13d81bdef4e1ef564ef18c10dd532e00ef774e
#include "Lista.h"
#include "Heuristica.h"
#include "Guloso.h"
#include "Movimento.h"
#include "nao_informados.h"
#include "Aestrela.h"
#include "IDA.h"
#include <fstream>
#include <time.h>

using namespace std;


int main(){
    clock_t start, end;
    double cpu_time_used;
    for(int n=1;n<13;n++){
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
    start = clock();
    //Guloso* metodo = new Guloso(estad,n);
    //Aestrela* metodo = new Aestrela(estad,n);
    IDA* metodo = new IDA(estad,n);
    metodo->resolve();
    end = clock();
    //metodo->caminho();

    cout <<n << "  " << ((double)(end - start)*1000)/CLOCKS_PER_SEC << endl;
    }
    return 0;

}
/*
Guloso tempo em ms nós
1 1 5
2 1 19
3 1 46
4 1 107
5 1 221
6 1 476
7 2 962
8 4 2006
9 8 4010
10 19 8175
11 56 16197
12 112 32498
A*
1 1 5
2 1 31
3 1 107
4 1 295
5 5 723
6 10 1653
7 30 3611
8 105 7647
9 369 15841
10 1315 32297
11 5377 65087
12 20606 130059
IDA*
1 1 5
2 1 31
3 1 107
4 1 295
5 3 723
6 21 1653
7 34 3611
8 118 7647
9 412 15841
10 1434 32297
11 5392 65087
12 20825 130059
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
/*
/// TESTE DA BUSCA EM PROFUNDIDADE

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
*/
