#include "personagem.h"

Personagem::Personagem(string classePersonagem)
{
    srand(time(0));
    
    int qtdAtributos = 7; 

    Accessdata *a = new Accessdata(qtdAtributos);

    int *atributos = a->obtemAtributos (classePersonagem);

    this->vida = atributos[0];
    this->mana = atributos[1];
    this->forca = atributos[2];
    this->magia = atributos[3];
    this->armadura = atributos[4];
    this->resistencia = atributos[5];
    this->agilidade = atributos[6];

    delete a;
    delete atributos; 
}
