#include <stdlib.h>
#include <stdio.h>
#include<time.h>

#define ELEMENTOS_POR_LINHA 15

void gerarArquivo(const char *nomeArquivo, int tamanho) {
    int i;
    FILE *arquivo = fopen(nomeArquivo, "w");
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo.\n");
        exit(1);
    }

    srand(time(NULL));
    for (i = 0; i < tamanho; i++) {
        int numero = rand() % 100000;
        fprintf(arquivo, "%05d ", numero);
        if ((i + 1) % ELEMENTOS_POR_LINHA == 0) {
            fprintf(arquivo, "\n");
        }
    }

    fclose(arquivo);
}

void interfaceGerarArquivo(const char *nomeArquivo){
	printf("Quantos numeros?");
	int tam;
	scanf("%d", &tam);
	gerarArquivo(nomeArquivo, tam);
}

int lerArquivo(const char *nomeArquivo, int **arr) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    int tamanho = 0, capacidade = 10;
    *arr = (int *)malloc(capacidade * sizeof(int));
    if (*arr == NULL) {
        printf("Erro ao alocar memoria para o array.\n");
        fclose(arquivo);
        exit(1);
    }

    while (fscanf(arquivo, "%d", &(*arr)[tamanho]) != EOF) {
        tamanho++;
        if (tamanho >= capacidade) {
            capacidade *= 2;
            *arr = (int *)realloc(*arr, capacidade * sizeof(int));
            if (*arr == NULL) {
                printf("Erro ao realocar memoria para o array.\n");
                fclose(arquivo);
                exit(1);
            }
        }
    }

    fclose(arquivo);
    return tamanho;
}

void salvarArquivo(const char *nomeArquivo, int arr[], int tamanho) {
    int i;
    FILE *arquivo = fopen(nomeArquivo, "w");
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo.\n");
        exit(1);
    }

    for (i = 0; i < tamanho; i++) {
        fprintf(arquivo, "%05d ", arr[i]);
        if ((i + 1) % ELEMENTOS_POR_LINHA == 0) {
            fprintf(arquivo, "\n");
        }
    }

    fclose(arquivo);
}

/* Funcao para preencher um array com numeros inteiros aleatorios*/
void dadosAleatorios(int arr[], int tamanho) {
    int i;
    srand(time(NULL));
	for (i = 0; i < tamanho; i++) {
        arr[i] = rand() % 100; 
    }
}

void imprimirArray(int arr[], int tamArr) {
    int i;
	for (i = 0; i < tamArr; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
