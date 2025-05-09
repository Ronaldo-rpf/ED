#include <stdio.h>
#include <stdlib.h>

#define CAPACIDADE 5

/* TAD lista usando vetor.
   elementos = vetor de inteiros [0..CAPACIDADE-1];
   tamanho= armazena a quantidade de elementos existentes na lista.
   
   Funções:
   void inicializarLista(Lista *lista);
   int estaCheia(Lista *lista);
   int adicionaElemento(Lista *lista, int elemento);
   int removeElemento(Lista *lista, int indice);
   void imprimiLista(Lista *lista);
   
*/
typedef struct {
    int elementos[CAPACIDADE];
    int tamanho;
} Lista;

/* Função para inicializar a lista como uma lista vazia;
   Entrada: uma estrutura do tipo Lista;
   Saída: uma Lista vazia;
*/   
void inicializaLista(Lista *lista) {
    printf("Lista inicializada.\n\n");
    lista->tamanho = 0;
}

/* Função para verificar se a lista está cheia.
   Entrada: uma Lista;
   Saída: verdadeiro se a lista estiver cheia e falso caso contrário.
*/
int estaCheia(Lista *lista) {
    if (lista->tamanho == CAPACIDADE){
        return 1;
    }
    else{
        return 0;
    }
}

/* Função para adicionar um elemento à lista.
   Entrada: uma Lista e um elemento inteiro;
   Saída: 1 se o elemento foi inserido na Lista e 0 caso contrário (lista sem espaço).
*/
int adicionaElemento(Lista *lista, int elemento) {
    if (estaCheia(lista)) {
        printf("Nao ha espaco para um novo item.\n\n");
        return 1; // Falha ao adicionar elemento
    }
    printf("Item adicionado com sucesso.\n\n");
    lista->elementos[lista->tamanho] = elemento;
    lista->tamanho++;
    return 0; // Sucesso
}

/* Função para remover um elemento da lista (por índice)
   Entrada: uma Lista e o índice do elemento que se deseja remover.
   Saída: 1 se o elemento foi removido com sucesso ou 0 caso contrário.
*/
int removeElemento(Lista *lista, int indice) {
    if (indice < 0 || indice >= lista->tamanho) {
        printf("Indice invalido.\n\n");
        return 1; // Índice inválido
    }
    for (int i = indice; i < lista->tamanho - 1; i++) {
        lista->elementos[i] = lista->elementos[i + 1];
    }
    lista->tamanho--;
    printf ("Item removido com sucesso.\n\n");
    return 0; // Sucesso
}

/* Função para imprimir os elementos da lista
   Entrada: uma Lista.
   Saída: os elementos da Lista exibidos na tela.
*/
void imprimiLista(Lista *lista) {
    for (int i = 0; i < lista->tamanho; i++) {
        printf("%d ", lista->elementos[i]);
    }
    printf("\n");
}

int pesquisaInterativa (Lista *lista, int elemento){
    for (int i = 0; i < lista->tamanho; i++){
        if (lista->elementos[i] == elemento){
            printf("Elemento encontrado no indice %d\n\n", i);
            return i;
        }
    }
    printf("Elemento nao encontrado na lista.\n\n");
    return -1;
}

int pesquisaBinaria (Lista *lista, int elemento){
    int inicio = 0;
    int fim = lista->tamanho - 1;
    int meio = (inicio + fim) / 2;

    while (inicio <= fim){
        if (lista->elementos[meio] == elemento){
            printf("Elemento encontrado no indice %d\n\n", meio);
            return meio;
        }
        else if (lista->elementos[meio] > elemento){
            fim = meio - 1;
            meio = (inicio + fim) / 2;
        }
        else{
            inicio = meio + 1;
            meio = (inicio + fim) / 2;
        }
    }
    printf("Elemento nao encontrado na lista.\n\n");
    return -1;
}

void merge(int *vet, int inicio, int meio, int fim){
    int i = inicio, j = meio+1, k = 0;
    int tamanho = (fim - inicio) + 1;
    int *vaux = (int*) calloc (tamanho, sizeof(int));

    while(i <= meio && j <= fim){
        if (vet[i] < vet[j]){
            vaux[k] = vet[i];
            k++;
            i++;
        }
        else{
            vaux[k] = vet[j];
            k++;
            j++;
        }
    }

    while (i <= meio){
        vaux[k] = vet[i];
        k++;
        i++;
    }

    while (j <= fim){
        vaux[k] = vet[j];
        k++;
        j++;
    }

    for(k = 0, i = inicio; k < tamanho; k++, i++){
        vet[i] = vaux[k];
    }

    free(vaux);
}

void mergesortDeFato(int *vet, int inicio, int fim){
    if (inicio >= fim){
        return;
    }
    int meio = (inicio + fim) / 2;
    mergesortDeFato(vet, inicio, meio);
    mergesortDeFato(vet, meio+1, fim);
    merge(vet, inicio, meio, fim);
}

void mergesort(Lista *lista){
    mergesortDeFato(lista->elementos, 0, lista->tamanho-1);
}

int main() {
    Lista minhaLista;
    inicializaLista(&minhaLista);

    adicionaElemento(&minhaLista, 20);
    adicionaElemento(&minhaLista, 40);
    adicionaElemento(&minhaLista, 67);
    adicionaElemento(&minhaLista, 8);

    printf("Lista inicial: ");
    imprimiLista(&minhaLista);

    //removeElemento(&minhaLista, 1); // Remove o elemento de índice 1 (20)

    //printf("Lista apos remocao: ");
    //imprimiLista(&minhaLista);

    mergesort(&minhaLista);
    imprimiLista(&minhaLista);

    int aux = pesquisaBinaria(&minhaLista, 8);
    printf("%d", aux);

    int elemento;

    Lista minhaLista2;
    inicializaLista(&minhaLista2);

    printf("1 - Inserir item na lista\n2 - Remover item da lista\n3 - Exibir lista\n4 - Pesquisar item na lista (ordene primeiro)\n5 - Ordenar crescentemente a lista\n6 - Sair\n\n");
    printf("Digite: ");
    scanf("%d", &aux);

    while(aux != 6){
        switch (aux){
            case 1:
                printf("Qual item deseja inserir?\n");
                scanf("%d", &elemento);
                aux = adicionaElemento(&minhaLista2, elemento);
                break;
            case 2:
                printf("Qual item que deseja remover?\n");
                imprimiLista(&minhaLista2);
                scanf("%d", &elemento);
                aux = pesquisaInterativa(&minhaLista2, elemento);
                if (aux==-1){
                    break;
                }
                removeElemento(&minhaLista2, aux);
                break;
            case 3:
                imprimiLista(&minhaLista2);
                break;
            case 4:
                printf("Qual item deseja pesquisar?\n");
                imprimiLista(&minhaLista2);
                scanf("%d", &elemento);
                aux = pesquisaBinaria(&minhaLista2, elemento);
                break;
            case 5:
                mergesort(&minhaLista2);
                imprimiLista(&minhaLista2);
                break;
            default:
                printf("Valor invalido.\n\n");
                break;
        }
        printf("1 - Inserir item na lista\n2 - Remover item da lista\n3 - Exibir lista\n4 - Pesquisar item na lista (ordene primeiro)\n5 - Ordenar crescentemente a lista\n6 - Sair\n\n");
        printf("Digite: ");
        scanf("%d", &aux);
    }
    printf("Fim do programa.\n");

    return 0;
}
