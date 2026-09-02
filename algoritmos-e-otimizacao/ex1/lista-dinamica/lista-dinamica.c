#include <stdio.h>
#include <stdlib.h>

#include "lista-dinamica.h"

typedef struct elemento {
    int dado;
    struct elemento *proximo;
} Elemento;

struct lista {
    Elemento *primeiro;
    Elemento *ultimo;
    int quantidade;
};

Lista *inicializar_lista(void) {
    Lista *lista = malloc(sizeof(*lista));

    if (lista != NULL) {
        lista->primeiro = NULL;
        lista->ultimo = NULL;
        lista->quantidade = 0;
    }

    return lista;
}

void liberar_lista(Lista *lista) {
    if (lista == NULL)
        return;

    while (lista->primeiro != NULL) {
        Elemento *removido = lista->primeiro;
        lista->primeiro = removido->proximo;
        free(removido);
    }

    free(lista);
}

int inserir_inicio(Lista *lista, int elemento) {
    if (lista == NULL)
        return 0;

    Elemento *novo = malloc(sizeof(*novo));
    if (novo == NULL)
        return 0;

    novo->dado = elemento;
    novo->proximo = lista->primeiro;
    lista->primeiro = novo;

    if (lista->ultimo == NULL)
        lista->ultimo = novo;

    lista->quantidade++;
    return 1;
}

int inserir_fim(Lista *lista, int elemento) {
    if (lista == NULL)
        return 0;

    Elemento *novo = malloc(sizeof(*novo));
    if (novo == NULL)
        return 0;

    novo->dado = elemento;
    novo->proximo = NULL;

    if (lista->ultimo == NULL)
        lista->primeiro = novo;
    else
        lista->ultimo->proximo = novo;

    lista->ultimo = novo;
    lista->quantidade++;
    return 1;
}

int consultar_posicao(const Lista *lista, int posicao, int *elemento) {
    if (lista == NULL || elemento == NULL || posicao < 0 || posicao >= lista->quantidade)
        return 0;

    const Elemento *atual = lista->primeiro;
    for (int i = 0; i < posicao; i++)
        atual = atual->proximo;

    *elemento = atual->dado;
    return 1;
}

int lista_vazia(const Lista *lista) {
    return lista == NULL || lista->quantidade == 0;
}

int tamanho_lista(const Lista *lista) {
    return lista == NULL ? 0 : lista->quantidade;
}

void imprimir_lista(const Lista *lista) {
    if (lista == NULL)
        return;

    for (const Elemento *atual = lista->primeiro; atual != NULL; atual = atual->proximo)
        printf("%d ", atual->dado);
    printf("\n");
}
