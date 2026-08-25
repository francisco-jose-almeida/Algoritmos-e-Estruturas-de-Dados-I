#include <stdio.h>
#include <stdlib.h>

int main(){
    int i, tamanho = 10;
    int* vetor=(int *) malloc(tamanho*sizeof(int));

    if(vetor == NULL){
        printf("Erro na alocacao!\n");
        exit(1);
    }
    else{
        printf("Vetor alocado!\n");
    }

    for(i=0;i<tamanho;i++){
        vetor[i] = i;
        printf("%d ",vetor[i]);
    }

    free(vetor);
    return 0;
}