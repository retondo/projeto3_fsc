#ifndef LISTA_H_
#define LISTA_H_

#include <stdio.h>
#include <stdlib.h>
#include "dadosLista.h"

// ======================================== ARESTA ========================================
typedef struct No {
    dadosArestas *info;
    struct No *prox;
} no_aresta;

typedef struct Lista {
    no_aresta *inicio;
    no_aresta *fim;
    int tam;
} listaArestas;

int lista_arestas_iniciar(listaArestas *l_arestas);
int lista_arestas_vazia(listaArestas *l_arestas);
void lista_arestas_inserir(listaArestas *l_arestas, dadosArestas *elemento);
void lista_arestas_remover(listaArestas *l_arestas, no_aresta *elemento);
void lista_arestas_imprimir(listaArestas *l_arestas);
// ========================================================================================

// ======================================== VERTICE =======================================
typedef struct No_Vertices {
    dadosVerticesOrigem *info;
    listaArestas *l_arestas;
    struct No_Vertices *prox;
} no_vertices;

typedef struct ListaVertices {
    no_vertices *inicio;
    no_vertices *fim;
    int tam;
} listaVerticesOrigem;

int lista_vertices_iniciar(listaVerticesOrigem *l_vertices);
int lista_vertices_vazia(listaVerticesOrigem *l_vertices);
void lista_vertices_inserir(listaVerticesOrigem *l_vertices, dadosVerticesOrigem *elemento);
void lista_vertices_remover(listaVerticesOrigem *l_vertices, no_vertices *elemento);
void lista_vertices_imprimir(listaVerticesOrigem *l_vertices);
// ========================================================================================

#endif
