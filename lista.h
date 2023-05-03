//
// Created by nava on 29/03/23.
//

#ifndef INC_03_TAREFAS_LISTA_H
#define INC_03_TAREFAS_LISTA_H

#include "utils.h"

// Constantes
enum {
    NAO_ACHEI = -1
};

// Tarefa
struct Tarefa {
    char nome[51];
    char descricao[251];
};

// Variáveis
extern int tamanho;
extern struct Tarefa *lista;
extern int posicao;

// Protótipos
BOOLEAN adicionar(struct Tarefa *valor);
int quantidadeElementos();
BOOLEAN buscarPorIndice(int indice, struct Tarefa *valor);
int buscarPorValor(struct Tarefa *valor);
void excluir(struct Tarefa *valor);
void ordenar();
void expandir();

void inicializar();
void finalizar();

#endif //INC_03_TAREFAS_LISTA_H
