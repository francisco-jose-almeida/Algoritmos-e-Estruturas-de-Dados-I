//1. Faca um programa em C que solicita ao usuario informacoes de funcionarios via teclado. As informacoes digitadas pelo o usuario sao: id, nome e salario do funcionario. Armazene as informacoes digitadas pelo usuario em um arquivo texto.

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int id;
    char nome[50];
    float salario;
}Funcionario;

void adicionarFuncionario(Funcionarios** f,int quantidade){
    quantidade++;
    
    f=(Funcionario*)realloc(f,quantidade*sizeof(Funcionario));

    printf("Informe o id do funcionario\n>>");
    scanf("%d",&f->id);
    printf("Informe o nome do funcionario\n>>");
    scanf("%[^\n]",f->nome);
    printf("Informe o salario do funcionario\n>>");
    scanf("%f",&f->salario);
    return;
}
void removerFuncionario (Funcionarios** f,int quantidade){}
void editarFuncionario  (Funcionarios** f,int quantidade){}
void mostrarFuncionario (Funcionarios** f,int quantidade){}

int main(){

    int resposta;
    int quantidade_funcionarios=0;
    FILE* arq=fopen("funcionarios.txt","a");

    if(arq==NULL){
        printf("ERRO: Impossivel criar o arquivo!");
        return 1;
    }

    Funcionario* funcionarios=(Funcionario*)malloc(quantidade_funcionarios*sizeof(Funcionario));

    if(funcionarios==NULL){
        printf("Erro ao alocar memoria!");
        return 1;
    }

    do{
        printf("== Gestao de Funcionarios ==\n"
            "O que deseja fazer:\n"
            "1 - Adicionar um funcionário\n"
            "2 - Remover um funcionario\n"
            "3 - Editar um funcionario\n"
            "4 - Exibir informações\n"
            "0 - Sair");
        scanf("%d",&resposta);
        switch(resposta){
            case 1:
                adicionarFuncionario(funcionarios,quantidade_funcionarios);
                break;
            case 2:
                removerFuncionario(funcionarios,quantidade_funcionarios);
                break;
            case 3:
                editarFuncionario(funcionarios,quantidade_funcionarios);
                break;
            case 4:
                mostrarFuncionario(funcionarios,quantidade_funcionarios);
                break;
            case 0:
                break;
            default:
                printf("Resposta Invalida!");
                break;
        } 
    }
    while(resposta!=0);

}