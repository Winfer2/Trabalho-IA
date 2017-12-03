#ifndef NAO_INFORMADO_H_INCLUDED
#define NAO_INFORMADO_H_INCLUDED

#include "Lista.h"
#include "Movimento.h"

class Backtracking{
    private:
        int N_pecas;
        int *jogo;
        int ultimo_movimento;
        Movimento *movimento;
        bool verifica_final();
        bool volta_estado();
        Lista *lista;

    public:
        Backtracking(int n_pecas);
        int get_N_pecas(){ return N_pecas; }
        void mostrar_jogo();
        bool avanca();
};

Backtracking::Backtracking(int n_pecas){
    lista = new Lista();

    // cria o estado inicial do jogo
    N_pecas = n_pecas;
    jogo = new int[2*N_pecas+1];
    for(int i = 0; i < 2*N_pecas+1; i++){
        if(i < N_pecas) jogo[i] = 1;
        else if(i == N_pecas) jogo[i] = 0;
        else jogo[i] = -1;
    }

    // adiciona estado inical na lista
    int *save = new int[2*N_pecas+1];
    for(int i = 0; i < 2*N_pecas+1; i++) save[i] = jogo[i];
    lista->adicionar(NULL, save, N_pecas);

    // cria movimentos
    movimento = new Movimento(N_pecas);

}

bool Backtracking::verifica_final(){
    for(int i = 0; i <= N_pecas; i++){
        if(i < N_pecas && jogo[i] != -1) return false;
        if(i == N_pecas && jogo[i] != 0) return false;
    }
    return true;
}

bool Backtracking::volta_estado(){

    // verifica jogo impossivel
    if(lista->get_ultimo()->get_ID() == lista->get_raiz()->get_ID()){
        return false;
    }

    // apaga ultimo no da lista
    lista->apagar(lista->get_ultimo()->get_ID());
    for(int i = 0; i < 2*N_pecas+1; i++) jogo[i] = lista->get_ultimo()->get_estado()[i];
    return true;
}

bool Backtracking::avanca(){
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
            avanca();
            if(verifica_final()){
                lista->adicionar(lista->get_ultimo(), jogo, N_pecas);
                return true;
            }
        }
    }

    if(!volta_estado()) return false;
    mostrar_jogo();
    return false;

}

void Backtracking::mostrar_jogo(){
    cout << endl;
    for(int i = 0; i < 2*N_pecas+1; i++){
        cout << jogo[i] << "\t";
    }
}

#endif // NAO_INFORMADO_H_INCLUDED
