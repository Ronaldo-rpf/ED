#include <stdio.h>
#include <stdlib.h>

void mergeCresc(int inicio, int final, int* vet);
void mergeDecres(int inicio, int final, int* vet);
void intercalaCresc(int inicio, int mid, int final, int* vet);
void intercalaDecres(int inicio, int mid, int final, int* vet);

int main() {
    int n;
    scanf("%d", &n);
    int* vet = (int*) calloc(n, sizeof(int));

    for(int i=0; i<n; i++){
        scanf("%d", &vet[i]);
    }
    
    int pares = 0, impares = 0;

    
    for(int i=0; i < n; i++){
        if (vet[i] % 2 == 0){
            pares++;
        }
    }
    for(int i=0; i<n; i++){
        if (vet[i] % 2 != 0){
            impares++;
        }
    }

    int* vetPar = (int*) calloc(pares, sizeof(int));
    int* vetImp = (int*) calloc(impares, sizeof(int));

    for(int i=0, j=0; i < n; i++){
        if (vet[i] % 2 == 0){
            vetPar[j] = vet[i];
            j++;
        }
    }
    for(int i=0, j=0; i<n; i++){
        if (vet[i] % 2 != 0){
            vetImp[j] = vet[i];
            j++;
        }
    }

    mergeCresc(0, pares-1, vetPar);
    mergeDecres(0, impares-1, vetImp);
    
    for(int i=0; i < pares; i++){
        vet[i] = vetPar[i];
    }

    for(int i=pares, j=0; impares != 0; i++, j++, impares--){
        vet[i] = vetImp[j];
    }

    for(int i=0; i< n; i++){
        printf("%d\n", vet[i]);
    }

    free(vetImp);
    free(vetPar);
    free(vet);
    return 0;
}

void mergeCresc(int inicio, int final, int* vet){
    if (inicio >= final){
        return;
    }
    int meio = (inicio + final) / 2;
    mergeCresc(inicio, meio, vet);
    mergeCresc(meio+1, final, vet);
    intercalaCresc(inicio, meio, final, vet);
}

void intercalaCresc(int inicio, int mid, int final, int* vet){
    int tamanho = final - inicio + 1;
    int *vetAux = (int*) calloc(tamanho, sizeof(int));
    int i = inicio, j = mid+1;
    int k=0;

    while(i <= mid && j<=final){
        if (vet[i] < vet[j]){
            vetAux[k] = vet[i];
            k++;
            i++;
        }
        else{
            vetAux[k] = vet[j];
            k++;
            j++;
        }
    }

    while (i<=mid){
        vetAux[k] = vet[i];
        k++;
        i++;
    }

    while(j<=final){
        vetAux[k] = vet[j];
        k++;
        j++;
    }

    for (int i = inicio, k=0; k < tamanho; i++, k++){
        vet[i] = vetAux[k];
    }


    free(vetAux);
}

void mergeDecres(int inicio, int final, int* vet){
    if (inicio >= final){
        return;
    }
    int meio = (inicio + final) / 2;
    mergeDecres(inicio, meio, vet);
    mergeDecres(meio+1, final, vet);
    intercalaDecres(inicio, meio, final, vet);
}

void intercalaDecres(int inicio, int mid, int final, int* vet){
    int tamanho = final - inicio + 1;
    int *vetAux = (int*) calloc(tamanho, sizeof(int));
    int i = inicio, j = mid+1;
    int k=0;

    while(i <= mid && j<=final){
        if (vet[i] > vet[j]){
            vetAux[k] = vet[i];
            k++;
            i++;
        }
        else{
            vetAux[k] = vet[j];
            k++;
            j++;
        }
    }

    while (i<=mid){
        vetAux[k] = vet[i];
        k++;
        i++;
    }

    while(j<=final){
        vetAux[k] = vet[j];
        k++;
        j++;
    }

    for (int i = inicio, k=0; k < tamanho; i++, k++){
        vet[i] = vetAux[k];
    }


    free(vetAux);
}