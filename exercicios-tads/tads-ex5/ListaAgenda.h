/* --- Estruturas de Dados --- */

// Estrutura para armazenar o dia e mês de aniversário
typedef struct {
    int dia;
    int mes;
} Data;

// Estrutura com os dados do contato (conforme requisitos do exercício)
typedef struct {
    char nome[41];         // Máximo 40 caracteres + \0
    char telefone[16];     // Máximo 15 caracteres + \0
    char celular[16];      // Máximo 15 caracteres + \0
    char email[41];        // Máximo 40 caracteres + \0
    Data dataAniversario;  // Estrutura Data aninhada
} Contato;

/* O 'typedef' abaixo define 'Elemento' como o nó da lista.
   'Lista' é definido como um ponteiro para ponteiro de Elemento (Elemento**),
   atendendo ao padrão de nó descritor/ponteiro sentinela.
*/
typedef struct elemento Elemento;
typedef Elemento* Lista;

/* --- Funções de Gerenciamento de Memória --- */

// Cria uma nova agenda (aloca o ponteiro para o primeiro elemento e define como NULL)
Lista* cria_agenda();

// Libera toda a memória alocada dinamicamente pela lista e seus nós
void libera_agenda(Lista* li);

/* --- Funções de Inserção --- */

// Insere um contato mantendo a lista em ordem alfabética pelo nome
int insere_contato(Lista* li, Contato c);

/* --- Funções de Remoção --- */

// Remove um contato específico buscando pelo nome
int remove_contato(Lista* li, char* nome);

// Percorre a lista removendo contatos que possuem nomes idênticos
void remove_duplicados(Lista* li);

/* --- Funções de Consulta e Edição --- */

// Exibe na tela todos os dados de todos os contatos da agenda
void lista_contatos(Lista* li);

// Busca um contato pelo nome. Retorna o endereço do nó ou NULL se não encontrar
Elemento* busca_contato(Lista* li, char* nome);

// Localiza um contato pelo nome e permite alterar seus dados (exceto o nome)
int atualiza_contato(Lista* li, char* nome);

/* --- Funções Auxiliares --- */

// Verifica se a lista está vazia (retorna 1 se vazia, 0 caso contrário)
int lista_vazia(Lista* li);