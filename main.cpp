#include "accessdata.h"
#include <cstdlib>
#include <ctime>
#include <stdlib.h>
#include <fstream>
#include <stdio.h>
#include <time.h>
#include <iostream>
#include <string.h>
#include personagem.h
#include arma.h
#include magia.h

using namespace std;

Accessdata::Accessdata(int qtdAtributos){
this->qtdAtributos = qtdAtributos;
this->atributos = new int[qtdAtributos];
}

string Accessdata::abreArquivo(string nomeDaClasse){
fstream arq;
arq.open(nomeDaClasse, ios::in);
string linha;

if (arq.is_open()){
getline(arq, linha);
}
arq.close();
return linha;
}

int *Accessdata::obtemAtributos(string nomeDaClasse){
string linha = abreArquivo(nomeDaClasse);
char str[linha.size()];
for (int i = 0; i < linha.size(); i++)
str[i] = linha[i];
char ch[2] = ",";
char *token;
char *palavra;
int i = 0;

token = strtok(str, ch);

while (token != NULL){
palavra = token;
token = strtok(NULL, ch);
this->atributos[i++] = atoi(palavra);
}
return this->atributos;
}

Magia::Magia(int vetor[5]){
this->nome = obtemNome(vetor[1]);
this->id = vetor[1];
this->dano = vetor[2];
this->gasto = vetor[3];
this->cura = vetor[4];
}

Magia::~Magia() {}
void Magia::imprimeDados(){
cout << nome << " | " << id << " | " << dano << " | " << gasto << " | " << cura << " | \n ";
}

int Magia::obtemID(){
return id;
}

int Magia::obtemDano(){
return dano;
}

string Magia::obtemNome(int id){
string base;

if (id == 1){
base = "Poção de Vida";
}
else if (id == 2){
base = "Halito de Fogo";
}
else if (id == 3){
base = "Bio";
}
else if (id == 4){
base = "Cura";
}
else if (id == 5){
base = "Flama Gelada";
}
else if (id == 6){
base = "Intoxicacao";
}
else if (id == 7){
base = "Tempestade";
}

return base;
}

void Magia::imprimeMagia(int vetor[7]){
for (int i = 0; i <= 7; i++){
if (vetor[i] == 1)
cout << "1* Poção de Vida - ";
else if (vetor[i] == 2)
cout << "2* Halito de Fogo - ";
else if (vetor[i] == 3)
cout << "3* Bio - ";
else if (vetor[i] == 4)
cout << "4* Cura - ";
else if (vetor[i] == 5)
cout << "5* Flama Gelada - ";
else if (vetor[i] == 6)
cout << "6* Intoxicacao - ";
else if (vetor[i] == 7)
cout << "7* Tempestade - ";
else if (vetor[i] == 8)
cout << "8* Voltar para o menu";
}
}

int Magia::obtemGasto(){
return gasto;
}

Arma::Arma(int vetor[4]){
this->id = vetor[1];
this->danoMin = vetor[2];
this->danoMax = vetor[3];
this->nome = obtemNome(vetor[1]);
}

Arma::~Arma() {}
void Arma::imprimeDados(){
cout << nome << " | " << id << " | " << danoMin << " | " << danoMax << " | \n ";
}

int Arma::calculaDano(){
int dano = this->danoMin + (rand() % (this->danoMax - this->danoMin));
return dano;
}

int Arma::obtemID(){
return id;
}

string Arma::obtemNome(int id){
string base;
if (id == 0){
base = "Desarmado";
}
else if (id == 1){
base = "Garra letal";
}
else if (id == 2){
base = "Tridente sagrado";
}
else if (id == 3){
base = "Espada barroca";
}
else if (id == 4){
base = "Porrete";
}
else if (id == 5){
base = "Cajado";
}
else if (id == 6){
base = "Besta";
}
else if (id == 7){
base = "Esfera de ataque";
}
else if (id == 8){
base = "Voto solene de bul-kathos";
}
return base;
}

void Arma::imprimeArma(int vetor[4]){
for (int i = 0; i < 4; i++){

if (vetor[i] == 1)
cout << "1* Garra Letal - ";
else if (vetor[i] == 2)
cout << "2* Tridente Sagrado - ";
else if (vetor[i] == 3)
cout << "3* Espada Barroca - ";
else if (vetor[i] == 4)
cout << "4* Porrete - ";
else if (vetor[i] == 5)
cout << "5* Cajado - ";
else if (vetor[i] == 6)
cout << "6* Besta - ";
else if (vetor[i] == 7)
cout << "7* Esfera de Ataque - ";
}
}

