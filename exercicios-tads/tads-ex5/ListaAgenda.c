#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaAgenda.h"

// --- Estruturas de Dados ---

struct elemento {
    Contato info;
    struct elemento *prox;
};

typedef struct elemento Elemento;
typedef Elemento* Lista; // A lista é um ponteiro para o primeiro elemento

// --- Implementação das Funções ---

// Cria uma nova lista retornando NULL
Lista* cria_agenda() {
    Lista* li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL)
        *li = NULL;
    return li;
}

// Insere mantendo a ordem alfabética
int insere_contato(Lista* li, Contato c) {
    if(li == NULL) return 0;
    Elemento *no = (Elemento*) malloc(sizeof(Elemento));
    if(no == NULL) return 0;

    no->info = c;
    
    // Caso 1: Lista vazia ou novo nome vem antes do primeiro
    if((*li) == NULL || strcmp((*li)->info.nome, c.nome) > 0) {
        no->prox = *li;
        *li = no;
    } else {
        // Caso 2: Buscar a posição correta no meio ou fim
        Elemento *ant = *li;
        Elemento *atual = (*li)->prox;
        while(atual != NULL && strcmp(atual->info.nome, c.nome) < 0) {
            ant = atual;
            atual = atual->prox;
        }
        no->prox = atual;
        ant->prox = no;
    }
    return 1;
}

// Exibe todos os contatos
void lista_contatos(Lista* li) {
    if(li == NULL || *li == NULL) {
        printf("\nAgenda vazia.\n");
        return;
    }
    Elemento* no = *li;
    printf("\n--- LISTA DE CONTATOS ---\n");
    while(no != NULL) {
        printf("Nome: %s\n", no->info.nome);
        printf("Tel: %s | Cel: %s\n", no->info.telefone, no->info.celular);
        printf("Email: %s\n", no->info.email);
        printf("Aniversario: %02d/%02d\n", no->info.dataAniversario.dia, no->info.dataAniversario.mes);
        printf("--------------------------\n");
        no = no->prox;
    }
}

// Busca por nome e retorna o endereço do elemento
Elemento* busca_contato(Lista* li, char* nome) {
    if(li == NULL || *li == NULL) return NULL;
    Elemento* no = *li;
    while(no != NULL && strcmp(no->info.nome, nome) != 0) {
        no = no->prox;
    }
    return no; // Retorna o ponteiro ou NULL se não achar
}

// Remove um contato específico
int remove_contato(Lista* li, char* nome) {
    if(li == NULL || *li == NULL) return 0;
    
    Elemento *ant, *no = *li;
    
    // Verifica se o contato existe usando a busca (apenas para validar conforme pedido)
    if(busca_contato(li, nome) == NULL) {
        printf("Erro: Contato '%s' nao encontrado.\n", nome);
        return 0;
    }

    // Lógica de remoção física
    if(strcmp(no->info.nome, nome) == 0) { // Remover o primeiro
        *li = no->prox;
        free(no);
        return 1;
    }

    while(no != NULL && strcmp(no->info.nome, nome) != 0) {
        ant = no;
        no = no->prox;
    }

    ant->prox = no->prox;
    free(no);
    return 1;
}

// Atualiza dados de um contato
int atualiza_contato(Lista* li, char* nome) {
    Elemento* no = busca_contato(li, nome);
    if(no == NULL) {
        printf("Erro: Contato '%s' nao encontrado.\n", nome);
        return 0;
    }

    printf("Novos dados para %s:\n", nome);
    printf("Novo Telefone: "); scanf("%s", no->info.telefone);
    printf("Novo Celular: "); scanf("%s", no->info.celular);
    printf("Novo Email: "); scanf("%s", no->info.email);
    printf("Novo Dia Nasc: "); scanf("%d", &no->info.dataAniversario.dia);
    printf("Novo Mes Nasc: "); scanf("%d", &no->info.dataAniversario.mes);
    
    return 1;
}

// Remove duplicados (mesmo nome)
void remove_duplicados(Lista* li) {
    if(li == NULL || *li == NULL) return;
    Elemento *atual = *li;
    
    while(atual != NULL && atual->prox != NULL) {
        if(strcmp(atual->info.nome, atual->prox->info.nome) == 0) {
            Elemento* duplicado = atual->prox;
            atual->prox = duplicado->prox;
            free(duplicado);
            // Não avança o 'atual' para checar se o próximo também é duplicado
        } else {
            atual = atual->prox;
        }
    }
}

// Libera toda a memória
void libera_agenda(Lista* li) {
    if(li != NULL) {
        Elemento* no;
        while((*li) != NULL) {
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}