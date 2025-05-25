#include <stdio.h>
#include <stdlib.h>

//----------------------------------------------------------------

typedef struct{
    int num;
    struct tpNo *prtEsq, *prtDir;
}tpNo;

//----------------------------------------------------------------

tpNo* initArvore();

int insertArvoreR(tpNo **arvore, int num);

int searchArvoreR(tpNo *arvore, int valor);

int alturaArvore(tpNo *arvore);

