#define MAX 10

struct numeros {
    int n;
};

typedef struct lista Lista;

Lista* inicializar_lista();
void libera_lista(Lista* li);
int lista_cheia(Lista* li);
int lista_vazia(Lista* li);
void imprime_lista(Lista* li);
int insere_elem(Lista* li, struct numeros nu);
int remove_elem(Lista* li, int num);