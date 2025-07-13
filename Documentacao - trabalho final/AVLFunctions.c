#include "AVLFunctions.h"

/**
 * Cria uma árvore AVL vazia.
 * @return Um ponteiro para uma árvore AVL vazia, apontando para NULL.
 */
tpArvore* initArvore() {
	tpArvore *arvore = NULL;
	return arvore;
}


/**
 * Calcula a altura de uma árvore AVL.
 * @param arvore Uma árvore AVL.
 * @return A altura da árvore AVL.
 */
int alturaArvore(tpArvore* arvore) {
	if(arvore == NULL) {
		return -1;
	} else {
		if(arvore ->direita == NULL && arvore ->esquerda == NULL) {

			return 0;
		} else if (arvore ->direita == NULL && arvore ->esquerda != NULL) {

			return 1 + alturaArvore(arvore -> esquerda);
		} else if (arvore -> direita != NULL && arvore ->esquerda == NULL) {

			return 1 + alturaArvore(arvore -> direita);
		} else if (arvore -> direita != NULL && arvore ->esquerda != NULL) {

			int esquerda = 1 + alturaArvore(arvore -> esquerda);
			int direita = 1 + alturaArvore(arvore -> direita);

			if(esquerda > direita) {
				return esquerda;
			} else {
 				return direita;
			}
		}
		return -1;
	}
}


/**
 * Rotaciona uma árvore AVL para a direita.
 * @param arv Uma árvore AVL.
 * @return A nova raiz da árvore AVL após a rotação.
 */
tpArvore* RSD(tpArvore* arv) {
	tpArvore* filho = arv->esquerda;
	arv->esquerda = filho->direita;
	filho->direita = arv;
	return filho;

}


/**
 * Rotaciona uma árvore AVL para a esquerda.
 * @param arv Uma árvore AVL.
 * @return A nova raiz da árvore AVL após a rotação.
 */
tpArvore* RSE(tpArvore* arv) {
	tpArvore* filho = arv->direita;
	arv->direita = filho->esquerda;
	filho->esquerda = arv;
	return filho;
}


/**
 * Calcular o fator de balanceamento de um nó de uma árvore AVL.
 * @param arvore Nó de uma árvore AVL.
 * @return O fator de balanceamento do nó.
 */
int verificaFB(tpArvore* arvore) {
	if(arvore == NULL) {
		return 0;
	} else {
		return alturaArvore(arvore->direita) - alturaArvore(arvore->esquerda);
	}
}


/**
 * Insere um item em uma árvore AVL.
 * @param arvore Uma árvore AVL;
 * @param item O item que será inserido.
 * @return A nova raiz da árvore AVL, após a inserção.
 */
tpArvore* insertArvore(tpArvore* arvore, tpItem item) {
	if(item.num <= 0) return NULL;
	tpItem busca = buscaArvore(arvore,item.num);
	if(busca.num != -1) return NULL;
	if(arvore == NULL) {
		tpArvore *galho = (tpArvore*)malloc(sizeof(tpArvore));
		if(galho != NULL) {
			galho->item = item;
			galho->esquerda = NULL;
			galho->direita = NULL;
			return galho;
		}
		return NULL;
	} else {
		if(item.num > arvore->item.num) {
			arvore->direita = insertArvore(arvore->direita,item);
		} 
		else {
			arvore->esquerda = insertArvore(arvore->esquerda,item);
		}

		int FB = verificaFB(arvore);
		if(FB < -1 && verificaFB(arvore->esquerda) < 0) {
			return RSD(arvore);
		}
		if(FB < -1 && verificaFB(arvore->esquerda) > 0) {
			arvore->esquerda = RSE(arvore->esquerda);
			return RSD(arvore);
		}
		if(FB > 1 && verificaFB(arvore->direita) > 0) {
			return RSE(arvore);
		}
		if(FB > 1 && verificaFB(arvore->direita) < 0) {
			arvore->direita = RSD(arvore->direita);
			return RSE(arvore);
		}

		return arvore;
	}
}


