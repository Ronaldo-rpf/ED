//Essas diretivas servem para evitar que um header file seja inclu�do mais de uma vez
//no mesmo projeto

#include <stdio.h>
#include <stdlib.h>

#include "ListaE.h"

void lstEncadeada();
char menu();
void cadastrarLstE(tpNo **lstAl);
void consultarLstE(tpNo *lstAl);
void RemoverLstE(tpNo **lstAl);
void OrdenarListaInterface(tpNo **lstAl);
