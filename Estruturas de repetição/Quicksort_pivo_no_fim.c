#include <stdio.h>
#include <stdlib.h>

int particiona(int*, int, int);
void quicksort(int*, int, int);

int main (){
    int *vet = (int*) malloc (10 * sizeof(int));

    for (int i = 0; i < 10; i++){
        printf("Valor do indice %d: ", i);
        scanf("%d", &vet[i]);
    }
    printf("\nVetor sem ordenacao:\n\n");
    for (int i = 0; i < 10; i++){
        printf("%d ", vet[i]);
    }

    quicksort(vet, 0, 9);

    printf("\n\nVetor apos a ordenacao (Quick sort):\n\n");
    for (int i = 0; i < 10; i++){
        printf("%d ", vet[i]);
    }

    free(vet);
    return 0;
}

void quicksort(int *vet, int inicio, int fim){
    if (inicio >= fim){
        return;
    }
    int indicePivo = particiona(vet, inicio, fim);
    quicksort(vet, inicio, indicePivo-1);
    quicksort(vet, indicePivo+1, fim);
}

int particiona (int *vet, int inicio, int fim){
    int i = inicio - 1;
    int j = inicio;
    int aux;
    int pivo = vet[fim];

    for (j = inicio; j < fim; j++){
        if (vet[j] <= pivo){
            i++;
            aux = vet[j];
            vet[j] = vet[i];
            vet[i] = aux;
        }
    }
    // se i começa com -1, logo, no fim vai ta a um indice A MENOS do meio onde o pivo deve estar.
    aux = vet[i+1];
    vet[i+1] = pivo;
    vet[fim] = aux;
    
    return (i + 1);
}

/*
int particiona (int *vet, int inicio, int fim){
    int i = inicio;
    int j = inicio;
    int aux;
    int pivo = vet[fim];

    for (j = inicio; j < fim; j++){
        if (vet[j] <= pivo){
            aux = vet[j];
            vet[j] = vet[i];
            vet[i] = aux;
            i++;
        }
    }
    // i começa com 0, logo, no fim, vai estar logo acima de onde o pivo deveria estar.
    aux = vet[i];
    vet[i] = pivo;
    vet[fim] = aux;
    
    return i;
}
*/
