//Esse arquivo implementa as funções de interface que o usuário 
// utilizará para manipular e acessar informações do programa 

#include <stdio.h>
#include <stdlib.h>

#include "interface.h"
#include <conio.h>

// Inicializa a lista com um ponteiro tpNo nulo, e a partir daí chama
// a função menu e as demais funções para manipular a lista
// void lstEncadeada(){
//     tpNo *lstAlunos = initLstE();
//     printf("PROGRAMA ALUNOS!\n");
//     char op;
//     do{
//             op = menu();
//             switch (op){
//                 case '1': cadastrarLstE(&lstAlunos);
//                           break;
//                 case '2': printLstE(lstAlunos);
//                           break;
//                 case '3': consultarLstE(lstAlunos);
//                           break;
//                 case '4': RemoverLstE(&lstAlunos);
//                           break;
//                 case '5': OrdenarListaInterface(&lstAlunos);
//                           break;
//                 case '0': printf("\n Hasta la vista baby!");
//             }
//     }while (op != '0');
// }

// //Função menu exibe quais são as opções de entrada para o programa.
// //Ele fica esperando uma entrada válida usando getch() dentro do dowhile, e depois
// //retorna o valor da escolha 
// char menu(){
//     char escolha;
  
//     printf("\n----------------------------");
//     printf("\n 1 - Cadastrar Aluno");
//     printf("\n 2 - Exibir Alunos");
//     printf("\n 3 - Consultar Aluno");
//     printf("\n 4 - Remover Aluno");
//     printf("\n 5 - Ordenar Lista por matricula");
//     printf("\n 0 - Sair do programa");
//     printf("\n Escolha uma das opcoes acima: ");
//     do{
//       escolha = getch();
//     }while ( (escolha !='0') && (escolha !='1') && (escolha !='2') && (escolha !='3') && (escolha !='4') && (escolha !='5'));
//     printf(" %c \n----------------------------", escolha);
//     return  escolha;
// }


// Passa a lista por referência para que a original seja alterada e 
// cadastra um aluno no inicio da lista. 
void cadastrarLstE(tpNo **lstAl){
    tpItem aluno;
    char nome[30];
    unsigned int mat;

    printf("\nDigite o nome do aluno: ");
    fgets(nome, 30, stdin);
    printf("\nDigite a matricula do aluno: ");
    scanf("%d",&mat);
    getchar();
    aluno = setItem(nome,mat);
    tpNo *lstAux =insertLstE(*lstAl, aluno);
    if ( isEmptyLstE(lstAux) ){
        printf("\nERRO - aluno nao cadastrado");
    } else {
        printf("\nCADASTRO COM SUCESSO!!!");
        (*lstAl) = lstAux;
    }

}

//Passa a lista para poder procurar por um determinado item a partir da matricula
// do aluno. Printa o primeiro aluno que encontrar. Se não achar, printa que o 
//aluno não está cadastrado
void consultarLstE(tpNo *lstAl){
    unsigned int mat;

    printf("\nDigite a matricula do aluno: ");
    scanf("%d",&mat);
    getchar();
    tpItem *al = searchItemLstE(lstAl,mat);
    if ( al != NULL ){
        printf("\naluno cadastrado");
        printf("\nNome do aluno: %s", al->nome);
    } else {
        printf("\nALUNO NAO CADASTRADO!!!");
    }
}

void RemoverLstE(tpNo **lstAl){
    unsigned int mat;

    if(*lstAl == NULL){
        printf("\nA lista nao tem nenhum aluno");
        return;
    }

    printf("\nDigite a matricula do aluno: ");
    scanf("%d",&mat);
    getchar();

    tpNo *al = removeItemLstEAux(lstAl, mat);
    
    if ( al != NULL || *lstAl == NULL){
        printf("\naluno Removido");
    } else {
        printf("\nALUNO NAO CADASTRADO!!!");
    }
}

void OrdenarListaInterface(tpNo **lstAl){
    ordenarLista(lstAl);
    printf("\nLista foi ordenada");
}
