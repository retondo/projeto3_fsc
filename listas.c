#include "listas.h"

// ======================================== ARESTA ========================================

int lista_arestas_vazia(listaArestas *l_arestas)
{
    if (l_arestas->inicio == NULL)
        return 1;
    else
        return 0;
}

int lista_arestas_iniciar(listaArestas *l_arestas)
{
    // Os argumentos da lista são iniciados como nulos se a lista existir
    if (l_arestas) {
        l_arestas->inicio = NULL;
        l_arestas->fim = NULL;
        l_arestas->tam = 0;
        return 1;
    } else {
        printf("A lista não existe!!");
        return 0;
    }
}

void lista_arestas_inserir(listaArestas *l_arestas, dadosArestas *elemento)
{
    // Alocando o nó novo na memória
    no_aresta *novo = (no_aresta *) malloc(sizeof(no_aresta));
    // Apontando o nó novo para o nó elemento
    novo->info = elemento;

    // Se a lista estiver vazia insere o novo nó
    if (lista_arestas_vazia(l_arestas)) {
        l_arestas->inicio = novo;
        l_arestas->fim = novo;
    } else {
        l_arestas->fim->prox = novo;
        l_arestas->fim = novo;
    }
    l_arestas->tam++;
}

void lista_arestas_remover(listaArestas *l_arestas, no_aresta *elemento)
{
    no_aresta *atual = l_arestas->inicio;
    no_aresta *anterior = NULL;

    while (atual != elemento) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual = l_arestas->fim = l_arestas->inicio) {
        l_arestas->inicio = NULL;
        l_arestas->fim = NULL;
    } else if (atual = l_arestas->inicio) {
        l_arestas->inicio = l_arestas->inicio->prox;
    } else if (atual = l_arestas->fim) {
        l_arestas->fim = anterior;
        anterior->prox = NULL;
    } else {
        anterior->prox = atual->prox;
    }
    l_arestas->tam--;

    free(elemento);
}

/*void imprimir_lista(lista *l) {
    no *n;
    n = l->inicio;

    //fl_clear_browser(fdui->dados_programas);

    while(n != NULL) {
        fl_add_browser_line_f(fdui->dados_programas, "%i", n->info->prioridade);
        n = n->prox;
    }

    //free(n);
}*/

// ======================================== VERTICE =======================================

int lista_vertices_vazia(listaVerticesOrigem *l_vertices)
{
    if (l_vertices->inicio == NULL)
        return 1;
    else
        return 0;
}

int lista_vertices_iniciar(listaVerticesOrigem *l_vertices)
{
    // Os argumentos da lista são iniciados como nulos se a lista existir
    if (l_vertices) {
        l_vertices->inicio = NULL;
        l_vertices->fim = NULL;
        l_vertices->tam = 0;
        return 1;
    } else {
        printf("A lista de vértices não existe!!");
        return 0;
    }
}

void lista_vertices_inserir(listaVerticesOrigem *l_vertices, dadosVerticesOrigem *elemento)
{
    // Alocando o nó novo na memória
    no_vertices *novo = (no_vertices *) malloc(sizeof(no_vertices));
    // Apontando o nó novo para o nó elemento
    novo->info = elemento;

    // Se a lista estiver vazia insere o novo nó
    if (lista_vertices_vazia(l_vertices)) {
        l_vertices->inicio = novo;
        l_vertices->fim = novo;
    } else {
        l_vertices->fim->prox = novo;
        l_vertices->fim = novo;
    }
    l_vertices->tam++;
}

void lista_vertices_remover(listaVerticesOrigem *l_vertices, no_vertices *elemento)
{
    no_vertices *atual = l_vertices->inicio;
    no_vertices *anterior = NULL;

    while (atual != elemento) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual = l_vertices->fim = l_vertices->inicio) {
        l_vertices->inicio = NULL;
        l_vertices->fim = NULL;
    } else if (atual = l_vertices->inicio) {
        l_vertices->inicio = l_vertices->inicio->prox;
    } else if (atual = l_vertices->fim) {
        l_vertices->fim = anterior;
        anterior->prox = NULL;
    } else {
        anterior->prox = atual->prox;
    }
    l_vertices->tam--;

    free(elemento);
}



