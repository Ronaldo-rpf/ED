#include "Arvore.h"

tpNo* initArvore(){
    tpNo *arvore;
    arvore = NULL;
    return  arvore;
}

int insertArvore(tpNo *arvore, int num){
    tpNo *no = malloc (sizeof(tpNo));
    if (no != NULL){
        if (arvore == NULL){
            arvore->num = num;
            arvore->prtDir = NULL;
            arvore->prtEsq = NULL;
            return 0;
        }
        else{
            tpNo *aux = arvore;
            while(aux != NULL){
                if (aux->num < num){
                    if(aux->prtDir == NULL){
                        aux->prtDir = no;
                        no->num = num;
                        no->prtDir = NULL;
                        no->prtEsq = NULL;
                        break;
                    }
                    aux = aux->prtDir;
                }
                else{
                    if (aux->prtEsq == NULL){
                        aux->prtEsq = no;
                        no->num = num;
                        no->prtDir = NULL;
                        no->prtEsq = NULL;
                        break;
                    }
                    aux = aux->prtEsq;
                }
            } 
        }
    }
    else{
        return 1;
    }
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
        return insertArvoreR((*arvore)->prtDir, num);
        //inseri na direita
    }
    else if ((*arvore)->prtDir == NULL && aux->prtEsq == NULL){

    }
}



int alturaArvore(tpNo *arvore){

}

int searchArvore(tpNo *arvore, int valor){
    if (arvore->prtDir == NULL && arvore->prtEsq == NULL){
        return -1;
    }
    else if (arvore->num == valor){
        return arvore->num;
    }
    else if (arvore->num < valor){
        arvore = arvore->prtDir;
        return searchArvore(arvore, valor);
    }
    else{
        arvore = arvore->prtEsq;
        return searchArvore(arvore, valor);
    }
}
