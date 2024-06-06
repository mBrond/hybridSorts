#include<stdio.h>
#include<stdlib.h>

#include"BucketQuickSort.h"

// Funcao para preencher um array com numeros inteiros aleatorios
void dadosAleatorios(int arr[], int tamanho) {
    int i;
	for (i = 0; i < tamanho; i++) {
        arr[i] = rand() % 100; // Valores aleatorios de 0 a 99
    }
}

void imprimirArray(int arr[], int tamArr) {
    int i;
	for (i = 0; i < tamArr; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void usarQuickBucket(){
	    int tam_array, tam_bucket;
    
    printf("Digite o tamanho do array: ");
    scanf("%d", &tam_array);

    if (tam_array <= 0) {
        printf("Tamanho inválido do array.\n");
        return 1;
    }
    
    printf("Digite o tamanho do balde: ");
    scanf("%d", &tam_bucket);

    if (tam_bucket <= 0) {
        printf("Tamanho inválido do balde.\n");
        return 1;
    }

    int arr[tam_array];

    srand(time(NULL));
    dadosAleatorios(arr, tam_array);

    printf("Array original: ");
    imprimirArray(arr, tam_array);

    ordenacaoHibrida(arr, tam_array, tam_bucket);

    printf("Array ordenado: ");
    imprimirArray(arr, tam_array);
}

//Menu de selecao
void menu();

int main(){
	usarQuickBucket();
}
