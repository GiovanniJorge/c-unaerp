#ifndef LISTA_SEQUENCIAL_H
#define LISTA_SEQUENCIAL_H

#define CAPACIDADE_MAXIMA 100000

typedef struct lista Lista;

Lista *inicializar_lista(void);
void liberar_lista(Lista *lista);

int inserir_inicio(Lista *lista, int elemento);
int inserir_fim(Lista *lista, int elemento);
int consultar_posicao(const Lista *lista, int posicao, int *elemento);

int lista_vazia(const Lista *lista);
int lista_cheia(const Lista *lista);
int tamanho_lista(const Lista *lista);
void imprimir_lista(const Lista *lista);

#endif
