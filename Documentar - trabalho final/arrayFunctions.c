#include <stdlib.h>
#include <stdio.h>
#include "arrayFunctions.h"

int* initArray(int tamanho){
    return ((int*)malloc(sizeof(int)*tamanho));
}

int inserirElemento(int* array, int valor, int* currentSize, int maxSize){
    if(*currentSize == maxSize){
        return 0;
    }

    array[*currentSize] = valor;
    (*currentSize)++;
    return 1;
}

int removerElemento(int* array, int valor, int* currentSize){
    for(int i = 0; i < *currentSize; i++){
        if(array[i] == valor){
            (*currentSize)--;
            for(int j = i; j < *currentSize; j++){
                array[j] = array[j+1];
            }
            return 1;
        }
    }

    return 0;
}

int editarElemento(int* array, int valorAtual, int valorNovo,  int currentSize){
    for(int i = 0; i < currentSize; i++){
        if(array[i] == valorAtual){
            array[i] = valorNovo;
            return 1;
        }
    }

    return 0;
}


int pesquisarElemento(int* array, int valor, int currentSize){
    for(int i = 0; i < currentSize; i++){
        if(array[i] == valor){
            return i;
        }
    }

    return -1;
}

void imprimirVetor(int* array, int currentSize){
    for(int i = 0; i < currentSize; i++){
        printf("[%d]", array[i]);
    }
}