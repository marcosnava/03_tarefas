#include <stdio.h>
#include <string.h>
#include "lista.h"

// Constantes
enum {
    OP_NAO_SELECIONADA = 0,
    OP_ADICIONAR = 1,
    OP_BUSCAR = 2,
    OP_EXCLUIR = 3,
    OP_SAIR = 4
};

// Prototipos
int menu();
void imprimir();

int main() {
    inicializar();

    int opcao = OP_NAO_SELECIONADA;
    char nome[51];
    char descricao[251];
    struct Tarefa tarefa;
    int indice;
    BOOLEAN deuCerto;

    while(opcao != OP_SAIR)
    {
        imprimir();
        printf("\n");

        opcao = menu();

        switch (opcao) {
            case OP_ADICIONAR:
                printf("Digite o nome da tarefa: ");
                fgets(nome, 50, stdin);
                nome[strcspn(nome, "\n")] = 0;

                printf("Digite da descricao da tarefa: ");
                fgets(descricao, 250, stdin);
                descricao[strcspn(descricao, "\n")] = 0;

                strcpy(tarefa.nome, nome);
                strcpy(tarefa.descricao, descricao);

                deuCerto = adicionar(&tarefa);
                if(deuCerto)
                {
                    ordenar();
                }
                else
                {
                    expandir();
                    adicionar(&tarefa);
                    ordenar();
                }
                break;
            case OP_BUSCAR:
                printf("Digite o nome da tarefa: ");
                fgets(nome, 50, stdin);
                nome[strcspn(nome, "\n")] = 0;

                strcpy(tarefa.nome, nome);

                indice = buscarPorValor(&tarefa);
                if(indice != -1)
                {
                    buscarPorIndice(indice, &tarefa);
                    printf("Tarefa encontrada:\n");
                    printf("\tNome: %s\n", tarefa.nome);
                    printf("\tDescricao: %s\n", tarefa.descricao);
                }
                else
                {
                    printf("*************************\n");
                    printf("* TAREFA NAO ENCONTRADA *\n");
                    printf("*************************\n\n");
                }
                printf("Pressione <ENTER> para continuar!\n");
                getchar();
                break;
            case OP_EXCLUIR:
                printf("Digite o nome da tarefa: ");
                fgets(nome, 50, stdin);
                nome[strcspn(nome, "\n")] = 0;

                strcpy(tarefa.nome, nome);

                excluir(&tarefa);
                break;
            case OP_SAIR:
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }
    }

    finalizar();
    return 0;
}

int menu()
{
    int op;
    printf("************************\n");
    printf("*        M E N U       *\n");
    printf("************************\n");
    printf("* 1 - Adicionar Tarefa *\n");
    printf("* 2 - Localizar Tarefa *\n");
    printf("* 3 - Excluir Tarefa   *\n");
    printf("* 4 - Sair             *\n");
    printf("************************\n");
    printf("Digite sua opcao: ");
    scanf("%d", &op);
    scanf("%*c");

    return op;
}

void imprimir()
{
    int i;
    struct Tarefa tarefa;

    printf("+----------------------------------------------------+\n");
    printf("|                   T A R E F A S                    |\n");
    printf("+----------------------------------------------------+\n");

    if(quantidadeElementos()!=0)
    {
        for(i = 0; i < quantidadeElementos(); i++)
        {
            buscarPorIndice(i, &tarefa);
            printf("Tarefa: %d\n", i + 1);
            printf("Nome: %s\n",tarefa.nome);
            printf("Descicao: %s\n", tarefa.descricao);
            printf("+----------------------------------------------------+\n");
        }
    }

}
