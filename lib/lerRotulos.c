#include <stdio.h>
#include <string.h>
#include "lerRotulos.h"

void transforma_em_bin(int endereco, char *bin) {
    for(int i = 31; i >= 0; i--) {
        bin[31-i] = ((endereco >> i) & 1) ? '1' : '0';
    }
    bin[32] = '\0';
}

void salvarEnderecos(rotulo *rotulos, int quantidadeDeRotulos) {
    FILE *arquivo = fopen("enderecos.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s\n", arquivo);
        return;
    }

    for (int i = 0; i < quantidadeDeRotulos; i++) {
        fprintf(arquivo, rotulos[i].enderecoMemoria);
        if (i != quantidadeDeRotulos - 1) {
            fprintf(arquivo, "\n");
        } 
    }

    fclose(arquivo);
}

int encontrarRotulos(char *nomeArquivo) {
    rotulo rotulos[250];
    int indiceDoRotulo = 0;
    int enderecoMemoriaAtual = 0;
    char buffer[250];

    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s\n", nomeArquivo);
        return 1;
    }
    
    while(fgets(buffer, 250, arquivo)) {
        size_t len = strlen(buffer);
        
        // Checando se o buffer termina com ':'
        if (len > 0 && buffer[len-2] == ':') {
            rotulo rotulo;
            buffer[len - 2] = '\0';
            //printf("Rotulo encontrado: %s\n", buffer);
            
            strcpy(rotulo.nome, buffer);
            transforma_em_bin(enderecoMemoriaAtual, rotulo.enderecoMemoria);
            rotulo.enderecoMemoriaInt = enderecoMemoriaAtual;
            printf("Endereco: %d\nEndereco em binario: %s\n\n", rotulo.enderecoMemoriaInt, rotulo.enderecoMemoria);
            
            rotulos[indiceDoRotulo] = rotulo;
            indiceDoRotulo++;
        } else {
            enderecoMemoriaAtual += 4;
        }
    }

    for (int i = 0; i < indiceDoRotulo; i++) {
        printf("Rotulo: %s, Endereco: %s\n", rotulos[i].nome, rotulos[i].enderecoMemoria);
    }
    
    fclose(arquivo);
    salvarEnderecos(rotulos, indiceDoRotulo);
    return 0;   
}

