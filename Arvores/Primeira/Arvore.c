#include "Arvore.h"

tpNo* initArvore(){
    tpNo *arvore;
    arvore = NULL;
    return arvore;
}

int insertArvoreR(tpNo **arvore, int num){
    if ((*arvore) == NULL){
        tpNo *no = (tpNo*) malloc (sizeof(tpNo));
        if (no != NULL){
            no->num = num;
            no->prtDir = NULL;
            no->prtEsq = NULL;
            (*arvore) = no;
            return 0;
        }
        return 1;
    }
    else if ((*arvore)->num <= num){
        return insertArvoreR(&((*arvore)->prtDir), num);
    }
    else{
        return insertArvoreR(&((*arvore)->prtEsq), num);
    }
}

int alturaArvore(tpNo *arvore){
    if (arvore == NULL){
        return -1;
    }
    else if (arvore->prtDir == NULL && arvore->prtEsq == NULL){
        return 0;
    }
    else if (arvore->prtDir == NULL && arvore->prtEsq != NULL){
        int esquerda = 1 + alturaArvore(arvore->prtEsq);
        return esquerda;
    }
    else if (arvore->prtDir != NULL && arvore->prtEsq == NULL){
        int direita = 1 + alturaArvore(arvore->prtDir);
        return direita;
    }
    else{
        int esquerda = 1 + alturaArvore(arvore->prtEsq);
        int direita = 1 + alturaArvore(arvore->prtDir);
        if (esquerda > direita){
            return esquerda;
        }
        else{
            return direita;
        }
    }
}

int searchArvoreR(tpNo *arvore, int valor){
    if (arvore == NULL){
        return -1;
    }
    else if (arvore->num == valor){
        return arvore->num;
    }
    else if (arvore->prtDir == NULL && arvore->prtEsq == NULL){
        return -1;
    }
    else if (arvore->num < valor){
        arvore = arvore->prtDir;
        return searchArvoreR(arvore, valor);
    }
    else{
        arvore = arvore->prtEsq;
        return searchArvoreR(arvore, valor);
    }
}

tpNo* deletarAux(tpNo **arvore, int num){
    if ((*arvore) == NULL){
        return NULL;
    }
    else {
        if ((*arvore)->num == num){
            printf("O numero foi encontrado.\n");
            if ((*arvore)->prtDir == NULL && (*arvore)->prtEsq == NULL){
                printf("Numero deletado: %d\n", (*arvore)->num);
                free(*arvore);
                return NULL;
            }
            else{
                if ((*arvore)->prtDir != NULL && (*arvore)->prtEsq != NULL){
                    tpNo* aux = (*arvore)->prtEsq;
                    while (aux->prtDir != NULL){
                        aux = aux->prtDir;
                    }
                    printf("Valores trocados: %d e %d\n", (*arvore)->num, aux->num);
                    (*arvore)->num = aux->num;
                    aux->num = num;
                    (*arvore)->prtEsq = deletarAux(&((*arvore)->prtEsq), num);
                    return (*arvore);
                }
                else{
                    tpNo* aux;
                    if ((*arvore)->prtDir != NULL){
                        aux = (*arvore)->prtDir;
                        printf("Numero deletado: %d\n", (*arvore)->num);
                        free(*arvore);
                    }
                    else{
                        aux = (*arvore)->prtEsq;
                        printf("Numero deletado: %d\n", (*arvore)->num);
                        free(*arvore);
                    }
                    return aux;
                }
            }
        }
        else{
            if ((*arvore)->num <= num){
                (*arvore)->prtDir = deletarAux(&((*arvore)->prtDir), num);
            }
            else{
                (*arvore)->prtEsq = deletarAux(&((*arvore)->prtEsq), num);
            }
            return (*arvore);
        }
    }
}

void imprimirNaoOrdenada(tpNo *arvore){
    if (arvore != NULL){
        printf("%d ", arvore->num);
        imprimirNaoOrdenada(arvore->prtEsq);
        imprimirNaoOrdenada(arvore->prtDir);
    }
}

void imprimirOrdenada(tpNo *arvore){
    if (arvore != NULL){
        imprimirOrdenada(arvore->prtEsq);
        printf("%d ", arvore->num);
        imprimirOrdenada(arvore->prtDir);
    }
}

