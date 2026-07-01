#include <stdio.h>
#include <stdlib.h>
#include "FilaDupla.h"

struct elemento {
    struct aluno dados;
    struct elemento *ant;
    struct elemento *prox;
};
typedef struct elemento Elem;

struct filaDupla {
    Elem *inicio;
    Elem *final;
    int qtd;
};

FilaDupla* cria_FilaDupla() {
    FilaDupla* fi = (FilaDupla*) malloc(sizeof(FilaDupla));
    if (fi != NULL) {
        fi->inicio = NULL;
        fi->final = NULL;
        fi->qtd = 0;
    }
    return fi;
}

void libera_FilaDupla(FilaDupla* fi) {
    if (fi != NULL) {
        Elem* no;
        while (fi->inicio != NULL) {
            no = fi->inicio;
            fi->inicio = fi->inicio->prox;
            free(no);
        }
        free(fi);
    }
}

int insere_FilaDupla(FilaDupla* fi, struct aluno al) {
    if (fi == NULL) return 0;
    Elem* no = (Elem*) malloc(sizeof(Elem));
    if (no == NULL) return 0;

    no->dados = al;
    no->prox = NULL;

    if (fi->final == NULL) {
        no->ant = NULL;
        fi->inicio = no;
    } else {
        no->ant = fi->final;
        fi->final->prox = no;
    }
    fi->final = no;
    fi->qtd++;
    return 1;
}

int remove_FilaDupla(FilaDupla* fi) {
    if (fi == NULL || fi->inicio == NULL) return 0;
    Elem* no = fi->inicio;

    fi->inicio = fi->inicio->prox;

    if (fi->inicio == NULL)
        fi->final = NULL;
    else
        fi->inicio->ant = NULL;

    free(no);
    fi->qtd--;
    return 1;
}

int consulta_FilaDupla(FilaDupla* fi, struct aluno *al) {
    if (fi == NULL || fi->inicio == NULL) return 0;
    *al = fi->inicio->dados;
    return 1;
}

int tamanho_FilaDupla(FilaDupla* fi) {
    if (fi == NULL) return 0;
    return fi->qtd;
}

int FilaDupla_vazia(FilaDupla* fi) {
    if (fi == NULL || fi->inicio == NULL) return 1;
    return 0;
}

void imprime_FilaDupla(FilaDupla* fi) {
    if (fi == NULL) return;
    Elem* no = fi->inicio;
    while (no != NULL) {
        printf("Matricula: %d\n", no->dados.matricula);
        printf("Nome: %s\n", no->dados.nome);
        printf("Notas: %f %f %f\n", no->dados.n1, no->dados.n2, no->dados.n3);
        printf("-------------------------------\n");
        no = no->prox;
    }
}