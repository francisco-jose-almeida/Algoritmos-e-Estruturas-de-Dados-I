#include <stdio.h>
#include <stdlib.h>

typedef struct No{
	int dado;
	struct No* anterior;
	struct No* proximo;
}No;

typedef struct lista{
	No *inicio;
	No *fim;
} Lista;

void inicializar(Lista *lista){
	lista->inicio=NULL;
	lista->fim=NULL;
}

void inserirInicio(Lista *lista, int valor){
	No* novo=(No*) malloc(sizeof(No));

	if(novo==NULL) return;

	novo->dado = valor;
	novo->anterior = NULL;

	if(lista->inicio==NULL && lista->fim==NULL){
		lista->inicio=lista->fim=novo;
		novo->proximo=NULL;
	}
	else{
		novo->proximo=lista->inicio;
		lista->inicio->anterior=novo;
	}
	lista->inicio = novo;
}

void inserirFinal(Lista *lista, int valor){
	No* novo=(No*) malloc(sizeof(No));

	if(novo==NULL) return;

	novo->dado = valor;
	novo->anterior = lista->fim;
	novo->proximo = NULL;

	if(lista->inicio==NULL && lista->fim==NULL){
		lista->inicio=lista->fim=novo;
		novo->anterior=NULL;
	}
	else{
		novo->anterior=lista->fim;
		lista->fim->proximo = novo;
	}
	lista->fim = novo;
}

void inserirPosicao(Lista *lista, int valor, int posicao){
	No* atual=lista->inicio;

	int contador=0;

	if(lista->inicio==NULL && lista->fim==NULL){
		No* novo=(No*) malloc(sizeof(No));
		novo->dado = valor;
		novo->anterior = NULL;
		novo->proximo = NULL;
		lista->inicio=lista->fim=novo;
		return;
	}

	while(atual!=NULL){
		contador++;
		if(contador==posicao){
			No* novo=(No*) malloc(sizeof(No));
			novo->dado = valor;
		
			novo->anterior=atual->anterior;
			novo->proximo=atual;

			if(atual->anterior!=NULL)
				atual->anterior->proximo=novo;
			else
				lista->inicio=novo;
			
			atual->anterior=novo;
			
			return;
		}
		atual=atual->proximo;
	}

	printf("Posicao %d invalida, A lista tem elementos entre 1 e %d !\n",posicao,contador);

	return;
}

void removerInicio(Lista *lista){

	if(lista->inicio==NULL && lista->fim==NULL){ 
		printf("Lista Vazia, Nada a remover!\n");
		return;
	}

	lista->inicio=lista->inicio->proximo;
	
	free(lista->inicio->anterior);

	lista->inicio->anterior=NULL;
}

void removerFinal(Lista *lista){
	if(lista->inicio==NULL && lista->fim==NULL){ 
		printf("Lista Vazia, Nada a remover!\n");
		return;
	}

	lista->fim=lista->fim->anterior;
	
	free(lista->fim->proximo);

	lista->fim->proximo=NULL;
}

void removerValor(Lista *lista,int valor){
	No* atual=lista->inicio;
	
	if(atual==NULL) return;
	
	while(atual->proximo != NULL && atual->dado != valor){
		atual=atual->proximo;
	}

	if(atual->anterior == NULL)
		lista->inicio = atual->proximo;
	else
		atual->anterior->proximo=atual->proximo;
		atual->proximo->anterior=atual->anterior;
	free(atual);

}

No *buscar(Lista *lista, int valor){
	No* atual = lista->inicio;

	int contador=0;

	while(atual != NULL){
		contador++;
		if(atual->dado==valor){ 
			printf("Elemento %d encontrado na posicao %d\n",valor,contador);
			return atual;
		}
		atual=atual->proximo;
	}
	
	printf("Elemento %d nao encontrado!\n",valor);
	return NULL;
}

void imprimirDireto(Lista *lista){
	No* atual=lista->inicio;

	printf("\n\nNULL <-> ");

	while(atual!=NULL){
		printf("%d <-> ",atual->dado);
		atual=atual->proximo;
	}

	printf("NULL\n\n");
}

void imprimirInverso(Lista *lista){
	No* atual=lista->fim;

	printf("\n\nNULL <-> ");

	while(atual!=NULL){
		printf("%d <-> ",atual->dado);
		atual=atual->anterior;
	}

	printf("NULL\n\n");
}

int contarElementos(Lista *lista){
	No* atual = lista->inicio;

	int contador=0;

	while(atual!=NULL){
		contador++;
		atual=atual->proximo;
	}

	printf("A lista tem %d elementos\n",contador);

	return contador;
}

void liberarLista(Lista *lista){
	No *atual=lista->inicio;

	if(lista->inicio==NULL && lista->fim==NULL) return;

	while(atual->proximo != NULL){
		No *proximo=atual->proximo;
		free(atual);
		atual=proximo;
	}
	lista->inicio=NULL;
	lista->fim=NULL;
}

int main(){
	Lista lista;

	int opcao=0;

	int valor,posicao;
	
	inicializar(&lista);
	
	while(1){

		printf("Menu\n"
			"0 - Sair\n"
			"1 - Inserir no inicio\n"
			"2 - Inserir no final\n"
			"3 - Inserir em posicao\n"
			"4 - Remover do inicio\n"
			"5 - Remover do final\n"
			"6 - Remover valor\n"
			"7 - Buscar valor\n"
			"8 - Imprimir direto\n"
			"9 - Imprimir inverso\n"
			"10 - Contar elementos\n");
		scanf("%d",&opcao);

		if(opcao==0) break;

		switch(opcao){
			case 1:
				printf("Digite o valor a ser inserido\n");
				scanf("%d",&valor);
				inserirInicio(&lista,valor);
				break;
			case 2:
				printf("Digite o valor a ser inserido\n");
				scanf("%d",&valor);
				inserirFinal(&lista,valor);
				break;
			case 3:
				printf("Digite o valor a ser inserido\n");
				scanf("%d",&valor);
				printf("Digite a posicao a ser inserido\n");
				scanf("%d",&posicao);
				inserirPosicao(&lista,valor,posicao);
				break;
			case 4:
				removerInicio(&lista);
				break;
			case 5:
				removerFinal(&lista);
				break;
			case 6:
				printf("Digite o valor a ser removido\n");
				scanf("%d",&valor);
				removerValor(&lista,valor);
				break;
			case 7:
				printf("Digite o valor a ser buscado\n");
				scanf("%d",&valor);
				buscar(&lista,valor);
				break;
			case 8:
				imprimirDireto(&lista);
				break;
			case 9:
				imprimirInverso(&lista);
				break;
			case 10:
				contarElementos(&lista);
				break;
			default:
				printf("Opcao Invalida!\n");
				break;
		}
	}

	liberarLista(&lista);

	return 0;
}
