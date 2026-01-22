#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
	char frase[100], palavra[20];
	
	printf("Informe a sua frase: ");
	scanf("%[^\n]", frase);
	printf("Informe a sua palavra: ");
	scanf("%s", palavra);
	
	if (strstr(frase, palavra) == NULL) {
		printf("\nA palavra nao esta na frase\n");
	}
	else {
		printf("\nA palavra esta na frase\n");
	}
	
	return 0;
}