Personagem::Personagem(int vetor[18]){
this->vida = vetor[0];
this->vidaMax = vetor[0];
this->mana = vetor[1];
this->manaMax = vetor[1];
this->forca = vetor[2];
this->magia = vetor[3];
this->resFisico = vetor[4];
this->resMagia = vetor[5];
this->agilidade = vetor[6];

for (int i = 0; i < 4; i++){
this->idArma[i] = vetor[(7 + i)];
}
for (int i = 0; i < 7; i++){
this->idMagia[i] = vetor[(11 + i)];
}

Accessdata *a = new Accessdata(4);
int *atributos = a->obtemAtributos("2desarmado.txt");
arma = new Arma(atributos);
anterior = arma;
delete a;
delete atributos;
}

Personagem::~Personagem() {}
void Personagem::imprimeDados(){
cout << vida << " | " << mana << " | " << forca << " | " << magia << " | ";
cout << resFisico << " | " << resMagia << " | " << agilidade << "\n";
}

int Personagem::mostraVida(){
return vida;
}

int Personagem::mostraMana(){
return mana;
}

int Personagem::ataqueFisico(){
float dano = arma->calculaDano();
dano += dano * (this->forca * 0.01);
return dano;
}

int Personagem::esquiva(){
int base = rand() % 100 + 1;
if (base < this->agilidade)
return 1;
return 0;
}

void Personagem::recebeDano(int dano, int flag){
if (flag == 1){
dano -= dano * (this->resFisico * 0.01);
}
else if (flag == 2){
dano -= dano * (this->resMagia * 0.01);
}
else if (flag == 3){
dano = dano * (-1);
this->vida += dano;
if (this->vida > this->vidaMax)
this->vida = this->vidaMax;
}

if(flag != 3){
cout << " O dano causado foi de: " << dano << "\n";
this->vida -= dano;
}
}

void Personagem::trocarArma(int flag){
string base;
Accessdata *a = new Accessdata(4);
int *atributos, op, stop;

if (flag == 0){
cout << " \n Escolha sua arma: \n ";
arma->imprimeArma(idArma);

do{
scanf("%d", &op);
getchar();
stop = 0;

for (int i = 0; i < 4; i++){
if (idArma[i] != op)
stop++;
}

if (stop == 4)
cout << "Opção invalida \n";
} while (stop == 4);
switch (op)
{
case 1:
base = "2garra-letal.txt";
break;
case 2:
base = "2tridente.txt";
break;
case 3:
base = "2espada-barroca.txt";
break;
case 4:
base = "2porrete.txt";
break;
case 5:
base = "2cajado.txt";
break;
case 6:
base = "2besta.txt";
break;
case 7:
base = "2esfera-de-ataque.txt";
break;
default:
cout << "Erro: Opcao invalida";
break;
}
anterior = arma;
atributos = a->obtemAtributos(base);
arma = new Arma(atributos);
cout << " \n Sua arma foi alterada para " << arma->obtemNome(op) << "\n ";
}
else if (flag == 1)
{
anterior = arma;
base = "2lendaria.txt";
atributos = a->obtemAtributos(base);
arma = new Arma(atributos);
}
else if (flag == 2){
arma = anterior;
}
cout << "\n";
}

int Personagem::ataqueMagia(int dano){
dano += dano * (this->magia * 0.01);
return dano;
}

int Personagem::menuMagia(){
string base;
Accessdata *a = new Accessdata(4);
Magia *magia;
int *atributos, op, stop, dano, flag;

do{
flag = 1;
cout << "Escolha sua magia: \n ";
magia->imprimeMagia(idMagia);

do{
scanf("%d", &op);
getchar();
stop = 0;

for (int i = 0; i < 7; i++){
if (idMagia[i] != op)
stop++;
}

if (stop == 7)
cout << "Opção inválida \n";
} while (stop == 7);
stop = 0;

switch (op){
case 1:
base = "3pocao.txt";
stop = 1;
break;
case 2:
base = "3halito.txt";
break;
case 3:
base = "3bio.txt";
break;
case 4:
base = "3cura.txt";
stop = 1;
break;
case 5:
base = "3flama.txt";
break;
case 6:
base = "3toxico.txt";
break;
case 7:
base = "3tempestade.txt";
break;
case 8:
cout << "De volta para o menu de combate... \n";
break;
default:
cout << "Opção inválida \n ";
break;
}

if (op != 8){
atributos = a->obtemAtributos(base);
magia = new Magia(atributos);

if((magia->obtemGasto() > mana)){
cout << "Mana insuficiente \n";
flag = 0;
}
}
}while (flag == 0);

if(op!= 8){

dano = magia->obtemDano();
cout << mostraMana();
manipulaMana(magia->obtemGasto(), 1);
cout << mostraMana();
cout << "\n " << magia->obtemNome(op) << " utilizada \n";

delete atributos;
delete a;
delete magia;
}

if(op == 8){
dano = 0;
}

if(stop == 0)
return ataqueMagia(dano);
else
dano = dano * (-1);
return dano;
}
void Personagem::manipulaMana(int gasto, int op)
{
if (op == 1)
this->mana -= gasto;
else if (op == 0)
{
this->mana += gasto;
if (this->mana > this->manaMax)
{
this->mana = this->manaMax;
}
}
}

