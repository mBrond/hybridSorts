#include <stdio.h>
#include <stdlib.h>
#include "Utils.h"
#include "BucketQuick.h"
#include "BubbleMerge.h"

void menu() {
    int opcao;

    do {
        printf("\nAlgoritmos Hibridos:\n");
        printf("0. Sair\n");
        printf("1. BucketSort com QuickSort\n");
        printf("2. BubbleSort com MergeSort\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                menuBucketQuick();
                break;
            case 2:
            	interfaceBubbleMerge();
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 0);
}

int main(){
	menu();
    return 0;
}
