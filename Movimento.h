#ifndef MOVIMENTO_H_INCLUDED
#define MOVIMENTO_H_INCLUDED

class Movimento
{
    private:
        int achaVazio(int* estado);
        int tam_N;
    public:
        Movimento(int tam){tam_N=tam;};
        bool moveR1(int* estado);
        bool moveR2(int* estado);
        bool moveR3(int* estado);
        bool moveR4(int* estado);
};

int Movimento::achaVazio(int* estado)
{
    int i;
    for(i = 0; estado[i]!=0; i++);
    return i;
}

bool Movimento::moveR1(int* estado)
{
    int i = achaVazio(estado);
    if(estado[i-1]>0)
    {
        estado[i]=estado[i-1];
        estado[i-1] = 0;
        return true;
    }
    return false;
}
bool Movimento::moveR2(int* estado)
{
    int i = achaVazio(estado);
    if(estado[i-2]>0)
    {
        estado[i]=estado[i-2];
        estado[i-2] = 0;
        return true;
    }
    return false;
}
bool Movimento::moveR3(int* estado)
{
    int i = achaVazio(estado);
    if(estado[i+1]<0)
    {
        estado[i]=estado[i+1];
        estado[i+1] = 0;
        return true;
    }
    return false;
}
bool Movimento::moveR4(int* estado)
{
    int i = achaVazio(estado);
    if(estado[i+2]<0)
    {
        estado[i]=estado[i+2];
        estado[i+2] = 0;
        return true;
    }
    return false;
}


#endif // MOVIMENTO_H_INCLUDED
