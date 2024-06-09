#include "BucketQuick.h"
#include "Utils.h"
#include <stdio.h>
#include <stdlib.h>


void menu() {
    int opcao;

    do {
        printf("\nAlgoritmos Hibridos:\n");
        printf("1. Miguel\n");
        printf("2. BucketSort com QuickSort\n");
        printf("3. Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                /*Miguel*/
                break;
            case 2:
                menuBucketQuick();
                break;
            case 3:
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 3);
}

int main(){
	menu();
    return 0;
}
