#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "lista-sequencial.h"

/* Altere somente esta lista para escolher os valores de N. */
static const int VALORES_N[] = {1000, 2000, 3000, 4000, 5000,
                                6000, 7000, 8000, 9000, 10000};
#define QUANTIDADE_N (sizeof(VALORES_N) / sizeof(VALORES_N[0]))
#define ELEMENTO_TESTE 42
#define ARQUIVO_RESULTADOS "resultados.csv"

static double medir_insercao_inicio(int n) {
    Lista *lista = inicializar_lista();
    clock_t inicio = clock();
    for (int i = 0; i < n; i++)
        inserir_inicio(lista, ELEMENTO_TESTE);
    clock_t fim = clock();
    liberar_lista(lista);
    return (double)(fim - inicio) / CLOCKS_PER_SEC;
}

static double medir_insercao_fim(int n) {
    Lista *lista = inicializar_lista();
    clock_t inicio = clock();
    for (int i = 0; i < n; i++)
        inserir_fim(lista, ELEMENTO_TESTE);
    clock_t fim = clock();
    liberar_lista(lista);
    return (double)(fim - inicio) / CLOCKS_PER_SEC;
}

static double medir_consulta(int n) {
    Lista *lista = inicializar_lista();
    int *posicoes = malloc((size_t)n * sizeof(*posicoes));
    int resultado = 0;
    volatile int acumulador = 0;

    if (lista == NULL || posicoes == NULL) {
        liberar_lista(lista);
        free(posicoes);
        return -1.0;
    }

    for (int i = 0; i < n; i++)
        inserir_fim(lista, ELEMENTO_TESTE);
    for (int i = 0; i < n; i++)
        posicoes[i] = rand() % n;

    clock_t inicio = clock();
    for (int i = 0; i < n; i++)
        consultar_posicao(lista, posicoes[i], &resultado);
        acumulador += resultado;
    clock_t fim = clock();

    liberar_lista(lista);
    free(posicoes);
    return (double)(fim - inicio) / CLOCKS_PER_SEC;
}

int main(void) {
    FILE *arquivo = fopen(ARQUIVO_RESULTADOS, "w");
    if (arquivo == NULL)
        return 1;

    srand(42);
    printf("   N   | insercao_inicio | insercao_fim | consulta\n");

    for (size_t i = 0; i < QUANTIDADE_N; i++) {
        int n = VALORES_N[i];
        double inicio = medir_insercao_inicio(n);
        double fim = medir_insercao_fim(n);
        double consulta = medir_consulta(n);
        printf("%6d |%11.4f      |%10.4f    |%8.4f\n", n, inicio, fim, consulta);
    }

    fclose(arquivo);
    return 0;
}
