#ifndef NAO_INFORMADO_H_INCLUDED
#define NAO_INFORMADO_H_INCLUDED

#include "Lista.h"
#include "Movimento.h"

class N_inf{
    private:
        int N_pecas;
        int *jogo;
        int *temp;
        Movimento *movimento;
        bool verifica_final();
        bool bt_volta_estado();
        Lista *lista;

    public:
        N_inf(int n_pecas);
        ~N_inf();
        void mostrar_jogo();
        bool backtracking();
        bool largura();
        bool profundidade();
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
//    int *save = new int[2*N_pecas+1];
//    for(int i = 0; i < 2*N_pecas+1; i++) save[i] = jogo[i];
    lista->adicionar(NULL, jogo, (2*N_pecas+1));

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
//    mostrar_jogo();

    if(verifica_final()) return true;

    for(int m = 1; m <= 4; m++){
        if(movimento->mover(m, jogo)){
            lista->adicionar(lista->get_ultimo(), jogo, (2*N_pecas+1));
            backtracking();
            if(verifica_final()){
                lista->adicionar(lista->get_ultimo(), jogo, (2*N_pecas+1));
                return true;
            }
        }
    }

    if(!bt_volta_estado()) return false;
//    mostrar_jogo();
    return false;
}

bool N_inf::largura(){

    for(int k = 0; k < (2*N_pecas+1); k++) temp[k] = jogo[k];

    for(int m = 1; m <= 4; m++){
        if(movimento->mover(m, jogo)){
            lista->adicionar(lista->get_ultimo(), jogo, (2*N_pecas+1));
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
            for(int k = 0; k < (2*N_pecas+1); k++) jogo[k] = temp[k];
        }
    }

    if(verifica_final()) return true;

    // jogo vira o estado do ultimo
    for(int i = 0; i < 2*N_pecas+1; i++) jogo[i] = lista->get_ultimo()->get_estado()[i];

//    lista->imprime();
//    cout << "\n";

    return profundidade();
}
#endif // NAO_INFORMADO_H_INCLUDED
