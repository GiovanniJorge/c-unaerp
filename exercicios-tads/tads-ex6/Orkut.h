// Nó da lista de amigos de um usuário
struct elemento_amigo {
    int id_amigo;
    struct elemento_amigo *prox;
};
typedef struct elemento_amigo NoAmigo;

// Estrutura do Usuário (cada um tem sua própria lista de amigos)
struct elemento_usuario {
    int id_usuario;
    NoAmigo *lista_amigos; // Ponteiro para a lista encadeada de amigos
    struct elemento_usuario *prox;
};
typedef struct elemento_usuario NoUsuario;

// O TipoOrkut é um ponteiro para o primeiro usuário da rede
typedef NoUsuario* TipoOrkut;

// Protótipos
TipoOrkut* cria_orkut();
NoUsuario* busca_usuario(TipoOrkut* pOrkut, int id);
void Relaciona(int Amigo1, int Amigo2, TipoOrkut* pOrkut);
