#include <stdio.h>
#include <stdlib.h>

#define MAX 3

typedef struct{
    char nome[50];
    int idade;
    char cpf[20];
    char rg[20];
    char telefone[20];
}Pessoa;

void preenche(Pessoa* p){
    printf("Digite o nome: ");
    scanf(" %[^\n]",p->nome);

    printf("Digite o idade: ");
    scanf(" %d",&p->idade);

    printf("Digite o CPF: ");
    scanf(" %[^\n]",p->cpf);

    printf("Digite o RG: ");
    scanf(" %[^\n]",p->rg);

    printf("Digite o Telefone: ");
    scanf(" %[^\n]",p->telefone);
}

void imprime(Pessoa* p){
    printf("Nome:\t\t%s\n",p->nome);
    printf("Idade:\t\t%d\n",p->idade);
    printf("CPF:\t\t%s\n",p->cpf);
    printf("RG:\t\t%s\n",p->rg);
    printf("Telefone:\t%s\n",p->telefone);
}

int main(){
    Pessoa* p = (Pessoa*) malloc(MAX*sizeof(Pessoa));
    
    if(p == NULL){
        printf("Erro ao alocar memooria!");
        exit(1);
    }

    for(int i=0;i<MAX;i++){
        preenche(&p[i]);
        printf("-----------------------------\n");
    }

    //realloc

    p = (Pessoa*) realloc(p, 5*sizeof(Pessoa));

    for(int i=3;i<MAX;i++){
        preenche(&p[i]);
        printf("-----------------------------\n");
    }

    printf("========== Pessoas ==========\n");
    for(int i=0;i<MAX;i++){
        imprime(&p[i]);
        printf("-----------------------------\n");
    }

    return 0;
}