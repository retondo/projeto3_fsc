#include "listas.h"
#include "listaVerticesOrigem.h"
#include <locale.h>

void lerArquivo(char *caminho);

int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    char caminho[150];

    printf("Insira o caminho do arquivo a ser lido: ");
    scanf("%s", caminho);
    lerArquivo(caminho);

    return 0;
}

void lerArquivo(char *caminho) {
    FILE *file;
    int numeroArestas;
    char c_atual, c_anterior = 0;

    // Criando lista de arestas e de vértices de origem
    listaArestas *l_arestas = (listaArestas *) malloc(sizeof(listaArestas));
    listaVerticesOrigem *l_vertices = (listaVerticesOrigem *) malloc(sizeof(listaVerticesOrigem));
    lista_arestas_iniciar(l_arestas);

    file = fopen(caminho, "r");

    // Leitura da primeira linha
    fscanf(file, "%i", &numeroArestas);

    // Leitura das arestas
    for ( ; numeroArestas != 0; numeroArestas--) {
        dadosArestas *a = (dadosArestas *) malloc(sizeof(dadosArestas));
        fscanf(file, "R%i,%i R%i,%i C%i", &a->aresta, &a->vertice1, &a->aresta, &a->vertice2, &a->custo);
        lista_arestas_inserir(l_arestas, a);
    }

    // Leitura dos vértices de origem de tráfego
    while ( (c_atual = fgetc(file)) != '0') {
        if (c_atual == 'V')
            c_anterior = c_atual;
        else if (c_anterior == 'V') {

        }

    }

    fclose(file);
}
