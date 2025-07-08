#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

int main (){
    //REMOVER
    int tamanho;
    printf("Tamanho do vetor: ");
    scanf("%d", &tamanho);
    int *vet = (int*) calloc (tamanho, sizeof(int));
    for (int i = 0; i < tamanho; i++){
        scanf("%d", &vet[i]);
    }
    constroiHeap(vet, tamanho - 1);
    for (int i = 0; i < tamanho; i++){
        printf("%d ", vet[i]);
    }
    int prio = removerPrioridade(vet, tamanho - 1);
    tamanho--;
    printf("Prioridade: %d\n\n", prio);
    for (int i = 0; i < tamanho; i++){
        printf("%d ", vet[i]);
    }
    printf("\n");

    //INSERIR

    



    free(vet);
    printf("FIM\n\n");
    return 0;
}
