#include <stdio.h>
#include "conversor.h"

int main(){

	float m;

	printf("Informe um comprimento em metros: ");
	scanf("%f",&m);

	printf("Convertido %.2f metros e\n"
			"%.2f centimetros\n"
			"%.2f quilometros\n"
			"%.2f milimetros\n", m, metrosCentimetros(m),metrosQuilometros(m),metrosMilimetros(m));

	return 0;
}
