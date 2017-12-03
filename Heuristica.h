#ifndef HEURISTICA_H_INCLUDED
#define HEURISTICA_H_INCLUDED

class Heuristica{
    private:

    public:
        Heuristica(){};
        int nPecas(int* estado, int tam_N);
};

int Heuristica::nPecas(int* estado, int tam_N){
    int quant = 0;
    int i = 0;
    for(; i<tam_N ; i++){
        if(estado[i]>0)
            quant++;
    }
    i++;
    for(; i<(2*tam_N)+1 ; i++){
        if(estado[i]<0)
            quant++;
    }
    return quant;
}
#endif // HEURISTICA_H_INCLUDED
