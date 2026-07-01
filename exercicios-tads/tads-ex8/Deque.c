#include <stdio.h>
#include <stdlib.h>
#include "Deque.h"

struct elemento {
    struct aluno dados;
    struct elemento *ant;
    struct elemento *prox;
};
typedef struct elemento Elem;

struct deque {
    Elem *inicio;
    Elem *final;
    int qtd;
};

Deque* cria_Deque() {
    Deque* dq = (Deque*) malloc(sizeof(Deque));
    if (dq != NULL) {
        dq->inicio = NULL;
        dq->final = NULL;
        dq->qtd = 0;
    }
    return dq;
}

void libera_Deque(Deque* dq) {
    if (dq != NULL) {
        Elem* no;
        while (dq->inicio != NULL) {
            no = dq->inicio;
            dq->inicio = dq->inicio->prox;
            free(no);
        }
        free(dq);
    }
}

int insere_Inicio_Deque(Deque* dq, struct aluno al) {
    if (dq == NULL) return 0;
    Elem* no = (Elem*) malloc(sizeof(Elem));
    if (no == NULL) return 0;

    no->dados = al;
    no->ant = NULL;
    no->prox = dq->inicio;

    if (dq->inicio == NULL) {
        dq->final = no;
    } else {
        dq->inicio->ant = no;
    }
    dq->inicio = no;
    dq->qtd++;
    return 1;
}

int insere_Final_Deque(Deque* dq, struct aluno al) {
    if (dq == NULL) return 0;
    Elem* no = (Elem*) malloc(sizeof(Elem));
    if (no == NULL) return 0;

    no->dados = al;
    no->prox = NULL;
    no->ant = dq->final;

    if (dq->final == NULL) {
        dq->inicio = no;
    } else {
        dq->final->prox = no;
    }
    dq->final = no;
    dq->qtd++;
    return 1;
}

int remove_Inicio_Deque(Deque* dq) {
    if (dq == NULL || dq->inicio == NULL) return 0;
    Elem* no = dq->inicio;

    dq->inicio = dq->inicio->prox;

    if (dq->inicio == NULL) {
        dq->final = NULL;
    } else {
        dq->inicio->ant = NULL;
    }

    free(no);
    dq->qtd--;
    return 1;
}

int remove_Final_Deque(Deque* dq) {
    if (dq == NULL || dq->final == NULL) return 0;
    Elem* no = dq->final;

    dq->final = dq->final->ant;

    if (dq->final == NULL) {
        dq->inicio = NULL;
    } else {
        dq->final->prox = NULL;
    }

    free(no);
    dq->qtd--;
    return 1;
}

int consulta_Inicio_Deque(Deque* dq, struct aluno *al) {
    if (dq == NULL || dq->inicio == NULL) return 0;
    *al = dq->inicio->dados;
    return 1;
}

int consulta_Final_Deque(Deque* dq, struct aluno *al) {
    if (dq == NULL || dq->final == NULL) return 0;
    *al = dq->final->dados;
    return 1;
}

int tamanho_Deque(Deque* dq) {
    if (dq == NULL) return 0;
    return dq->qtd;
}

int Deque_vazia(Deque* dq) {
    if (dq == NULL || dq->inicio == NULL) return 1;
    return 0;
}

void imprime_Deque(Deque* dq) {
    if (dq == NULL) return;
    Elem* no = dq->inicio;
    while (no != NULL) {
        printf("Matricula: %d | Nome: %s\n", no->dados.matricula, no->dados.nome);
        no = no->prox;
    }
    printf("-------------------------------\n");
}