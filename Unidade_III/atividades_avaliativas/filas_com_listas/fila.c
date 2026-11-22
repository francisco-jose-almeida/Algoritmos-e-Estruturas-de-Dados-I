#include <stdio.h>
#include <stdlib.h>

#include "fila.h"

void inicializar(Fila *fila){
	fila->inicio=fila->fim=NULL;
}

int estaVazia(Fila *fila){
	return fila->inicio==NULL && fila->fim==NULL;
}

int enqueue(Fila *fila, int valor){
	No* novo= (No*) malloc(sizeof(No));

	if(novo==NULL) return 2;

	novo->dado=valor;

	novo->proximo=NULL;

	if(estaVazia(fila))
		fila->inicio=novo;
	else
		fila->fim->proximo=novo;

	fila->fim=novo;

	return 0;
}

int dequeue(Fila *fila, int *valor){
	if(estaVazia(fila)){
		return 1;
	}

	No* novo = fila->inicio;

	*valor=fila->inicio->dado;

	fila->inicio=fila->inicio->proximo;

	if(novo==fila->fim)
		fila->fim=NULL;

	free(novo);


	return 0;

}
int front(Fila *fila, int *valor){
	if(estaVazia(fila)){
		return 1;
	}

	*valor=fila->inicio->dado;

	return 0;
}

int back(Fila *fila,int *valor){
	if(estaVazia(fila)){
		return 1;
	}

	*valor=fila->fim->dado;

	return 0;
}
void imprimirFila(Fila *fila){
	No* atual=fila->inicio;

	printf("Inicio\n");

	while(atual!=NULL){
		printf("%d -> ",atual->dado);
		atual=atual->proximo;
	}

	printf("NULL\n\n");
}

int contarElementos(Fila *fila){
	No* atual=fila->inicio;

	int contador=0;

	while(atual!=NULL){
		contador++;
		atual=atual->proximo;
	}

	return contador;
}
void liberarFila(Fila *fila){
	No* atual=fila->inicio;

	while(atual!=NULL){
		No *proximo=atual->proximo;
		free(atual);
		atual=proximo;
	}

	fila=NULL;
};
