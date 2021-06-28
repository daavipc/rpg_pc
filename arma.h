#include <iostream>
#include <string.h>
#include <cstdlib>
#include <ctime>
using namespace std;

class Arma{
protected:
    string nome;
    int id;
    int danoMin;
    int danoMax;
public:
    Arma(int vetor[4]);
    void imprimeDados();
    int obtemID();
    void imprimeArma(int vetor[4]);
    int calculaDano();
    string obtemNome(int id);
    ~Arma();
};