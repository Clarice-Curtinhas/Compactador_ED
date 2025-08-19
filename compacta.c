#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "compactador.h"
#include "bitmap/bitmap.h"

#define TAM_MAX_BITS 8

int main(int argc, const char **argv){
    if (argc < 2){
        printf("Linha de comando com argumentos insuficientes!\n");
        return 1;
    }

    FILE *arquivo_entrada;
    char nome_arquivo[100];
    long tam_arquivo;
    unsigned char *buffer;
    unsigned char matriz_codigo[ASCII][ASCII];
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

    // Aloca um buffer para armazenar os dados do arquivo. Aloca "tam_arquivo + 1" posições para adicionar um \0.
    buffer = (unsigned char*) calloc(tam_arquivo + 1, sizeof(unsigned char));

    if (buffer == NULL){
        printf("Erro ao alocar memória\n");
        return 1;
    }

    // Lê os dados do arquivo e armazena no buffer
    bytes_lidos = fread(buffer, sizeof(unsigned char), tam_arquivo, arquivo_entrada);

    if (bytes_lidos != tam_arquivo){
        printf("Erro ao ler o arquivo\n");
        free(buffer);
        fclose(arquivo_entrada);
        return 1;
    }

    //buffer[tam_arquivo] = '\0';
    
    fclose(arquivo_entrada);

    FILE *arquivo_saida;
    char nome_arquivo_compactado[100];
    unsigned char *buffer_compactado, *arv_bin_compactada;
    size_t bytes_escritos, tamBin;
    long tam_buffer_compactado;
    int tam_inic = 0;

    strcpy(nome_arquivo_compactado, nome_arquivo);
    strcat(nome_arquivo_compactado, ".comp");

    arquivo_saida = fopen(nome_arquivo_compactado, "wb");

    if (arquivo_saida == NULL){
        printf("Erro ao abrir o arquivo de saída\n");
        free(buffer);
        return 1;
    }

    tArvore *arvoreHuffman = Codifica(buffer, matriz_codigo, tam_arquivo);

    arv_bin_compactada = (unsigned char*) calloc(RetornaFrequencia(arvoreHuffman), sizeof(unsigned char*));

    EscreveCodigoHuffman(arvoreHuffman, buffer, tam_arquivo); // Apenas para visualização

    tam_buffer_compactado = EscreveTextoCodificado(buffer, matriz_codigo, &buffer_compactado, tam_arquivo);
    //printf("Buffer compactado: %s, %ld\n", buffer_compactado, tam_buffer_compactado); // teste

    arv_bin_compactada = ArvoreCompactada(arvoreHuffman, arv_bin_compactada, &tam_inic);

    bitmap *bm = bitmapInit(tam_buffer_compactado * TAM_MAX_BITS);

    for (int i = 0; i < tam_buffer_compactado; i++){
        bitmapAppendLeastSignificantBit(bm, buffer_compactado[i]);
    }

    fwrite(arv_bin_compactada, 1, tam_inic, arquivo_saida);
    fprintf(arquivo_saida, "~"); // Imprime esse caracter no arquivo como indicador que a árvore terminou
    bytes_escritos = fwrite(bitmapGetContents(bm), 1, (bitmapGetLength(bm) + 7) / 8, arquivo_saida);


    fclose(arquivo_saida);
    bitmapLibera(bm);
    DesalocaArvore(arvoreHuffman);
    free(arv_bin_compactada);
    free(buffer);
    free(buffer_compactado);

    return 0;
}