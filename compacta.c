#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "compactador.h"
#include "bitmap/bitmap.h"

#define TAM_MAX_BITS 8

/*int main(int argc, const char **argv){
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

    buffer[tam_arquivo] = '\0';
    printf("Teste buffer: %s\n", buffer);

    printf("\n");
    
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

   // tArvore *arvoreHuffman = Codifica(buffer, tam_arquivo);
    tArvore *arvoreHuffman = Codifica(buffer);

    arv_bin_compactada = (unsigned char*) calloc(RetornaFrequencia(arvoreHuffman), sizeof(unsigned char*));
    arv_bin_compactada[0] = '\0';

    tam_buffer_compactado = EscreveCodigoHuffman(arvoreHuffman, buffer, tam_arquivo); // Apenas para visualização
    printf("Tam buffer compactado: %ld\n", tam_buffer_compactado);

    buffer_compactado = (unsigned char *) calloc(tam_buffer_compactado + 1, sizeof(unsigned char));
    buffer_compactado[tam_buffer_compactado] = '\0';

    EscreveTextoCodificado(buffer, arvoreHuffman, buffer_compactado);
    printf("Buffer compactado: %s, %ld\n", buffer_compactado, tam_buffer_compactado); // teste

    ImprimeArvore(arvoreHuffman);
    arv_bin_compactada = ArvoreCompactada(arvoreHuffman, arv_bin_compactada, &tam_inic);

    printf("\n\nArvore pronta: '%s'\n\n", arv_bin_compactada);

    bitmap *bm = bitmapInit(tam_buffer_compactado * TAM_MAX_BITS);

    for (int i = 0; i < tam_buffer_compactado; i++){
        bitmapAppendLeastSignificantBit(bm, buffer_compactado[i]);
    }

    /*for (int i=0; i<bitmapGetLength(bm); i++) {
		printf("bit #%d = %0xh\n", i, bitmapGetBit(bm, i));
	}*/

    /*fwrite(arv_bin_compactada, 1, strlen(arv_bin_compactada), arquivo_saida);
    fprintf(arquivo_saida, "/"); // Imprime uma barra no arquivo como indicador que a árvore terminou
    bytes_escritos = fwrite(bitmapGetContents(bm), 1, (bitmapGetLength(bm) + 7) / 8, arquivo_saida);


    /*if (bytes_escritos != tam_buffer_compactado){
        printf("Erro ao escrever no arquivo de saída\n");
    }*/

    /*fclose(arquivo_saida);
    bitmapLibera(bm);
    DesalocaArvore(arvoreHuffman);
    free(arv_bin_compactada);
    free(buffer);
    free(buffer_compactado);

    return 0;
}*/