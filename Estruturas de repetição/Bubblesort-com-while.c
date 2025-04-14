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

void bubblesort(int* vet, int tam){
    int aux;
    int flag = 1;
    while(flag){
        flag = 0;
        for(int i = 0; i < tam-1; i++){
            if (vet[i] > vet[i+1]){
                aux = vet[i];
                vet[i] = vet[i+1];
                vet[i+1] = aux;
                flag = 1;
            }
        }
    }
}
