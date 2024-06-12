#include <stdio.h>
#include<stdlib.h>
#include<time.h>

#include"Utils.h"

#define MAX_BUBBLE 30

//Funcao para realizar Bubble Sort em uma sublista
void bubbleSort(int arr[], int esq, int dir) {
    int i, j;
    for (i = esq; i <= dir; i++) { //Itera todos os elementos definidos na porcao do vetor
        for (j = esq; j <= dir - (i - esq); j++) { //Vai ate o ultimo elemento nao ordenado
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

//funcao para mesclar duas sublistas ordenadas
void merge(int arr[], int esq, int mid, int dir) {
    int indexEsq = mid - esq + 1;
    int indexDir = dir - mid;
    int i, j, k;

    //aloca arrays temporarios
    int *arrEsq = (int *)malloc(indexEsq * sizeof(int));
    int *arrDir = (int *)malloc(indexDir * sizeof(int));

    // Copia dados para os arrays temporarios
    for (i = 0; i < indexEsq; i++) {
        arrEsq[i] = arr[esq + i];
    }
    for (j = 0; j < indexDir; j++) {
        arrDir[j] = arr[mid + 1 + j];
    }

    i = 0;
    j = 0; 
    k = esq;

    //mescla os arrays temporários de volta ao array original
    while (i < indexEsq && j < indexDir){
        if (arrEsq[i] <= arrDir[j]) {
            arr[k] = arrEsq[i];
            i++;
        } else {
            arr[k] = arrDir[j];
            j++;
        }
        k++;
    }

    while (i < indexEsq) {
        arr[k] = arrEsq[i];
        i++;
        k++;
    }

    while (j < indexDir) {
        arr[k] = arrDir[j];
        j++;
        k++;
    }

    free(arrEsq);
    free(arrDir);
}

void mergeBubble(int arr[], int esq, int dir) {
    int tamArr = dir - esq + 1;
    if (tamArr <= MAX_BUBBLE) { //apenas chama a ordenação do Bubble se o array é menor/igual ao max definido para o bubble
        bubbleSort(arr, esq, dir);
    } else {
        if (esq < dir) {
            int mid = esq + (dir - esq) / 2;
            mergeBubble(arr, esq, mid); //esquerda >< Meio
            mergeBubble(arr, mid + 1, dir); //meio+1 >< Direita
            merge(arr, esq, mid, dir);
        }
    }
}

void interfaceBMInterna(){
	int tam;
	printf("Qual o tamanho do array?");
	scanf("%d", &tam);
	
	int arr[tam];
	dadosAleatorios(arr, tam);

	double tempoTotal;
	clock_t tComeco = clock(), tFinal;	
	
	mergeBubble(arr, 0, tam-1);
	
	tFinal =  clock();
	tempoTotal = (double) (tFinal - tComeco) / CLOCKS_PER_SEC;
	printf("Tempo final %lf\n", tempoTotal);

}

void interfaceBMExterna(){
	int user, tam;
	do{
		printf("\nRecriar arquivo externo? 0-Nao, 1-Sim\n");
		scanf("%d", &user);
	}while(user!=1 && user!=0);
	
	printf("\nQuantos inteiros?");
	scanf("%d", &tam);
	if(user==1){
		gerarArquivo("dados_desorganizados.txt", tam);
	}
	
	int *arr;
    int tamanho = lerArquivo("dados_desorganizados.txt", &arr);

	double tempoTotal;
	clock_t tComeco = clock(), tFinal;	
	
	mergeBubble(arr, 0, tam+1);
	
	tFinal =  clock();
	tempoTotal = (double) (tFinal - tComeco) / CLOCKS_PER_SEC;
	salvarArquivo("dados_ordenados.txt", arr, tam);
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
        		interfaceBMExterna();
        		break;        	
		}

	}
}
