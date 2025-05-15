#include "lib/lerRotulos.h"
#include <stdio.h>
#include <stdlib.h> 

int main() {
    //char *nomeArquivo = (char *)malloc(sizeof(char) * 250);
    char nomeArquivo[250] = "source.asm";
    //printf("Digite o caminho do arquivo: ");
    //scanf("%249s", nomeArquivo);
    encontrarRotulos(nomeArquivo);

    
    return 0;
}