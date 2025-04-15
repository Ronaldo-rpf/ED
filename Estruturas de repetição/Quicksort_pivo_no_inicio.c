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
    int i = inicio;
    int j = inicio + 1;
    int aux;
    int pivo = vet[inicio];

    for (j = inicio + 1; j <= fim; j++){
        if (vet[j] <= pivo){
            i++;
            aux = vet[j];
            vet[j] = vet[i];
            vet[i] = aux;
        }
    }
    // i começa onde esta o pivo, por isso incrementamos logo apos achar um valor menor.
    aux = vet[i];
    vet[i] = pivo;
    vet[inicio] = aux;
    
    return i;
}

/*
int particiona (int *vet, int inicio, int fim){
    int i = inicio + 1;
    int j = inicio + 1;
    int aux;
    int pivo = vet[inicio];

    for (j = inicio + 1; j <= fim; j++){
        if (vet[j] <= pivo){
            aux = vet[j];
            vet[j] = vet[i];
            vet[i] = aux;
            i++;
        }
    }
    // i começa em cima do pivo, e no final, precisa diminuir 1 pra onde o pivo irá.
    aux = vet[i - 1];
    vet[i - 1] = pivo;
    vet[inicio] = aux;
    
    return (i - 1);
}
*/
