#include <stdio.h>
#include <stdlib.h>

typedef struct no{
	int dado;
	No* anterior;
	No* proximo;
}No;

void inserirInicio(No **lista, int valor){
	No* novo=(No*) malloc(sizeof(No));

	if(novo==NULL) return;

	novo->dado = valor;
	novo->anterior = NULL;
	novo->proximo = *lista;
	*lista = novo;
}

void inserirFinal(No **lista, int valor){
	No* novo=(No*) malloc(sizeof(No));

	No* atual=*lista;

	if(novo==NULL) return;

	if(*lista==NULL){
		*lista=novo;
		return;
	}

	while(atual->proximo!=NULL){
		atual=atual->proximo;
	}

	atual->proximo=novo;

	novo->dado = valor;
	novo->anterior = atual;
	novo->proximo = NULL;
}

void imprimirLista(No *lista){
	No* atual=lista;

	printf("NULL <->");

	while(atual!=NULL){
		printf("%d <-> ",atual->proximo);
		atual=atual->proximo;
	}

	printf("NULL\n");
}

No* buscar(No *lista, int valor){
	No* atual = lista;

	while(atual != NULL){
		if(atual->dado==valor) return atual;
		atual=atual->proximo;
	}

	return NULL;
}

void remover(No **lista,int valor){
	No* atual=*lista;
	
	while(atual != NULL && atual->dado !=valor){
		atual=atual->proximo;
	}

	if(atual==NULL) return;

	if(atual->anterior == NULL)
		*lista = atual->proximo;
	else
		atual->anterior->proximo=atual->proximo;
	free(atual);
}

void liberarLista(No **lista){
	No *atual=*lista;

	while(atual != NULL){
		No *proximo=atual->proximo;
		free(atual);
		atual=proximo;
	}
	*lista = NULL;
}

int main(){
	No *lista = NULL;

	inserirInicio(&lista,20);
	inserirInicio(&lista,10);
	inserirFinal(&lista,30);
	inserirFinal(&lista,40);

	printf("Lista inicial: \n");
	imprimirLista(lista);

	printf("\n Buscando 30: \n");
	
	if(buscar(lista,30) != NULL)
		printf("Elemento encontrado!\n");
	else
		printf("Elemento nao encontrado!\n");

	printf("\n Removendo 20:: \n");
	remover(&lista,20);
	imprimirLista(lista);

	liberarLista(&lista);

	return 0;
}
