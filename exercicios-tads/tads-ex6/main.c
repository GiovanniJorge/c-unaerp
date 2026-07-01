#include <stdio.h>
#include <stdlib.h>
#include "Orkut.h"

int main() {
    TipoOrkut* meuOrkut = cria_orkut();

    // Simulando que o Amigo 100 já está cadastrado (conforme enunciado)
    // No mundo real, haveria uma função de cadastro inicial.
    NoUsuario* inicial = (NoUsuario*) malloc(sizeof(NoUsuario));
    inicial->id_usuario = 100;
    inicial->lista_amigos = NULL;
    inicial->prox = NULL;
    *meuOrkut = inicial;

    // Testando o procedimento: Relacionar 100 com 200 (200 não existe ainda)
    Relaciona(100, 200, meuOrkut);
    
    // Testando o procedimento: Relacionar 100 com 300 (300 não existe ainda)
    Relaciona(100, 300, meuOrkut);

    // Verificando se o 100 tem os amigos 200 e 300
    NoUsuario* busca = busca_usuario(meuOrkut, 100);
    if(busca != NULL) {
        printf("Amigos do ID 100: ");
        NoAmigo* aux = busca->lista_amigos;
        while(aux != NULL) {
            printf("%d ", aux->id_amigo);
            aux = aux->prox;
        }
    }

    return 0;
}