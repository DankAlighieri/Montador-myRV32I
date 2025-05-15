typedef struct {
    char nome[250];
    int enderecoMemoria;
} rotulo;

int encontrarRotulos(char *nomeArquivo);
unsigned int transforma_em_bin(int endereco);