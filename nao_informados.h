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
        void volta_estado();
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
    lista->adicionar(NULL, jogo, N_pecas);

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

void Backtracking::volta_estado(){
    // apaga ultimo no da lista
    lista->apagar(lista->get_ultimo()->get_ID());
}

bool Backtracking::avanca(){

    mostrar_jogo();

    if(verifica_final()) return true;

    if(movimento->moveR1(jogo)) avanca();
    if(movimento->moveR2(jogo)) avanca();
    if(movimento->moveR3(jogo)) avanca();
    if(movimento->moveR4(jogo)) avanca();
    else{
        cout << "\t ERROU " << endl;
//        volta_estado();
    }

//    avanca();

}

void Backtracking::mostrar_jogo(){
    cout << endl;
    for(int i = 0; i < 2*N_pecas+1; i++){
        cout << jogo[i] << "\t";
    }
    cout << endl;
}

#endif // NAO_INFORMADO_H_INCLUDED
