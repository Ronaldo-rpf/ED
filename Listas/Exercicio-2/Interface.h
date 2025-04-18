#include <stdio.h>
#include <stdlib.h>
#include "ListaE.h"

//-----------------------------------------------------------------------------
    /**
     * Exibe um menu com opções para modificar uma lista encadeada.
     * @return O numero escolhido pelo usuário para executar uma das tarefas apresentadas no menu;
     */
char menu();

//-----------------------------------------------------------------------------
    /**
     * Cadastra um novo aluno (célula) na lista encadeada.
     * @param lstAl ponteiro para o primeiro nó da lista encadeada;
     * @return
     */
void cadastrarLstE(tpNo **lstAl);

//-----------------------------------------------------------------------------
    /**
     * Pesquisa na lista encadeada se existe um aluno com o id fornecido.
     * @param lstAl ponteiro para o primeiro nó da lista encadeada;
     * @return
     */
void consultarLstE(tpNo *lstAl);

//-----------------------------------------------------------------------------
    /**
     * Exibe o menu principal, a partir da função "char menu()", inicializa a lista encadeada, e chama as funções requeridas de fato.
     * @return
     */
void lstEncadeada();

//-----------------------------------------------------------------------------
/**
 * Remove um nó da lista encadeada.
 * @param lstAl ponteiro para o primeiro nó da lista encadeada;
 * @return 
 */
void removerLstE(tpNo **lstAl);