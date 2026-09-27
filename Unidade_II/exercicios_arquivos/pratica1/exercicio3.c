#include <stdio.h>
#include <stdlib.h>

typedef struct{
	char nome[32];
	float preco;
}Fruta;

int cadastrarFruta(FILE* arquivo, Fruta** lista, int* quantidade){
	
	(*quantidade)++;

	Fruta* temp=realloc(*lista,(*quantidade)*sizeof(Fruta));

	if(temp==NULL){ printf("Erro ao alocar memoria\n");return 1;}
	*lista=temp;

	printf("Informe o nome da fruta:\n>>");
	scanf(" %[^\n]",(*lista)[(*quantidade)-1].nome);
	fprintf(arquivo,"nome: %s,",(*lista)[(*quantidade)-1].nome);
	printf("Informe o preco da fruta:\n>>");
	scanf(" %f",&(*lista)[(*quantidade)-1].preco);
	fprintf(arquivo,"preco: R$%.2f\n",(*lista)[(*quantidade)-1].preco);

	return 0;
};

int main(){
	
	int resposta=1;

	int quantidade_frutas=0;

	FILE* arq=fopen("frutas.txt","w");

	if(arq==NULL) {printf("Erro ao abrir arquivo!\n");return 1;}

	Fruta* frutas=(Fruta*) malloc(quantidade_frutas*sizeof(Fruta));

	while(resposta!=0){

		if(cadastrarFruta(arq,&frutas,&quantidade_frutas)){
			printf("Erro na coleta de dados!\n");
			return 1;
		};

		printf("Deseja inserir mais uma fruta?\n1 - Sim\n0 - Nao(Sair)\n(1,0)>>");
		scanf(" %d",&resposta);
	}

	fclose(arq);
	free(frutas);

	return 0;
}
