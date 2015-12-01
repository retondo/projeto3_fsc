#include "calcularCaminho.h"
#include <locale.h>

int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    char caminho[150];

    printf("Insira o caminho do arquivo a ser lido: ");
    scanf("%s", caminho);
    lerArquivo(caminho);
    arvoreMinima();

    return 0;
}














