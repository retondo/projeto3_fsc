#include "listas.h"
#include <locale.h>
#include <strings.h>

void lerArquivo(char *caminho);

listaArestas *l_arestas;
listaVerticesOrigem *l_vertices;

int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    char caminho[150];

    printf("Insira o caminho do arquivo a ser lido: ");
    scanf("%s", caminho);
    lerArquivo(caminho);
    lista_arestas_imprimir(l_arestas);
    lista_vertices_imprimir(l_vertices);

    return 0;
}

void arvoreMinima() {
    listaArestas *arvore_minima = (listaArestas *) malloc(sizeof(listaArestas));
    // Lista auxiliar de todas as arestas
    listaArestas *aux = (listaArestas *) malloc(sizeof(listaArestas));
    listaArestas *copia = (listaArestas *) malloc(sizeof(listaArestas));
    lista_arestas_iniciar(aux);
    lista_arestas_iniciar(arvore_minima);
    copia = l_arestas;
    no_vertices *nv = l_vertices->inicio;
    no_aresta *na;
    int verticesUsados[l_arestas->tam*2], i = 0;

    while (nv->prox != NULL) {
        while (!lista_arestas_vazia(l_arestas)) {
            // Parte a busca da árvore pelo vértice de origem
            na = copia->inicio;
            while (na->prox != NULL) {
                if (na->info->vertice1 == nv->info->vertice0 || na->info->vertice2 == nv->info->vertice0) {
                    if (lista_arestas_vazia(aux))
                        lista_arestas_inserir(aux, na->info);
                    else if (na->info->custo < aux->inicio->info->custo) {
                        lista_arestas_remover(aux, aux->inicio);
                        lista_arestas_remover(copia, aux->inicio);
                        lista_arestas_inserir(aux, na->info);
                    }
                    verticesUsados[i] = nv->info->vertice0;
                }
                na = na->prox;
            }
        }
        nv = nv->prox;
    }
}

void lerArquivo(char *caminho) {
    FILE *file;
    int numeroArestas;
    char c_atual, c_anterior = 0;

    // Criando lista de arestas e de vértices de origem
    l_arestas = (listaArestas *) malloc(sizeof(listaArestas));
    l_vertices = (listaVerticesOrigem *) malloc(sizeof(listaVerticesOrigem));
    lista_arestas_iniciar(l_arestas);
    lista_vertices_iniciar(l_vertices);

    if (!(file = fopen(caminho, "r"))) {
        printf("\nNão foi possível abrir o arquivo!!\n");
        exit(1);
    } else {

        // Leitura da primeira linha
        fscanf(file, "%d\n", &numeroArestas);

        // Leitura das arestas
        for ( ; numeroArestas != 0; numeroArestas--) {
            dadosArestas *a = (dadosArestas *) malloc(sizeof(dadosArestas));
            fscanf(file, "R%d,%d R%d,%d C%d\n", &a->aresta, &a->vertice1, &a->aresta, &a->vertice2, &a->custo);
            lista_arestas_inserir(l_arestas, a);
        }

        // Leitura dos vértices de origem de tráfego
        while ( (c_atual = fgetc(file)) != '0') {
            if (c_atual == 'V') {
                c_anterior = c_atual;
            } else if (c_anterior == 'V') {
                dadosVerticesOrigem *v = (dadosVerticesOrigem *) malloc(sizeof(dadosVerticesOrigem));
                v->vertice0 = atoi(&c_atual);
                c_anterior = 0;
                lista_vertices_inserir(l_vertices, v);
            }
        }

        fclose(file);
    }
}












