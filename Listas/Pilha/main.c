#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "Pilha.h"

char menu();
void inserir(tpPilha *pilha);
void deletarQualquer(tpPilha *pilha);
void pesquisar(tpPilha pilha);

int main(){
    tpPilha pilha = initPilha();
    
    char escolha;
    escolha = menu();

    while(escolha != '6'){
        switch (escolha){
            case '1':
                inserir(&pilha);
                break;
            case'2':
                pop(&pilha);
                break;
            case'3':
                deletarQualquer(&pilha);
                break;
            case'4':
                pesquisar(pilha);
                break;
            case '5':
                printarPilha(pilha);
                break;
            default:
                printf("Opcao invalida.\n");
                break;
        }
        escolha = menu();
    }

    printf("FIM.\n");
    return 0;
}

char menu(){
    char escolha = 'a';
    printf("-----------Programa Pilha-----------\n");
    printf("1 - Inserir\n2 - Deletar aluno\n3 - Deletar qualquer aluno da pilha\n4 - Pesquisar aluno\n5 - Mostrar pilha\n6 - Sair\n");
    while (escolha != '1' && escolha != '2' && escolha != '3' && escolha != '4' && escolha != '5' && escolha != '6'){
        printf("Digite a seguir: ");
        escolha = getch();
        printf("Escolha feita: %c\n", escolha);
    }
    return escolha;

}

void inserir(tpPilha *pilha){
    char nome[50];
    unsigned int mat;
    tpItem aluno;
    printf("Nome do aluno: ");
    fgets(nome, 50, stdin);
    printf("Matricula do aluno: ");
    scanf("%d", &mat);
    getchar();
    
    aluno.id = mat;
    strcpy(aluno.nome, nome);
    int veri = inserirAluno(pilha, aluno);
    if (veri){
        printf("Erro ao inserir aluno.\n");
        return;
    }
    printf("Aluno inserido com sucesso.\n");
    return;
}

void deletarQualquer(tpPilha *pilha){
    unsigned int mat;
    printf("Matricula do aluno: ");
    scanf("%d", &mat);
    getchar();

    int veri = deletePilha(pilha, mat);
    if (veri){
        printf("Aluno nao foi encontrado. Pilha deletada.\n");
        return;
    }
    printf("Aluno deletado.\n");
    return;
}

void pesquisar(tpPilha pilha){
    unsigned int mat;
    printf("Matricula do aluno: ");
    scanf("%d", &mat);
    getchar();

    tpItem aluno = searchItemPilha(pilha, mat);
    if (aluno.id == 0){
        printf("Aluno nao encontrado.\n");
        return;
    }
    printf("Aluno encontrado.\n");
    printf("Nome: %s", aluno.nome);
    return;
}