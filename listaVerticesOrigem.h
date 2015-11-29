#ifndef LISTA_H_
#define LISTA_H_

#include "dadosLista.h"
#include "listas.h"

typedef struct No {
    dadosVerticesOrigem *info;
    struct No *prox;
} no;

typedef struct Lista {
    no *inicio;
    no *fim;
    int tam;
} listaVerticesOrigem;

int lista_iniciar(listaVerticesOrigem *lista);
void lista_inserir(listaVerticesOrigem *lista, dadosVerticesOrigem *elemento);
void lista_remover(listaVerticesOrigem *lista);
void imprimir_lista(listaVerticesOrigem *lista);
int lista_vazia(listaVerticesOrigem *lista);

#endif
