#include "arma.h"

Arma::Arma(string nomeArma)
{
    srand(time(0));
    this->nome = nomeArma;
    int qtdAtributos = 10; 
    Accessdata *a = new Accessdata(qtdAtributos);

    int *atributos = a->obtemAtributos(nomeArma);

    this->danoMin = atributos[0];
    this->danoMax = atributos[1];
    
    this->listasDeClasses = new int[8];

    int j; 
    for(int i=2; i< qtdAtributos; i++)
        listasDeClasses[j++] = atributos[i];

    delete a;
    delete atributos; 
}

int Arma::calculaDano()
{
      return (this->danoMin + (rand() %(this->danoMax - this->danoMin +1)));

}

