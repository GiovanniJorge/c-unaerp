#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
	char palavra1[20], palavra2[20];
	
	printf("Informe a primeira palavra: ");
	scanf("%s[^/n]", palavra1);
	printf("Informe a segunda palavra: ");
	scanf("%s[^/n]", palavra2);
	int resultado=strcmp(palavra1, palavra2);
	if(resultado==-1)
		printf("\nPalavra que vem primeiro em ordem alfabetica: %s\n", palavra1);
	else if(resultado==1)
		printf("\nPalavra que vem primeiro em ordem alfabetica: %s\n", palavra2);
	else
		printf("\nAs palavras sao iguais\n");
		
	return 0;
}