#include <stdio.h>
#include <stdlib.h>

typedef struct dragao{
    int dias;
    double multa;
    double media;
}dragao;

void desceHeap(dragao *vet, int ultimoIndice, int indiceAserHipado);
dragao removerPrioridade (dragao *vet, int ultimoIndice);
void sobeHeap(dragao *vet, int indiceAserHipado);

int main (){
    dragao maior;
    int cont = 0, controleDias = 0, dias, multa, indice = 0, flag = 1, tamanho = 1;
    double multaTotal = 0;
    dragao *vet = (dragao*) malloc (tamanho * sizeof(dragao));
    if (vet == NULL){
        return 0;
    }
    printf("Inicio dia %d.\n", (cont + 1));
    scanf("%d %d", &dias, &multa);
    vet[tamanho-1].dias = dias;
    controleDias += dias;
    vet[tamanho-1].multa = multa;
    vet[tamanho-1].media = vet[tamanho-1].multa / vet[tamanho-1].dias;

    printf("Comecou a treinar um dragao.\n");
    maior = vet[0];
    maior.dias--;

    printf("Fim do dia %d.\n", (cont + 1));
    cont++;

    while (controleDias > cont){
        printf("Inicio dia %d.\n", (cont + 1));

        if(maior.dias == 0){
            printf("Terminou de treinar um dragao.\n");
            maior = removerPrioridade(vet, tamanho-1);
            tamanho--;
            printf("Comecou a treinar um dragao. %d %lf\n", maior.dias, maior.multa);
        }
        
        if(flag == 1){
            scanf("%d %d", &dias, &multa);
            if (dias == 0){
                flag = 0;
                continue;
            }
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
            sobeHeap(vet, 0, tamanho-1);
        }

        for (int i = 0; i < tamanho; i++){
            multaTotal += vet[i].multa;
            printf("Multa a pagar TOTAL = %.2lf\n", multaTotal);
        }
        
        maior.dias--;
        printf("Fim do dia %d.\n", (cont + 1));
        printf("Faltam %d dias parar terminar esse dragao.\n", maior.dias);
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

void sobeHeap(dragao *vet, int indiceAserHipado){
    if (indiceAserHipado == 0){
        return;
    }
    dragao aux;
    int pai = (indiceAserHipado - 1) / 2;
    if (vet[indiceAserHipado].media > vet[pai].multa && indiceAserHipado != ultimoIndice){
        aux = vet[indiceAserHipado];
        vet[indiceAserHipado] =  vet[pai];
        vet[pai] = aux;
        sobeHeap(vet, ultimoIndice, pai);
    }
}

dragao removerPrioridade (dragao *vet, int ultimoIndice){
    dragao prioridade;
    prioridade = vet[0];
    vet[0] = vet[ultimoIndice];
    dragao *temp = (dragao*) realloc (vet, ultimoIndice * sizeof(dragao));
    vet = temp;
    desceHeap(vet, ultimoIndice-1, 0);
    return prioridade;
}

