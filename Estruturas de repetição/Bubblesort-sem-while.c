#include <stdio.h>
#include <stdlib.h>

void bubblesort(int*, int);

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

    bubblesort(vet, 10);

    printf("\n\nVetor apos a ordenacao (Bubble Sort):\n\n");
    for (int i = 0; i < 10; i++){
        printf("%d ", vet[i]);
    }

    free(vet);
    return 0;
}

void bubblesort(int *vet, int tam){
    int aux;
    for (int i = 0; i < tam - 1; i++){
        for (int j = 0; j < tam - i - 1; j++){
            if (vet[j] > vet[j+1]){
                aux = vet[j];
                vet[j] = vet[j+1];
                vet[j+1] = aux;
            }
        }
    }
}
