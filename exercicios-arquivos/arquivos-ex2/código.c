#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int year;
    char driver[100];
    char owner[100];
    int car;
    char manufacturer[100];
    int wins;
    int top5;
    int top10;
    int races;
    float points;
    float gap;    
} Campeao;

int carrega_campeoes(char nome_arquivo[], Campeao vet[]);
void organiza_por_ano(Campeao vet[], int tamanho);
void merge_sort_champions(Campeao vet[], int inicio, int fim);
void merge_champions(Campeao vet[], int inicio, int meio, int fim);
void salva_campeoes(Campeao vet[], int tamanho, char nome_arquivo[]);

int main() {
    Campeao pilotos[200];
    int qtd_pilotos = 0;

    printf("--- Sistema Data Crazy NASCAR ---\n");

    qtd_pilotos = carrega_campeoes("nascar_champions.csv", pilotos);

    if (qtd_pilotos > 0) {
        printf("Carregados %d registros com sucesso.\n", qtd_pilotos);

        organiza_por_ano(pilotos, qtd_pilotos);
        printf("Dados ordenados por ano.\n");

        salva_campeoes(pilotos, qtd_pilotos, "nascar_champions_ordenado.csv");
        printf("Arquivo 'nascar_champions_ordenado.csv' salvo com sucesso!\n");
    } else {
        printf("Erro: Nao foi possivel carregar os dados ou arquivo vazio.\n");
    }

    return 0;
}

int carrega_campeoes(char nome_arquivo[], Campeao vet[]) {
    FILE *arq = fopen(nome_arquivo, "r");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo %s\n", nome_arquivo);
        return 0;
    }

    char buffer[1024];
    int count = 0;

    fgets(buffer, 1024, arq);

    while (count < 200 && fscanf(arq, "%d,%99[^,],%99[^,],%d,%99[^,],%d,%d,%d,%d,%f,%f",
            &vet[count].year,
            vet[count].driver,      
            vet[count].owner,        
            &vet[count].car,
            vet[count].manufacturer,
            &vet[count].wins,
            &vet[count].top5,
            &vet[count].top10,
            &vet[count].races,
            &vet[count].points,      
            &vet[count].gap) == 11) {
        count++;
    }

    fclose(arq);
    return count;
}

void organiza_por_ano(Campeao vet[], int tamanho) {
    if (tamanho > 0) {
        merge_sort_champions(vet, 0, tamanho - 1); 
    }
}

void merge_sort_champions(Campeao vet[], int inicio, int fim) {
    if (inicio < fim) {
        int meio = (inicio + fim) / 2;
        merge_sort_champions(vet, inicio, meio);
        merge_sort_champions(vet, meio + 1, fim);
        merge_champions(vet, inicio, meio, fim);
    }
}

void merge_champions(Campeao vet[], int inicio, int meio, int fim) {
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    Campeao *L = (Campeao*) malloc(n1 * sizeof(Campeao));
    Campeao *R = (Campeao*) malloc(n2 * sizeof(Campeao));

    for (int i = 0; i < n1; i++)
        L[i] = vet[inicio + i];
    for (int j = 0; j < n2; j++)
        R[j] = vet[meio + 1 + j];

    int i = 0, j = 0, k = inicio;
    
    while (i < n1 && j < n2) {
        if (L[i].year <= R[j].year) {
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

void salva_campeoes(Campeao vet[], int tamanho, char nome_arquivo[]) {
    FILE *arq = fopen(nome_arquivo, "w");
    
    if (arq == NULL) {
        printf("Erro ao criar arquivo de saida.\n");
        return;
    }

    fprintf(arq, "Year,Driver,Owner(s)/Team,Car No.,Manufacturer,Wins,Top-5,Top-10,Races,Points,Gap\n");

    for(int i = 0; i < tamanho; i++) {
        fprintf(arq, "%d,%s,%s,%d,%s,%d,%d,%d,%d,%.2f,%.2f\n",
            vet[i].year,
            vet[i].driver,
            vet[i].owner,
            vet[i].car,
            vet[i].manufacturer,
            vet[i].wins,
            vet[i].top5,
            vet[i].top10,
            vet[i].races,
            vet[i].points,
            vet[i].gap
        );
    }

    fclose(arq);
}