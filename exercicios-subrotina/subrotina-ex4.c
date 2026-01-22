/*Nível Médio - Exercício 4*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int conta_pares(int v[], int n);

int main() {
	srand(time(NULL));
	int n;
	printf("Informe a quantidade de numeros a serem comparados: ");
	scanf("%i", &n);
	int v[n];
	for (int i=0;i<n;i++) {
		v[i] = rand() % 100;
		printf("Numero %i: %i\n", i+1, v[i]);
	}
	int resultado = conta_pares(v, n);
	printf("Resultado: %i", resultado);
	
	return 0;
}

int conta_pares(int v[], int n) {
	int pares = 0;
	for (int i=0;i<n;i++) {
		if(v[i]%2 == 0) {
			pares += 1;
		}
	}
	return pares;
}