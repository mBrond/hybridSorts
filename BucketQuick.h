#ifndef ORDENACAO_H
#define ORDENACAO_H

void ordenacaoHibrida(int arr[], int n, int tam_bucket);
void gerarArquivo(const char *nomeArquivo, int tamanho);
int lerArquivo(const char *nomeArquivo, int **arr);
void salvarArquivo(const char *nomeArquivo, int arr[], int tamanho);
void menu();

#endif 
