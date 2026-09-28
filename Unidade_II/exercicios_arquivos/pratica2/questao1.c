#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int matricula;
	char nome[64];
	float nota_final;
}Aluno;

int receberAlunos(Aluno* lista, int quantidade){
	
	Aluno* temp=(Aluno*) malloc(sizeof(Aluno));

	if(temp==NULL) return 1;

	for(int i=0;i<quantidade;i++){
		printf("Informe a matricula do aluno %d\n>>",i+1);
		scanf("%d",&lista[i].matricula);

		printf("Informe o nome do aluno %d\n>>", i+1);
		scanf(" %[^\n]",lista[i].nome);

		printf("Informe a nota final do aluno %d\n>>",i+1);

		scanf(" %f",&lista[i].nota_final);

		printf("---------------------\n");
	}

	free(temp);
	return 0;
}

int salvarAlunosArquivo(FILE* fd, Aluno* lista,int quantidade){

	for(int i=0;i<quantidade;i++){
		fprintf(fd,"%d \t %s \t %.1f\n",lista[i].matricula, lista[i].nome, lista[i].nota_final);

	}
	return 0;
}

int lerArquivoAlunos(FILE* fd){
	
	int matricula;
	char nome[64];
	float nota_final;

	while(fscanf(fd, "%d %s %f",&matricula,nome,&nota_final)!=EOF){
		printf("%d \t %s \t %.1f \n",matricula,nome,nota_final);
	}
	return 0;
};

int main(){

	int quantidade_alunos=5;

	FILE* arq=fopen("alunos.txt","w");

	if(arq==NULL) return 1;

	Aluno* alunos=(Aluno*) malloc(quantidade_alunos*sizeof(Aluno));

	if(alunos==NULL) return 1;

	receberAlunos(alunos, quantidade_alunos);
	
	salvarAlunosArquivo(arq,alunos,quantidade_alunos);

	fclose(arq);

	arq=fopen("alunos.txt","r");

	lerArquivoAlunos(arq);

	return 0;
}
