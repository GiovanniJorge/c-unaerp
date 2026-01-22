#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	char nome[100];
	char etapa[100];
	int numero;
	float nota;
} Aluno;

int carrega_alunos(char nome_arquivo[], Aluno vet[]);
void organiza_por_nota(Aluno vet[], int tamanho);
void merge_sort_alunos(Aluno vet[], int inicio, int fim);
void merge_alunos(Aluno vet[], int inicio, int meio, int fim);
void salva_alunos(Aluno vet[], int tamanho, char nome_arquivo[]);

int main() {
	Aluno pessoa[500];
	int qtd_pessoas = 0;
	
	printf("--- Sistema Alunos ---\n");
	
	qtd_pessoas = carrega_alunos("alunos.csv", pessoa);
	
	if (qtd_pessoas > 0) {
		printf("Carregados %d registros com sucesso.\n", qtd_pessoas);
	
	    organiza_por_nota(pessoa, qtd_pessoas);
	    printf("Dados ordenados alfabeticamente pelo campo Nome.\n");
	
	    salva_alunos(pessoa, qtd_pessoas, "alunos_ordenados_por_nome.csv");
	    printf("Arquivo 'alunos_ordenados_por_nome.csv' salvo com sucesso!\n");
    } else {
        printf("Erro: Nao foi possivel carregar os dados ou arquivo vazio.\n");
    }

    return 0;
}

int carrega_alunos(char nome_arquivo[], Aluno vet[]) {
    FILE *arq = fopen(nome_arquivo, "r");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo %s\n", nome_arquivo);
        return 0;
    }

    char buffer[1024];
    int count = 0;

    fgets(buffer, 1024, arq);

    while (count < 500 && fscanf(arq, "%99[^;];%99[^:]:%d;%f\n",
            vet[count].nome,
            vet[count].etapa,        
            &vet[count].numero,            
            &vet[count].nota) == 4) {
        count++;
    }

    fclose(arq);
    return count;
}

void organiza_por_nota(Aluno vet[], int tamanho) {
    if (tamanho > 0) {
        merge_sort_alunos(vet, 0, tamanho - 1);  
    }
}

void merge_sort_alunos(Aluno vet[], int inicio, int fim) {
    if (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;
        merge_sort_alunos(vet, inicio, meio);
        merge_sort_alunos(vet, meio + 1, fim);
        merge_alunos(vet, inicio, meio, fim);
    }
}

void merge_alunos(Aluno vet[], int inicio, int meio, int fim) {
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    Aluno *L = (Aluno*) malloc(n1 * sizeof(Aluno));
    Aluno *R = (Aluno*) malloc(n2 * sizeof(Aluno));

    if (L == NULL || R == NULL) {
        fprintf(stderr, "Erro de alocacao de memoria no merge.\n");
        if (L) free(L);
        if (R) free(R);
        return;
    }

    for (int i = 0; i < n1; i++)
        L[i] = vet[inicio + i];
    for (int j = 0; j < n2; j++)
        R[j] = vet[meio + 1 + j];

    int i = 0, j = 0, k = inicio;

    while (i < n1 && j < n2) {
        if (strcmp(L[i].nome, R[j].nome) <= 0) {
            vet[k] = L[i];
            i++;
        } else {
            vet[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        vet[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        vet[k] = R[j];
        j++;
        k++;
    }
   
    free(L);
    free(R);
}

void salva_alunos(Aluno vet[], int tamanho, char nome_arquivo[]) {
    FILE *arq = fopen(nome_arquivo, "w");
   
    if (arq == NULL) {
        printf("Erro ao criar arquivo de saida.\n");
        return;
    }

    fprintf(arq, "Nome;Etapa;Nota Final\n");

    for(int i = 0; i < tamanho; i++) {
        fprintf(arq, "%s;%s:%d;%.1f\n",
            vet[i].nome,
            vet[i].etapa,
            vet[i].numero,
            vet[i].nota
        );
    }

    fclose(arq);
}
