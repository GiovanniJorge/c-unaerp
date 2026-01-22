#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
	char frase[100], caractere;
	
	printf("Digite a sua frase: ");
	scanf("%[^\n]", frase);
	printf("Digite o seu caractere: ");
	scanf(" %c", &caractere);
	
	char *posicao = strchr(frase, caractere);
	
	if(posicao != NULL) {
		int indice = posicao - frase;
		printf("\nO caractere '%c' aparece pela primeira vez na posicao %d\n", caractere, indice);
	}
	else {
		printf("\nO caractere %c nao foi encontrado na frase\n", caractere);
	}
	
	return 0;
}