#include <stdio.h>
#include <stdlib.h>

#include "fila.h"
#include "tarefas.h"

void inicializarTarefas(Tarefas *tarefas){

	tarefas->fila=malloc(sizeof(Fila));

	inicializar(tarefas->fila);

	tarefas->inicio=0;
	tarefas->fim=0;
}

int addTarefa(Tarefas *tarefas, int id, char *texto){
	
	int erro= enqueue(tarefas->fila,id);
	
	if(!erro){
		tarefas->descricoes[tarefas->fim]=texto;

		tarefas->fim=(tarefas->fim+1)%MAX_SIZE;
	}
	return erro;
}

int execProxima(Tarefas *tarefas, int *id, char **texto){

	int erro = dequeue(tarefas->fila,id);
	if(!erro){
		*texto=tarefas->descricoes[tarefas->inicio];

		tarefas->inicio=(tarefas->inicio+1)%MAX_SIZE;
	}
	return erro;
}

int consultProxima(Tarefas *tarefas, int *id, char **texto){
	int erro= front(tarefas->fila,id);
	if(!erro)
		*texto=tarefas->descricoes[tarefas->inicio];
	return erro;
}

void listarTarefas(Tarefas *tarefas){
	No *atual=tarefas->fila->inicio;
	int contador=tarefas->inicio;

	printf("Lista de Tarefas\n"
			"id\tdescricao\n");

	while(atual!=NULL){
		printf("%d\t%s\n",atual->dado,tarefas->descricoes[contador]);

		atual=atual->proximo;
		contador=(contador+1)%MAX_SIZE;
	}

	printf("\n\n");
}

void liberarTarefas(Tarefas *tarefas){
	liberarFila(tarefas->fila);

	free(tarefas->fila);

	tarefas=NULL;
}
