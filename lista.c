//
// Created by nava on 29/03/23.
//

#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Variáveis
int tamanho = 5;
struct Tarefa *lista;
int posicao = 0;

void inicializar()
{
    lista = malloc(tamanho * sizeof(struct Tarefa));
    if(!lista)
    {
        printf("Erro na alocacao de memoria!\n");
        exit(-1);
    }
}

void finalizar()
{
    free(lista);
}

BOOLEAN adicionar(struct Tarefa *valor)
{
    if(posicao == tamanho)
    {
        return FALSE;
    }
    else
    {
        strcpy(lista[posicao].nome, valor->nome);
        strcpy(lista[posicao].descricao, valor->descricao);
        posicao++;
        return TRUE;
    }
}

int quantidadeElementos()
{
    return posicao;
}

BOOLEAN buscarPorIndice(int indice, struct Tarefa *valor)
{
    if(indice < 0 || indice >= posicao)
    {
        return FALSE;
    }
    else
    {
        strcpy(valor->nome, lista[indice].nome);
        strcpy(valor->descricao, lista[indice].descricao);
        return TRUE;
    }
}

int buscarPorValor(struct Tarefa *valor)
{
    int i;
    for(i = 0; i < posicao; i++)
    {
        if(strcmp(lista[i].nome, valor->nome) == 0)
        {
            return i;
        }
    }

    return NAO_ACHEI;
}

void excluir(struct Tarefa *valor)
{
    int indice;
    int i;

    indice = buscarPorValor(valor);

    if(indice != NAO_ACHEI)
    {
        for(i = indice; i < (posicao - 1); i++)
        {
            lista[i] = lista[i + 1];
        }

        posicao--;
    }
}

void ordenar()
{
    if(posicao != 0)
    {
        int i;
        int j;
        struct Tarefa aux;

        for(i = 0; i < (posicao - 1); i++)
        {
            for(j = i + 1; j < posicao; j++)
            {
                if(strcmp(lista[i].nome, lista[j].nome) > 0)
                {
                    aux = lista[i];
                    lista[i] = lista[j];
                    lista[j] = aux;
                }
            }
        }
    }
}

void expandir()
{
    int novoTamanho = tamanho * 1.5;
    struct Tarefa *aux;
    int i;

    aux = malloc(novoTamanho * sizeof(struct Tarefa));
    if(!aux)
    {
        printf("Erro de alocacao de memoria!\n");
        exit(-1);
    }

    for(i = 0; i < tamanho; i++)
    {
        aux[i] = lista[i];
    }

    free(lista);

    tamanho = novoTamanho;
    lista = aux;
}