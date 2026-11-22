#include <stdio.h>
#include <stdlib.h>

#include "fila.h"

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

	printf("\n");

	return opcao;
}
void executar(Fila *fila,int opcao){	
	
	int* valor=malloc(sizeof(int));

	switch(opcao){
			case 0:
				break;
			case 1:
				printf("Digite o valor a ser inserido\n");
				scanf("%d",&valor);
				if(!erro(enqueue(fila, valor)))
					printf("Inserido %d na fila\n\n",valor);
				break;
			case 2:
				if(!erro(dequeue(fila, &valor)))
					printf("Removido %d do inicio da fila\n\n",valor);
				break;
			case 3:
				if(!erro(front(fila, &valor)))
					printf("Inicio: %d\n\n",valor);
				break;
			case 4:
				if(!erro(back(fila, &valor)))
					printf("Final: %d\n\n",valor);	
				break;
			case 5:
				printf("A fila %s vazia\n\n",estaVazia(fila) ? "esta" : "nao esta");
				break;
			case 6:
				imprimirFila(fila);
				break;
			case 7:
				valor=contarElementos(fila);
				printf("A fila tem %d elementos\n\n",valor);
				break;
			default:
				printf("Opcao Invalida! (%d)\n\n",opcao);
				break;
		}
}
 
int main(){
	Fila fila;

	int opcao;

	inicializar(&fila);

	//TO DO: MENU
	do{
		opcao=menu();

		executar(&fila,opcao);

	}while(opcao);
	
	liberarFila(&fila);

	printf("A fila foi liberada da memoria!\n\n");
	
	return 0;
}
