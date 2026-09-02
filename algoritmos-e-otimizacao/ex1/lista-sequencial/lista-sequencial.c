#include <stdio.h>
#include <stdlib.h>

#include "lista-sequencial.h"

struct lista {
    int dados[CAPACIDADE_MAXIMA];
    int quantidade;
};

Lista *inicializar_lista(void) {
    Lista *lista = malloc(sizeof(*lista));

    if (lista != NULL)
        lista->quantidade = 0;

    return lista;
}

void liberar_lista(Lista *lista) {
    free(lista);
}

int lista_vazia(const Lista *lista) {
    return lista == NULL || lista->quantidade == 0;
}

int lista_cheia(const Lista *lista) {
    return lista != NULL && lista->quantidade == CAPACIDADE_MAXIMA;
}

int inserir_inicio(Lista *lista, int elemento) {
    if (lista == NULL || lista_cheia(lista))
        return 0;

    for (int i = lista->quantidade; i > 0; i--)
        lista->dados[i] = lista->dados[i - 1];

    lista->dados[0] = elemento;
    lista->quantidade++;
    return 1;
}

int inserir_fim(Lista *lista, int elemento) {
    if (lista == NULL || lista_cheia(lista))
        return 0;

    lista->dados[lista->quantidade] = elemento;
    lista->quantidade++;
    return 1;
}

int consultar_posicao(const Lista *lista, int posicao, int *elemento) {
    if (lista == NULL || elemento == NULL || posicao < 0 || posicao >= lista->quantidade)
        return 0;

    *elemento = lista->dados[posicao];
    return 1;
}

int tamanho_lista(const Lista *lista) {
    return lista == NULL ? 0 : lista->quantidade;
}

void imprimir_lista(const Lista *lista) {
    if (lista == NULL)
        return;

    for (int i = 0; i < lista->quantidade; i++)
        printf("%d ", lista->dados[i]);
    printf("\n");
}
