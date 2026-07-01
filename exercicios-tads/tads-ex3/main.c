#include <stdio.h>
#include <stdlib.h>
#include "ListaSequencial.h"

int main()
{
    struct strings s[11] = {
	{"Agua", 500, 1.50},
	{"Refrigerante", 350, 3.00},
	{"Suco", 300, 2.50},
	{"Cerveja", 600, 5.00},
	{"Vinho", 750, 25.00},
	{"Cha", 300, 2.00},
	{"Cafe", 200, 1.00},
	{"Energetio", 250, 6.00},
	{"Iogurte", 200, 3.50},
	{"Leite", 1000, 4.00},
	{"Whisky", 1000, 150.00}
	};

    Lista* li = inicializar_lista();

    if (li == NULL){
        printf("Erro ao alocar lista.\n");
        return 1;
    }

    imprime_lista(li);

    for (int i = 0; i < 11; i++)
        insere_bebida(li, s[i]);

	printf("Pirmeira impressao:\n");
    imprime_lista(li);
    printf("\n\n\n\n");
    
    remove_bebida(li, "Refrigerante");

	printf("Segunda impressao:\n");
    imprime_lista(li);
    printf("\n\n\n\n");

    libera_lista(li);

    li = inicializar_lista();

    imprime_lista(li);

    libera_lista(li);

    return 0;
}