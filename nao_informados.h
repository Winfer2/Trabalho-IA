#ifndef NAO_INFORMADO_H_INCLUDED
#define NAO_INFORMADO_H_INCLUDED

#include "Movimento.h"

class Backtracking{
    private:
        int N_pecas;
        int *jogo;
        int ultimo_movimento;
        Movimento *movimento;
        bool verifica_final();

    public:
        Backtracking(int n_pecas);
        int get_N_pecas(){ return N_pecas; }
        void mostrar_jogo();
        bool avanca(int Mov);
};

Backtracking::Backtracking(int n_pecas){
    N_pecas = n_pecas;
    jogo = new int[2*N_pecas+1];
    for(int i = 0; i < 2*N_pecas+1; i++){
        if(i < N_pecas) jogo[i] = 1;
        else if(i == N_pecas) jogo[i] = 0;
        else jogo[i] = -1;
    }
    ultimo_movimento = 0;

    movimento = new Movimento(N_pecas);
    movimento->moveR4(jogo);
}

bool Backtracking::verifica_final(){
    for(int i = 0; i < 2*N_pecas+1; i++){
        if(i < N_pecas && jogo[i] != -1) return false;
        if(i == N_pecas && jogo[i] != 0) return false;
        return true;
    }
}

bool Backtracking::avanca(int Mov){
    int mov = Mov;

    mostrar_jogo();

    if(verifica_final()) return true;
    if(mov == 1){
        if(movimento->moveR1(jogo)){
            avanca(1);
            return true;
        }else{
            volta_estado();
            mov = 2;
        }
    }else if(mov == 2){
        if(movimento->moveR1(jogo)){
            avanca(2);
            return true;
        }else{
            volta_estado();
            mov = 3;
        }
    }
    }else if(mov == 3){
        if(movimento->moveR1(jogo)){
            avanca(3);
            return true;
        }else{
            volta_estado();
            mov = 4;
        }
    }
    }else if(mov == 4){
        if(movimento->moveR1(jogo)){
            avanca(4);
            return true;
        }else{
            volta_estado();
            mov = 3;
        }
    }

}

void Backtracking::mostrar_jogo(){
    cout << endl;
    for(int i = 0; i < 2*N_pecas+1; i++){
        cout << jogo[i] << "\t";
    }
    cout << endl;
}

#endif // NAO_INFORMADO_H_INCLUDED
