#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "Arvore.h"

char escolha();
void inserir (tpNo **arvore);
//void deletar (tpNo **arvore);
void pesquisar (tpNo *arvore);
void altura (tpNo *arvore);

int main (){
    tpNo* T;
    T = initArvore();
    
    char letra = escolha();
    do{
        switch (letra){
            case '1':
                inserir(&T);
                break;
            case '2':
                printf("deletar.\n");
                break;
            case '3':
                pesquisar(T);
                break;
            case '4':
                altura(T);
                break;
            default:
                break;
        }
        letra = escolha();
    } while(letra != '5');

    printf("FIM.\n");
    return 0;
}

char escolha(){
    char escolha = 'a';
    printf("--------------------------------Programa Arvore--------------------------------\n");
    printf("1 - Inserir no.\n2 - Deletar no.\n3 - Pesquisar no.\n4 - Altura da arvore.\n5 - Sair.\n");
    while (escolha != '1' && escolha != '2' && escolha != '3' && escolha != '4' && escolha != '5'){
        printf("Digite: ");
        escolha = getch();
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