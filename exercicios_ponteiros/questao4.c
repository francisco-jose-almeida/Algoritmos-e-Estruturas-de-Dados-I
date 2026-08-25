#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void calcula_hexagono(float l, float* area, float* perimetro){
	
	(*area) = 3*pow(l,2)*sqrt(3)/2;
	
	(*perimetro) = 6*l;
	
	return;
}

int main(){

	float lado, resultado_area, resultado_perimetro;

	printf("Informe o comprimento do lado (l)\n>>");
	scanf("%f", &lado);

	calcula_hexagono(lado,&resultado_area,&resultado_perimetro);

	printf("As Area e Perimetro de um hexgono de lado %.2f sao:\nArea: %.2f\nPerimetro: %.2f\n",lado,resultado_area,resultado_perimetro);

	return 0;
}
