#define MAX 10

struct strings {
    char s[20];
};

typedef struct lista Lista;

Lista* inicializar_lista();
void libera_lista(Lista* li);
int lista_cheia(Lista* li);
int lista_vazia(Lista* li);
void imprime_lista(Lista* li);
int insere_elem(Lista* li, struct strings st);
int remove_elem(Lista* li, char *str);