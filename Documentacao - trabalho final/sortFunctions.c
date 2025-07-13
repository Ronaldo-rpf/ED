#include "sortFunctions.h"

/**
 * Ordena um vetor utilizando o método do Bubble Sort.
 * @param vet O vetor que será ordenado;
 * @param tamanho O tamanho do vetor que será ordenado.
 * @return 
 */
void bubbleSort(int* vet, int tamanho){
    int aux;
    for(int i = 0; i < tamanho - 1; i++){
        for(int j = 0; j < tamanho - i - 1; j++){
            if(vet[j] > vet[j+1]){
                aux = vet[j];
                vet[j] = vet[j+1];
                vet[j+1] = aux;
            }
        }
    }
}


/**
 * Ordena um vetor utilizando o método do Merge Sort.
 * @param vet O vetor que será ordenado;
 * @param i O primeiro índice do vetor;
 * @param f O último índice do vetor.
 * @return 
 */
void mergeSort(int* vet, int i, int f){
    if(i>=f)
        return;

    int meio = (f + i) / 2;    
    mergeSort(vet, i, meio);
    mergeSort(vet, meio + 1, f);
    intercala(vet, i, meio, f);
}


/**
 * Intercala crescentemente os valores dos índices de um vetor em um intervalo.
 * @param vet O vetor que será ordenado;
 * @param init Índice do início do intervalo;
 * @param meio Índice do meio do intervalo;
 * @param fim Índice do final do intervalo.
 * @return 
 */
void intercala(int* vet, int init, int meio, int fim){
    int* vetAux = (int*)malloc(sizeof(int) * (unsigned long long)(fim - init + 1));
    int aux = 0;

    int v1 = init;
    int v2 = meio+1;
    
    while(v1 <= meio && v2 <= fim){
        if(vet[v1] <= vet[v2]){
            vetAux[aux] = vet[v1];
            aux++;
            v1++;
        }
        else{
            vetAux[aux] = vet[v2];
            aux++;
            v2++;
        }
    }

    while(v1 <= meio){
        vetAux[aux] = vet[v1];
        v1++;
        aux++;
    }

    while(v2 <= fim){
        vetAux[aux] = vet[v2];
        v2++;
        aux++;
    }

    aux = 0;
    for(int x = init; x <= fim; x++){
        vet[x] = vetAux[aux];
        aux++;
    }

    free(vetAux);
}


/**
 * Ordena um vetor utilizando o método do Quick Sort.
 * @param vet O vetor que será ordenado;
 * @param i O primeiro índice do vetor;
 * @param f O último índice do vetor.
 * @return 
 */
void quickSort(int* vet, int i, int f){
    if(i >= f)
        return;

    int pivot = particiona(vet, i, f);
    quickSort(vet, i, pivot - 1);
    quickSort(vet, pivot + 1, f);    
}


/**
 * Organiza o vetor de forma que, em um intervalo, e a partir de um pivô, todos os valores maiores que o mesmo ficam à sua direita, e todos os menores, à sua esquerda, deixando o pivô na posição correta no vetor.
 * @param vet O vetor que será ordenado;
 * @param init Índice do início do intervalo;
 * @param fim Índice do final do intervalo.
 * @return O índice final do pivô.
 */
int particiona(int* vet, int init, int fim){

    int v1 = init-1;
    int v2 = init;

    int pivot = vet[fim];

    int aux;
    for(; v2 < fim;v2++){
        if(vet[v2] < pivot){
            v1++;
            aux = vet[v2];
            vet[v2] = vet[v1];
            vet[v1] = aux;
        }
    }

    v1++;
    vet[fim] = vet[v1];
    vet[v1] = pivot;
    
    return v1;
}


/**
 * Ordena um vetor utilizando o método do Quick Sort.
 * @param vet O vetor que será ordenado;
 * @param i O primeiro índice do vetor;
 * @param f O último índice do vetor.
 * @return 
 */
void quickSortRandom(int* vet, int i, int f){
    if(i >= f)
        return;

    int pivot = particionaRandom(vet, i, f);
    quickSortRandom(vet, i, pivot - 1);
    quickSortRandom(vet, pivot + 1, f);    
}


/**
 * Organiza o vetor de forma que, em um intervalo, e a partir de um pivô, todos os valores maiores que o mesmo ficam à sua direita, e todos os menores, à sua esquerda, deixando o pivô na posição correta no vetor.
 * @param vet O vetor que será ordenado;
 * @param init Índice do início do intervalo;
 * @param fim Índice do final do intervalo.
 * @return O índice final do pivô.
 */
int particionaRandom(int* vet, int init, int fim){
    
    int v1 = init-1;
    int v2 = init;

    int randomindex = init + (rand() % (fim - init + 1));

    int pivot = vet[randomindex];

    int aux;
    for(; v2 <= fim; v2++){
        if(v2 == randomindex){}
        else if(vet[v2] < pivot){
            v1++;
            if(v1!=randomindex){
                aux = vet[v2];
                vet[v2] = vet[v1];
                vet[v1] = aux;    
            }
            else{
                aux = vet[v2];
                vet[v2] = vet[v1+1];
                vet[v1+1] = vet[v1];
                vet[v1] = aux;
                randomindex++;
            }
        }
    }

    v1++;
    vet[randomindex] = vet[v1];
    vet[v1] = pivot;
    
    return v1;
}



