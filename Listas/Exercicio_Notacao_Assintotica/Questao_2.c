#include <stdio.h>
#include <stdlib.h>

int maximo(int *vet, int tamanho);

int main (){
    int vetor[10] = {1, 2, 300, 7, 8, 9, 20, 4, 3, 2};
    int valor = maximo(vetor, 10);
    printf("Valor maximo: %d\n\n", valor);

    return 0;
}

int maximo(int *vet, int tamanho){
    if (tamanho == 0){
        return -1000;
    }
    int max = vet[tamanho - 1];
    int aux = maximo(vet, tamanho-1);
    if (aux > max){
        max = aux;
    }
    return max;
}
