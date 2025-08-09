#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "descompactador.h"

#define string "0001o1m01b1 001a01u1l001z1e01s1r"
#define texto "010 000 001 011 1101 1110 1110 1101 011 010 000 001 010 000 001 011 100 1111 100 1111 100 011 100 1100 1010 1011"
#define MAX_TAM_ARVORE 500
#define TAM_MAX_BITS 8

int main(int argc, const char **argv){
    unsigned char c1[35] = "0001o1m01b1 001a01u1l001z1e01s1r", text[118] = texto;
    unsigned char *textoDescompac, arvore_arq[MAX_TAM_ARVORE];
    int tam_arvore = 0;
    tArvore *arv;

    /*c1[32] = '\0';

    printf("%s\n", c1);

    arv = DecodificaArvore(c1, &tam);

    if(arv!= NULL){
        ImprimeArvore(arv);
    }

    else printf("Não foi\n");

    EscreveTextoDecodificado(&textoDescompac, arv, texto);

    printf("%s\n", textoDescompac);*/
    
    //minha parte começa aqui
    
    if (argc < 2){
        printf("Linha de comando com argumentos insuficientes!\n");
        return 1;
    }

    FILE *arquivo_entrada;
    char nome_arquivo[100], caracter, caracter_binario;
    long tam_arquivo, tam_binario;
    unsigned char *buffer;
    int byte[TAM_MAX_BITS], lidos = 0;
    size_t bytes_lidos;

    strcpy(nome_arquivo, argv[1]);
    arquivo_entrada = fopen(nome_arquivo, "rb");

    if (arquivo_entrada == NULL){
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }

    // Lê a árvore no início do arquivo binário
    while(1){
        fscanf(arquivo_entrada, "%c", &caracter);
        if (caracter == '/') break;

        arvore_arq[tam_arvore] = caracter;
        printf("%c ", caracter);
        tam_arvore++;
    }

    // Cria a árvore
    tam_arvore = 0;
    arv = DecodificaArvore(arvore_arq, &tam_arvore);

    // Calcula o tamanho da parte binária do arquivo
    fseek(arquivo_entrada, 0, SEEK_END);
    tam_arquivo = ftell(arquivo_entrada);
    fseek(arquivo_entrada, tam_arvore + 1, SEEK_SET);
    tam_binario = tam_arquivo - (tam_arvore + 1);

    // Aloca um buffer para armazenar os dados do arquivo
    buffer = (unsigned char*) calloc(tam_binario + 1, sizeof(unsigned char));

    if (buffer == NULL){
        printf("Erro ao alocar memória\n");
        return 1;
    }

    // Lê os dados do arquivo e armazena no buffer
    unsigned char codigo[tam_binario * TAM_MAX_BITS];

    while (1){
        if (!fread(&caracter_binario, 1, 1, arquivo_entrada)) break;

        printf("%c", caracter_binario);

        for (int i = 0; i < TAM_MAX_BITS; i++){
            //byte[7 - i] = (caracter_binario >> i) & 1;

            buffer[lidos] = (unsigned char)((caracter_binario >> (7 - i)) & 1);
            lidos++;
        }
    }
    
    for (int i = 0; i < tam_binario; i++) {
        printf("%u", buffer[i]);
    }
    printf("\n");
    //buffer[tam_binario] = '\0';
    //printf("Buffer: %s\n", buffer);

    //printf("%ld, %s\n", bytes_lidos, buffer);

    if (bytes_lidos != tam_binario){
        printf("Erro ao ler o arquivo\n");
        free(buffer);
        fclose(arquivo_entrada);
        return 1;
    }
    
    fclose(arquivo_entrada);

    /*FILE *arquivo_saida;
    char nome_arquivo_descompactado[100];
    unsigned char *buffer_descompactado;
    size_t bytes_escritos;
    long tam_buffer_descompactado;

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

    //tam_buffer_descompactado = EscreveCodigoHuffman(arvoreHuffman, buffer, tam_arquivo); // Apenas para visualização

    bytes_escritos = fwrite(buffer_descompactado, 1, tam_buffer_descompactado, arquivo_saida);

    if (bytes_escritos != tam_buffer_descompactado){
        printf("Erro ao escrever no arquivo de saída\n");
    }

    fclose(arquivo_saida);
    free(buffer);
    free(buffer_descompactado);

    free(textoDescompac);

    DesalocaArvore(arv);

    return 0;*/
}