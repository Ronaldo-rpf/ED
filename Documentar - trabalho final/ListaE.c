/********************************************************************
 * Este arquivo cont�m c�digo para manipular uma lista encadeada de itens.
 * Um item � uma estrutura definida pelo usu�rio da biblioteca ListaE.h.
 * Uma lista encadeada � um ponteiro para um n�. Um n� possui dois campos:
 * a) um campo do tipo tpItem;
 * b) um ponteiro para o pr�ximo n�;
 *
 * Obs:
 * -> O tipo tpItem deve conter obrigat�riamente um campo nomeado de id do tipo unsigned int.
 *
 */
#include "ListaE.h"
//-----------------------------------------------------------------------------
struct Celula {
       tpItem    item;
       struct Celula  *prox;
};

typedef  struct Celula tpNo;
//-----------------------------------------------------------------------------
/**
 * @param .
 * @return a lista inicializada com o ponteiro apontando para NULL;
 */
tpNo * initLstE(){
    tpNo *lst = NULL;
    return lst;
}

/**
 * @param lst = uma Lista de itens;
 * @param item= um item a ser inserido em lst
 * @return a lista se o item foi inserido em lst ou NULL caso contr�rio.
 */
tpNo *insertLstE(tpNo *lst, tpItem item){
    tpNo *no = (tpNo*)malloc(sizeof(tpNo));
   	if (no !=NULL){
		no->item = item;
		no->prox = lst;
   		lst=no;
   		return lst;
	}
    return NULL;
}
//-----------------------------------------------------------------------------
/**
 * @param lst = uma Lista n�o vazia de itens;
 * @return retorna o item da primeira posi��o de lst.
 */
tpItem  getE(tpNo *lst){
       return lst->item;
}


//-----------------------------------------------------------------------------
/**
 * Exibe no monitor os itens da lista.
 * @param lst = uma Lista de itens;
 * @return
 */
void printLstE(tpNo *lst){
    //tpNo *aux = lst;

    while (lst != NULL) {
            printItem(lst->item);
            printf("\n----------------------------------");
            lst = lst->prox;
    }
}

//-----------------------------------------------------------------------------
/**
 * Verifica se a lista est� vazia.
 * @param lst = uma Lista de itens;
 * @return true se lst vazia ou false caso contr�rio.
 */
booleano isEmptyLstE(tpNo *lst){
    if (lst == NULL) return true;
    return false;
}

//-----------------------------------------------------------------------------
/**
 * Verifica se a lista est� vazia.
 * @param lst = uma Lista de itens;
 * @param id = � o identificador que ser� buscado em lst.
 * @return o item na lista com o id ou NULL se n�o for encontrado.
 */
tpItem * searchItemLstE(tpNo *lst, unsigned int id){
    if  (lst != NULL){
        if (lst->item.id == id){
            return &(lst->item);
        } else {
            return searchItemLstE(lst->prox, id);
        }
    }
    return NULL;
}

tpNo* removeItemLstEAux(tpNo **noAtual, unsigned int id){
    return removeItemLstE(NULL, noAtual, id);
}

tpNo * removeItemLstE(tpNo **noAnterior, tpNo **noAtual, unsigned int id){
    //printf("a");
    if(*noAtual == NULL){
        //printf("b");
        return NULL;
    }
    
    if((*noAtual)->item.id == id){
        //printf("c");
        if(noAnterior == NULL){
            //printf("d");
            *noAtual = (*noAtual)->prox;
            return *noAtual;
        }
        else{
            //printf("e");
            //return (*noAnterior)->prox = (*noAtual)->prox;
            return *noAnterior = insertLstE((*noAtual)->prox ,(*noAnterior)->item);
        }
    }
    else{
        //printf("f");
        return removeItemLstE(noAtual, &((*noAtual)->prox), id);
    }
}




int consultarQTDEAlunos(tpNo* lst){
    if(lst==NULL)
        return 0;
    
    return 1 + consultarQTDEAlunos(lst->prox);
}

void preencherArrayAuxiliar(tpNo* noAtual, tpItem* vetorDeItens, int indice){
    if(indice < 0)
        return;

    vetorDeItens[indice] = noAtual->item;
    indice--;
    preencherArrayAuxiliar(noAtual->prox, vetorDeItens, indice);

}

void mergeSortItem(tpItem* vet, int i, int f){
    if(i>=f)
        return;

    int meio = (f + i) / 2;    
    mergeSortItem(vet, i, meio);
    mergeSortItem(vet, meio + 1, f);
    intercalaItem(vet, i, meio, f);
}

void intercalaItem(tpItem* vet, int init, int meio, int fim){
    tpItem* vetAux = (tpItem*)malloc(sizeof(tpItem) * (unsigned long long)(fim - init + 1));
    int aux = 0;

    int v1 = init;
    int v2 = meio+1;
    
    while(v1 <= meio && v2 <= fim){
        if(vet[v1].id <= vet[v2].id){
            vetAux[aux] = vet[v1];
            aux++;
            v1++;
        }
        else{
            vetAux[aux] = vet[v2];
            aux++;
            v2++;
        }
    }

    while(v1 <= meio){
        vetAux[aux] = vet[v1];
        v1++;
        aux++;
    }

    while(v2 <= fim){
        vetAux[aux] = vet[v2];
        v2++;
        aux++;
    }

    aux = 0;
    for(int x = init; x <= fim; x++){
        vet[x] = vetAux[aux];
        aux++;
    }
}

void ordenarLista(tpNo** lista){
    //printf("1");
    int qtde = consultarQTDEAlunos(*lista);
    //printf("2\n");
    //printf("%d\n", qtde);

    if(qtde == 0)
        return;

    tpItem* vetorItens = (tpItem*)malloc(sizeof(tpItem) * (unsigned long long)(qtde));
    preencherArrayAuxiliar(*lista, vetorItens, qtde-1);

    //printf("3");

    mergeSortItem(vetorItens, 0, qtde-1);

    //printf("4");

    tpNo** listaAux = NULL;
    listaAux = lista;

    for(int i = 0; i < qtde; i++){
        (*listaAux)->item = vetorItens[i];
        listaAux = &(*listaAux)->prox;
    }

    //printf("\n6");

}