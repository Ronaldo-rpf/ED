#include <stdio.h>
#include <stdlib.h>

//----------------------------------------------------------------

typedef struct no{
    int num;
    struct no *prtEsq, *prtDir;
}tpNo;

//----------------------------------------------------------------

tpNo* initArvore();

int insertArvoreR(tpNo **arvore, int num);

int searchArvoreR(tpNo *arvore, int valor);

int alturaArvore(tpNo *arvore);

int deleteArvore(tpNo **arvore, int num);

tpNo* deletarAux(tpNo **arvore, int num);

void imprimirNaoOrdenada(tpNo *arvore);

void imprimirOrdenada(tpNo *arvore);