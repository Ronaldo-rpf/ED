#include <stdio.h>
#include <stdlib.h>

typedef struct dragao{
    int dias;
    int multa;
    double media;
}dragao;

void desceHeap(dragao *vet, int ultimoIndice, int indiceAserHipado);
void sobeHeap(dragao *vet, int indiceAserHipado);

int main (){
    dragao maior;
    int cont = 0, controleDias = 0, dias, multa, flag = 1, tamanho = 0, indice = 0;
    double multaTotal = 0;
    dragao *vet = (dragao*) calloc (tamanho, sizeof(dragao));
    if (vet == NULL){
        return 0;
    }
    scanf("%d %d", &dias, &multa);
    maior.dias = dias;
    maior.multa = multa;
    maior.media = maior.multa / maior.dias;
    controleDias += dias;
    maior.dias--;


    while (controleDias > cont){
        cont++;
        if(maior.dias == 0 && cont != 1){
            maior = vet[0];
            vet[0] = vet[indice-1];
            vet[indice-1].media = 0;
            indice--;
            desceHeap(vet, indice, 0);
        }
        
        if(flag == 1){
            scanf("%d %d", &dias, &multa);
            if (dias != 0){
                tamanho++;
                dragao *temp = (dragao*) realloc (vet, tamanho * sizeof(dragao));
                if (temp == NULL){
                    return 0;
                }
                vet = temp;
                vet[indice].dias = dias;
                controleDias += dias;
                vet[indice].multa = multa;
                vet[indice].media = vet[indice].multa / vet[indice].dias;
                sobeHeap(vet, indice);
                indice++;
            }
            else{
                flag = 0;
            }
        }
        for (int i = 0; i < indice; i++){
            multaTotal += vet[i].multa;
        }
        
        maior.dias--;
    }
    printf("%lf\n", multaTotal);

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

void sobeHeap(dragao *vet, int indiceAserHipado){
    if (indiceAserHipado == 0){
        return;
    }
    dragao aux;
    int pai = (indiceAserHipado - 1) / 2;
    if (vet[indiceAserHipado].media > vet[pai].media){
        aux = vet[indiceAserHipado];
        vet[indiceAserHipado] =  vet[pai];
        vet[pai] = aux;
        sobeHeap(vet, pai);
    }
}
