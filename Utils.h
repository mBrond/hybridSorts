#ifndef UTILS_H
#define UTILS_H

#include"Utils.c"

void gerarArquivo(const char *nomeArquivo, int tamanho);
void interfaceGerarArquivo(const char *nomeArquivo);
int lerArquivo(const char *nomeArquivo, int **arr);
void salvarArquivo(const char *nomeArquivo, int arr[], int tamanho);
/*Funcao para preencher um array com numeros inteiros aleatorios*/
void dadosAleatorios(int arr[], int tamanho);
/*Funcao para imprimir um array*/
void imprimirArray(int arr[], int tamArr);

#endif 
