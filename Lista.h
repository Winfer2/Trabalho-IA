#ifndef LISTA_H
#define LISTA_H

#include <iostream>

using namespace std;

class No_Lista{
    private:
        No_Lista* pai;
        No_Lista* filho;        No_Lista* est_ant;
        int profundidade;
        int ID;
        int* estado;
        int tam_N;
    public:
        No_Lista(No_Lista* no_pai, No_Lista* no_est_ant, int prof, int tamN, int* estad, int I_D);
        ~No_Lista(){delete[] estado;}
        int get_ID(){return ID;}
        int get_profundidade(){return profundidade;}
        int get_N(){return tam_N;}
        int* get_estado(){return estado;}
        No_Lista* get_pai(){return pai;}
        No_Lista* get_filho(){return filho;}
        No_Lista* get_est_ant(){return est_ant;}
        void set_filho(No_Lista* no){filho = no;}
        void set_pai(No_Lista* no){pai = no;}
};

No_Lista::No_Lista(No_Lista* no_pai, No_Lista* no_est_ant, int prof, int tamN, int* estad, int I_D){
    ID = I_D;
    pai = no_pai;
    est_ant = no_est_ant;
    profundidade = prof;
    tam_N = tamN;
    estado = estad;
    filho = NULL;
}

class Lista{
    private:
        No_Lista* raiz;
        No_Lista* ultimo;
        int tamanho;

    public:
        Lista(){raiz = NULL; ultimo = NULL; tamanho = 0;}
        ~Lista(){ while(ultimo != NULL) apagar(ultimo->get_ID()); }
        No_Lista* get_ultimo(){return ultimo;}
        No_Lista* get_raiz(){return raiz;}
        int get_tamanho(){return tamanho;}
        void adicionar(No_Lista* no_est_ant, int* estad, int tam_N);
        void apagar(int I_D);
        void imprime();
};

void Lista::imprime(){
    No_Lista* temp = raiz;
    while(temp != NULL){
        for(int i = 0; i < (2*temp->get_N()+1); i++){
            cout << temp->get_ID();
            cout << ")" << temp->get_estado()[i] << "\t";
        }cout << "\n";
        temp = temp->get_filho();
    }
}

void Lista::adicionar(No_Lista* no_est_ant, int* estad, int tam_N){
    if(tamanho == 0){
        No_Lista* no = new No_Lista(ultimo, no_est_ant, 0, tam_N, estad, 0);
        raiz = ultimo = no;
        tamanho++;
        return;
    }

    No_Lista* no = new No_Lista(ultimo, no_est_ant, (no_est_ant->get_profundidade()+1), tam_N, estad, (ultimo->get_ID()+1));
    ultimo->set_filho(no);
    ultimo = no;
    tamanho++;
}

void Lista::apagar(int I_D){
    if(tamanho == 0) return;

    No_Lista *temp = raiz;
    while(temp->get_ID() != I_D) temp = temp->get_filho();
    if(temp->get_pai() != NULL) temp->get_pai()->set_filho(temp->get_filho());
    else raiz = temp->get_filho();

    if(temp->get_filho() != NULL) temp->get_filho()->set_pai(temp->get_pai());
    else ultimo = temp->get_pai();

    delete temp;
    tamanho--;
}

#endif // LISTA_H
