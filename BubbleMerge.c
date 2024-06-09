#include <stdio.h>
#include<stdlib.h>

#include"BubbleMerge.h"
#include"Utils.h"

#define MAX_BUBBLE 50

// Funcao para realizar Bubble Sort em uma sublista
void bubbleSort(int arr[], int left, int right) {
	int i, j;
    for (i = left; i < right; i++) { //itera todos os elementos definidos na porcao do vetor
        for (j = left; j < right - (i - left); j++) { // vai ateh o ultimo elemento nao ordenado. 
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Funcao para mesclar duas sublistas ordenadas
void merge(int arr[], int left, int mid, int right) {
    int index1 = mid - left + 1;
    int index2 = right - mid;
	int i;
    int L[index1], R[index2];
    

    for (i = 0; i < index1; i++) {
        L[i] = arr[left + i];
    }
    for (i = 0; i < index2; i++) {
        R[i] = arr[mid + 1 + i];
    }

	int j = 0, k = left;

    while (i < index1 && j < index2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < index1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < index2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Funcao para realizar o Hybrid Merge Sort
void hybridMergeSort(int arr[], int left, int right) {
    if (right - left + 1 <= MAX_BUBBLE) { //apenas chama a ordenacao do Bubble se o array eh menor/igual ao 
        bubbleSort(arr, left, right);
    } else {
        if (left < right) {
            int mid = left + (right - left) / 2;
            hybridMergeSort(arr, left, mid); //esquerda >< meio
            hybridMergeSort(arr, mid + 1, right); // meio+1 >< direita
            merge(arr, left, mid, right);
        }
    }
}

// Funcao auxiliar para iniciar a ordenação
void sort(int arr[], int n) {
    hybridMergeSort(arr, 0, n - 1);
}


void interfaceBubbleMerge(){
	
}

// Exemplo de uso
//int main() {
//    int arr[] = {12, 11, 13, 5, 6O, 7};
//    int tam = 6;
//    int qtdMaxBubble = 5;
//
//    printf("Array inicial: \n");
//    printArray(arr, n);
//
//    sort(arr, n, qtdMaxBubble);
//
//    printf("Array ordenado: \n");
//    printArray(arr, n);
//
//    return 0;
//}

