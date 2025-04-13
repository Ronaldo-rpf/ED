#include <stdio.h>
#include <stdlib.h>

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

    mergesort(vet, 0, 9);

    printf("\n\nVetor apos a ordenacao (Merge Sort):\n\n");
    for (int i = 0; i < 10; i++){
        printf("%d ", vet[i]);
    }

    free(vet);
    return 0;
}

void mergesort (int *vetor, int left, int right){
    if (left >= right){
        return;
    }
    int mid = (left + right) / 2;
    mergesort(vetor, left, mid);
    mergesort(vetor, mid+1, right);
    merge(vetor, left, mid, right);
}

void merge(int *vetor, int left, int mid, int right){
    int i = left, j = mid + 1, k = 0;
    int tamanho = (right - left) + 1;
    int *vaux = (int*) calloc(tamanho, sizeof(int));

    while(i <= mid && j <= right){
        if (vetor[i] < vetor[j]){
            vaux[k] = vetor[i];
            k++;
            i++;
        }
        else{
            vaux[k] = vetor[j];
            k++;
            j++;
        }
    }

    while(i <= mid){
        vaux[k] = vetor[i];
        k++;
        i++;
    }

    while(j <= right){
        vaux[k] = vetor[j];
        k++;
        j++;
    }

    for (i = left, k = 0; k < tamanho; i++, k++){
        vetor[i] = vaux[k];
    }

    free (vaux);
}