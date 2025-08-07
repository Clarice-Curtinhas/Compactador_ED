/**
* Created by Clarice Curtinhas Santos on 10/7/25
* Copyright © 2025 Clarice Curtinhas Santos, Ana Luisa Casotti de Andrade. All rights reserved.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arvore.h"

#define CARACTER 1
#define NUMERO 2

#define TAM_MAX_BITS 100

typedef struct Arvore{
    unsigned char carac;
    int freq;
    tArvore *esq;
    tArvore *dir;
} tArvore;

tArvore *CriaFolhas(unsigned char caracter){
    tArvore *arv;

    arv = (tArvore*) calloc(1, sizeof(tArvore));

    arv->carac = caracter;
    arv->freq = 1;

    arv->esq = NULL;
    arv->dir = NULL;

    return arv;
}

tArvore *CriaGalhos(tArvore *esq, tArvore *dir){
    tArvore *arv;

    arv = (tArvore*) calloc(1, sizeof(tArvore));

    arv->freq = RetornaFrequencia(dir) + RetornaFrequencia(esq);

    arv->esq = esq;
    arv->dir = dir;

    return arv;
}

void AcrescimoDeCaracter(tArvore *arv){
    if(arv != NULL) arv->freq++;
}

int RetornaFrequencia(tArvore *arv){
    if(arv != NULL) return arv->freq;
}

unsigned char RetornaCaracter(tArvore *arv){
    if(arv != NULL) return arv->carac;
}

unsigned char* ImprimeArvore(tArvore *arv, unsigned char *buffer){
    size_t tam = strlen(buffer);
    unsigned char no = '0', folha = '1', codigo[TAM_MAX_BITS];

    if(arv == NULL){
        printf(" < > ");
    }

    else{
        if(arv->carac){
            if(buffer != NULL){
                buffer[tam] = folha;
                buffer[tam+1] = arv->carac;
                buffer[tam+2] = '\0';

                // Usando os codigos dos caracteres

                /*if(EncontraCaracter(arv, arv->carac, codigo, 0) == 1){
                    strcat(buffer, codigo);
                }
                */
            }

            if(arv->carac != '\n') printf(" < '%c'", arv->carac);
            else printf(" < quebra de linha");
        }
        
        else{
            if(buffer != NULL){
                ///Acho que não vai precisar da parte comentada e ela tá dando problema
                //unsigned char binario[TAM_MAX_BITS];
                buffer[tam] = no;
                buffer[tam+1] = '\0';

                /*FrequenciaBinario(arv->freq, &*binario);
                if(binario != NULL) strcat(buffer, binario);
                else {
                    buffer[tam+1] = '0';
                    buffer[tam+2] = '\0';
                }*/
            }

            printf(" < %d", arv->freq);
            //binario[0] = '\0';
        }

        buffer = ImprimeArvore(arv->esq, buffer);
        buffer = ImprimeArvore(arv->dir, buffer);

        printf(" >");
    }

    return buffer;
}

void FrequenciaBinario(int frequencia, unsigned char *bin){
    int num;
    unsigned char caract, c1 = '1', c0 = '0';

    if(frequencia > 0){
        FrequenciaBinario(frequencia/2, bin);
        num = frequencia % 2;

        if(num == 1) strcat(bin, &c1);
        else strcat(bin, &c0);
    }
}

void DesalocaArvore(tArvore *arv){
    if(arv == NULL) return;

    else{
        DesalocaArvore(arv->esq);
        DesalocaArvore(arv->dir);

        free(arv);
    }
}

void EscreveCodigoHuffman(tArvore *arv, unsigned char *text, int tam){
    unsigned char caracter[tam], codigoHuffman[TAM_MAX_BITS];
    int qntAnalisados = 0, jaFoi;

    printf("%d\n", tam);

    for(int i = 0; i < tam; i++){
        jaFoi = 0;

        if(i != 0){
            for(int j = 0; j < qntAnalisados; j++){

                if(caracter[j] == text[i]){
                    jaFoi = 1;
                    break;
                }
            }
        }

        if(jaFoi == 0){
            printf("SCII: %d - %c - ", text[i], text[i]);

            if(EncontraCaracter(arv, text[i], codigoHuffman, 0) == 0)
                printf("Erro! caracter não encontrado");
            
            else{
                printf("%s", codigoHuffman);
                printf(";\n");
            }

            caracter[qntAnalisados] = text[i];
            qntAnalisados++;
        }
    }

    printf("\n");
}

int EncontraCaracter(tArvore *arv, unsigned char carac, unsigned char *codigoHuffman, int tamCodigo){
    codigoHuffman = (unsigned char *) realloc(codigoHuffman, tamCodigo + 1); // Acho que isso está errado, mas reduziu muito os erros de valgrind

    if(arv->carac){
        if(carac == arv->carac) {
            codigoHuffman[tamCodigo] = '\0';
            return 1;
        }
    }

    else{

        codigoHuffman[tamCodigo] = '0';
        if(EncontraCaracter(arv->esq, carac, codigoHuffman, tamCodigo + 1) == 1){
            return 1;
        }

        codigoHuffman[tamCodigo] = '1';
        if(EncontraCaracter(arv->dir, carac, codigoHuffman, tamCodigo + 1) == 1){
            return 1;
        }

        return 0;
    }
}