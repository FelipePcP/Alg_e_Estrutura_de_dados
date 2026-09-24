//////////////////////////////////////////////////////////
//Programa que implemanta uma lista duplamente encadeada//
//////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

///////////////////////////
//declaracao da estrutura//
///////////////////////////

struct no {
	int numero;
	struct no *anterior;
	struct no *proximo;
};

////////////////////////////////////
//funcao que insere um no na lista//
////////////////////////////////////

struct no *inserir(struct no *cabeca, int numero){      //inserir(funcao) recebe o que ta na direita e devolve o que ta ba esquerda//
	//criacao novo no
	struct no *novoNo = (struct no *) malloc(sizeof(struct no));
	novoNo -> numero = numero;
	novoNo -> anterior = NULL;
	novoNo -> proximo = cabeca; //cabeca velha
	
	//ajuste do apontamento da cabeca
	cabeca = novoNo;
	
	//ajuste do ponteiro anterior do sgundo no
	if (cabeca -> proximo != NULL) {                   //se passar pelo if, ha um segundo numero, nao estou sozinho
		cabeca -> proximo -> anterior = cabeca;
	}
	
	//retorno da cabeca atualizada
	return cabeca;
}

////////////////////////////////////
//funcao que exclui um no da lista//
////////////////////////////////////

struct no *excluir(struct no *cabeca, int numero) {     //exclui o numero que escolher e arruma os ponteiros
	//cenario facil - lista vazia
	if (cabeca == NULL) {
		return cabeca;
	}
	//cenario facil - excluir um unico
	if (cabeca -> numero == numero) {
		struct no *limpaBunda = cabeca;
		cabeca = cabeca -> proximo;
		free(limpaBunda);
	//cenario facil: excluir o Nao nulo
		if(cabeca != NULL) {
			cabeca -> anterior = NULL;
		}
		return cabeca;
	}	
	
	//procura do no a ser excluido
	struct no *ponteiro = cabeca;
	while ((ponteiro != NULL) && (ponteiro -> numero != numero)) {
		ponteiro = ponteiro -> proximo;
	}
	
	//cenario dificil - n encontrei o numero na lista
	if (ponteiro == NULL) {
		return cabeca;
	}
	
	//cenario dificil - excluir o ultimo
	ponteiro -> anterior -> proximo = ponteiro -> proximo;
	if (ponteiro -> proximo != NULL) { //cenario dificil - excluir no meio
		ponteiro -> proximo -> anterior = ponteiro -> anterior;
	}
	free(ponteiro);
	
	//retorno da cabeca atualizada
	return cabeca;
}

//////////////////////////////
//funcao que imprime a lista//
//////////////////////////////

void imprimir(struct no *cabeca) {
	struct no *ponteiro = cabeca;
	while (ponteiro != NULL) {
		printf("%d\n", ponteiro -> numero);
		ponteiro = ponteiro -> proximo;
	}
}

////////////////////////////////////////////
//funcao proncipal de execucao do programa//
////////////////////////////////////////////

int main () {
	//declaracao da cabeca da lista
	struct no *cabeca = NULL;
	
	//primeiro teste - imprimir a cabeca
	imprimir(cabeca);
	cabeca = excluir(cabeca, 0);
	
	cabeca = inserir (cabeca, 1);
	cabeca = inserir (cabeca, 2);
	cabeca = inserir (cabeca, 3);
	cabeca = inserir (cabeca, 4);
	cabeca = inserir (cabeca, 5);
	imprimir(cabeca);
	
	cabeca = excluir (cabeca, 0);
	cabeca = excluir (cabeca, 1);
	cabeca = excluir (cabeca, 3);
	cabeca = excluir (cabeca, 5);
	imprimir(cabeca);
	
	cabeca = excluir(cabeca, 2);
	cabeca = excluir(cabeca, 4);
	imprimir(cabeca);
	
	//segundo teste
	int i = 0;
	while (1) {
		cabeca = inserir(cabeca, 1);
	}
}
