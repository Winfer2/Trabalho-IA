#ifndef GULOSO_H_INCLUDED
#define GULOSO_H_INCLUDED

#include <iostream>
#include "Movimento.h"
#include "Heuristica.h"
#include "Lista.h"

class Guloso{
    private:
    Heuristica* custo;
    Movimento* moviment;
    Lista* abertos;
    Lista* fechados;
    int tam_N;
    void bestMove();
    bool verifica();
    void copia(int* a,int* b);
    public:
        void resolve();
        void caminho();
        Guloso(int* estad, int tam);
};

Guloso::Guloso(int* estad, int tam){
    tam_N=tam;
    custo = new Heuristica();
    moviment = new Movimento(tam_N);
    abertos = new Lista();
    fechados = new Lista();
    abertos->adicionar(NULL,estad,tam);
}

void Guloso::resolve(){
    int i = 0;
    while(1){
        i++;
        if(abertos->get_ultimo()==NULL)
        {
            //std::cout<<"aaaa";
            return;
        }
        fechados->adicionar(
            abertos->get_ultimo()->get_est_ant(),
            abertos->get_ultimo()->get_estado(),
            tam_N);
        if (verifica())
            return;
        abertos->apagar(abertos->get_ultimo()->get_ID());
        bestMove();
        /*
        std::cout<<abertos->get_ultimo()->get_estado()[0]<<std::endl;
        std::cout<<abertos->get_ultimo()->get_estado()[1]<<std::endl;
        std::cout<<abertos->get_ultimo()->get_estado()[2]<<std::endl;
        std::cout<<abertos->get_ultimo()->get_estado()[3]<<std::endl;
        std::cout<<abertos->get_ultimo()->get_estado()[4]<<std::endl;
        std::cout<<abertos->get_ultimo()->get_estado()[5]<<std::endl;
        std::cout<<abertos->get_ultimo()->get_estado()[6]<<std::endl;
        std::cout<<std::endl;*/
        //if(i==5)
        //return;
    }
}
void Guloso::copia(int* a,int* b){
    for(int i = 0; i<(2*tam_N)+1;i++)
        a[i]=b[i];
}
void  Guloso::bestMove(){
    int *aux=new int[2*tam_N+1];
    int *estad=new int[2*tam_N+1];
    //*estad = *fechados->get_ultimo()->get_estado();
    copia(estad,fechados->get_ultimo()->get_estado());
    copia(aux,estad);
    int a=-1,b=-1,c=-1,d=-1;
    //std::cout<<estad[3]<<std::endl;
    if(moviment->moveR1(aux)){
        a=custo->nPecas(aux,tam_N);
        copia(aux,estad);
    }
    //std::cout<<estad[3]<<std::endl;
    if(moviment->moveR2(aux)){
        b=custo->nPecas(aux,tam_N);
        copia(aux,estad);
    }
    //std::cout<<estad[3]<<std::endl;
    if(moviment->moveR3(aux)){
        c=custo->nPecas(aux,tam_N);
        copia(aux,estad);
    }
    //std::cout<<estad[3]<<std::endl;
    if(moviment->moveR4(aux)){
        d=custo->nPecas(aux,tam_N);
        copia(aux,estad);
    }
    //std::cout<<a<<b<<c<<d<<std::endl;
    while(1){
    if(a==-1&&b==-1&&c==-1&&d==-1){
        return;
    }
    else if(a>=b&&a>=c&&a>=d&&a!=-1){
        if(moviment->moveR1(aux)){
            //std::cout<<aux[0]<<std::endl;
            int *aux2=new int[2*tam_N+1];
            copia(aux2,aux);
            abertos->adicionar(fechados->get_ultimo(),aux2,tam_N);
        }
        a=-1;
        copia(aux,estad);
    }else if(b>=c&&b>=d&&b!=-1){
        if(moviment->moveR2(aux)){
            int *aux2=new int[2*tam_N+1];
            copia(aux2,aux);
            abertos->adicionar(fechados->get_ultimo(),aux2,tam_N);
        }
        b=-1;
        copia(aux,estad);
    }else if(c>=d&&c!=-1){
        if(moviment->moveR3(aux)){
            int *aux2=new int[2*tam_N+1];
            copia(aux2,aux);
            abertos->adicionar(fechados->get_ultimo(),aux2,tam_N);
        }
        c=-1;
        copia(aux,estad);
    }else if(d!=-1){
        if(moviment->moveR4(aux)){
            int *aux2=new int[2*tam_N+1];
            copia(aux2,aux);
            abertos->adicionar(fechados->get_ultimo(),aux2,tam_N);
        }
        d=-1;
        copia(aux,estad);
    }
    }
}

bool Guloso::verifica(){
    int n=custo->nPecas(fechados->get_ultimo()->get_estado(),tam_N);
    if(n==0)
        return true;
    else
    return false;
}

void Guloso::caminho(){
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

#endif // GULOSO_H_INCLUDED
