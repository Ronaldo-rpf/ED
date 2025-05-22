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
                    aux = aux->prtDir;
                }
                else{
                    aux = aux->prtEsq;
                }
            }
            aux = 
        }
    }
    else{
        return 1;
    }
}