/**
 * Procura um valor em uma árvore AVL.
 * @param arvore Uma árvore AVL;
 * @param valor O valor que será procurado.
 * @return O item caso o mesmo seja encontrado na árvore, ou -1 caso contrário.
 */
int searchArvoreR(tpNo *arvore, int valor){
    if (arvore == NULL){
        return -1;
    }
    else if (arvore->num == valor){
        return arvore->num;
    }
    else if (arvore->prtDir == NULL && arvore->prtEsq == NULL){
        return -1;
    }
    else if (arvore->num < valor){
        arvore = arvore->prtDir;
        return searchArvoreR(arvore, valor);
    }
    else{
        arvore = arvore->prtEsq;
        return searchArvoreR(arvore, valor);
    }
}


/**
 * Exibe no monitor os valores de uma árvore AVL em ordem crescente.
 * @param arvore Uma árvore AVL.
 * @return 
 */
void printArvoreEmOrdem(tpArvore* arvore) {

	if(arvore == NULL) return;

	printArvoreEmOrdem(arvore->esquerda);
	printf("\n%d",arvore->item.num);
	printArvoreEmOrdem(arvore->direita);
}


/**
 * Encontra o menor valor em uma árvore AVL.
 * @param arvore Uma árvore AVL.
 * @return O ponteiro para o nó com o menor valor da árvore.
 */
tpArvore* procuraMenor(tpArvore* arvore) {

	tpArvore *aux1 = arvore;
	tpArvore *aux2 = arvore->esquerda;

	while (aux2 != NULL) {

		aux1 = aux2;
		aux2 = aux2->esquerda;
	}

	return aux1;
}


/**
 * Remove um valor de uma árvore AVL.
 * @param raiz Uma árvore AVL;
 * @param valor O valor que será removido.
 * @return 1 caso o valor for removido com sucesso, ou 0 caso contrário.
 */
int removeArvore(tpArvore** raiz, int valor) {

	if (*raiz == NULL) {
		return 0;
	}

	int res;

	if (valor < (*raiz)->item.num) {
		res = removeArvore(&((*raiz)->esquerda), valor);
		if (res == 1 && verificaFB(*raiz) >= 2) {
			if (alturaArvore((*raiz)->direita->esquerda) <= alturaArvore((*raiz)->direita->direita)) {
				*raiz = RSE(*raiz);
			} else {
				(*raiz)->direita = RSD((*raiz)->direita);
				*raiz = RSE(*raiz);
			}
		}
	} else if (valor > (*raiz)->item.num) {
		res = removeArvore(&((*raiz)->direita), valor);
		if (res == 1 && verificaFB(*raiz) <= -2) {
			if (alturaArvore((*raiz)->esquerda->direita) <= alturaArvore((*raiz)->esquerda->esquerda)) {
				*raiz = RSD(*raiz);
			} else {
				(*raiz)->esquerda = RSE((*raiz)->esquerda);
				*raiz = RSD(*raiz);
			}
		}
	} else {
		tpArvore* temp = *raiz;

		if ((*raiz)->esquerda == NULL) {
			*raiz = (*raiz)->direita;
			free(temp);
		} else if ((*raiz)->direita == NULL) {
			*raiz = (*raiz)->esquerda;
			free(temp);
		} else {
			tpArvore* menor = procuraMenor((*raiz)->direita);
			(*raiz)->item = menor->item;
			removeArvore(&((*raiz)->direita), menor->item.num);

			if (verificaFB(*raiz) <= -2) {
				if (alturaArvore((*raiz)->esquerda->direita) <= alturaArvore((*raiz)->esquerda->esquerda)) {
					*raiz = RSD(*raiz);
				} else {
					(*raiz)->esquerda = RSE((*raiz)->esquerda);
					*raiz = RSD(*raiz);
				}
			}

			if (verificaFB(*raiz) >= 2) {
				if (alturaArvore((*raiz)->direita->esquerda) <= alturaArvore((*raiz)->direita->direita)) {
					*raiz = RSE(*raiz);
				} else {
					(*raiz)->direita = RSD((*raiz)->direita);
					*raiz = RSE(*raiz);
				}
			}
		}
		return 1;
	}
	return res;
}
