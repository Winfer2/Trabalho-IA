#ifndef NAO_INFORMADO_H_INCLUDED
#define NAO_INFORMADO_H_INCLUDED

#include "Lista.h"
#include "Movimento.h"

class N_inf{
    private:
        int N_pecas;
        int *jogo;
        Movimento *movimento;
        bool verifica_final();
        bool bt_volta_estado();
        Lista *lista;
        Lista *fechados;

    public:
        N_inf(int n_pecas);
        void mostrar_jogo();
        bool backtracking();
        bool largura();
        bool profundidade();
};

N_inf::N_inf(int n_pecas){

    // cria o estado inicial do jogo
    N_pecas = n_pecas;
    jogo = new int[2*N_pecas+1];
    for(int i = 0; i < 2*N_pecas+1; i++){
        if(i < N_pecas) jogo[i] = 1;
        else if(i == N_pecas) jogo[i] = 0;
        else jogo[i] = -1;
    }

    // adiciona estado inical na lista
    lista = new Lista();
    fechados = new Lista();
    int *save = new int[2*N_pecas+1];
    for(int i = 0; i < 2*N_pecas+1; i++) save[i] = jogo[i];
    lista->adicionar(NULL, save, N_pecas);

    // cria movimentos
    movimento = new Movimento(N_pecas);

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

bool N_inf::backtracking(){
    int *save = new int[2*N_pecas+1];

    mostrar_jogo();

    if(verifica_final()){
        lista->adicionar(lista->get_ultimo(), jogo, N_pecas);
        return true;
    }

    for(int m = 1; m <= 4; m++){
        if(movimento->mover(m, jogo)){
            for(int i = 0; i < 2*N_pecas+1; i++) save[i] = jogo[i];
            lista->adicionar(lista->get_ultimo(), save, N_pecas);
            backtracking();
            if(verifica_final()){
                lista->adicionar(lista->get_ultimo(), jogo, N_pecas);
                return true;
            }
        }
    }

    if(!bt_volta_estado()) return false;
    mostrar_jogo();
    return false;
}

void N_inf::mostrar_jogo(){
    cout << endl;
    for(int i = 0; i < 2*N_pecas+1; i++){
        cout << jogo[i] << "\t";
    }
}

bool N_inf::largura(){
    int *save;

    for(int m = 1; m <= 4; m++){
        save = new int[2*N_pecas+1];
        for(int i = 0; i < 2*N_pecas+1; i++) save[i] = jogo[i];
        if(movimento->mover(m, save)) lista->adicionar(lista->get_ultimo(), save, N_pecas);
    }

    if(verifica_final()) return true;

    // remove raiz
    if(lista->get_tamanho() == 0) return false;
    lista->apagar(lista->get_raiz()->get_ID());

    // jogo vira o estado da nova raiz
    for(int i = 0; i < 2*N_pecas+1; i++) jogo[i] = lista->get_raiz()->get_estado()[i];

    lista->imprime();
    cout << "\n";

    return largura();

}

bool N_inf::profundidade(){
    int *save;

    for(int m = 1; m <= 4; m++){
        save = new int[2*N_pecas+1];
        for(int i = 0; i < 2*N_pecas+1; i++) save[i] = jogo[i];
        if(movimento->mover(m, save)) lista->adicionar(lista->get_ultimo(), save, N_pecas);
    }

    if(verifica_final()) return true;

    // jogo vira o estado da nova raiz
    for(int i = 0; i < 2*N_pecas+1; i++) jogo[i] = lista->get_ultimo()->get_estado()[i];

    lista->imprime();
    cout << "\n";

    // remove raiz
    if(lista->get_tamanho() == 0) return false;
    lista->apagar(lista->get_ultimo()->get_ID());

    return profundidade();
}
#endif // NAO_INFORMADO_H_INCLUDED
