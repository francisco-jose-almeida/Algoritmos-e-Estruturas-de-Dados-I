#include <stdio.h>
#include <stdlib.h>

typedef struct no{
	int dado;
	No* anterior;
	No* proximo;
}No;

typedef struct lista{
	No *inicio;
	No *fim;
} Lista;

void inicializar(Lista *lista){
	No *inicio = malloc(sizeof(No));
	No *fim = malloc(sizeof(No));

	*lista->inicio=inicio;
	*lista->fim=fim;
}

void inserirInicio(Lista *lista, int valor){
	No* novo=(No*) malloc(sizeof(No));

	if(novo==NULL) return;

	novo->dado = valor;
	novo->anterior = NULL;
	novo->proximo = *lista->inicio;
	*lista->inicio = novo;
}

void inserirFinal(Lista *lista, int valor){
	No* novo=(No*) malloc(sizeof(No));

	if(novo==NULL) return;

	novo->dado = valor;
	novo->anterior = *lista->final;
	novo->proximo = NULL;
	*lista->final = novo;
}

void inserirPosicao(Lista *lista, int valor, int posicao){

	No* atual=*lista->inicio;

	int contador=0;

	if(novo==NULL) return;

	while(atual->proximo!=NULL){
		if(contador==posicao){
			No* novo=(No*) malloc(sizeof(No));
			novo->dado = valor;
			novo->anterior = atual->anterior;
			novo->proximo = atual;
			return;
		}
		contador++;
		atual=atual->proximo;
	}
	return
}

void removerInicio(Lista *lista){
	*lista->inicio=*lista->inicio->proximo;
	
	free(*lista->inicio->anterior);

	*lista->inicio->anterior=NULL;
}

void removerFinal(Lista *lista){
	*lista->fim=*lista->fim->anterior;
	
	free(*lista->fim->proximo);

	*lista->fim->proximo=NULL;
}

void removerValor(Lista *lista){
	No* atual=*lista->inicio;
	
	if(atual==NULL) return;
	
	while(atual->proximo != NULL && atual->dado != valor){
		atual=atual->proximo;
	}

	if(atual->anterior == NULL)
		*lista->inicio = atual->proximo;
	else
		atual->anterior->proximo=atual->proximo;
		atual->proximo->anterior=atual->anterior;
	free(atual);

}

No *buscar(Lista lista, int valor){
	No* atual = lista->inicio;

	while(atual->proximo != NULL){
		if(atual->dado==valor) return atual;
		atual=atual->proximo;
	}

	return NULL;
}

void imprimirDireto(Lista lista){
	No* atual=lista->inicio;

	printf("NULL <->");

	while(atual->proximo!=NULL){
		printf("%d <-> ",atual->dado);
		atual=atual->proximo;
	}

	printf("NULL\n");
}

void imprimirInverso(Lista *lista){
	No* atual=lista->fim;

	printf("NULL <->");

	while(atual!=NULL){
		printf("%d <-> ",atual->dado);
		atual=atual->anterior;
	}

	printf("NULL\n");
}

int contarElementos(Lista *lista){}

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
	Lista lista;

	inicializar(&lista);
	
	

	liberarLista(&lista);

	return 0;
}
