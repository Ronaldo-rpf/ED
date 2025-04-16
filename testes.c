#include <stdio.h>
#include <stdlib.h>

int busca (int *vet, int elemento, int tamanho);

int main (){
    int vet[10] = {2,5,6,4,23,232,65,7,8,0};

    int aux = busca(vet, 65, 10);
    printf("%d", aux);


    return 0;
}

int busca (int *vet, int elemento, int tamanho){
    int inicio = 0;
    int fim = tamanho - 1;
    int meio = (inicio + fim) / 2;

    while (inicio <= fim){
        if (vet[meio] == elemento){
            return meio;
        }
        else if (vet[meio] > elemento){
            fim = meio - 1;
            meio = (inicio + fim) / 2;
        }
        else{
            inicio = meio + 1;
            meio = (inicio + fim) / 2;
        }
    }

    return -1;
}
