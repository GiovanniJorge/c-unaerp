#include <stdio.h>
#include <stdlib.h>
#include "Orkut.h"

TipoOrkut* cria_orkut() {
    TipoOrkut* li = (TipoOrkut*) malloc(sizeof(TipoOrkut));
    if(li != NULL) *li = NULL;
    return li;
}

// Função auxiliar para buscar se um usuário já existe na rede
NoUsuario* busca_usuario(TipoOrkut* pOrkut, int id) {
    if(pOrkut == NULL || *pOrkut == NULL) return NULL;
    NoUsuario* atual = *pOrkut;
    while(atual != NULL) {
        if(atual->id_usuario == id) return atual;
        atual = atual->prox;
    }
    return NULL;
}

// Função auxiliar para inserir um usuário novo na rede
NoUsuario* insere_usuario_rede(TipoOrkut* pOrkut, int id) {
    NoUsuario* novo = (NoUsuario*) malloc(sizeof(NoUsuario));
    novo->id_usuario = id;
    novo->lista_amigos = NULL;
    novo->prox = *pOrkut; // Insere no início da lista de usuários
    *pOrkut = novo;
    return novo;
}

// Função auxiliar para inserir ID na lista de amigos de alguém
void insere_na_lista_amigos(NoUsuario* user, int id_amigo) {
    NoAmigo* novo = (NoAmigo*) malloc(sizeof(NoAmigo));
    novo->id_amigo = id_amigo;
    novo->prox = user->lista_amigos;
    user->lista_amigos = novo;
}

// Procedimento Principal solicitado
void Relaciona(int Amigo1, int Amigo2, TipoOrkut* pOrkut) {
    if(pOrkut == NULL) return;

    // 1. Localiza o Amigo1 (garantido pelo enunciado que existe)
    NoUsuario* user1 = busca_usuario(pOrkut, Amigo1);
    
    // 2. Verifica se o Amigo2 já existe. Se não, cadastra-o.
    NoUsuario* user2 = busca_usuario(pOrkut, Amigo2);
    if(user2 == NULL) {
        user2 = insere_usuario_rede(pOrkut, Amigo2);
    }

    // 3. Adiciona o Amigo2 na lista do Amigo1
    insere_na_lista_amigos(user1, Amigo2);

    // 4. Adiciona o Amigo1 na lista do Amigo2 (Relação de amizade é mútua)
    insere_na_lista_amigos(user2, Amigo1);
    
    printf("Relacao entre %d e %d estabelecida!\n", Amigo1, Amigo2);
}