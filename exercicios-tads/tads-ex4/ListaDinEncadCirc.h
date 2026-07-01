// Definição da estrutura de dados que será armazenada
struct aluno{
    int matricula;
    char nome[30];
    float n1,n2,n3;
};

/* O 'typedef' abaixo esconde a implementação do nó (struct elemento).
   'Lista' é um ponteiro para um ponteiro de elemento. Isso permite que
   a função altere o valor do ponteiro externo à função.
*/
typedef struct elemento* Lista;

// --- Protótipos das funções de gerenciamento de memória ---
Lista* cria_lista();
void libera_lista(Lista* li);

// --- Protótipos das funções de consulta ---
// Retornam 1 para sucesso e 0 para falha (ou não encontrado)
int consulta_lista_pos(Lista* li, int pos, struct aluno *al);
int consulta_lista_mat(Lista* li, int mat, struct aluno *al);

// --- Protótipos das funções de inserção ---
// Em listas circulares, a inserção exige cuidado para manter o ciclo fechado
int insere_lista_final(Lista* li, struct aluno al);
int insere_lista_inicio(Lista* li, struct aluno al);
int insere_lista_ordenada(Lista* li, struct aluno al);

// --- Protótipos das funções de remoção ---
int remove_lista(Lista* li, int mat);
int remove_lista_inicio(Lista* li);
int remove_lista_final(Lista* li);

// --- Funções de estado e exibição ---
int tamanho_lista(Lista* li);
int lista_vazia(Lista* li);
void imprime_lista(Lista* li);

// --- Funções da atividade 07 ---
int busca_maior_nota(Lista *li, struct aluno *al);
int insere_lista_ordenada_nome(Lista *li, struct aluno al);
int concatena_listas(Lista *li1, Lista *li2);
Lista* filtrar_aprovados(Lista *li);
