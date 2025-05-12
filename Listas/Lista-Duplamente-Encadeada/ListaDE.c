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
#include "ListaDE.h"

/**
 * Inicia uma LDE vazia.
 * @param .
 * @return a lista inicializada com os ponteiros apontando para NULL e quantItens=0;
 */
tpLDE initLstDE(){
    tpLDE lde;
    lde.ptrPrim = NULL;
    lde.ptrUlt  = NULL;
    lde.quantItens = 0;
    return lde;
}

//-----------------------------------------------------------------------------
/**
 * Insere um item no fim da lista.
 * @param lstDE = uma Lista de itens;
 * @param item= um item a ser inserido em lstDE
 * @return 1 se o item foi inserido em lst ou 0 caso contr�rio.
 */
int insertLstDE(tpLDE *lstDE, tpItem item){
    tpNo *no = (tpNo*)malloc(sizeof(tpNo));
   	if (no !=NULL){
		no->item      = item;
		no->ptrProx   = NULL;
		no->ptrAnt    = (*lstDE).ptrUlt; //pq é um registro

   		(*lstDE).quantItens = (*lstDE).quantItens + 1;
   		if ((*lstDE).ptrPrim == NULL){
            (*lstDE).ptrPrim = no;
            (*lstDE).ptrUlt = no;
        } 
        else{
            lstDE->ptrUlt->ptrProx = no;
            (*lstDE).ptrUlt = no;
        }
   		return 1;   //1 = elemento inserido
	}
    return 0; //0 = elemento n�o inserido
}
//-----------------------------------------------------------------------------
/**
 * Retorna o primeiro item da lista.
 * @param lst = uma Lista n�o vazia de itens;
 * @return retorna o item da primeira posi��o de lst.
 */
tpItem getItem(tpLDE lstDE){
       return lstDE.ptrPrim->item;
}


//-----------------------------------------------------------------------------
/**
 * Exibe no monitor os itens da lista.
 * @param lst = uma Lista de itens;
 * @return
 */
void printLstDE(tpLDE lst){
    tpNo *aux = lst.ptrPrim;

    while (aux != NULL) {
            printItem(aux->item);
            printf("\n----------------------------------");
            aux = aux->ptrProx;
    }
}

//-----------------------------------------------------------------------------
/**
 * Verifica se a lista est� vazia.
 * @param lst = uma Lista de itens;
 * @return true se lst vazia ou false caso contr�rio.
 */
booleano isEmptyLstDE(tpLDE lst){
    if (lst.quantItens==0) return true;
    return false;
}

//-----------------------------------------------------------------------------
/**
 * Busca um item na lista.
 * @param lst = uma Lista de itens;
 * @param id = � o identificador que ser� buscado em lst.
 * @return o item na lista com o id ou NULL se n�o for encontrado.
 */
/*
tpItem  *searchItemLstDE(tpLDE lst, unsigned int id){
    tpNo *aux = lst.ptrPrim;
    while (aux != NULL){
        if ( (*aux).item.id == id){
            return &(*aux).item;
        } else {
            aux = aux->ptrProx;
        }
    }
    return NULL;
}
*/
tpItem  searchItemLstDE(tpLDE lst, unsigned int id){
    tpNo *aux = lst.ptrPrim;
    while (aux != NULL){
        if ( (*aux).item.id == id){
            return (*aux).item;
        } else {
            aux = aux->ptrProx;
        }
    }
    tpItem item;
    item.id = 0;
    return item;
}

int insertLstDE_SR(tpLDE *lstDE, tpItem item){
    tpItem aux = searchItemLstDE(*lstDE, item.id);
    if (aux.id == 0){
        int aux = insertLstDE(lstDE, item);
        if (aux){
            printf("Item inserido com sucesso.\n\n");
            return 0;
        }
        else{
            printf("Erro ao inserir item.\n\n");
            return 1;
        }
    }
    else{
        printf("Item ja existe na lista.\n\n");
        return 1;
    }
}

int deleteLstDE (tpLDE *lstDE, unsigned int id){
    tpNo *aux = lstDE->ptrPrim;
    printf("Quantidade de alunos antes da remocao: %d\n", lstDE->quantItens);
    while(aux != NULL){
        if (aux->item.id == id && aux->ptrAnt == NULL && aux->ptrProx == NULL){
            free(aux);
            lstDE->ptrPrim = NULL;
            lstDE->ptrUlt = NULL;
            lstDE->quantItens = lstDE->quantItens - 1;
            printf("Aluno deletado.\n");
            printf("Quantidade de alunos apos a remocao: %d\n", lstDE->quantItens);
            return 0;
        }
        else if (aux->item.id == id && aux->ptrAnt == NULL){
            lstDE->ptrPrim = aux->ptrProx;
            lstDE->ptrPrim->ptrAnt = NULL;
            free(aux);
            lstDE->quantItens = lstDE->quantItens - 1;
            printf("Aluno deletado.\n");
            printf("Quantidade de alunos apos a remocao: %d\n", lstDE->quantItens);
            return 0;
        }
        else if (aux->item.id == id && aux->ptrProx == NULL){
            lstDE->ptrUlt = aux->ptrAnt;
            aux->ptrAnt->ptrProx = NULL;
            free(aux);
            lstDE->quantItens = lstDE->quantItens - 1;
            printf("Aluno deletado.\n");
            printf("Quantidade de alunos apos a remocao: %d\n", lstDE->quantItens);
            return 0;
        }
        else if (aux->item.id == id){
            aux->ptrAnt->ptrProx = aux->ptrProx;
            aux->ptrProx->ptrAnt = aux->ptrAnt;
            free(aux);
            lstDE->quantItens = lstDE->quantItens - 1;
            printf("Aluno deletado.\n");
            printf("Quantidade de alunos apos a remocao: %d\n", lstDE->quantItens);
            return 0;
        }
        else{
            aux = aux->ptrProx;
        }
    }
    printf("Aluno nao encontrado.\n\n");
    return 1;
}

int quantosIds (tpLDE lst, unsigned int id){
    int cont = 0;
    tpNo *aux = lst.ptrPrim;
    while (aux != NULL){
        if(aux->item.id == id){
            cont++;
        }
        aux = aux->ptrProx;
    }
    return cont;
}

booleano ordenadaOuNao (tpLDE lst){
    tpNo *aux = lst.ptrPrim;
    if (aux == NULL){
        return true;
    }
    while(aux->ptrProx != NULL){
        if (aux->item.id > aux->ptrProx->item.id){
            return false;
        }
        aux = aux->ptrProx;
    }
    return true;
}

