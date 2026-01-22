/*Nível Difícil - Exercício 8*/

#include<stdio.h>
#include<stdlib.h>

int eh_primo(int n);
void lista_primos(int inicio, int fim);

int main() {
	int n, inicio, fim;
	printf("Informe o valor de n: ");
	scanf("%i", &n);
	int resultado = eh_primo(n);
	if (resultado == 0) {
		printf("Resultado: Numero primo");
	}
	else {
		printf("Resultado: Numero nao primo");
	}
	
	printf("\n\nInforme o valor do inicio: ");
	scanf("%i", &inicio);
	printf("Informe o valor do fim: ");
	scanf("%i", &fim);
	printf("\nNumeros primos no intervalo:");
	lista_primos(inicio, fim);
	
	return 0;
}

int eh_primo(int n) {
	int primo = 0;
	for (int i=2;i<n;i++) {
		if (n%i == 0) {	
			primo = 1;
		}
	}
	if (n == 1) {
		primo = 1;
	}
	return primo;
}

void lista_primos(int inicio, int fim) {
	int primo;
	for (inicio;inicio<=fim;inicio++) {
		primo = 0;
		for (int i=2;i<inicio;i++) {
	 		if (inicio%i == 0) {
	 			primo = 1;
			}
		}
		if (inicio == 1) {
			primo = 1;
		}
		if (primo == 0) {
			printf("\n%i", inicio);
		}	
	}	    
}   
  
		 