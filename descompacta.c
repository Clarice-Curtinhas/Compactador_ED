#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "descompactador.h"
#include "compactador.h"

#define MAX_TAM_ARVORE 500
#define TAM_MAX_BITS 8
/*
int main(int argc, const char **argv){
    unsigned char *textoDescompac, arvore_arq[MAX_TAM_ARVORE];
    int tam_arvore = 0;
    tArvore *arv;
    
    //minha parte começa aqui
    
    if (argc < 2){
        printf("Linha de comando com argumentos insuficientes!\n");
        return 1;
    }

    FILE *arquivo_entrada;
    char nome_arquivo[100], caracter_binario;
    long tam_arquivo, tam_binario;
    unsigned char *buffer;
    int byte[TAM_MAX_BITS], lidos = 0;
    size_t bytes_lidos;

    strcpy(nome_arquivo, argv[1]);
    //strcat(nome_arquivo, ".comp");
    arquivo_entrada = fopen(nome_arquivo, "rb");

    if (arquivo_entrada == NULL){
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }

    // Lê a árvore no início do arquivo binário
    unsigned char caracter;

    while(fread(&caracter, sizeof(unsigned char), 1, arquivo_entrada)) {

        if (caracter == '~'){
            break;
        }

        if (tam_arvore >= MAX_TAM_ARVORE) {
            printf("Erro: a árvore no arquivo excede o tamanho máximo permitido.\n");
            fclose(arquivo_entrada);
            return 1;
        }

        arvore_arq[tam_arvore] = caracter;
        tam_arvore++;
    }

    arvore_arq[tam_arvore] = '\0';

    // Cria a árvore
    int tam_arvore_aux = 0;

    arv = DecodificaArvore(arvore_arq, &tam_arvore_aux, tam_arvore);

    if(arv == NULL){
        printf("Erro: árvore igual a NULL");
        return 1;
    }

    // Calcula o tamanho da parte binária do arquivo
    fseek(arquivo_entrada, 0, SEEK_END);
    tam_arquivo = ftell(arquivo_entrada);
    fseek(arquivo_entrada, tam_arvore + 1, SEEK_SET);
    tam_binario = tam_arquivo - (tam_arvore + 1);

    // Aloca um buffer para armazenar os dados do arquivo
    buffer = (unsigned char*) calloc((tam_binario * TAM_MAX_BITS) + 1, sizeof(unsigned char));

    if (buffer == NULL){
        printf("Erro ao alocar memória\n");
        return 1;
    }

    // Lê os dados do arquivo e armazena no buffer
    unsigned char codigo[tam_binario * TAM_MAX_BITS];
    unsigned char *textoCod;


    while (1){
        if (!fread(&caracter_binario, 1, 1, arquivo_entrada)) break;

        //printf("\nbyte:%c -> bits: ", caracter_binario);

        for (int i = 0; i < TAM_MAX_BITS; i++){

            buffer[lidos] = ((caracter_binario >> (7 - i)) & 1) + '0';
            //printf("%c ", buffer[lidos]);
            lidos++;
        }
    }

    
    //buffer[lidos] = '\0';
    //printf("Buffer: %s, tam buffer: %d\n", buffer, lidos);

    if (lidos/8 != tam_binario){
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

    buffer_descompactado = (unsigned char*) calloc(tam_arquivo*3, sizeof(unsigned char));

    int tam_nome_arquivo = strlen(nome_arquivo);

    // Retira o ".comp" do nome do arquivo e adiciona ".descomp"
    for (int i = 0; i < tam_nome_arquivo - 5; i++){
        nome_arquivo_descompactado[i] = nome_arquivo[i];
    }

    strcat(nome_arquivo_descompactado, ".descomp");

    arquivo_saida = fopen(nome_arquivo_descompactado, "wb");

    if (arquivo_saida == NULL){
        printf("Erro ao abrir o arquivo de saída\n");
        free(buffer);
        return 1;
    }

    //buffer_descompactado = (unsigned char *) calloc(100, sizeof(unsigned char));

    tam_buffer_descompactado = EscreveTextoDecodificado(&buffer_descompactado, arv, buffer, tam_arquivo*5);
    //printf("buffer descomp.: %s, tam: %ld\n", buffer_descompactado, tam_buffer_descompactado);

    bytes_escritos = fwrite(buffer_descompactado, 1, tam_buffer_descompactado, arquivo_saida);

    if (bytes_escritos != tam_buffer_descompactado){
        printf("Erro ao escrever no arquivo de saída\n");
    }

    fclose(arquivo_saida);
    free(buffer);
    free(buffer_descompactado);

    //free(textoDescompac);

    DesalocaArvore(arv);

    return 0;
}*/