#include <stdio.h>
#include <stdlib.h>

#include "fila.h"

typedef struct Tarefa{
	int id;
	char descricao[128];
}Tarefa;

void imprimirTarefas(Fila *fila){
	No* atual=fila->inicio;

	Tarefa* dado;

	printf("Lista de Tarefas\n"
			"ID\tDescricao\n");
	
	while(atual!=NULL){
		
		dado=(Tarefa*)atual->dado;

		printf("%d \t %s \n",dado->id,dado->descricao);
		atual=atual->proximo;
	}

	printf("\n\n");
}

int erro(int error_code){
	switch(error_code){
		case 0:
			break;
		case 1:
			printf("ERRO: Fila vazia! (%d)\n\n",error_code);
			break;
		case 2:
			printf("Erro ao alocar memoria! (%d)\n\n",error_code);
			break;
		default:
			printf("Codigo de erro desconhecido! (%d)\n\n", error_code);
			break;
	};
	return error_code;
}

int menu(){

	int opcao;

	printf(
			"Gerenciador de Tarefas\n"
			"----------------------\n"
			"1\tAdcionar Processo\n"
			"2\tFinalizar Tarefa Atual\n"
			"3\tConsultar Proxima tarefa\n"
			"4\tVer Lista Completa\n"
			"0\tSair\n>>");

	scanf("%d",&opcao);

	return opcao;

}

int executar(Fila *fila, int opcao){
	Tarefa* valor= malloc(sizeof(Tarefa));
	
	if(valor==NULL) return 2;

	switch(opcao){
		case 0:
			break;
		case 1:{
			Tarefa* novo= malloc(sizeof(Tarefa));

			if(novo==NULL) return 2;

			printf("Informe o identificador da Tarefa:");
			scanf("%d",&novo->id);

			printf("Informe uma breve descricao da Tarefa:\n");
			scanf(" %[^\n]",novo->descricao);

			if(!erro(enqueue(fila,novo)))
				printf("\nTarefa Adcionada ao final da fila\n\n");
			break;
		}
		case 2:
			if(!erro(dequeue(fila,&valor))){
				printf("Tarefa id:%d Finalizada\n\n",valor->id);
				free(valor);
			}
			break;
		case 3:
			if(!erro(front(fila,&valor)))
				printf("Proxima Tarefa:\n"
						"ID\tDescricao\n"
						"%d\t%s\n\n",valor->id,valor->descricao);
			break;
		case 4:
			imprimirTarefas(fila);
			break;
		default:
			printf("Opcao Invalida!(%d)\n\n",opcao);
			break;
	}
	return 0;
}

int main(){
	Fila fila;

	int opcao;

	inicializar(&fila);

	do{
		opcao=menu();

		printf("\n");

		erro(executar(&fila, opcao));
	}while(opcao);

	liberarFila(&fila);

	printf("Fila Liberada da Memoria\n");

	return 0;
}
