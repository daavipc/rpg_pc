#include <iostream>
#include <string.h>
#include <cstdlib>
#include <ctime>
using namespace std;

class Personagem
{
protected:
    int vidaMax;
    int vida;
    int manaMax;
    int mana;
    int forca;
    int magia;
    int resFisico;
    int resMagia;
    int agilidade;
    Arma *arma;
    Arma *anterior;
    int idArma[7];
    int idMagia[7];
public:
    Personagem(int vetor[18]);
    void imprimeDados();
    int mostraVida();
    int mostraMana();
    void trocarArma(int flag);
    void recebeDano(int dano, int flag);
    int lendaria(int op);
    int esquiva();
    void manipulaMana(int gasto, int op);
    int ataqueFisico();
    int menuMagia();
    int ataqueMagia(int dano);
    ~Personagem();
};