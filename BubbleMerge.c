#include <stdio.h>
#include<stdlib.h>
#include<time.h>

//#include"BubbleMerge.h"
#include"Utils.h"

#define MAX_BUBBLE 50

// Funcao para realizar Bubble Sort em uma sublista
void bubbleSort(int arr[], int esq, int dir){
	int i, j;
    for(i = esq; i < dir; i++){ //itera todos os elementos definidos na porcao do vetor
        for(j = esq; j < dir - (i - esq); j++){ // vai ateh o ultimo elemento nao ordenado. 
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Funcao para mesclar duas sublistas ordenadas
void merge(int arr[], int esq, int mid, int dir){
    int indexEsq = mid - esq + 1;
    int indexDir = dir - mid;
	int i;
    int ArrayEsq[indexEsq], ArrayDir[indexDir];

    for (i = 0; i < indexEsq; i++) {
        ArrayEsq[i] = arr[esq + i];
    }
    for (i = 0; i < indexDir; i++) {
        ArrayDir[i] = arr[mid + 1 + i];
    }

	int j = 0, k = esq;

    while(i < indexEsq && j < indexDir){
        if(ArrayEsq[i] <= ArrayDir[j]){
            arr[k] = ArrayEsq[i];
            i++;
        } else {
            arr[k] = ArrayDir[j];
            j++;
        }
        k++;
    }

//    while (i < indexL) {
//        arr[k] = ArrayEsq[i];
//        i++;
//        k++;
//    }
//
//    while (j < indexR) {
//        arr[k] = ArrayDir[j];
//        j++;
//        k++;
//    }
}

// Funcao para realizar o Hybrid Merge Sort
void mergeBubble(int arr[], int esq, int dir) {
    if (dir - esq + 1 <= MAX_BUBBLE) { //apenas chama a ordenacao do Bubble se o array eh menor/igual ao 
        bubbleSort(arr, esq, dir);
    } else {
        if (esq < dir) {
            int mid = esq + (dir - esq) / 2;
            mergeBubble(arr, esq, mid); //esquerda >< meio
            mergeBubble(arr, mid + 1, dir); // meio+1 >< direita
            merge(arr, esq, mid, dir); //juntar sublistas
        }
    }
}

// Funcao auxiliar para iniciar a ordenação
//void primeiroSort(int arr[], int n) {
//    mergeBubble(arr, 0, n - 1);
//}

void interfaceBMInterna(){
	int tam;
	printf("Qual o tamanho do array?");
	scanf("%d", &tam);
	
	int arr[tam];
	dadosAleatorios(arr, tam);
	imprimirArray(arr, tam);

	double tempoTotal;
	clock_t tComeco = clock(), tFinal;	
	
	mergeBubble(arr, 0, tam-1);
	
	tFinal =  clock();
	tempoTotal = (double) (tFinal - tComeco) / CLOCKS_PER_SEC;
	imprimirArray(arr, tam);
	printf("Tempo final %lf\n", tempoTotal);
}

void interfaceBubbleMerge(){
	int user = 9;
	while(user !=3){
        printf("1. Ordenacao interna\n");
        printf("2. Ordenacao externa\n");
        printf("3. Sair\n");
        printf("Opcao: ");
        scanf("%d", &user);
        
        switch (user){
        	case 1:
        		interfaceBMInterna();
        		break;
        	case 2:
        		break;        	
		}

	}
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

