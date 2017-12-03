#include <iostream>
#include "Lista.h"
#include "Heuristica.h"
#include "Guloso.h"
#include "Movimento.h"
#include "nao_informados.h"

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


/// TESTE DO BACKTRAKING
int main(){
    int n_pecas = 2;
    Backtracking *backtracking = new Backtracking(n_pecas);
    backtracking->avanca();
    backtracking->mostrar_jogo();

    return 0;
}
