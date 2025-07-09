#include <stdio.h>
#include <stdlib.h>

typedef struct dragao{
    int dias;
    double multa;
    double media;
}dragao;

void desceHeap(dragao *vet, int ultimoIndice, int indiceAserHipado);
void constroiHeap (dragao *vet, int ultimoIndice);
dragao removerPrioridade (dragao *vet, int ultimoIndice);

int main (){
    dragao maior;
    int cont = 0, controleDias = 0, total, dias, multa, tamanho, indice = 0;
    double multaTotal = 0;
    scanf("%d", &tamanho);
    total = tamanho;
    dragao *vet = (dragao*) calloc (tamanho, sizeof(dragao));
    if (vet == NULL){
        return 0;
    }
    printf("Inicio dia %d.\n", (cont + 1));
    if(total != 0){
        scanf("%d %d", &dias, &multa);
        vet[indice].dias = dias;
        controleDias += dias;
        vet[indice].multa = multa;
        vet[indice].media = vet[indice].multa / vet[indice].dias;
        constroiHeap(vet, tamanho-1);
        total--;
    }
    maior = removerPrioridade(vet, tamanho-1);
    tamanho--;
    maior.dias--; 
    
    cont++;

    while (controleDias > cont){

        if(maior.dias == 0){
            maior = removerPrioridade(vet, tamanho-1);
            tamanho--;
        }
        
        if(total != 0){
            scanf("%d %d", &dias, &multa);
            vet[indice].dias = dias;
            controleDias += dias;
            vet[indice].multa = multa;
            vet[indice].media = vet[indice].multa / vet[indice].dias;
            constroiHeap(vet, tamanho-1);
            total--;
        }
        
        for (int i = 0; i < tamanho; i++){
            multaTotal += vet[i].multa;
        }
        
        maior.dias--;
        cont++;
    }

    printf("Multa a pagar TOTAL = %.2lf\n", multaTotal);
    free(vet);
    return 0;
}

void desceHeap(dragao *vet, int ultimoIndice, int indiceAserHipado){
    dragao aux;
    int maior;
    int esquerda = 2*indiceAserHipado + 1;
    int direita = 2*indiceAserHipado + 2;
    if (esquerda <= ultimoIndice && vet[esquerda].media > vet[indiceAserHipado].media){
        maior = esquerda;
    }
    else{
        maior = indiceAserHipado;
    }
    if (direita <= ultimoIndice && vet[direita].media > vet[maior].media){
        maior = direita;
    }
    if (maior != indiceAserHipado){
        aux = vet[maior];
        vet[maior] = vet[indiceAserHipado];
        vet[indiceAserHipado] = aux;
        desceHeap(vet, ultimoIndice, maior);
    }
}

void constroiHeap (dragao *vet, int ultimoIndice){
    for (int i = (ultimoIndice/2); i >= 0; i--){
        desceHeap(vet, ultimoIndice, i);
    }
}

dragao removerPrioridade (dragao *vet, int ultimoIndice){
    dragao prioridade;
    prioridade = vet[0];
    vet[0] = vet[ultimoIndice];
    dragao *temp = (dragao*) realloc (vet, ultimoIndice * sizeof(int));
    vet = temp;
    desceHeap(vet, ultimoIndice-1, 0);
    return prioridade;
}
