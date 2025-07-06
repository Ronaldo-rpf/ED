#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "Arvore.h"

char escolha();
void inserir (tpNo **arvore);
void deletar (tpNo **arvore);
void pesquisar (tpNo *arvore);
void altura (tpNo *arvore);

int main (){
    tpNo* T;
    tpNo** aux = &T;
    T = initArvore();
    
    char letra = escolha();
    do{
        switch (letra){
            case '1':
                inserir(&T);
                fatorBalanceamento(&T);
                break;
            case '2':
                deletar(&T);
                break;
            case '3':
                pesquisar(T);
                break;
            case '4':
                altura(T);
                break;
            case '5':
                printf("Ordenada:\n");
                imprimirOrdenada(T);
                printf("\n\n");
                printf("Nao ordenada:\n");
                imprimirNaoOrdenada(T);
                printf("\n\n");
                break;
            default:
                break;
        }
        letra = escolha();
    } while(letra != '6');

    T->fatorBalanceamento = alturaArvore(T->prtDir) - alturaArvore(T->prtEsq);
    int aux = T->fatorBalanceamento;
    printf("%d", aux);
    T->prtDir->fatorBalanceamento = alturaArvore(T->prtDir->prtDir) - alturaArvore(T->prtDir->prtEsq);
    aux = T->prtDir->fatorBalanceamento;
    printf("%d", aux);
    

    printf("FIM.\n");
    return 0;
}

char escolha(){
    char escolha = 'a';
    printf("--------------------------------Programa Arvore--------------------------------\n");
    printf("1 - Inserir no.\n2 - Deletar no.\n3 - Pesquisar no.\n4 - Altura da arvore.\n5 - Imprimir Arvore.\n6 - Sair.\n");
    while (escolha != '1' && escolha != '2' && escolha != '3' && escolha != '4' && escolha != '5' && escolha != '6'){
        printf("Digite: ");
        escolha = (char) getch();
        printf("Escolha feita: %c\n", escolha);
    }
    return escolha;
}

void inserir (tpNo **arvore){
    int num;
    printf("Numero que deseja inserir: ");
    scanf("%d", &num);
    getchar();

    int aux = insertArvoreR(arvore, num);
    if (aux){
        printf("Erro ao inserir numero.\n\n");
        return;
    }
    printf("Numero inserido com sucesso.\n\n");
    return;
}

void pesquisar (tpNo *arvore){
    int num;
    printf("Numero que deseja pesquisar: ");
    scanf("%d", &num);
    getchar();
    int aux = searchArvoreR(arvore, num);
    if (aux == -1){
        printf("Numero nao encontrado na arvore.\n\n");
        return;
    }
    printf("Numero encontrado: %d\n\n", aux);
    return;
}

void altura (tpNo *arvore){
    int aux = alturaArvore(arvore);
    if (aux == -1){
        printf("A arvore esta vazia.");
        return;
    }
    else if (aux == 0){
        printf("A arvore tem altura %d.\n", aux);
        printf("A arvore possui apenas 1 no.\n");
        return;
    }
    else{
        printf("A arvore tem altura %d.\n", aux);
        return;
    }
}

void deletar(tpNo **arvore){
    if ((*arvore) == NULL){
        printf("Arvore vazia.\n");
        return;
    }
    int num;
    printf("Numero que deseja deletar: ");
    scanf("%d", &num);
    getchar();
    (*arvore) = deleteArvore(arvore, num);
    if (arvore != NULL){
        printf("Numero deletado com sucesso.\n");
        return;
    }
    printf("Falha ao deletar numero.\n");
    return;
}