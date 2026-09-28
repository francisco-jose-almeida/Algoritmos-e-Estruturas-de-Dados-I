#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int chars;
	int words;
	int lines;
	int letter_a;
}FileInfo;

void lerArquivo(FILE* fd, FileInfo* infos_ptr){
	
	int letter;
	int chars=0;
	int words=0;
	int lines=0;
	int letter_a=0;
	
	while(!feof(fd)){
		letter=fgetc(fd);
		chars++;
		if(letter==' ' || letter=='\t') words++;
		else if(letter=='\n') lines++;
		else if(letter=='a' || letter=='A') letter_a++;
	}

	infos_ptr->chars=chars;
	infos_ptr->words=words;
	infos_ptr->lines=lines;
	infos_ptr->letter_a=letter_a;
}

int main(){

	FILE* arq= fopen("texto.txt","r");

	if(arq==NULL) return 1;

	FileInfo infos;

	lerArquivo(arq,&infos);

	printf("Caracteres: %d \nPalavras: %d \nLinhas: %d \nOcorrencias de A: %d\n",infos.chars,infos.words,infos.lines,infos.letter_a);

	fclose(arq);

	return 0;
}
