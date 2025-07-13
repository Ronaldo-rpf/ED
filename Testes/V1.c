#include <stdio.h>
#include <stdlib.h>

typedef struct dragao{
    int dias;
    double multa;
    double media;
}dragao;

void desceHeap(dragao *vet, int ultimoIndice, int indiceAserHipado);
void sobeHeap(dragao *vet, int indiceAserHipado);

int main (){
    dragao maior;
    int cont = 0, controleDias = 0, dias, multa, flag = 1, tamanho = 0;
    double multaTotal = 0;
    dragao *vet = (dragao*) malloc (tamanho * sizeof(dragao));
    if (vet == NULL){
        return 0;
    }
    scanf("%d %d", &dias, &multa);
    maior.dias = dias;
    maior.multa = multa;
    maior.media = maior.multa / maior.dias;
    controleDias += dias;
    maior.dias--;

    cont++;

    while (controleDias > cont){

        if(maior.dias == 0){
            maior = vet[0];
            vet[0] = vet[tamanho-1];
            tamanho--;
            dragao *temp = (dragao*) realloc (vet, tamanho * sizeof(dragao));
            if (temp == NULL && tamanho != 0){
                return 0;
            }
            vet = temp;
            desceHeap(vet, tamanho-1, 0);
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
                vet[tamanho-1].dias = dias;
                controleDias += dias;
                vet[tamanho-1].multa = multa;
                vet[tamanho-1].media = vet[tamanho-1].multa / vet[tamanho-1].dias;
                sobeHeap(vet, tamanho-1);
            }
            else{
                flag = 0;
            }
        }
        for (int i = 0; i < tamanho; i++){
            multaTotal += vet[i].multa;
        }
        
        maior.dias--;
        cont++;
    }
    printf("%.2lf\n", multaTotal);
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
