#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
	char str[100];
	
	printf("Dgite sua frase: ");
	scanf("%[^\n]", str);
	
	printf("\nFrase: %s\n", str);
	printf("Tamanho da string: %d\n", strlen(str));
	
	return 0;
}               