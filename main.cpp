#include <iostream>
#include "Lista.h"
#include "Heuristica.h"
#include "Guloso.h"

using namespace std;

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
