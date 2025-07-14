#include "ListaDE.h"

/**
 * Cria uma lista duplamente encadeada vazia.
 * @return A lista duplamente encadeada inicializada com os ponteiros apontando para NULL.
 */
tpLDE initLstDE(){
    tpLDE lde;
    lde.ptrPrim = NULL;
    lde.ptrUlt  = NULL;
    lde.quantItens = 0;
    return lde;
}


/**
 * Insere um item no fim de uma lista duplamente encadeada.
 * @param lstDE Uma lista duplamente encadeada;
 * @param item O item que será inserido na lista.
 * @return 1 caso o item for inserido com sucesso, ou 0 caso contrário.
 */
int insertLstDE(tpLDE *lstDE, tpItem item){
    tpNo *no = (tpNo*)malloc(sizeof(tpNo));
   	if (no != NULL){
		no->item      = item;
		no->ptrProx   = NULL;
		no->ptrAnt    = (*lstDE).ptrUlt;

   		(*lstDE).quantItens = (*lstDE).quantItens + 1;
   		if ((*lstDE).ptrPrim == NULL){
            (*lstDE).ptrPrim = no;
            (*lstDE).ptrUlt = no;
        } 
        else{
            lstDE->ptrUlt->ptrProx = no;
            (*lstDE).ptrUlt = no;
        }
   		return 1; 
	}
    return 0; 
}


/**
 * Retorna o primeiro item de uma lista duplamente encadeada.
 * @param lst Uma lista duplamente encadeada.
 * @return O primeiro item da lista.
 */
tpItem getItem(tpLDE lstDE){
       return lstDE.ptrPrim->item;
}


/**
 * Exibe no monitor os itens de uma lista duplamente encadeada.
 * @param lst Uma lista duplamente encadeada.
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


/**
 * Verifica se uma lista duplamente encadeada está vazia.
 * @param lst Uma lista duplamente encadeada.
 * @return Verdadeiro caso a lista duplamente encadeada estiver vazia, ou Falso caso contrário.
 */
booleano isEmptyLstDE(tpLDE lst){
    if (lst.quantItens==0) return true;
    return false;
}


/**
 * Procura um item em uma lista duplamente encadeada.
 * @param lst Uma lista duplamente encadeada;
 * @param id O identificador que será buscado na lista.
 * @return O item da lista com o identificador procurado, caso o mesmo seja encontrado na lista, ou um item com identificador 0 caso contrário.
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


/**
 * Insere um item no fim de uma lista duplamente encadeada, sem repetições.
 * @param lstDE Uma lista duplamente encadeada;
 * @param item O item que será inserido na lista.
 * @return 1 caso o item for inserido com sucesso, ou 0 caso contrário.
 */
int insertLstDE_SR(tpLDE *lstDE, tpItem item){
    tpItem aux = searchItemLstDE(*lstDE, item.id);
    if (aux.id == 0){
        int aux = insertLstDE(lstDE, item);
        if (aux){
            printf("Item inserido com sucesso.\n\n");
            return 1;
        }
        else{
            printf("Erro ao inserir item.\n\n");
            return 0;
        }
    }
    else{
        printf("Item ja existe na lista.\n\n");
        return 0;
    }
}


