#include <stdio.h>
#include <stdlib.h>
#include "ListaDinEncadCirc.h"

int main(){
    // Massa de dados para teste - Lista 1
    struct aluno a[8] = {{2,"Andre",9.5,7.8,8.5},
                         {4,"Ricardo",7.5,8.7,6.8},
                         {3,"Bianca",2.1,0.7,3.4},
                         {7,"Roberta",4.3,9.9,6.4},
						 {8,"Cleber",9.0,7.6,7.8},
						 {5,"Joao",3.9,4.7,1.2},
						 {6,"Felipe",8.7,9.1,8.3},
						 {1,"Gabriela",10.0,7.5,9.2}};

    // Inicialização do TAD - Lista 1
    printf("LISTA 1\n");
    Lista* li1 = cria_lista();
    
    imprime_lista(li1);
    printf("Tamanho atual: %d\n\n", tamanho_lista(li1));

    printf("--- Inserindo alunos no inicio ---\n\n");
    for(int i=0; i < 8; i++)
        insere_lista_inicio(li1, a[i]);
        
    imprime_lista(li1);
    printf("Tamanho atual: %d\n", tamanho_lista(li1));
        
    struct aluno melhor;    
    busca_maior_nota(li1, &melhor);
    printf("\nAluno com maior media: %s (Matricula: %d)\n\n\n", melhor.nome, melhor.matricula);
    
    // Massa de dados para teste - Lista 2
    struct aluno b[3] = {{9,"Mateus",9.1,7.5,8.3},
                         {11,"Helena",5.6,10.0,7.7},
                         {10,"Jose",3.2,9.6,6.4}};
                         
    // Inicialização do TAD - Lista 2                   
    printf("LISTA 2\n");
    Lista* li2 = cria_lista();
    
    imprime_lista(li2);
    printf("Tamanho atual: %d\n\n", tamanho_lista(li2));

    printf("--- Inserindo alunos no inicio ---\n");
    for(int i=0; i < 3; i++)
        insere_lista_inicio(li2, b[i]);
    
	printf("\n--- Concatenando listas ---\n\n");             
    concatena_listas(li1, li2);

    imprime_lista(li1);
    printf("Tamanho atual: %d\n", tamanho_lista(li1));
    
    // Inicialização do TAD - Lista de Aprovados
    printf("\n\nLISTA DE APROVADOS\n");
    Lista* li_aprovados = filtrar_aprovados(li1);
    
    printf("Tamanho atual: %d\n\n", tamanho_lista(li_aprovados));
    
    imprime_lista(li_aprovados);
    printf("Tamanho atual: %d\n", tamanho_lista(li_aprovados));
    
    // Inicialização do TAD - Lista Ordenada Por Nome
    printf("\n\nLISTA ORDENADA POR NOME\n");
    Lista* li_ordenada = cria_lista();
    
    imprime_lista(li_ordenada);
    printf("Tamanho atual: %d\n\n", tamanho_lista(li_ordenada));
    
    struct aluno temp;
	int tam = tamanho_lista(li1);
	
	for(int i = 1; i <= tam; i++) {
	    consulta_lista_pos(li1, i, &temp);
	    insere_lista_ordenada_nome(li_ordenada, temp);
	}
        
    imprime_lista(li_ordenada);
    printf("Tamanho atual: %d\n", tamanho_lista(li_ordenada));

    // Limpeza de memória
    libera_lista(li1);
    libera_lista(li2);
    libera_lista(li_aprovados);
    libera_lista(li_ordenada);

    printf("\nMemoria liberada. Programa finalizado.\n");
    return 0;
}