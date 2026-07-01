#define MAX 10

struct strings {
    char nome[20];
    int volume;
    float preco;
};

typedef struct lista Lista;

Lista* inicializar_lista();
void libera_lista(Lista* li);
int lista_cheia(Lista* li);
int lista_vazia(Lista* li);
void imprime_lista(Lista* li);
int insere_bebida(Lista* li, struct strings st);
int remove_bebida(Lista* li, char *str);