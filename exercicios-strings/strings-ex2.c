#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
	char str1[20], str2[100], espaco[]=" ";
	
	printf("Informe o seu nome: ");
	scanf("%s[^\n]", str1);
	
	printf("Informe o seu sobrenome: ");
	scanf("%s[^\n]", str2);
	
	printf("\nOla, %s!", strcat(str1,strcat(espaco, str2)));
	
	return 0;
}