//////////////////////////////////////////
//lista circular de encadeamento simples//
//////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

//////////////////////////
//Modelagem da estrutura//
//////////////////////////

struct no{
	int numero;
	struct no *proximo;
};

////////////////////////////////////
//funcao que insere um no na lista//
////////////////////////////////////

struct no *inserir(struct no *cabeca, int numero) {
	// criacao do novoNo
	struct no *novoNo = (struct no *) malloc(sizeof(struct no));
	novoNo -> numero = numero;
	novoNo -> proximo = NULL;
	
	// caso facil - litas vazia
	if (cabeca == NULL) {
		cabeca = novoNo;
		cabeca -> proximo = cabeca;
		return cabeca;
	}
	
	// caso dificil - lista nao vazia
	struct no *ultimo = cabeca;              
	while (ultimo -> proximo != cabeca) {    //<-procura o ultimo
		ultimo = ultimo -> proximo;          
	}
	
	ultimo -> proximo = novoNo;
	novoNo -> proximo = cabeca;
	return cabeca;
}

////////////////////////////////////
//funcao que exclui um no da lista//
////////////////////////////////////

struct no *excluir(struct no *cabeca, int numero) {
	// caso Muito facil - lista vazia
	if (cabeca == NULL) {
		return NULL;
	}
	
	//caso facil - excluir o unico
	if ((cabeca -> numero == numero) && (cabeca -> proximo == cabeca)) {
		free(cabeca);
		return NULL;
	}
	
	//caso dificil - excluir o primeiro
	if (cabeca -> numero == numero) {
		struct no *ultimo = cabeca;
		while (ultimo -> proximo != cabeca) {
			ultimo = ultimo -> proximo;
		}
		cabeca = cabeca -> proximo;
		
		free(ultimo -> proximo);
		ultimo -> proximo = cabeca;
		return cabeca;
	}
	
	// Caso muito dificil - excluir no meio ou no final
	struct no *anterior =cabeca;
	while ((anterior -> proximo != cabeca) && (anterior -> proximo -> numero != numero)) {
		anterior = anterior -> proximo;
	}
	if (anterior -> proximo == cabeca) {
		return cabeca;
	}
	struct no *limpaBunda = anterior -> proximo;
	anterior -> proximo = anterior -> proximo -> proximo;
	free(limpaBunda);
	return cabeca;
}

//////////////////////////////////////
//funcao que imprime a lista na tela//
//////////////////////////////////////

void imprimir(struct no *cabeca) {
	if (cabeca == NULL) {
		return;
	}
	
	struct no *ponteiro = cabeca;
	do {
		printf("%d\n", ponteiro -> numero);
		ponteiro = ponteiro -> proximo;
	} while (ponteiro != cabeca);
}

///////////////////////////////////////////
//funcao principalde execucao do programa//
///////////////////////////////////////////

int main() {
	struct no *cabeca = NULL;
	
	imprimir(cabeca);
	cabeca = excluir (cabeca, 0);
	
	cabeca = inserir (cabeca, 1);
	cabeca = inserir (cabeca, 2);
	cabeca = inserir (cabeca, 3);
	cabeca = inserir (cabeca, 4);
	cabeca = inserir (cabeca, 5);
	imprimir (cabeca);
	
	cabeca = excluir (cabeca, 1);
	cabeca = excluir (cabeca, 3);
	cabeca = excluir (cabeca, 5);
	imprimir(cabeca);

	cabeca = excluir (cabeca, 0);
	cabeca = excluir (cabeca, 2);
	cabeca = excluir (cabeca, 4);
	imprimir(cabeca);
}
