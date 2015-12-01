#ifndef CALCULARCAMINHO_H_
#define CALCULARCAMINHO_H_

#include "listas.h"
#include <string.h>

listaArestas *l_arestas;
listaVerticesOrigem *l_vertices;

void copiarLista(listaArestas *origem, listaArestas *destino);
int vertices_usados(int *verticesUsados, int v1, int v2);
void lerArquivo(char *caminho);
void arvoreMinima();

#endif
