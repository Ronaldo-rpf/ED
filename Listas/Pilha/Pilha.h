#include <stdio.h>
#include <stdlib.h>

//-------------------------------------------------------------------------------------

typedef struct{
    char nome[50];
    unsigned int id;
} tpItem;

typedef struct{
    tpItem aluno;
    tpNo *ptrProx, *ptrAnt;
} tpNo;

typedef struct{
    tpNo *ptrPrim, *ptrUlt;
    int quantidadeItens;
} tpPilha;

//-------------------------------------------------------------------------------------

void printarPilha (tpPilha pilha);

tpPilha initPilha();

int inserirAluno (tpPilha *pilha, tpItem aluno);

tpItem searchItemPilha (tpPilha pilha, unsigned int id);

int deletePilha (tpPilha *pilha, unsigned int id);

