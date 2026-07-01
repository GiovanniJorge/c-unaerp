#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaSequencial.h"

struct lista {
    int qtd;
    struct strings dados[MAX];
};

Lista* inicializar_lista(){
    Lista *li = (Lista*) malloc(sizeof(struct lista));

    if (li != NULL)
        li->qtd = 0;

    return li;
}

void libera_lista(Lista* li){
    free(li);
}

int lista_cheia(Lista* li){
    if (li == NULL)
      return -1;

    return (li->qtd == MAX);
}

int lista_vazia(Lista* li){
    if (li == NULL)
      return -1;

    return (li->qtd == 0);
}

void imprime_lista(Lista* li){
    if (li == NULL)
      return;

    for (int i = 0; i < li->qtd; i++){
        printf("Bebida %2d: %12s | ", i+1, li->dados[i].nome);
        printf("Volume: %4d | ", li->dados[i].volume);
        printf("Preco: %5.2f\n", li->dados[i].preco);
    }
}

int insere_bebida(Lista* li, struct strings st){
    if (li == NULL)
      return 0;

    if (li->qtd == MAX)
      return 0;

    li->dados[li->qtd] = st;
    li->qtd++;
    return 1;
}

int remove_bebida(Lista *li, char *str){
    if (li == NULL)
        return 0;

    if (li->qtd == 0)
        return 0;

    int i = 0;

    while (i < li->qtd && (strcmp(li->dados[i].nome, str) != 0))
        i++;

    if (i == li->qtd)
        return 0;

    for (int k = i; k < li->qtd - 1; k++)
        li->dados[k] = li->dados[k+1];

    li->qtd--;
    return 1;
}