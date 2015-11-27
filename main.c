#include "lista.h"

int main(void)
{
    char caminho[150];

    printf("Insira o caminho do arquivo a ser lido: ");
    scanf("%s", caminho);
    lerArquivo(caminho);

    return 0;
}

void lerArquivo(char *caminho) {
    FILE *file;
    int n, i;

    file = fopen(caminho, "r");

    //Leitura
    fscanf(file, "%i", &n);
    while (i <= n) {
        fscanf(file, "R%i,%i R%i,%i C%i", );
        i++;
    }

}
