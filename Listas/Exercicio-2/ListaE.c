/********************************************************************
 * Este arquivo contém código para manipular uma lista encadeada de itens.
 * Um item é uma estrutura definida pelo usuário da biblioteca ListaE.h.
 * Uma lista encadeada é um ponteiro para um nó. Um nó possui dois campos:
 * a) um campo do tipo tpItem;
 * b) um ponteiro para o próximo nó;
 *
 * Obs:
 * -> O tipo tpItem deve conter obrigatóriamente um campo nomeado de id do tipo unsigned int.
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
tpNo* initLstE(){
    tpNo *lst = NULL;
    return lst;
}

/**
 * @param lst = uma Lista de itens;
 * @param item= um item a ser inserido em lst
 * @return a lista se o item foi inserido em lst ou NULL caso contrário.
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
 * @param lst = uma Lista não vazia de itens;
 * @return retorna o item da primeira posição de lst.
 */
tpItem getE(tpNo *lst){
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
 * Verifica se a lista está vazia.
 * @param lst = uma Lista de itens;
 * @return true se lst vazia ou false caso contrário.
 */
booleano isEmptyLstE(tpNo *lst){
    if (lst == NULL) return true;
    return false;
}

//-----------------------------------------------------------------------------
/**
 * Verifica se a lista está vazia.
 * @param lst uma Lista de itens;
 * @param id é o identificador que será buscado em lst.
 * @return o item na lista com o id ou NULL se não for encontrado.
 */
tpItem* searchItemLstE(tpNo *lst, unsigned int id){
    if  (lst != NULL){
        if (lst->item.id == id){
            return &(lst->item);
        } else {
            return searchItemLstE(lst->prox, id);
        }
    }
    return NULL;
}

//-----------------------------------------------------------------------------
/**
 * Função auxiliar para remover um nó da lista.
 * @param noAtual O ponteiro que aponta pro início da lista;
 * @param id ID do aluno que deseja remover da lista;
 * @return Ponteiro do tipo tpNo, para tratamento de erros na função principal.
 */
tpNo* removeItemLstEAux(tpNo **noAtual, unsigned int id){
    return removeItemLstE(NULL, noAtual, id);
}

//-----------------------------------------------------------------------------
/**
 * Encontra e remove um nó em uma lista encadeada.
 * @param noAnterior Nó imediatamente anterior ao analisado no momento;
 * @param noAtual Nó analisado nessa chamada de função atual; 
 * @param id ID do aluno que deseja remover da lista;
 * @return Ponteiro do tipo tpNo, para tratamento de erros na função principal.
 */
tpNo * removeItemLstE(tpNo **noAnterior, tpNo **noAtual, unsigned int id){
    if(*noAtual == NULL){
        printf("b");
        return NULL;
    }
    
    else if((*noAtual)->item.id == id){
        if(noAnterior == NULL){
            *noAtual = (*noAtual)->prox;
            return *noAtual;
        }
        else{
            return (*noAnterior)->prox = (*noAtual)->prox;
        }
    }
    else{
        return removeItemLstE(noAtual, &((*noAtual)->prox), id);
    }
}
