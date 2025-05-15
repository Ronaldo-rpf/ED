#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "Fila.h"

char menu();
void inserir(tpFila *fila);
void deletarQualquer(tpFila *fila);
void pesquisar(tpFila fila);

int main(){
    tpFila fila = initFila();
    
    char escolha;
    escolha = menu();

    while(escolha != '6'){
        switch (escolha){
            case '1':
                inserir(&fila);
                break;
            case'2':
                dequeue(&fila);
                break;
            case'3':
                deletarQualquer(&fila);
                break;
            case'4':
                pesquisar(fila);
                break;
            case '5':
                printarFila(fila);
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
    printf("-----------Programa Fila-----------\n");
    printf("1 - Inserir\n2 - Deletar aluno\n3 - Deletar qualquer aluno da Fila\n4 - Pesquisar aluno\n5 - Mostrar fila\n6 - Sair\n");
    while (escolha != '1' && escolha != '2' && escolha != '3' && escolha != '4' && escolha != '5' && escolha != '6'){
        printf("Digite a seguir: ");
        escolha = getch();
        printf("Escolha feita: %c\n", escolha);
    }
    return escolha;

}

void inserir(tpFila *fila){
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
    int veri = enqueue(fila, aluno);
    if (veri){
        printf("Erro ao inserir aluno.\n");
        return;
    }
    printf("Aluno inserido com sucesso.\n");
    return;
}

void deletarQualquer(tpFila *fila){
    unsigned int mat;
    printf("Matricula do aluno: ");
    scanf("%d", &mat);
    getchar();

    int veri = deleteFila(fila, mat);
    if (veri){
        printf("Aluno nao foi encontrado. Fila deletada.\n");
        return;
    }
    printf("Aluno deletado.\n");
    return;
}

void pesquisar(tpFila fila){
    unsigned int mat;
    printf("Matricula do aluno: ");
    scanf("%d", &mat);
    getchar();

    tpItem aluno = searchItemFila(fila, mat);
    if (aluno.id == 0){
        printf("Aluno nao encontrado.\n");
        return;
    }
    printf("Aluno encontrado.\n");
    printf("Nome: %s", aluno.nome);
    return;
}