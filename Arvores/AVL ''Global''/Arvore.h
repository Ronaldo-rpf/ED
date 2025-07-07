#include <stdio.h>
#include <stdlib.h>

//----------------------------------------------------------------

typedef struct no{
    int num;
    int fatorBalanceamento;
    struct no *prtEsq, *prtDir;
}tpNo;

//----------------------------------------------------------------

tpNo* initArvore();

int insertArvoreR(tpNo **arvore, int num);

int searchArvoreR(tpNo *arvore, int valor);

int alturaArvore(tpNo *arvore);

tpNo* deleteArvore(tpNo **arvore, int num);

void imprimirNaoOrdenada(tpNo *arvore);

void imprimirOrdenada(tpNo *arvore);

void fatorBalanceamento (tpNo **arvore);

void balanceamento (tpNo **arvore);

void rotacaoSimplesDireita (tpNo **arvore);

void rotacaoSimplesEsquerda (tpNo **arvore);