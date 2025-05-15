#include <stdint.h>
typedef struct {
    char nome[250];
    char enderecoMemoria[33];  // 32 bits + null terminator
    int enderecoMemoriaInt;
} rotulo;

int encontrarRotulos(char *nomeArquivo);
void transforma_em_bin(int endereco, char *bin);