#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int codigo;
	char nome[32];
	int qtd;
	float preco;
}Produto;

int lerProdutosArquivo(FILE* fd,Produto** lista,int* quantidade){
	
	char linha[128];

	int codigo;
	char nome[32];
	int qtd;
	float preco;

	Produto* temp=NULL;
	
	Produto* lista_atual=*lista;


	while(fgets(linha,sizeof(linha),fd)!=NULL){
		(*quantidade)++;

		temp=(Produto*)realloc(lista_atual,(*quantidade)*sizeof(Produto));
		if( temp == NULL) return 1;

		lista_atual=temp;

		codigo=atoi(strtok(linha," \t"));
		strcpy(nome,strtok(NULL," \t"));
		qtd=atoi(strtok(NULL," \t"));
		preco=atof(strtok(NULL," \t"));

		nome[sizeof(nome)-1]='\0';

		temp[(*quantidade)-1].codigo=codigo;
		strcpy(temp[(*quantidade)-1].nome,nome);
		temp[(*quantidade)-1].qtd=qtd;
		temp[(*quantidade)-1].preco=preco;

	}

	*lista=temp;

	return 0;
};

int listarProdutos(Produto* lista,int quantidade){
	
	for(int i=0;i<quantidade;i++){
		printf("Codigo\tNome\tQtd\tPreco\n");
		printf("%d\t%s\t%d\t%.2f\n\n",lista[i].codigo,lista[i].nome,lista[i].qtd,lista[i].preco);
	}

	return 0;
}
int consultarProduto(Produto* lista, int quantidade){

	int codigo;

	printf("Informe o codigo do produto\n");
	scanf("%d",&codigo);

	for(int i=0;i<quantidade;i++){
		if(lista[i].codigo==codigo){
			printf("Codigo\tNome\tQtd\tPreco\n");
			printf("%d\t%s\t%d\t%.2f\n\n",lista[i].codigo,lista[i].nome,lista[i].qtd,lista[i].preco);
			break;
		}
	}

	return 0;
}
int alterarQuantidade(Produto** lista, int quantidade){

	int codigo;
	int qtd;

	printf("Informe o codigo do produto\n");
	scanf("%d",&codigo);

	for(int i=0;i<quantidade;i++){
		if((*lista)[i].codigo==codigo){
			printf("Quantidade atual: %d\n",(*lista)[i].qtd);
			printf("Informe a nova quantidade:\n>>");
			scanf("%d",&qtd);
			(*lista)[i].qtd=qtd;
			printf("Nova quantidade: %d\n",(*lista)[i].qtd);
			break;
		}
	}

	return 0;
}
int calcularValorEstoque(Produto* lista, int quantidade){

	float soma=0;
	for(int i=0;i<quantidade;i++){
		soma+=lista[i].qtd*lista[i].preco;
	}
	printf("O valor total do estoque e de R$%.2f\n",soma);

	return 0;
}
int salvarArquivo(FILE* fd,Produto* lista,int quantidade){
	
	for(int i=0;i<quantidade;i++){
		fprintf(fd,"%d\t%s\t%d\t%.2f\n",lista[i].codigo,lista[i].nome,lista[i].qtd,lista[i].preco);
	}

	return 0;
}


int main(){

	int resposta;

	int quantidade_produtos=0;

	FILE* produtos_fd=fopen("produtos.txt","r");
	
	if(produtos_fd==NULL) return 1;

	Produto* produtos=(Produto*)malloc(quantidade_produtos*sizeof(Produto));

	//Recuperar dados do arquivo
	lerProdutosArquivo(produtos_fd,&produtos,&quantidade_produtos);

	//Mostrar Menu
	
	do{
		printf(
			"==== Controle de Estoque ====\n"
			"==== O que deseja fazer? ====\n"
			"1 - Listar Produtos\n"
			"2 - Consultar produto\n"
			"3 - Alterar quantidade\n"
			"4 - Calcular valor total do estoque\n"
			"5 - Sair\n"
			"============================\n(1,2,3,4,5)>>");
		scanf("%d",&resposta);
		switch(resposta){
			case 1:
				listarProdutos(produtos,quantidade_produtos);
				break;
			case 2:
				consultarProduto(produtos, quantidade_produtos);
				break;
			case 3:
				alterarQuantidade(&produtos,quantidade_produtos);
				fclose(produtos_fd);
				produtos_fd=fopen("produtos.txt","w");

				salvarArquivo(produtos_fd,produtos,quantidade_produtos);

				fclose(produtos_fd);
				produtos_fd=fopen("produtos.txt","r");

				break;
			case 4:
				calcularValorEstoque(produtos,quantidade_produtos);
				break;
			case 5:
				break;
			default:
				printf("Resposta Invalida!\n");
				break;
		}
	}while(resposta!=5);

	fclose(produtos_fd);
	free(produtos);

	return 0;
}
