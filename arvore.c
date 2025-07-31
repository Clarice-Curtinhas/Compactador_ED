/**
* Created by Clarice Curtinhas Santos on 10/7/25
* Copyright © 2025 Clarice Curtinhas Santos, Ana Luisa Casotti de Andrade. All rights reserved.
*/

#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

#define CARACTER 1
#define NUMERO 2

typedef struct Arvore{
    char carac;
    int freq;
    tArvore *esq;
    tArvore *dir;
} tArvore;

tArvore *CriaFolhas(char caracter){
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

char RetornaCaracter(tArvore *arv){
    if(arv != NULL) return arv->carac;
}

void ImprimeArvore(tArvore *arv){
    if(arv == NULL) printf(" < > ");

    else{
        if(arv->carac) printf(" < '%c'", arv->carac);
        else printf(" < %d", arv->freq);

        ImprimeArvore(arv->esq);
        ImprimeArvore(arv->dir);

        printf(" >");
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

void EscreveCodigoHuffman(tArvore *arv, char *text, int tam){
    char caracter[tam], *codigoHuffman;
    int qntAnalisados = 0, jaAnalisado;

    for(int i = 0; i < tam; i++){
        jaAnalisado = 0;

        if(i != 0){
            for(int j = 0; j < qntAnalisados; j++){

                if(caracter[j] == text[i]){
                    jaAnalisado = 1;
                    break;
                }
            }
        }

        if(jaAnalisado == 1) continue;

        else{
            printf("SCII: %d - %c - ", text[i], text[i]);
            EncontraCaracter(arv, text[i], codigoHuffman, 0);
            printf("%s", codigoHuffman);
            printf(";\n");

            caracter[qntAnalisados] = text[i];
            qntAnalisados++;
        }
    }

    printf("\n");
}

int EncontraCaracter(tArvore *arv, char carac, char *codigoHuffman, int tamCodigo){
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