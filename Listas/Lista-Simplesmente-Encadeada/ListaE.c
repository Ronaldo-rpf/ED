#include "ListaE.h"

struct Celula {
       tpItem    item;
       struct Celula  *prox;
};

typedef  struct Celula tpNo;

/**
 * Inicia uma lista simplesmente encadeada vazia.
 * @return A lista inicializada com o ponteiro apontando para NULL.
 */
tpNo * initLstE(){
    tpNo *lst = NULL;
    return lst;
}


/**
 * Insere um item em uma lista simplesmente encadeada.
 * @param lst Uma lista de itens;
 * @param item Um item a ser inserido na lista.
 * @return A lista se o item foi inserido com sucesso, ou NULL caso contrário.
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


/**
 * Retorna o primeiro item de uma lista simplesmente encadeada.
 * @param lst  Uma Lista não vazia de itens.
 * @return O item da primeira posição da lista simplesmente encadeada.
 */
tpItem  getE(tpNo *lst){
       return lst->item;
}


/**
 * Exibe no monitor os itens de uma lista simplesmente encadeada.
 * @param lst Uma lista simplesmente encadeada de itens.
 * @return
 */
void printLstE(tpNo *lst){
    while (lst != NULL) {
            printItem(lst->item);
            printf("\n----------------------------------");
            lst = lst->prox;
    }
}


/**
 * Verifica se a lista está vazia.
 * @param lst Uma lista simplesmente encadeada de itens.
 * @return True se a lista simplesmente encadeada estiver vazia ou false caso contrário.
 */
booleano isEmptyLstE(tpNo *lst){
    if (lst == NULL) return true;
    return false;
}


/**
 * Procura um identificador em uma lista simplesmente encadeada.
 * @param lst Uma lista simplesmente encadeada de itens;
 * @param id O identificador que será buscado na lista simplesmente encadeada.
 * @return O item na lista com o identificador, ou NULL se não for encontrado.
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


/**
 * Remove um item de uma lista simplesmente encadeada.
 * @param lst Uma lista simplesmente encadeada de itens;
 * @param id O identificador que será removido na lista simplesmente encadeada.
 * @return O novo ponteiro para o início da lista simplesmente encadeada.
 */
tpNo* removerItem (tpNo* lst, unsigned int id){
    tpNo* anterior = NULL;
    tpNo* atual = lst;

    while (atual != NULL){
        if (atual->item.id == id){
            if (anterior == NULL){
                lst = atual->prox;
            }
            else{
                anterior->prox = atual->prox;
            }
            free(atual);
            printf("Aluno removido.\n");
            return lst;
        }
        else{
            anterior = atual;
            atual = atual->prox;
        }
    }
    printf("Aluno nao cadastrado.\n");
    return lst;
}


/**
 * Retorna quantos itens estão inseridos em uma lista simplesmente encadeada.
 * @param lst Uma lista simplesmente encadeada de itens;
 * @return A quantidade de itens cadastrados em uma lista simplesmente encadeada.
 */
int consultarQTDEAlunos(tpNo* lst){
    if(lst==NULL)
        return 0;
    
    return 1 + consultarQTDEAlunos(lst->prox);
}


/**
 * Preenche um vetor auxiliar de itens.
 * @param noAtual O primeiro nó de uma lista simplesmente encadeada, ou seja, a própria lista;
 * @param vetorDeItens O vetor auxiliar que será preenchido;
 * @param indice O último índice válido do vetor auxiliar.
 * @return
 */
void preencherArrayAuxiliar(tpNo* noAtual, tpItem* vetorDeItens, int indice){
    if(indice < 0)
        return;

    vetorDeItens[indice] = noAtual->item;
    indice--;
    preencherArrayAuxiliar(noAtual->prox, vetorDeItens, indice);
}


/**
 * Ordena um vetor de itens.
 * @param vet Um vetor de itens;
 * @param i O primeiro índice do vetor;
 * @param f O último índice do vetor.
 * @return 
 */
void mergeSortItem(tpItem* vet, int i, int f){
    if(i>=f)
        return;

    int meio = (f + i) / 2;    
    mergeSortItem(vet, i, meio);
    mergeSortItem(vet, meio + 1, f);
    intercalaItem(vet, i, meio, f);
}


/**
 * Intercala crescentemente os valores dos índices de um vetor em um intervalo.
 * @param vet Vetor de itens;
 * @param init índice do início do intervalo;
 * @param meio Índice do meio do intervalo;
 * @param fim Índice do final do intervalo.
 * @return 
 */
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


/**
 * Ordena uma lista simplesmente encadeada.
 * @param lst Uma lista simplesmente encadeada.
 * @return 
 */
void ordenarLista(tpNo** lst){
    int qtde = consultarQTDEAlunos(*lst);

    if(qtde == 0)
        return;

    tpItem* vetorItens = (tpItem*)malloc(sizeof(tpItem) * (unsigned long long)(qtde));
    preencherArrayAuxiliar(*lst, vetorItens, qtde-1);

    mergeSortItem(vetorItens, 0, qtde-1);

    tpNo** listaAux = NULL;
    listaAux = lst;

    for(int i = 0; i < qtde; i++){
        (*listaAux)->item = vetorItens[i];
        listaAux = &(*listaAux)->prox;
    }
}
