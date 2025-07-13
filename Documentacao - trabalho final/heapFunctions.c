#include "heapFunctions.h"
#include <stdio.h>

/**
 * Inicia uma fila de prioridade com o tamanho desejado.
 * @param tamanho Tamanho desejado para a fila de prioridade.
 * @return Um vetor alocado com o tamanho desejado.
 */
int* initFilaP(int tamanho){
    return ((int*)malloc(sizeof(int)*tamanho));
}


/**
 * Organiza e define a prioridade de um novo valor inserido no início de uma fila de prioridade.
 * @param vet A fila de prioridade;
 * @param n Último índice da fila de prioridade;
 * @param i Índice do novo valor.
 * @return 
 */
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


/**
 * Organiza e define a prioridade de um novo valor inserido no final de uma fila de prioridade.
 * @param vet A fila de prioridade;
 * @param indexAtual Índice do novo valor.
 * @return 
 */
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


/**
 * Aumenta a prioridade de um valor em uma fila de prioridade.
 * @param vet A fila de prioridade;
 * @param currentSize Tamanho da fila de prioridade;
 * @param indice Índice do valor que terá a prioridade aumentada;
 * @param aumento A quantidade que será incrementado ao valor.
 * @return 1 caso o aumento de prioridade tenha sido um sucesso, ou 0 caso contrário.
 */
int aumentarPrioIndice(int* vet, int currentSize, int indice, int aumento) {

	if(indice > currentSize - 1) return 0;

	if(currentSize == 0) return 0;

	vet[indice] += aumento;
	sobeHeap(vet,indice);
	return 1;
}


/**
 * Diminui a prioridade de um valor em uma fila de prioridade.
 * @param vet A fila de prioridade;
 * @param currentSize Tamanho da fila de prioridade;
 * @param indice Índice do valor que terá a prioridade diminuida;
 * @param aumento A quantidade que será decrementada do valor.
 * @return 1 caso a diminuição de prioridade tenha sido um sucesso, ou 0 caso contrário.
 */
int diminuirPrioIndice(int* vet, int currentSize, int indice, int decressimo) {

	if(indice > currentSize - 1) return 0;

	if(currentSize == 0) return 0;

	vet[indice] -= decressimo;
	desceHeap(vet,currentSize,indice);
	return 1;
}


/**
 * Retira o valor com maior prioridade em uma fila de prioridade.
 * @param vet A fila de prioridade;
 * @param currentSize Tamanho da fila de prioridade.
 * @return O valor com maior prioridade, ou -1 caso a fila de prioridade esteja vazia.
 */
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


/**
 * Insere um valor em uma fila de prioridade.
 * @param vet A fila de prioridade;
 * @param value O valor que será inserido;
 * @param currentSize Tamanho da fila de prioridade;
 * @param maxSize Tamanho máximo permitido da fila de prioridade.
 * @return 1 caso o valor for inserido com sucesso, ou 0 caso contrário.
 */
int inserirPrio(int* vet, int value, int* currentSize, int maxSize){
    if(*currentSize == maxSize)
        return 0;

    vet[*currentSize] = value;
    sobeHeap(vet, *currentSize);

    (*currentSize)++;
    return 1;
}


/**
 * Exibe no monitor uma fila de prioridade.
 * @param array A fila de prioridade;
 * @param currentSize Tamanho da fila de prioridade.
 * @return 
 */
void imprimirFila(int* array, int currentSize){
    for(int i = 0; i < currentSize; i++){
        printf("[%d]", array[i]);
    }
}
