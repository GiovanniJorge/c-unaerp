/*Nível Desafiador - Exercício 6*/

#include<stdio.h>
#include<stdlib.h>

int fatorial_rec(int n);
int fatorial_iter(int n);

int main() {
	int n;
	printf("Informe o numero para o fatorial: ");
	scanf("%i", &n);
	int resultado_rec = fatorial_rec(n);
	// 0.021s
	printf("\nResultado usando recursao: %i\n", resultado_rec);
	int resultado_iter = fatorial_iter(n);
	// 0.018s
	printf("Resultado usando laco: %i", resultado_iter);
	
	return 0;
}

int fatorial_rec(int n) {
	if(n==1) {
		return 1;
	}
	else {
		return n*fatorial_rec(n-1);
	}
}

int fatorial_iter(int n) {
	int fatorial = n;
	for(int i=1;i<n;i++) {
		fatorial = fatorial*i;
	}
	return fatorial;
}

/*A versão mais eficiente foi a que utilizou o laço, uma vez que é mais explícita e foi capaz de executar o código de maneira mais rápida
(0.018 segundos). Apesar do uso da recursão ter tornado o código mais conciso, ele apresentou um tempo maior de execução (0.021 segundos)
e se mostrou mais complexo de codificar*/