#include <stdio.h>
#include <stdlib.h>

//-------------------------------------------------------------------------------------

typedef struct{
    char nome[50];
    unsigned int id;
} tpItem;

typedef struct tpNo{
    tpItem aluno;
    struct tpNo *ptrProx, *ptrAnt;
} tpNo;

typedef struct{
    tpNo *ptrPrim, *ptrUlt;
    int quantidadeItens;
} tpFila;

//-------------------------------------------------------------------------------------

void printarFila (tpFila fila);

tpFila initFila();

int enqueue (tpFila *fila, tpItem aluno);

tpItem searchItemFila (tpFila fila, unsigned int id);

int deleteFila (tpFila *fila, unsigned int id);

void dequeue (tpFila *fila);