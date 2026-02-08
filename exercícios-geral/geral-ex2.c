#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main() {
int numero = 0;
char nome[3][50];
int votos[3] = {0, 0, 0};
int vencedor = 0;

for(int i = 0; i < 3; i++) {
printf("Informe o nome do candidato %i: ", numero += 1);
scanf("%s", &nome[i]);

printf("Informe o numero de votos: ");
scanf("%i", &votos[i]);

printf("\n");
}

for(int i = 0; i < 3; i++) {
if (votos[i] > votos[vencedor]) {
vencedor = i;
}
}

printf("Resultado: O candidato vencedor da eleicao foi: %s\n\n", nome[vencedor]);

return 0;
}