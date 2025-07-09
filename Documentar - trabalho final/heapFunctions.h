#include <stdlib.h>

int* initFilaP(int tamanho);

void desceHeap(int* vet, int n, int i);
void sobeHeap(int* vet, int indexAtual);

int aumentarPrioIndice(int* vet, int currentSize, int indice, int aumento);
int diminuirPrioIndice(int* vet, int currentSize, int indice, int decressimo);

int extrairMaxPrio(int* vet, int* currentSize);
int inserirPrio(int* vet, int value, int* currentSize, int maxSize);

void imprimirFila(int* array, int currentSize);
