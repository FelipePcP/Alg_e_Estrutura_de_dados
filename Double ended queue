/////////////////////////////////
// Programa double ended queue //
/////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

////////////////////////////////////
//declaracao das variaveis globais//
////////////////////////////////////

int contador = 1;

///////////////////////////////////
//Modelagem da estrutura de dados//
///////////////////////////////////

struct no {
	int numero;
	struct no *proximo;
};

struct deque {
	struct no *filaNormal;
	struct no *filaPreferencial;
};

///////////////////////////////////////////////////
//funcao que insere um no em uma fila espessifica//
///////////////////////////////////////////////////

struct no *inserir(struct no *fila, int numero) {
	struct no *novoNo = (struct no *) malloc(sizeof(struct no));
	novoNo -> numero = numero;
	novoNo -> proximo = fila;
	return novoNo;
}

//////////////////////////////////////////////////
//funcao que remove um no de uma fila especifica//
//////////////////////////////////////////////////

struct no *remover (struct no *fila) {
	//caso mttt facil - fila vazia
	if (fila == NULL) {
		return NULL;
	}
	
	//caso facil - so tem um unico no na fila
	if (fila -> proximo == NULL) {
		printf ("%d\n", fila -> numero);
		free(fila);
		return NULL;
	}
	
	//caso dificil - tem mais de um no na fila
	struct no *penultimo = fila;
	while (penultimo -> proximo -> proximo !=NULL) {
		penultimo = penultimo -> proximo;
	}
	printf("%d\n", penultimo -> proximo -> numero);
	free(penultimo -> proximo);
	penultimo -> proximo = NULL;
	return fila;
}

////////////////////////////////////
//funcao que realiza o atendimento//
////////////////////////////////////

void atender(struct deque *cabeca){
	//caso facil de mais- ambas filas vazias
	if ((cabeca -> filaNormal == NULL) && (cabeca -> filaPreferencial == NULL)) {
		contador = 1;
		return;
	}
	
	//caso meio facil - so tem normal
	if (cabeca -> filaPreferencial == NULL) {
		cabeca -> filaNormal = remover(cabeca -> filaNormal);
		contador = 1;
		return;
	}
	
	//caso facil engual o de cima -so tem preferencial
	if (cabeca -> filaNormal == NULL) {
		cabeca -> filaPreferencial = remover(cabeca -> filaPreferencial);
		contador = 1;
		return;
	}
	
	//caso dificil - tem gnt nas duas filas
	if((contador % 4) == 0) {
		cabeca -> filaNormal = remover(cabeca -> filaNormal);
	} else {
		cabeca -> filaPreferencial = remover(cabeca -> filaPreferencial);
	}
	contador++;
}

////////////////////////////////////////////
//funcao principal de execucao do programa//
////////////////////////////////////////////

int main () {
	struct deque *cabeca = (struct deque*) malloc(sizeof(struct deque));
	cabeca -> filaNormal = NULL;
	cabeca -> filaPreferencial = NULL;
	
	atender(cabeca);
	
	int i = 0;
	for (i = 0 ; i < 10 ; i++) {
		cabeca -> filaNormal = inserir(cabeca -> filaNormal, i);
	}
	for (i = 1000 ; i < 1010 ; i++) {
		cabeca -> filaPreferencial = inserir(cabeca -> filaPreferencial, i);
	}
	for (i = 0 ; i < 20 ; i++){
		atender(cabeca);
	}
}
