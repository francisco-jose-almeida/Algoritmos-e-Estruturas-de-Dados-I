/*
Faca um programa que recebe nomes de frutas e seu preco. A quantidade frutas deve informada pelo usuario. Utilize alocação dinamica, espcialmente a função realloc para não desperdiçar memoria.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char nome[50];
	float preco;
}Fruta;

int main(){
	
	//Recebe quantidade de frutas
	int quantidade_frutas;

	printf("Informe a quantidade de frutas:\n>>");
	scanf("%d",&quantidade_frutas);
	
	Fruta* frutas = (Fruta*) malloc(quantidade_frutas*sizeof(Fruta)); 

	if(frutas == NULL){
		printf("Erro ao alocar memoria!");
		exit(0);
	}

	for(int i=0;i<quantidade_frutas;i++){
		//Recebe nome de fruta
		printf("Informe o nome da %dª fruta:\n>>",i+1);
		scanf(" %49[^\n]",frutas[i].nome);

		//Recebe preço de fruta
		printf("Informe o preco da %dª fruta:\n>>",i+1);
		scanf("%f",&frutas[i].preco);
	}
	
	printf("==Lista de Frutas adicionadas==\nQuantidade: %d\n",quantidade_frutas);

	for(int i=0;i<quantidade_frutas;i++){
		printf("%d \t %s \t R$%.2f\n",i+1,frutas[i].nome,frutas[i].preco);
	}

	free(frutas);

	return 0;
}
