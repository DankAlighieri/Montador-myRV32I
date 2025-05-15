#include <stdio.h>
#include <string.h>
#include "lerRotulos.h"

int encontrarRotulos(char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s\n", nomeArquivo);
        return 1;
    }
    
    char buffer[250];
    while(fgets(buffer, 250, arquivo)) {
        size_t len = strlen(buffer);
        
        // Checando se o buffer termina com ':'
        if (len > 0 && buffer[len-2] == ':') {
            printf("Rotulo encontrado: %s\n", buffer);
        }
    } 
    fclose(arquivo);
    return 0;   
}