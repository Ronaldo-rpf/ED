#include "Pilha.h"

void printarPilha (tpPilha pilha){
    tpNo *aux = pilha.ptrPrim;
    while (aux != NULL){
        printf("\n----------------------\n");
        printf("Nome: %s\n", aux->aluno.nome);
        printf("Id: %d\n", aux->aluno.id);
        printf("\n----------------------\n");
        aux = aux->ptrProx;
    }
    return;
}

tpPilha initPilha(){
    tpPilha pilha;
    pilha.ptrPrim = NULL;
    pilha.ptrUlt = NULL;
    pilha.quantidadeItens = 0;
    return pilha;
}

int inserirAluno (tpPilha *pilha, tpItem aluno){
    tpNo *no = (tpNo*) malloc (sizeof(tpNo));
    if (no != NULL){
        pilha->ptrUlt->ptrProx = no;
        no->ptrAnt = pilha->ptrUlt;
        no->ptrProx = NULL;
        pilha->ptrUlt = no;
        pilha->quantidadeItens = pilha->quantidadeItens + 1;
        if (pilha->ptrPrim == NULL){
            pilha->ptrPrim = no;
        }
        return 0;
    }
    return 1;
}

//search e delete