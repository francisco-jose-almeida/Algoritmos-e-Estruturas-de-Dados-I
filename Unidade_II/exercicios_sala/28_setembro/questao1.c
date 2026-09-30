#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int matricula;
	char nome[64];
	char curso[64];
	float media;
}Aluno;

int cadastrarAluno(Aluno** lista,int* quantidade){
	
	(*quantidade)++;

	Aluno* temp=(Aluno*)realloc((*lista),(*quantidade)*sizeof(Aluno));

	if(temp==NULL) return 1;

	printf("Informe a matricula do aluno\n>>");
	scanf(" %d",&temp->matricula);
	
	printf("Informe o nome do aluno\n>>");
	scanf(" %[^\n]",temp->nome);
	
	printf("Informe o curso do aluno\n>>");
	scanf(" %[^\n]",temp->curso);
	
	printf("Informe a media do aluno\n>>");
	scanf(" %f",&temp->media);

	(*lista)=temp;
	return 0;
}
int listarAlunos(Aluno* lista, int quantidade){

	printf("Matricula\tNome\tCurso\tMedia\n");
	for(int i=0;i<quantidade;i++){
		printf("%d\t%s\t%s\t%.2f\n",lista[i].matricula,lista[i].nome,lista[i].curso,lista[i].media);
	}

	return 0;
}
int buscarAluno(Aluno* lista,int quantidade){
	
	int matricula;

	printf("Informe a matricula do aluno\n>>");
	scanf(" %d",&matricula);

	for(int i=0;i<quantidade;i++){
		if(lista[i].matricula==matricula){
			return i;
		}
	}

	return -1;
}
int alterarMedia(Aluno** lista, int quantidade){
	
	int index=buscarAluno(lista,quantidade);
	Aluno* temp=lista[index];

	if(temp==NULL) return 1;

	printf("Informe a nova media do aluno\nMedia atual: %.2f\n",temp->media);
	scanf(" %f",&temp->media);

	lista[index]=temp;

	return 0;
}

int main(){

	int quantidade_alunos=0;
	printf("Informe a quantidade de alunos:\n>>");
	scanf("%d",&quantidade_alunos);

	Aluno* alunos=(Aluno*)malloc(quantidade_alunos*sizeof(Aluno));

	if(alunos==NULL)return 1;

	FILE* alunos_fd=fopen("alunos.dat","wb");

	if(alunos_fd==NULL) return 1;

	cadastrarAluno(&alunos,&quantidade_alunos);
	listarAlunos(alunos,quantidade_alunos);
	buscarAluno(alunos,quantidade_alunos);
	alterarMedia(&alunos,quantidade_alunos);

	fwrite(alunos,sizeof(Aluno),quantidade_alunos,alunos_fd);

	fclose(alunos_fd);

	return 0;
}
