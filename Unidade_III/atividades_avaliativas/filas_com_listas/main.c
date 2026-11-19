#include <stdio.h>
#include <stdlib.h>

typedef struct No{
	int dado;
	struct No* proximo;
}No;

typedef struct Fila{
	No *inicio;
	No *fim;
}Fila;

void inicializar(Fila *fila){
	fila->inicio=fila->fim=NULL;
};

int estaVazia(Fila *fila){
	return fila->inicio==NULL && fila->fim==NULL;
};

int enqueue(Fila *fila, int valor){
	No* novo= (No*) malloc(sizeof(No));

	if(novo==NULL) return 1;

	novo->dado=valor;

	novo->proximo=NULL;

	if(estaVazia(fila))
		fila->inicio=novo;
	else
		fila->fim->proximo=novo;

	fila->fim=novo;

	return 0;
};

int dequeue(Fila *fila, int *valor){
	if(estaVazia(fila)){
		printf("A fila esta vazia, nada a remover!\n\n");
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
		printf("A fila esta vazia!\n\n");
		return 1;
	}

	*valor=fila->inicio->dado;

	return 0;
};

int back(Fila *fila, int *valor){
	if(estaVazia(fila)){
		printf("A fila esta vazia!\n\n");
		return 1;
	}

	*valor=fila->fim->dado;

	return 0;
};

void imprimirFila(Fila *fila){
	No* atual=fila->inicio;

	printf("Inicio\n");

	while(atual!=NULL){
		printf("%d -> ",atual->dado);
		atual=atual->proximo;
	}

	printf("NULL\n\n");
};

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

int main(){
	Fila fila;

	int opcao,valor;

	inicializar(&fila);

	//TO DO: MENU
	do{
		printf("=== MENU ===\n"
				"1 - Inserir na fila\n"
				"2 - Remover da fila\n"
				"3 - Primeiro da fila\n"
				"4 - Ultimo da fila\n"
				"5 - Esta vazia?\n"
				"6 - Exibir fila\n"
				"7 - Contar elementos\n"
				"0 - Sair\n");
		scanf("%d",&opcao);
		switch(opcao){
			case 0:
				break;
			case 1:
				printf("Digite o valor a ser inserido\n");
				scanf("%d",&valor);
				enqueue(&fila, valor);
				printf("Inserido %d na fila\n\n",valor);
				break;
			case 2:
				dequeue(&fila, &valor);
				printf("Removido %d do inicio da fila\n\n",valor);
				break;
			case 3:
				front(&fila, &valor);
				printf("Inicio: %d\n\n",valor);
				break;
			case 4:
				front(&fila, &valor);
				printf("Final: %d\n\n",valor);	
				break;
			case 5:
				printf("A fila %s vazia\n\n",estaVazia(&fila) ? "esta" : "nao esta");
				break;
			case 6:
				imprimirFila(&fila);
				break;
			case 7:
				valor=contarElementos(&fila);
				printf("A fila tem %d elementos\n\n",valor);
				break;
		}
	}while(opcao!=0);
	
	printf("A fila foi liberada da memoria!\n\n");
	
	liberarFila(&fila);

	return 0;
}
