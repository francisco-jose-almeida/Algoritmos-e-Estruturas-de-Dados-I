#include <stdio.h>
#include <stdlib.h>

int main(){
    
    //Abrindo arquivo
    FILE* arq;
    arq = fopen("arquivo.txt","r");
    if(arq==NULL){
        printf("ERRO: Impossivel criar o arquivo\n");
        exit(1);
    }
    else{
        printf("Arquivo Criado com Sucesso!\n");
    }

    /*
    //Escrevendo Caracter
    fputc('C',arq);

    //Escrevendo Strings
    fputs("Hello, World!\n", arq);

    //Escrevendo Strings Formatadas
    fprintf(arq,"Hello World!\n");
    */
    
    //Leitura de dados no arquivo
    
    //Lendo o primeiro character
    //int c=fgetc(arq);
    //printf("%c\n",c);

    
    char linha[256];
    /*
    //Lendo a primeira linha
    fgets(linha,sizeof(linha),arq);
    printf("%s",linha);
    
    fscanf(arq,"%s",linha);
    printf("%s\n",linha);
    */
    
    //Lendo ate o final do arquivo(EOF)
    while(!feof(arq)){
        fscanf(arq," %s",linha);
        printf("%s",linha);
    }

    //Fechando o arquivo
    fclose(arq);
    
    


    return 0;
}