#include <stdlib.h>
#include <stdio.h>
#include "Utils.h"

/* Funcao para preencher um array com numeros inteiros aleatorios*/
void dadosAleatorios(int arr[], int tamanho) {
    int i;
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