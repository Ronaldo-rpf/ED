#include <stdio.h>
#include <stdlib.h>


#include "ListaDE.h"
#include <conio.h>      //as fun��es do conio s�o �teis para manipular caracteres na tela, especificar cor de car�cter e de fundo.

char menu();
void inserirAluno(tpLDE *lde);
void deletarAluno(tpLDE *lde);
void pesquisarAluno(tpLDE lde);
void quantosId (tpLDE lde);
void ordenadoOuNao (tpLDE lde);

int main()
{   tpLDE lde = initLstDE();
    //char escolha;
    //escolha = menu();
/*
    while (escolha != '5'){
        switch (escolha){
            case '1':
                inserirAluno(&lde);
                break;
            case '2':
                deletarAluno(&lde);
                break;
            case '3':
                printLstDE(lde);
                break;
            case'4':
                pesquisarAluno(lde);
                break;
            case '6':
                quantosId(lde);
                break; 
            case '7':
                ordenadoOuNao(lde);
                break;
            default:
                printf("Opcao invalida.\n\n");
                break;
        }
        escolha = menu();
    }
*/
    inserirAluno(&lde);
    inserirAluno(&lde);
    inserirAluno(&lde);
    printLstDE(lde);

    tpLDE L2 = initLstDE();
    inserirAluno(&L2);
    inserirAluno(&L2);
    inserirAluno(&L2);
    printLstDE(L2);

    copiaL1emL2existente(lde, &L2);
    printLstDE(L2);

    printf("\n FIM!\n");
    return 0;
}

char menu(){
    char escolha = 'a';
    printf("------- Programa Lista Duplamente Encadeada: -------\n");
    printf("1 - Inserir aluno.\n2 - Deletar aluno.\n3 - Mostrar alunos cadastrados.\n4 - Pesquisar aluno.\n5 - Sair do programa.\n6 - Quantos id's igual.\n7 - Esta ordenada ou nao.\n");
    while(escolha != '1' && escolha != '2' && escolha != '3' && escolha != '4' && escolha != '5' && escolha != '6' && escolha != '7'){
        printf("Digite a seguir: ");
        escolha = getch();
        printf("\nEscolha feita: %c\n", escolha);
    }
    return escolha;
}

void inserirAluno(tpLDE *lde){
    tpItem aluno;
    char nome[40];
    unsigned int mat;
    printf("Nome do aluno: ");
    fgets(nome, 40, stdin);
    printf("Matricula do aluno: ");
    scanf("%d", &mat);
    getchar();
    aluno = setItem(nome, mat);

    int verificacao = insertLstDE_SR(lde, aluno);
    if (verificacao){
        printf("Erro ao inserir aluno.\n\n");
    }
    else{
        printf("Item inserido com sucesso.\n\n");
    }
    return;
}

void deletarAluno(tpLDE *lde){
    unsigned int mat;
    printf("Matricula do aluno: ");
    scanf("%d", &mat);
    getchar();
    int verificacao = deleteLstDE(lde, mat);
    if(verificacao){
        printf("Erro ao remover aluno.\n\n");
    }
    else{
        printf("Aluno removido com sucesso.\n\n");
    }
    return;
}

void pesquisarAluno(tpLDE lde){
    unsigned int mat;
    printf("Matricula do aluno: ");
    scanf("%d", &mat);
    getchar();
    tpItem aluno = searchItemLstDE(lde, mat);
    if (aluno.id == 0){
        printf("Aluno nao encontrado.\n\n");
    }
    else{
        printf("Aluno encontrado.\n\n");
        printItem(aluno);
    }
    return;
}

void quantosId (tpLDE lde){
    unsigned int mat;
    printf("Qual o id a ser pesquisado: ");
    scanf("%d", &mat);
    getchar();
    int cont = quantosIds(lde, mat);
    printf("Quantidade de ids iguais ao digitado: %d\n", cont);
    return;
}

void ordenadoOuNao (tpLDE lde){
    int aux = ordenadaOuNao(lde);
    if (aux){
        printf("A lista esta ordenada.\n");
        return;
    }
    else{
        printf("A lista NAO esta ordenada.\n");
        return;
    }
}

