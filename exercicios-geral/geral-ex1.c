#include <stdio.h>
#include <stdlib.h>

int main() {
    // Declaração de variáveis
    int idade;
    char sexo;
    float salario;

    float soma = 0;
    int maior, menor;
    int contador = 0;
    int feminino = 0;

    // Inicialização da variável idade
    idade = 0;

    while (idade >= 0) {
        // Leitura das informações
        printf("Idade: ");
        scanf("%d", &idade);

        // Verificação para saída do loop
        if (idade < 0) {
            break;
        }

        printf("Sexo [M ou F]: ");
        scanf(" %c", &sexo);

        printf("Salario: ");
        scanf("%f", &salario);

        // Soma dos salários
        soma += salario;
        printf("Soma Salario: %.2f\n", soma);

        // Determinação da maior e menor idade
        if (contador == 0) {
            maior = idade;
            menor = idade;
        } else {
            if (idade > maior) {
                maior = idade;
            }
            if (idade < menor) {
                menor = idade;
            }
        }

        // Verificação do sexo e salário
        if ((sexo == 'F' || sexo == 'f') && salario > 2500) {
            feminino++;
        }

        // Incrementar o contador
        contador++;
    }
    // Exibir resultados
    if (contador > 0) {
    printf("\nMedia dos salarios: R$ %.2f\n", soma / contador);
    printf("Maior idade = %d\n", maior);
    printf("Menor idade = %d\n", menor);
    printf("Sexo feminino e salarios superiores a R$ 2500,00 = %d\n", feminino);
} else {
printf("Nenhum dado valido foi inserido no sistema");
}
   
    return 0;
}