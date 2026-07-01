#include <stdio.h>
#include <stdlib.h>
#include "ListaSequencial.h"

int main()
{
    struct numeros n[11] = {4, 8, -1, 19, 2, 7, 8, 5, 9, 22, 45};

    Lista* li = inicializar_lista();

    if (li == NULL){
        printf("Erro ao alocar lista.\n");
        return 1;
    }

    imprime_lista(li);

    for (int i = 0; i < 11; i++)
        insere_elem(li, n[i]);

	printf("Pirmeira impressao:\n");
    imprime_lista(li);
    printf("\n\n\n\n");
    
    remove_elem(li, 8);

	printf("Segunda impressao:\n");
    imprime_lista(li);
    printf("\n\n\n\n");

    libera_lista(li);

    li = inicializar_lista();

    imprime_lista(li);

    libera_lista(li);

    return 0;
}