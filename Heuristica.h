#ifndef HEURISTICA_H_INCLUDED
#define HEURISTICA_H_INCLUDED

class Heuristica{
    private:

    public:
        Heuristica();
        int nPretas(int* estado);
};

int Heuristica::nPretas(int* estado, int tam_N){
    int quant = 0;
    for(int i = 0; i<tam_N ; i++){
        if(estado[i]<0)
            quant++;
    }
    return quant;
}
#endif // HEURISTICA_H_INCLUDED
