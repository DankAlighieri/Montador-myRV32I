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
            
            buffer[len - 2] = '\0';
            
            strcpy(rotulo.nome, buffer);
            rotulo.enderecoMemoria = enderecoMemoriaAtual;
            rotulos[indiceDoRotulo] = rotulo;
            indiceDoRotulo++;
        } else {
            enderecoMemoriaAtual += 4;
        }
    }

    for (int i = 0; i < indiceDoRotulo; i++) {
        printf("Rotulo: %s, Endereco: %d\n", rotulos[i].nome, rotulos[i].enderecoMemoria);
    }

    fclose(arquivo);
    return 0;   
}
unsigned int transforma_em_bin(int endereco) {
    unsigned int binario = 0;
    unsigned int mascara = 1;
    unsigned int resultado = 0;
    int posicao = 0;

    // Converte o endereço para binário no formato de 32 bits
    while (endereco > 0) {
        if (endereco & mascara) {
            resultado |= (1 << posicao);
        }
        endereco >>= 1;
        posicao++;
    }

    return resultado;
}