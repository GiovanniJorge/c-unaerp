/*Soma*/

#include<stdio.h>
#include<stdlib.h>

int soma(int a, int b);

int main() {
	int a, b;
	printf("Informe os numeros a serem somados:\nNumero 1: ");
	scanf("%i", &a);
	printf("Numero 2: ");
	scanf("%i", &b);
	int resultado = soma(a, b);
	printf("Resultado: %i", resultado);
	
	return 0;
}

int soma(int a, int b) {
	int soma = a + b;
	return soma;
}