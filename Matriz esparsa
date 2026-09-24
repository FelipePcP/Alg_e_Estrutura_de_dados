////////////////////////////////////////////
//programa q implementa uma matriz esparsa//
////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

////////////////////////////
//declaracao de constantes//
////////////////////////////

#define MODULO 3

////////////////////////////
//declaracao de estruturas//
////////////////////////////

struct no {                  //controla as colunas
	int numero;
	struct no *proximoNo;
};

struct diretor {             //controla as linhas da tabela
	int resto;
	struct no *proximoNo;
	struct diretor *proximoDiretor;
};
///////////////////////////////////
//declaracao de variaveis globais//
///////////////////////////////////

struct diretor *cabeca = NULL;

////////////////////////////////////
///funcao que procura o diretor/////
///correto, se nao encontrar cria///
//////////////verticalmente/////////
////////////////////////////////////

struct diretor *procuraDiretor(int numero) {
	int resto = (numero % MODULO);
	
	//procura diretor correto
	struct diretor *ponteiro = cabeca;
	
	while ((ponteiro != NULL) && (ponteiro -> resto != resto)) {
		ponteiro = ponteiro -> proximoDiretor;
	}
	
	//cenario em que o diretir correto foi encontrado
	if (ponteiro != NULL) {
		return ponteiro;
	}
	
	//cenario em que o diretir correto NAO foi encontrado
	struct diretor *novoDiretor = (struct diretor *) malloc(sizeof(struct diretor));
	novoDiretor -> resto = resto;
	novoDiretor -> proximoNo = NULL;
	novoDiretor -> proximoDiretor = cabeca;
	cabeca = novoDiretor;       //liha mais importante do codigo, em que o ponteiro ta apontando pro novo diretor
	return novoDiretor;
}

//////////////////////////////////////////////////////////
//funcao que insere um numero na matriz(horizontalmente)//
//////////////////////////////////////////////////////////

void inserir(int numero) {
	struct diretor *ponteiroDiretor = procuraDiretor(numero);
	
	struct no *novoNo = (struct no *) malloc(sizeof(struct no));
	novoNo -> numero = numero;
	novoNo -> proximoNo = ponteiroDiretor -> proximoNo;
	ponteiroDiretor -> proximoNo = novoNo;
}
/////////////////////////////////////////
//funcao que exclui um numero da matriz//
/////////////////////////////////////////

void excluir (int numero) {
	struct diretor *ponteiroDiretor = procuraDiretor(numero);
	
	// cenario MUITO facil: lista vazia
	if (ponteiroDiretor -> proximoNo == NULL) {
		return;
	}
	
	// cenario facil: excluir o primeiro 
	if (ponteiroDiretor -> proximoNo -> numero == numero) {
		struct no *limpabunda = ponteiroDiretor -> proximoNo;
		ponteiroDiretor -> proximoNo = ponteiroDiretor -> proximoNo -> proximoNo;
		free (limpabunda);
		return;
	}
	
	//cenario dificil: procurar pelo numero que vai ser excluido e parar antes dele
	struct no *anterior = ponteiroDiretor -> proximoNo;
	while((anterior -> proximoNo !=NULL) && (anterior -> proximoNo -> numero != numero )) {
		anterior = anterior -> proximoNo;
	}
	
	//cenario em que eu n encontrei
	if (anterior -> proximoNo == NULL) {
		return;
	}
	
	//cenario que eu encontrei
	struct no *limpabunda = anterior -> proximoNo;
	anterior -> proximoNo = anterior -> proximoNo -> proximoNo;
	free(limpabunda);
}


///////////////////////////////////////
//funcao que imprime a matriz na tela//
///////////////////////////////////////


void imprimir() {
	struct diretor *ponteiroDiretor = cabeca;
	printf("resto \t Numeros \n");
	while (ponteiroDiretor != NULL) {
		printf("%d\t", ponteiroDiretor -> resto);
		struct no *ponteiroNo = ponteiroDiretor -> proximoNo;
		while (ponteiroNo != NULL) {
			printf("%d, ", ponteiroNo -> numero);
			ponteiroNo = ponteiroNo -> proximoNo;
		}
		printf("\n");
		ponteiroDiretor = ponteiroDiretor -> proximoDiretor;
	}
}

////////////////////////////////
//Funcao principal de execucao//
////////////////////////////////

int main() {
	inserir(5);
	inserir(293);
	inserir(10);
	inserir(4);
	inserir(144);
	inserir(9);
	inserir(6);
	imprimir();
	excluir(5);
	excluir(9);
	excluir(4);
	imprimir();

}
