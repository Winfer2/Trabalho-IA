#ifndef AESTRELA_H_INCLUDED
#define AESTRELA_H_INCLUDED

#include <iostream>
#include "Movimento.h"
#include "Heuristica.h"
#include "Lista.h"

class Aestrela{
    private:
    Heuristica* custo;
    Movimento* moviment;
    Lista* abertos;
    Lista* fechados;
    int tam_N;
    void explora();
    bool verifica();
    void copia(int* a,int* b);
    public:
        void resolve();
        void caminho();
        Aestrela(int* estad, int tam);
};

Aestrela::Aestrela(int* estad, int tam){
    tam_N=tam;
    custo = new Heuristica();
    moviment = new Movimento(tam_N);
    abertos = new Lista();
    fechados = new Lista();
    abertos->adicionar(NULL,estad,tam);
}

bool Aestrela::verifica(){
    int n=custo->nPecas(fechados->get_ultimo()->get_estado(),tam_N);
    if(n==0)
        return true;
    else
    return false;
}
void Aestrela::copia(int* a,int* b){
    for(int i = 0; i<(2*tam_N)+1;i++)
        a[i]=b[i];
}
void Aestrela::explora(){
    int* estad = new int[(2*tam_N)+1];
    copia(estad,fechados->get_ultimo()->get_estado());
    for(int i = 1; i<5 ; i++){
        int *aux=new int[2*tam_N+1];
        copia(aux,estad);
        if(moviment->mover(i,aux))
            abertos->adicionar(fechados->get_ultimo(),aux,tam_N);
    }
}

void Aestrela::caminho(){
    int* x=fechados->get_ultimo()->get_estado();
    No_Lista *atual = fechados->get_ultimo();
    while(1){
        for(int i = 0;i<2*tam_N+1;i++)
        {
            std::cout<< x[i]<< " , ";
        }
        std::cout<<";"<<endl;
        if(atual->get_est_ant()==NULL)
            return;
        atual=atual->get_est_ant();
        x=atual->get_estado();

    }

}

void Aestrela::resolve(){
    int fn;
    No_Lista *menor;
    No_Lista *atual;
    while(1){
        atual = abertos->get_raiz();
        menor = atual;
        fn = custo->nPecas(atual->get_estado(),tam_N)+atual->get_profundidade();
        while(atual!=NULL){
            if(fn>(custo->nPecas(atual->get_estado(),tam_N)+atual->get_profundidade())){
                fn = custo->nPecas(atual->get_estado(),tam_N)+atual->get_profundidade();
                menor = atual;
            }
            atual=atual->get_filho();
       }
    fechados->adicionar(menor->get_est_ant(),menor->get_estado(),tam_N);
    abertos->apagar(menor->get_ID());
        if (verifica()){
            std::cout<<abertos->get_tamanho()+fechados->get_tamanho()<<std::endl;
            return;
        }
    explora();
    }

}

#endif // AESTRELA_H_INCLUDED
