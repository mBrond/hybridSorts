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
        printf("1. BubbleSort com MergeSort\n");
        printf("2. BucketSort com QuickSort\n");
        printf("3. Gerar arquivo com inteiros\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                interfaceBubbleMerge();
                break;
            case 2:
                menuBucketQuick();
                break;
            case 3:
            	interfaceGerarArquivo("dados_desorganizados.txt");
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
