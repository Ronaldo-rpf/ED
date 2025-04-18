#include <stdio.h>
#include <stdlib.h>

#include "ListaE.h"
#include "Interface.h"
#include <conio.h>

char menu(){
  char escolha;

  printf("\n----------------------------");
  printf("\n 1 - Cadastrar Aluno");
  printf("\n 2 - Exibir Alunos");
  printf("\n 3 - Consultar Aluno");
  printf("\n 4 - Sair do programa");
  printf("\n 5 - Remover Aluno");
  printf("\n Escolha uma das opções acima: ");
  do{
    escolha = getch();
  }while ( (escolha !='1') && (escolha !='2') && (escolha !='3') && (escolha !='4') && (escolha != '5'));
  printf(" %c \n----------------------------", escolha);
  return  escolha;
}

void cadastrarLstE(tpNo **lstAl){
    tpItem aluno;
    char nome[30];
    unsigned int mat;

    printf("\n Digite o nome do aluno: ");
    fgets(nome, 30, stdin);

    printf("\n Digite a matricula do aluno: ");
    scanf("%d",&mat);
    fflush(stdin);
    //getchar();

    aluno = setItem(nome,mat);
    tpNo *lstAux =insertLstE(*lstAl, aluno);
    if ( isEmptyLstE(lstAux) ){
        printf("\n ERRO - aluno não cadastrado");
    } else {
        printf("\n CADASTRO COM SUCESSO!!!");
        (*lstAl) = lstAux;
    }

}

void consultarLstE(tpNo *lstAl){
    unsigned int mat;

    printf("\n Digite a matricula do aluno: ");
    scanf("%d",&mat);
    tpItem *al = searchItemLstE(lstAl,mat);
    if ( al != NULL ){
        printf("\n aluno cadastrado");
        printf("\n Nome do aluno: %s", al->nome);
    } else {
        printf("\n ALUNO NÃO CADASTRADO!!!");
    }
}

void lstEncadeada(){
    tpNo *lstAlunos = initLstE();
    printf("PROGRAMA ALUNOS!\n");
    char op;
    do{
            op = menu();
            switch (op){
                case '1': cadastrarLstE(&lstAlunos);
                          break;
                case '2': printLstE(lstAlunos);
                          break;
                case '3': consultarLstE(lstAlunos);
                          break;
                case '4': printf("\n Hasta la vista baby!\n\n");
                          break;
                case '5': removerLstE(&lstAlunos);
                          break;
            }
    }while (op != '4');
}

void removerLstE(tpNo **lstAl){
    unsigned int mat;

    if(*lstAl == NULL){
        printf("\n A lista nao tem nenhum aluno");
        return;
    }

    printf("\n Digite a matricula do aluno: ");
    scanf("%d",&mat);
    getchar();

    tpNo *al = removeItemLstEAux(lstAl, mat);
    
    if ( al != NULL || *lstAl == NULL){
        printf("\n aluno Removido");
    } else {
        printf("\n ALUNO NAO CADASTRADO!!!");
    }
}