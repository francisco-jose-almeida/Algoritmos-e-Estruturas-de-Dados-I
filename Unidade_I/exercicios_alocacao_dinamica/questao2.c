#include <stdio.h>
#include <stdlib.h>

int main(){
    int tamanho = 3;

    //Alocando espaco para cada linha da matriz
    int** matriz = (int **) malloc(tamanho*sizeof(int*));
   
    //Alocando espaco para cada coluna da matriz
    for (int i=0;i<tamanho;i++){
        matriz[i] = (int *) malloc(tamanho*sizeof(int));
    }

    //Verificando exito da alocacao
    if(matriz==NULL){
        printf("Erro ao alocar memoria!\n");
    }
    else{
        printf("Matriz alocada\n");

    }

    //Preenchendo e imprimindo matriz
    for (int i=0;i<tamanho;i++){
        for (int j=0;j<tamanho;j++){

            matriz[i][j] = 3*i + j;
            
            printf("%d ", matriz[i][j]);
        }
        
        printf("\n");
    }

    //Liberando espaco previamente alocado
    for (int i=0;i<tamanho;i++){
        free(matriz[i]);
    }

    free(matriz);
}
