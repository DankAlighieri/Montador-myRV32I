#include <stdio.h>
#include <string.h>
#include "lerRotulos.h"

int encontrarRotulos(char *nomeArquivo) {
    rotulo rotulos[250];
    int indiceDoRotulo = 0;
    int enderecoMemoriaAtual = 0;


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
            rotulo rotulo;
            printf("Rotulo encontrado: %s\n", buffer);
            strcpy(rotulo.nome, buffer);
            rotulo.enderecoMemoria = enderecoMemoriaAtual;
            rotulos[indiceDoRotulo] = rotulo;
            indiceDoRotulo++;
        } else {
            enderecoMemoriaAtual += 4;
        }
    }
    fclose(arquivo);
    return 0;   
}