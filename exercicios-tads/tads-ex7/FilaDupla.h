struct aluno {
    int matricula;
    char nome[30];
    float n1, n2, n3;
};

typedef struct filaDupla FilaDupla;

FilaDupla* cria_FilaDupla();
void libera_FilaDupla(FilaDupla* fi);
int insere_FilaDupla(FilaDupla* fi, struct aluno al);
int remove_FilaDupla(FilaDupla* fi);
int consulta_FilaDupla(FilaDupla* fi, struct aluno *al);
int tamanho_FilaDupla(FilaDupla* fi);
int FilaDupla_vazia(FilaDupla* fi);
void imprime_FilaDupla(FilaDupla* fi);