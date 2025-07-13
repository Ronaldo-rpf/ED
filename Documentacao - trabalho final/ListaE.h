#include "Item.h"
#include <stdlib.h>

typedef  struct Celula tpNo;

/**
 * Inicia uma lista simplesmente encadeada vazia.
 * @return A lista inicializada com o ponteiro apontando para NULL.
 */
tpNo * initLstE();


/**
 * Insere um item em uma lista simplesmente encadeada.
 * @param lst Uma lista de itens;
 * @param item Um item a ser inserido na lista.
 * @return A lista se o item foi inserido com sucesso, ou NULL caso contrário.
 */
tpNo*insertLstE(tpNo *lst, tpItem item);


/**
 * Retorna o primeiro item de uma lista simplesmente encadeada.
 * @param lst  Uma Lista não vazia de itens.
 * @return O item da primeira posição da lista simplesmente encadeada.
 */
tpItem  getE(tpNo *lst);


/**
 * Exibe no monitor os itens de uma lista simplesmente encadeada.
 * @param lst Uma lista simplesmente encadeada de itens.
 * @return
 */
void printLstE(tpNo *lst);


/**
 * Verifica se a lista está vazia.
 * @param lst Uma lista simplesmente encadeada de itens.
 * @return True se a lista simplesmente encadeada estiver vazia ou false caso contrário.
 */
booleano isEmptyLstE(tpNo *lst);


/**
 * Procura um identificador em uma lista simplesmente encadeada.
 * @param lst Uma lista simplesmente encadeada de itens;
 * @param id O identificador que será buscado na lista simplesmente encadeada.
 * @return O item na lista com o identificador, ou NULL se não for encontrado.
 */
tpItem *searchItemLstE(tpNo *lst, unsigned int id);


/**
 * Remove um item de uma lista simplesmente encadeada.
 * @param lst Uma lista simplesmente encadeada de itens;
 * @param id O identificador que será removido na lista simplesmente encadeada.
 * @return O novo ponteiro para o início da lista simplesmente encadeada.
 */
tpNo* removerItem (tpNo* lst, unsigned int id);


/**
 * Retorna quantos itens estão inseridos em uma lista simplesmente encadeada.
 * @param lst Uma lista simplesmente encadeada de itens;
 * @return A quantidade de itens cadastrados em uma lista simplesmente encadeada.
 */
int consultarQTDEAlunos(tpNo* lst);


/**
 * Preenche um vetor auxiliar de itens.
 * @param noAtual O primeiro nó de uma lista simplesmente encadeada, ou seja, a própria lista;
 * @param vetorDeItens O vetor auxiliar que será preenchido;
 * @param indice O último índice válido do vetor auxiliar.
 * @return
 */
void preencherArrayAuxiliar(tpNo* noAtual, tpItem* vetorDeItens, int indice);


/**
 * Ordena um vetor de itens.
 * @param vet Um vetor de itens;
 * @param i O primeiro índice do vetor;
 * @param f O último índice do vetor.
 * @return 
 */
void mergeSortItem(tpItem* vet, int i, int f);


/**
 * Intercala crescentemente os valores dos índices de um vetor em um intervalo.
 * @param vet Vetor de itens;
 * @param init índice do início do intervalo;
 * @param meio Índice do meio do intervalo;
 * @param fim Índice do final do intervalo.
 * @return 
 */
void intercalaItem(tpItem* vet, int init, int meio, int fim);


/**
 * Ordena uma lista simplesmente encadeada.
 * @param lst Uma lista simplesmente encadeada.
 * @return 
 */
void ordenarLista(tpNo** lista);
