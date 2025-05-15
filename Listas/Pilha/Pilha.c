#include "Pilha.h"

void printarPilha (tpPilha pilha){
    tpNo *aux = pilha.ptrPrim;
    while (aux != NULL){
        printf("\n----------------------\n");
        printf("Nome: %s", aux->aluno.nome);
        printf("Id: %d\n", aux->aluno.id);
        printf("----------------------\n");
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
        no->aluno = aluno;
        no->ptrAnt = pilha->ptrUlt;
        no->ptrProx = NULL;
        pilha->quantidadeItens = pilha->quantidadeItens + 1;
        if (pilha->ptrPrim == NULL){
            pilha->ptrPrim = no;
            pilha->ptrUlt = no;
        }
        else{
            pilha->ptrUlt->ptrProx = no;
            pilha->ptrUlt = no;
        }
        return 0;
    }
    return 1;
}

tpItem searchItemPilha (tpPilha pilha, unsigned int id){
    tpItem item;
    tpNo *aux = pilha.ptrPrim;
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

int deletePilha (tpPilha *pilha, unsigned int id){
    tpNo *aux = pilha->ptrUlt;
    while (aux != NULL){
        if (aux->aluno.id == id){
            aux = aux->ptrAnt;
            free(pilha->ptrUlt);
            pilha->ptrUlt = aux;
            aux->ptrProx = NULL;
            printf("Quantidade de itens antes da remocao: %d\n", pilha->quantidadeItens);
            pilha->quantidadeItens = pilha->quantidadeItens - 1;
            printf("Quantidade de itens apos a remocao: %d\n", pilha->quantidadeItens);
            return 0;
        }
        aux = aux->ptrAnt;
        free(pilha->ptrUlt);
        pilha->ptrUlt = aux;
        if (aux == NULL){
            printf("Aluno nao encontrado ainda.\n");
            printf("Quantidade de itens antes da remocao: %d\n", pilha->quantidadeItens);
            pilha->quantidadeItens = pilha->quantidadeItens - 1;
            printf("Quantidade de itens apos a remocao: %d\n", pilha->quantidadeItens);
            break;
        }
        aux->ptrProx = NULL;
        printf("Aluno nao encontrado ainda.\n");
        printf("Quantidade de itens antes da remocao: %d\n", pilha->quantidadeItens);
        pilha->quantidadeItens = pilha->quantidadeItens - 1;
        printf("Quantidade de itens apos a remocao: %d\n", pilha->quantidadeItens);
    }
    printf("Aluno nao encontrado, fim da pilha.\n");
    pilha->ptrPrim = NULL;
    return 1;
}

void pop (tpPilha *pilha){
    tpNo *aux = pilha->ptrUlt;
    if (aux != NULL){
        printf("Aluno deletado: \n");
        printf("Nome: %s\n", aux->aluno.nome);
        printf("Matricula: %d\n", aux->aluno.id);
        aux = aux->ptrAnt;
        free(pilha->ptrUlt);
        pilha->ptrUlt = aux;
        if (aux == NULL){
            pilha->ptrPrim = NULL;
            printf("Quantidade de itens antes da remocao: %d\n", pilha->quantidadeItens);
            pilha->quantidadeItens = pilha->quantidadeItens - 1;
            printf("Quantidade de itens apos a remocao: %d\n", pilha->quantidadeItens);
            return;
        }
        aux->ptrProx = NULL;
        printf("Quantidade de itens antes da remocao: %d\n", pilha->quantidadeItens);
        pilha->quantidadeItens = pilha->quantidadeItens - 1;
        printf("Quantidade de itens apos a remocao: %d\n", pilha->quantidadeItens);
        return;
    }
    printf("A pilha esta vazia.\n");
}
