/*Nível Fácil - Exercício 2*/

#include<stdio.h>
#include<stdlib.h>

int maximo(int x, int y);

int main() {
	int x, y;
	printf("Informe os numeros a serem comparados:\nNumero 1: ");
	scanf("%i", &x);
	printf("Numero 2: ");
	scanf("%i", &y);
	int resultado = maximo(x, y);
	printf("Resultado: %i", resultado);
	
	return 0;
}

int maximo(int x, int y) {
	int maximo;
	if(x>y) {
		maximo = x;
	}
	else {
		maximo = y;
	}
}