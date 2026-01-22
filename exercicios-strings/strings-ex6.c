#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
	char frase[100];
	
	printf("Informe a sua frase: ");
	scanf("%[^\n]", frase);
	
	printf("\n");
	for(int i=strlen(frase);i>=0;i--) {
		printf("%c", frase[i]);
	}
	printf("\n");
	
	return 0;
}