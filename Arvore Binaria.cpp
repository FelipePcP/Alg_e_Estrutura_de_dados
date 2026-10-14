///////////////////////////////////////////////
// progrma que implementa uma Arvore binaria //
///////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

///////////////////////////////////
// declaracao da estrutura do no //
///////////////////////////////////

struct no {
int numero;
struct no *esquerda;
struct no *direita;
};

///////////////////////////////////////
// funcao que insere um no na arvore //
///////////////////////////////////////

struct no *inserir(struct no *raiz, int numero) {
//cenario facil arvore vazia
if (raiz == NULL){

// criacao do novo no
struct no *novoNo = (struct no *) malloc(sizeof(struct no));
novoNo -> numero = numero;
novoNo -> esquerda = NULL;
novoNo -> direita = NULL;

//retorno do novo no para raiz
return novoNo;
}

// cenario dificil arvore n vazia
int sorteio = (rand() % 2);
if (sorteio) {
raiz -> esquerda = inserir(raiz -> esquerda, numero);
} else {
raiz -> direita = inserir(raiz -> direita, numero);
}

return raiz;
}

//////////////////////////////////////////
// funcao que faz a navegacao pre ordem //
//////////////////////////////////////////

void navegarPreOrdem(struct no *raiz) {
if (raiz == NULL) return; // protecao

printf ("%d", raiz -> numero);
navegarPreOrdem(raiz -> esquerda);
navegarPreOrdem(raiz -> direita);
}

//////////////////////////////////////////
// funcao que faz a navegacao Em-ordem //
//////////////////////////////////////////

void navegarEmOrdem(struct no *raiz) {
if (raiz == NULL) return; // protecao

navegarEmOrdem(raiz -> esquerda);
printf ("%d", raiz -> numero);
navegarEmOrdem(raiz -> direita);
}

//////////////////////////////////////////
// funcao que faz a navegacao Pos ordem //
//////////////////////////////////////////

void navegarPosOrdem(struct no *raiz) {
if (raiz == NULL) return; // protecao

navegarPosOrdem(raiz -> esquerda);
navegarPosOrdem(raiz -> direita);
printf ("%d", raiz -> numero);
}


int main () {
//declaracao de variaveis
struct no *raiz = NULL;
int i = 0;

//inicializacao da aleatoriedade
time_t t;
srand(time(&t));

//inclusao de nos na arvore
for (i = 0 ; i < 10 ; i++){
raiz = inserir(raiz, i);
}

//navegacoes

printf("Pre-ordem: ");
navegarPreOrdem(raiz);
printf("\n");

printf("Em-ordem: ");
navegarEmOrdem(raiz);
printf("\n");

printf("Pos-ordem: ");
navegarPosOrdem(raiz);
printf("\n");
}
