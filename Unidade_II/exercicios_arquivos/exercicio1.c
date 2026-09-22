//1. Faca um programa em C que solicita ao usuario informacoes de funcionarios via teclado. As informacoes digitadas pelo o usuario sao: id, nome e salario do funcionario. Armazene as informacoes digitadas pelo usuario em um arquivo texto.

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int id;
    char nome[50];
    float salario;
}Funcionario;

int main(){

    FILE* arq=fopen("funcionarios.txt","a");

    Funcionario* f;

    if(arq==NULL){
        printf("ERRO: Impossivel criar o arquivo!");
        return 1;
    }

    printf("Informe o id do funcionario\n>>");
    scanf("%d",&(f->id));
    printf("Informe o nome do funcionario\n>>");
    scanf("%[49^\n]",f->nome);
    printf("Informe o salario do funcionario\n>>");
    scanf("%f",&(f->salario));

    fprintf(arq,"== Informacoes ==\n"
        "id: %d\n"
        "nome: %s"
        "salario:R$ %.2f\n",f->id,f->nome,f->salario);

    printf("== Informacoes ==\n"
        "id: %d\n"
        "nome: %s"
        "salario:R$ %.2f\n",f->id,f->nome,f->salario);

    fclose(arq);

    return 0;
}