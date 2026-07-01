#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaDinEncadCirc.h"

/* * Estrutura do Nó (Elemento)
 * Encapsulada no .c para que o usuário do TAD não manipule ponteiros internos.
 */
struct elemento {
    struct aluno dados;    // Conteúdo informativo
    struct elemento *prox; // Ponteiro para o próximo nó
};
typedef struct elemento Elem;

/* * Criação da Lista
 * Retorna um ponteiro para ponteiro (Lista**), que serve como o "nó descritor".
 */
Lista* cria_lista() {
    Lista* li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL)
        *li = NULL; // A lista inicia apontando para NULL (vazia)
    return li;
}

/* * Liberação da Lista
 * CUIDADO: Em listas circulares, um 'while(no != NULL)' causaria loop infinito.
 */
void libera_lista(Lista* li) {
    if(li != NULL && (*li) != NULL) {
        Elem *aux, *no = *li;
        // Percorremos a lista até que o próximo volte a ser o início
        while((*li) != no->prox) {
            aux = no;
            no = no->prox;
            free(aux);
        }
        free(no); // Libera o último elemento que sobrou
        free(li); // Libera o ponteiro sentinela (cabeçalho)
    }
}

/* * Consulta por Posição
 * Objetivo: Recuperar os dados do aluno em uma determinada posição (1, 2, 3...).
 * @param li: Ponteiro para a lista.
 * @param pos: Posição desejada (baseada em 1).
 * @param al: Ponteiro para a estrutura que receberá os dados (passagem por referência).
 */
int consulta_lista_pos(Lista* li, int pos, struct aluno *al){
    // Validação de segurança:
    // 1. A lista existe? (li != NULL)
    // 2. A lista possui nós? ((*li) != NULL)
    // 3. A posição é válida? (pos > 0)
    if(li == NULL || (*li) == NULL || pos <= 0)
        return 0;

    Elem *no = *li; // Começamos a busca pelo primeiro nó
    int i = 1;      // Contador para rastrear a posição atual

    /* * Lógica de Navegação Circular:
     * O loop deve parar se:
     * a) Encontrarmos a posição (i < pos se torna falso)
     * b) Voltarmos ao início da lista (no->prox == *li), significando que a posição
     * pedida é maior que o tamanho da lista.
     */
    while(no->prox != (*li) && i < pos){
        no = no->prox;
        i++;
    }

    /* * Verificação de Sucesso:
     * Se saímos do loop, precisamos saber se paramos porque achamos o 'i == pos'
     * ou se a lista acabou antes de chegarmos lá.
     */
    if(i != pos) {
        // Se i ainda é diferente de pos, a posição solicitada não existe na lista
        return 0;
    } else {
        // Sucesso: Copia os dados do nó encontrado para o parâmetro de saída
        *al = no->dados;
        return 1;
    }
}
/* * Consulta por Matrícula (Busca por Chave)
 * Objetivo: Localizar um aluno através do seu número de matrícula.
 * @param li: Ponteiro para a lista.
 * @param mat: Valor da matrícula que estamos procurando.
 * @param al: Ponteiro de destino para copiar os dados caso o aluno seja encontrado.
 */
int consulta_lista_mat(Lista* li, int mat, struct aluno *al){
    // Validação inicial: se a lista não existe ou está vazia, a busca falha imediatamente.
    if(li == NULL || (*li) == NULL)
        return 0;

    Elem *no = *li; // Começamos a busca a partir do primeiro nó (início)

    /* * Lógica de Busca em Lista Circular:
     * O loop continuará enquanto:
     * 1. O próximo nó NÃO for o início (evita loop infinito se o valor não existir).
     * 2. O valor do nó atual NÃO for a matrícula desejada.
     */
    while(no->prox != (*li) && no->dados.matricula != mat){
        no = no->prox;
    }

    /* * Tratamento do Resultado:
     * Ao sair do loop, o ponteiro 'no' parou em algum lugar.
     * Precisamos testar se ele parou porque achou o dado ou porque a lista acabou.
     */
    if(no->dados.matricula != mat){
        // Se após percorrer (ou chegar ao último), a matrícula ainda for diferente,
        // significa que o elemento não pertence à lista.
        return 0;
    } else {
        // Elemento encontrado!
        // Copiamos os dados para o ponteiro 'al' (passagem por referência).
        *al = no->dados;
        return 1;
    }
}

/* * Inserção no Final
 * Objetivo: Adicionar um novo aluno após o último elemento atual da lista.
 * @param li: Ponteiro para o descritor da lista (ponteiro para ponteiro).
 * @param al: Estrutura contendo os dados do aluno a ser inserido.
 */
