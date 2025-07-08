#include <stdio.h>
#include <stdlib.h>

typedef struct dragao{
    int dias;
    double multa;
    double media;
}dragao;

int qualoMaior(dragao *vet, int tamanho);

int main (){
    int cont = 0, controleDias = 0, total, maior, dias, multa, tamanho, indice = 0;
    double multaTotal = 0;
    scanf("%d", &tamanho);
    total = tamanho;
    dragao *vet = (dragao*) calloc (tamanho, sizeof(dragao));
    if (vet == NULL){
        return 0;
    }
    if(total != 0){
        scanf("%d %d", &dias, &multa);
        vet[indice].dias = dias;
        controleDias += dias;
        vet[indice].multa = multa;
        vet[indice].media = vet[indice].multa / vet[indice].dias;
        indice++;
        total--;
    }
    maior = qualoMaior(vet, tamanho); 
    vet[maior].dias--; 
    cont++;

    while (controleDias > cont){

        if(vet[maior].dias == 0){
            vet[maior].media = 0;
            vet[maior].multa = 0;
            maior = qualoMaior(vet, tamanho);
        }
        
        if(total != 0){
            scanf("%d %d", &dias, &multa);
            vet[indice].dias = dias;
            controleDias += dias;
            vet[indice].multa = multa;
            vet[indice].media = vet[indice].multa / vet[indice].dias;
            indice++;
            total--;
        }
        
        for (int i = 0; i < tamanho; i++){
            if (i == maior){
                continue;
            }
            multaTotal += vet[i].multa;
        }
        vet[maior].dias--;
        cont++;
    }

    printf("%lf", multaTotal);
    free(vet);
    return 0;
}

int qualoMaior(dragao *vet, int tamanho){
    int maior = 0;
    for (int i =0; i<tamanho; i++){
        if (vet[i].media > vet[maior].media){
            maior = i;
        }
    }
    return maior;
}
