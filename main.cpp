#include <iostream>
#include <time.h>
#include "Lista.h"
#include "Heuristica.h"
#include "Guloso.h"
#include "Movimento.h"
#include "nao_informados.h"
#include "Aestrela.h"
#include "IDA.h"


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
/*
/// TESTE DA BUSCA EM PROFUNDIDADE
int main(){
    int n_pecas = 4;
    N_inf *n_inf = new N_inf(n_pecas);

    if(n_inf->profundidade()) cout << "\n\nSOLUCAO ENCONTRADA\n\n";
    else cout << "\n\nPROBLEMA IMPOSSIVEL\n\n";

    return 0;
}
*/
