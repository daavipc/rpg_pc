#include "magia.h"

Arma::Arma(string nomeMagia)
{
    srand(time(0));
    this->nome = nomeMagia;
    int qtdAtributos = 10; 
    Accessdata *a = new Accessdata(qtdAtributos);

    int *atributos = a->obtemAtributos(nomeMagia);

    this->dano = atributos[0];
    this->cura = atributos[1];
    this->gastoMana = atributos[2];
    
    this->listasDeClasses = new int[7];

    int j; 
    for(int i=2; i< qtdAtributos; i++)
        listasDeClasses[j++] = atributos[i];

    delete a;
    delete atributos; 
}