#include <stdio.h>
#include <stdlib.h>
#include "DequeDinamico.h"

typedef struct elemento {
    struct aluno dados;
    struct elemento *anterior;
    struct elemento *proximo;
} No;

struct Deque {
    No *inicio;
    No *final;
    int qtd;
};

Deque* cria_Deque() {
    Deque *dq = (Deque*) malloc(sizeof(Deque));
    if (dq != NULL) {
        dq->inicio = NULL;
        dq->final = NULL;
        dq->qtd = 0;
    }
    return dq;
}

void libera_Deque(Deque* dq) {
    if (dq != NULL) {
        No* no;
        while (dq->inicio != NULL) {
            no = dq->inicio;
            dq->inicio = dq->inicio->proximo;
            free(no);
        }
        free(dq);
    }
}

int tamanho_Deque(Deque* dq) {
    if (dq == NULL) 
        return -1;
    return dq->qtd;
}

int Deque_cheia(Deque* dq) {
    if (dq == NULL) 
        return -1;
    if (dq->qtd == MAX)
        return 1;
    return 0;
}

int Deque_vazia(Deque* dq) {
    if (dq == NULL) 
        return -1;
    if (dq->qtd == 0)
        return 1;
    return 0;
}

int consultaInicio_Deque(Deque* dq, struct aluno *al) {
    if (dq == NULL || dq->qtd == 0) 
        return 0;
    *al = dq->inicio->dados;
    return 1;
}

int consultaFinal_Deque(Deque* dq, struct aluno *al) {
    if (dq == NULL || dq->qtd == 0) 
        return 0;
    *al = dq->final->dados;
    return 1;
}

int insereFinal_Deque(Deque* dq, struct aluno al) {
    if (dq == NULL || dq->qtd == MAX) 
        return 0;

    No* novo = (No*) malloc(sizeof(No));
    if (novo == NULL) 
        return 0;

    novo->dados = al;
    novo->proximo = NULL;
    novo->anterior = dq->final;

    if (dq->final == NULL) {
        dq->inicio = novo;
    } else {
        dq->final->proximo = novo;
    }

    dq->final = novo;
    dq->qtd++;
    return 1;
}

int insereInicio_Deque(Deque* dq, struct aluno al) {
    if (dq == NULL || dq->qtd == MAX) 
        return 0;

    No* novo = (No*) malloc(sizeof(No));
    if (novo == NULL) 
        return 0;

    novo->dados = al;
    novo->anterior = NULL;
    novo->proximo = dq->inicio;

    if (dq->inicio == NULL) {
        dq->final = novo;
    } else {
        dq->inicio->anterior = novo;
    }

    dq->inicio = novo;
    dq->qtd++;
    return 1;
}

int removeInicio_Deque(Deque* dq) {
    if (dq == NULL || dq->qtd == 0) 
        return 0;

    No* no = dq->inicio;
    dq->inicio = dq->inicio->proximo;

    if (dq->inicio == NULL) {
        dq->final = NULL;
    } else {
        dq->inicio->anterior = NULL;
    }

    free(no);
    dq->qtd--;
    return 1;
}

int removeFinal_Deque(Deque* dq) {
    if (dq == NULL || dq->qtd == 0) 
        return 0;

    No* no = dq->final;
    dq->final = dq->final->anterior;

    if (dq->final == NULL) {
        dq->inicio = NULL;
    } else {
        dq->final->proximo = NULL;
    }

    free(no);
    dq->qtd--;
    return 1;
}

void imprime_Deque(Deque* dq) {
    if (dq == NULL) 
        return;
    
    No* atual = dq->inicio;
    while (atual != NULL) {
        printf("-------------------------------\n");
        printf("Matricula: %d\n", atual->dados.matricula);
        printf("Nome: %s\n", atual->dados.nome);
        printf("Notas: %f %f %f\n", atual->dados.n1, atual->dados.n2, atual->dados.n3);
        atual = atual->proximo;
    }
}