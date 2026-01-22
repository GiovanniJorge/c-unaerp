/*Nível Médio - Exercício 5*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void invert(int v[], int n);

int main() {
	srand(time(NULL));
	int n;
	printf("Informe a quantidade de valores a serem invertidos: ");
	scanf("%i", &n);
	int v[n];
	printf("\nVetor Original:\n");
	for (int i=0;i<n;i++) {
		v[i] = rand() % 100;
		printf("V[%i]: %i\n", i+1, v[i]);
	}
	invert(v, n);
	
	return 0;
}
	
void invert(int v[], int n) {
	for (int i=0;i<n/2;i++) {
		int aux = v[i];
		v[i] = v[n-i-1];
		v[n-i-1] = aux;
	}
	printf("\nVetor Invertido:");
	for (int i=0;i<n;i++) {
		printf("\nV[%i]: %i", i+1, v[i]);
	}
}