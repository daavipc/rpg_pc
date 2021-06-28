#include <iostream>
#include <string.h>
#include <cstdlib>
#include <ctime>
using namespace std;

class Magia
{
private:
    string nome;
    int id;
    int dano;
    int cura;
    int gastoMana;
    
public:
    Magia(int vetor[5]);
    void imprimeDados();
    int obtemID();
    int obtemDano();
    int obtemGasto();
    string obtemNome(int id);
    void imprimeMagia(int vetor[5]);
    ~Magia();
};