int insere_lista_final(Lista* li, struct aluno al){
    // 1. Verificação de segurança: a lista (o ponteiro li) foi criada?
    if(li == NULL)
        return 0;

    // 2. Alocação dinâmica do novo nó (elemento)
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL) // Falha na alocação (falta de memória)
        return 0;

    // Atribui os dados ao novo nó
    no->dados = al;

    /* * Lógica de Inserção: */
    if((*li) == NULL){
        // CASO A: Lista Vazia
        // Se a lista está vazia, o "final" é também o "início".
        *li = no;          // O ponteiro de início da lista aponta para o novo nó
        no->prox = no;     // Circularidade: o nó aponta para si mesmo
    } else {
        // CASO B: Lista com Elementos
        // Precisamos encontrar o nó que atualmente é o último.
        Elem *aux = *li;

        // O último nó é aquele cujo 'prox' aponta para o início (*li)
        while(aux->prox != (*li)){
            aux = aux->prox;
        }

        /* * Ajuste de Ponteiros para Inserção:
         * 1. O antigo último (aux) agora aponta para o novo nó.
         * 2. O novo nó (no) agora aponta para o início (*li), fechando o círculo.
         */
        aux->prox = no;
        no->prox = *li;
    }

    return 1; // Sucesso
}


/* * Inserção no Início
 * Estratégia: O novo nó deve apontar para o antigo início,
 * e o último nó deve ser atualizado para apontar para este novo início.
 */
int insere_lista_inicio(Lista* li, struct aluno al) {
    if(li == NULL) return 0;
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL) return 0;
    no->dados = al;

    if((*li) == NULL) { // Caso A: Lista Vazia
        *li = no;
        no->prox = no; // Circularidade: aponta para si mesmo
    } else {           // Caso B: Lista já possui elementos
        Elem *aux = *li;
        // Percorre até encontrar o último nó (aquele que aponta para o início)
        while(aux->prox != (*li))
            aux = aux->prox;

        no->prox = *li;  // Novo nó aponta para o atual primeiro
        aux->prox = no;  // Último nó agora aponta para o novo nó
        *li = no;        // O ponteiro de entrada da lista agora é o novo nó
    }
    return 1;
}

/* * Inserção Ordenada (por Matrícula)
 * Objetivo: Manter a lista sempre crescente, sem necessidade de ordenar depois.
 * Este algoritmo trata três cenários: Lista vazia, Inserção no Início e Meio/Fim.
 */
int insere_lista_ordenada(Lista* li, struct aluno al){
    if(li == NULL) return 0;

    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL) return 0;
    no->dados = al;

    // CASO 1: Lista Vazia
    // O novo nó torna-se o primeiro e aponta para si mesmo.
    if((*li) == NULL){
        *li = no;
        no->prox = no;
        return 1;
    }
    else {
        // CASO 2: Inserção no Início
        // Se a matrícula do novo aluno for MENOR que a do primeiro atual.
        if((*li)->dados.matricula > al.matricula){
            Elem *ultimo = *li;
            // IMPORTANTE: Em listas circulares, para mudar o início,
            // precisamos que o último nó aponte para o novo primeiro.
            while(ultimo->prox != (*li))
                ultimo = ultimo->prox;

            no->prox = *li;      // Novo nó aponta para o antigo início
            ultimo->prox = no;   // O último fecha o ciclo no novo nó
            *li = no;            // Atualiza o cabeçalho da lista
            return 1;
        }

        // CASO 3: Inserção no Meio ou no Final
        // Usamos dois ponteiros auxiliares para "abrir espaço" entre dois nós.
        Elem *ant = *li;
        Elem *atual = (*li)->prox;

        // Percorre enquanto:
        // 1. Não der a volta completa (atual != *li)
        // 2. A matrícula do nó atual for menor que a do novo aluno
        while(atual != (*li) && atual->dados.matricula < al.matricula){
            ant = atual;
            atual = atual->prox;
        }

        // O novo nó entra entre 'ant' e 'atual'
        ant->prox = no;
        no->prox = atual;
        // Se 'atual' for o '*li', o nó foi inserido no fim corretamente.

        return 1;
    }
}
/* * Remoção do Início
 * Necessário atualizar o 'prox' do último elemento para o novo início.
 */
int remove_lista_inicio(Lista* li) {
    if(li == NULL || (*li) == NULL) return 0;

    // Caso 1: Apenas um elemento
    if((*li) == (*li)->prox) {
        free(*li);
        *li = NULL;
        return 1;
    }

    // Caso 2: Múltiplos elementos. Precisamos do último para manter a circularidade.
    Elem *atual = *li;
    while(atual->prox != (*li))
        atual = atual->prox;

    Elem *no_removido = *li;
    atual->prox = no_removido->prox; // Último aponta para o segundo elemento
    *li = no_removido->prox;        // O início da lista passa a ser o segundo
    free(no_removido);
    return 1;
}

/* * Remoção do Final
 * Diferente da lista comum, aqui o "final" é o nó que aponta para o "início".
 */
