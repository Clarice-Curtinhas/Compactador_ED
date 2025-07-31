#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "compactador.h"

int main(int argc, const char **argv){

    if (argc < 2){
        printf("Linha de comando com argumentos insuficientes!\n");
        return 1;
    }

    FILE *arquivo_entrada;
    char nome_arquivo[100];
    long tam_arquivo;
    unsigned char *buffer;
    size_t bytes_lidos;

    strcpy(nome_arquivo, argv[1]);
    arquivo_entrada = fopen(nome_arquivo, "rb");

    if (arquivo_entrada == NULL){
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }

    // Calcula o tamanho do arquivo
    fseek(arquivo_entrada, 0, SEEK_END);
    tam_arquivo = ftell(arquivo_entrada);
    fseek(arquivo_entrada, 0, SEEK_SET);

    // Aloca um buffer para armazenar os dados do arquivo
    buffer = (unsigned char*) calloc(1, tam_arquivo);

    if (buffer == NULL){
        printf("Erro ao alocar memória\n");
        return 1;
    }

    // Lê os dados do arquivo e armazena no buffer
    bytes_lidos = fread(buffer, 1, tam_arquivo, arquivo_entrada);

    if (bytes_lidos != tam_arquivo){
        printf("Erro ao ler o arquivo\n");
        free(buffer);
        fclose(arquivo_entrada);
        return 1;
    }

    printf("%s\n", buffer);
    
    fclose(arquivo_entrada);

    FILE *arquivo_saida;
    char nome_arquivo_compactado[100];
    unsigned char *buffer_compactado;
    size_t bytes_escritos;
    long tam_buffer_compactado;

    strcpy(nome_arquivo_compactado, nome_arquivo);
    strcat(nome_arquivo_compactado, ".comp");

    arquivo_saida = fopen(nome_arquivo_compactado, "wb");

    if (arquivo_saida == NULL){
        printf("Erro ao abrir o arquivo de saída\n");
        free(buffer);
        return 1;
    }

    tArvore *arvoreHuffman = Codifica(buffer);
    EscreveCodigoHuffman(arvoreHuffman, buffer, tam_arquivo); // Apenas para visualização
    tam_buffer_compactado = EscreveTextoCodificado(buffer, arvoreHuffman, &buffer_compactado);

    printf("%s, %ld\n", buffer_compactado, tam_buffer_compactado); // teste

    bytes_escritos = fwrite(buffer_compactado, 1, tam_buffer_compactado, arquivo_saida);

    if (bytes_escritos != tam_buffer_compactado){
        printf("Erro ao escrever no arquivo de saída\n");
    }

    fclose(arquivo_saida);
    free(buffer);
    free(buffer_compactado);

    return 0;
}