/**
 * Remove um item de uma lista duplamente encadeada.
 * @param lstDE Uma lista duplamente encadeada;
 * @param id O identificador que será deletado da lista.
 * @return 1 caso o item for removido com sucesso, ou 0 caso contrário.
 */
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
            return 1;
        }
        else if (aux->item.id == id && aux->ptrAnt == NULL){
            lstDE->ptrPrim = aux->ptrProx;
            lstDE->ptrPrim->ptrAnt = NULL;
            free(aux);
            lstDE->quantItens = lstDE->quantItens - 1;
            printf("Aluno deletado.\n");
            printf("Quantidade de alunos apos a remocao: %d\n", lstDE->quantItens);
            return 1;
        }
        else if (aux->item.id == id && aux->ptrProx == NULL){
            lstDE->ptrUlt = aux->ptrAnt;
            aux->ptrAnt->ptrProx = NULL;
            free(aux);
            lstDE->quantItens = lstDE->quantItens - 1;
            printf("Aluno deletado.\n");
            printf("Quantidade de alunos apos a remocao: %d\n", lstDE->quantItens);
            return 1;
        }
        else if (aux->item.id == id){
            aux->ptrAnt->ptrProx = aux->ptrProx;
            aux->ptrProx->ptrAnt = aux->ptrAnt;
            free(aux);
            lstDE->quantItens = lstDE->quantItens - 1;
            printf("Aluno deletado.\n");
            printf("Quantidade de alunos apos a remocao: %d\n", lstDE->quantItens);
            return 1;
        }
        else{
            aux = aux->ptrProx;
        }
    }
    printf("Aluno nao encontrado.\n\n");
    return 0;
}


/**
 * Retorna quantos identificadores específicos existem em uma lista duplamente encadeada.
 * @param lst Uma lista duplamente encadeada;
 * @param id O identificador que será contabilizado na lista.
 * @return A quantidade de identificadores iguais ao desejado que existem na lista.
 */
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


/**
 * Verifica se uma lista duplamente encadeada está ordenada crescentemente ou não.
 * @param lst Uma lista duplamente encadeada.
 * @return Verdadeiro caso a lista esteja ordenada crescentemente, e Falso caso contrário.
 */
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


/**
 * Copia todos os itens presentes em uma lista duplamente encadeada, e insere os mesmos em outra nova lista duplamente encadeada.
 * @param lde1 Uma lista duplamente encadeada.
 * @return A nova lista duplamente encadeada com todos os itens da outra lista inseridos nela.
 */
tpLDE copiaL1emL2 (tpLDE lde1){
    int veri;
    tpLDE L2 = initLstDE();
    tpNo *aux = lde1.ptrPrim;
    while (aux != NULL){
        veri = insertLstDE_SR(&L2, aux->item);
        if (veri){
            printf("Erro ao inserir item de L1 em L2.\n");    
            return L2;
        }
        aux = aux->ptrProx;
    }
    return L2;
}


/**
 * Copia todos os itens presentes em uma lista duplamente encadeada, e insere os mesmos em outra lista duplamente encadeada, ambas já criadas previamente.
 * @param lde1 Uma lista duplamente encadeada, onde os itens serão copiados;
 * @param lde2 Uma lista duplamente encadeada, onde os itens serão inseridos.
 * @return 
 */
void copiaL1emL2existente (tpLDE lde1, tpLDE *lde2){
    int veri, quant;
    quant = lde2->quantItens;
    tpNo *aux = lde2->ptrPrim;
    while(aux != NULL){    
        for (int i = 0; i < quant; i++){
            veri = deleteLstDE(lde2, aux->item.id);
            if(veri){
                printf("Erro ao deletar aluno da lista L2.\n");
                return;
            }
            aux = aux->ptrProx;
        }
    }
    printf("Todos os aluno da lista L2 foram deletados.\n");
    aux = lde1.ptrPrim;
    while(aux->ptrProx != NULL){    
        if (aux->item.id == aux->ptrProx->item.id){
            veri = deleteLstDE(&lde1, aux->item.id);
            if(veri){
                printf("Erro ao deletar aluno da lista L1.\n");
                return;
            }
        }
        aux = aux->ptrProx;
    }
    printf("Todos os aluno repetidos da lista L1 foram deletados.\n");

    aux = lde1.ptrPrim;
    while (aux != NULL){
        veri = insertLstDE_SR(lde2, aux->item);
        if(veri){
            printf("Erro ao inserir item de L1 em L2.\n");    
            return;
        }
        aux = aux->ptrProx;
    }

    printf("A lista L1 foi copiada para a lista L2.\n");
    return;
}