int lendaria(){
int base = rand() % 100 + 1;

if (base <= 20){
cout << " \n Seu ataque será ampliado \n";
return 1;
}
return 0;
}

int critico(){
int base = rand() % 100 + 1;

if (base <= 30){
cout << " \n Seu dano será dobrado \n";
return 1;
}
return 0;
}

int observaVida(int vida){
if (vida <= 0){
return 1;
}
return 0;
}

void menuCombate(int i, Personagem *playerX, Personagem *playerY){
cout << "\n [" << i << "]";
int op, stop, dano = 1, base, flag;
flag = lendaria();
if (flag)
{
playerX->trocarArma(1);
if (critico()){
dano = 2;
}
}

do{
stop = 1;
cout << " \n HP: " << playerX->mostraVida() << " MP: " << playerX->mostraMana() << " \n Digite sua preferência: \n 1-Ataque Fisico  |  2-Magia  |  3-Trocar arma \n --";
scanf("%d", &op);
getchar();

switch (op){
case 1:
playerX->manipulaMana(10, 0);
dano *= playerX->ataqueFisico();
if (playerY->esquiva())
cout << "O jogador esquivou \n ";
else
playerY->recebeDano(dano, 1);
break;
case 2:
dano = playerX->menuMagia();
if (dano == 0)
stop = 0;
else if(dano < 0){
playerX->recebeDano(dano, 3);
}
else
playerY->recebeDano(dano, 2);
break;
case 3:
flag = 0;
playerX->manipulaMana(10, 0);
playerX->trocarArma(0);
break;
default:
cout << "Inválido \n";
stop = 0;
break;
}
}while (stop == 0);

if(flag){
playerX->trocarArma(2);
}
}

int main(){
srand(time(0));
int q = 18;
Accessdata *a = new Accessdata(q);
int *atributos;
int op, i, n, stop;
int teste[2][q];
Personagem *player1;
Personagem *player2;

for (i = 1; i <= 2; i++){
do{
stop = 1;
cout << " \n[" << i << "] Escolha seu personagem: \n 1-Guerreiro \n 2-Ladrao \n 3-Mago \n 4-Paladino \n 5-Animal \n 6-Troll \n 7-Dragao \n 8-Zumbi \n";
scanf("%d", &op);
getchar();

switch (op){
case 1:
atributos = a->obtemAtributos("1guerreiro.txt");
for (n = 0; n < q; n++)
teste[i][n] = atributos[n];
break;
case 2:
atributos = a->obtemAtributos("1ladrao.txt");
for (n = 0; n < q; n++)
teste[i][n] = atributos[n];
break;
case 3:
atributos = a->obtemAtributos("1mago.txt");
for (n = 0; n < q; n++)
teste[i][n] = atributos[n];
break;
case 4:
atributos = a->obtemAtributos("1paladino.txt");
for (n = 0; n < q; n++)
teste[i][n] = atributos[n];
break;
case 5:
atributos = a->obtemAtributos("1animal.txt");
for (n = 0; n < q; n++)
teste[i][n] = atributos[n];
break;
case 6:
atributos = a->obtemAtributos("1troll.txt");
for (n = 0; n < q; n++)
teste[i][n] = atributos[n];
break;
case 7:
atributos = a->obtemAtributos("1dragao.txt");
for (n = 0; n < q; n++)
teste[i][n] = atributos[n];
break;
case 8:
atributos = a->obtemAtributos("1zumbi.txt");
for (n = 0; n < q; n++)
teste[i][n] = atributos[n];
break;
default:
cout << "\n Opção inválida. \n";
stop = 0;
break;
}
}while (stop == 0);
}
player1 = new Personagem(teste[1]);
player2 = new Personagem(teste[2]);
delete a;
delete atributos;
cout << "\n Jogadores: preparem-se! \n";
stop = 0;
q = 0;

do{
q++;
if (stop == 0){
menuCombate(1, player1, player2);

if (observaVida(player2->mostraVida())){
player2->mostraVida();
cout << "\n O jogador 1 venceu a partida! \n";
stop = 1;
}
}


if (stop == 0){
menuCombate(2, player2, player1);

if (observaVida(player1->mostraVida())){
player1->mostraVida();
cout << "\n O jogador 2 venceu a partida! \n";
stop = 1;
}
}

}while (stop == 0);

return 0;
}