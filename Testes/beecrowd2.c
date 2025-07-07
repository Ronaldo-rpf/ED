#include <stdio.h>
#include <stdlib.h>

typedef struct dragao{
    int dias;
    double multa;
    double media;
}dragao;

int qualoMaior(dragao *vet, int tamanho);

int main (){
    dragao aux;
    int cont = 0, controleDias = 0, total, maior, dias, multa, tamanho;
    double multaTotal = 0;
    printf("Quantos dragaoes terao ao todo? \n");
    scanf("%d", &tamanho);
    total = tamanho;
    dragao *vet = (dragao*)calloc (tamanho, sizeof(dragao));
    if (vet == NULL){
        return 0;
    }
    printf("Inicio dia %d.\n", (cont + 1));
    if(total != 0){
        scanf("%d %d", &dias, &multa);
        vet[cont].dias = dias;
        controleDias += dias;
        vet[cont].multa = multa;
        vet[cont].media = vet[cont].multa / vet[cont].dias;
        total--;
    }
    maior = qualoMaior(vet, tamanho);
    printf("Comecou a treinar o indice %d.\n", maior);   
    vet[maior].dias--; 
    printf("Fim do dia %d.\n", (cont+1));
    
    cont++;

    while (controleDias > cont){
        printf("Inicio dia %d.\n", (cont + 1));

        if(vet[maior].dias == 0){
            printf("terminou de treinar o dragao de indice %d.\n", maior);
            aux = vet[tamanho-1];
            vet[maior] = aux;
            tamanho--;
            vet = (dragao*) realloc (vet, tamanho);
            if (vet == NULL){
                return 0;
            }
            maior = qualoMaior(vet, tamanho);
            printf("comeca hoje cedo ja a treinar o de indice %d\n", maior);

        }

        for (int i = 0; i < tamanho; i++){
            if (i == maior){
                continue;
            }
            multaTotal += vet[i].multa;
        }

        printf("Multa acumulada ate esse dia %lf\n", multaTotal);
        if(total != 0){
            scanf("%d %d", &dias, &multa);
            vet[cont].dias = dias;
            controleDias += dias;
            vet[cont].multa = multa;
            vet[cont].media = vet[cont].multa / vet[cont].dias;
            total--;
        }
        
        
        
        printf("Fim do dia %d.\n", (cont+1));
        vet[maior].dias--;
        cont++;
    }

    printf("Multa a pagar = %lf\n", multaTotal);
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
