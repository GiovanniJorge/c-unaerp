#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaAgenda.h"

int main() {
    // 1. Massa de dados para teste (conforme seu modelo anterior)
    Contato c[4] = {
        {"Ricardo", "11-1111", "91111-1111", "ricardo@email.com", {10, 5}},
        {"Andre",   "22-2222", "92222-2222", "andre@email.com",   {15, 3}},
        {"Ana",     "33-3333", "93333-3333", "ana@email.com",     {20, 8}},
        {"Bianca",  "44-4444", "94444-4444", "bianca@email.com",  {05, 12}}
    };

    // 2. Inicialização da Agenda
    Lista* li = cria_agenda();

    // 3. Testando Inserção (que deve manter a ordem alfabética automaticamente)
    printf("--- Inserindo contatos na agenda ---\n");
    for(int i = 0; i < 4; i++) {
        if(insere_contato(li, c[i]))
            printf("Contato '%s' inserido.\n", c[i].nome);
    }

    // 4. Listagem Geral
    printf("\n--- Exibindo Agenda Ordenada ---\n");
    lista_contatos(li);

    // 5. Testando Busca por Nome
    printf("\n--- Testando busca por nome ---\n");
    char nome_busca[] = "Bianca";
    Elemento* res = busca_contato(li, nome_busca);
    if(res != NULL)
        printf("Busca por '%s': Encontrado!", nome_busca);
    else
        printf("Busca por '%s': Nao encontrado.\n", nome_busca);

    // 6. Testando Edição (Atualização)
    printf("\n--- Testando atualizacao de contato ---\n");
    // Nota: atualiza_contato solicitara os novos dados via scanf conforme implementado
    atualiza_contato(li, "Ana");

    // 7. Testando Remoção
    printf("\n--- Testando remocao de contato ---\n");
    char nome_remocao[] = "Ricardo";
    if(remove_contato(li, nome_remocao))
        printf("Contato '%s' removido com sucesso!\n", nome_remocao);
    else
        printf("Falha ao remover '%s'.\n", nome_remocao);

    // 8. Exibição Final
    printf("\n--- Agenda Final ---\n");
    lista_contatos(li);

    // 9. Limpeza de memória (Liberação)
    libera_agenda(li);

    printf("\nMemoria liberada. Programa finalizado.\n");
    return 0;
}