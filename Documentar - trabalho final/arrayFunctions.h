#include <stdlib.h>

int* initArray(int tamanho);
int inserirElemento(int* array, int valor, int* currentSize, int maxSize);
int removerElemento(int* array, int valor, int* currentSize);
int editarElemento(int* array, int valorAtual, int valorNovo,  int currentSize);
int pesquisarElemento(int* array, int valor, int currentSize);
void imprimirVetor(int* array, int currentSize);
