#include <stdio.h>
#include <stdlib.h>

#include "listas.h"

int menu(){	
	int opcao;	

	printf("\n");

	printf("=========== Menu ===========\n"
			" 0 \t Sair\n"
			" 1 \t Inserir no inicio\n"
			" 2 \t Inserir no final\n"
			" 3 \t Inserir em posicao\n"
			" 4 \t Remover do inicio\n"
			" 5 \t Remover do final\n"
			" 6 \t Remover valor\n"
			" 7 \t Buscar valor\n"
			" 8 \t Imprimir direto\n"
			" 9 \t Imprimir inverso\n"
			"10 \t Contar elementos\n"
			"----------------------------\n"
			">>");
	scanf("%d",&opcao);

	printf("\n");

	return opcao;
}

void executar(Lista *lista,int opcao){

	int valor,posicao;

	switch(opcao){
		case 0:
			break;
		case 1:
			printf("Digite o valor a ser inserido\n");
			scanf("%d",&valor);
			inserirInicio(lista,valor);
			break;
		case 2:
			printf("Digite o valor a ser inserido\n");
			scanf("%d",&valor);
			inserirFinal(lista,valor);
			break;
		case 3:
			printf("Digite a posicao a ser inserido\n");
			scanf("%d",&posicao);
			printf("Digite o valor a ser inserido\n");
			scanf("%d",&valor);
			inserirPosicao(lista,valor,posicao);
			break;
		case 4:
			removerInicio(lista);
			break;
		case 5:
			removerFinal(lista);
			break;
		case 6:
			printf("Digite o valor a ser removido\n");
			scanf("%d",&valor);
			removerValor(lista,valor);
			break;
		case 7:
			printf("Digite o valor a ser buscado\n");
			scanf("%d",&valor);
			buscar(lista,valor);
			break;
		case 8:
			imprimirDireto(lista);
			break;
		case 9:
			imprimirInverso(lista);
			break;
		case 10:
			contarElementos(lista);
			break;
		default:
			printf("Opcao Invalida!\n");
			break;
	}

}

int main(){
	Lista lista;

	int opcao=20;

	inicializar(&lista);

	while(opcao!=0){

		opcao=menu();

		executar(&lista,opcao);
	}

	liberarLista(&lista);

	return 0;
}
