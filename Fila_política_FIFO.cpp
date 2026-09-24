//////////////////////////////////////////////////////
// programa que implementa uma fila (politica FIFO) //
//////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

//declaracao estrutura do no

struct no {
	int numero;
	struct no *proximo;
};

//funcao que insere um no na fila

struct no *entrar(struct no *cabeca, int numero) {
	
	//criacao de um novo no
	struct no *novoNo = (struct no *) malloc(sizeof(struct no));
	novoNo -> numero = numero;
	novoNo -> proximo = cabeca;
	
	return novoNo;
}

// funcao que remove da fila

struct no  *sair(struct no *cabeca) {
	
	// Caso facil: fila vazia
	if (cabeca == NULL) {
		return cabeca;
	}
	
	//caso medio: so tem um unico no na fila
	if (cabeca -> proximo == NULL) {
		printf ("%d\n", cabeca -> numero);
		free (cabeca);
		return NULL;
	}
	
	//caso dificil: fila nao vazia
	struct no *penultimo = cabeca;
	while (penultimo -> proximo -> proximo != NULL) {
		penultimo = penultimo -> proximo;
	}
	printf("%d\n", penultimo -> proximo -> numero);
	free(penultimo -> proximo);
	penultimo -> proximo = NULL;
	return cabeca;
}

//funcao principal

int main() {
	//declaracao de variaveis
	struct no *cabeca = NULL;
	int i = 0;
	
	//processamento
	for ( i = 0 ; i < 5000 ; i++){
		cabeca = entrar(cabeca, i);
	}
	for ( i = 0 ; i < 5000 ; i++){
		cabeca = sair(cabeca);
	}
	return 0;
}
