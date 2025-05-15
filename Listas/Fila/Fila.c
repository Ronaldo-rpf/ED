#include "Fila.h"

void printarFila (tpFila fila){
    tpNo *aux = fila.ptrPrim;
    while (aux != NULL){
        printf("\n----------------------\n");
        printf("Nome: %s", aux->aluno.nome);
        printf("Id: %d\n", aux->aluno.id);
        printf("----------------------\n");
        aux = aux->ptrProx;
    }
    return;
}

tpFila initFila(){
    tpFila fila;
    fila.quantidadeItens = 0;
    fila.ptrPrim = NULL;
    fila.ptrUlt = NULL;
    return fila;
}

int enqueue (tpFila *fila, tpItem aluno){
    tpNo *no = (tpNo*) malloc (sizeof(tpNo));
    if (no != NULL){
        no->aluno = aluno;
        no->ptrAnt = NULL;
        no->ptrProx = fila->ptrPrim;
        if (fila->ptrPrim == NULL){
            fila->ptrUlt = no;
        }
        else{
            fila->ptrPrim->ptrAnt = no;
        }
        fila->ptrPrim = no;
        fila->quantidadeItens = fila->quantidadeItens + 1;
        return 0;
    }    
    return 1;
}

tpItem searchItemFila (tpFila fila, unsigned int id){
    tpItem item;
    tpNo *aux = fila.ptrPrim;
    while (aux != NULL){
        if (aux->aluno.id == id){
            item.id = id;
            strcpy(item.nome, aux->aluno.nome);
            return item;
        }
        aux = aux->ptrProx;
    }
    item.id = 0;
    return item;
}

int deleteFila (tpFila *fila, unsigned int id){
    tpNo *aux = fila->ptrUlt;
    while (aux != NULL){
        if (aux->aluno.id == id){
            aux = aux->ptrAnt;
            free(fila->ptrUlt);
            if (aux == NULL){
                fila->ptrUlt = NULL;
                fila->ptrPrim = NULL;
                printf("Quantidade antes da remocao: %d\n", fila->quantidadeItens);
                fila->quantidadeItens = fila->quantidadeItens - 1;
                printf("Quantidade apos a remocao: %d\n", fila->quantidadeItens);
                return 0;
            }
            aux->ptrProx = NULL;
            fila->ptrUlt = aux;
            printf("Quantidade antes da remocao: %d\n", fila->quantidadeItens);
            fila->quantidadeItens = fila->quantidadeItens - 1;
            printf("Quantidade apos a remocao: %d\n", fila->quantidadeItens);
            return 0;
        }
        else{
            aux = aux->ptrAnt;
            free(fila->ptrUlt);
            if (aux == NULL){
                fila->ptrUlt = NULL;
                fila->ptrPrim = NULL;
                printf("Quantidade antes da remocao: %d\n", fila->quantidadeItens);
                fila->quantidadeItens = fila->quantidadeItens - 1;
                printf("Quantidade apos a remocao: %d\n", fila->quantidadeItens);
                break;
            }
            aux->ptrProx = NULL;
            fila->ptrUlt = aux;
            printf("Quantidade antes da remocao: %d\n", fila->quantidadeItens);
            fila->quantidadeItens = fila->quantidadeItens - 1;
            printf("Quantidade apos a remocao: %d\n", fila->quantidadeItens);
            printf("Aluno nao encontrado ainda.\n");
        }
    }
    return 1;
}

void dequeue (tpFila *fila){
    tpNo *aux = fila->ptrUlt;
    if (aux != NULL){
        printf("Aluno deletado: %s", aux->aluno.nome);
        printf("Matricula: %d\n", aux->aluno.id);
        aux = aux->ptrAnt;
        free(fila->ptrUlt);
        if (aux == NULL){
            fila->ptrPrim = NULL;
            fila->ptrUlt = NULL;
            printf("Quantidade antes da remocao: %d\n", fila->quantidadeItens);
            fila->quantidadeItens = fila->quantidadeItens - 1;
            printf("Quantidade apos a remocao: %d\n", fila->quantidadeItens);
            return;
        }
        aux->ptrProx = NULL;
        fila->ptrUlt = aux;
        printf("Quantidade antes da remocao: %d\n", fila->quantidadeItens);
        fila->quantidadeItens = fila->quantidadeItens - 1;
        printf("Quantidade apos a remocao: %d\n", fila->quantidadeItens);
        return;
    }
    printf("A fila esta vazia.\n");
    return;
}
