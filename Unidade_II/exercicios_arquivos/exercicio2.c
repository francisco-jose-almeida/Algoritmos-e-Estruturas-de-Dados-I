#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nome[50];
    float nota;
}Aluno;

int main(){
   
    int quantidade_alunos=0;


    FILE* arq=fopen("alunos.txt","a");
    
    if(arq==NULL){
        printf("ERRO: Impossivel criar o arquivo!");
        return 1;
    }

    printf("Informe a quantidade de alunos:\n>>");
    scanf("%d",&quantidade_alunos);

    Aluno* alunos=(Aluno*) malloc(quantidade_alunos*sizeof(Aluno));

    if(alunos==NULL){
        printf("Erro ao alocar memoria!");
        return 1;
    }

    for(int i=0;i<quantidade_alunos;i++){
        fprintf(arq,"-------------------\n");
        printf("-------------------\n");
        

        printf("Informe o nome do aluno:\n>>");
        scanf(" %s",alunos[i].nome);
        fprintf(arq,"nome: %s\n",alunos[i].nome);

        printf("Informe a nota do aluno:\n>>");
        scanf("%f",&alunos[i].nota);
        fprintf(arq,"nota: %.2f\n",alunos[i].nota);


    }

    return 0;
}