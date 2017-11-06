#include <iostream>
#include "Lista.h"

using namespace std;

int main(){
    int* estad = new int[3];
    estad[0] = -1;
    estad[1] = 0;
    estad[2] = 1;
    int* estad2 = new int[3];
    estad2[0] = -2;
    estad2[1] = 1;
    estad2[2] = 2;
    int* estad3 = new int[3];
    estad3[0] = -3;
    estad3[1] = 1;
    estad3[2] = 3;

    Lista *lista = new Lista();
    lista->adicionar(NULL, estad, 1);
    lista->adicionar(lista->get_raiz(), estad2, 1);
    lista->adicionar(lista->get_raiz(), estad3, 1);
    lista->imprime();
    lista->apagar(lista->get_raiz()->get_filho()->get_ID());
    delete lista;

    cout << "\n\n\nHello world!" << endl;
    return 0;
}
