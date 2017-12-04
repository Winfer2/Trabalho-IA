#ifndef NAO_INFORMADO_H_INCLUDED
#define NAO_INFORMADO_H_INCLUDED

#include "Lista.h"
#include "Movimento.h"
#include <math.h>

class N_inf{
    private:
        int N_pecas;
        int *jogo;
        int *temp;
        int tam_list;
        int val_ord();
        Movimento *movimento;
        bool verifica_final();
        bool bt_volta_estado();
        Lista *lista;

    public:
        N_inf(int n_pecas);
        ~N_inf();
        int get_tam_lista(){return tam_list;}
        void mostrar_jogo();
        bool backtracking();
        bool largura();
        bool profundidade();
        bool ordenada();
};

N_inf::N_inf(int n_pecas){

    // cria o estado inicial do jogo
    N_pecas = n_pecas;
    temp = new int[2*N_pecas+1];
    jogo = new int[2*N_pecas+1];
    for(int i = 0; i < 2*N_pecas+1; i++){
        if(i < N_pecas) jogo[i] = 1;
        else if(i == N_pecas) jogo[i] = 0;
        else jogo[i] = -1;
    }

    // adiciona estado inical na lista
    lista = new Lista();

    tam_list = 1;
    lista->adicionar_ord(NULL, jogo, (2*N_pecas+1), val_ord());

    // cria movimentos
    movimento = new Movimento(N_pecas);

}

N_inf::~N_inf(){
    delete lista;
    delete movimento;
    delete[] jogo;
    delete[] temp;
}

bool N_inf::verifica_final(){
    for(int i = 0; i <= N_pecas; i++){
        if(i < N_pecas && jogo[i] != -1) return false;
        if(i == N_pecas && jogo[i] != 0) return false;
    }
    return true;
}

bool N_inf::bt_volta_estado(){

    // verifica jogo impossivel
    if(lista->get_ultimo()->get_ID() == lista->get_raiz()->get_ID()){
        return false;
    }

    // apaga ultimo no da lista
    lista->apagar(lista->get_ultimo()->get_ID());
    tam_list--;
    for(int i = 0; i < 2*N_pecas+1; i++) jogo[i] = lista->get_ultimo()->get_estado()[i];
    return true;
}

void N_inf::mostrar_jogo(){
    cout << endl;
    for(int i = 0; i < 2*N_pecas+1; i++){
        cout << jogo[i] << "\t";
    }
}

bool N_inf::backtracking(){

    if(verifica_final()) return true;

    for(int m = 1; m <= 4; m++){
        if(movimento->mover(m, jogo)){
            lista->adicionar(lista->get_ultimo(), jogo, (2*N_pecas+1));
            tam_list++;
            backtracking();
            if(verifica_final()){
                lista->adicionar(lista->get_ultimo(), jogo, (2*N_pecas+1));
                tam_list++;
                return true;
            }
        }
    }

    if(!bt_volta_estado()) return false;

    return false;
}

bool N_inf::largura(){

    for(int k = 0; k < (2*N_pecas+1); k++) temp[k] = jogo[k];

    for(int m = 1; m <= 4; m++){
        if(movimento->mover(m, jogo)){
            lista->adicionar(lista->get_ultimo(), jogo, (2*N_pecas+1));
            tam_list++;
            for(int k = 0; k < (2*N_pecas+1); k++) jogo[k] = temp[k];
        }
    }

    if(verifica_final()) return true;

    // remove raiz
    if(lista->get_tamanho() == 0) return false;
    lista->apagar(lista->get_raiz()->get_ID());

    // jogo vira o estado da nova raiz
    for(int i = 0; i < 2*N_pecas+1; i++) jogo[i] = lista->get_raiz()->get_estado()[i];

    return largura();
}

bool N_inf::profundidade(){

    // remove ultimo
    if(lista->get_tamanho() == 0) return false;
    lista->apagar(lista->get_ultimo()->get_ID());

    for(int k = 0; k < (2*N_pecas+1); k++) temp[k] = jogo[k];

    for(int m = 1; m <= 4; m++){
        if(movimento->mover(m, jogo)){
            lista->adicionar(lista->get_ultimo(), jogo, (2*N_pecas+1));
            tam_list++;
            for(int k = 0; k < (2*N_pecas+1); k++) jogo[k] = temp[k];
        }
    }

    if(verifica_final()) return true;

    // jogo vira o estado do ultimo
    for(int i = 0; i < 2*N_pecas+1; i++) jogo[i] = lista->get_ultimo()->get_estado()[i];

    return profundidade();
}

int N_inf::val_ord(){
    int val = 0;

//    // objetivo 1 para minimizar
//    for(int i = 0; i < 2*N_pecas+1; i++) val += jogo[i]*((int)(100*sin((2*M_PI*i)/(2*N_pecas+1))));
//
    // objetivo 2 para minimizar
    for(int i = 0; i < 2*N_pecas+1; i++) val += jogo[i]*(N_pecas-i);
//
//    // objetivo 3 para minimizar
//    for(int i = 0; i < 2*N_pecas+1; i++)
//        if (i < N_pecas) val += jogo[i]*i;


    return val;
}

bool N_inf::ordenada(){

    // remove ultimo
    if(lista->get_tamanho() == 0) return false;
    lista->apagar(lista->get_ultimo()->get_ID());

    for(int k = 0; k < (2*N_pecas+1); k++) temp[k] = jogo[k];

    for(int m = 1; m <= 4; m++){
        if(movimento->mover(m, jogo)){
            lista->adicionar_ord(lista->get_ultimo(), jogo, (2*N_pecas+1), val_ord());
            tam_list++;
            for(int k = 0; k < (2*N_pecas+1); k++) jogo[k] = temp[k];
        }
    }

    if(verifica_final()) return true;

    // jogo vira o estado do ultimo
    for(int i = 0; i < 2*N_pecas+1; i++) jogo[i] = lista->get_ultimo()->get_estado()[i];

    return ordenada();
}

#endif // NAO_INFORMADO_H_INCLUDED
