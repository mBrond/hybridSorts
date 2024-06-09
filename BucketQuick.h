#ifndef ORDENACAO_H
#define ORDENACAO_H

int comparar(const void *a, const void *b);
void ordenarBalde(int arr[], int tamanho);
void liberarMemoriaBaldes(int **buckets, int *indices, int num_buckets);
void distribuirElementosNosBaldes(int **buckets, int *indices, int *arr, int n, int tam_bucket, int num_buckets);
void ordenarBaldes(int **buckets, int *indices, int num_buckets);
void mesclarBaldesOrdenados(int **buckets, int *indices, int num_buckets, int *arr);
void BucketQuick(int arr[], int n, int tam_bucket);
void gerarArquivo(const char *nomeArquivo, int tamanho);
int lerArquivo(const char *nomeArquivo, int **arr);
void salvarArquivo(const char *nomeArquivo, int arr[], int tamanho);
void menu();

#endif 
