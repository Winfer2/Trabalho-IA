#ifndef IDA_H_INCLUDED
#define IDA_H_INCLUDED

class IDA{
    private:
    Heuristica* custo;
    Movimento* moviment;
    Lista* abertos;
    Lista* fechados;
    Lista* descartados;
    int tam_N;
    int patamar;
    int *estadoInicial;
    void explora();
    bool verifica();
    void copia(int* a,int* b);
    void reseta();
    public:
        void resolve();
        void caminho();
        IDA(int* estad, int tam);
};

IDA::IDA(int* estad, int tam){
    tam_N=tam;
    custo = new Heuristica();
    moviment = new Movimento(tam_N);
    abertos = new Lista();
    estadoInicial = new int[(2*tam)+1];
    copia(estadoInicial,estad);
    fechados = new Lista();
    descartados = new Lista();
    abertos->adicionar(NULL,estadoInicial,tam_N);
    patamar = custo->nPecas(abertos->get_raiz()->get_estado(),tam);
}

bool IDA::verifica(){
    int n=custo->nPecas(fechados->get_ultimo()->get_estado(),tam_N);
    if(n==0)
        return true;
    else
    return false;
}
void IDA::copia(int* a,int* b){
    for(int i = 0; i<(2*tam_N)+1;i++)
        a[i]=b[i];
}
void IDA::explora(){
    int* estad = new int[(2*tam_N)+1];
    copia(estad,fechados->get_ultimo()->get_estado());
    for(int i = 1; i<5 ; i++){
        int *aux=new int[2*tam_N+1];
        copia(aux,estad);
        if(moviment->mover(i,aux)){
            if((fechados->get_ultimo()->get_profundidade()+custo->nPecas(aux,tam_N)+1)<=patamar)
                abertos->adicionar(fechados->get_ultimo(),aux,tam_N);
            else
                descartados->adicionar(fechados->get_ultimo(),aux,tam_N);
        }
    }
}

void IDA::caminho(){
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

void IDA::resolve(){
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
    if(abertos->get_raiz()==NULL){
    reseta();
    }
    }
}

void IDA::reseta(){
    int novoPatamar=custo->nPecas(descartados->get_raiz()->get_estado(),tam_N)+descartados->get_raiz()->get_profundidade();
    while(descartados->get_ultimo()!=NULL){
        if(custo->nPecas(descartados->get_ultimo()->get_estado(),tam_N)+descartados->get_ultimo()->get_profundidade()<novoPatamar)
            novoPatamar=custo->nPecas(descartados->get_ultimo()->get_estado(),tam_N)+descartados->get_ultimo()->get_profundidade();
        descartados->apagar(descartados->get_ultimo()->get_ID());
    }
    patamar=20*novoPatamar;
    std::cout<<patamar<<endl;
    abertos->adicionar(NULL,estadoInicial,tam_N);
    while(fechados->get_ultimo()!=NULL){
        fechados->apagar(fechados->get_ultimo()->get_ID());
    }
}

#endif // IDA_H_INCLUDED
