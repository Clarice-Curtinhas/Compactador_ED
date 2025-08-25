#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "descompactador.h"
#include "compactador.h"

#define MAX_TAM_ARVORE 1000
#define TAM_MAX_BITS 8

int main(int argc, const char **argv){
    unsigned char *textoDescompac, arvore_arq[MAX_TAM_ARVORE];
    int tam_arvore = 0;
    tArvore *arv;
    
    
    if (argc < 2){
        printf("Linha de comando com argumentos insuficientes!\n");
        return 1;
    }

    FILE *arquivo_entrada;
    char nome_arquivo[100], caracter_binario;
    int tam_arv,  total_bits;
    long tam_arquivo, tam_binario, tam_original;
    unsigned char *buffer;
    int byte[TAM_MAX_BITS], lidos = 0;
    size_t bytes_lidos;

    strcpy(nome_arquivo, argv[1]);
    arquivo_entrada = fopen(nome_arquivo, "rb");

    if (arquivo_entrada == NULL){
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }

    // Lê os valores escritos no início do arquivo binário
    fread(&tam_arv, sizeof(int), 1, arquivo_entrada);
    fread(&tam_original, sizeof(long), 1, arquivo_entrada);
    fread(&total_bits, sizeof(int), 1, arquivo_entrada);

    // Lê a árvore no início do arquivo binário
    unsigned char caracter = 0;

    while(fread(&caracter, sizeof(unsigned char), 1, arquivo_entrada)) {

        if (tam_arvore >= MAX_TAM_ARVORE) {
            printf("Erro: a árvore no arquivo excede o tamanho máximo permitido.\n");
            fclose(arquivo_entrada);
            return 1;
        }

        arvore_arq[tam_arvore] = caracter;
        tam_arvore++;

        if(tam_arvore == tam_arv){
            break;
        }
    }

    // Cria a árvore
    int tam_arvore_aux = 0;

    arv = DecodificaArvore(arvore_arq, &tam_arvore_aux, tam_arvore);

    if(arv == NULL){
        printf("Erro: árvore igual a NULL");
        return 1;
    }

    // Aloca um buffer para armazenar os dados do arquivo
    buffer = (unsigned char*) calloc(total_bits, sizeof(unsigned char));

    if (buffer == NULL){
        printf("Erro ao alocar memória\n");
        return 1;
    }

    // Lê os dados do arquivo e armazena no buffer
    while (lidos < total_bits){
        if (!fread(&caracter_binario, 1, 1, arquivo_entrada)) break;

        for (int i = 0; i < TAM_MAX_BITS; i++){
            if(lidos >= total_bits) break;

            buffer[lidos] = ((caracter_binario >> (7 - i)) & 1) + '0';
            lidos++;
        }
    }

    if (lidos != total_bits){
        printf("Erro ao ler o arquivo\n");
        free(buffer);
        fclose(arquivo_entrada);
        return 1;
    }
    
    fclose(arquivo_entrada);

    FILE *arquivo_saida;
    char nome_arquivo_descompactado[100] = {0};
    unsigned char *buffer_descompactado;
    size_t bytes_escritos;
    long tam_buffer_descompactado;

    int tam_nome_arquivo = strlen(nome_arquivo);

    // Retira o ".comp" do nome do arquivo
    for (int i = 0; i < tam_nome_arquivo - 5; i++){
        nome_arquivo_descompactado[i] = nome_arquivo[i];
    }

    arquivo_saida = fopen(nome_arquivo_descompactado, "wb");

    if (arquivo_saida == NULL){
        printf("Erro ao abrir o arquivo de saída\n");
        free(buffer);
        return 1;
    }

    EscreveTextoDecodificado(&buffer_descompactado, arv, buffer, lidos-1);

    bytes_escritos = fwrite(buffer_descompactado, 1, tam_original, arquivo_saida);

    if (bytes_escritos != tam_original){
        printf("Erro ao escrever no arquivo de saída\n");
    }

    fclose(arquivo_saida);
    free(buffer);
    free(buffer_descompactado);
    DesalocaArvore(arv);

    return 0;
}