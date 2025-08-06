#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "descompactador.h"

#define string "0001o1m01b1 001a01u1l001z1e01s1r"

int main(int argc, const char **argv){
    char c1[35] = "0001o1m01b1 001a01u1l001z1e01s1r";
    tArvore *arv;

    c1[32] = '\0';

    printf("%s\n", c1);

    arv = DecodificaArvore(c1);

    if(DecodificaArvore != NULL){
        ImprimeArvore(DecodificaArvore(c1), NULL);
    }

    else printf("Não foi\n");

    /*if (argc < 2){
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
    // OBS.: preciso ver um jeito de desconsiderar os bytes que armazenam a árvore de compactação no início do arquivo
    // e armazená-los em uma árvore para ser utilizada na função de descompactação
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

    printf("%ld, %s\n", bytes_lidos, buffer);

    if (bytes_lidos != tam_arquivo){
        printf("Erro ao ler o arquivo\n");
        free(buffer);
        fclose(arquivo_entrada);
        return 1;
    }
    
    fclose(arquivo_entrada);

    FILE *arquivo_saida;
    char nome_arquivo_descompactado[100];
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

    // Aqui deve entrar a função que descompacta o arquivo.
    // Ela irá receber árvore de compactação, buffer, tam_arquivo, buffer_descompactado e tam_buffer_descompactado

    bytes_escritos = fwrite(buffer_descompactado, 1, tam_buffer_descompactado, arquivo_saida);

    if (bytes_escritos != tam_buffer_descompactado){
        printf("Erro ao escrever no arquivo de saída\n");
    }

    fclose(arquivo_saida);
    free(buffer);
    free(buffer_descompactado);*/

    return 0;
}