int remove_lista_final(Lista* li) {
    if(li == NULL || (*li) == NULL) return 0;

    if((*li) == (*li)->prox) { // Único elemento
        free(*li);
        *li = NULL;
        return 1;
    }

    Elem *ant, *no = *li;
    // Percorre até encontrar o último, mantendo o anterior (ant)
    while(no->prox != (*li)) {
        ant = no;
        no = no->prox;
    }
    ant->prox = no->prox; // O penúltimo agora aponta para o início (*li)
    free(no);
    return 1;
}

/* * Remoção por Valor (Matrícula)
 */
int remove_lista(Lista* li, int mat) {
    if(li == NULL || (*li) == NULL) return 0;

    Elem *no = *li;
    // Caso especial: o elemento está logo na primeira posição
    if(no->dados.matricula == mat) {
        if(no == no->prox) { // Único elemento da lista
            free(no);
            *li = NULL;
        } else {
            // Se houver mais de um, precisamos achar o último para atualizar o 'prox'
            Elem *ult = *li;
            while(ult->prox != (*li))
                ult = ult->prox;
            ult->prox = (*li)->prox;
            *li = (*li)->prox;
            free(no);
        }
        return 1;
    }

    // Busca no restante da lista
    Elem *ant = no;
    no = no->prox;
    // Percorre enquanto não voltar ao início E não achar a matrícula
    while(no != (*li) && no->dados.matricula != mat) {
        ant = no;
        no = no->prox;
    }

    if(no == *li) return 0; // Deu a volta completa e não encontrou

    ant->prox = no->prox; // "Pula" o nó que será removido
    free(no);
    return 1;
}

/* * Tamanho da Lista
 * Nota Didática: Usamos 'do-while' porque a condição de parada (no != *li)
 * já é falsa no primeiro instante em listas circulares.
 */
int tamanho_lista(Lista* li) {
    if(li == NULL || (*li) == NULL) return 0;
    int cont = 0;
    Elem* no = *li;
    do {
        cont++;
        no = no->prox;
    } while(no != (*li)); // Só para quando voltar ao endereço inicial
    return cont;
}

int lista_cheia(Lista* li){
    return 0;
}

int lista_vazia(Lista* li){
    if(li == NULL)
        return 1;
    if(*li == NULL)
        return 1;
    return 0;
}


/* * Impressão da Lista
 */
void imprime_lista(Lista* li){
    if(li == NULL || (*li) == NULL)
        return;
    Elem* no = *li;
    do{
        printf("Matricula: %d\n",no->dados.matricula);
        printf("Nome: %s\n",no->dados.nome);
        printf("Notas: %f %f %f\n",no->dados.n1,
                                   no->dados.n2,
                                   no->dados.n3);
        printf("-------------------------------\n");
        no = no->prox;
    }while(no != (*li));
}

int busca_maior_nota(Lista *li, struct aluno *al) {
	if(li == NULL)
		return 0;
		
	if((*li) == NULL)
		return 0;
	
	Elem *no = *li, *aux = no;
	float media = 0, atual = 0;
	
	do {
		media = (no->dados.n1 + no->dados.n2 + no->dados.n3) / 3.0;
		if(media > atual) {
			atual = media;
			aux = no;
		}
		no = no->prox;
	} while(no != (*li));
	
	*al =  aux->dados;
	
	return 1;
}

int insere_lista_ordenada_nome(Lista* li, struct aluno al){
    if(li == NULL) return 0;

    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL) return 0;
    no->dados = al;

    if((*li) == NULL){
        *li = no;
        no->prox = no;
        return 1;
    }
    else {
        if(strcmp(al.nome, (*li)->dados.nome) < 0){
            Elem *ultimo = *li;

            while(ultimo->prox != (*li))
                ultimo = ultimo->prox;

            no->prox = *li;      
            ultimo->prox = no;   
            *li = no;            
            return 1;
        }

        Elem *ant = *li;
        Elem *atual = (*li)->prox;

        while(atual != (*li) && strcmp(atual->dados.nome, al.nome) < 0){
            ant = atual;
            atual = atual->prox;
        }

        ant->prox = no;
        no->prox = atual;

        return 1;
    }
}

int concatena_listas(Lista *li1, Lista *li2) {
    if (li1 == NULL || li2 == NULL || (*li2) == NULL) {
        return 0;
    }

    Elem *atual2 = *li2;

    do {
        if (!insere_lista_final(li1, atual2->dados)) {
            return 0;
        }

        atual2 = atual2->prox;
    } while (atual2 != (*li2));

    return 1;
}

Lista* filtrar_aprovados(Lista *li) {
    Lista* li_aprovados = cria_lista();

    if (li == NULL || (*li) == NULL) {
        return li_aprovados;
    }

    Elem *no = *li;
    float media;

    do {
        media = (no->dados.n1 + no->dados.n2 + no->dados.n3) / 3.0;

        if (media >= 5.0) {
            insere_lista_final(li_aprovados, no->dados);
        }

        no = no->prox;
    } while (no != (*li));

    return li_aprovados;
}

