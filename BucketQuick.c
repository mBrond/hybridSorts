#include "BucketQuick.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ELEMENTOS_POR_LINHA 15

int comparar(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void ordenarBalde(int arr[], int tamanho) {
    qsort(arr, tamanho, sizeof(int), comparar);
}

void liberarMemoriaBaldes(int **buckets, int *indices, int num_buckets) {
    for (int i = 0; i < num_buckets; i++) {
        free(buckets[i]);
    }
    free(buckets);
    free(indices);
}

void distribuirElementosNosBaldes(int **buckets, int *indices, int *arr, int n, int tam_bucket, int num_buckets) {
    for (int i = 0; i < n; i++) {
        int indice_bucket = arr[i] / tam_bucket;
        if (indices[indice_bucket] % tam_bucket == 0) {
            buckets[indice_bucket] = (int *)realloc(buckets[indice_bucket], (indices[indice_bucket] + tam_bucket) * sizeof(int));
            if (buckets[indice_bucket] == NULL) {
                printf("Erro ao realocar memoria para um balde.\n");
                liberarMemoriaBaldes(buckets, indices, num_buckets);
                free(arr);
                exit(1);
            }
        }
        buckets[indice_bucket][indices[indice_bucket]++] = arr[i];
    }
}


void ordenarBaldes(int **buckets, int *indices, int num_buckets) {
    int i;
    for (i = 0; i < num_buckets; i++) {
        ordenarBalde(buckets[i], indices[i]);
    }
}

void mesclarBaldesOrdenados(int **buckets, int *indices, int num_buckets, int *arr) {
    int i, j, k = 0;
    for (i = 0; i < num_buckets; i++) {
        for (j = 0; j < indices[i]; j++) {
            arr[k++] = buckets[i][j];
        }
        free(buckets[i]);
    }
}

void BucketQuick(int arr[], int n, int tam_bucket) {
    int valor_maximo = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > valor_maximo) {
            valor_maximo = arr[i];
        }
    }

    int num_buckets = (valor_maximo / tam_bucket) + 1;

    int **buckets = (int **)malloc(num_buckets * sizeof(int *));
    if (buckets == NULL) {
        printf("Erro ao alocar memoria para os baldes.\n");
        exit(1);
    }

    int *indices = (int *)calloc(num_buckets, sizeof(int));
    if (indices == NULL) {
        printf("Erro ao alocar memoria para os indices dos baldes.\n");
        free(buckets);
        exit(1);
    }

    for (int i = 0; i < num_buckets; i++) {
        buckets[i] = (int *)malloc(tam_bucket * sizeof(int));
        if (buckets[i] == NULL) {
            printf("Erro ao alocar memoria para um balde.\n");
            liberarMemoriaBaldes(buckets, indices, num_buckets);
            exit(1);
        }
    }

    distribuirElementosNosBaldes(buckets, indices, arr, n, tam_bucket, num_buckets);
    ordenarBaldes(buckets, indices, num_buckets);
    mesclarBaldesOrdenados(buckets, indices, num_buckets, arr);

    liberarMemoriaBaldes(buckets, indices, num_buckets);
}


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

void menu() {
    int opcao;
    int tam_array, tam_bucket;
    const char *nomeArquivoDesorganizado = "dados_desorganizados.txt";
    const char *nomeArquivoOrdenado = "dados_ordenados.txt";
    
    do {
        printf("\nEscolha uma opcao:\n");
        printf("1. Ordenacao interna\n");
        printf("2. Ordenacao externa\n");
        printf("3. Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:{
                int i;
                printf("Digite o tamanho do array: ");
                scanf("%d", &tam_array);

                if (tam_array <= 0) {
                    printf("Tamanho invalido do array.\n");
                    break;
                }

                printf("Digite o tamanho do balde: ");
                scanf("%d", &tam_bucket);

                if (tam_bucket <= 0) {
                    printf("Tamanho invalido do balde.\n");
                    break;
                }

                int *arr = (int *)malloc(tam_array * sizeof(int));
                if (arr == NULL) {
                    printf("Erro ao alocar memoria para o array.\n");
                    exit(1);
                }

                srand(time(NULL));
                for (i = 0; i < tam_array; i++) {
                    arr[i] = rand() % 100000; 
                }

                printf("Array desorganizado:\n");
                for (i = 0; i < tam_array; i++) {
                    printf("%05d ", arr[i]);
                    if ((i + 1) % ELEMENTOS_POR_LINHA == 0) {
                        printf("\n");
                    }
                }
                printf("\n");
                clock_t inicio = clock();
                BucketQuick(arr, tam_array, tam_bucket);
                clock_t fim = clock();

                printf("\nArray organizado:\n");
                for (i = 0; i < tam_array; i++) {
                    printf("%05d ", arr[i]);
                    if ((i + 1) % ELEMENTOS_POR_LINHA == 0) {
                        printf("\n");
                    }
                }
                printf("\n");

                double tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
                printf("Tempo de execucao da ordenacao interna: %.6f segundos\n", tempo_gasto);

                free(arr);
                break;
            }
            case 2:{
                printf("Digite o tamanho do array: ");
                scanf("%d", &tam_array);

                if (tam_array <= 0) {
                    printf("Tamanho invalido do array.\n");
                    break;
                }

                printf("Digite o tamanho do balde: ");
                scanf("%d", &tam_bucket);

                if (tam_bucket <= 0) {
                    printf("Tamanho invalido do balde.\n");
                    break;
                }

                gerarArquivo(nomeArquivoDesorganizado, tam_array);

                int *arr;
                int tamanho = lerArquivo(nomeArquivoDesorganizado, &arr);

                clock_t inicio = clock();
                BucketQuick(arr, tamanho, tam_bucket);
                clock_t fim = clock();

                salvarArquivo(nomeArquivoOrdenado, arr, tamanho);

                double tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
                printf("Tempo de execucao da ordenacao externa: %.6f segundos\n", tempo_gasto);

                free(arr);
                printf("Os dados foram ordenados e salvos no arquivo '%s'.\n", nomeArquivoOrdenado);
                break;
            }
            case 3:{
                break;
            }
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 3);
}

int main(){
    menu();
    return 0;
}

               
