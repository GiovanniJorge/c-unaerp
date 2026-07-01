#include <stdio.h>
#include <stdlib.h>
#include "ListaSequencial.h"

struct lista {
    int qtd;
    struct numeros dados[MAX];
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
        printf("Numero %2d: %2d\n", i+1, li->dados[i].n);
    }
}

int insere_elem(Lista* li, struct numeros nu){
    if (li == NULL)
      return 0;

    if (li->qtd == MAX)
      return 0;

    li->dados[li->qtd] = nu;
    li->qtd++;
    return 1;
}

int remove_elem(Lista *li, int num){
    if (li == NULL)
        return 0;

    if (li->qtd == 0)
        return 0;

    int i = 0;

    while (i < li->qtd && li->dados[i].n != num)
        i++;

    if (i == li->qtd)
        return 0;

    for (int k = i; k < li->qtd - 1; k++)
        li->dados[k] = li->dados[k+1];

    li->qtd--;
    return 1;
}