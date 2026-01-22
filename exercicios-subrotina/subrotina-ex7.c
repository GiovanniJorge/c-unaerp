/*Nível Difícil - Exercício 7*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int produto_escalar(int a[], int b[], int n);

int main() {
	int n;
	printf("Informe a quantidade de valores presentes no vetor: ");
	scanf("%i", &n);
	int a[n], b[n];
	srand(time(NULL));
	printf("\nValores do vetor a:");
	for (int i=0;i<n;i++) {
		a[i] = rand() % 10;
		printf("\na[%i]: %i", i+1, a[i]);
	}
	printf("\n\nValores do vetor b:");
	for (int i=0;i<n;i++) {
		b[i] = rand() % 10;
		printf("\nb[%i]: %i", i+1, b[i]);
	}
	int resultado = produto_escalar(a, b, n);
	printf("\n\nResultado: %i", resultado);
	
	return 0;
}

int produto_escalar(int a[], int b[], int n) {
	int produto_esc;
	for (int i=0;i<n;i++) {
		produto_esc += a[i]*b[i];
	}
	return produto_esc;
}