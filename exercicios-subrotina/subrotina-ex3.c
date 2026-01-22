/*Nível Médio - Exercício 3*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

float media(float v[], int n);

int main() {
	srand(time(NULL));
	int n;
	printf("Informe a quantidade de numeros a serem utilizados na media: ");
	scanf("%i", &n);
	float v[n];
	for(int i=0;i<n;i++) {
		v[i] = (rand() % 100)*0.1;
		printf("Numero %i: %.1f\n", i+1, v[i]);
	}
	float resultado = media(v, n);
	printf("Resultado: %.2f", resultado);
	
	return 0;
}

float media(float v[], int n) {
	float media = 0;
	for(int i=0;i<n;i++) {
		media += v[i];
	}
	return media/n;
}