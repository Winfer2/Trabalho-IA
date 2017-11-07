#include <iostream>
#include "Lista.h"
#include "Heuristica.h"

using namespace std;

int main(){
    int* estad = new int[3];
    estad[0] = -1;
    estad[1] = 0;
    estad[2] = 1;
    int* estad2 = new int[5];
    estad2[0] = 2;
    estad2[1] = 1;
    estad2[2] = 0;
    estad2[3] = 1;
    estad2[4] = -2;
    int* estad3 = new int[3];
    estad3[0] = -3;
    estad3[1] = 1;
    estad3[2] = 3;

    Heuristica *a= new Heuristica();
    cout<<a->nPecas(estad2,2);

    cout << "\n\n\nHello world!" << endl;
    return 0;
}
