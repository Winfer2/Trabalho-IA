#ifndef MOVIMENTO_H_INCLUDED
#define MOVIMENTO_H_INCLUDED

class Movimento
{
    private:
        int achaVazio(int* estado);
        int tam_N;
    public:
        Movimento(int tam){tam_N = tam; cout << tam_N;};
        bool moveR1(int* estado);
        bool moveR2(int* estado);
        bool moveR3(int* estado);
        bool moveR4(int* estado);
};

int Movimento::achaVazio(int* estado)
{
    int i;
    for(i = 0; estado[i] != 0; i++);
    return i;
}

bool Movimento::moveR1(int* estado)
{
    cout << "\nmovimento 1" << endl;
    int i = achaVazio(estado);
    if(i-1 >= 0 && estado[i-1] > 0)
    {
        swap(estado[i], estado[i-1]);
        return true;
    }
    return false;
}
bool Movimento::moveR2(int* estado)
{
    cout << "\nmovimento 2" << endl;
    int i = achaVazio(estado);
    if(i-2 >= 0 && estado[i-2] > 0)
    {
        swap(estado[i], estado[i-2]);
        return true;
    }
    return false;
}
bool Movimento::moveR3(int* estado)
{
    cout << "\nmovimento 3" << endl;
    int i = achaVazio(estado);
    if(i+1 < (2*tam_N+1))
        if(estado[i+1] < 0)
            {
                swap(estado[i], estado[i+1]);
                return true;
            }
    return false;
}
bool Movimento::moveR4(int* estado)
{
    cout << "\nmovimento 4" << endl;
    int i = achaVazio(estado);
    if(i+2 < (2*tam_N+1) && estado[i+2] < 0)
    {
        swap(estado[i], estado[i+2]);
        return true;
    }
    return false;
}


#endif // MOVIMENTO_H_INCLUDED
