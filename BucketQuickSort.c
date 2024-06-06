#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Funcao de comparacao para o QuickSort
int comparar(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Funcao para inserir elementos nos baldes
void inserirNoBucket(int arr[], int bucket[], int n, int tam_bucket) {
    int i, j;
	for (i = 0; i < n; i++) {
        int indice_bucket = arr[i] / tam_bucket;
        for (j = 0; j < tam_bucket; j++) {
            if (bucket[indice_bucket * tam_bucket + j] == -1) {
                bucket[indice_bucket * tam_bucket + j] = arr[i];
                break;
            }
        }
        if (j == tam_bucket) {
        	//comentei o printf pra deixar mais rapido	
            //printf("Estouro: Nao e possivel adicionar %d ao balde %d\n", arr[i], indice_bucket);
            exit(1);
        }
    }
}

// Funcao de ordenacao hibrida
void bucketQuick(int arr[], int n, int tam_bucket) {
    int valor_maximo = arr[0], i;
    for(i = 1; i < n; i++) {
        if (arr[i] > valor_maximo) {
            valor_maximo = arr[i];
        }
    }

    // Inicializa os baldes
    int num_buckets = (valor_maximo / tam_bucket) + 1;
    int bucket[num_buckets * tam_bucket];
    for (i = 0; i < num_buckets * tam_bucket; i++) {
        bucket[i] = -1;
    }

    // Insere os elementos nos baldes
    inserirNoBucket(arr, bucket, n, tam_bucket);

    // Ordena individualmente os baldes usando o QuickSort
    for (i = 0; i < num_buckets; i++) {
        qsort(&bucket[i * tam_bucket], tam_bucket, sizeof(int), comparar);
    }

    // Concatena os baldes ordenados para formar o array final ordenado
    int indice = 0;
    for (i = 0; i < num_buckets * tam_bucket; i++) {
        if (bucket[i] != -1) {
            arr[indice++] = bucket[i];
        }
    }
}
