#include "heap.h"

void desceHeap(int *vet, int ultimoIndice, int indiceAserHipado){
    int maior, aux;
    int esquerda = 2*indiceAserHipado + 1;
    int direita = 2*indiceAserHipado + 2;
    if (esquerda <= ultimoIndice && vet[esquerda] > vet[indiceAserHipado]){
        maior = esquerda;
    }
    else{
        maior = indiceAserHipado;
    }
    if (direita <= ultimoIndice && vet[direita] > vet[maior]){
        maior = direita;
    }
    if (maior != indiceAserHipado){
        aux = vet[maior];
        vet[maior] = vet[indiceAserHipado];
        vet[indiceAserHipado] = aux;
        desceHeap(vet, ultimoIndice, maior);
    }
}

void constroiHeap (int *vet, int ultimoIndice){
    for (int i = (ultimoIndice/2); i >= 0; i--){
        desceHeap(vet, ultimoIndice, i);
    }
}

int removerPrioridade (int *vet, int ultimoIndice){
    int prioridade;
    if (ultimoIndice == 0){
        printf("Fila so possui um unico elemento.\n");
        printf("A fila acabou.\n");
        prioridade = vet[0];
        free(vet);
        return prioridade;
    }
    prioridade = vet[0];
    vet[0] = vet[ultimoIndice];
    int *temp = (int*) realloc (vet, ultimoIndice * sizeof(int));
    if (temp == NULL){
        printf("Erro na realocacao de memoria.\n");
        return -1;
    }
    vet = temp;
    desceHeap(vet, ultimoIndice-1, 0);
    return prioridade;
}

void inserirItem (int *vet, int item){

    

}

void sobeHeap (int *vet, int indiceAserHipado){
    if (indiceAserHipado == 0){
        return;
    }
    int pai = (indiceAserHipado - 1) / 2;
    int aux;
    if (vet[pai] < vet[indiceAserHipado]){
        aux = vet[pai];
        vet[pai] = vet[indiceAserHipado];
        vet[indiceAserHipado] = aux;
        sobeHeap(vet, pai);
    }
}
