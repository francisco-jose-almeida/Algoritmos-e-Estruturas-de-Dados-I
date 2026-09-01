//Crie um tipo estruturado para armkazenar dados de um funcionario. Uma estrutura deste tipo possui os seguintes campos: nome, salario, identificador ecargo
//xa) Escreva uma função que receba como parametro o endereco de uma estrutura do tipo Funcionario e preencha seus campos com valores fornecidos pelo usuarioo via teclado
//xb) Escreva uma função que receba como parametro o endereco de uma estrutura do tipo Funcionario e imprima os valores dos seus campos
//xc) Implemente uma funcao para realizar uma alteracao no salario de uma estrutaura do tipo funcionario
//xd) Escreva uma função que receba como parametro um vetor de estruturas do tipo Funcionario e imprima o cargo e o salario do Funcionario com maior salario e o cargo em salario do funcionario com o menor salario

#include <stdio.h>
#include <stdlib.h>
//#include <string.h>

typedef struct {
    char nome[50];
    float salario;
    int identificador;
    char cargo[50];
}Funcionario;

void preencher(Funcionario* f){
    printf("Digite o Nome: ");
    scanf(" %[^\n]",f->nome);
    printf("Digite o Salario: ");
    scanf(" %f",&f->salario);
    printf("Digite o Identificador: ");
    scanf(" %d",&f->identificador);
    printf("Digite o Cargo: ");
    scanf(" %[^\n]",f->cargo);

}

void imprimir(Funcionario* f){
    printf("Nome:\t\t%s\n",f->nome);
    printf("Salario:\tR$%.2f\n",f->salario);
    printf("Identificador:\t%d\n",f->identificador);
    printf("Cargo:\t\t%s\n",f->cargo);
}

void alterarSalario(Funcionario* f,float novo_salario){

    f->salario=novo_salario;

}

void imprimirMaiorMenorFuncionario(Funcionario* f,int quantidade_funcionarios){
    Funcionario maior=f[0];
    Funcionario menor=f[0];
    for (int i=1;i<quantidade_funcionarios;i++){
        if((f[i].salario)>(maior.salario)){
            maior=f[i];
        }
        else if((f[i].salario)<(menor.salario)){
            menor=f[i];
        }
    }
    printf("======== Funcionario de Maior Salario ========\n");
    printf("Cargo: %s \tSalario: %.2f \n",maior.cargo,maior.salario);
    printf("======== Funcionario de Menor Salario ========\n");
    printf("Cargo: %s \tSalario: %.2f \n",menor.cargo,menor.salario);
}

int main(){
    //Alocacao dinamica do vetor funcionarios
    Funcionario* funcionarios = (Funcionario*) malloc(sizeof(Funcionario));
    
    char resposta_sim_nao='s';
    int resposta_identificador;
    float resposta_novo_salario;
    //quantidade de funcionarios vindo do usuario
    int quantidade=0;

    printf("Informe a quantidade de funcionarios:\n>>");
    scanf("%d",&quantidade);

    //reallocacao de memoria sabendo da quantidade de funcionarios
    funcionarios = (Funcionario*) realloc(funcionarios,quantidade*sizeof(Funcionario));

    if(funcionarios == NULL){
        printf("Erro ao alocar memoria");
        exit(1);
    }

    //preencher vetor funcionarios
    for(int i=0;i<quantidade;i++){
        preencher(funcionarios);
    }
    
    //Alterar salario de um funcionario
    
    printf("Deseja alterar algum salario?(S/n)\n>>");
    scanf(" %c",&resposta_sim_nao);
    
    while(resposta_sim_nao=='s' || resposta_sim_nao=='S'){
        printf("Informe o identificador do funcionario:\n>>");
        scanf(" %d",&resposta_identificador);
        printf("Informe o Novo Salario:\n>>");
        scanf(" %f", &resposta_novo_salario);
        for(int i=0;i<quantidade;i++){
            if(funcionarios[i].identificador==resposta_identificador){
                alterarSalario(&funcionarios[i],resposta_novo_salario);
            }
        }
        printf("Deseja alterar outro salario?(S/n)\n>>");
        scanf(" %c",&resposta_sim_nao);
    }

    resposta_sim_nao='s';
    printf("Deseja saber Maior e Menor salarios?(S/n)\n>>");
    scanf(" %c",&resposta_sim_nao);

    if(resposta_sim_nao=='s' || resposta_sim_nao=='S'){
        imprimirMaiorMenorFuncionario(&funcionarios,quantidade);
    }

    //Imprimir vetor funcionarios
    printf("============== Funcionarios ==============\n");

    for(int i=0;i<quantidade;i++){
        imprimir(funcionarios);
        printf("-------------------------------------------\n");
    }


    return 0;
}