#include <stdio.h>
#include <stdlib.h>
#include "FilaDupla.h"

int main() {
    struct aluno al, a[4] = {
        {2, "Andre",    9.5f, 7.8f, 8.5f},
        {4, "Ricardo", 7.5f, 8.7f, 6.8f},
        {1, "Bianca",   9.7f, 6.7f, 8.4f},
        {3, "Ana",      5.7f, 6.1f, 7.4f}
    };

    FilaDupla* fi = cria_FilaDupla();

    printf("Tamanho inicial: %d\n\n", tamanho_FilaDupla(fi));

    int i;
    for (i = 0; i < 4; i++) {
        insere_FilaDupla(fi, a[i]);
        if (FilaDupla_vazia(fi)) {
            printf("Erro!\n");
        }
        consulta_FilaDupla(fi, &al);
        printf("Consulta (Frente): %d \t %s\n", al.matricula, al.nome);
    }

    printf("\n--- Exibindo Fila Completa ---\n");
    imprime_FilaDupla(fi);
    printf("Tamanho atual: %d\n\n", tamanho_FilaDupla(fi));

    for (i = 0; i < 4; i++) {
        remove_FilaDupla(fi);
        if (!FilaDupla_vazia(fi)) {
            consulta_FilaDupla(fi, &al);
            printf("Consulta apos remocao: %d \t %s\n", al.matricula, al.nome);
        }
    }

    printf("\nTamanho final: %d\n", tamanho_FilaDupla(fi));

    libera_FilaDupla(fi);
    system("pause");
    return 0;
}