#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
	char frase[100];
	int quantidade=0;
	
	printf("Informe a sua frase: ");
	scanf("%[^\n]", frase);
	
	for(int i=0;i<strlen(frase);i++) {
		if (frase[i] == ' ') {
			quantidade++;
		}
	}
	
	printf("\nA quantidade de espacos na frase informada foi: %d\n", quantidade);
	
	return 0;
}