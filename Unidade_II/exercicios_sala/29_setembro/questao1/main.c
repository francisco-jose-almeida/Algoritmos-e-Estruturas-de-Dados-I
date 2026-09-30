#include <stdio.h>
#include "calculadora.h"

int main(){

	int v1,v2;

	printf("Digite dois valores inteiros: ");
	scanf("%d %d",&v1,&v2);

	int soma_v = soma(v1,v2);
	printf("A soma: %d\n",soma_v);

	return 0;
}
