#include "heapFunctions.h"
#include <stdio.h>

int* initFilaP(int tamanho){
    return ((int*)malloc(sizeof(int)*tamanho));
}

void desceHeap(int* vet, int n, int i){

    int esq = 2*i + 1;
    int dir = 2*i + 2;
    int maior;

    if(esq <= n && vet[esq] > vet[i])
        maior = esq;
    else
        maior = i;

    if(dir <= n && vet[dir] > vet[maior])
        maior = dir;

    if(maior != i){
        int aux = vet[i];
        vet[i] = vet[maior];
        vet[maior] = aux;

        desceHeap(vet, n, maior);
    }
}


void sobeHeap(int* vet, int indexAtual){
    if(indexAtual == 0)
        return;

    int pai = (indexAtual-1)/2;

    if(vet[pai] < vet[indexAtual]){
        int aux = vet[indexAtual];
        vet[indexAtual] = vet[pai];
        vet[pai] = aux;

        sobeHeap(vet, pai);
    }
}

int aumentarPrioIndice(int* vet, int currentSize, int indice, int aumento) {

	if(indice > currentSize - 1) return 0;

	if(currentSize == 0) return 0;

	vet[indice] += aumento;
	sobeHeap(vet,indice);
	return 1;
}

int diminuirPrioIndice(int* vet, int currentSize, int indice, int decressimo) {

	if(indice > currentSize - 1) return 0;

	if(currentSize == 0) return 0;

	vet[indice] -= decressimo;
	desceHeap(vet,currentSize,indice);
	return 1;
}


int extrairMaxPrio(int* vet, int* currentSize) {

	if(*currentSize > 0) {
		int item = vet[0];
		vet[0] = vet[*currentSize - 1];
		(*currentSize)--;
		desceHeap(vet, *currentSize,0);
		return item;
	}
	return -1;
}

int inserirPrio(int* vet, int value, int* currentSize, int maxSize){
    if(*currentSize == maxSize)
        return 0;

    vet[*currentSize] = value;
    sobeHeap(vet, *currentSize);

    (*currentSize)++;
    return 1;
}

void imprimirFila(int* array, int currentSize){
    for(int i = 0; i < currentSize; i++){
        printf("[%d]", array[i]);
    }
}
