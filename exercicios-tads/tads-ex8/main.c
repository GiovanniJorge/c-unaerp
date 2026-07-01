#include <stdio.h>
#include <stdlib.h>
#include "Deque.h"

int main() {
    struct aluno al;
    struct aluno a[4] = {
        {2, "Andre",    9.5f, 7.8f, 8.5f},
        {4, "Ricardo", 7.5f, 8.7f, 6.8f},
        {1, "Bianca",   9.7f, 6.7f, 8.4f},
        {3, "Ana",      5.7f, 6.1f, 7.4f}
    };

    Deque* dq = cria_Deque();

    insere_Final_Deque(dq, a[0]); // Inserção normal de fila: Andre no fim
    insere_Final_Deque(dq, a[1]); // Ricardo no fim
    printf("Inseridos no final (Andre, Ricardo):\n");
    imprime_Deque(dq);

    insere_Inicio_Deque(dq, a[2]); // Bianca entra diretamente no INÍCIO
    insere_Inicio_Deque(dq, a[3]); // Ana entra diretamente no INÍCIO
    printf("Inseridos no inicio (Bianca, depois Ana):\n");
    imprime_Deque(dq); // Ordem esperada: Ana -> Bianca -> Andre -> Ricardo

    consulta_Inicio_Deque(dq, &al);
    printf("Inicio atual: %s\n", al.nome);
    consulta_Final_Deque(dq, &al);
    printf("Final atual: %s\n\n", al.nome);

    remove_Inicio_Deque(dq);
    printf("Apos remover do inicio (Ana sai):\n");
    imprime_Deque(dq);

    remove_Final_Deque(dq);
    printf("Apos remover do final (Ricardo sai):\n");
    imprime_Deque(dq);

    libera_Deque(dq);
    system("pause");
    return 0;
}