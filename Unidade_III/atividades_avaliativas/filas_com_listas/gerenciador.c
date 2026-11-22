#include <stdio.h>
#include <stdlib.h>

#include "fila.h"
#include "tarefas.h"


//Funcao de tratamento de codigos de erro
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

//Mostra o menu na tela e recebe escolha do usuario
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

//Executa opcao escolhida pelo usuario
int executar(Tarefas *tarefas, int opcao){
	int valor;
	
	switch(opcao){
		case 0:
			break;
		case 1:
			char* texto=malloc(SIZE_DESC*sizeof(char));
			
			printf("Informe o identificador da Tarefa:\n");
			scanf(" %d",&valor);

			printf("Informe uma breve descricao da Tarefa:\n");
			scanf(" %[^\n]",texto);

			if(!erro(addTarefa(tarefas, valor, texto)))
				printf("\nTarefa Adcionada \n"
						"ID\tDescricao\n"
						"%d\t%s\n\n",valor,texto);	
			break;
		case 2:
			if(!erro(execProxima(tarefas,&valor,&texto))){
				printf("Tarefa Executada\n"
						"ID\tDescricao\n"
						"%d\t%s\n\n",valor,texto);
			}
			break;
		case 3:
			if(!erro(consultProxima(tarefas,&valor,&texto)))
				printf("Proxima Tarefa:\n"
						"ID\tDescricao\n"
						"%d\t%s\n\n",valor,texto);
			break;
		case 4:
			listarTarefas(tarefas);
			break;
		default:
			printf("Opcao Invalida!(%d)\n\n",opcao);
			break;
	}
	return 0;
}

int main(){

	Tarefas tarefas;

	int opcao;

	//Incializando fila
	inicializarTarefas(&tarefas);

	do{
		//Funcao menu retorna opcao escolhida pelo usuario
		opcao=menu();

		printf("\n");
	
		//Funcao executa opcao escolhida e pode retornar codigo de erro
		erro(executar(&tarefas, opcao));
	
	}while(opcao);

	liberarTarefas(&tarefas);

	printf("Fila Liberada da Memoria\n");

	return 0;
}
