#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
	char frase_normal[100], frase_invertida[100];
	int j=0;
	
	printf("Informe a sua frase: ");
	scanf("%[^\n]", frase_normal);
	
	int tamanho = strlen(frase_normal);
	for(int i=tamanho-1;i>=0;i--) {
		frase_invertida[j++] = frase_normal[i];
	}
	
	if (strcmp(frase_normal, frase_invertida) == 0) {
		printf("\nA frase e um palindromo\n");
	}
	else {
		printf("\nA frase nao e um palindromo\n");
	}
	
	return 0;
}